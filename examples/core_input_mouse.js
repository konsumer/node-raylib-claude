/*******************************************************************************************
*
*   raylib [core] example - Mouse input
*
*   Example ported to JavaScript with node-raylib
*
*   Example originally created with raylib 1.0, last time updated with raylib 5.5
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
  IsKeyPressed,
  KEY_H,
  HideCursor,
  ShowCursor,
  GetMousePosition,
  IsMouseButtonPressed,
  MOUSE_BUTTON_LEFT,
  MOUSE_BUTTON_MIDDLE,
  MOUSE_BUTTON_RIGHT,
  MOUSE_BUTTON_SIDE,
  MOUSE_BUTTON_EXTRA,
  MOUSE_BUTTON_FORWARD,
  MOUSE_BUTTON_BACK,
  RAYWHITE, 
  DARKGRAY,
  DARKBLUE,
  MAROON,
  LIME,
  PURPLE,
  YELLOW,
  ORANGE,
  BEIGE,
  RED
} from '../index.js'

// Initialization
//--------------------------------------------------------------------------------------
const screenWidth = 800
const screenHeight = 450

InitWindow(screenWidth, screenHeight, "raylib [core] example - mouse input")

const ballPosition = { x: -100.0, y: -100.0 }
let ballColor = DARKBLUE
let isCursorHidden = 0

SetTargetFPS(60)               // Set our game to run at 60 frames-per-second
//---------------------------------------------------------------------------------------

// Main game loop
while (!WindowShouldClose())    // Detect window close button or ESC key
{
    // Update
    //----------------------------------------------------------------------------------
    if (IsKeyPressed(KEY_H))
    {
        if (isCursorHidden == 0)
        {
            HideCursor()
            isCursorHidden = 1
        }
        else
        {
            ShowCursor()
            isCursorHidden = 0
        }
    }
    
    const mousePos = GetMousePosition()
    ballPosition.x = mousePos.x
    ballPosition.y = mousePos.y

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) ballColor = MAROON
    else if (IsMouseButtonPressed(MOUSE_BUTTON_MIDDLE)) ballColor = LIME
    else if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) ballColor = DARKBLUE
    else if (IsMouseButtonPressed(MOUSE_BUTTON_SIDE)) ballColor = PURPLE
    else if (IsMouseButtonPressed(MOUSE_BUTTON_EXTRA)) ballColor = YELLOW
    else if (IsMouseButtonPressed(MOUSE_BUTTON_FORWARD)) ballColor = ORANGE
    else if (IsMouseButtonPressed(MOUSE_BUTTON_BACK)) ballColor = BEIGE
    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing()

    ClearBackground(RAYWHITE)

    DrawCircleV(ballPosition, 40, ballColor)

    DrawText("move ball with mouse and click mouse button to change color", 10, 10, 20, DARKGRAY)
    DrawText("Press 'H' to toggle cursor visibility", 10, 30, 20, DARKGRAY)

    if (isCursorHidden == 1) 
        DrawText("CURSOR HIDDEN", 20, 60, 20, RED)
    else 
        DrawText("CURSOR VISIBLE", 20, 60, 20, LIME)

    EndDrawing()
    //----------------------------------------------------------------------------------
}

// De-Initialization
//--------------------------------------------------------------------------------------
CloseWindow()        // Close window and OpenGL context
//--------------------------------------------------------------------------------------