/*******************************************************************************************
*
*   raylib [textures] example - Bunnymark
*
*   Example ported to JavaScript with node-raylib
*
*   Example originally created with raylib 1.6, last time updated with raylib 2.5
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2014-2025 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

import { 
  InitWindow, 
  CloseWindow, 
  BeginDrawing, 
  EndDrawing, 
  ClearBackground, 
  DrawText, 
  DrawTexture,
  DrawRectangle,
  DrawFPS,
  LoadTexture,
  UnloadTexture,
  GetMousePosition,
  GetRandomValue,
  GetScreenWidth,
  GetScreenHeight,
  IsMouseButtonDown,
  TextFormat,
  SetTargetFPS, 
  WindowShouldClose,
  MOUSE_BUTTON_LEFT,
  RAYWHITE,
  BLACK,
  GREEN,
  MAROON
} from '../index.js'

// Constants
const MAX_BUNNIES = 50000    // 50K bunnies limit

// This is the maximum amount of elements (quads) per batch
// NOTE: This value is defined in [rlgl] module and can be changed there
const MAX_BATCH_ELEMENTS = 8192

// Bunny class equivalent
class Bunny {
    constructor() {
        this.position = { x: 0, y: 0 }
        this.speed = { x: 0, y: 0 }
        this.color = { r: 255, g: 255, b: 255, a: 255 }
    }
}

// Initialization
//--------------------------------------------------------------------------------------
const screenWidth = 800
const screenHeight = 450

InitWindow(screenWidth, screenHeight, "raylib [textures] example - bunnymark")

// Load bunny texture
const texBunny = LoadTexture("examples/resources/wabbit_alpha.png")

const bunnies = []    // Bunnies array
let bunniesCount = 0  // Bunnies counter

SetTargetFPS(60)               // Set our game to run at 60 frames-per-second
//--------------------------------------------------------------------------------------

// Main game loop
while (!WindowShouldClose())    // Detect window close button or ESC key
{
    // Update
    //----------------------------------------------------------------------------------
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        // Create more bunnies
        for (let i = 0; i < 100; i++) {
            if (bunniesCount < MAX_BUNNIES) {
                const bunny = new Bunny()
                const mousePos = GetMousePosition()
                bunny.position = { x: mousePos.x, y: mousePos.y }
                bunny.speed.x = GetRandomValue(-250, 250)/60.0
                bunny.speed.y = GetRandomValue(-250, 250)/60.0
                bunny.color = { 
                    r: GetRandomValue(50, 240),
                    g: GetRandomValue(80, 240),
                    b: GetRandomValue(100, 240), 
                    a: 255 
                }
                bunnies.push(bunny)
                bunniesCount++
            }
        }
    }

    // Update bunnies
    for (let i = 0; i < bunniesCount; i++) {
        bunnies[i].position.x += bunnies[i].speed.x
        bunnies[i].position.y += bunnies[i].speed.y

        if (((bunnies[i].position.x + texBunny.width/2) > GetScreenWidth()) ||
            ((bunnies[i].position.x + texBunny.width/2) < 0)) bunnies[i].speed.x *= -1
        if (((bunnies[i].position.y + texBunny.height/2) > GetScreenHeight()) ||
            ((bunnies[i].position.y + texBunny.height/2 - 40) < 0)) bunnies[i].speed.y *= -1
    }
    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing()

        ClearBackground(RAYWHITE)

        for (let i = 0; i < bunniesCount; i++) {
            // NOTE: When internal batch buffer limit is reached (MAX_BATCH_ELEMENTS),
            // a draw call is launched and buffer starts being filled again;
            // before issuing a draw call, updated vertex data from internal CPU buffer is send to GPU...
            // Process of sending data is costly and it could happen that GPU data has not been completely
            // processed for drawing while new data is tried to be sent (updating current in-use buffers)
            // it could generates a stall and consequently a frame drop, limiting the number of drawn bunnies
            DrawTexture(texBunny, Math.floor(bunnies[i].position.x), Math.floor(bunnies[i].position.y), bunnies[i].color)
        }

        DrawRectangle(0, 0, screenWidth, 40, BLACK)
        DrawText(TextFormat("bunnies: %i", bunniesCount), 120, 10, 20, GREEN)
        DrawText(TextFormat("batched draw calls: %i", 1 + Math.floor(bunniesCount/MAX_BATCH_ELEMENTS)), 320, 10, 20, MAROON)

        DrawFPS(10, 10)

    EndDrawing()
    //----------------------------------------------------------------------------------
}

// De-Initialization
//--------------------------------------------------------------------------------------
UnloadTexture(texBunny)    // Unload bunny texture

CloseWindow()              // Close window and OpenGL context
//--------------------------------------------------------------------------------------