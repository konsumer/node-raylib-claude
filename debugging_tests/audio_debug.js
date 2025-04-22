/*******************************************************************************************
*
*   raylib [audio] example - Audio Debug Test
*
*   Testing deeper audio playback issues
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
  IsSoundPlaying,
  IsKeyPressed,
  SetTargetFPS, 
  WindowShouldClose,
  KEY_SPACE,
  RAYWHITE,
  LIGHTGRAY,
  GREEN,
  RED
} from '../index.js'

console.log("Starting audio debug test")

// Initialization
const screenWidth = 800
const screenHeight = 450

InitWindow(screenWidth, screenHeight, "raylib [audio] debug test")
console.log("Window initialized")

InitAudioDevice()
console.log("Audio device initialized")

// Load a sound file with global reference to prevent GC
console.log("Loading sound file...")
global.sound = LoadSound("examples/resources/sound.wav")
console.log("Sound loaded")

// Set a flag to show when sound is playing
let playedSound = false
let frameCount = 0

SetTargetFPS(60)

// Main game loop
console.log("Starting main loop")
while (!WindowShouldClose() && frameCount < 300) // Run for 5 seconds (60 FPS × 5)
{
    frameCount++
    
    // Play sound when space is pressed
    if (IsKeyPressed(KEY_SPACE)) {
        console.log("SPACE pressed - Playing sound")
        PlaySound(global.sound)
        playedSound = true
    }
    
    // Check if sound is currently playing
    const soundIsPlaying = IsSoundPlaying(global.sound)
    if (soundIsPlaying) {
        console.log(`Frame ${frameCount}: Sound is playing`)
    }
    
    // Draw
    BeginDrawing()
    
        ClearBackground(RAYWHITE)
        
        DrawText("Press SPACE to play sound", 200, 180, 20, LIGHTGRAY)
        
        // Show playback status
        if (playedSound) {
            DrawText("Sound was triggered", 200, 220, 20, GREEN)
            
            // Display current playback state
            const statusColor = soundIsPlaying ? GREEN : RED
            DrawText(`Is playing: ${soundIsPlaying ? "YES" : "NO"}`, 200, 260, 20, statusColor)
        }
        
        // Show frame counter
        DrawText(`Frame: ${frameCount}/300`, 200, 300, 20, LIGHTGRAY)
        
    EndDrawing()
}

// Cleanup
console.log("Unloading sound")
UnloadSound(global.sound)
global.sound = null

console.log("Closing audio device")
CloseAudioDevice()

console.log("Closing window")
CloseWindow()

console.log("Test completed")