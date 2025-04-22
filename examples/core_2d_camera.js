/*******************************************************************************************
*
*   raylib [core] example - 2D Camera system
*
*   Example ported to JavaScript with node-raylib
*
*   Example originally created with raylib 1.5, last time updated with raylib 3.0
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2016-2025 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

import { 
  InitWindow, 
  CloseWindow, 
  BeginDrawing, 
  EndDrawing, 
  BeginMode2D,
  EndMode2D,
  ClearBackground, 
  DrawText, 
  DrawRectangle,
  DrawRectangleRec,
  DrawRectangleLines,
  DrawLine,
  Fade,
  GetRandomValue,
  GetMouseWheelMove,
  IsKeyDown,
  IsKeyPressed,
  SetTargetFPS, 
  WindowShouldClose,
  KEY_RIGHT,
  KEY_LEFT,
  KEY_A,
  KEY_S,
  KEY_R,
  RAYWHITE,
  RED,
  GREEN,
  DARKGRAY,
  BLUE,
  SKYBLUE,
  BLACK
} from '../index.js'

// Constants
const MAX_BUILDINGS = 100

// Initialization
//--------------------------------------------------------------------------------------
const screenWidth = 800
const screenHeight = 450

InitWindow(screenWidth, screenHeight, "raylib [core] example - 2d camera")

const player = { x: 400, y: 280, width: 40, height: 40 }
const buildings = []
const buildColors = []

let spacing = 0

for (let i = 0; i < MAX_BUILDINGS; i++) {
    buildings[i] = {
        width: GetRandomValue(50, 200),
        height: GetRandomValue(100, 800),
        y: screenHeight - 130.0 - GetRandomValue(100, 800),
        x: -6000.0 + spacing
    }

    spacing += buildings[i].width

    buildColors[i] = {
        r: GetRandomValue(200, 240),
        g: GetRandomValue(200, 240),
        b: GetRandomValue(200, 250),
        a: 255
    }
}

const camera = {
    target: { x: player.x + 20.0, y: player.y + 20.0 },
    offset: { x: screenWidth/2.0, y: screenHeight/2.0 },
    rotation: 0.0,
    zoom: 1.0
}

SetTargetFPS(60)                   // Set our game to run at 60 frames-per-second
//--------------------------------------------------------------------------------------

// Main game loop
while (!WindowShouldClose())        // Detect window close button or ESC key
{
    // Update
    //----------------------------------------------------------------------------------
    // Player movement
    if (IsKeyDown(KEY_RIGHT)) player.x += 2
    else if (IsKeyDown(KEY_LEFT)) player.x -= 2

    // Camera target follows player
    camera.target.x = player.x + 20
    camera.target.y = player.y + 20

    // Camera rotation controls
    if (IsKeyDown(KEY_A)) camera.rotation--
    else if (IsKeyDown(KEY_S)) camera.rotation++

    // Limit camera rotation to 80 degrees (-40 to 40)
    if (camera.rotation > 40) camera.rotation = 40
    else if (camera.rotation < -40) camera.rotation = -40

    // Camera zoom controls
    // Uses log scaling to provide consistent zoom speed
    camera.zoom = Math.exp(Math.log(camera.zoom) + (GetMouseWheelMove()*0.1))

    if (camera.zoom > 3.0) camera.zoom = 3.0
    else if (camera.zoom < 0.1) camera.zoom = 0.1

    // Camera reset (zoom and rotation)
    if (IsKeyPressed(KEY_R)) {
        camera.zoom = 1.0
        camera.rotation = 0.0
    }
    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing()

        ClearBackground(RAYWHITE)

        BeginMode2D(camera)

            DrawRectangle(-6000, 320, 13000, 8000, DARKGRAY)

            for (let i = 0; i < MAX_BUILDINGS; i++) DrawRectangleRec(buildings[i], buildColors[i])

            DrawRectangleRec(player, RED)

            DrawLine(Math.floor(camera.target.x), -screenHeight*10, Math.floor(camera.target.x), screenHeight*10, GREEN)
            DrawLine(-screenWidth*10, Math.floor(camera.target.y), screenWidth*10, Math.floor(camera.target.y), GREEN)

        EndMode2D()

        DrawText("SCREEN AREA", 640, 10, 20, RED)

        DrawRectangle(0, 0, screenWidth, 5, RED)
        DrawRectangle(0, 5, 5, screenHeight - 10, RED)
        DrawRectangle(screenWidth - 5, 5, 5, screenHeight - 10, RED)
        DrawRectangle(0, screenHeight - 5, screenWidth, 5, RED)

        DrawRectangle(10, 10, 250, 113, Fade(SKYBLUE, 0.5))
        DrawRectangleLines(10, 10, 250, 113, BLUE)

        DrawText("Free 2d camera controls:", 20, 20, 10, BLACK)
        DrawText("- Right/Left to move Offset", 40, 40, 10, DARKGRAY)
        DrawText("- Mouse Wheel to Zoom in-out", 40, 60, 10, DARKGRAY)
        DrawText("- A / S to Rotate", 40, 80, 10, DARKGRAY)
        DrawText("- R to reset Zoom and Rotation", 40, 100, 10, DARKGRAY)

    EndDrawing()
    //----------------------------------------------------------------------------------
}

// De-Initialization
//--------------------------------------------------------------------------------------
CloseWindow()        // Close window and OpenGL context
//--------------------------------------------------------------------------------------