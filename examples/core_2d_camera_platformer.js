/*******************************************************************************************
*
*   raylib [core] example - 2D Camera platformer
*
*   Example ported to JavaScript with node-raylib
*
*   Example originally created with raylib 2.5, last time updated with raylib 3.0
*
*   Example contributed by arvyy (@arvyy) and reviewed by Ramon Santamaria (@raysan5)
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2019-2025 arvyy (@arvyy)
*
********************************************************************************************/

import { 
  InitWindow, 
  CloseWindow, 
  BeginDrawing,
  EndDrawing,
  ClearBackground,
  BeginMode2D,
  EndMode2D,
  DrawRectangleRec,
  DrawCircleV,
  DrawText,
  GetFrameTime,
  GetMouseWheelMove,
  IsKeyPressed,
  IsKeyDown,
  WindowShouldClose,
  GetWorldToScreen2D,
  GetScreenToWorld2D,
  Vector2Subtract,
  Vector2Length,
  Vector2Add,
  Vector2Scale,
  SetTargetFPS,
  LIGHTGRAY,
  GRAY,
  RED,
  GOLD,
  BLACK,
  DARKGRAY,
  KEY_R,
  KEY_C,
  KEY_LEFT,
  KEY_RIGHT,
  KEY_SPACE
} from '../index.js'

const G = 400
const PLAYER_JUMP_SPD = 350.0
const PLAYER_HOR_SPD = 200.0

// Helper functions for Math
const fminf = Math.min
const fmaxf = Math.max

// Initialization
//--------------------------------------------------------------------------------------
const screenWidth = 800
const screenHeight = 450

InitWindow(screenWidth, screenHeight, "raylib [core] example - 2d camera platformer")

// Player initialization
const player = {
  position: { x: 400, y: 280 },
  speed: 0,
  canJump: false
}

// Environment items
const envItems = [
  { rect: { x: 0, y: 0, width: 1000, height: 400 }, blocking: 0, color: LIGHTGRAY },
  { rect: { x: 0, y: 400, width: 1000, height: 200 }, blocking: 1, color: GRAY },
  { rect: { x: 300, y: 200, width: 400, height: 10 }, blocking: 1, color: GRAY },
  { rect: { x: 250, y: 300, width: 100, height: 10 }, blocking: 1, color: GRAY },
  { rect: { x: 650, y: 300, width: 100, height: 10 }, blocking: 1, color: GRAY }
]

const envItemsLength = envItems.length

// Camera initialization
const camera = {
  target: { x: player.position.x, y: player.position.y },
  offset: { x: screenWidth/2.0, y: screenHeight/2.0 },
  rotation: 0.0,
  zoom: 1.0
}

// Camera update functions
function UpdateCameraCenter(camera, player, envItems, envItemsLength, delta, width, height) {
  camera.offset = { x: width/2.0, y: height/2.0 }
  camera.target = { x: player.position.x, y: player.position.y }
}

function UpdateCameraCenterInsideMap(camera, player, envItems, envItemsLength, delta, width, height) {
  camera.target = { x: player.position.x, y: player.position.y }
  camera.offset = { x: width/2.0, y: height/2.0 }
  let minX = 1000, minY = 1000, maxX = -1000, maxY = -1000

  for (let i = 0; i < envItemsLength; i++) {
    const ei = envItems[i]
    minX = fminf(ei.rect.x, minX)
    maxX = fmaxf(ei.rect.x + ei.rect.width, maxX)
    minY = fminf(ei.rect.y, minY)
    maxY = fmaxf(ei.rect.y + ei.rect.height, maxY)
  }

  const max = GetWorldToScreen2D({ x: maxX, y: maxY }, camera)
  const min = GetWorldToScreen2D({ x: minX, y: minY }, camera)

  if (max.x < width) camera.offset.x = width - (max.x - width/2)
  if (max.y < height) camera.offset.y = height - (max.y - height/2)
  if (min.x > 0) camera.offset.x = width/2 - min.x
  if (min.y > 0) camera.offset.y = height/2 - min.y
}

// Variables for UpdateCameraCenterSmoothFollow
const smoothFollowSettings = {
  minSpeed: 30,
  minEffectLength: 10,
  fractionSpeed: 0.8
}

function UpdateCameraCenterSmoothFollow(camera, player, envItems, envItemsLength, delta, width, height) {
  camera.offset = { x: width/2.0, y: height/2.0 }
  const diff = Vector2Subtract(player.position, camera.target)
  const length = Vector2Length(diff)

  if (length > smoothFollowSettings.minEffectLength) {
    const speed = fmaxf(smoothFollowSettings.fractionSpeed * length, smoothFollowSettings.minSpeed)
    camera.target = Vector2Add(camera.target, Vector2Scale(diff, speed * delta / length))
  }
}

// Variables for UpdateCameraEvenOutOnLanding
const evenOutSettings = {
  evenOutSpeed: 700,
  eveningOut: false,
  evenOutTarget: 0
}

function UpdateCameraEvenOutOnLanding(camera, player, envItems, envItemsLength, delta, width, height) {
  camera.offset = { x: width/2.0, y: height/2.0 }
  camera.target.x = player.position.x

  if (evenOutSettings.eveningOut) {
    if (evenOutSettings.evenOutTarget > camera.target.y) {
      camera.target.y += evenOutSettings.evenOutSpeed * delta

      if (camera.target.y > evenOutSettings.evenOutTarget) {
        camera.target.y = evenOutSettings.evenOutTarget
        evenOutSettings.eveningOut = false
      }
    } else {
      camera.target.y -= evenOutSettings.evenOutSpeed * delta

      if (camera.target.y < evenOutSettings.evenOutTarget) {
        camera.target.y = evenOutSettings.evenOutTarget
        evenOutSettings.eveningOut = false
      }
    }
  } else {
    if (player.canJump && (player.speed == 0) && (player.position.y != camera.target.y)) {
      evenOutSettings.eveningOut = true
      evenOutSettings.evenOutTarget = player.position.y
    }
  }
}

// Variables for UpdateCameraPlayerBoundsPush
const boundsPushSettings = {
  bbox: { x: 0.2, y: 0.2 }
}

function UpdateCameraPlayerBoundsPush(camera, player, envItems, envItemsLength, delta, width, height) {
  const bboxWorldMin = GetScreenToWorld2D(
    { x: (1 - boundsPushSettings.bbox.x) * 0.5 * width, y: (1 - boundsPushSettings.bbox.y) * 0.5 * height }, 
    camera
  )
  const bboxWorldMax = GetScreenToWorld2D(
    { x: (1 + boundsPushSettings.bbox.x) * 0.5 * width, y: (1 + boundsPushSettings.bbox.y) * 0.5 * height }, 
    camera
  )
  camera.offset = { 
    x: (1 - boundsPushSettings.bbox.x) * 0.5 * width, 
    y: (1 - boundsPushSettings.bbox.y) * 0.5 * height 
  }

  if (player.position.x < bboxWorldMin.x) camera.target.x = player.position.x
  if (player.position.y < bboxWorldMin.y) camera.target.y = player.position.y
  if (player.position.x > bboxWorldMax.x) camera.target.x = bboxWorldMin.x + (player.position.x - bboxWorldMax.x)
  if (player.position.y > bboxWorldMax.y) camera.target.y = bboxWorldMin.y + (player.position.y - bboxWorldMax.y)
}

// Update Player function
function UpdatePlayer(player, envItems, envItemsLength, delta) {
  if (IsKeyDown(KEY_LEFT)) player.position.x -= PLAYER_HOR_SPD * delta
  if (IsKeyDown(KEY_RIGHT)) player.position.x += PLAYER_HOR_SPD * delta
  if (IsKeyDown(KEY_SPACE) && player.canJump) {
    player.speed = -PLAYER_JUMP_SPD
    player.canJump = false
  }

  let hitObstacle = false
  for (let i = 0; i < envItemsLength; i++) {
    const ei = envItems[i]
    const p = player.position
    if (ei.blocking &&
        ei.rect.x <= p.x &&
        ei.rect.x + ei.rect.width >= p.x &&
        ei.rect.y >= p.y &&
        ei.rect.y <= p.y + player.speed * delta) {
      hitObstacle = true
      player.speed = 0.0
      p.y = ei.rect.y
      break
    }
  }

  if (!hitObstacle) {
    player.position.y += player.speed * delta
    player.speed += G * delta
    player.canJump = false
  } else {
    player.canJump = true
  }
}

// Store pointers to the multiple update camera functions
const cameraUpdaters = [
  UpdateCameraCenter,
  UpdateCameraCenterInsideMap,
  UpdateCameraCenterSmoothFollow,
  UpdateCameraEvenOutOnLanding,
  UpdateCameraPlayerBoundsPush
]

let cameraOption = 0
const cameraUpdatersLength = cameraUpdaters.length

const cameraDescriptions = [
  "Follow player center",
  "Follow player center, but clamp to map edges",
  "Follow player center; smoothed",
  "Follow player center horizontally; update player center vertically after landing",
  "Player push camera on getting too close to screen edge"
]

SetTargetFPS(60)
//--------------------------------------------------------------------------------------

// Main game loop
while (!WindowShouldClose())    // Detect window close button or ESC key
{
  // Update
  //----------------------------------------------------------------------------------
  const deltaTime = GetFrameTime()

  UpdatePlayer(player, envItems, envItemsLength, deltaTime)

  camera.zoom += GetMouseWheelMove() * 0.05

  if (camera.zoom > 3.0) camera.zoom = 3.0
  else if (camera.zoom < 0.25) camera.zoom = 0.25

  if (IsKeyPressed(KEY_R)) {
    camera.zoom = 1.0
    player.position = { x: 400, y: 280 }
  }

  if (IsKeyPressed(KEY_C)) cameraOption = (cameraOption + 1) % cameraUpdatersLength

  // Call update camera function by its pointer
  cameraUpdaters[cameraOption](camera, player, envItems, envItemsLength, deltaTime, screenWidth, screenHeight)
  //----------------------------------------------------------------------------------

  // Draw
  //----------------------------------------------------------------------------------
  BeginDrawing()

    ClearBackground(LIGHTGRAY)

    BeginMode2D(camera)

      for (let i = 0; i < envItemsLength; i++) {
        DrawRectangleRec(envItems[i].rect, envItems[i].color)
      }

      const playerRect = { 
        x: player.position.x - 20, 
        y: player.position.y - 40, 
        width: 40, 
        height: 40 
      }
      DrawRectangleRec(playerRect, RED)
      
      DrawCircleV(player.position, 5, GOLD)

    EndMode2D()

    DrawText("Controls:", 20, 20, 10, BLACK)
    DrawText("- Right/Left to move", 40, 40, 10, DARKGRAY)
    DrawText("- Space to jump", 40, 60, 10, DARKGRAY)
    DrawText("- Mouse Wheel to Zoom in-out, R to reset zoom", 40, 80, 10, DARKGRAY)
    DrawText("- C to change camera mode", 40, 100, 10, DARKGRAY)
    DrawText("Current camera mode:", 20, 120, 10, BLACK)
    DrawText(cameraDescriptions[cameraOption], 40, 140, 10, DARKGRAY)

  EndDrawing()
  //----------------------------------------------------------------------------------
}

// De-Initialization
//--------------------------------------------------------------------------------------
CloseWindow()        // Close window and OpenGL context
//--------------------------------------------------------------------------------------