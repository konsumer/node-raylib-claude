/*******************************************************************************************
*
*   raylib [shaders] example - Postprocessing with custom uniform variable
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
*   Example originally created with raylib 1.3, last time updated with raylib 4.0
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
  BeginTextureMode,
  EndTextureMode,
  BeginShaderMode,
  EndShaderMode,
  ClearBackground,
  DrawFPS,
  DrawText,
  DrawTextureRec,
  DrawModel,
  DrawGrid,
  LoadModel,
  UnloadModel,
  LoadTexture,
  UnloadTexture,
  LoadRenderTexture,
  UnloadRenderTexture,
  TextFormat,
  LoadShader,
  UnloadShader,
  GetShaderLocation,
  SetShaderValue,
  UpdateCamera,
  GetMousePosition,
  WindowShouldClose,
  SetConfigFlags,
  SetTargetFPS,
  RAYWHITE,
  WHITE,
  RED,
  GRAY,
  CAMERA_PERSPECTIVE,
  CAMERA_ORBITAL,
  MATERIAL_MAP_DIFFUSE,
  SHADER_UNIFORM_VEC2,
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

InitWindow(screenWidth, screenHeight, "raylib [shaders] example - custom uniform variable")

// Define the camera to look into our 3d world
const camera = {
    position: { x: 8.0, y: 8.0, z: 8.0 },    // Camera position
    target: { x: 0.0, y: 1.5, z: 0.0 },      // Camera looking at point
    up: { x: 0.0, y: 1.0, z: 0.0 },          // Camera up vector (rotation towards target)
    fovy: 45.0,                              // Camera field-of-view Y
    projection: CAMERA_PERSPECTIVE           // Camera projection type
}

const model = LoadModel("examples/resources/models/barracks.obj")                   // Load OBJ model
const texture = LoadTexture("examples/resources/models/barracks_diffuse.png")   // Load model texture (diffuse map)
// model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture                     // Set model diffuse texture

const position = { x: 0.0, y: 0.0, z: 0.0 }                                    // Set model position

// Load postprocessing shader
// NOTE: Defining 0 (NULL) for vertex shader forces usage of internal default vertex shader
const shader = LoadShader(0, TextFormat("examples/resources/shaders/glsl%i/swirl.fs", GLSL_VERSION))

// Get variable (uniform) location on the shader to connect with the program
// NOTE: If uniform variable could not be found in the shader, function returns -1
const swirlCenterLoc = GetShaderLocation(shader, "center")

const swirlCenter = [screenWidth/2, screenHeight/2]

// Create a RenderTexture2D to be used for render to texture
const target = LoadRenderTexture(screenWidth, screenHeight)

SetTargetFPS(60)                   // Set our game to run at 60 frames-per-second
//--------------------------------------------------------------------------------------

// Main game loop
while (!WindowShouldClose())        // Detect window close button or ESC key
{
    // Update
    //----------------------------------------------------------------------------------
    UpdateCamera(camera, CAMERA_ORBITAL)

    const mousePosition = GetMousePosition()

    swirlCenter[0] = mousePosition.x
    swirlCenter[1] = screenHeight - mousePosition.y

    // Send new value to the shader to be used on drawing
    SetShaderValue(shader, swirlCenterLoc, swirlCenter, SHADER_UNIFORM_VEC2)
    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------
    BeginTextureMode(target)       // Enable drawing to texture
        ClearBackground(RAYWHITE)  // Clear texture background

        BeginMode3D(camera)        // Begin 3d mode drawing
            DrawModel(model, position, 0.5, WHITE)   // Draw 3d model with texture
            DrawGrid(10, 1.0)     // Draw a grid
        EndMode3D()                // End 3d mode drawing, returns to orthographic 2d mode

        DrawText("TEXT DRAWN IN RENDER TEXTURE", 200, 10, 30, RED)
    EndTextureMode()               // End drawing to texture (now we have a texture available for next passes)

    BeginDrawing()
        ClearBackground(RAYWHITE)  // Clear screen background

        // Enable shader using the custom uniform
        BeginShaderMode(shader)
            // NOTE: Render texture must be y-flipped due to default OpenGL coordinates (left-bottom)
            DrawTextureRec(
                target.texture,
                { x: 0, y: 0, width: target.texture.width, height: -target.texture.height },
                { x: 0, y: 0 },
                WHITE
            )
        EndShaderMode()

        // Draw some 2d text over drawn texture
        DrawText("(c) Barracks 3D model by Alberto Cano", screenWidth - 220, screenHeight - 20, 10, GRAY)
        DrawFPS(10, 10)
    EndDrawing()
    //----------------------------------------------------------------------------------
}

// De-Initialization
//--------------------------------------------------------------------------------------
UnloadShader(shader)               // Unload shader
UnloadTexture(texture)             // Unload texture
UnloadModel(model)                 // Unload model
UnloadRenderTexture(target)        // Unload render texture

CloseWindow()                      // Close window and OpenGL context
//--------------------------------------------------------------------------------------
