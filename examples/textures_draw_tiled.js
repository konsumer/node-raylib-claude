/*******************************************************************************************
*
*   raylib [textures] example - Draw part of the texture tiled
*
*   Example ported to JavaScript with node-raylib
*
*   Example originally created with raylib 3.0, last time updated with raylib 4.2
*
*   Example contributed by Vlad Adrian (@demizdor) and reviewed by Ramon Santamaria (@raysan5)
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2020-2025 Vlad Adrian (@demizdor) and Ramon Santamaria (@raysan5)
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
  DrawTexturePro,
  DrawRectangle,
  DrawRectangleRec,
  DrawRectangleLinesEx,
  LoadTexture,
  UnloadTexture,
  SetTextureFilter,
  CheckCollisionPointRec,
  ColorAlpha,
  TextFormat,
  SetConfigFlags,
  GetScreenWidth,
  GetScreenHeight,
  GetMousePosition,
  GetFPS,
  SetTargetFPS, 
  WindowShouldClose,
  IsMouseButtonPressed,
  IsKeyPressed,
  MOUSE_BUTTON_LEFT,
  KEY_UP,
  KEY_DOWN,
  KEY_LEFT,
  KEY_RIGHT,
  KEY_SPACE,
  TEXTURE_FILTER_TRILINEAR,
  FLAG_WINDOW_RESIZABLE,
  BLACK, MAROON, ORANGE, BLUE, PURPLE, BEIGE, LIME, RED, 
  DARKGRAY, SKYBLUE, RAYWHITE, LIGHTGRAY, DARKBLUE, WHITE
} from '../index.js'

// Constants
const OPT_WIDTH = 220       // Max width for the options container
const MARGIN_SIZE = 8       // Size for the margins
const COLOR_SIZE = 16       // Size of the color select buttons

// Draw part of a texture (defined by a rectangle) with rotation and scale tiled into dest.
function DrawTextureTiled(texture, source, dest, origin, rotation, scale, tint) {
    if ((texture.id <= 0) || (scale <= 0.0)) return;  // Wanna see a infinite loop?!...just delete this line!
    if ((source.width == 0) || (source.height == 0)) return;

    const tileWidth = source.width*scale
    const tileHeight = source.height*scale
    
    if ((dest.width < tileWidth) && (dest.height < tileHeight)) {
        // Can fit only one tile
        DrawTexturePro(texture, 
            {x: source.x, y: source.y, width: (dest.width/tileWidth)*source.width, height: (dest.height/tileHeight)*source.height},
            {x: dest.x, y: dest.y, width: dest.width, height: dest.height}, 
            origin, rotation, tint)
    }
    else if (dest.width <= tileWidth) {
        // Tiled vertically (one column)
        let dy = 0
        for (;dy+tileHeight < dest.height; dy += tileHeight) {
            DrawTexturePro(texture, 
                {x: source.x, y: source.y, width: (dest.width/tileWidth)*source.width, height: source.height}, 
                {x: dest.x, y: dest.y + dy, width: dest.width, height: tileHeight}, 
                origin, rotation, tint)
        }

        // Fit last tile
        if (dy < dest.height) {
            DrawTexturePro(texture, 
                {x: source.x, y: source.y, width: (dest.width/tileWidth)*source.width, height: (dest.height - dy)/tileHeight*source.height},
                {x: dest.x, y: dest.y + dy, width: dest.width, height: dest.height - dy}, 
                origin, rotation, tint)
        }
    }
    else if (dest.height <= tileHeight) {
        // Tiled horizontally (one row)
        let dx = 0
        for (;dx+tileWidth < dest.width; dx += tileWidth) {
            DrawTexturePro(texture, 
                {x: source.x, y: source.y, width: source.width, height: (dest.height/tileHeight)*source.height}, 
                {x: dest.x + dx, y: dest.y, width: tileWidth, height: dest.height}, 
                origin, rotation, tint)
        }

        // Fit last tile
        if (dx < dest.width) {
            DrawTexturePro(texture, 
                {x: source.x, y: source.y, width: (dest.width - dx)/tileWidth*source.width, height: (dest.height/tileHeight)*source.height},
                {x: dest.x + dx, y: dest.y, width: dest.width - dx, height: dest.height}, 
                origin, rotation, tint)
        }
    }
    else {
        // Tiled both horizontally and vertically (rows and columns)
        let dx = 0
        for (;dx+tileWidth < dest.width; dx += tileWidth) {
            let dy = 0
            for (;dy+tileHeight < dest.height; dy += tileHeight) {
                DrawTexturePro(texture, source, 
                    {x: dest.x + dx, y: dest.y + dy, width: tileWidth, height: tileHeight}, 
                    origin, rotation, tint)
            }

            if (dy < dest.height) {
                DrawTexturePro(texture, 
                    {x: source.x, y: source.y, width: source.width, height: (dest.height - dy)/tileHeight*source.height},
                    {x: dest.x + dx, y: dest.y + dy, width: tileWidth, height: dest.height - dy}, 
                    origin, rotation, tint)
            }
        }

        // Fit last column of tiles
        if (dx < dest.width) {
            let dy = 0
            for (;dy+tileHeight < dest.height; dy += tileHeight) {
                DrawTexturePro(texture, 
                    {x: source.x, y: source.y, width: (dest.width - dx)/tileWidth*source.width, height: source.height},
                    {x: dest.x + dx, y: dest.y + dy, width: dest.width - dx, height: tileHeight}, 
                    origin, rotation, tint)
            }

            // Draw final tile in the bottom right corner
            if (dy < dest.height) {
                DrawTexturePro(texture, 
                    {x: source.x, y: source.y, width: (dest.width - dx)/tileWidth*source.width, height: (dest.height - dy)/tileHeight*source.height},
                    {x: dest.x + dx, y: dest.y + dy, width: dest.width - dx, height: dest.height - dy}, 
                    origin, rotation, tint)
            }
        }
    }
}

// Main code
//--------------------------------------------------------------------------------------
// Initialization
//--------------------------------------------------------------------------------------
const screenWidth = 800
const screenHeight = 450

SetConfigFlags(FLAG_WINDOW_RESIZABLE) // Make the window resizable
InitWindow(screenWidth, screenHeight, "raylib [textures] example - Draw part of a texture tiled")

// NOTE: Textures MUST be loaded after Window initialization (OpenGL context is required)
const texPattern = LoadTexture("examples/resources/patterns.png")
SetTextureFilter(texPattern, TEXTURE_FILTER_TRILINEAR) // Makes the texture smoother when upscaled

// Coordinates for all patterns inside the texture
const recPattern = [
    { x: 3, y: 3, width: 66, height: 66 },
    { x: 75, y: 3, width: 100, height: 100 },
    { x: 3, y: 75, width: 66, height: 66 },
    { x: 7, y: 156, width: 50, height: 50 },
    { x: 85, y: 106, width: 90, height: 45 },
    { x: 75, y: 154, width: 100, height: 60 }
]

// Setup colors
const colors = [BLACK, MAROON, ORANGE, BLUE, PURPLE, BEIGE, LIME, RED, DARKGRAY, SKYBLUE]
const MAX_COLORS = colors.length
const colorRec = []

// Calculate rectangle for each color
for (let i = 0, x = 0, y = 0; i < MAX_COLORS; i++) {
    colorRec[i] = {
        x: 2.0 + MARGIN_SIZE + x,
        y: 22.0 + 256.0 + MARGIN_SIZE + y,
        width: COLOR_SIZE*2.0,
        height: COLOR_SIZE
    }

    if (i == (MAX_COLORS/2 - 1)) {
        x = 0
        y += COLOR_SIZE + MARGIN_SIZE
    }
    else x += (COLOR_SIZE*2 + MARGIN_SIZE)
}

let activePattern = 0, activeCol = 0
let scale = 1.0, rotation = 0.0

SetTargetFPS(60)
//---------------------------------------------------------------------------------------

// Main game loop
while (!WindowShouldClose())    // Detect window close button or ESC key
{
    // Update
    //----------------------------------------------------------------------------------
    // Handle mouse
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        const mouse = GetMousePosition()

        // Check which pattern was clicked and set it as the active pattern
        for (let i = 0; i < recPattern.length; i++) {
            if (CheckCollisionPointRec(mouse, {
                x: 2 + MARGIN_SIZE + recPattern[i].x, 
                y: 40 + MARGIN_SIZE + recPattern[i].y, 
                width: recPattern[i].width, 
                height: recPattern[i].height 
            })) {
                activePattern = i
                break
            }
        }

        // Check to see which color was clicked and set it as the active color
        for (let i = 0; i < MAX_COLORS; ++i) {
            if (CheckCollisionPointRec(mouse, colorRec[i])) {
                activeCol = i
                break
            }
        }
    }

    // Handle keys

    // Change scale
    if (IsKeyPressed(KEY_UP)) scale += 0.25
    if (IsKeyPressed(KEY_DOWN)) scale -= 0.25
    if (scale > 10.0) scale = 10.0
    else if (scale <= 0.0) scale = 0.25

    // Change rotation
    if (IsKeyPressed(KEY_LEFT)) rotation -= 25.0
    if (IsKeyPressed(KEY_RIGHT)) rotation += 25.0

    // Reset
    if (IsKeyPressed(KEY_SPACE)) { rotation = 0.0; scale = 1.0; }
    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing()
        ClearBackground(RAYWHITE)

        // Draw the tiled area
        DrawTextureTiled(texPattern, recPattern[activePattern], 
            {x: OPT_WIDTH+MARGIN_SIZE, y: MARGIN_SIZE, width: GetScreenWidth() - OPT_WIDTH - 2.0*MARGIN_SIZE, height: GetScreenHeight() - 2.0*MARGIN_SIZE},
            {x: 0.0, y: 0.0}, rotation, scale, colors[activeCol])

        // Draw options
        DrawRectangle(MARGIN_SIZE, MARGIN_SIZE, OPT_WIDTH - MARGIN_SIZE, GetScreenHeight() - 2*MARGIN_SIZE, ColorAlpha(LIGHTGRAY, 0.5))

        DrawText("Select Pattern", 2 + MARGIN_SIZE, 30 + MARGIN_SIZE, 10, BLACK)
        DrawTexture(texPattern, 2 + MARGIN_SIZE, 40 + MARGIN_SIZE, BLACK)
        DrawRectangle(2 + MARGIN_SIZE + recPattern[activePattern].x, 40 + MARGIN_SIZE + recPattern[activePattern].y, 
            recPattern[activePattern].width, recPattern[activePattern].height, ColorAlpha(DARKBLUE, 0.3))

        DrawText("Select Color", 2+MARGIN_SIZE, 10+256+MARGIN_SIZE, 10, BLACK)
        for (let i = 0; i < MAX_COLORS; i++) {
            DrawRectangleRec(colorRec[i], colors[i])
            if (activeCol == i) DrawRectangleLinesEx(colorRec[i], 3, ColorAlpha(WHITE, 0.5))
        }

        DrawText("Scale (UP/DOWN to change)", 2 + MARGIN_SIZE, 80 + 256 + MARGIN_SIZE, 10, BLACK)
        DrawText(TextFormat("%.2fx", scale), 2 + MARGIN_SIZE, 92 + 256 + MARGIN_SIZE, 20, BLACK)

        DrawText("Rotation (LEFT/RIGHT to change)", 2 + MARGIN_SIZE, 122 + 256 + MARGIN_SIZE, 10, BLACK)
        DrawText(TextFormat("%.0f degrees", rotation), 2 + MARGIN_SIZE, 134 + 256 + MARGIN_SIZE, 20, BLACK)

        DrawText("Press [SPACE] to reset", 2 + MARGIN_SIZE, 164 + 256 + MARGIN_SIZE, 10, DARKBLUE)

        // Draw FPS
        DrawText(TextFormat("%i FPS", GetFPS()), 2 + MARGIN_SIZE, 2 + MARGIN_SIZE, 20, BLACK)
    EndDrawing()
    //----------------------------------------------------------------------------------
}

// De-Initialization
//--------------------------------------------------------------------------------------
UnloadTexture(texPattern)        // Unload texture

CloseWindow()              // Close window and OpenGL context
//--------------------------------------------------------------------------------------