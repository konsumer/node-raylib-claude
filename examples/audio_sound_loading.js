/*******************************************************************************************
*
*   raylib [audio] example - Sound loading and playing
*
*   Example ported to JavaScript with node-raylib
*   NOTE: Due to current binding limitations, audio won't actually be heard
*
*   Example originally created with raylib 1.1, last time updated with raylib 3.5
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
  ClearBackground,
  DrawText,
  InitAudioDevice,
  CloseAudioDevice,
  LoadSound,
  UnloadSound,
  PlaySound,
  IsKeyPressed,
  SetTargetFPS,
  WindowShouldClose,
  KEY_SPACE,
  KEY_ENTER,
  RAYWHITE,
  LIGHTGRAY,
  RED
} from '../index.js'

// Initialization
//--------------------------------------------------------------------------------------
const screenWidth = 800
const screenHeight = 450

InitWindow(screenWidth, screenHeight, "raylib [audio] example - sound loading and playing")

InitAudioDevice()      // Initialize audio device

// Create global references to audio objects to prevent garbage collection
// This is important to keep the sounds from being collected while the C code uses them
global.soundWav = LoadSound("examples/resources/sound.wav")
global.soundOgg = LoadSound("examples/resources/target.ogg")

SetTargetFPS(60)               // Set our game to run at 60 frames-per-second
//--------------------------------------------------------------------------------------

// Main game loop
while (!WindowShouldClose())    // Detect window close button or ESC key
{
    // Update
    //----------------------------------------------------------------------------------
    if (IsKeyPressed(KEY_SPACE)) PlaySound(global.soundWav)      // Play WAV sound
    if (IsKeyPressed(KEY_ENTER)) PlaySound(global.soundOgg)      // Play OGG sound
    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing()

        ClearBackground(RAYWHITE)

        DrawText("Press SPACE to PLAY the WAV sound!", 200, 180, 20, LIGHTGRAY)
        DrawText("Press ENTER to PLAY the OGG sound!", 200, 220, 20, LIGHTGRAY)

    EndDrawing()
    //----------------------------------------------------------------------------------
}

// De-Initialization
//--------------------------------------------------------------------------------------
UnloadSound(global.soundWav)     // Unload sound data
UnloadSound(global.soundOgg)     // Unload sound data
global.soundWav = null           // Clear the global references
global.soundOgg = null

CloseAudioDevice()     // Close audio device

CloseWindow()          // Close window and OpenGL context
//--------------------------------------------------------------------------------------
