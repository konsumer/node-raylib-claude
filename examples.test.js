import { describe, it } from 'node:test'
import assert from 'node:assert'
import { execFile } from 'node:child_process'
import { readdirSync } from 'node:fs'
import { join, dirname } from 'node:path'
import { fileURLToPath } from 'node:url'

// Get the current directory
const __filename = fileURLToPath(import.meta.url)
const __dirname = dirname(__filename)

// Configuration
const TIMEOUT_MS = 1500 // Run each example for 1.5 seconds
const EXAMPLES_DIR = join(__dirname, 'examples')

// Get all JS files in the examples directory
const exampleFiles = readdirSync(EXAMPLES_DIR)
  .filter(file => file.endsWith('.js'))
  .map(file => join(EXAMPLES_DIR, file))

// Function to test a single example
function testExample(filePath) {
  return new Promise((resolve, reject) => {
    // We'll use execFile instead of spawn for simpler handling
    const childProcess = execFile('node', [filePath], {
      timeout: TIMEOUT_MS,
      killSignal: 'SIGTERM'
    }, (error, stdout, stderr) => {
      // If there was an error but it's just a timeout, we consider that successful
      // (examples are expected to run continuously until killed)
      if (error && error.killed) {
        resolve({ success: true });
        return;
      }

      // If there was some other error, report it
      if (error) {
        resolve({
          success: false,
          error: `Execution error: ${error.message}`,
          stdout,
          stderr
        });
        return;
      }

      // No error, process exited normally
      resolve({ success: true });
    });
  });
}

describe('Example tests', () => {
  // Basic test to ensure we found examples
  it('Should find example files', () => {
    assert.ok(exampleFiles.length > 0, 'No example files found');
    console.log(`Found ${exampleFiles.length} examples to test`);
  });

  // Test each example individually
  for (const file of exampleFiles) {
    const filename = file.split('/').pop();

    it(`Example "${filename}" should run without crashing`, async () => {
      const result = await testExample(file);

      // if (!result.success) {
      //   console.error(`Error running ${filename}:`);
      //   if (result.stdout) console.error(`stdout: ${result.stdout}`);
      //   if (result.stderr) console.error(`stderr: ${result.stderr}`);
      // }

      assert.equal(result.success, true, result.error || 'Example crashed');
    });
  }
});
