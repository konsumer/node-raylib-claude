/*******************************************************************************************
*
*   raylib [shaders] example - Model shader
*
*   Example ported to JavaScript with node-raylib
*
*   NOTE: This example requires raylib OpenGL 3.3 or ES2 versions for shaders support,
*         OpenGL 1.1 does not support shaders, recompile raylib to OpenGL 3.3 version.
*
*   NOTE: Shaders used in this example are #version 330 (OpenGL 3.3), to test this example
*         on OpenGL ES 2.0 platforms (Android, Raspberry Pi, HTML5), use #version 100 shaders
*         raylib comes with shaders ready for both versions, check raylib/shaders install folder
*
*   Example originally created with raylib 1.3, last time updated with raylib 3.7
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
  DrawText,
  DrawModel,
  DrawGrid,
  LoadModel,
  UnloadModel,
  LoadTexture,
  UnloadTexture,
  TextFormat,
  LoadShader,
  UnloadShader,
  UpdateCamera,
  DisableCursor,
  SetConfigFlags,
  WindowShouldClose,
  SetTargetFPS,
  RAYWHITE,
  WHITE,
  GRAY,
  CAMERA_PERSPECTIVE,
  CAMERA_FREE,
  MATERIAL_MAP_DIFFUSE,
  FLAG_MSAA_4X_HINT
} from '../index.js'

// Initialization
//--------------------------------------------------------------------------------------
const screenWidth = 800
const screenHeight = 450

// Define platform-specific GLSL version
let GLSL_VERSION = 330
if (process.platform === 'android' || process.platform === 'web') {
  GLSL_VERSION = 100
}

SetConfigFlags(FLAG_MSAA_4X_HINT)      // Enable Multi Sampling Anti Aliasing 4x (if available)

InitWindow(screenWidth, screenHeight, "raylib [shaders] example - model shader")

// Define the camera to look into our 3d world
const camera = {
    position: { x: 4.0, y: 4.0, z: 4.0 },    // Camera position
    target: { x: 0.0, y: 1.0, z: -1.0 },     // Camera looking at point
    up: { x: 0.0, y: 1.0, z: 0.0 },          // Camera up vector (rotation towards target)
    fovy: 45.0,                              // Camera field-of-view Y
    projection: CAMERA_PERSPECTIVE           // Camera projection type
}

const model = LoadModel("resources/models/watermill.obj")                   // Load OBJ model
const texture = LoadTexture("resources/models/watermill_diffuse.png")   // Load model texture

// Load shader for model
// NOTE: Defining 0 (NULL) for vertex shader forces usage of internal default vertex shader
const shader = LoadShader(0, TextFormat("resources/shaders/glsl%i/grayscale.fs", GLSL_VERSION))

model.materials[0].shader = shader                 // Set shader effect to 3d model
model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture // Bind texture to model

const position = { x: 0.0, y: 0.0, z: 0.0 }    // Set model position

DisableCursor()                    // Limit cursor to relative movement inside the window
SetTargetFPS(60)                   // Set our game to run at 60 frames-per-second
//--------------------------------------------------------------------------------------

// Main game loop
while (!WindowShouldClose())        // Detect window close button or ESC key
{
    // Update
    //----------------------------------------------------------------------------------
    UpdateCamera(camera, CAMERA_FREE)
    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing()

        ClearBackground(RAYWHITE)

        BeginMode3D(camera)

            DrawModel(model, position, 0.2, WHITE)   // Draw 3d model with texture

            DrawGrid(10, 1.0)     // Draw a grid

        EndMode3D()

        DrawText("(c) Watermill 3D model by Alberto Cano", screenWidth - 210, screenHeight - 20, 10, GRAY)

        DrawFPS(10, 10)

    EndDrawing()
    //----------------------------------------------------------------------------------
}

// De-Initialization
//--------------------------------------------------------------------------------------
UnloadShader(shader)       // Unload shader
UnloadTexture(texture)     // Unload texture
UnloadModel(model)         // Unload model

CloseWindow()              // Close window and OpenGL context
//--------------------------------------------------------------------------------------