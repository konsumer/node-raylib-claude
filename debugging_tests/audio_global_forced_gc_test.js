/*******************************************************************************************
*
*   raylib [audio] example - Global References with Forced GC Test
*
*   Test that uses global references and forces garbage collection to test robustness
*
********************************************************************************************/

import { 
  InitWindow, 
  CloseWindow, 
  InitAudioDevice,
  CloseAudioDevice,
  LoadSound,
  UnloadSound,
  PlaySound,
  BeginDrawing,
  EndDrawing,
  ClearBackground,
  DrawText,
  RAYWHITE,
  LIGHTGRAY
} from '../index.js'

// To use this test, run with: node --expose-gc examples/audio_global_forced_gc_test.js

console.log("Starting global references with forced GC test")

// Initialize
console.log("Initializing window")
InitWindow(800, 450, "Audio Global Refs + Forced GC Test")

console.log("Initializing audio device")
InitAudioDevice()

// Load sound with global reference to protect from GC
console.log("Loading sound with global reference for GC protection")
global.sound = LoadSound("examples/resources/sound.wav")
console.log("Sound loaded, playing it once")
PlaySound(global.sound)

// If we have access to the explicit garbage collector, use it
if (global.gc) {
  console.log("Explicit GC available, will force garbage collection...")
  
  // Run a short loop that forces garbage collection between frames
  for (let i = 0; i < 5; i++) {
    console.log(`Iteration ${i+1}: Forcing garbage collection...`)
    global.gc()
    
    BeginDrawing()
    ClearBackground(RAYWHITE)
    DrawText(`Forced GC iteration: ${i+1}`, 200, 180, 20, LIGHTGRAY)
    DrawText(`Using global.sound reference for protection`, 150, 220, 20, LIGHTGRAY)
    EndDrawing()
  }
} else {
  console.log("Explicit GC not available. Run with: node --expose-gc examples/audio_global_forced_gc_test.js")
  
  // Just render a few frames
  for (let i = 0; i < 5; i++) {
    BeginDrawing()
    ClearBackground(RAYWHITE)
    DrawText("GC not available", 200, 200, 20, LIGHTGRAY)
    EndDrawing()
  }
}

// Cleanup
console.log("Test complete, cleaning up")
UnloadSound(global.sound)
global.sound = null
CloseAudioDevice()
CloseWindow()

console.log("Test finished")