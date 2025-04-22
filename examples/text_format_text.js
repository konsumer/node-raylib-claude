/*******************************************************************************************
*
*   raylib [text] example - Text formatting
*
*   Example ported to JavaScript with node-raylib
*
*   Example originally created with raylib 1.1, last time updated with raylib 3.0
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
  TextFormat,
  GetFrameTime,
  SetTargetFPS, 
  WindowShouldClose,
  RAYWHITE,
  RED,
  GREEN,
  BLUE,
  BLACK
} from '../index.js'

// Initialization
//--------------------------------------------------------------------------------------
const screenWidth = 800
const screenHeight = 450

InitWindow(screenWidth, screenHeight, "raylib [text] example - text formatting")

let score = 100020
let hiscore = 200450
let lives = 5

SetTargetFPS(60)               // Set our game to run at 60 frames-per-second
//--------------------------------------------------------------------------------------

// Main game loop
while (!WindowShouldClose())    // Detect window close button or ESC key
{
    // Update
    //----------------------------------------------------------------------------------
    // TODO: Update your variables here
    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing()

    ClearBackground(RAYWHITE)

    DrawText(TextFormat("Score: %08i", score), 200, 80, 20, RED)

    DrawText(TextFormat("HiScore: %08i", hiscore), 200, 120, 20, GREEN)

    DrawText(TextFormat("Lives: %02i", lives), 200, 160, 40, BLUE)

    DrawText(TextFormat("Elapsed Time: %02.02f ms", GetFrameTime()*1000), 200, 220, 20, BLACK)

    EndDrawing()
    //----------------------------------------------------------------------------------
}

// De-Initialization
//--------------------------------------------------------------------------------------
CloseWindow()        // Close window and OpenGL context
//--------------------------------------------------------------------------------------