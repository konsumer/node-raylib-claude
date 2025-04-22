/*******************************************************************************************
*
*   raylib [shapes] example - Draw basic shapes 2d (rectangle, circle, line...)
*
*   Example ported to JavaScript with node-raylib
*
*   Example originally created with raylib 1.0, last time updated with raylib 4.2
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
  DrawCircle,
  DrawCircleGradient,
  DrawCircleLines,
  DrawRectangle,
  DrawRectangleGradientH,
  DrawRectangleLines,
  DrawTriangle,
  DrawTriangleLines,
  DrawPoly,
  DrawPolyLines,
  DrawPolyLinesEx,
  DrawLine,
  SetTargetFPS, 
  WindowShouldClose,
  RAYWHITE,
  DARKGRAY,
  DARKBLUE,
  GREEN,
  SKYBLUE,
  RED,
  MAROON,
  GOLD,
  ORANGE,
  VIOLET,
  BROWN,
  BEIGE,
  BLACK
} from '../index.js'

// Initialization
//--------------------------------------------------------------------------------------
const screenWidth = 800
const screenHeight = 450

InitWindow(screenWidth, screenHeight, "raylib [shapes] example - basic shapes drawing")

let rotation = 0.0

SetTargetFPS(60)               // Set our game to run at 60 frames-per-second
//--------------------------------------------------------------------------------------

// Main game loop
while (!WindowShouldClose())    // Detect window close button or ESC key
{
    // Update
    //----------------------------------------------------------------------------------
    rotation += 0.2
    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing()

    ClearBackground(RAYWHITE)

    DrawText("some basic shapes available on raylib", 20, 20, 20, DARKGRAY)

    // Circle shapes and lines
    DrawCircle(screenWidth/5, 120, 35, DARKBLUE)
    DrawCircleGradient(screenWidth/5, 220, 60, GREEN, SKYBLUE)
    DrawCircleLines(screenWidth/5, 340, 80, DARKBLUE)

    // Rectangle shapes and lines
    DrawRectangle(screenWidth/4*2 - 60, 100, 120, 60, RED)
    DrawRectangleGradientH(screenWidth/4*2 - 90, 170, 180, 130, MAROON, GOLD)
    DrawRectangleLines(screenWidth/4*2 - 40, 320, 80, 60, ORANGE)  // NOTE: Uses QUADS internally, not lines

    // Triangle shapes and lines
    DrawTriangle(
        { x: screenWidth/4.0*3.0, y: 80.0 },
        { x: screenWidth/4.0*3.0 - 60.0, y: 150.0 },
        { x: screenWidth/4.0*3.0 + 60.0, y: 150.0 }, 
        VIOLET
    )

    DrawTriangleLines(
        { x: screenWidth/4.0*3.0, y: 160.0 },
        { x: screenWidth/4.0*3.0 - 20.0, y: 230.0 },
        { x: screenWidth/4.0*3.0 + 20.0, y: 230.0 }, 
        DARKBLUE
    )

    // Polygon shapes and lines
    DrawPoly({ x: screenWidth/4.0*3, y: 330 }, 6, 80, rotation, BROWN)
    DrawPolyLines({ x: screenWidth/4.0*3, y: 330 }, 6, 90, rotation, BROWN)
    DrawPolyLinesEx({ x: screenWidth/4.0*3, y: 330 }, 6, 85, rotation, 6, BEIGE)

    // NOTE: We draw all LINES based shapes together to optimize internal drawing,
    // this way, all LINES are rendered in a single draw pass
    DrawLine(18, 42, screenWidth - 18, 42, BLACK)
    
    EndDrawing()
    //----------------------------------------------------------------------------------
}

// De-Initialization
//--------------------------------------------------------------------------------------
CloseWindow()        // Close window and OpenGL context
//--------------------------------------------------------------------------------------