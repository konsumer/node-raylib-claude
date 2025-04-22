/*******************************************************************************************
*
*   raylib [core] example - Keyboard input
*
*   Example ported to JavaScript with node-raylib
*
*   Example originally created with raylib 1.0, last time updated with raylib 1.0
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2014-2025 Ramon Santamaria (@raysan5)
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
  SetTargetFPS, 
  WindowShouldClose,
  IsKeyDown,
  KEY_RIGHT,
  KEY_LEFT,
  KEY_UP,
  KEY_DOWN,
  RAYWHITE, 
  DARKGRAY,
  MAROON
} from '../index.js'

// Initialization
//--------------------------------------------------------------------------------------
const screenWidth = 800
const screenHeight = 450

InitWindow(screenWidth, screenHeight, "raylib [core] example - keyboard input")

const ballPosition = { x: screenWidth/2, y: screenHeight/2 }

SetTargetFPS(60)               // Set our game to run at 60 frames-per-second
//--------------------------------------------------------------------------------------

// Main game loop
while (!WindowShouldClose())    // Detect window close button or ESC key
{
    // Update
    //----------------------------------------------------------------------------------
    if (IsKeyDown(KEY_RIGHT)) ballPosition.x += 2.0
    if (IsKeyDown(KEY_LEFT)) ballPosition.x -= 2.0
    if (IsKeyDown(KEY_UP)) ballPosition.y -= 2.0
    if (IsKeyDown(KEY_DOWN)) ballPosition.y += 2.0
    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing()

    ClearBackground(RAYWHITE)

    DrawText("move the ball with arrow keys", 10, 10, 20, DARKGRAY)

    DrawCircleV(ballPosition, 50, MAROON)

    EndDrawing()
    //----------------------------------------------------------------------------------
}

// De-Initialization
//--------------------------------------------------------------------------------------
CloseWindow()        // Close window and OpenGL context
//--------------------------------------------------------------------------------------