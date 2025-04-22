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

// Add color definitions
jsCode += `\n// Color creation helper\n`
jsCode += `const createColor = (r, g, b, a = 255) => ({ r, g, b, a });\n\n`

// Add common color constants 
jsCode += `// Common color constants\n`
jsCode += `export const RED = createColor(255, 0, 0, 255);\n`
jsCode += `export const GREEN = createColor(0, 255, 0, 255);\n`
jsCode += `export const BLUE = createColor(0, 0, 255, 255);\n`
jsCode += `export const BLACK = createColor(0, 0, 0, 255);\n`
jsCode += `export const WHITE = createColor(255, 255, 255, 255);\n`
jsCode += `export const RAYWHITE = createColor(245, 245, 245, 255);\n`
jsCode += `export const LIGHTGRAY = createColor(200, 200, 200, 255);\n`
jsCode += `export const GRAY = createColor(130, 130, 130, 255);\n`
jsCode += `export const DARKGRAY = createColor(80, 80, 80, 255);\n`
jsCode += `export const YELLOW = createColor(255, 255, 0, 255);\n`
jsCode += `export const GOLD = createColor(255, 203, 0, 255);\n`
jsCode += `export const ORANGE = createColor(255, 161, 0, 255);\n`
jsCode += `export const PINK = createColor(255, 109, 194, 255);\n`
jsCode += `export const MAROON = createColor(190, 33, 55, 255);\n`
jsCode += `export const LIME = createColor(0, 158, 47, 255);\n`
jsCode += `export const DARKGREEN = createColor(0, 117, 44, 255);\n`
jsCode += `export const SKYBLUE = createColor(102, 191, 255, 255);\n`
jsCode += `export const DARKBLUE = createColor(0, 82, 172, 255);\n`
jsCode += `export const PURPLE = createColor(200, 122, 255, 255);\n`
jsCode += `export const VIOLET = createColor(135, 60, 190, 255);\n`
jsCode += `export const DARKPURPLE = createColor(112, 31, 126, 255);\n`
jsCode += `export const BEIGE = createColor(211, 176, 131, 255);\n`
jsCode += `export const BROWN = createColor(127, 106, 79, 255);\n`
jsCode += `export const DARKBROWN = createColor(76, 63, 47, 255);\n`
jsCode += `export const TRANSPARENT = createColor(0, 0, 0, 0);\n`

// Export the Color helper
jsCode += `\n// Export Color helper function\n`
jsCode += `export const Color = createColor;\n`

// Write the generated code to file
await writeFile(path.join(fileURLToPath(import.meta.url), '..', '..', 'index.js'), jsCode)
console.log('Raylib JS bindings generated successfully!')
