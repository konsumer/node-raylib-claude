/*******************************************************************************************
*
*   raylib [textures] example - sprite button
*
*   Example ported to JavaScript with node-raylib
*
*   Example originally created with raylib 2.5, last time updated with raylib 2.5
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
  CheckCollisionPointRec,
  IsMouseButtonDown,
  IsMouseButtonReleased,
  SetTargetFPS, 
  WindowShouldClose,
  MOUSE_BUTTON_LEFT,
  RAYWHITE,
  WHITE
} from '../index.js'

// Constants
const NUM_FRAMES = 3      // Number of frames (rectangles) for the button sprite texture

// Initialization
//--------------------------------------------------------------------------------------
const screenWidth = 800
const screenHeight = 450

InitWindow(screenWidth, screenHeight, "raylib [textures] example - sprite button")

InitAudioDevice()      // Initialize audio device

const fxButton = LoadSound("examples/resources/buttonfx.wav")   // Load button sound
const button = LoadTexture("examples/resources/button.png")    // Load button texture

// Define frame rectangle for drawing
const frameHeight = button.height/NUM_FRAMES
const sourceRec = { x: 0, y: 0, width: button.width, height: frameHeight }

// Define button bounds on screen
const btnBounds = { 
    x: screenWidth/2.0 - button.width/2.0, 
    y: screenHeight/2.0 - button.height/NUM_FRAMES/2.0, 
    width: button.width, 
    height: frameHeight 
}

let btnState = 0               // Button state: 0-NORMAL, 1-MOUSE_HOVER, 2-PRESSED
let btnAction = false          // Button action should be activated

let mousePoint = { x: 0.0, y: 0.0 }

SetTargetFPS(60)
//--------------------------------------------------------------------------------------

// Main game loop
while (!WindowShouldClose())    // Detect window close button or ESC key
{
    // Update
    //----------------------------------------------------------------------------------
    mousePoint = GetMousePosition()
    btnAction = false

    // Check button state
    if (CheckCollisionPointRec(mousePoint, btnBounds))
    {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) btnState = 2
        else btnState = 1

        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) btnAction = true
    }
    else btnState = 0

    if (btnAction)
    {
        PlaySound(fxButton)

        // TODO: Any desired action
    }

    // Calculate button frame rectangle to draw depending on button state
    sourceRec.y = btnState * frameHeight
    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing()

        ClearBackground(RAYWHITE)

        DrawTextureRec(button, sourceRec, { x: btnBounds.x, y: btnBounds.y }, WHITE) // Draw button frame

    EndDrawing()
    //----------------------------------------------------------------------------------
}

// De-Initialization
//--------------------------------------------------------------------------------------
UnloadTexture(button)  // Unload button texture
UnloadSound(fxButton)  // Unload sound

CloseAudioDevice()     // Close audio device

CloseWindow()          // Close window and OpenGL context
//--------------------------------------------------------------------------------------