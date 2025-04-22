/*******************************************************************************************
*
*   raylib [core] example - Windows drop files
*
*   Example ported to JavaScript with node-raylib
*
*   NOTE: This example only works on platforms that support drag & drop (Windows, Linux, OSX, Html5?)
*
*   Example originally created with raylib 1.3, last time updated with raylib 4.2
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
  DrawText, 
  DrawRectangle,
  IsFileDropped,
  LoadDroppedFiles,
  UnloadDroppedFiles,
  TextCopy,
  Fade,
  SetTargetFPS, 
  WindowShouldClose,
  RAYWHITE,
  DARKGRAY,
  LIGHTGRAY,
  GRAY
} from '../index.js'

// Constants
const MAX_FILEPATH_RECORDED = 4096
const MAX_FILEPATH_SIZE = 2048

// Initialization
//--------------------------------------------------------------------------------------
const screenWidth = 800
const screenHeight = 450

InitWindow(screenWidth, screenHeight, "raylib [core] example - drop files")

let filePathCounter = 0
const filePaths = new Array(MAX_FILEPATH_RECORDED).fill('') // We will register a maximum of filepaths

SetTargetFPS(60)               // Set our game to run at 60 frames-per-second
//--------------------------------------------------------------------------------------

// Main game loop
while (!WindowShouldClose())    // Detect window close button or ESC key
{
    // Update
    //----------------------------------------------------------------------------------
    if (IsFileDropped()) {
        const droppedFiles = LoadDroppedFiles()

        for (let i = 0, offset = filePathCounter; i < droppedFiles.count; i++) {
            if (filePathCounter < (MAX_FILEPATH_RECORDED - 1)) {
                filePaths[offset + i] = droppedFiles.paths[i]
                filePathCounter++
            }
        }

        UnloadDroppedFiles(droppedFiles)    // Unload filepaths from memory
    }
    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing()

        ClearBackground(RAYWHITE)

        if (filePathCounter == 0) DrawText("Drop your files to this window!", 100, 40, 20, DARKGRAY)
        else {
            DrawText("Dropped files:", 100, 40, 20, DARKGRAY)

            for (let i = 0; i < filePathCounter; i++) {
                if (i%2 == 0) DrawRectangle(0, 85 + 40*i, screenWidth, 40, Fade(LIGHTGRAY, 0.5))
                else DrawRectangle(0, 85 + 40*i, screenWidth, 40, Fade(LIGHTGRAY, 0.3))

                DrawText(filePaths[i], 120, 100 + 40*i, 10, GRAY)
            }

            DrawText("Drop new files...", 100, 110 + 40*filePathCounter, 20, DARKGRAY)
        }

    EndDrawing()
    //----------------------------------------------------------------------------------
}

// De-Initialization
//--------------------------------------------------------------------------------------
CloseWindow()          // Close window and OpenGL context
//--------------------------------------------------------------------------------------