/*******************************************************************************************
*
*   raylib [models] example - Load 3d model with animations and play them
*
*   Example ported to JavaScript with node-raylib
*
*   Example originally created with raylib 2.5, last time updated with raylib 3.5
*
*   Example contributed by Culacant (@culacant) and reviewed by Ramon Santamaria (@raysan5)
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2019-2025 Culacant (@culacant) and Ramon Santamaria (@raysan5)
*
********************************************************************************************
*
*   NOTE: To export a model from blender, make sure it is not posed, the vertices need to be 
*         in the same position as they would be in edit mode and the scale of your models is 
*         set to 0. Scaling can be done from the export menu.
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
  DrawModelEx,
  DrawCube,
  DrawGrid,
  LoadModel,
  UnloadModel,
  LoadTexture,
  UnloadTexture,
  LoadModelAnimations,
  UnloadModelAnimations,
  UpdateModelAnimation,
  UpdateCamera,
  SetMaterialTexture,
  DisableCursor,
  IsKeyDown,
  KEY_SPACE,
  CAMERA_FIRST_PERSON,
  CAMERA_PERSPECTIVE,
  MATERIAL_MAP_DIFFUSE,
  RAYWHITE,
  WHITE,
  RED,
  MAROON,
  GRAY
} from '../index.js'

// Initialization
//--------------------------------------------------------------------------------------
const screenWidth = 800
const screenHeight = 450

InitWindow(screenWidth, screenHeight, "raylib [models] example - model animation")

// Define the camera to look into our 3d world
const camera = {
    position: { x: 10.0, y: 10.0, z: 10.0 },  // Camera position
    target: { x: 0.0, y: 0.0, z: 0.0 },       // Camera looking at point
    up: { x: 0.0, y: 1.0, z: 0.0 },           // Camera up vector (rotation towards target)
    fovy: 45.0,                               // Camera field-of-view Y
    projection: CAMERA_PERSPECTIVE            // Camera mode type
}

const model = LoadModel("examples/resources/models/iqm/guy.iqm")                // Load the animated model mesh and basic data
const texture = LoadTexture("examples/resources/models/iqm/guytex.png")        // Load model texture and set material
SetMaterialTexture(model.materials[0], MATERIAL_MAP_DIFFUSE, texture)      // Set model material map texture

const position = { x: 0.0, y: 0.0, z: 0.0 }   // Set model position

// Load animation data
let animsCount = 0
const anims = LoadModelAnimations("examples/resources/models/iqm/guyanim.iqm", animsCount)
let animFrameCounter = 0

DisableCursor()                    // Catch cursor
SetTargetFPS(60)                   // Set our game to run at 60 frames-per-second
//--------------------------------------------------------------------------------------

// Main game loop
while (!WindowShouldClose())        // Detect window close button or ESC key
{
    // Update
    //----------------------------------------------------------------------------------
    UpdateCamera(camera, CAMERA_FIRST_PERSON)

    // Play animation when spacebar is held down
    if (IsKeyDown(KEY_SPACE)) {
        animFrameCounter++
        UpdateModelAnimation(model, anims[0], animFrameCounter)
        if (animFrameCounter >= anims[0].frameCount) animFrameCounter = 0
    }
    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing()

        ClearBackground(RAYWHITE)

        BeginMode3D(camera)

            DrawModelEx(
                model, 
                position, 
                { x: 1.0, y: 0.0, z: 0.0 }, 
                -90.0, 
                { x: 1.0, y: 1.0, z: 1.0 }, 
                WHITE
            )

            for (let i = 0; i < model.boneCount; i++) {
                const translation = anims[0].framePoses[animFrameCounter][i].translation
                DrawCube(translation, 0.2, 0.2, 0.2, RED)
            }

            DrawGrid(10, 1.0)         // Draw a grid

        EndMode3D()

        DrawText("PRESS SPACE to PLAY MODEL ANIMATION", 10, 10, 20, MAROON)
        DrawText("(c) Guy IQM 3D model by @culacant", screenWidth - 200, screenHeight - 20, 10, GRAY)

    EndDrawing()
    //----------------------------------------------------------------------------------
}

// De-Initialization
//--------------------------------------------------------------------------------------
UnloadTexture(texture)                     // Unload texture
UnloadModelAnimations(anims, animsCount)   // Unload model animations data
UnloadModel(model)                         // Unload model

CloseWindow()                  // Close window and OpenGL context
//--------------------------------------------------------------------------------------