/*******************************************************************************************
*
*   raylib [core] example - 2d camera split screen
*
*   Example ported to JavaScript with node-raylib
*
*   Addapted from the core_3d_camera_split_screen example:
*       https://github.com/raysan5/raylib/blob/master/examples/core/core_3d_camera_split_screen.c
*
*   Example originally created with raylib 4.5, last time updated with raylib 4.5
*
*   Example contributed by Gabriel dos Santos Sanches (@gabrielssanches) and reviewed by Ramon Santamaria (@raysan5)
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2023-2025 Gabriel dos Santos Sanches (@gabrielssanches)
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
  BeginTextureMode,
  EndTextureMode,
  DrawLineV,
  DrawRectangleRec,
  DrawRectangle,
  DrawText,
  DrawTextureRec,
  LoadRenderTexture,
  UnloadRenderTexture,
  TextFormat,
  Fade,
  IsKeyDown,
  WindowShouldClose,
  GetScreenWidth,
  GetScreenHeight,
  SetTargetFPS,
  RAYWHITE,
  BLACK,
  LIGHTGRAY,
  RED,
  BLUE,
  MAROON,
  DARKBLUE,
  WHITE,
  KEY_W,
  KEY_A,
  KEY_S,
  KEY_D,
  KEY_UP,
  KEY_DOWN,
  KEY_LEFT,
  KEY_RIGHT
} from '../index.js'

const PLAYER_SIZE = 40

// Initialization
//--------------------------------------------------------------------------------------
const screenWidth = 800
const screenHeight = 440

InitWindow(screenWidth, screenHeight, "raylib [core] example - 2d camera split screen")

const player1 = { x: 200, y: 200, width: PLAYER_SIZE, height: PLAYER_SIZE }
const player2 = { x: 250, y: 200, width: PLAYER_SIZE, height: PLAYER_SIZE }

const camera1 = {
  target: { x: player1.x, y: player1.y },
  offset: { x: 200.0, y: 200.0 },
  rotation: 0.0,
  zoom: 1.0
}

const camera2 = {
  target: { x: player2.x, y: player2.y },
  offset: { x: 200.0, y: 200.0 },
  rotation: 0.0,
  zoom: 1.0
}

const screenCamera1 = LoadRenderTexture(screenWidth/2, screenHeight)
const screenCamera2 = LoadRenderTexture(screenWidth/2, screenHeight)

// Build a flipped rectangle the size of the split view to use for drawing later
const splitScreenRect = {
  x: 0.0,
  y: 0.0,
  width: screenCamera1?.texture?.width || 0,
  height: -screenCamera1?.texture?.height || 0
}

SetTargetFPS(60)               // Set our game to run at 60 frames-per-second
//--------------------------------------------------------------------------------------

// Main game loop
while (!WindowShouldClose())    // Detect window close button or ESC key
{
    // Update
    //----------------------------------------------------------------------------------
    if (IsKeyDown(KEY_S)) player1.y += 3.0
    else if (IsKeyDown(KEY_W)) player1.y -= 3.0
    if (IsKeyDown(KEY_D)) player1.x += 3.0
    else if (IsKeyDown(KEY_A)) player1.x -= 3.0

    if (IsKeyDown(KEY_UP)) player2.y -= 3.0
    else if (IsKeyDown(KEY_DOWN)) player2.y += 3.0
    if (IsKeyDown(KEY_RIGHT)) player2.x += 3.0
    else if (IsKeyDown(KEY_LEFT)) player2.x -= 3.0

    camera1.target = { x: player1.x, y: player1.y }
    camera2.target = { x: player2.x, y: player2.y }
    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------
    BeginTextureMode(screenCamera1)
        ClearBackground(RAYWHITE)

        BeginMode2D(camera1)

            // Draw full scene with first camera
            for (let i = 0; i < screenWidth/PLAYER_SIZE + 1; i++) {
                DrawLineV(
                    { x: PLAYER_SIZE*i, y: 0 },
                    { x: PLAYER_SIZE*i, y: screenHeight },
                    LIGHTGRAY
                )
            }

            for (let i = 0; i < screenHeight/PLAYER_SIZE + 1; i++) {
                DrawLineV(
                    { x: 0, y: PLAYER_SIZE*i },
                    { x: screenWidth, y: PLAYER_SIZE*i },
                    LIGHTGRAY
                )
            }

            for (let i = 0; i < screenWidth/PLAYER_SIZE; i++) {
                for (let j = 0; j < screenHeight/PLAYER_SIZE; j++) {
                    DrawText(TextFormat("[%i,%i]", i, j), 10 + PLAYER_SIZE*i, 15 + PLAYER_SIZE*j, 10, LIGHTGRAY)
                }
            }

            DrawRectangleRec(player1, RED)
            DrawRectangleRec(player2, BLUE)
        EndMode2D()

        DrawRectangle(0, 0, GetScreenWidth()/2, 30, Fade(RAYWHITE, 0.6))
        DrawText("PLAYER1: W/S/A/D to move", 10, 10, 10, MAROON)

    EndTextureMode()

    BeginTextureMode(screenCamera2)
        ClearBackground(RAYWHITE)

        BeginMode2D(camera2)

            // Draw full scene with second camera
            for (let i = 0; i < screenWidth/PLAYER_SIZE + 1; i++) {
                DrawLineV(
                    { x: PLAYER_SIZE*i, y: 0 },
                    { x: PLAYER_SIZE*i, y: screenHeight },
                    LIGHTGRAY
                )
            }

            for (let i = 0; i < screenHeight/PLAYER_SIZE + 1; i++) {
                DrawLineV(
                    { x: 0, y: PLAYER_SIZE*i },
                    { x: screenWidth, y: PLAYER_SIZE*i },
                    LIGHTGRAY
                )
            }

            for (let i = 0; i < screenWidth/PLAYER_SIZE; i++) {
                for (let j = 0; j < screenHeight/PLAYER_SIZE; j++) {
                    DrawText(TextFormat("[%i,%i]", i, j), 10 + PLAYER_SIZE*i, 15 + PLAYER_SIZE*j, 10, LIGHTGRAY)
                }
            }

            DrawRectangleRec(player1, RED)
            DrawRectangleRec(player2, BLUE)

        EndMode2D()

        DrawRectangle(0, 0, GetScreenWidth()/2, 30, Fade(RAYWHITE, 0.6))
        DrawText("PLAYER2: UP/DOWN/LEFT/RIGHT to move", 10, 10, 10, DARKBLUE)

    EndTextureMode()

    // Draw both views render textures to the screen side by side
    BeginDrawing()
        ClearBackground(BLACK)

        DrawTextureRec(screenCamera1.texture, splitScreenRect, { x: 0, y: 0 }, WHITE)
        DrawTextureRec(screenCamera2.texture, splitScreenRect, { x: screenWidth/2.0, y: 0 }, WHITE)

        DrawRectangle(GetScreenWidth()/2 - 2, 0, 4, GetScreenHeight(), LIGHTGRAY)
    EndDrawing()
}

// De-Initialization
//--------------------------------------------------------------------------------------
UnloadRenderTexture(screenCamera1) // Unload render texture
UnloadRenderTexture(screenCamera2) // Unload render texture

CloseWindow()        // Close window and OpenGL context
//--------------------------------------------------------------------------------------
