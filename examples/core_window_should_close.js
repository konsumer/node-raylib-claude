/*******************************************************************************************
*
*   raylib [core] example - Window should close
*
*   Example ported to JavaScript with node-raylib
*
*   Example originally created with raylib 4.2, last time updated with raylib 4.2
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
  DrawRectangle,
  SetTargetFPS, 
  WindowShouldClose,
  IsKeyPressed,
  SetExitKey,
  KEY_NULL,
  KEY_ESCAPE,
  KEY_Y,
  KEY_N,
  RAYWHITE,
  BLACK,
  WHITE,
  LIGHTGRAY
} from '../index.js'

// Initialization
//--------------------------------------------------------------------------------------
const screenWidth = 800
const screenHeight = 450

InitWindow(screenWidth, screenHeight, "raylib [core] example - window should close")

SetExitKey(KEY_NULL)       // Disable KEY_ESCAPE to close window, X-button still works

let exitWindowRequested = false   // Flag to request window to exit
let exitWindow = false    // Flag to set window to exit

SetTargetFPS(60)           // Set our game to run at 60 frames-per-second
//--------------------------------------------------------------------------------------

// Main game loop
while (!exitWindow)
{
    // Update
    //----------------------------------------------------------------------------------
    // Detect if X-button or KEY_ESCAPE have been pressed to close window
    if (WindowShouldClose() || IsKeyPressed(KEY_ESCAPE)) exitWindowRequested = true
    
    if (exitWindowRequested)
    {
        // A request for close window has been issued, we can save data before closing
        // or just show a message asking for confirmation
        
        if (IsKeyPressed(KEY_Y)) exitWindow = true
        else if (IsKeyPressed(KEY_N)) exitWindowRequested = false
    }
    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing()

    ClearBackground(RAYWHITE)

    if (exitWindowRequested)
    {
        DrawRectangle(0, 100, screenWidth, 200, BLACK)
        DrawText("Are you sure you want to exit program? [Y/N]", 40, 180, 30, WHITE)
    }
    else DrawText("Try to close the window to get confirmation message!", 120, 200, 20, LIGHTGRAY)

    EndDrawing()
    //----------------------------------------------------------------------------------
}

// De-Initialization
//--------------------------------------------------------------------------------------
CloseWindow()        // Close window and OpenGL context
//--------------------------------------------------------------------------------------