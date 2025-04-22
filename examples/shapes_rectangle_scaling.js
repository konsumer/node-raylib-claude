/*******************************************************************************************
*
*   raylib [shapes] example - rectangle scaling by mouse
*
*   Example ported to JavaScript with node-raylib
*
*   Example originally created with raylib 2.5, last time updated with raylib 2.5
*
*   Example contributed by Vlad Adrian (@demizdor) and reviewed by Ramon Santamaria (@raysan5)
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2018-2025 Vlad Adrian (@demizdor) and Ramon Santamaria (@raysan5)
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
  DrawRectangleLinesEx,
  DrawTriangle,
  SetTargetFPS, 
  WindowShouldClose,
  GetMousePosition,
  CheckCollisionPointRec,
  IsMouseButtonPressed,
  IsMouseButtonReleased,
  GetScreenWidth,
  GetScreenHeight,
  Fade,
  MOUSE_BUTTON_LEFT,
  RAYWHITE,
  GRAY,
  GREEN,
  RED
} from '../index.js'

// Initialization
//--------------------------------------------------------------------------------------
const screenWidth = 800
const screenHeight = 450

const MOUSE_SCALE_MARK_SIZE = 12

InitWindow(screenWidth, screenHeight, "raylib [shapes] example - rectangle scaling mouse")

const rec = { x: 100, y: 100, width: 200, height: 80 }

let mousePosition = { x: 0, y: 0 }

let mouseScaleReady = false
let mouseScaleMode = false

SetTargetFPS(60)               // Set our game to run at 60 frames-per-second
//--------------------------------------------------------------------------------------

// Main game loop
while (!WindowShouldClose())    // Detect window close button or ESC key
{
    // Update
    //----------------------------------------------------------------------------------
    mousePosition = GetMousePosition()

    if (CheckCollisionPointRec(mousePosition, {
        x: rec.x + rec.width - MOUSE_SCALE_MARK_SIZE,
        y: rec.y + rec.height - MOUSE_SCALE_MARK_SIZE,
        width: MOUSE_SCALE_MARK_SIZE, 
        height: MOUSE_SCALE_MARK_SIZE
    }))
    {
        mouseScaleReady = true
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) mouseScaleMode = true
    }
    else mouseScaleReady = false

    if (mouseScaleMode)
    {
        mouseScaleReady = true

        rec.width = (mousePosition.x - rec.x)
        rec.height = (mousePosition.y - rec.y)

        // Check minimum rec size
        if (rec.width < MOUSE_SCALE_MARK_SIZE) rec.width = MOUSE_SCALE_MARK_SIZE
        if (rec.height < MOUSE_SCALE_MARK_SIZE) rec.height = MOUSE_SCALE_MARK_SIZE
        
        // Check maximum rec size
        if (rec.width > (GetScreenWidth() - rec.x)) rec.width = GetScreenWidth() - rec.x
        if (rec.height > (GetScreenHeight() - rec.y)) rec.height = GetScreenHeight() - rec.y

        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) mouseScaleMode = false
    }
    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing()

    ClearBackground(RAYWHITE)

    DrawText("Scale rectangle dragging from bottom-right corner!", 10, 10, 20, GRAY)

    DrawRectangleRec(rec, Fade(GREEN, 0.5))

    if (mouseScaleReady)
    {
        DrawRectangleLinesEx(rec, 1, RED)
        DrawTriangle(
            { x: rec.x + rec.width - MOUSE_SCALE_MARK_SIZE, y: rec.y + rec.height },
            { x: rec.x + rec.width, y: rec.y + rec.height },
            { x: rec.x + rec.width, y: rec.y + rec.height - MOUSE_SCALE_MARK_SIZE },
            RED
        )
    }

    EndDrawing()
    //----------------------------------------------------------------------------------
}

// De-Initialization
//--------------------------------------------------------------------------------------
CloseWindow()        // Close window and OpenGL context
//--------------------------------------------------------------------------------------