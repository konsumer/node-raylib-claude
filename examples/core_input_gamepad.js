/*******************************************************************************************
*
*   raylib [core] example - Gamepad input
*
*   Example ported to JavaScript with node-raylib
*
*   NOTE: This example requires a Gamepad connected to the system
*         raylib is configured to work with the following gamepads:
*                - Xbox 360 Controller (Xbox 360, Xbox One)
*                - PLAYSTATION(R)3 Controller
*         Check raylib.h for buttons configuration
*
*   Example originally created with raylib 1.1, last time updated with raylib 4.2
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
  DrawTexture,
  DrawCircle,
  DrawRectangle,
  DrawRectangleRounded,
  DrawTriangle,
  LoadTexture,
  UnloadTexture,
  IsGamepadAvailable,
  IsGamepadButtonDown,
  GetGamepadName,
  GetGamepadAxisMovement,
  GetGamepadAxisCount,
  GetGamepadButtonPressed,
  IsKeyPressed,
  TextFormat,
  TextToLower,
  TextFindIndex,
  SetConfigFlags,
  SetTargetFPS, 
  WindowShouldClose,
  KEY_LEFT,
  KEY_RIGHT,
  GAMEPAD_AXIS_LEFT_X,
  GAMEPAD_AXIS_LEFT_Y,
  GAMEPAD_AXIS_RIGHT_X,
  GAMEPAD_AXIS_RIGHT_Y,
  GAMEPAD_AXIS_LEFT_TRIGGER,
  GAMEPAD_AXIS_RIGHT_TRIGGER,
  GAMEPAD_BUTTON_UNKNOWN,
  GAMEPAD_BUTTON_MIDDLE,
  GAMEPAD_BUTTON_MIDDLE_RIGHT,
  GAMEPAD_BUTTON_MIDDLE_LEFT,
  GAMEPAD_BUTTON_RIGHT_FACE_LEFT,
  GAMEPAD_BUTTON_RIGHT_FACE_DOWN,
  GAMEPAD_BUTTON_RIGHT_FACE_RIGHT,
  GAMEPAD_BUTTON_RIGHT_FACE_UP,
  GAMEPAD_BUTTON_LEFT_FACE_UP,
  GAMEPAD_BUTTON_LEFT_FACE_DOWN,
  GAMEPAD_BUTTON_LEFT_FACE_LEFT,
  GAMEPAD_BUTTON_LEFT_FACE_RIGHT,
  GAMEPAD_BUTTON_LEFT_TRIGGER_1,
  GAMEPAD_BUTTON_RIGHT_TRIGGER_1,
  GAMEPAD_BUTTON_LEFT_THUMB,
  GAMEPAD_BUTTON_RIGHT_THUMB,
  FLAG_MSAA_4X_HINT,
  RAYWHITE,
  BLACK,
  RED,
  BLUE,
  LIME,
  MAROON,
  GOLD,
  DARKGRAY,
  LIGHTGRAY,
  GRAY,
  VIOLET,
  PINK,
  GREEN
} from '../index.js'

// NOTE: Gamepad name ID depends on drivers and OS
const XBOX_ALIAS_1 = "xbox"
const XBOX_ALIAS_2 = "x-box"
const PS_ALIAS = "playstation"

// Initialization
//--------------------------------------------------------------------------------------
const screenWidth = 800
const screenHeight = 450

SetConfigFlags(FLAG_MSAA_4X_HINT)  // Set MSAA 4X hint before windows creation

InitWindow(screenWidth, screenHeight, "raylib [core] example - gamepad input")

const texPs3Pad = LoadTexture("examples/resources/ps3.png")
const texXboxPad = LoadTexture("examples/resources/xbox.png")

// Set axis deadzones
const leftStickDeadzoneX = 0.1
const leftStickDeadzoneY = 0.1
const rightStickDeadzoneX = 0.1
const rightStickDeadzoneY = 0.1
const leftTriggerDeadzone = -0.9
const rightTriggerDeadzone = -0.9

SetTargetFPS(60)               // Set our game to run at 60 frames-per-second
//--------------------------------------------------------------------------------------

let gamepad = 0 // which gamepad to display

// Main game loop
while (!WindowShouldClose())    // Detect window close button or ESC key
{
    // Update
    //----------------------------------------------------------------------------------
    // ...
    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing()

        ClearBackground(RAYWHITE)

        if (IsKeyPressed(KEY_LEFT) && gamepad > 0) gamepad--
        if (IsKeyPressed(KEY_RIGHT)) gamepad++

        if (IsGamepadAvailable(gamepad))
        {
            const gamepadName = GetGamepadName(gamepad)
            DrawText(TextFormat("GP%d: %s", gamepad, gamepadName), 10, 10, 10, BLACK)

            // Get axis values
            let leftStickX = GetGamepadAxisMovement(gamepad, GAMEPAD_AXIS_LEFT_X)
            let leftStickY = GetGamepadAxisMovement(gamepad, GAMEPAD_AXIS_LEFT_Y)
            let rightStickX = GetGamepadAxisMovement(gamepad, GAMEPAD_AXIS_RIGHT_X)
            let rightStickY = GetGamepadAxisMovement(gamepad, GAMEPAD_AXIS_RIGHT_Y)
            let leftTrigger = GetGamepadAxisMovement(gamepad, GAMEPAD_AXIS_LEFT_TRIGGER)
            let rightTrigger = GetGamepadAxisMovement(gamepad, GAMEPAD_AXIS_RIGHT_TRIGGER)

            // Calculate deadzones
            if (leftStickX > -leftStickDeadzoneX && leftStickX < leftStickDeadzoneX) leftStickX = 0.0
            if (leftStickY > -leftStickDeadzoneY && leftStickY < leftStickDeadzoneY) leftStickY = 0.0
            if (rightStickX > -rightStickDeadzoneX && rightStickX < rightStickDeadzoneX) rightStickX = 0.0
            if (rightStickY > -rightStickDeadzoneY && rightStickY < rightStickDeadzoneY) rightStickY = 0.0
            if (leftTrigger < leftTriggerDeadzone) leftTrigger = -1.0
            if (rightTrigger < rightTriggerDeadzone) rightTrigger = -1.0

            const gamepadNameLower = TextToLower(gamepadName)
            if (TextFindIndex(gamepadNameLower, XBOX_ALIAS_1) > -1 || TextFindIndex(gamepadNameLower, XBOX_ALIAS_2) > -1)
            {
                DrawTexture(texXboxPad, 0, 0, DARKGRAY)

                // Draw buttons: xbox home
                if (IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_MIDDLE)) DrawCircle(394, 89, 19, RED)

                // Draw buttons: basic
                if (IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_MIDDLE_RIGHT)) DrawCircle(436, 150, 9, RED)
                if (IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_MIDDLE_LEFT)) DrawCircle(352, 150, 9, RED)
                if (IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_RIGHT_FACE_LEFT)) DrawCircle(501, 151, 15, BLUE)
                if (IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)) DrawCircle(536, 187, 15, LIME)
                if (IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_RIGHT_FACE_RIGHT)) DrawCircle(572, 151, 15, MAROON)
                if (IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_RIGHT_FACE_UP)) DrawCircle(536, 115, 15, GOLD)

                // Draw buttons: d-pad
                DrawRectangle(317, 202, 19, 71, BLACK)
                DrawRectangle(293, 228, 69, 19, BLACK)
                if (IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_LEFT_FACE_UP)) DrawRectangle(317, 202, 19, 26, RED)
                if (IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_LEFT_FACE_DOWN)) DrawRectangle(317, 202 + 45, 19, 26, RED)
                if (IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_LEFT_FACE_LEFT)) DrawRectangle(292, 228, 25, 19, RED)
                if (IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_LEFT_FACE_RIGHT)) DrawRectangle(292 + 44, 228, 26, 19, RED)

                // Draw buttons: left-right back
                if (IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_LEFT_TRIGGER_1)) DrawCircle(259, 61, 20, RED)
                if (IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_RIGHT_TRIGGER_1)) DrawCircle(536, 61, 20, RED)

                // Draw axis: left joystick
                let leftGamepadColor = BLACK
                if (IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_LEFT_THUMB)) leftGamepadColor = RED
                DrawCircle(259, 152, 39, BLACK)
                DrawCircle(259, 152, 34, LIGHTGRAY)
                DrawCircle(259 + Math.floor(leftStickX*20),
                           152 + Math.floor(leftStickY*20), 25, leftGamepadColor)

                // Draw axis: right joystick
                let rightGamepadColor = BLACK
                if (IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_RIGHT_THUMB)) rightGamepadColor = RED
                DrawCircle(461, 237, 38, BLACK)
                DrawCircle(461, 237, 33, LIGHTGRAY)
                DrawCircle(461 + Math.floor(rightStickX*20),
                           237 + Math.floor(rightStickY*20), 25, rightGamepadColor)

                // Draw axis: left-right triggers
                DrawRectangle(170, 30, 15, 70, GRAY)
                DrawRectangle(604, 30, 15, 70, GRAY)
                DrawRectangle(170, 30, 15, Math.floor(((1 + leftTrigger)/2)*70), RED)
                DrawRectangle(604, 30, 15, Math.floor(((1 + rightTrigger)/2)*70), RED)
            }
            else if (TextFindIndex(gamepadNameLower, PS_ALIAS) > -1)
            {
                DrawTexture(texPs3Pad, 0, 0, DARKGRAY)

                // Draw buttons: ps
                if (IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_MIDDLE)) DrawCircle(396, 222, 13, RED)

                // Draw buttons: basic
                if (IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_MIDDLE_LEFT)) DrawRectangle(328, 170, 32, 13, RED)
                if (IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_MIDDLE_RIGHT)) 
                    DrawTriangle(
                        { x: 436, y: 168 }, 
                        { x: 436, y: 185 }, 
                        { x: 464, y: 177 }, 
                        RED
                    )
                if (IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_RIGHT_FACE_UP)) DrawCircle(557, 144, 13, LIME)
                if (IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_RIGHT_FACE_RIGHT)) DrawCircle(586, 173, 13, RED)
                if (IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)) DrawCircle(557, 203, 13, VIOLET)
                if (IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_RIGHT_FACE_LEFT)) DrawCircle(527, 173, 13, PINK)

                // Draw buttons: d-pad
                DrawRectangle(225, 132, 24, 84, BLACK)
                DrawRectangle(195, 161, 84, 25, BLACK)
                if (IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_LEFT_FACE_UP)) DrawRectangle(225, 132, 24, 29, RED)
                if (IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_LEFT_FACE_DOWN)) DrawRectangle(225, 132 + 54, 24, 30, RED)
                if (IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_LEFT_FACE_LEFT)) DrawRectangle(195, 161, 30, 25, RED)
                if (IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_LEFT_FACE_RIGHT)) DrawRectangle(195 + 54, 161, 30, 25, RED)

                // Draw buttons: left-right back buttons
                if (IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_LEFT_TRIGGER_1)) DrawCircle(239, 82, 20, RED)
                if (IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_RIGHT_TRIGGER_1)) DrawCircle(557, 82, 20, RED)

                // Draw axis: left joystick
                let leftGamepadColor = BLACK
                if (IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_LEFT_THUMB)) leftGamepadColor = RED
                DrawCircle(319, 255, 35, BLACK)
                DrawCircle(319, 255, 31, LIGHTGRAY)
                DrawCircle(319 + Math.floor(leftStickX*20),
                           255 + Math.floor(leftStickY*20), 25, leftGamepadColor)

                // Draw axis: right joystick
                let rightGamepadColor = BLACK
                if (IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_RIGHT_THUMB)) rightGamepadColor = RED
                DrawCircle(475, 255, 35, BLACK)
                DrawCircle(475, 255, 31, LIGHTGRAY)
                DrawCircle(475 + Math.floor(rightStickX*20),
                           255 + Math.floor(rightStickY*20), 25, rightGamepadColor)

                // Draw axis: left-right triggers
                DrawRectangle(169, 48, 15, 70, GRAY)
                DrawRectangle(611, 48, 15, 70, GRAY)
                DrawRectangle(169, 48, 15, Math.floor(((1 + leftTrigger)/2)*70), RED)
                DrawRectangle(611, 48, 15, Math.floor(((1 + rightTrigger)/2)*70), RED)
            }
            else
            {
                // Draw background: generic
                DrawRectangleRounded({ x: 175, y: 110, width: 460, height: 220}, 0.3, 16, DARKGRAY)

                // Draw buttons: basic
                DrawCircle(365, 170, 12, RAYWHITE)
                DrawCircle(405, 170, 12, RAYWHITE)
                DrawCircle(445, 170, 12, RAYWHITE)
                DrawCircle(516, 191, 17, RAYWHITE)
                DrawCircle(551, 227, 17, RAYWHITE)
                DrawCircle(587, 191, 17, RAYWHITE)
                DrawCircle(551, 155, 17, RAYWHITE)
                if (IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_MIDDLE_LEFT)) DrawCircle(365, 170, 10, RED)
                if (IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_MIDDLE)) DrawCircle(405, 170, 10, GREEN)
                if (IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_MIDDLE_RIGHT)) DrawCircle(445, 170, 10, BLUE)
                if (IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_RIGHT_FACE_LEFT)) DrawCircle(516, 191, 15, GOLD)
                if (IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)) DrawCircle(551, 227, 15, BLUE)
                if (IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_RIGHT_FACE_RIGHT)) DrawCircle(587, 191, 15, GREEN)
                if (IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_RIGHT_FACE_UP)) DrawCircle(551, 155, 15, RED)

                // Draw buttons: d-pad
                DrawRectangle(245, 145, 28, 88, RAYWHITE)
                DrawRectangle(215, 174, 88, 29, RAYWHITE)
                DrawRectangle(247, 147, 24, 84, BLACK)
                DrawRectangle(217, 176, 84, 25, BLACK)
                if (IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_LEFT_FACE_UP)) DrawRectangle(247, 147, 24, 29, RED)
                if (IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_LEFT_FACE_DOWN)) DrawRectangle(247, 147 + 54, 24, 30, RED)
                if (IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_LEFT_FACE_LEFT)) DrawRectangle(217, 176, 30, 25, RED)
                if (IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_LEFT_FACE_RIGHT)) DrawRectangle(217 + 54, 176, 30, 25, RED)

                // Draw buttons: left-right back
                DrawRectangleRounded({ x: 215, y: 98, width: 100, height: 10}, 0.5, 16, DARKGRAY)
                DrawRectangleRounded({ x: 495, y: 98, width: 100, height: 10}, 0.5, 16, DARKGRAY)
                if (IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_LEFT_TRIGGER_1)) 
                    DrawRectangleRounded({ x: 215, y: 98, width: 100, height: 10}, 0.5, 16, RED)
                if (IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_RIGHT_TRIGGER_1)) 
                    DrawRectangleRounded({ x: 495, y: 98, width: 100, height: 10}, 0.5, 16, RED)

                // Draw axis: left joystick
                let leftGamepadColor = BLACK
                if (IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_LEFT_THUMB)) leftGamepadColor = RED
                DrawCircle(345, 260, 40, BLACK)
                DrawCircle(345, 260, 35, LIGHTGRAY)
                DrawCircle(345 + Math.floor(leftStickX*20),
                           260 + Math.floor(leftStickY*20), 25, leftGamepadColor)

                // Draw axis: right joystick
                let rightGamepadColor = BLACK
                if (IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_RIGHT_THUMB)) rightGamepadColor = RED
                DrawCircle(465, 260, 40, BLACK)
                DrawCircle(465, 260, 35, LIGHTGRAY)
                DrawCircle(465 + Math.floor(rightStickX*20),
                           260 + Math.floor(rightStickY*20), 25, rightGamepadColor)

                // Draw axis: left-right triggers
                DrawRectangle(151, 110, 15, 70, GRAY)
                DrawRectangle(644, 110, 15, 70, GRAY)
                DrawRectangle(151, 110, 15, Math.floor(((1 + leftTrigger)/2)*70), RED)
                DrawRectangle(644, 110, 15, Math.floor(((1 + rightTrigger)/2)*70), RED)
            }

            DrawText(TextFormat("DETECTED AXIS [%i]:", GetGamepadAxisCount(0)), 10, 50, 10, MAROON)

            for (let i = 0; i < GetGamepadAxisCount(0); i++)
            {
                DrawText(TextFormat("AXIS %i: %.02f", i, GetGamepadAxisMovement(0, i)), 20, 70 + 20*i, 10, DARKGRAY)
            }

            const buttonPressed = GetGamepadButtonPressed()
            if (buttonPressed != GAMEPAD_BUTTON_UNKNOWN) 
                DrawText(TextFormat("DETECTED BUTTON: %i", buttonPressed), 10, 430, 10, RED)
            else 
                DrawText("DETECTED BUTTON: NONE", 10, 430, 10, GRAY)
        }
        else
        {
            DrawText(TextFormat("GP%d: NOT DETECTED", gamepad), 10, 10, 10, GRAY)

            DrawTexture(texXboxPad, 0, 0, LIGHTGRAY)
        }

    EndDrawing()
    //----------------------------------------------------------------------------------
}

// De-Initialization
//--------------------------------------------------------------------------------------
UnloadTexture(texPs3Pad)
UnloadTexture(texXboxPad)

CloseWindow()        // Close window and OpenGL context
//--------------------------------------------------------------------------------------