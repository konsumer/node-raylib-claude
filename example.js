// Example usage of node-raylib
import { 
  InitWindow, CloseWindow, BeginDrawing, EndDrawing,
  ClearBackground, DrawText, SetTargetFPS, WindowShouldClose,
  DrawRectangle,
  BLACK, RAYWHITE, RED, GREEN, BLUE, WHITE
} from './index.js'

InitWindow(800, 450, "raylib [core] test")
SetTargetFPS(60)

while (!WindowShouldClose()) {
  BeginDrawing()
  ClearBackground(RAYWHITE)
  
  // Draw color bars
  DrawText("Welcome to raylib in Node.js!", 190, 80, 20, BLACK)
  
  const barWidth = 100
  const barHeight = 40
  const startX = 150
  const startY = 150
  
  // Draw color samples with labels
  DrawText("RED", startX + 40, startY, 20, BLACK)
  DrawText("GREEN", startX + 40 + barWidth, startY, 20, BLACK)
  DrawText("BLUE", startX + 40 + barWidth*2, startY, 20, BLACK)
  DrawText("WHITE", startX + 40 + barWidth*3, startY, 20, BLACK)
  
  // Draw color rectangles
  DrawRectangle(startX, startY + 30, barWidth, barHeight, RED)
  DrawRectangle(startX + barWidth, startY + 30, barWidth, barHeight, GREEN)
  DrawRectangle(startX + barWidth*2, startY + 30, barWidth, barHeight, BLUE)
  DrawRectangle(startX + barWidth*3, startY + 30, barWidth, barHeight, WHITE)
  
  DrawText("These colors show the bindings are working correctly!", 150, 250, 20, BLACK)
  
  EndDrawing()
}

CloseWindow()
