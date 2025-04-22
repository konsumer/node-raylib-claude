/*******************************************************************************************
*
*   raylib [audio] example - Garbage Collection and Audio Test
*
*   Test that tries to trigger garbage collection while audio is playing
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

console.log("Starting garbage collection stress test")

// Initialize
console.log("Initializing window")
InitWindow(800, 450, "Audio GC Test")

console.log("Initializing audio device")
InitAudioDevice()

// Load sound
console.log("Loading sound")
let soundRef = LoadSound("examples/resources/sound.wav")
console.log("Sound loaded, playing it once")
PlaySound(soundRef)

// Create a function that allocates a bunch of objects to try to trigger GC
function allocateMemory() {
  const objects = []
  for (let i = 0; i < 100000; i++) {
    objects.push({ index: i, data: new Array(100).fill(Math.random()) })
  }
  return objects.length
}

// Run a short loop that allocates memory aggressively and draws frames
console.log("Running high-memory allocation loop")
for (let i = 0; i < 5; i++) {
  console.log(`Iteration ${i+1}: Allocating memory...`)
  const objCount = allocateMemory()
  
  BeginDrawing()
  ClearBackground(RAYWHITE)
  DrawText(`Memory allocation iteration: ${i+1}`, 200, 200, 20, LIGHTGRAY)
  EndDrawing()
}

// Cleanup
console.log("Test complete, cleaning up")
UnloadSound(soundRef)
soundRef = null
CloseAudioDevice()
CloseWindow()

console.log("Test finished")