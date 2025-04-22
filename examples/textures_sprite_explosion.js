/*******************************************************************************************
*
*   raylib [textures] example - sprite explosion
*
*   Example ported to JavaScript with node-raylib
*
*   Example originally created with raylib 2.5, last time updated with raylib 3.5
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2019-2025 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

import { 
  InitWindow, 
  CloseWindow, 
  BeginDrawing, 
  EndDrawing, 
  ClearBackground, 
  DrawTextureRec,
  LoadTexture,
  UnloadTexture,
  LoadSound,
  UnloadSound,
  InitAudioDevice,
  CloseAudioDevice,
  PlaySound,
  GetMousePosition,
  IsMouseButtonPressed,
  SetTargetFPS, 
  WindowShouldClose,
  MOUSE_BUTTON_LEFT,
  RAYWHITE,
  WHITE
} from '../index.js'

// Constants
const NUM_FRAMES_PER_LINE = 5
const NUM_LINES = 5

// Initialization
//--------------------------------------------------------------------------------------
const screenWidth = 800
const screenHeight = 450

InitWindow(screenWidth, screenHeight, "raylib [textures] example - sprite explosion")

InitAudioDevice()

// Load explosion sound
const fxBoom = LoadSound("examples/resources/boom.wav")

// Load explosion texture
const explosion = LoadTexture("examples/resources/explosion.png")

// Init variables for animation
const frameWidth = explosion.width/NUM_FRAMES_PER_LINE   // Sprite one frame rectangle width
const frameHeight = explosion.height/NUM_LINES           // Sprite one frame rectangle height
let currentFrame = 0
let currentLine = 0

const frameRec = { x: 0, y: 0, width: frameWidth, height: frameHeight }
const position = { x: 0.0, y: 0.0 }

let active = false
let framesCounter = 0

SetTargetFPS(60)               // Set our game to run at 60 frames-per-second
//---------------------------------------------------------------------------------------

// Main game loop
while (!WindowShouldClose())    // Detect window close button or ESC key
{
    // Update
    //----------------------------------------------------------------------------------

    // Check for mouse button pressed and activate explosion (if not active)
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && !active)
    {
        const mousePos = GetMousePosition()
        position.x = mousePos.x
        position.y = mousePos.y
        active = true

        position.x -= frameWidth/2.0
        position.y -= frameHeight/2.0

        PlaySound(fxBoom)
    }

    // Compute explosion animation frames
    if (active)
    {
        framesCounter++

        if (framesCounter > 2)
        {
            currentFrame++

            if (currentFrame >= NUM_FRAMES_PER_LINE)
            {
                currentFrame = 0
                currentLine++

                if (currentLine >= NUM_LINES)
                {
                    currentLine = 0
                    active = false
                }
            }

            framesCounter = 0
        }
    }

    frameRec.x = frameWidth*currentFrame
    frameRec.y = frameHeight*currentLine
    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing()

        ClearBackground(RAYWHITE)

        // Draw explosion required frame rectangle
        if (active) DrawTextureRec(explosion, frameRec, position, WHITE)

    EndDrawing()
    //----------------------------------------------------------------------------------
}

// De-Initialization
//--------------------------------------------------------------------------------------
UnloadTexture(explosion)   // Unload texture
UnloadSound(fxBoom)        // Unload sound

CloseAudioDevice()

CloseWindow()              // Close window and OpenGL context
//--------------------------------------------------------------------------------------