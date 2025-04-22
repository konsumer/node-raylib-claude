/*******************************************************************************************
*
*   raylib [shapes] example - collision area
*
*   Example ported to JavaScript with node-raylib
*
*   Example originally created with raylib 2.5, last time updated with raylib 2.5
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2013-2025 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

import { 
  InitWindow, 
  CloseWindow, 
  BeginDrawing, 
  EndDrawing, 
  ClearBackground, 
  DrawText, 
  DrawRectangle,
  DrawRectangleRec,
  DrawFPS,
  CheckCollisionRecs,
  GetCollisionRec,
  GetMouseX,
  GetMouseY,
  GetScreenWidth,
  GetScreenHeight,
  IsKeyPressed,
  MeasureText,
  TextFormat,
  SetTargetFPS, 
  WindowShouldClose,
  KEY_SPACE,
  RAYWHITE,
  RED,
  BLACK,
  GOLD,
  BLUE,
  LIME,
  LIGHTGRAY
} from '../index.js'

// Initialization
//---------------------------------------------------------
const screenWidth = 800
const screenHeight = 450

InitWindow(screenWidth, screenHeight, "raylib [shapes] example - collision area")

// Box A: Moving box
const boxA = { 
    x: 10, 
    y: GetScreenHeight()/2.0 - 50, 
    width: 200, 
    height: 100 
}
let boxASpeedX = 4

// Box B: Mouse moved box
const boxB = { 
    x: GetScreenWidth()/2.0 - 30, 
    y: GetScreenHeight()/2.0 - 30, 
    width: 60, 
    height: 60 
}

let boxCollision = { x: 0, y: 0, width: 0, height: 0 } // Collision rectangle

const screenUpperLimit = 40      // Top menu limits

let pause = false             // Movement pause
let collision = false         // Collision detection

SetTargetFPS(60)               // Set our game to run at 60 frames-per-second
//----------------------------------------------------------

// Main game loop
while (!WindowShouldClose())    // Detect window close button or ESC key
{
    // Update
    //-----------------------------------------------------
    // Move box if not paused
    if (!pause) boxA.x += boxASpeedX

    // Bounce box on x screen limits
    if (((boxA.x + boxA.width) >= GetScreenWidth()) || (boxA.x <= 0)) boxASpeedX *= -1

    // Update player-controlled-box (box02)
    boxB.x = GetMouseX() - boxB.width/2
    boxB.y = GetMouseY() - boxB.height/2

    // Make sure Box B does not go out of move area limits
    if ((boxB.x + boxB.width) >= GetScreenWidth()) boxB.x = GetScreenWidth() - boxB.width
    else if (boxB.x <= 0) boxB.x = 0

    if ((boxB.y + boxB.height) >= GetScreenHeight()) boxB.y = GetScreenHeight() - boxB.height
    else if (boxB.y <= screenUpperLimit) boxB.y = screenUpperLimit

    // Check boxes collision
    collision = CheckCollisionRecs(boxA, boxB)

    // Get collision rectangle (only on collision)
    if (collision) boxCollision = GetCollisionRec(boxA, boxB)

    // Pause Box A movement
    if (IsKeyPressed(KEY_SPACE)) pause = !pause
    //-----------------------------------------------------

    // Draw
    //-----------------------------------------------------
    BeginDrawing()

        ClearBackground(RAYWHITE)

        DrawRectangle(0, 0, screenWidth, screenUpperLimit, collision ? RED : BLACK)

        DrawRectangleRec(boxA, GOLD)
        DrawRectangleRec(boxB, BLUE)

        if (collision) {
            // Draw collision area
            DrawRectangleRec(boxCollision, LIME)

            // Draw collision message
            DrawText("COLLISION!", GetScreenWidth()/2 - MeasureText("COLLISION!", 20)/2, screenUpperLimit/2 - 10, 20, BLACK)

            // Draw collision area
            DrawText(TextFormat("Collision Area: %i", Math.floor(boxCollision.width) * Math.floor(boxCollision.height)), GetScreenWidth()/2 - 100, screenUpperLimit + 10, 20, BLACK)
        }

        // Draw help instructions
        DrawText("Press SPACE to PAUSE/RESUME", 20, screenHeight - 35, 20, LIGHTGRAY)

        DrawFPS(10, 10)

    EndDrawing()
    //-----------------------------------------------------
}

// De-Initialization
//---------------------------------------------------------
CloseWindow()        // Close window and OpenGL context
//----------------------------------------------------------