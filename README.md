# node-raylib

This is a very light NAPI-based binding for raylib 5.5 that uses modern JavaScript (ES modules).

## Features

- Complete bindings for raylib 5.5
- Uses N-API for ABI stability across Node.js versions (and even BunJS!)
- ES Module format for modern JavaScript projects
- Automated code-generation from the [raylib API definition](https://github.com/RobLoach/raylib-api)

## Installation

```bash
npm install raylib
```

## Usage

```javascript
import {
  InitWindow,
  WindowShouldClose,
  SetTargetFPS,
  CloseWindow,
  BeginDrawing,
  ClearBackground,
  DrawText,
  EndDrawing,
  RED,
  RAYWHITE
} from 'raylib'

// Initialize window
InitWindow(800, 450, "raylib [core] example")
SetTargetFPS(60)

// Main game loop
while (!WindowShouldClose()) {
  BeginDrawing()
  ClearBackground(RAYWHITE)
  DrawText("Congrats! You created your first raylib window!", 190, 200, 20, RED)
  EndDrawing()
}

// Close window
CloseWindow()
```

## Development

### Building

```bash
# Generate bindings
npm run generate

# Compile the native module
npm run compile

# Clean build artifacts
npm run clean

# Rebuild from scratch
npm run rebuild

# Run the example
npm run test:example
```

## License

This project is licensed under the Zlib License - see the LICENSE file for details.

## Credits

Based on the work in [node-raylib](https://github.com/RobLoach/node-raylib).
