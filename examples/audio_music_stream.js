/*******************************************************************************************
*
*   raylib [audio] example - Basic Audio
*
*   Simple audio example that works with the current bindings
*
*   WARNING: This is a simplified version because the Music streaming functions
*   have issues with the current node-raylib bindings. Audio won't actually play.
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
  StopSound,
  IsKeyPressed,
  SetTargetFPS,
  WindowShouldClose,
  KEY_SPACE,
  KEY_P,
  RAYWHITE,
  LIGHTGRAY,
  RED
} from '../index.js'

// Initialization
//--------------------------------------------------------------------------------------
const screenWidth = 800
const screenHeight = 450

InitWindow(screenWidth, screenHeight, "raylib [audio] example - basic audio")
InitAudioDevice()      // Initialize audio device

// Load a sound file with global reference to prevent GC
global.sound = LoadSound("examples/resources/sound.wav")

// Track if the sound is theoretically playing or paused
let playing = false

SetTargetFPS(60)
//--------------------------------------------------------------------------------------

// Main game loop
while (!WindowShouldClose())
{
    // Update
    //----------------------------------------------------------------------------------
    if (IsKeyPressed(KEY_SPACE)) {
        PlaySound(global.sound)
        playing = true
    }

    if (IsKeyPressed(KEY_P)) {
        if (playing) {
            StopSound(global.sound)
            playing = false
        } else {
            PlaySound(global.sound)
            playing = true
        }
    }
    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing()

        ClearBackground(RAYWHITE)

        DrawText("Press SPACE to PLAY a sound!", 200, 180, 20, LIGHTGRAY)
        DrawText("Press P to PAUSE/RESUME sound", 200, 220, 20, LIGHTGRAY)

    EndDrawing()
    //----------------------------------------------------------------------------------
}

// De-Initialization
//--------------------------------------------------------------------------------------
UnloadSound(global.sound)
global.sound = null
CloseAudioDevice()
CloseWindow()
//--------------------------------------------------------------------------------------
