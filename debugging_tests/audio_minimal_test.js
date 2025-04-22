/*******************************************************************************************
*
*   raylib [audio] example - Sound loading and playing (instrumented)
*
*   Based on the original audio_sound_loading.js example but with debugging
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
//--------------------------------------------------------------------------------------
console.log("Starting instrumented test...")
const screenWidth = 800
const screenHeight = 450

console.log("Initializing window...")
InitWindow(screenWidth, screenHeight, "raylib [audio] example - sound loading and playing (debug)")
console.log("Window initialized")

console.log("Initializing audio device...")
InitAudioDevice()      // Initialize audio device
console.log("Audio device initialized")

console.log("Loading WAV sound...")
const fxWav = LoadSound("examples/resources/sound.wav")         // Load WAV audio file
console.log("WAV sound loaded")

console.log("Loading OGG sound...")
const fxOgg = LoadSound("examples/resources/target.ogg")        // Load OGG audio file
console.log("OGG sound loaded")

console.log("Setting target FPS...")
SetTargetFPS(60)               // Set our game to run at 60 frames-per-second
console.log("Target FPS set")
//--------------------------------------------------------------------------------------

// Run for limited time and count frames
let frameCount = 0
const MAX_FRAMES = 300  // 5 seconds at 60 FPS

console.log("Entering main loop...")
// Main game loop
while (!WindowShouldClose() && frameCount < MAX_FRAMES)    // Detect window close button or ESC key
{
    frameCount++;
    
    // Update
    //----------------------------------------------------------------------------------
    if (IsKeyPressed(KEY_SPACE)) {
        console.log("Playing WAV sound")
        PlaySound(fxWav)      // Play WAV sound
    }
    
    if (IsKeyPressed(KEY_ENTER)) {
        console.log("Playing OGG sound")
        PlaySound(fxOgg)      // Play OGG sound
    }
    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing()

        ClearBackground(RAYWHITE)

        DrawText("Press SPACE to PLAY the WAV sound!", 200, 180, 20, LIGHTGRAY)
        DrawText("Press ENTER to PLAY the OGG sound!", 200, 220, 20, LIGHTGRAY)
        DrawText(`Frame count: ${frameCount}`, 200, 260, 20, LIGHTGRAY)

    EndDrawing()
    //----------------------------------------------------------------------------------
}
console.log("Main loop completed")

// De-Initialization
//--------------------------------------------------------------------------------------
console.log("Unloading WAV sound...")
UnloadSound(fxWav)     // Unload sound data
console.log("WAV sound unloaded")

console.log("Unloading OGG sound...")
UnloadSound(fxOgg)     // Unload sound data
console.log("OGG sound unloaded")

console.log("Closing audio device...")
CloseAudioDevice()     // Close audio device
console.log("Audio device closed")

console.log("Closing window...")
CloseWindow()          // Close window and OpenGL context
console.log("Window closed")

console.log("Test completed successfully")