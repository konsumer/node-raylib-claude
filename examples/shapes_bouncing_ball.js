/*******************************************************************************************
*
*   raylib [shapes] example - bouncing ball
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
  DrawText, 
  DrawCircleV,
  DrawFPS,
  SetConfigFlags,
  GetScreenWidth,
  GetScreenHeight,
  IsKeyPressed,
  SetTargetFPS, 
  WindowShouldClose,
  KEY_SPACE,
  FLAG_MSAA_4X_HINT,
  RAYWHITE,
  MAROON,
  LIGHTGRAY,
  GRAY
} from '../index.js'

// Initialization
//---------------------------------------------------------
const screenWidth = 800
const screenHeight = 450

SetConfigFlags(FLAG_MSAA_4X_HINT)
InitWindow(screenWidth, screenHeight, "raylib [shapes] example - bouncing ball")

const ballPosition = { x: GetScreenWidth()/2.0, y: GetScreenHeight()/2.0 }
const ballSpeed = { x: 5.0, y: 4.0 }
const ballRadius = 20

let pause = false
let framesCounter = 0

SetTargetFPS(60)               // Set our game to run at 60 frames-per-second
//----------------------------------------------------------

// Main game loop
while (!WindowShouldClose())    // Detect window close button or ESC key
{
    // Update
    //-----------------------------------------------------
    if (IsKeyPressed(KEY_SPACE)) pause = !pause

    if (!pause) {
        ballPosition.x += ballSpeed.x
        ballPosition.y += ballSpeed.y

        // Check walls collision for bouncing
        if ((ballPosition.x >= (GetScreenWidth() - ballRadius)) || (ballPosition.x <= ballRadius)) ballSpeed.x *= -1.0
        if ((ballPosition.y >= (GetScreenHeight() - ballRadius)) || (ballPosition.y <= ballRadius)) ballSpeed.y *= -1.0
    }
    else framesCounter++
    //-----------------------------------------------------

    // Draw
    //-----------------------------------------------------
    BeginDrawing()

        ClearBackground(RAYWHITE)

        DrawCircleV(ballPosition, ballRadius, MAROON)
        DrawText("PRESS SPACE to PAUSE BALL MOVEMENT", 10, GetScreenHeight() - 25, 20, LIGHTGRAY)

        // On pause, we draw a blinking message
        if (pause && ((Math.floor(framesCounter/30))%2)) DrawText("PAUSED", 350, 200, 30, GRAY)

        DrawFPS(10, 10)

    EndDrawing()
    //-----------------------------------------------------
}

// De-Initialization
//---------------------------------------------------------
CloseWindow()        // Close window and OpenGL context
//----------------------------------------------------------