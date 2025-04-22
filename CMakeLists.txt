cmake_minimum_required(VERSION 3.15)
project(node-raylib)

include_directories(${CMAKE_JS_INC})

include(FetchContent)
FetchContent_Declare(
    raylib
    URL https://github.com/raysan5/raylib/archive/refs/tags/5.5.zip
)
FetchContent_MakeAvailable(raylib)

execute_process(COMMAND node -p "require('node-addon-api').include" OUTPUT_VARIABLE NODE_ADDON_API_DIR OUTPUT_STRIP_TRAILING_WHITESPACE)
include_directories(${NODE_ADDON_API_DIR})

add_library(${PROJECT_NAME} SHARED src/node-raylib.c ${CMAKE_JS_SRC})
set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "" SUFFIX ".node")
target_link_libraries(${PROJECT_NAME} ${CMAKE_JS_LIB} raylib)
set_property(TARGET ${PROJECT_NAME} PROPERTY C_STANDARD 11)
target_compile_definitions(${PROJECT_NAME} PRIVATE NAPI_VERSION=4)
