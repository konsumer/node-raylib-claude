# node-raylib

This is a very light NAPI-based binding for raylib 5.5 that uses modern JavaScript (ES modules).

## Features

- Complete bindings for raylib 5.5
- Uses N-API for ABI stability across Node.js versions
- ES Module format for modern JavaScript projects
- Automated code generation from the raylib API definition

## Installation

```bash
npm install raylib
```

## Usage

```javascript
import raylib from 'raylib';

// Initialize window
raylib.InitWindow(800, 450, "raylib [core] example");
raylib.SetTargetFPS(60);

// Define colors for easier use
const RED = { r: 255, g: 0, b: 0, a: 255 };
const RAYWHITE = { r: 245, g: 245, b: 245, a: 255 };

// Main game loop
while (!raylib.WindowShouldClose()) {
  raylib.BeginDrawing();
  raylib.ClearBackground(RAYWHITE);
  raylib.DrawText("Congrats! You created your first raylib window!", 190, 200, 20, RED);
  raylib.EndDrawing();
}

// Close window
raylib.CloseWindow();
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
