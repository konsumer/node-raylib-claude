/*******************************************************************************************
*
*   raylib [audio] example - Forced Garbage Collection and Audio Test
*
*   Test that explicitly forces garbage collection while audio is playing
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

// To use this test, run with: node --expose-gc examples/audio_forced_gc_test.js

console.log("Starting forced garbage collection test")

// Initialize
console.log("Initializing window")
InitWindow(800, 450, "Audio Forced GC Test")

console.log("Initializing audio device")
InitAudioDevice()

// Load sound as local variable (not global)
console.log("Loading sound as local variable (not global)")
let soundRef = LoadSound("examples/resources/sound.wav")
console.log("Sound loaded, playing it once")
PlaySound(soundRef)

// If we have access to the explicit garbage collector, use it
if (global.gc) {
  console.log("Explicit GC available, will force garbage collection...")
  
  // Run a short loop that forces garbage collection between frames
  for (let i = 0; i < 5; i++) {
    console.log(`Iteration ${i+1}: Forcing garbage collection...`)
    global.gc()
    
    BeginDrawing()
    ClearBackground(RAYWHITE)
    DrawText(`Forced GC iteration: ${i+1}`, 200, 200, 20, LIGHTGRAY)
    EndDrawing()
  }
} else {
  console.log("Explicit GC not available. Run with: node --expose-gc examples/audio_forced_gc_test.js")
  
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
UnloadSound(soundRef)
soundRef = null
CloseAudioDevice()
CloseWindow()

console.log("Test finished")