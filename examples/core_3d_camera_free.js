/*******************************************************************************************
*
*   raylib [core] example - Initialize 3d camera free
*
*   Example ported to JavaScript with node-raylib
*
*   Example originally created with raylib 1.3, last time updated with raylib 1.3
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2015-2025 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

import { 
  InitWindow, 
  CloseWindow, 
  BeginDrawing, 
  EndDrawing, 
  BeginMode3D,
  EndMode3D,
  ClearBackground, 
  DrawText, 
  DrawRectangle,
  DrawRectangleLines,
  DrawCube,
  DrawCubeWires,
  DrawGrid,
  UpdateCamera,
  DisableCursor,
  SetTargetFPS, 
  WindowShouldClose,
  IsKeyPressed,
  Fade,
  CAMERA_FREE,
  CAMERA_PERSPECTIVE,
  RAYWHITE,
  RED,
  MAROON,
  SKYBLUE,
  BLUE,
  BLACK,
  DARKGRAY
} from '../index.js'

// Initialization
//--------------------------------------------------------------------------------------
const screenWidth = 800
const screenHeight = 450

InitWindow(screenWidth, screenHeight, "raylib [core] example - 3d camera free")

// Define the camera to look into our 3d world
const camera = {
    position: { x: 10.0, y: 10.0, z: 10.0 }, // Camera position
    target: { x: 0.0, y: 0.0, z: 0.0 },      // Camera looking at point
    up: { x: 0.0, y: 1.0, z: 0.0 },          // Camera up vector (rotation towards target)
    fovy: 45.0,                              // Camera field-of-view Y
    projection: CAMERA_PERSPECTIVE           // Camera projection type
}

const cubePosition = { x: 0.0, y: 0.0, z: 0.0 }

DisableCursor()                    // Limit cursor to relative movement inside the window

SetTargetFPS(60)                   // Set our game to run at 60 frames-per-second
//--------------------------------------------------------------------------------------

// Main game loop
while (!WindowShouldClose())        // Detect window close button or ESC key
{
    // Update
    //----------------------------------------------------------------------------------
    UpdateCamera(camera, CAMERA_FREE)

    if (IsKeyPressed('Z'.charCodeAt(0))) camera.target = { x: 0.0, y: 0.0, z: 0.0 }
    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing()

        ClearBackground(RAYWHITE)

        BeginMode3D(camera)

            DrawCube(cubePosition, 2.0, 2.0, 2.0, RED)
            DrawCubeWires(cubePosition, 2.0, 2.0, 2.0, MAROON)

            DrawGrid(10, 1.0)

        EndMode3D()

        DrawRectangle(10, 10, 320, 93, Fade(SKYBLUE, 0.5))
        DrawRectangleLines(10, 10, 320, 93, BLUE)

        DrawText("Free camera default controls:", 20, 20, 10, BLACK)
        DrawText("- Mouse Wheel to Zoom in-out", 40, 40, 10, DARKGRAY)
        DrawText("- Mouse Wheel Pressed to Pan", 40, 60, 10, DARKGRAY)
        DrawText("- Z to zoom to (0, 0, 0)", 40, 80, 10, DARKGRAY)

    EndDrawing()
    //----------------------------------------------------------------------------------
}

// De-Initialization
//--------------------------------------------------------------------------------------
CloseWindow()        // Close window and OpenGL context
//--------------------------------------------------------------------------------------