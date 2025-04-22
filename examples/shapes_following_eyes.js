/*******************************************************************************************
*
*   raylib [shapes] example - following eyes
*
*   Example ported to JavaScript with node-raylib
*
*   Example originally created with raylib 2.5, last time updated with raylib 2.5
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2013-2025 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

import { 
  InitWindow, 
  CloseWindow, 
  BeginDrawing, 
  EndDrawing, 
  ClearBackground, 
  DrawCircleV,
  DrawFPS,
  GetMousePosition,
  GetScreenWidth,
  GetScreenHeight,
  CheckCollisionPointCircle,
  SetTargetFPS, 
  WindowShouldClose,
  RAYWHITE,
  LIGHTGRAY,
  BROWN,
  DARKGREEN,
  BLACK
} from '../index.js'

// Initialization
//--------------------------------------------------------------------------------------
const screenWidth = 800
const screenHeight = 450

InitWindow(screenWidth, screenHeight, "raylib [shapes] example - following eyes")

const scleraLeftPosition = { x: GetScreenWidth()/2.0 - 100.0, y: GetScreenHeight()/2.0 }
const scleraRightPosition = { x: GetScreenWidth()/2.0 + 100.0, y: GetScreenHeight()/2.0 }
const scleraRadius = 80

let irisLeftPosition = { x: GetScreenWidth()/2.0 - 100.0, y: GetScreenHeight()/2.0 }
let irisRightPosition = { x: GetScreenWidth()/2.0 + 100.0, y: GetScreenHeight()/2.0 }
const irisRadius = 24

let angle = 0.0
let dx = 0.0, dy = 0.0, dxx = 0.0, dyy = 0.0

SetTargetFPS(60)               // Set our game to run at 60 frames-per-second
//--------------------------------------------------------------------------------------

// Main game loop
while (!WindowShouldClose())    // Detect window close button or ESC key
{
    // Update
    //----------------------------------------------------------------------------------
    const mousePos = GetMousePosition()
    irisLeftPosition = { x: mousePos.x, y: mousePos.y }
    irisRightPosition = { x: mousePos.x, y: mousePos.y }

    // Check not inside the left eye sclera
    if (!CheckCollisionPointCircle(irisLeftPosition, scleraLeftPosition, scleraRadius - irisRadius)) {
        dx = irisLeftPosition.x - scleraLeftPosition.x
        dy = irisLeftPosition.y - scleraLeftPosition.y

        angle = Math.atan2(dy, dx)

        dxx = (scleraRadius - irisRadius) * Math.cos(angle)
        dyy = (scleraRadius - irisRadius) * Math.sin(angle)

        irisLeftPosition.x = scleraLeftPosition.x + dxx
        irisLeftPosition.y = scleraLeftPosition.y + dyy
    }

    // Check not inside the right eye sclera
    if (!CheckCollisionPointCircle(irisRightPosition, scleraRightPosition, scleraRadius - irisRadius)) {
        dx = irisRightPosition.x - scleraRightPosition.x
        dy = irisRightPosition.y - scleraRightPosition.y

        angle = Math.atan2(dy, dx)

        dxx = (scleraRadius - irisRadius) * Math.cos(angle)
        dyy = (scleraRadius - irisRadius) * Math.sin(angle)

        irisRightPosition.x = scleraRightPosition.x + dxx
        irisRightPosition.y = scleraRightPosition.y + dyy
    }
    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing()

        ClearBackground(RAYWHITE)

        DrawCircleV(scleraLeftPosition, scleraRadius, LIGHTGRAY)
        DrawCircleV(irisLeftPosition, irisRadius, BROWN)
        DrawCircleV(irisLeftPosition, 10, BLACK)

        DrawCircleV(scleraRightPosition, scleraRadius, LIGHTGRAY)
        DrawCircleV(irisRightPosition, irisRadius, DARKGREEN)
        DrawCircleV(irisRightPosition, 10, BLACK)

        DrawFPS(10, 10)

    EndDrawing()
    //----------------------------------------------------------------------------------
}

// De-Initialization
//--------------------------------------------------------------------------------------
CloseWindow()        // Close window and OpenGL context
//--------------------------------------------------------------------------------------