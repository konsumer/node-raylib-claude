/*******************************************************************************************
*
*   raylib [audio] example - Safe Sound Loading and Playing
*
*   A version designed to work around binding limitations
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
  LIGHTGRAY
} from '../index.js'

// Initialization
const screenWidth = 800
const screenHeight = 450

InitWindow(screenWidth, screenHeight, "raylib [audio] example - safe sound playing")
InitAudioDevice()

// Load sounds with global references to prevent garbage collection
global.wavSound = LoadSound("examples/resources/sound.wav")
global.oggSound = LoadSound("examples/resources/target.ogg")

SetTargetFPS(60)

// Main game loop - only running for a fixed duration
let frames = 0
const MAX_FRAMES = 300 // Run for 5 seconds (60 fps × 5)

while (!WindowShouldClose() && frames < MAX_FRAMES) {
    frames++
    
    // Check for key presses to play sounds
    if (IsKeyPressed(KEY_SPACE)) {
        PlaySound(global.wavSound)
    }
    
    if (IsKeyPressed(KEY_ENTER)) {
        PlaySound(global.oggSound)
    }
    
    // Render
    BeginDrawing()
    
        ClearBackground(RAYWHITE)
        DrawText("Press SPACE to play WAV sound", 200, 180, 20, LIGHTGRAY)
        DrawText("Press ENTER to play OGG sound", 200, 220, 20, LIGHTGRAY)
        DrawText(`Frame: ${frames}/${MAX_FRAMES}`, 200, 260, 20, LIGHTGRAY)
    
    EndDrawing()
}

// Cleanup
UnloadSound(global.wavSound)
UnloadSound(global.oggSound)
global.wavSound = null
global.oggSound = null

CloseAudioDevice()
CloseWindow()