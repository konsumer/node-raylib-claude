// this will generate the NAPI C interface for node

import { writeFile } from 'node:fs/promises'
import path from 'node:path'
import { fileURLToPath } from 'node:url'
import raylibJson from './api.js'

// First, build a set of all struct types that need conversions
const structTypesNeeded = new Set()

// Add all struct types from the structs section
raylibJson.structs.forEach((struct) => {
  structTypesNeeded.add(struct.name)
})

// Scan function parameters and return types to find additional struct types
raylibJson.functions.forEach((func) => {
  // Check return type
  if (func.returnType && !isBasicType(func.returnType) && func.returnType.trim() !== 'void') {
    const cleanType = cleanTypeName(func.returnType)
    if (!cleanType.includes('*')) {
      // For non-pointer struct returns
      structTypesNeeded.add(cleanType)
    }
  }

  // Check parameters
  if (func.params) {
    func.params.forEach((param) => {
      // Skip ellipsis parameters
      if (param.type.trim() === '...') {
        return
      }

      if (!isBasicType(param.type) && param.type.trim() !== 'void') {
        const cleanType = cleanTypeName(param.type)
        if (!cleanType.includes('*')) {
          // For non-pointer struct params
          structTypesNeeded.add(cleanType)
        } else if (cleanType.includes('*') && !cleanType.startsWith('char') && !cleanType.startsWith('const char')) {
          // For pointer to struct (not char*)
          structTypesNeeded.add(cleanType.replace('*', '').trim())
        }
      }
    })
  }
})

// Helper function to check if a type is a basic C type
function isBasicType(type) {
  const basicTypes = ['void', 'char', 'unsigned char', 'short', 'unsigned short', 'int', 'unsigned int', 'long', 'unsigned long', 'float', 'double', 'bool', 'char *', 'const char *']
  return basicTypes.some((bt) => type.trim() === bt || type.trim() === `const ${bt}`)
}

// Helper function to clean up type names
function cleanTypeName(type) {
  return type.replace('const ', '').trim()
}

// Function to sanitize type names for use in function identifiers
function sanitizeTypeName(typeName) {
  // Replace problematic characters with underscores
  return typeName.replace(/[^a-zA-Z0-9_]/g, '_')
}


// Generated C file header
let bindingsSource = `#include <node_api.h>
#include <raylib.h>
#include <raymath.h>
#include <rlgl.h>
#include <stdlib.h>
#include <string.h>

// Utility functions for N-API
napi_value CreateNumber(napi_env env, double value) {
    napi_value result;
    napi_create_double(env, value, &result);
    return result;
}

napi_value CreateString(napi_env env, const char* value) {
    napi_value result;
    napi_create_string_utf8(env, value, NAPI_AUTO_LENGTH, &result);
    return result;
}

// Forward declarations for struct conversions
`

// Generate struct conversion forward declarations
structTypesNeeded.forEach((structType) => {
  // Avoid generating void_to_js and void_from_js functions
  // Also skip empty strings and sanitize function names
  if (structType !== 'void' && structType !== '') {
    const sanitizedType = sanitizeTypeName(structType)
    bindingsSource += `${structType} ${sanitizedType}_from_js(napi_env env, napi_value jsObj);\n`
    bindingsSource += `napi_value ${sanitizedType}_to_js(napi_env env, ${structType} data);\n`
  }
})

bindingsSource += `\n// Forward declarations for functions\n`

// Generate enums
function generateEnums() {
  let enumsCode = '// Enum definitions\n'

  raylibJson.enums.forEach((enumDef) => {
    enumsCode += `napi_value Create_${sanitizeTypeName(enumDef.name)}(napi_env env) {\n`
    enumsCode += '    napi_value enumObj;\n'
    enumsCode += '    napi_create_object(env, &enumObj);\n\n'

    enumDef.values.forEach((value) => {
      enumsCode += `    // ${value.description}\n`
      enumsCode += `    napi_value ${sanitizeTypeName(value.name)}_val;\n`
      enumsCode += `    napi_create_int32(env, ${value.value}, &${sanitizeTypeName(value.name)}_val);\n`
      enumsCode += `    napi_set_named_property(env, enumObj, "${value.name}", ${sanitizeTypeName(value.name)}_val);\n\n`
    })

    enumsCode += '    return enumObj;\n'
    enumsCode += '}\n\n'
  })

  return enumsCode
}

// Generate structs
function generateStructs() {
  let structsCode = '// Struct conversions\n'

  // Only generate conversions for structs we actually have definitions for
  const definedStructs = new Set(raylibJson.structs.map((struct) => struct.name))

  raylibJson.structs.forEach((structDef) => {
    const sanitizedType = sanitizeTypeName(structDef.name)

    // JS to C struct conversion
    structsCode += `${structDef.name} ${sanitizedType}_from_js(napi_env env, napi_value jsObj) {\n`
    structsCode += `    ${structDef.name} result;\n`
    structsCode += '    napi_value prop;\n'
    structsCode += '    bool has_property;\n\n'

    structDef.fields.forEach((field) => {
      structsCode += `    // Get ${field.name}\n`
      structsCode += `    napi_has_named_property(env, jsObj, "${field.name}", &has_property);\n`
      structsCode += `    if (has_property) {\n`
      structsCode += `        napi_get_named_property(env, jsObj, "${field.name}", &prop);\n`

      if (field.type === 'float') {
        structsCode += `        double temp_${sanitizeTypeName(field.name)};\n`
        structsCode += `        napi_get_value_double(env, prop, &temp_${sanitizeTypeName(field.name)});\n`
        structsCode += `        result.${field.name} = (float)temp_${sanitizeTypeName(field.name)};\n`
      } else if (field.type === 'int' || field.type === 'unsigned int') {
        structsCode += `        napi_get_value_int32(env, prop, (int32_t*)&result.${field.name});\n`
      } else if (field.type === 'unsigned char' || field.type === 'char') {
        // Handle byte types (e.g. Color fields)
        structsCode += `        int32_t temp_${sanitizeTypeName(field.name)};\n`
        structsCode += `        napi_get_value_int32(env, prop, &temp_${sanitizeTypeName(field.name)});\n`
        structsCode += `        result.${field.name} = (unsigned char)temp_${sanitizeTypeName(field.name)};\n`
      } else if (field.type === 'bool') {
        structsCode += `        napi_get_value_bool(env, prop, &result.${field.name});\n`
      } else if (field.type === 'char *' || field.type === 'const char *') {
        structsCode += `        size_t str_len;\n`
        structsCode += `        napi_get_value_string_utf8(env, prop, NULL, 0, &str_len);\n`
        structsCode += `        result.${field.name} = (char*)malloc(str_len + 1);\n`
        structsCode += `        napi_get_value_string_utf8(env, prop, (char*)result.${field.name}, str_len + 1, &str_len);\n`
      } else if (definedStructs.has(field.type)) {
        // Only use _from_js for structs we know about
        const fieldSanitizedType = sanitizeTypeName(field.type)
        structsCode += `        result.${field.name} = ${fieldSanitizedType}_from_js(env, prop);\n`
      } else if (field.type.includes('*')) {
        // For pointer fields in from_js
        structsCode += `        // Handle pointer type ${field.type}\n`
        structsCode += `        napi_valuetype valueType;\n`
        structsCode += `        napi_typeof(env, prop, &valueType);\n`
        structsCode += `        if (valueType == napi_number) {\n`
        structsCode += `            double pointerValue;\n`
        structsCode += `            napi_get_value_double(env, prop, &pointerValue);\n`
        structsCode += `            result.${field.name} = (${field.type.replace('*', '').trim()}*)(uintptr_t)pointerValue;\n`
        structsCode += `        } else {\n`
        structsCode += `            result.${field.name} = NULL;\n`
        structsCode += `        }\n`
      } else {
        structsCode += `        // TODO: Handle field type ${field.type}\n`
      }

      structsCode += `    } else {\n`
      structsCode += `        // Set default value\n`
      if (field.type === 'float' || field.type === 'int' || field.type === 'unsigned int') {
        structsCode += `        result.${field.name} = 0;\n`
      } else if (field.type === 'unsigned char' || field.type === 'char') {
        structsCode += `        result.${field.name} = 0;\n`
      } else if (field.type === 'bool') {
        structsCode += `        result.${field.name} = false;\n`
      } else if (field.type === 'char *' || field.type === 'const char *') {
        structsCode += `        result.${field.name} = NULL;\n`
      } else if (field.type.includes('*')) {
        structsCode += `        // Set default NULL for pointer type ${field.type}\n`
        structsCode += `        result.${field.name} = NULL;\n`
      } else {
        structsCode += `        // TODO: Set default for ${field.type}\n`
        structsCode += `        memset(&result.${field.name}, 0, sizeof(result.${field.name}));\n`
      }
      structsCode += `    }\n\n`
    })

    structsCode += '    return result;\n'
    structsCode += '}\n\n'

    // C struct to JS conversion
    structsCode += `napi_value ${sanitizedType}_to_js(napi_env env, ${structDef.name} data) {\n`
    structsCode += '    napi_value jsObj;\n'
    structsCode += '    napi_create_object(env, &jsObj);\n'
    structsCode += '    napi_value prop;\n\n'

    structDef.fields.forEach((field) => {
      structsCode += `    // Set ${field.name}\n`
      if (field.type === 'float') {
        structsCode += `    napi_create_double(env, (double)data.${field.name}, &prop);\n`
      } else if (field.type === 'int' || field.type === 'unsigned int') {
        structsCode += `    napi_create_int32(env, (int32_t)data.${field.name}, &prop);\n`
      } else if (field.type === 'unsigned char' || field.type === 'char') {
        structsCode += `    napi_create_int32(env, (int32_t)data.${field.name}, &prop);\n`
      } else if (field.type === 'bool') {
        structsCode += `    napi_get_boolean(env, data.${field.name}, &prop);\n`
      } else if (field.type === 'char *' || field.type === 'const char *') {
        structsCode += `    if (data.${field.name} != NULL) {\n`
        structsCode += `        napi_create_string_utf8(env, data.${field.name}, NAPI_AUTO_LENGTH, &prop);\n`
        structsCode += `    } else {\n`
        structsCode += `        napi_get_null(env, &prop);\n`
        structsCode += `    }\n`
      } else if (definedStructs.has(field.type)) {
        // Only use _to_js for structs we know about
        const fieldSanitizedType = sanitizeTypeName(field.type)
        structsCode += `    prop = ${fieldSanitizedType}_to_js(env, data.${field.name});\n`
      } else if (field.type.includes('*')) {
        // For pointer fields in to_js
        structsCode += `    // Handle pointer type ${field.type}\n`
        structsCode += `    if (data.${field.name} != NULL) {\n`
        structsCode += `        // Store the pointer as a double (JS Number)\n`
        structsCode += `        napi_create_double(env, (double)(uintptr_t)data.${field.name}, &prop);\n`
        structsCode += `    } else {\n`
        structsCode += `        napi_get_null(env, &prop);\n`
        structsCode += `    }\n`
      } else {
        structsCode += `    // TODO: Handle field type ${field.type}\n`
        structsCode += `    napi_get_null(env, &prop);\n`
      }

      structsCode += `    napi_set_named_property(env, jsObj, "${field.name}", prop);\n\n`
    })

    structsCode += '    return jsObj;\n'
    structsCode += '}\n\n'
  })

  // Generate stub conversions for structs we need but don't have full definitions for
  const definedStructNames = new Set(raylibJson.structs.map((struct) => struct.name))

  structTypesNeeded.forEach((structType) => {
    if (!definedStructNames.has(structType) && structType !== '' && structType !== 'void') {
      const sanitizedType = sanitizeTypeName(structType)
      structsCode += `// Stub conversion for undefined struct ${structType}\n`

      // From JS conversion stub
      structsCode += `${structType} ${sanitizedType}_from_js(napi_env env, napi_value jsObj) {\n`
      structsCode += `    // Warning: No struct definition available for ${structType}\n`
      structsCode += `    ${structType} result;\n`
      structsCode += `    memset(&result, 0, sizeof(result));\n`
      structsCode += `    return result;\n`
      structsCode += `}\n\n`

      // To JS conversion stub
      structsCode += `napi_value ${sanitizedType}_to_js(napi_env env, ${structType} data) {\n`
      structsCode += `    // Warning: No struct definition available for ${structType}\n`
      structsCode += `    napi_value jsObj;\n`
      structsCode += `    napi_create_object(env, &jsObj);\n`
      structsCode += `    return jsObj;\n`
      structsCode += `}\n\n`
    }
  })

  return structsCode
}

// Generate function bindings
function generateFunctions() {
  let functionsCode = '// Function bindings\n'
  let functionDeclarations = ''
  let functionRegistrations = ''

  // Set of defined struct types for checking
  const definedStructs = new Set(raylibJson.structs.map((struct) => struct.name))

  // Add special handling for void* type
  bindingsSource += `// Special handler for void* type\n`
  bindingsSource += `void* void_ptr_from_js(napi_env env, napi_value jsObj) {\n`
  bindingsSource += `    // Check if it's a number (pointer stored as double)\n`
  bindingsSource += `    napi_valuetype valueType;\n`
  bindingsSource += `    napi_typeof(env, jsObj, &valueType);\n`
  bindingsSource += `    if (valueType == napi_number) {\n`
  bindingsSource += `        double pointerValue;\n`
  bindingsSource += `        napi_get_value_double(env, jsObj, &pointerValue);\n`
  bindingsSource += `        return (void*)(uintptr_t)pointerValue;\n`
  bindingsSource += `    }\n`
  bindingsSource += `    // In real implementation, you might want to handle Buffer objects\n`
  bindingsSource += `    return NULL;\n`
  bindingsSource += `}\n\n`
  bindingsSource += `napi_value void_ptr_to_js(napi_env env, void* data) {\n`
  bindingsSource += `    napi_value result;\n`
  bindingsSource += `    if (data != NULL) {\n`
  bindingsSource += `        // Store the pointer as a double (JS Number)\n`
  bindingsSource += `        napi_create_double(env, (double)(uintptr_t)data, &result);\n`
  bindingsSource += `    } else {\n`
  bindingsSource += `        napi_get_null(env, &result);\n`
  bindingsSource += `    }\n`
  bindingsSource += `    return result;\n`
  bindingsSource += `}\n\n`

  // We only need the void_ptr_from_js function, not any alias
  bindingsSource += `// Special handler for functions needing void* returns\n`
  bindingsSource += `typedef void* void_ptr;\n\n`

  raylibJson.functions.forEach((funcDef) => {
    const funcName = funcDef.name
    const sanitizedFuncName = sanitizeTypeName(funcName)
    functionDeclarations += `napi_value BindNode_${sanitizedFuncName}(napi_env env, napi_callback_info info);\n`

    functionsCode += `napi_value BindNode_${sanitizedFuncName}(napi_env env, napi_callback_info info) {\n`

    // Get parameters if any
    if (funcDef.params && funcDef.params.length > 0) {
      // Filter out variadic (...) parameters for parameter count checking
      const regularParams = funcDef.params.filter(param => param.type.trim() !== '...')
      const hasVariadic = funcDef.params.some(param => param.type.trim() === '...')

      // For variadic functions, we accept any number of arguments >= regularParams.length
      const minParams = regularParams.length

      functionsCode += `    size_t argc = ${funcDef.params.length};\n`
      functionsCode += `    napi_value args[${funcDef.params.length}];\n`
      functionsCode += '    napi_get_cb_info(env, info, &argc, args, NULL, NULL);\n\n'

      // Parameter validation - only check minimum number for variadic functions
      functionsCode += `    if (argc < ${minParams}) {\n`
      functionsCode += '        napi_throw_error(env, NULL, "Wrong number of arguments");\n'
      functionsCode += '        napi_value undefined;\n'
      functionsCode += '        napi_get_undefined(env, &undefined);\n'
      functionsCode += '        return undefined;\n'
      functionsCode += '    }\n\n'

      // Declare variables for parameters
      funcDef.params.forEach((param, index) => {
        const type = param.type.trim()
        const sanitizedParamName = sanitizeTypeName(param.name)

        // Skip ellipsis parameters
        if (type === '...') {
          return;
        }

        // Handle basic integer types
        if (type === 'int' || type === 'unsigned int' || type === 'short' || type === 'unsigned short' || type === 'char' || type === 'unsigned char') {
          functionsCode += `    ${type} ${sanitizedParamName};\n`
          functionsCode += `    napi_get_value_int32(env, args[${index}], (int32_t*)&${sanitizedParamName});\n\n`
        }
        // Handle larger integer types
        else if (type === 'long' || type === 'unsigned long' || type === 'long long' || type === 'unsigned long long') {
          functionsCode += `    ${type} ${sanitizedParamName};\n`
          functionsCode += `    napi_get_value_int64(env, args[${index}], (int64_t*)&${sanitizedParamName});\n\n`
        }
        // Handle floating point types
        else if (type === 'float' || type === 'double') {
          if (type === 'float') {
            functionsCode += `    double temp_${sanitizedParamName};\n`
            functionsCode += `    napi_get_value_double(env, args[${index}], &temp_${sanitizedParamName});\n`
            functionsCode += `    float ${sanitizedParamName} = (float)temp_${sanitizedParamName};\n\n`
          } else {
            functionsCode += `    double ${sanitizedParamName};\n`
            functionsCode += `    napi_get_value_double(env, args[${index}], &${sanitizedParamName});\n\n`
          }
        }
        // Handle boolean
        else if (type === 'bool') {
          functionsCode += `    bool ${sanitizedParamName};\n`
          functionsCode += `    napi_get_value_bool(env, args[${index}], &${sanitizedParamName});\n\n`
        }
        // Handle string types
        else if (type === 'const char *' || type === 'char *') {
          functionsCode += `    size_t ${sanitizedParamName}_len;\n`
          functionsCode += `    napi_get_value_string_utf8(env, args[${index}], NULL, 0, &${sanitizedParamName}_len);\n`
          functionsCode += `    char* ${sanitizedParamName} = (char*)malloc(${sanitizedParamName}_len + 1);\n`
          functionsCode += `    napi_get_value_string_utf8(env, args[${index}], ${sanitizedParamName}, ${sanitizedParamName}_len + 1, &${sanitizedParamName}_len);\n\n`
        }
        // Handle pointers to struct types
        else if (type.endsWith('*') && !type.startsWith('const char') && !type.startsWith('char')) {
          const structType = type.replace('*', '').trim()
          const sanitizedStructType = sanitizeTypeName(structType)

          // Check if we have a defined conversion for this struct
          if (structTypesNeeded.has(structType)) {
            functionsCode += `    ${structType} ${sanitizedParamName}_value = ${sanitizedStructType}_from_js(env, args[${index}]);\n`
            functionsCode += `    ${type} ${sanitizedParamName} = &${sanitizedParamName}_value;\n\n`
          } else {
            functionsCode += `    // Warning: No conversion available for ${structType}\n`
            functionsCode += `    ${type} ${sanitizedParamName} = NULL;\n\n`
          }
        }
        // Handle struct types passed by value
        else if (!type.includes('*')) {
          // Check if we have a defined conversion for this struct
          if (structTypesNeeded.has(type)) {
            const sanitizedStructType = sanitizeTypeName(type)
            functionsCode += `    ${type} ${sanitizedParamName} = ${sanitizedStructType}_from_js(env, args[${index}]);\n\n`
          } else {
            functionsCode += `    // Warning: No conversion available for ${type}\n`
            functionsCode += `    ${type} ${sanitizedParamName};\n`
            functionsCode += `    memset(&${sanitizedParamName}, 0, sizeof(${sanitizedParamName}));\n\n`
          }
        }
        // Handle void* pointers
        else if (type === 'void*' || type === 'const void*' || type === 'void *' || type === 'const void *') {
          functionsCode += `    ${type} ${sanitizedParamName} = void_ptr_from_js(env, args[${index}]);\n\n`;
        }
        // Add a fallback for any types we don't handle specifically
        else {
          functionsCode += `    // TODO: Handle parameter type ${type}\n`
          functionsCode += `    void* ${sanitizedParamName} = NULL; // Placeholder\n\n`
        }
      })
    }

    // Call the raylib function with parameters
    if (funcDef.returnType && funcDef.returnType !== 'void') {
      functionsCode += `    ${funcDef.returnType} result = ${funcName}(`
    } else {
      functionsCode += `    ${funcName}(`
    }

    // Add parameters to function call
    if (funcDef.params && funcDef.params.length > 0) {
      // Filter out ellipsis parameters before iterating
      const regularParams = funcDef.params.filter(param => param.type.trim() !== '...')

      regularParams.forEach((param, index) => {
        functionsCode += sanitizeTypeName(param.name)
        if (index < regularParams.length - 1) {
          functionsCode += ', '
        }
      })
    }
    functionsCode += ');\n'

    // Free any allocated memory
    if (funcDef.params && funcDef.params.length > 0) {
      funcDef.params.forEach((param) => {
        // Skip ellipsis parameters
        if (param.type.trim() === '...') {
          return;
        }

        const sanitizedParamName = sanitizeTypeName(param.name)
        if (param.type === 'const char *' || param.type === 'char *') {
          functionsCode += `    free(${sanitizedParamName});\n`
        }
      })
    }

    // Handle return value
    if (funcDef.returnType && funcDef.returnType !== 'void') {
      const returnType = funcDef.returnType.trim()

      // Handle known struct types
      if (structTypesNeeded.has(returnType)) {
        const sanitizedReturnType = sanitizeTypeName(returnType)
        functionsCode += `    return ${sanitizedReturnType}_to_js(env, result);\n`
      }
      // Handle floating point types
      else if (returnType === 'float' || returnType === 'double') {
        functionsCode += `    napi_value jsResult;\n`
        functionsCode += `    napi_create_double(env, (double)result, &jsResult);\n`
        functionsCode += `    return jsResult;\n`
      }
      // Handle integer types
      else if (returnType === 'int' || returnType === 'unsigned int' || returnType === 'short' || returnType === 'unsigned short' || returnType === 'char' || returnType === 'unsigned char') {
        functionsCode += `    napi_value jsResult;\n`
        functionsCode += `    napi_create_int32(env, (int32_t)result, &jsResult);\n`
        functionsCode += `    return jsResult;\n`
      }
      // Handle larger integer types
      else if (returnType === 'long' || returnType === 'unsigned long' || returnType === 'long long' || returnType === 'unsigned long long') {
        functionsCode += `    napi_value jsResult;\n`
        functionsCode += `    napi_create_int64(env, (int64_t)result, &jsResult);\n`
        functionsCode += `    return jsResult;\n`
      }
      // Handle boolean
      else if (returnType === 'bool') {
        functionsCode += `    napi_value jsResult;\n`
        functionsCode += `    napi_get_boolean(env, result, &jsResult);\n`
        functionsCode += `    return jsResult;\n`
      }
      // Handle string types
      else if (returnType === 'const char *' || returnType === 'char *') {
        functionsCode += `    napi_value jsResult;\n`
        functionsCode += `    if (result == NULL) {\n`
        functionsCode += `        napi_get_null(env, &jsResult);\n`
        functionsCode += `    } else {\n`
        functionsCode += `        napi_create_string_utf8(env, result, NAPI_AUTO_LENGTH, &jsResult);\n`
        functionsCode += `    }\n`
        functionsCode += `    return jsResult;\n`
      }
      // For other types, assume they're structs and try to use _to_js conversion
      else {
        functionsCode += `    // TODO: Handle return type ${returnType}\n`
        functionsCode += `    napi_value jsResult;\n`
        functionsCode += `    napi_get_null(env, &jsResult);\n`
        functionsCode += `    return jsResult; // Placeholder\n`
      }
    } else {
      functionsCode += '    napi_value jsResult;\n'
      functionsCode += '    napi_get_undefined(env, &jsResult);\n'
      functionsCode += '    return jsResult;\n'
    }

    functionsCode += '}\n\n'

    // Add function to module exports
    functionRegistrations += `    napi_value ${sanitizedFuncName}_fn;\n`
    functionRegistrations += `    napi_create_function(env, NULL, 0, BindNode_${sanitizedFuncName}, NULL, &${sanitizedFuncName}_fn);\n`
    functionRegistrations += `    napi_set_named_property(env, exports, "${funcName}", ${sanitizedFuncName}_fn);\n\n`
  })

  return { functionsCode, functionDeclarations, functionRegistrations }
}

// Generate module initialization
function generateModuleInit(functionRegistrations) {
  let moduleInit = `
// Initialize module
napi_value Init(napi_env env, napi_value exports) {
    napi_value enumValue;
`

  // Register enums
  raylibJson.enums.forEach((enumDef) => {
    const sanitizedEnumName = sanitizeTypeName(enumDef.name)
    moduleInit += `    // Register ${enumDef.name} enum\n`
    moduleInit += `    enumValue = Create_${sanitizedEnumName}(env);\n`
    moduleInit += `    napi_set_named_property(env, exports, "${enumDef.name}", enumValue);\n\n`
  })

  // Register functions
  moduleInit += functionRegistrations
  moduleInit += '    return exports;\n}\n\n'
  moduleInit += 'NAPI_MODULE(NODE_GYP_MODULE_NAME, Init)'

  return moduleInit
}

// After generating the code, find and fix void_from_js references
const { functionsCode: origFunctionsCode, functionDeclarations, functionRegistrations } = generateFunctions()

// Fix all problematic code patterns
let functionsCode = origFunctionsCode
  // Fix the problematic patterns with void_from_js
  .replace(/void ptr_value = void_from_js\(env, args\[\d+\]\);(\s+)void \* ptr = &ptr_value;/g,
      'void* ptr = void_ptr_from_js(env, args[0]);')
  .replace(/void srcPtr_value = void_from_js\(env, args\[\d+\]\);(\s+)void \* srcPtr = &srcPtr_value;/g,
      'void* srcPtr = void_ptr_from_js(env, args[0]);')
  .replace(/void dstPtr_value = void_from_js\(env, args\[\d+\]\);(\s+)void \* dstPtr = &dstPtr_value;/g,
      'void* dstPtr = void_ptr_from_js(env, args[0]);')
  .replace(/void data_value = void_from_js\(env, args\[\d+\]\);(\s+)void \* data = &data_value;/g,
      'void* data = void_ptr_from_js(env, args[1]);');

bindingsSource += functionDeclarations + '\n'
bindingsSource += generateEnums()
bindingsSource += generateStructs()
bindingsSource += functionsCode
bindingsSource += generateModuleInit(functionRegistrations)

// Write the generated code to file
await writeFile(path.join(fileURLToPath(import.meta.url), '..', '..', 'src', 'node-raylib.c'), bindingsSource)
console.log('Raylib N-API bindings generated successfully!')
