// this will generate the Node interface for JS

import { writeFile } from 'node:fs/promises'
import path from 'node:path'
import { fileURLToPath } from 'node:url'
import { raylib as raylibJson } from '@raylib/api'

// Generate a clean JS interface
let jsCode = `// Auto-generated raylib bindings for Node.js
// Generated from @raylib/api ${raylibJson.version}

import { createRequire } from 'node:module';
const require = createRequire(import.meta.url);
const bindings = require('./build/Release/node-raylib.node');

export default bindings;

// Add convenient aliases and property exports for commonly used types
`

// Generate export statements for each binding property
jsCode += `\n// Export all functions and objects from bindings\n`
raylibJson.functions.forEach(func => {
  jsCode += `export const ${func.name} = bindings.${func.name};\n`
})

// Generate convenient constants for enum values
raylibJson.enums.forEach(enumDef => {
  jsCode += `\n// ${enumDef.name} enum values\n`
  
  // Export direct constants for each enum value
  enumDef.values.forEach(value => {
    jsCode += `export const ${value.name} = ${value.value};\n`
  })
})

// Add common color constants 
jsCode += `\n// Common color constants\n`
jsCode += `export const RED = { r: 255, g: 0, b: 0, a: 255 };\n`
jsCode += `export const GREEN = { r: 0, g: 255, b: 0, a: 255 };\n`
jsCode += `export const BLUE = { r: 0, g: 0, b: 255, a: 255 };\n`
jsCode += `export const BLACK = { r: 0, g: 0, b: 0, a: 255 };\n`
jsCode += `export const WHITE = { r: 255, g: 255, b: 255, a: 255 };\n`
jsCode += `export const RAYWHITE = { r: 245, g: 245, b: 245, a: 255 };\n`
jsCode += `export const LIGHTGRAY = { r: 200, g: 200, b: 200, a: 255 };\n`
jsCode += `export const GRAY = { r: 130, g: 130, b: 130, a: 255 };\n`
jsCode += `export const DARKGRAY = { r: 80, g: 80, b: 80, a: 255 };\n`
jsCode += `export const YELLOW = { r: 255, g: 255, b: 0, a: 255 };\n`
jsCode += `export const GOLD = { r: 255, g: 203, b: 0, a: 255 };\n`
jsCode += `export const ORANGE = { r: 255, g: 161, b: 0, a: 255 };\n`
jsCode += `export const PINK = { r: 255, g: 109, b: 194, a: 255 };\n`
jsCode += `export const MAROON = { r: 190, g: 33, b: 55, a: 255 };\n`
jsCode += `export const LIME = { r: 0, g: 158, b: 47, a: 255 };\n`
jsCode += `export const DARKGREEN = { r: 0, g: 117, b: 44, a: 255 };\n`
jsCode += `export const SKYBLUE = { r: 102, g: 191, b: 255, a: 255 };\n`
jsCode += `export const DARKBLUE = { r: 0, g: 82, b: 172, a: 255 };\n`
jsCode += `export const PURPLE = { r: 200, g: 122, b: 255, a: 255 };\n`
jsCode += `export const VIOLET = { r: 135, g: 60, b: 190, a: 255 };\n`
jsCode += `export const DARKPURPLE = { r: 112, g: 31, b: 126, a: 255 };\n`
jsCode += `export const BEIGE = { r: 211, g: 176, b: 131, a: 255 };\n`
jsCode += `export const BROWN = { r: 127, g: 106, b: 79, a: 255 };\n`
jsCode += `export const DARKBROWN = { r: 76, g: 63, b: 47, a: 255 };\n`
jsCode += `export const TRANSPARENT = { r: 0, g: 0, b: 0, a: 0 };\n`

// Export the Color helper
jsCode += `\n// Export Color helper function\n`
jsCode += `export const Color = (r, g, b, a = 255) => ({ r, g, b, a });\n`

// Write the generated code to file
await writeFile(path.join(fileURLToPath(import.meta.url), '..', '..', 'index.js'), jsCode)
console.log('Raylib JS bindings generated successfully!')
