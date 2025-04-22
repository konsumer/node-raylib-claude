# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Build Commands

- `npm run build` - Compile the project using cmake-js
- `npm run clean` - Clean build artifacts
- `npm test` - Run tests (uses Node.js built-in test runner)

## Code Style Guidelines

- **JavaScript**: Use ES Modules (import/export syntax) with standardjs-style.
- **C Code**: Follow C11 standard, use N-API conventions
- **Naming**: Use camelCase for JavaScript functions, snake_case for C functions
- **Formatting**: Maintain consistent indentation (2 spaces)
- **Error Handling**: Use proper N-API error checking in C code
- **Types**: Follow raylib type conventions for consistency
- **Imports**: Group imports by source (node: prefixed first)
- **Generation**: Use tools/gen\_\*.js scripts for generating bindings
- **Comments**: Document complex conversions between JS and C types

## Repository Structure

- `src/` - C bindings code
- `tools/` - Code generation utilities
- `index.js` - Main module entry point for NodeJs

## Code Generation Notes

- **Variadic Functions**: Use special handling for '...' parameters
- **Void Pointers**: Use void_ptr typedef for void* parameters
- **Memory Management**: Free resources like strings properly
- **Struct Conversions**: Generate proper type conversions for raylib structs
- **Colors**: Objects with properties r, g, b, a (0-255 values)

## Color Handling

- **Color Objects**: Colors are defined as objects with r, g, b, a properties (all 0-255)
- **Color Constants**: Standard color constants provided (RED, BLUE, GREEN, etc.)
- **Color Creation**: Use function `Color(r, g, b, a)` to create color objects
- **Example**: `const myRed = { r: 255, g: 0, b: 0, a: 255 }` or `const myRed = Color(255, 0, 0, 255)`

## Known Issues

### Audio Bindings

The current audio bindings have critical issues with pointer handling that affect functionality:

1. **Audio Loading Works, Playback Doesn't**:
   - Sound files load correctly (LoadSound/LoadMusicStream)
   - But audio doesn't play when PlaySound/PlayMusicStream are called
   - IsSoundPlaying always returns false

2. **Technical Root Cause**:
   - The AudioStream struct contains critical pointer fields: `buffer` and `processor`
   - The current bindings zero out these pointers during JS-to-C conversion
   - The AudioStream_from_js function contains TODOs for these fields
   - Without these pointers, audio can't actually play

3. **Potential Segfaults**:
   - In complex examples, audio operations may cause segfaults
   - This is due to inconsistent handling of audio resource lifecycle
   - Global references (global.sound = LoadSound(...)) can help prevent some issues

4. **Fix Required**:
   - The gen_c.js binding generator needs to be updated to handle pointer fields
   - Proper reference counting should be implemented for audio resources
   - Complete the TODOs in AudioStream_from_js and AudioStream_to_js

Until these issues are fixed, avoid demos that rely on audio playback or add clear documentation that audio won't be heard.