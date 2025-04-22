/*******************************************************************************************
*
*   raylib [core] example - 2d camera mouse zoom
*
*   Example ported to JavaScript with node-raylib
*
*   Example originally created with raylib 4.2, last time updated with raylib 4.2
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2022-2025 Jeffery Myers (@JeffM2501)
*
********************************************************************************************/

import { 
  InitWindow, 
  CloseWindow, 
  BeginDrawing, 
  EndDrawing, 
  ClearBackground, 
  BeginMode2D,
  EndMode2D, 
  DrawGrid,
  DrawCircle,
  DrawCircleV,
  DrawText,
  DrawTextEx,
  GetFontDefault,
  WindowShouldClose,
  IsKeyPressed,
  IsMouseButtonDown,
  IsMouseButtonPressed,
  GetMouseDelta,
  Vector2Scale,
  Vector2Add,
  GetMouseWheelMove,
  GetScreenToWorld2D,
  GetMousePosition,
  Clamp,
  TextFormat,
  GetMouseX,
  GetMouseY,
  GetScreenWidth,
  GetScreenHeight,
  SetTargetFPS,
  RAYWHITE,
  MAROON,
  DARKGRAY,
  BLACK,
  KEY_ONE,
  KEY_TWO,
  MOUSE_BUTTON_LEFT,
  MOUSE_BUTTON_RIGHT
} from '../index.js'

// rlgl functions that need to be handled
const rlPushMatrix = () => {}
const rlPopMatrix = () => {}
const rlTranslatef = (x, y, z) => {}
const rlRotatef = (angle, x, y, z) => {}

// Similar to Math.abs but for floats
const fabsf = Math.abs

// Initialization
//--------------------------------------------------------------------------------------
const screenWidth = 800
const screenHeight = 450

InitWindow(screenWidth, screenHeight, "raylib [core] example - 2d camera mouse zoom")

const camera = { 
  offset: { x: 0, y: 0 },
  target: { x: 0, y: 0 },
  rotation: 0,
  zoom: 1.0
}

let zoomMode = 0   // 0-Mouse Wheel, 1-Mouse Move

SetTargetFPS(60)               // Set our game to run at 60 frames-per-second
//--------------------------------------------------------------------------------------

// Main game loop
while (!WindowShouldClose())    // Detect window close button or ESC key
{
    // Update
    //----------------------------------------------------------------------------------
    if (IsKeyPressed(KEY_ONE)) zoomMode = 0
    else if (IsKeyPressed(KEY_TWO)) zoomMode = 1
    
    // Translate based on mouse right click
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
    {
        const delta = GetMouseDelta()
        const scaledDelta = Vector2Scale(delta, -1.0/camera.zoom)
        camera.target = Vector2Add(camera.target, scaledDelta)
    }

    if (zoomMode == 0)
    {
        // Zoom based on mouse wheel
        const wheel = GetMouseWheelMove()
        if (wheel != 0)
        {
            // Get the world point that is under the mouse
            const mouseWorldPos = GetScreenToWorld2D(GetMousePosition(), camera)

            // Set the offset to where the mouse is
            camera.offset = GetMousePosition()

            // Set the target to match, so that the camera maps the world space point 
            // under the cursor to the screen space point under the cursor at any zoom
            camera.target = mouseWorldPos

            // Zoom increment
            const scaleFactor = 1.0 + (0.25*fabsf(wheel))
            if (wheel < 0) 
                camera.zoom = camera.zoom / scaleFactor
            else
                camera.zoom = camera.zoom * scaleFactor
            
            camera.zoom = Clamp(camera.zoom, 0.125, 64.0)
        }
    }
    else
    {
        // Zoom based on mouse right click
        if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
        {
            // Get the world point that is under the mouse
            const mouseWorldPos = GetScreenToWorld2D(GetMousePosition(), camera)

            // Set the offset to where the mouse is
            camera.offset = GetMousePosition()

            // Set the target to match, so that the camera maps the world space point 
            // under the cursor to the screen space point under the cursor at any zoom
            camera.target = mouseWorldPos
        }
        if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
        {
            // Zoom increment
            const deltaX = GetMouseDelta().x
            const scaleFactor = 1.0 + (0.01*fabsf(deltaX))
            if (deltaX < 0)
                camera.zoom = camera.zoom / scaleFactor
            else
                camera.zoom = camera.zoom * scaleFactor
            
            camera.zoom = Clamp(camera.zoom, 0.125, 64.0)
        }
    }
    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing()
        ClearBackground(RAYWHITE)

        BeginMode2D(camera)

            // Draw the 3d grid, rotated 90 degrees and centered around 0,0 
            // just so we have something in the XY plane
            rlPushMatrix()
                rlTranslatef(0, 25*50, 0)
                rlRotatef(90, 1, 0, 0)
                DrawGrid(100, 50)
            rlPopMatrix()

            // Draw a reference circle
            DrawCircle(GetScreenWidth()/2, GetScreenHeight()/2, 50, MAROON)
            
        EndMode2D()
        
        // Draw mouse reference
        DrawCircleV(GetMousePosition(), 4, DARKGRAY)
        DrawTextEx(GetFontDefault(), TextFormat("[%i, %i]", GetMouseX(), GetMouseY()), 
            Vector2Add(GetMousePosition(), { x: -44, y: -24 }), 20, 2, BLACK)

        DrawText("[1][2] Select mouse zoom mode (Wheel or Move)", 20, 20, 20, DARKGRAY)
        if (zoomMode == 0) 
            DrawText("Mouse left button drag to move, mouse wheel to zoom", 20, 50, 20, DARKGRAY)
        else 
            DrawText("Mouse left button drag to move, mouse press and move to zoom", 20, 50, 20, DARKGRAY)
    
    EndDrawing()
    //----------------------------------------------------------------------------------
}

// De-Initialization
//--------------------------------------------------------------------------------------
CloseWindow()        // Close window and OpenGL context
//--------------------------------------------------------------------------------------