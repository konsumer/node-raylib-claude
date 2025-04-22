/*******************************************************************************************
*
*   raylib [audio] example - Load and play sound immediately
*
*   Quick test that loads a sound, plays it, and exits
*
********************************************************************************************/

import { 
  InitWindow, 
  CloseWindow, 
  InitAudioDevice,
  CloseAudioDevice,
  LoadSound,
  UnloadSound,
  PlaySound
} from '../index.js'

console.log("Starting quick audio test")

// Initialize minimum required systems
console.log("Initializing window")
InitWindow(800, 450, "Audio Quick Test")

console.log("Initializing audio device")
InitAudioDevice()

// Load and play sound immediately
console.log("Loading sound")
const sound = LoadSound("examples/resources/sound.wav")
console.log("Sound loaded, playing it immediately")
PlaySound(sound)

// Sleep for a moment to allow sound to play
console.log("Waiting 1 second")
const startTime = Date.now()
while (Date.now() - startTime < 1000) {
  // Busy wait
}

// Cleanup
console.log("Unloading sound")
UnloadSound(sound)
console.log("Closing audio device")
CloseAudioDevice()
console.log("Closing window")
CloseWindow()

console.log("Test complete")