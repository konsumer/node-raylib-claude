/*******************************************************************************************
*
*   raylib [text] example - Input Box
*
*   Example ported to JavaScript with node-raylib
*
*   Example originally created with raylib 1.7, last time updated with raylib 3.5
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
  DrawRectangleRec,
  DrawRectangleLines,
  CheckCollisionPointRec,
  GetMousePosition,
  SetMouseCursor,
  GetCharPressed,
  IsKeyPressed,
  MeasureText,
  TextFormat,
  SetTargetFPS, 
  WindowShouldClose,
  KEY_BACKSPACE,
  MOUSE_CURSOR_IBEAM,
  MOUSE_CURSOR_DEFAULT,
  RAYWHITE,
  GRAY,
  LIGHTGRAY,
  RED,
  DARKGRAY,
  MAROON
} from '../index.js'

// Constants
const MAX_INPUT_CHARS = 9

// Initialization
//--------------------------------------------------------------------------------------
const screenWidth = 800
const screenHeight = 450

InitWindow(screenWidth, screenHeight, "raylib [text] example - input box")

let name = ""      // NOTE: One extra space required for null terminator char '\0'
let letterCount = 0

const textBox = { x: screenWidth/2.0 - 100, y: 180, width: 225, height: 50 }
let mouseOnText = false

let framesCounter = 0

SetTargetFPS(60)               // Set our game to run at 60 frames-per-second
//--------------------------------------------------------------------------------------

// Main game loop
while (!WindowShouldClose())    // Detect window close button or ESC key
{
    // Update
    //----------------------------------------------------------------------------------
    if (CheckCollisionPointRec(GetMousePosition(), textBox)) mouseOnText = true
    else mouseOnText = false

    if (mouseOnText)
    {
        // Set the window's cursor to the I-Beam
        SetMouseCursor(MOUSE_CURSOR_IBEAM)

        // Get char pressed (unicode character) on the queue
        let key = GetCharPressed()

        // Check if more characters have been pressed on the same frame
        while (key > 0)
        {
            // NOTE: Only allow keys in range [32..125]
            if ((key >= 32) && (key <= 125) && (letterCount < MAX_INPUT_CHARS))
            {
                name += String.fromCharCode(key)
                letterCount++
            }

            key = GetCharPressed()  // Check next character in the queue
        }

        if (IsKeyPressed(KEY_BACKSPACE))
        {
            letterCount--
            if (letterCount < 0) letterCount = 0
            name = name.substring(0, letterCount)
        }
    }
    else SetMouseCursor(MOUSE_CURSOR_DEFAULT)

    if (mouseOnText) framesCounter++
    else framesCounter = 0
    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing()

        ClearBackground(RAYWHITE)

        DrawText("PLACE MOUSE OVER INPUT BOX!", 240, 140, 20, GRAY)

        DrawRectangleRec(textBox, LIGHTGRAY)
        if (mouseOnText) DrawRectangleLines(textBox.x, textBox.y, textBox.width, textBox.height, RED)
        else DrawRectangleLines(textBox.x, textBox.y, textBox.width, textBox.height, DARKGRAY)

        DrawText(name, textBox.x + 5, textBox.y + 8, 40, MAROON)

        DrawText(TextFormat("INPUT CHARS: %i/%i", letterCount, MAX_INPUT_CHARS), 315, 250, 20, DARKGRAY)

        if (mouseOnText)
        {
            if (letterCount < MAX_INPUT_CHARS)
            {
                // Draw blinking underscore char
                if (((Math.floor(framesCounter/20))%2) == 0) DrawText("_", textBox.x + 8 + MeasureText(name, 40), textBox.y + 12, 40, MAROON)
            }
            else DrawText("Press BACKSPACE to delete chars...", 230, 300, 20, GRAY)
        }

    EndDrawing()
    //----------------------------------------------------------------------------------
}

// De-Initialization
//--------------------------------------------------------------------------------------
CloseWindow()        // Close window and OpenGL context
//--------------------------------------------------------------------------------------