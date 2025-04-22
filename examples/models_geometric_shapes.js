/*******************************************************************************************
*
*   raylib [models] example - Draw some basic geometric shapes (cube, sphere, cylinder...)
*
*   Example ported to JavaScript with node-raylib
*
*   Example originally created with raylib 1.0, last time updated with raylib 3.5
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
  BeginMode3D,
  EndMode3D,
  ClearBackground, 
  DrawFPS, 
  DrawCube,
  DrawCubeWires,
  DrawSphere,
  DrawSphereWires,
  DrawCylinder,
  DrawCylinderWires,
  DrawCapsule,
  DrawCapsuleWires,
  DrawGrid,
  SetTargetFPS, 
  WindowShouldClose,
  CAMERA_PERSPECTIVE,
  RAYWHITE,
  RED,
  GOLD,
  MAROON,
  GREEN,
  LIME,
  SKYBLUE,
  DARKBLUE,
  BROWN,
  PINK,
  VIOLET,
  PURPLE
} from '../index.js'

// Initialization
//--------------------------------------------------------------------------------------
const screenWidth = 800
const screenHeight = 450

InitWindow(screenWidth, screenHeight, "raylib [models] example - geometric shapes")

// Define the camera to look into our 3d world
const camera = {
    position: { x: 0.0, y: 10.0, z: 10.0 },
    target: { x: 0.0, y: 0.0, z: 0.0 },
    up: { x: 0.0, y: 1.0, z: 0.0 },
    fovy: 45.0,
    projection: CAMERA_PERSPECTIVE
}

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

        BeginMode3D(camera)

            DrawCube({x: -4.0, y: 0.0, z: 2.0}, 2.0, 5.0, 2.0, RED)
            DrawCubeWires({x: -4.0, y: 0.0, z: 2.0}, 2.0, 5.0, 2.0, GOLD)
            DrawCubeWires({x: -4.0, y: 0.0, z: -2.0}, 3.0, 6.0, 2.0, MAROON)

            DrawSphere({x: -1.0, y: 0.0, z: -2.0}, 1.0, GREEN)
            DrawSphereWires({x: 1.0, y: 0.0, z: 2.0}, 2.0, 16, 16, LIME)

            DrawCylinder({x: 4.0, y: 0.0, z: -2.0}, 1.0, 2.0, 3.0, 4, SKYBLUE)
            DrawCylinderWires({x: 4.0, y: 0.0, z: -2.0}, 1.0, 2.0, 3.0, 4, DARKBLUE)
            DrawCylinderWires({x: 4.5, y: -1.0, z: 2.0}, 1.0, 1.0, 2.0, 6, BROWN)

            DrawCylinder({x: 1.0, y: 0.0, z: -4.0}, 0.0, 1.5, 3.0, 8, GOLD)
            DrawCylinderWires({x: 1.0, y: 0.0, z: -4.0}, 0.0, 1.5, 3.0, 8, PINK)

            DrawCapsule({x: -3.0, y: 1.5, z: -4.0}, {x: -4.0, y: -1.0, z: -4.0}, 1.2, 8, 8, VIOLET)
            DrawCapsuleWires({x: -3.0, y: 1.5, z: -4.0}, {x: -4.0, y: -1.0, z: -4.0}, 1.2, 8, 8, PURPLE)

            DrawGrid(10, 1.0)        // Draw a grid

        EndMode3D()

        DrawFPS(10, 10)

    EndDrawing()
    //----------------------------------------------------------------------------------
}

// De-Initialization
//--------------------------------------------------------------------------------------
CloseWindow()        // Close window and OpenGL context
//--------------------------------------------------------------------------------------