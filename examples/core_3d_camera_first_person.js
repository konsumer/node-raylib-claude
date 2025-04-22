/*******************************************************************************************
*
*   raylib [core] example - 3d camera first person
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
  ClearBackground,
  BeginMode3D,
  EndMode3D,
  DrawPlane,
  DrawCube,
  DrawCubeWires,
  DrawRectangle,
  DrawRectangleLines,
  DrawText,
  UpdateCamera,
  DisableCursor,
  GetRandomValue,
  IsKeyPressed,
  WindowShouldClose,
  Fade,
  TextFormat,
  SetTargetFPS,
  RAYWHITE,
  LIGHTGRAY,
  BLUE,
  LIME,
  GOLD,
  MAROON,
  PURPLE,
  DARKPURPLE,
  SKYBLUE,
  BLACK,
  CAMERA_FIRST_PERSON,
  CAMERA_FREE,
  CAMERA_THIRD_PERSON,
  CAMERA_ORBITAL,
  CAMERA_PERSPECTIVE,
  CAMERA_ORTHOGRAPHIC,
  KEY_ONE,
  KEY_TWO,
  KEY_THREE,
  KEY_FOUR,
  KEY_P
} from '../index.js'

const MAX_COLUMNS = 20
const DEG2RAD = Math.PI/180.0

// Function stubs for camera operations which aren't exported directly
// You may need to implement these functions or find proper equivalents
const CameraYaw = (camera, angle, rotateAroundTarget) => {
  // This would be implemented based on the rcamera.h implementation
}

const CameraPitch = (camera, angle, lockView, rotateAroundTarget, rotateUp) => {
  // This would be implemented based on the rcamera.h implementation
}

// Initialization
//--------------------------------------------------------------------------------------
const screenWidth = 800
const screenHeight = 450

InitWindow(screenWidth, screenHeight, "raylib [core] example - 3d camera first person")

// Define the camera to look into our 3d world (position, target, up vector)
const camera = {
  position: { x: 0.0, y: 2.0, z: 4.0 },    // Camera position
  target: { x: 0.0, y: 2.0, z: 0.0 },      // Camera looking at point
  up: { x: 0.0, y: 1.0, z: 0.0 },          // Camera up vector (rotation towards target)
  fovy: 60.0,                              // Camera field-of-view Y
  projection: CAMERA_PERSPECTIVE           // Camera projection type
}

let cameraMode = CAMERA_FIRST_PERSON

// Generates some random columns
const heights = Array(MAX_COLUMNS).fill(0).map(() => GetRandomValue(1, 12))
const positions = Array(MAX_COLUMNS).fill(0).map((v, i) => ({
  x: GetRandomValue(-15, 15),
  y: heights[i]/2.0,
  z: GetRandomValue(-15, 15)
}))
const colors = Array(MAX_COLUMNS).fill(0).map(() => ({
  r: GetRandomValue(20, 255),
  g: GetRandomValue(10, 55),
  b: 30,
  a: 255
}))

DisableCursor()                    // Limit cursor to relative movement inside the window

SetTargetFPS(60)                   // Set our game to run at 60 frames-per-second
//--------------------------------------------------------------------------------------

// Main game loop
while (!WindowShouldClose())        // Detect window close button or ESC key
{
    // Update
    //----------------------------------------------------------------------------------
    // Switch camera mode
    if (IsKeyPressed(KEY_ONE)) {
        cameraMode = CAMERA_FREE
        camera.up = { x: 0.0, y: 1.0, z: 0.0 } // Reset roll
    }

    if (IsKeyPressed(KEY_TWO)) {
        cameraMode = CAMERA_FIRST_PERSON
        camera.up = { x: 0.0, y: 1.0, z: 0.0 } // Reset roll
    }

    if (IsKeyPressed(KEY_THREE)) {
        cameraMode = CAMERA_THIRD_PERSON
        camera.up = { x: 0.0, y: 1.0, z: 0.0 } // Reset roll
    }

    if (IsKeyPressed(KEY_FOUR)) {
        cameraMode = CAMERA_ORBITAL
        camera.up = { x: 0.0, y: 1.0, z: 0.0 } // Reset roll
    }

    // Switch camera projection
    if (IsKeyPressed(KEY_P)) {
        if (camera.projection == CAMERA_PERSPECTIVE) {
            // Create isometric view
            cameraMode = CAMERA_THIRD_PERSON
            // Note: The target distance is related to the render distance in the orthographic projection
            camera.position = { x: 0.0, y: 2.0, z: -100.0 }
            camera.target = { x: 0.0, y: 2.0, z: 0.0 }
            camera.up = { x: 0.0, y: 1.0, z: 0.0 }
            camera.projection = CAMERA_ORTHOGRAPHIC
            camera.fovy = 20.0 // near plane width in CAMERA_ORTHOGRAPHIC

            // Note: These camera operations may need implementation or alternatives
            // CameraYaw(&camera, -135 * DEG2RAD, true)
            // CameraPitch(&camera, -45 * DEG2RAD, true, true, false)
        }
        else if (camera.projection == CAMERA_ORTHOGRAPHIC) {
            // Reset to default view
            cameraMode = CAMERA_THIRD_PERSON
            camera.position = { x: 0.0, y: 2.0, z: 10.0 }
            camera.target = { x: 0.0, y: 2.0, z: 0.0 }
            camera.up = { x: 0.0, y: 1.0, z: 0.0 }
            camera.projection = CAMERA_PERSPECTIVE
            camera.fovy = 60.0
        }
    }

    // Update camera computes movement internally depending on the camera mode
    // Some default standard keyboard/mouse inputs are hardcoded to simplify use
    // For advance camera controls, it's recommended to compute camera movement manually
    UpdateCamera(camera, cameraMode)         // Update camera
    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing()

        ClearBackground(RAYWHITE)

        BeginMode3D(camera)

            DrawPlane({ x: 0.0, y: 0.0, z: 0.0 }, { x: 32.0, y: 32.0 }, LIGHTGRAY) // Draw ground
            DrawCube({ x: -16.0, y: 2.5, z: 0.0 }, 1.0, 5.0, 32.0, BLUE)     // Draw a blue wall
            DrawCube({ x: 16.0, y: 2.5, z: 0.0 }, 1.0, 5.0, 32.0, LIME)      // Draw a green wall
            DrawCube({ x: 0.0, y: 2.5, z: 16.0 }, 32.0, 5.0, 1.0, GOLD)      // Draw a yellow wall

            // Draw some cubes around
            for (let i = 0; i < MAX_COLUMNS; i++) {
                DrawCube(positions[i], 2.0, heights[i], 2.0, colors[i])
                DrawCubeWires(positions[i], 2.0, heights[i], 2.0, MAROON)
            }

            // Draw player cube
            if (cameraMode == CAMERA_THIRD_PERSON) {
                DrawCube(camera.target, 0.5, 0.5, 0.5, PURPLE)
                DrawCubeWires(camera.target, 0.5, 0.5, 0.5, DARKPURPLE)
            }

        EndMode3D()

        // Draw info boxes
        DrawRectangle(5, 5, 330, 100, Fade(SKYBLUE, 0.5))
        DrawRectangleLines(5, 5, 330, 100, BLUE)

        DrawText("Camera controls:", 15, 15, 10, BLACK)
        DrawText("- Move keys: W, A, S, D, Space, Left-Ctrl", 15, 30, 10, BLACK)
        DrawText("- Look around: arrow keys or mouse", 15, 45, 10, BLACK)
        DrawText("- Camera mode keys: 1, 2, 3, 4", 15, 60, 10, BLACK)
        DrawText("- Zoom keys: num-plus, num-minus or mouse scroll", 15, 75, 10, BLACK)
        DrawText("- Camera projection key: P", 15, 90, 10, BLACK)

        DrawRectangle(600, 5, 195, 100, Fade(SKYBLUE, 0.5))
        DrawRectangleLines(600, 5, 195, 100, BLUE)

        DrawText("Camera status:", 610, 15, 10, BLACK)

        let cameraModeName = "CUSTOM"
        if (cameraMode == CAMERA_FREE) cameraModeName = "FREE"
        else if (cameraMode == CAMERA_FIRST_PERSON) cameraModeName = "FIRST_PERSON"
        else if (cameraMode == CAMERA_THIRD_PERSON) cameraModeName = "THIRD_PERSON"
        else if (cameraMode == CAMERA_ORBITAL) cameraModeName = "ORBITAL"

        DrawText(`- Mode: ${cameraModeName}`, 610, 30, 10, BLACK)

        let projectionName = "CUSTOM"
        if (camera.projection == CAMERA_PERSPECTIVE) projectionName = "PERSPECTIVE"
        else if (camera.projection == CAMERA_ORTHOGRAPHIC) projectionName = "ORTHOGRAPHIC"

        DrawText(`- Projection: ${projectionName}`, 610, 45, 10, BLACK)
        DrawText(TextFormat("- Position: (%06.3f, %06.3f, %06.3f)",
            camera.position.x, camera.position.y, camera.position.z), 610, 60, 10, BLACK)
        DrawText(TextFormat("- Target: (%06.3f, %06.3f, %06.3f)",
            camera.target.x, camera.target.y, camera.target.z), 610, 75, 10, BLACK)
        DrawText(TextFormat("- Up: (%06.3f, %06.3f, %06.3f)",
            camera.up.x, camera.up.y, camera.up.z), 610, 90, 10, BLACK)

    EndDrawing()
    //----------------------------------------------------------------------------------
}

// De-Initialization
//--------------------------------------------------------------------------------------
CloseWindow()        // Close window and OpenGL context
//--------------------------------------------------------------------------------------
