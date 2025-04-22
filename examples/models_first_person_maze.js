/*******************************************************************************************
*
*   raylib [models] example - first person maze
*
*   Example ported to JavaScript with node-raylib
*
*   Example originally created with raylib 2.5, last time updated with raylib 3.5
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2019-2025 Ramon Santamaria (@raysan5)
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
  DrawModel,
  DrawTextureEx,
  DrawRectangle,
  DrawRectangleLines,
  LoadImage,
  UnloadImage,
  LoadTexture,
  UnloadTexture,
  LoadTextureFromImage,
  LoadImageColors,
  UnloadImageColors,
  GenMeshCubicmap,
  LoadModelFromMesh,
  UnloadModel,
  UpdateCamera,
  DisableCursor,
  CheckCollisionCircleRec,
  GetScreenWidth,
  GetScreenHeight,
  SetTargetFPS, 
  WindowShouldClose,
  CAMERA_FIRST_PERSON,
  CAMERA_PERSPECTIVE,
  MATERIAL_MAP_DIFFUSE,
  RAYWHITE,
  WHITE,
  GREEN,
  RED
} from '../index.js'

// Initialization
//--------------------------------------------------------------------------------------
const screenWidth = 800
const screenHeight = 450

InitWindow(screenWidth, screenHeight, "raylib [models] example - first person maze")

// Define the camera to look into our 3d world
const camera = {
    position: { x: 0.2, y: 0.4, z: 0.2 },    // Camera position
    target: { x: 0.185, y: 0.4, z: 0.0 },    // Camera looking at point
    up: { x: 0.0, y: 1.0, z: 0.0 },          // Camera up vector (rotation towards target)
    fovy: 45.0,                              // Camera field-of-view Y
    projection: CAMERA_PERSPECTIVE           // Camera projection type
}

const imMap = LoadImage("examples/resources/cubicmap.png")      // Load cubicmap image (RAM)
const cubicmap = LoadTextureFromImage(imMap)       // Convert image to texture to display (VRAM)
const mesh = GenMeshCubicmap(imMap, { x: 1.0, y: 1.0, z: 1.0 })
const model = LoadModelFromMesh(mesh)

// NOTE: By default each cube is mapped to one part of texture atlas
const texture = LoadTexture("examples/resources/cubicmap_atlas.png")    // Load map texture
model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture    // Set map diffuse texture

// Get map image data to be used for collision detection
const mapPixels = LoadImageColors(imMap)
UnloadImage(imMap)             // Unload image from RAM

const mapPosition = { x: -16.0, y: 0.0, z: -8.0 }  // Set model position

DisableCursor()                // Limit cursor to relative movement inside the window

SetTargetFPS(60)               // Set our game to run at 60 frames-per-second
//--------------------------------------------------------------------------------------

// Main game loop
while (!WindowShouldClose())    // Detect window close button or ESC key
{
    // Update
    //----------------------------------------------------------------------------------
    const oldCamPos = { x: camera.position.x, y: camera.position.y, z: camera.position.z }    // Store old camera position

    UpdateCamera(camera, CAMERA_FIRST_PERSON)

    // Check player collision (we simplify to 2D collision detection)
    const playerPos = { x: camera.position.x, y: camera.position.z }
    const playerRadius = 0.1  // Collision radius (player is modelled as a cilinder for collision)

    let playerCellX = Math.floor(playerPos.x - mapPosition.x + 0.5)
    let playerCellY = Math.floor(playerPos.y - mapPosition.z + 0.5)

    // Out-of-limits security check
    if (playerCellX < 0) playerCellX = 0
    else if (playerCellX >= cubicmap.width) playerCellX = cubicmap.width - 1

    if (playerCellY < 0) playerCellY = 0
    else if (playerCellY >= cubicmap.height) playerCellY = cubicmap.height - 1

    // Check map collisions using image data and player position
    // TODO: Improvement: Just check player surrounding cells for collision
    for (let y = 0; y < cubicmap.height; y++) {
        for (let x = 0; x < cubicmap.width; x++) {
            if ((mapPixels[y*cubicmap.width + x].r === 255) &&       // Collision: white pixel, only check R channel
                (CheckCollisionCircleRec(
                    playerPos, 
                    playerRadius,
                    { 
                        x: mapPosition.x - 0.5 + x*1.0, 
                        y: mapPosition.z - 0.5 + y*1.0, 
                        width: 1.0, 
                        height: 1.0 
                    }
                ))) {
                // Collision detected, reset camera position
                camera.position = oldCamPos
            }
        }
    }
    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing()

        ClearBackground(RAYWHITE)

        BeginMode3D(camera)
            DrawModel(model, mapPosition, 1.0, WHITE)                     // Draw maze map
        EndMode3D()

        DrawTextureEx(cubicmap, { x: GetScreenWidth() - cubicmap.width*4.0 - 20, y: 20.0 }, 0.0, 4.0, WHITE)
        DrawRectangleLines(GetScreenWidth() - cubicmap.width*4 - 20, 20, cubicmap.width*4, cubicmap.height*4, GREEN)

        // Draw player position radar
        DrawRectangle(GetScreenWidth() - cubicmap.width*4 - 20 + playerCellX*4, 20 + playerCellY*4, 4, 4, RED)

        DrawFPS(10, 10)

    EndDrawing()
    //----------------------------------------------------------------------------------
}

// De-Initialization
//--------------------------------------------------------------------------------------
UnloadImageColors(mapPixels)   // Unload color array

UnloadTexture(cubicmap)        // Unload cubicmap texture
UnloadTexture(texture)         // Unload map texture
UnloadModel(model)             // Unload map model

CloseWindow()                  // Close window and OpenGL context
//--------------------------------------------------------------------------------------