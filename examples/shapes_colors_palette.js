/*******************************************************************************************
*
*   raylib [shapes] example - Colors palette
*
*   Example ported to JavaScript with node-raylib
*
*   Example originally created with raylib 1.0, last time updated with raylib 2.5
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
  DrawRectangle,
  DrawRectangleRec,
  DrawRectangleLinesEx,
  SetTargetFPS, 
  WindowShouldClose,
  GetMousePosition,
  CheckCollisionPointRec,
  IsKeyDown,
  GetScreenWidth,
  GetScreenHeight,
  MeasureText,
  Fade,
  KEY_SPACE,
  RAYWHITE,
  BLACK,
  GRAY,
  DARKGRAY, MAROON, ORANGE, DARKGREEN, DARKBLUE, DARKPURPLE, DARKBROWN,
  RED, GOLD, LIME, BLUE, VIOLET, BROWN, LIGHTGRAY, PINK, YELLOW,
  GREEN, SKYBLUE, PURPLE, BEIGE
} from '../index.js'

// Initialization
//--------------------------------------------------------------------------------------
const screenWidth = 800
const screenHeight = 450

InitWindow(screenWidth, screenHeight, "raylib [shapes] example - colors palette")

const MAX_COLORS_COUNT = 21  // Number of colors available

const colors = [
    DARKGRAY, MAROON, ORANGE, DARKGREEN, DARKBLUE, DARKPURPLE, DARKBROWN,
    GRAY, RED, GOLD, LIME, BLUE, VIOLET, BROWN, LIGHTGRAY, PINK, YELLOW,
    GREEN, SKYBLUE, PURPLE, BEIGE
]

const colorNames = [
    "DARKGRAY", "MAROON", "ORANGE", "DARKGREEN", "DARKBLUE", "DARKPURPLE",
    "DARKBROWN", "GRAY", "RED", "GOLD", "LIME", "BLUE", "VIOLET", "BROWN",
    "LIGHTGRAY", "PINK", "YELLOW", "GREEN", "SKYBLUE", "PURPLE", "BEIGE"
]

const colorsRecs = []     // Rectangles array

// Fills colorsRecs data (for every rectangle)
for (let i = 0; i < MAX_COLORS_COUNT; i++)
{
    colorsRecs.push({
        x: 20 + 100*(i%7) + 10*(i%7),
        y: 80 + 100*Math.floor(i/7) + 10*Math.floor(i/7),
        width: 100,
        height: 100
    })
}

const colorState = new Array(MAX_COLORS_COUNT).fill(0)  // Color state: 0-DEFAULT, 1-MOUSE_HOVER

let mousePoint = { x: 0, y: 0 }

SetTargetFPS(60)               // Set our game to run at 60 frames-per-second
//--------------------------------------------------------------------------------------

// Main game loop
while (!WindowShouldClose())    // Detect window close button or ESC key
{
    // Update
    //----------------------------------------------------------------------------------
    mousePoint = GetMousePosition()

    for (let i = 0; i < MAX_COLORS_COUNT; i++)
    {
        if (CheckCollisionPointRec(mousePoint, colorsRecs[i])) colorState[i] = 1
        else colorState[i] = 0
    }
    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing()

    ClearBackground(RAYWHITE)

    DrawText("raylib colors palette", 28, 42, 20, BLACK)
    DrawText("press SPACE to see all colors", GetScreenWidth() - 180, GetScreenHeight() - 40, 10, GRAY)

    for (let i = 0; i < MAX_COLORS_COUNT; i++)    // Draw all rectangles
    {
        DrawRectangleRec(colorsRecs[i], Fade(colors[i], colorState[i] ? 0.6 : 1.0))

        if (IsKeyDown(KEY_SPACE) || colorState[i])
        {
            DrawRectangle(
                colorsRecs[i].x, 
                colorsRecs[i].y + colorsRecs[i].height - 26, 
                colorsRecs[i].width, 
                20, 
                BLACK
            )
            
            DrawRectangleLinesEx(colorsRecs[i], 6, Fade(BLACK, 0.3))
            
            DrawText(
                colorNames[i], 
                colorsRecs[i].x + colorsRecs[i].width - MeasureText(colorNames[i], 10) - 12,
                colorsRecs[i].y + colorsRecs[i].height - 20, 
                10, 
                colors[i]
            )
        }
    }

    EndDrawing()
    //----------------------------------------------------------------------------------
}

// De-Initialization
//--------------------------------------------------------------------------------------
CloseWindow()                // Close window and OpenGL context
//--------------------------------------------------------------------------------------