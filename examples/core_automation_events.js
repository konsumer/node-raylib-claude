/*******************************************************************************************
*
*   raylib [core] example - automation events
*
*   Example ported to JavaScript with node-raylib
*
*   Example originally created with raylib 5.0, last time updated with raylib 5.0
*
*   Example based on 2d_camera_platformer example by arvyy (@arvyy)
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2023-2025 Ramon Santamaria (@raysan5)
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
  DrawRectangle,
  DrawRectangleLines,
  DrawText,
  DrawCircle,
  DrawTriangle,
  IsKeyDown,
  IsKeyPressed,
  IsFileDropped,
  LoadDroppedFiles,
  UnloadDroppedFiles,
  IsFileExtension,
  GetMouseWheelMove,
  GetWorldToScreen2D,
  LoadAutomationEventList,
  UnloadAutomationEventList,
  SetAutomationEventList,
  StartAutomationEventRecording,
  StopAutomationEventRecording,
  SetAutomationEventBaseFrame,
  PlayAutomationEvent,
  ExportAutomationEventList,
  WindowShouldClose,
  Fade,
  TextFormat,
  TraceLog,
  SetTargetFPS,
  LOG_INFO,
  LIGHTGRAY,
  GRAY,
  RED,
  BLACK,
  DARKGRAY,
  SKYBLUE,
  BLUE,
  MAROON,
  LIME,
  DARKGREEN,
  KEY_LEFT,
  KEY_RIGHT,
  KEY_SPACE,
  KEY_R,
  KEY_S,
  KEY_A
} from '../index.js'

const GRAVITY = 400
const PLAYER_JUMP_SPD = 350.0
const PLAYER_HOR_SPD = 200.0

const MAX_ENVIRONMENT_ELEMENTS = 5

// Helper Math functions
const fminf = Math.min
const fmaxf = Math.max

// Initialization
//--------------------------------------------------------------------------------------
const screenWidth = 800
const screenHeight = 450

InitWindow(screenWidth, screenHeight, "raylib [core] example - automation events")

// Define player
const player = {
  position: { x: 400, y: 280 },
  speed: 0,
  canJump: false
}

// Define environment elements (platforms)
const envElements = [
  { rect: { x: 0, y: 0, width: 1000, height: 400 }, blocking: 0, color: LIGHTGRAY },
  { rect: { x: 0, y: 400, width: 1000, height: 200 }, blocking: 1, color: GRAY },
  { rect: { x: 300, y: 200, width: 400, height: 10 }, blocking: 1, color: GRAY },
  { rect: { x: 250, y: 300, width: 100, height: 10 }, blocking: 1, color: GRAY },
  { rect: { x: 650, y: 300, width: 100, height: 10 }, blocking: 1, color: GRAY }
]

// Define camera
const camera = {
  target: { x: player.position.x, y: player.position.y },
  offset: { x: screenWidth/2.0, y: screenHeight/2.0 },
  rotation: 0.0,
  zoom: 1.0
}

// Automation events
const aelist = LoadAutomationEventList(0)  // Initialize list of automation events to record new events
SetAutomationEventList(aelist)
let eventRecording = false
let eventPlaying = false

let frameCounter = 0
let playFrameCounter = 0
let currentPlayFrame = 0

SetTargetFPS(60)
//--------------------------------------------------------------------------------------

// Main game loop
while (!WindowShouldClose())
{
    // Update
    //----------------------------------------------------------------------------------
    const deltaTime = 0.015 //GetFrameTime()
    
    // Dropped files logic
    //----------------------------------------------------------------------------------
    if (IsFileDropped())
    {
        const droppedFiles = LoadDroppedFiles()

        // Supports loading .rgs style files (text or binary) and .png style palette images
        if (IsFileExtension(droppedFiles.paths[0], ".txt;.rae"))
        {
            UnloadAutomationEventList(aelist)
            const newAelist = LoadAutomationEventList(droppedFiles.paths[0])
            
            eventRecording = false
            
            // Reset scene state to play
            eventPlaying = true
            playFrameCounter = 0
            currentPlayFrame = 0
            
            player.position = { x: 400, y: 280 }
            player.speed = 0
            player.canJump = false

            camera.target = { x: player.position.x, y: player.position.y }
            camera.offset = { x: screenWidth/2.0, y: screenHeight/2.0 }
            camera.rotation = 0.0
            camera.zoom = 1.0
        }

        UnloadDroppedFiles(droppedFiles)   // Unload filepaths from memory
    }
    //----------------------------------------------------------------------------------

    // Update player
    //----------------------------------------------------------------------------------
    if (IsKeyDown(KEY_LEFT)) player.position.x -= PLAYER_HOR_SPD * deltaTime
    if (IsKeyDown(KEY_RIGHT)) player.position.x += PLAYER_HOR_SPD * deltaTime
    if (IsKeyDown(KEY_SPACE) && player.canJump)
    {
        player.speed = -PLAYER_JUMP_SPD
        player.canJump = false
    }

    let hitObstacle = 0
    for (let i = 0; i < MAX_ENVIRONMENT_ELEMENTS; i++)
    {
        const element = envElements[i]
        const p = player.position
        if (element.blocking &&
            element.rect.x <= p.x &&
            element.rect.x + element.rect.width >= p.x &&
            element.rect.y >= p.y &&
            element.rect.y <= p.y + player.speed * deltaTime)
        {
            hitObstacle = 1
            player.speed = 0.0
            p.y = element.rect.y
        }
    }

    if (!hitObstacle)
    {
        player.position.y += player.speed * deltaTime
        player.speed += GRAVITY * deltaTime
        player.canJump = false
    }
    else player.canJump = true

    if (IsKeyPressed(KEY_R))
    {
        // Reset game state
        player.position = { x: 400, y: 280 }
        player.speed = 0
        player.canJump = false

        camera.target = { x: player.position.x, y: player.position.y }
        camera.offset = { x: screenWidth/2.0, y: screenHeight/2.0 }
        camera.rotation = 0.0
        camera.zoom = 1.0
    }
    //----------------------------------------------------------------------------------

    // Events playing
    // NOTE: Logic must be before Camera update because it depends on mouse-wheel value, 
    // that can be set by the played event... but some other inputs could be affected
    //----------------------------------------------------------------------------------
    if (eventPlaying && aelist.events)
    {
        // NOTE: Multiple events could be executed in a single frame
        while (playFrameCounter == aelist.events[currentPlayFrame]?.frame)
        {
            PlayAutomationEvent(aelist.events[currentPlayFrame])
            currentPlayFrame++

            if (currentPlayFrame == aelist.count)
            {
                eventPlaying = false
                currentPlayFrame = 0
                playFrameCounter = 0

                TraceLog(LOG_INFO, "FINISH PLAYING!")
                break
            }
        }

        playFrameCounter++
    }
    //----------------------------------------------------------------------------------

    // Update camera
    //----------------------------------------------------------------------------------
    camera.target = { x: player.position.x, y: player.position.y }
    camera.offset = { x: screenWidth/2.0, y: screenHeight/2.0 }
    let minX = 1000, minY = 1000, maxX = -1000, maxY = -1000

    // WARNING: On event replay, mouse-wheel internal value is set
    camera.zoom += (GetMouseWheelMove() * 0.05)
    if (camera.zoom > 3.0) camera.zoom = 3.0
    else if (camera.zoom < 0.25) camera.zoom = 0.25

    for (let i = 0; i < MAX_ENVIRONMENT_ELEMENTS; i++)
    {
        const element = envElements[i]
        minX = fminf(element.rect.x, minX)
        maxX = fmaxf(element.rect.x + element.rect.width, maxX)
        minY = fminf(element.rect.y, minY)
        maxY = fmaxf(element.rect.y + element.rect.height, maxY)
    }

    const max = GetWorldToScreen2D({ x: maxX, y: maxY }, camera)
    const min = GetWorldToScreen2D({ x: minX, y: minY }, camera)

    if (max.x < screenWidth) camera.offset.x = screenWidth - (max.x - screenWidth/2)
    if (max.y < screenHeight) camera.offset.y = screenHeight - (max.y - screenHeight/2)
    if (min.x > 0) camera.offset.x = screenWidth/2 - min.x
    if (min.y > 0) camera.offset.y = screenHeight/2 - min.y
    //----------------------------------------------------------------------------------
    
    // Events management
    if (IsKeyPressed(KEY_S))    // Toggle events recording
    {
        if (!eventPlaying)
        {
            if (eventRecording)
            {
                StopAutomationEventRecording()
                eventRecording = false
                
                ExportAutomationEventList(aelist, "automation.rae")
                
                TraceLog(LOG_INFO, "RECORDED FRAMES: %i", aelist.count)
            }
            else 
            {
                SetAutomationEventBaseFrame(180)
                StartAutomationEventRecording()
                eventRecording = true
            }
        }
    }
    else if (IsKeyPressed(KEY_A)) // Toggle events playing (WARNING: Starts next frame)
    {
        if (!eventRecording && (aelist.count > 0))
        {
            // Reset scene state to play
            eventPlaying = true
            playFrameCounter = 0
            currentPlayFrame = 0

            player.position = { x: 400, y: 280 }
            player.speed = 0
            player.canJump = false

            camera.target = { x: player.position.x, y: player.position.y }
            camera.offset = { x: screenWidth/2.0, y: screenHeight/2.0 }
            camera.rotation = 0.0
            camera.zoom = 1.0
        }
    }

    if (eventRecording || eventPlaying) frameCounter++
    else frameCounter = 0
    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing()

        ClearBackground(LIGHTGRAY)

        BeginMode2D(camera)

            // Draw environment elements
            for (let i = 0; i < MAX_ENVIRONMENT_ELEMENTS; i++)
            {
                DrawRectangleRec(envElements[i].rect, envElements[i].color)
            }

            // Draw player rectangle
            DrawRectangleRec({ 
                x: player.position.x - 20, 
                y: player.position.y - 40, 
                width: 40, 
                height: 40 
            }, RED)

        EndMode2D()
        
        // Draw game controls
        DrawRectangle(10, 10, 290, 145, Fade(SKYBLUE, 0.5))
        DrawRectangleLines(10, 10, 290, 145, Fade(BLUE, 0.8))

        DrawText("Controls:", 20, 20, 10, BLACK)
        DrawText("- RIGHT | LEFT: Player movement", 30, 40, 10, DARKGRAY)
        DrawText("- SPACE: Player jump", 30, 60, 10, DARKGRAY)
        DrawText("- R: Reset game state", 30, 80, 10, DARKGRAY)

        DrawText("- S: START/STOP RECORDING INPUT EVENTS", 30, 110, 10, BLACK)
        DrawText("- A: REPLAY LAST RECORDED INPUT EVENTS", 30, 130, 10, BLACK)

        // Draw automation events recording indicator
        if (eventRecording)
        {
            DrawRectangle(10, 160, 290, 30, Fade(RED, 0.3))
            DrawRectangleLines(10, 160, 290, 30, Fade(MAROON, 0.8))
            DrawCircle(30, 175, 10, MAROON)

            if (((Math.floor(frameCounter/15))%2) == 1) 
                DrawText(TextFormat("RECORDING EVENTS... [%i]", aelist.count), 50, 170, 10, MAROON)
        }
        else if (eventPlaying)
        {
            DrawRectangle(10, 160, 290, 30, Fade(LIME, 0.3))
            DrawRectangleLines(10, 160, 290, 30, Fade(DARKGREEN, 0.8))
            DrawTriangle(
                { x: 20, y: 155 + 10 }, 
                { x: 20, y: 155 + 30 }, 
                { x: 40, y: 155 + 20 }, 
                DARKGREEN
            )

            if (((Math.floor(frameCounter/15))%2) == 1) 
                DrawText(TextFormat("PLAYING RECORDED EVENTS... [%i]", currentPlayFrame), 50, 170, 10, DARKGREEN)
        }
        

    EndDrawing()
    //----------------------------------------------------------------------------------
}

// De-Initialization
//--------------------------------------------------------------------------------------
CloseWindow()        // Close window and OpenGL context
//--------------------------------------------------------------------------------------