/*******************************************************************************************
*
*   raylib [audio] example - Load and play sound with global reference
*
*   Tests using global references to prevent garbage collection of audio resources
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

console.log("Starting audio test with global references")

// Initialize minimum required systems
console.log("Initializing window")
InitWindow(800, 450, "Audio Global Test")

console.log("Initializing audio device")
InitAudioDevice()

// Load sound and store in global reference
console.log("Loading sound with global reference")
global.sound = LoadSound("examples/resources/sound.wav")
console.log("Sound loaded, playing it immediately")
PlaySound(global.sound)

// Sleep for a moment to allow sound to play
console.log("Waiting 1 second")
const startTime = Date.now()
while (Date.now() - startTime < 1000) {
  // Busy wait
}

// Cleanup
console.log("Unloading sound")
UnloadSound(global.sound)
global.sound = null
console.log("Closing audio device")
CloseAudioDevice()
console.log("Closing window")
CloseWindow()

console.log("Test complete")