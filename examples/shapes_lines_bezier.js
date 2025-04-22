/*******************************************************************************************
*
*   raylib [shapes] example - Cubic-bezier lines
*
*   Example ported to JavaScript with node-raylib
*
*   Example originally created with raylib 1.7, last time updated with raylib 1.7
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2017-2025 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

import { 
  InitWindow, 
  CloseWindow, 
  BeginDrawing, 
  EndDrawing, 
  ClearBackground, 
  DrawText, 
  DrawLineBezier,
  DrawCircleV,
  SetTargetFPS, 
  WindowShouldClose,
  SetConfigFlags,
  GetMousePosition,
  CheckCollisionPointCircle,
  IsMouseButtonDown,
  IsMouseButtonReleased,
  MOUSE_BUTTON_LEFT,
  FLAG_MSAA_4X_HINT,
  RAYWHITE,
  GRAY,
  BLUE,
  RED
} from '../index.js'

// Initialization
//--------------------------------------------------------------------------------------
const screenWidth = 800
const screenHeight = 450

SetConfigFlags(FLAG_MSAA_4X_HINT)
InitWindow(screenWidth, screenHeight, "raylib [shapes] example - cubic-bezier lines")

const startPoint = { x: 30, y: 30 }
const endPoint = { x: screenWidth - 30, y: screenHeight - 30 }
let moveStartPoint = false
let moveEndPoint = false

SetTargetFPS(60)               // Set our game to run at 60 frames-per-second
//--------------------------------------------------------------------------------------

// Main game loop
while (!WindowShouldClose())    // Detect window close button or ESC key
{
    // Update
    //----------------------------------------------------------------------------------
    const mouse = GetMousePosition()

    if (CheckCollisionPointCircle(mouse, startPoint, 10.0) && IsMouseButtonDown(MOUSE_BUTTON_LEFT)) moveStartPoint = true
    else if (CheckCollisionPointCircle(mouse, endPoint, 10.0) && IsMouseButtonDown(MOUSE_BUTTON_LEFT)) moveEndPoint = true

    if (moveStartPoint)
    {
        startPoint.x = mouse.x
        startPoint.y = mouse.y
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) moveStartPoint = false
    }

    if (moveEndPoint)
    {
        endPoint.x = mouse.x
        endPoint.y = mouse.y
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) moveEndPoint = false
    }
    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing()

        ClearBackground(RAYWHITE)

        DrawText("MOVE START-END POINTS WITH MOUSE", 15, 20, 20, GRAY)

        // Draw line Cubic Bezier, in-out interpolation (easing), no control points
        DrawLineBezier(startPoint, endPoint, 4.0, BLUE)
        
        // Draw start-end spline circles with some details
        DrawCircleV(startPoint, CheckCollisionPointCircle(mouse, startPoint, 10.0) ? 14.0 : 8.0, moveStartPoint ? RED : BLUE)
        DrawCircleV(endPoint, CheckCollisionPointCircle(mouse, endPoint, 10.0) ? 14.0 : 8.0, moveEndPoint ? RED : BLUE)

    EndDrawing()
    //----------------------------------------------------------------------------------
}

// De-Initialization
//--------------------------------------------------------------------------------------
CloseWindow()        // Close window and OpenGL context
//--------------------------------------------------------------------------------------