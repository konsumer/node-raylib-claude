/*******************************************************************************************
*
*   raylib [textures] example - Background scrolling
*
*   Example ported to JavaScript with node-raylib
*
*   Example originally created with raylib 2.0, last time updated with raylib 2.5
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
  DrawText, 
  DrawTextureEx,
  LoadTexture,
  UnloadTexture,
  SetTargetFPS, 
  WindowShouldClose,
  GetColor,
  WHITE,
  RED,
  RAYWHITE
} from '../index.js'

// Initialization
//--------------------------------------------------------------------------------------
const screenWidth = 800
const screenHeight = 450

InitWindow(screenWidth, screenHeight, "raylib [textures] example - background scrolling")

// NOTE: Be careful, background width must be equal or bigger than screen width
// if not, texture should be draw more than two times for scrolling effect
const background = LoadTexture("examples/resources/cyberpunk_street_background.png")
const midground = LoadTexture("examples/resources/cyberpunk_street_midground.png")
const foreground = LoadTexture("examples/resources/cyberpunk_street_foreground.png")

let scrollingBack = 0.0
let scrollingMid = 0.0
let scrollingFore = 0.0

SetTargetFPS(60)               // Set our game to run at 60 frames-per-second
//--------------------------------------------------------------------------------------

// Main game loop
while (!WindowShouldClose())    // Detect window close button or ESC key
{
    // Update
    //----------------------------------------------------------------------------------
    scrollingBack -= 0.1
    scrollingMid -= 0.5
    scrollingFore -= 1.0

    // NOTE: Texture is scaled twice its size, so it sould be considered on scrolling
    if (scrollingBack <= -background.width*2) scrollingBack = 0
    if (scrollingMid <= -midground.width*2) scrollingMid = 0
    if (scrollingFore <= -foreground.width*2) scrollingFore = 0
    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing()

        ClearBackground(GetColor(0x052c46ff))

        // Draw background image twice
        // NOTE: Texture is scaled twice its size
        DrawTextureEx(background, { x: scrollingBack, y: 20 }, 0.0, 2.0, WHITE)
        DrawTextureEx(background, { x: background.width*2 + scrollingBack, y: 20 }, 0.0, 2.0, WHITE)

        // Draw midground image twice
        DrawTextureEx(midground, { x: scrollingMid, y: 20 }, 0.0, 2.0, WHITE)
        DrawTextureEx(midground, { x: midground.width*2 + scrollingMid, y: 20 }, 0.0, 2.0, WHITE)

        // Draw foreground image twice
        DrawTextureEx(foreground, { x: scrollingFore, y: 70 }, 0.0, 2.0, WHITE)
        DrawTextureEx(foreground, { x: foreground.width*2 + scrollingFore, y: 70 }, 0.0, 2.0, WHITE)

        DrawText("BACKGROUND SCROLLING & PARALLAX", 10, 10, 20, RED)
        DrawText("(c) Cyberpunk Street Environment by Luis Zuno (@ansimuz)", screenWidth - 330, screenHeight - 20, 10, RAYWHITE)

    EndDrawing()
    //----------------------------------------------------------------------------------
}

// De-Initialization
//--------------------------------------------------------------------------------------
UnloadTexture(background)  // Unload background texture
UnloadTexture(midground)   // Unload midground texture
UnloadTexture(foreground)  // Unload foreground texture

CloseWindow()              // Close window and OpenGL context
//--------------------------------------------------------------------------------------