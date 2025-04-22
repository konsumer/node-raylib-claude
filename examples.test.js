import { describe, test } from 'node:test'
import assert from 'node:assert'
import { spawn } from 'node:child_process'
import { readdirSync } from 'node:fs'
import { join, dirname } from 'node:path'
import { fileURLToPath } from 'node:url'

// Get the current directory
const __filename = fileURLToPath(import.meta.url)
const __dirname = dirname(__filename)

// Configuration
const TIMEOUT_MS = 1000 // Run each example for 1 seconds
const EXAMPLES_DIR = join(__dirname, 'examples')

// Get all JS files in the examples directory
const exampleFiles = readdirSync(EXAMPLES_DIR)
  .filter(file => file.endsWith('.js'))
  .map(file => join(EXAMPLES_DIR, file))

// Function to test a single example
function testExample(filePath) {
  return new Promise((resolve) => {
    // Start the example
    const process = spawn('node', [filePath], {
      stdio: 'pipe' // Suppress console output from the examples
    })

    process.stderr.on('data', (data) => {
      console.error(data.toString());
    });

    // Check for immediate errors
    process.on('error', (err) => {
      resolve({ success: false, error: err.message })
    })

    let exitCode = 0
    process.on('exit', (code) => {
      exitCode = code;
    })

    // Set a timeout to kill the process after specified duration
    const timeout = setTimeout(() => {
      process.kill()
      if (exitCode !== 0 && exitCode !== null) {
        resolve({ success: false, error: `Process exited with code ${exitCode}` })
      } else {
        resolve({ success: true })
      }
    }, TIMEOUT_MS)
  })
}

describe('Example tests', async () => {
  // Basic test to ensure we found examples
  test('Should find example files', () => {
    assert.equal(exampleFiles.length > 0, true, 'No example files found')
    console.log(`Found ${exampleFiles.length} examples to test`)
  })

  // Test each example
  for (const file of exampleFiles) {
    const filename = file.split('/').pop()

    test(`Example "${filename}" should run without crashing`, async () => {
      const result = await testExample(file)
      assert.equal(result.success, true, result.error || `Example crashed`)
    })
  }
})
