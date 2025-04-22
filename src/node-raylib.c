#include <node_api.h>
#include <raylib.h>
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
Vector2 Vector2_from_js(napi_env env, napi_value jsObj);
napi_value Vector2_to_js(napi_env env, Vector2 data);
Vector3 Vector3_from_js(napi_env env, napi_value jsObj);
napi_value Vector3_to_js(napi_env env, Vector3 data);
Vector4 Vector4_from_js(napi_env env, napi_value jsObj);
napi_value Vector4_to_js(napi_env env, Vector4 data);
Matrix Matrix_from_js(napi_env env, napi_value jsObj);
napi_value Matrix_to_js(napi_env env, Matrix data);
Color Color_from_js(napi_env env, napi_value jsObj);
napi_value Color_to_js(napi_env env, Color data);
Rectangle Rectangle_from_js(napi_env env, napi_value jsObj);
napi_value Rectangle_to_js(napi_env env, Rectangle data);
Image Image_from_js(napi_env env, napi_value jsObj);
napi_value Image_to_js(napi_env env, Image data);
Texture Texture_from_js(napi_env env, napi_value jsObj);
napi_value Texture_to_js(napi_env env, Texture data);
RenderTexture RenderTexture_from_js(napi_env env, napi_value jsObj);
napi_value RenderTexture_to_js(napi_env env, RenderTexture data);
NPatchInfo NPatchInfo_from_js(napi_env env, napi_value jsObj);
napi_value NPatchInfo_to_js(napi_env env, NPatchInfo data);
GlyphInfo GlyphInfo_from_js(napi_env env, napi_value jsObj);
napi_value GlyphInfo_to_js(napi_env env, GlyphInfo data);
Font Font_from_js(napi_env env, napi_value jsObj);
napi_value Font_to_js(napi_env env, Font data);
Camera3D Camera3D_from_js(napi_env env, napi_value jsObj);
napi_value Camera3D_to_js(napi_env env, Camera3D data);
Camera2D Camera2D_from_js(napi_env env, napi_value jsObj);
napi_value Camera2D_to_js(napi_env env, Camera2D data);
Mesh Mesh_from_js(napi_env env, napi_value jsObj);
napi_value Mesh_to_js(napi_env env, Mesh data);
Shader Shader_from_js(napi_env env, napi_value jsObj);
napi_value Shader_to_js(napi_env env, Shader data);
MaterialMap MaterialMap_from_js(napi_env env, napi_value jsObj);
napi_value MaterialMap_to_js(napi_env env, MaterialMap data);
Material Material_from_js(napi_env env, napi_value jsObj);
napi_value Material_to_js(napi_env env, Material data);
Transform Transform_from_js(napi_env env, napi_value jsObj);
napi_value Transform_to_js(napi_env env, Transform data);
BoneInfo BoneInfo_from_js(napi_env env, napi_value jsObj);
napi_value BoneInfo_to_js(napi_env env, BoneInfo data);
Model Model_from_js(napi_env env, napi_value jsObj);
napi_value Model_to_js(napi_env env, Model data);
ModelAnimation ModelAnimation_from_js(napi_env env, napi_value jsObj);
napi_value ModelAnimation_to_js(napi_env env, ModelAnimation data);
Ray Ray_from_js(napi_env env, napi_value jsObj);
napi_value Ray_to_js(napi_env env, Ray data);
RayCollision RayCollision_from_js(napi_env env, napi_value jsObj);
napi_value RayCollision_to_js(napi_env env, RayCollision data);
BoundingBox BoundingBox_from_js(napi_env env, napi_value jsObj);
napi_value BoundingBox_to_js(napi_env env, BoundingBox data);
Wave Wave_from_js(napi_env env, napi_value jsObj);
napi_value Wave_to_js(napi_env env, Wave data);
AudioStream AudioStream_from_js(napi_env env, napi_value jsObj);
napi_value AudioStream_to_js(napi_env env, AudioStream data);
Sound Sound_from_js(napi_env env, napi_value jsObj);
napi_value Sound_to_js(napi_env env, Sound data);
Music Music_from_js(napi_env env, napi_value jsObj);
napi_value Music_to_js(napi_env env, Music data);
VrDeviceInfo VrDeviceInfo_from_js(napi_env env, napi_value jsObj);
napi_value VrDeviceInfo_to_js(napi_env env, VrDeviceInfo data);
VrStereoConfig VrStereoConfig_from_js(napi_env env, napi_value jsObj);
napi_value VrStereoConfig_to_js(napi_env env, VrStereoConfig data);
FilePathList FilePathList_from_js(napi_env env, napi_value jsObj);
napi_value FilePathList_to_js(napi_env env, FilePathList data);
AutomationEvent AutomationEvent_from_js(napi_env env, napi_value jsObj);
napi_value AutomationEvent_to_js(napi_env env, AutomationEvent data);
AutomationEventList AutomationEventList_from_js(napi_env env, napi_value jsObj);
napi_value AutomationEventList_to_js(napi_env env, AutomationEventList data);
RenderTexture2D RenderTexture2D_from_js(napi_env env, napi_value jsObj);
napi_value RenderTexture2D_to_js(napi_env env, RenderTexture2D data);
Texture2D Texture2D_from_js(napi_env env, napi_value jsObj);
napi_value Texture2D_to_js(napi_env env, Texture2D data);
Camera Camera_from_js(napi_env env, napi_value jsObj);
napi_value Camera_to_js(napi_env env, Camera data);
int int_from_js(napi_env env, napi_value jsObj);
napi_value int_to_js(napi_env env, int data);
TraceLogCallback TraceLogCallback_from_js(napi_env env, napi_value jsObj);
napi_value TraceLogCallback_to_js(napi_env env, TraceLogCallback data);
LoadFileDataCallback LoadFileDataCallback_from_js(napi_env env, napi_value jsObj);
napi_value LoadFileDataCallback_to_js(napi_env env, LoadFileDataCallback data);
SaveFileDataCallback SaveFileDataCallback_from_js(napi_env env, napi_value jsObj);
napi_value SaveFileDataCallback_to_js(napi_env env, SaveFileDataCallback data);
LoadFileTextCallback LoadFileTextCallback_from_js(napi_env env, napi_value jsObj);
napi_value LoadFileTextCallback_to_js(napi_env env, LoadFileTextCallback data);
SaveFileTextCallback SaveFileTextCallback_from_js(napi_env env, napi_value jsObj);
napi_value SaveFileTextCallback_to_js(napi_env env, SaveFileTextCallback data);
unsigned char unsigned_char_from_js(napi_env env, napi_value jsObj);
napi_value unsigned_char_to_js(napi_env env, unsigned char data);
float float_from_js(napi_env env, napi_value jsObj);
napi_value float_to_js(napi_env env, float data);
TextureCubemap TextureCubemap_from_js(napi_env env, napi_value jsObj);
napi_value TextureCubemap_to_js(napi_env env, TextureCubemap data);
Rectangle * Rectangle___from_js(napi_env env, napi_value jsObj);
napi_value Rectangle___to_js(napi_env env, Rectangle * data);
AudioCallback AudioCallback_from_js(napi_env env, napi_value jsObj);
napi_value AudioCallback_to_js(napi_env env, AudioCallback data);

// Forward declarations for functions
// Special handler for void* type
void* void_ptr_from_js(napi_env env, napi_value jsObj) {
    // This is a placeholder that returns NULL
    // In real implementation, you might want to handle Buffer objects
    return NULL;
}

napi_value void_ptr_to_js(napi_env env, void* data) {
    // This is a placeholder that returns null
    napi_value result;
    napi_get_null(env, &result);
    return result;
}

// Special handler for functions needing void* returns
typedef void* void_ptr;
void_ptr void_from_js(napi_env env, napi_value jsObj) {
    return void_ptr_from_js(env, jsObj);
}

napi_value BindNode_InitWindow(napi_env env, napi_callback_info info);
napi_value BindNode_CloseWindow(napi_env env, napi_callback_info info);
napi_value BindNode_WindowShouldClose(napi_env env, napi_callback_info info);
napi_value BindNode_IsWindowReady(napi_env env, napi_callback_info info);
napi_value BindNode_IsWindowFullscreen(napi_env env, napi_callback_info info);
napi_value BindNode_IsWindowHidden(napi_env env, napi_callback_info info);
napi_value BindNode_IsWindowMinimized(napi_env env, napi_callback_info info);
napi_value BindNode_IsWindowMaximized(napi_env env, napi_callback_info info);
napi_value BindNode_IsWindowFocused(napi_env env, napi_callback_info info);
napi_value BindNode_IsWindowResized(napi_env env, napi_callback_info info);
napi_value BindNode_IsWindowState(napi_env env, napi_callback_info info);
napi_value BindNode_SetWindowState(napi_env env, napi_callback_info info);
napi_value BindNode_ClearWindowState(napi_env env, napi_callback_info info);
napi_value BindNode_ToggleFullscreen(napi_env env, napi_callback_info info);
napi_value BindNode_ToggleBorderlessWindowed(napi_env env, napi_callback_info info);
napi_value BindNode_MaximizeWindow(napi_env env, napi_callback_info info);
napi_value BindNode_MinimizeWindow(napi_env env, napi_callback_info info);
napi_value BindNode_RestoreWindow(napi_env env, napi_callback_info info);
napi_value BindNode_SetWindowIcon(napi_env env, napi_callback_info info);
napi_value BindNode_SetWindowIcons(napi_env env, napi_callback_info info);
napi_value BindNode_SetWindowTitle(napi_env env, napi_callback_info info);
napi_value BindNode_SetWindowPosition(napi_env env, napi_callback_info info);
napi_value BindNode_SetWindowMonitor(napi_env env, napi_callback_info info);
napi_value BindNode_SetWindowMinSize(napi_env env, napi_callback_info info);
napi_value BindNode_SetWindowMaxSize(napi_env env, napi_callback_info info);
napi_value BindNode_SetWindowSize(napi_env env, napi_callback_info info);
napi_value BindNode_SetWindowOpacity(napi_env env, napi_callback_info info);
napi_value BindNode_SetWindowFocused(napi_env env, napi_callback_info info);
napi_value BindNode_GetWindowHandle(napi_env env, napi_callback_info info);
napi_value BindNode_GetScreenWidth(napi_env env, napi_callback_info info);
napi_value BindNode_GetScreenHeight(napi_env env, napi_callback_info info);
napi_value BindNode_GetRenderWidth(napi_env env, napi_callback_info info);
napi_value BindNode_GetRenderHeight(napi_env env, napi_callback_info info);
napi_value BindNode_GetMonitorCount(napi_env env, napi_callback_info info);
napi_value BindNode_GetCurrentMonitor(napi_env env, napi_callback_info info);
napi_value BindNode_GetMonitorPosition(napi_env env, napi_callback_info info);
napi_value BindNode_GetMonitorWidth(napi_env env, napi_callback_info info);
napi_value BindNode_GetMonitorHeight(napi_env env, napi_callback_info info);
napi_value BindNode_GetMonitorPhysicalWidth(napi_env env, napi_callback_info info);
napi_value BindNode_GetMonitorPhysicalHeight(napi_env env, napi_callback_info info);
napi_value BindNode_GetMonitorRefreshRate(napi_env env, napi_callback_info info);
napi_value BindNode_GetWindowPosition(napi_env env, napi_callback_info info);
napi_value BindNode_GetWindowScaleDPI(napi_env env, napi_callback_info info);
napi_value BindNode_GetMonitorName(napi_env env, napi_callback_info info);
napi_value BindNode_SetClipboardText(napi_env env, napi_callback_info info);
napi_value BindNode_GetClipboardText(napi_env env, napi_callback_info info);
napi_value BindNode_GetClipboardImage(napi_env env, napi_callback_info info);
napi_value BindNode_EnableEventWaiting(napi_env env, napi_callback_info info);
napi_value BindNode_DisableEventWaiting(napi_env env, napi_callback_info info);
napi_value BindNode_ShowCursor(napi_env env, napi_callback_info info);
napi_value BindNode_HideCursor(napi_env env, napi_callback_info info);
napi_value BindNode_IsCursorHidden(napi_env env, napi_callback_info info);
napi_value BindNode_EnableCursor(napi_env env, napi_callback_info info);
napi_value BindNode_DisableCursor(napi_env env, napi_callback_info info);
napi_value BindNode_IsCursorOnScreen(napi_env env, napi_callback_info info);
napi_value BindNode_ClearBackground(napi_env env, napi_callback_info info);
napi_value BindNode_BeginDrawing(napi_env env, napi_callback_info info);
napi_value BindNode_EndDrawing(napi_env env, napi_callback_info info);
napi_value BindNode_BeginMode2D(napi_env env, napi_callback_info info);
napi_value BindNode_EndMode2D(napi_env env, napi_callback_info info);
napi_value BindNode_BeginMode3D(napi_env env, napi_callback_info info);
napi_value BindNode_EndMode3D(napi_env env, napi_callback_info info);
napi_value BindNode_BeginTextureMode(napi_env env, napi_callback_info info);
napi_value BindNode_EndTextureMode(napi_env env, napi_callback_info info);
napi_value BindNode_BeginShaderMode(napi_env env, napi_callback_info info);
napi_value BindNode_EndShaderMode(napi_env env, napi_callback_info info);
napi_value BindNode_BeginBlendMode(napi_env env, napi_callback_info info);
napi_value BindNode_EndBlendMode(napi_env env, napi_callback_info info);
napi_value BindNode_BeginScissorMode(napi_env env, napi_callback_info info);
napi_value BindNode_EndScissorMode(napi_env env, napi_callback_info info);
napi_value BindNode_BeginVrStereoMode(napi_env env, napi_callback_info info);
napi_value BindNode_EndVrStereoMode(napi_env env, napi_callback_info info);
napi_value BindNode_LoadVrStereoConfig(napi_env env, napi_callback_info info);
napi_value BindNode_UnloadVrStereoConfig(napi_env env, napi_callback_info info);
napi_value BindNode_LoadShader(napi_env env, napi_callback_info info);
napi_value BindNode_LoadShaderFromMemory(napi_env env, napi_callback_info info);
napi_value BindNode_IsShaderValid(napi_env env, napi_callback_info info);
napi_value BindNode_GetShaderLocation(napi_env env, napi_callback_info info);
napi_value BindNode_GetShaderLocationAttrib(napi_env env, napi_callback_info info);
napi_value BindNode_SetShaderValue(napi_env env, napi_callback_info info);
napi_value BindNode_SetShaderValueV(napi_env env, napi_callback_info info);
napi_value BindNode_SetShaderValueMatrix(napi_env env, napi_callback_info info);
napi_value BindNode_SetShaderValueTexture(napi_env env, napi_callback_info info);
napi_value BindNode_UnloadShader(napi_env env, napi_callback_info info);
napi_value BindNode_GetScreenToWorldRay(napi_env env, napi_callback_info info);
napi_value BindNode_GetScreenToWorldRayEx(napi_env env, napi_callback_info info);
napi_value BindNode_GetWorldToScreen(napi_env env, napi_callback_info info);
napi_value BindNode_GetWorldToScreenEx(napi_env env, napi_callback_info info);
napi_value BindNode_GetWorldToScreen2D(napi_env env, napi_callback_info info);
napi_value BindNode_GetScreenToWorld2D(napi_env env, napi_callback_info info);
napi_value BindNode_GetCameraMatrix(napi_env env, napi_callback_info info);
napi_value BindNode_GetCameraMatrix2D(napi_env env, napi_callback_info info);
napi_value BindNode_SetTargetFPS(napi_env env, napi_callback_info info);
napi_value BindNode_GetFrameTime(napi_env env, napi_callback_info info);
napi_value BindNode_GetTime(napi_env env, napi_callback_info info);
napi_value BindNode_GetFPS(napi_env env, napi_callback_info info);
napi_value BindNode_SwapScreenBuffer(napi_env env, napi_callback_info info);
napi_value BindNode_PollInputEvents(napi_env env, napi_callback_info info);
napi_value BindNode_WaitTime(napi_env env, napi_callback_info info);
napi_value BindNode_SetRandomSeed(napi_env env, napi_callback_info info);
napi_value BindNode_GetRandomValue(napi_env env, napi_callback_info info);
napi_value BindNode_LoadRandomSequence(napi_env env, napi_callback_info info);
napi_value BindNode_UnloadRandomSequence(napi_env env, napi_callback_info info);
napi_value BindNode_TakeScreenshot(napi_env env, napi_callback_info info);
napi_value BindNode_SetConfigFlags(napi_env env, napi_callback_info info);
napi_value BindNode_OpenURL(napi_env env, napi_callback_info info);
napi_value BindNode_TraceLog(napi_env env, napi_callback_info info);
napi_value BindNode_SetTraceLogLevel(napi_env env, napi_callback_info info);
napi_value BindNode_MemAlloc(napi_env env, napi_callback_info info);
napi_value BindNode_MemRealloc(napi_env env, napi_callback_info info);
napi_value BindNode_MemFree(napi_env env, napi_callback_info info);
napi_value BindNode_SetTraceLogCallback(napi_env env, napi_callback_info info);
napi_value BindNode_SetLoadFileDataCallback(napi_env env, napi_callback_info info);
napi_value BindNode_SetSaveFileDataCallback(napi_env env, napi_callback_info info);
napi_value BindNode_SetLoadFileTextCallback(napi_env env, napi_callback_info info);
napi_value BindNode_SetSaveFileTextCallback(napi_env env, napi_callback_info info);
napi_value BindNode_LoadFileData(napi_env env, napi_callback_info info);
napi_value BindNode_UnloadFileData(napi_env env, napi_callback_info info);
napi_value BindNode_SaveFileData(napi_env env, napi_callback_info info);
napi_value BindNode_ExportDataAsCode(napi_env env, napi_callback_info info);
napi_value BindNode_LoadFileText(napi_env env, napi_callback_info info);
napi_value BindNode_UnloadFileText(napi_env env, napi_callback_info info);
napi_value BindNode_SaveFileText(napi_env env, napi_callback_info info);
napi_value BindNode_FileExists(napi_env env, napi_callback_info info);
napi_value BindNode_DirectoryExists(napi_env env, napi_callback_info info);
napi_value BindNode_IsFileExtension(napi_env env, napi_callback_info info);
napi_value BindNode_GetFileLength(napi_env env, napi_callback_info info);
napi_value BindNode_GetFileExtension(napi_env env, napi_callback_info info);
napi_value BindNode_GetFileName(napi_env env, napi_callback_info info);
napi_value BindNode_GetFileNameWithoutExt(napi_env env, napi_callback_info info);
napi_value BindNode_GetDirectoryPath(napi_env env, napi_callback_info info);
napi_value BindNode_GetPrevDirectoryPath(napi_env env, napi_callback_info info);
napi_value BindNode_GetWorkingDirectory(napi_env env, napi_callback_info info);
napi_value BindNode_GetApplicationDirectory(napi_env env, napi_callback_info info);
napi_value BindNode_MakeDirectory(napi_env env, napi_callback_info info);
napi_value BindNode_ChangeDirectory(napi_env env, napi_callback_info info);
napi_value BindNode_IsPathFile(napi_env env, napi_callback_info info);
napi_value BindNode_IsFileNameValid(napi_env env, napi_callback_info info);
napi_value BindNode_LoadDirectoryFiles(napi_env env, napi_callback_info info);
napi_value BindNode_LoadDirectoryFilesEx(napi_env env, napi_callback_info info);
napi_value BindNode_UnloadDirectoryFiles(napi_env env, napi_callback_info info);
napi_value BindNode_IsFileDropped(napi_env env, napi_callback_info info);
napi_value BindNode_LoadDroppedFiles(napi_env env, napi_callback_info info);
napi_value BindNode_UnloadDroppedFiles(napi_env env, napi_callback_info info);
napi_value BindNode_GetFileModTime(napi_env env, napi_callback_info info);
napi_value BindNode_CompressData(napi_env env, napi_callback_info info);
napi_value BindNode_DecompressData(napi_env env, napi_callback_info info);
napi_value BindNode_EncodeDataBase64(napi_env env, napi_callback_info info);
napi_value BindNode_DecodeDataBase64(napi_env env, napi_callback_info info);
napi_value BindNode_ComputeCRC32(napi_env env, napi_callback_info info);
napi_value BindNode_ComputeMD5(napi_env env, napi_callback_info info);
napi_value BindNode_ComputeSHA1(napi_env env, napi_callback_info info);
napi_value BindNode_LoadAutomationEventList(napi_env env, napi_callback_info info);
napi_value BindNode_UnloadAutomationEventList(napi_env env, napi_callback_info info);
napi_value BindNode_ExportAutomationEventList(napi_env env, napi_callback_info info);
napi_value BindNode_SetAutomationEventList(napi_env env, napi_callback_info info);
napi_value BindNode_SetAutomationEventBaseFrame(napi_env env, napi_callback_info info);
napi_value BindNode_StartAutomationEventRecording(napi_env env, napi_callback_info info);
napi_value BindNode_StopAutomationEventRecording(napi_env env, napi_callback_info info);
napi_value BindNode_PlayAutomationEvent(napi_env env, napi_callback_info info);
napi_value BindNode_IsKeyPressed(napi_env env, napi_callback_info info);
napi_value BindNode_IsKeyPressedRepeat(napi_env env, napi_callback_info info);
napi_value BindNode_IsKeyDown(napi_env env, napi_callback_info info);
napi_value BindNode_IsKeyReleased(napi_env env, napi_callback_info info);
napi_value BindNode_IsKeyUp(napi_env env, napi_callback_info info);
napi_value BindNode_GetKeyPressed(napi_env env, napi_callback_info info);
napi_value BindNode_GetCharPressed(napi_env env, napi_callback_info info);
napi_value BindNode_SetExitKey(napi_env env, napi_callback_info info);
napi_value BindNode_IsGamepadAvailable(napi_env env, napi_callback_info info);
napi_value BindNode_GetGamepadName(napi_env env, napi_callback_info info);
napi_value BindNode_IsGamepadButtonPressed(napi_env env, napi_callback_info info);
napi_value BindNode_IsGamepadButtonDown(napi_env env, napi_callback_info info);
napi_value BindNode_IsGamepadButtonReleased(napi_env env, napi_callback_info info);
napi_value BindNode_IsGamepadButtonUp(napi_env env, napi_callback_info info);
napi_value BindNode_GetGamepadButtonPressed(napi_env env, napi_callback_info info);
napi_value BindNode_GetGamepadAxisCount(napi_env env, napi_callback_info info);
napi_value BindNode_GetGamepadAxisMovement(napi_env env, napi_callback_info info);
napi_value BindNode_SetGamepadMappings(napi_env env, napi_callback_info info);
napi_value BindNode_SetGamepadVibration(napi_env env, napi_callback_info info);
napi_value BindNode_IsMouseButtonPressed(napi_env env, napi_callback_info info);
napi_value BindNode_IsMouseButtonDown(napi_env env, napi_callback_info info);
napi_value BindNode_IsMouseButtonReleased(napi_env env, napi_callback_info info);
napi_value BindNode_IsMouseButtonUp(napi_env env, napi_callback_info info);
napi_value BindNode_GetMouseX(napi_env env, napi_callback_info info);
napi_value BindNode_GetMouseY(napi_env env, napi_callback_info info);
napi_value BindNode_GetMousePosition(napi_env env, napi_callback_info info);
napi_value BindNode_GetMouseDelta(napi_env env, napi_callback_info info);
napi_value BindNode_SetMousePosition(napi_env env, napi_callback_info info);
napi_value BindNode_SetMouseOffset(napi_env env, napi_callback_info info);
napi_value BindNode_SetMouseScale(napi_env env, napi_callback_info info);
napi_value BindNode_GetMouseWheelMove(napi_env env, napi_callback_info info);
napi_value BindNode_GetMouseWheelMoveV(napi_env env, napi_callback_info info);
napi_value BindNode_SetMouseCursor(napi_env env, napi_callback_info info);
napi_value BindNode_GetTouchX(napi_env env, napi_callback_info info);
napi_value BindNode_GetTouchY(napi_env env, napi_callback_info info);
napi_value BindNode_GetTouchPosition(napi_env env, napi_callback_info info);
napi_value BindNode_GetTouchPointId(napi_env env, napi_callback_info info);
napi_value BindNode_GetTouchPointCount(napi_env env, napi_callback_info info);
napi_value BindNode_SetGesturesEnabled(napi_env env, napi_callback_info info);
napi_value BindNode_IsGestureDetected(napi_env env, napi_callback_info info);
napi_value BindNode_GetGestureDetected(napi_env env, napi_callback_info info);
napi_value BindNode_GetGestureHoldDuration(napi_env env, napi_callback_info info);
napi_value BindNode_GetGestureDragVector(napi_env env, napi_callback_info info);
napi_value BindNode_GetGestureDragAngle(napi_env env, napi_callback_info info);
napi_value BindNode_GetGesturePinchVector(napi_env env, napi_callback_info info);
napi_value BindNode_GetGesturePinchAngle(napi_env env, napi_callback_info info);
napi_value BindNode_UpdateCamera(napi_env env, napi_callback_info info);
napi_value BindNode_UpdateCameraPro(napi_env env, napi_callback_info info);
napi_value BindNode_SetShapesTexture(napi_env env, napi_callback_info info);
napi_value BindNode_GetShapesTexture(napi_env env, napi_callback_info info);
napi_value BindNode_GetShapesTextureRectangle(napi_env env, napi_callback_info info);
napi_value BindNode_DrawPixel(napi_env env, napi_callback_info info);
napi_value BindNode_DrawPixelV(napi_env env, napi_callback_info info);
napi_value BindNode_DrawLine(napi_env env, napi_callback_info info);
napi_value BindNode_DrawLineV(napi_env env, napi_callback_info info);
napi_value BindNode_DrawLineEx(napi_env env, napi_callback_info info);
napi_value BindNode_DrawLineStrip(napi_env env, napi_callback_info info);
napi_value BindNode_DrawLineBezier(napi_env env, napi_callback_info info);
napi_value BindNode_DrawCircle(napi_env env, napi_callback_info info);
napi_value BindNode_DrawCircleSector(napi_env env, napi_callback_info info);
napi_value BindNode_DrawCircleSectorLines(napi_env env, napi_callback_info info);
napi_value BindNode_DrawCircleGradient(napi_env env, napi_callback_info info);
napi_value BindNode_DrawCircleV(napi_env env, napi_callback_info info);
napi_value BindNode_DrawCircleLines(napi_env env, napi_callback_info info);
napi_value BindNode_DrawCircleLinesV(napi_env env, napi_callback_info info);
napi_value BindNode_DrawEllipse(napi_env env, napi_callback_info info);
napi_value BindNode_DrawEllipseLines(napi_env env, napi_callback_info info);
napi_value BindNode_DrawRing(napi_env env, napi_callback_info info);
napi_value BindNode_DrawRingLines(napi_env env, napi_callback_info info);
napi_value BindNode_DrawRectangle(napi_env env, napi_callback_info info);
napi_value BindNode_DrawRectangleV(napi_env env, napi_callback_info info);
napi_value BindNode_DrawRectangleRec(napi_env env, napi_callback_info info);
napi_value BindNode_DrawRectanglePro(napi_env env, napi_callback_info info);
napi_value BindNode_DrawRectangleGradientV(napi_env env, napi_callback_info info);
napi_value BindNode_DrawRectangleGradientH(napi_env env, napi_callback_info info);
napi_value BindNode_DrawRectangleGradientEx(napi_env env, napi_callback_info info);
napi_value BindNode_DrawRectangleLines(napi_env env, napi_callback_info info);
napi_value BindNode_DrawRectangleLinesEx(napi_env env, napi_callback_info info);
napi_value BindNode_DrawRectangleRounded(napi_env env, napi_callback_info info);
napi_value BindNode_DrawRectangleRoundedLines(napi_env env, napi_callback_info info);
napi_value BindNode_DrawRectangleRoundedLinesEx(napi_env env, napi_callback_info info);
napi_value BindNode_DrawTriangle(napi_env env, napi_callback_info info);
napi_value BindNode_DrawTriangleLines(napi_env env, napi_callback_info info);
napi_value BindNode_DrawTriangleFan(napi_env env, napi_callback_info info);
napi_value BindNode_DrawTriangleStrip(napi_env env, napi_callback_info info);
napi_value BindNode_DrawPoly(napi_env env, napi_callback_info info);
napi_value BindNode_DrawPolyLines(napi_env env, napi_callback_info info);
napi_value BindNode_DrawPolyLinesEx(napi_env env, napi_callback_info info);
napi_value BindNode_DrawSplineLinear(napi_env env, napi_callback_info info);
napi_value BindNode_DrawSplineBasis(napi_env env, napi_callback_info info);
napi_value BindNode_DrawSplineCatmullRom(napi_env env, napi_callback_info info);
napi_value BindNode_DrawSplineBezierQuadratic(napi_env env, napi_callback_info info);
napi_value BindNode_DrawSplineBezierCubic(napi_env env, napi_callback_info info);
napi_value BindNode_DrawSplineSegmentLinear(napi_env env, napi_callback_info info);
napi_value BindNode_DrawSplineSegmentBasis(napi_env env, napi_callback_info info);
napi_value BindNode_DrawSplineSegmentCatmullRom(napi_env env, napi_callback_info info);
napi_value BindNode_DrawSplineSegmentBezierQuadratic(napi_env env, napi_callback_info info);
napi_value BindNode_DrawSplineSegmentBezierCubic(napi_env env, napi_callback_info info);
napi_value BindNode_GetSplinePointLinear(napi_env env, napi_callback_info info);
napi_value BindNode_GetSplinePointBasis(napi_env env, napi_callback_info info);
napi_value BindNode_GetSplinePointCatmullRom(napi_env env, napi_callback_info info);
napi_value BindNode_GetSplinePointBezierQuad(napi_env env, napi_callback_info info);
napi_value BindNode_GetSplinePointBezierCubic(napi_env env, napi_callback_info info);
napi_value BindNode_CheckCollisionRecs(napi_env env, napi_callback_info info);
napi_value BindNode_CheckCollisionCircles(napi_env env, napi_callback_info info);
napi_value BindNode_CheckCollisionCircleRec(napi_env env, napi_callback_info info);
napi_value BindNode_CheckCollisionCircleLine(napi_env env, napi_callback_info info);
napi_value BindNode_CheckCollisionPointRec(napi_env env, napi_callback_info info);
napi_value BindNode_CheckCollisionPointCircle(napi_env env, napi_callback_info info);
napi_value BindNode_CheckCollisionPointTriangle(napi_env env, napi_callback_info info);
napi_value BindNode_CheckCollisionPointLine(napi_env env, napi_callback_info info);
napi_value BindNode_CheckCollisionPointPoly(napi_env env, napi_callback_info info);
napi_value BindNode_CheckCollisionLines(napi_env env, napi_callback_info info);
napi_value BindNode_GetCollisionRec(napi_env env, napi_callback_info info);
napi_value BindNode_LoadImage(napi_env env, napi_callback_info info);
napi_value BindNode_LoadImageRaw(napi_env env, napi_callback_info info);
napi_value BindNode_LoadImageAnim(napi_env env, napi_callback_info info);
napi_value BindNode_LoadImageAnimFromMemory(napi_env env, napi_callback_info info);
napi_value BindNode_LoadImageFromMemory(napi_env env, napi_callback_info info);
napi_value BindNode_LoadImageFromTexture(napi_env env, napi_callback_info info);
napi_value BindNode_LoadImageFromScreen(napi_env env, napi_callback_info info);
napi_value BindNode_IsImageValid(napi_env env, napi_callback_info info);
napi_value BindNode_UnloadImage(napi_env env, napi_callback_info info);
napi_value BindNode_ExportImage(napi_env env, napi_callback_info info);
napi_value BindNode_ExportImageToMemory(napi_env env, napi_callback_info info);
napi_value BindNode_ExportImageAsCode(napi_env env, napi_callback_info info);
napi_value BindNode_GenImageColor(napi_env env, napi_callback_info info);
napi_value BindNode_GenImageGradientLinear(napi_env env, napi_callback_info info);
napi_value BindNode_GenImageGradientRadial(napi_env env, napi_callback_info info);
napi_value BindNode_GenImageGradientSquare(napi_env env, napi_callback_info info);
napi_value BindNode_GenImageChecked(napi_env env, napi_callback_info info);
napi_value BindNode_GenImageWhiteNoise(napi_env env, napi_callback_info info);
napi_value BindNode_GenImagePerlinNoise(napi_env env, napi_callback_info info);
napi_value BindNode_GenImageCellular(napi_env env, napi_callback_info info);
napi_value BindNode_GenImageText(napi_env env, napi_callback_info info);
napi_value BindNode_ImageCopy(napi_env env, napi_callback_info info);
napi_value BindNode_ImageFromImage(napi_env env, napi_callback_info info);
napi_value BindNode_ImageFromChannel(napi_env env, napi_callback_info info);
napi_value BindNode_ImageText(napi_env env, napi_callback_info info);
napi_value BindNode_ImageTextEx(napi_env env, napi_callback_info info);
napi_value BindNode_ImageFormat(napi_env env, napi_callback_info info);
napi_value BindNode_ImageToPOT(napi_env env, napi_callback_info info);
napi_value BindNode_ImageCrop(napi_env env, napi_callback_info info);
napi_value BindNode_ImageAlphaCrop(napi_env env, napi_callback_info info);
napi_value BindNode_ImageAlphaClear(napi_env env, napi_callback_info info);
napi_value BindNode_ImageAlphaMask(napi_env env, napi_callback_info info);
napi_value BindNode_ImageAlphaPremultiply(napi_env env, napi_callback_info info);
napi_value BindNode_ImageBlurGaussian(napi_env env, napi_callback_info info);
napi_value BindNode_ImageKernelConvolution(napi_env env, napi_callback_info info);
napi_value BindNode_ImageResize(napi_env env, napi_callback_info info);
napi_value BindNode_ImageResizeNN(napi_env env, napi_callback_info info);
napi_value BindNode_ImageResizeCanvas(napi_env env, napi_callback_info info);
napi_value BindNode_ImageMipmaps(napi_env env, napi_callback_info info);
napi_value BindNode_ImageDither(napi_env env, napi_callback_info info);
napi_value BindNode_ImageFlipVertical(napi_env env, napi_callback_info info);
napi_value BindNode_ImageFlipHorizontal(napi_env env, napi_callback_info info);
napi_value BindNode_ImageRotate(napi_env env, napi_callback_info info);
napi_value BindNode_ImageRotateCW(napi_env env, napi_callback_info info);
napi_value BindNode_ImageRotateCCW(napi_env env, napi_callback_info info);
napi_value BindNode_ImageColorTint(napi_env env, napi_callback_info info);
napi_value BindNode_ImageColorInvert(napi_env env, napi_callback_info info);
napi_value BindNode_ImageColorGrayscale(napi_env env, napi_callback_info info);
napi_value BindNode_ImageColorContrast(napi_env env, napi_callback_info info);
napi_value BindNode_ImageColorBrightness(napi_env env, napi_callback_info info);
napi_value BindNode_ImageColorReplace(napi_env env, napi_callback_info info);
napi_value BindNode_LoadImageColors(napi_env env, napi_callback_info info);
napi_value BindNode_LoadImagePalette(napi_env env, napi_callback_info info);
napi_value BindNode_UnloadImageColors(napi_env env, napi_callback_info info);
napi_value BindNode_UnloadImagePalette(napi_env env, napi_callback_info info);
napi_value BindNode_GetImageAlphaBorder(napi_env env, napi_callback_info info);
napi_value BindNode_GetImageColor(napi_env env, napi_callback_info info);
napi_value BindNode_ImageClearBackground(napi_env env, napi_callback_info info);
napi_value BindNode_ImageDrawPixel(napi_env env, napi_callback_info info);
napi_value BindNode_ImageDrawPixelV(napi_env env, napi_callback_info info);
napi_value BindNode_ImageDrawLine(napi_env env, napi_callback_info info);
napi_value BindNode_ImageDrawLineV(napi_env env, napi_callback_info info);
napi_value BindNode_ImageDrawLineEx(napi_env env, napi_callback_info info);
napi_value BindNode_ImageDrawCircle(napi_env env, napi_callback_info info);
napi_value BindNode_ImageDrawCircleV(napi_env env, napi_callback_info info);
napi_value BindNode_ImageDrawCircleLines(napi_env env, napi_callback_info info);
napi_value BindNode_ImageDrawCircleLinesV(napi_env env, napi_callback_info info);
napi_value BindNode_ImageDrawRectangle(napi_env env, napi_callback_info info);
napi_value BindNode_ImageDrawRectangleV(napi_env env, napi_callback_info info);
napi_value BindNode_ImageDrawRectangleRec(napi_env env, napi_callback_info info);
napi_value BindNode_ImageDrawRectangleLines(napi_env env, napi_callback_info info);
napi_value BindNode_ImageDrawTriangle(napi_env env, napi_callback_info info);
napi_value BindNode_ImageDrawTriangleEx(napi_env env, napi_callback_info info);
napi_value BindNode_ImageDrawTriangleLines(napi_env env, napi_callback_info info);
napi_value BindNode_ImageDrawTriangleFan(napi_env env, napi_callback_info info);
napi_value BindNode_ImageDrawTriangleStrip(napi_env env, napi_callback_info info);
napi_value BindNode_ImageDraw(napi_env env, napi_callback_info info);
napi_value BindNode_ImageDrawText(napi_env env, napi_callback_info info);
napi_value BindNode_ImageDrawTextEx(napi_env env, napi_callback_info info);
napi_value BindNode_LoadTexture(napi_env env, napi_callback_info info);
napi_value BindNode_LoadTextureFromImage(napi_env env, napi_callback_info info);
napi_value BindNode_LoadTextureCubemap(napi_env env, napi_callback_info info);
napi_value BindNode_LoadRenderTexture(napi_env env, napi_callback_info info);
napi_value BindNode_IsTextureValid(napi_env env, napi_callback_info info);
napi_value BindNode_UnloadTexture(napi_env env, napi_callback_info info);
napi_value BindNode_IsRenderTextureValid(napi_env env, napi_callback_info info);
napi_value BindNode_UnloadRenderTexture(napi_env env, napi_callback_info info);
napi_value BindNode_UpdateTexture(napi_env env, napi_callback_info info);
napi_value BindNode_UpdateTextureRec(napi_env env, napi_callback_info info);
napi_value BindNode_GenTextureMipmaps(napi_env env, napi_callback_info info);
napi_value BindNode_SetTextureFilter(napi_env env, napi_callback_info info);
napi_value BindNode_SetTextureWrap(napi_env env, napi_callback_info info);
napi_value BindNode_DrawTexture(napi_env env, napi_callback_info info);
napi_value BindNode_DrawTextureV(napi_env env, napi_callback_info info);
napi_value BindNode_DrawTextureEx(napi_env env, napi_callback_info info);
napi_value BindNode_DrawTextureRec(napi_env env, napi_callback_info info);
napi_value BindNode_DrawTexturePro(napi_env env, napi_callback_info info);
napi_value BindNode_DrawTextureNPatch(napi_env env, napi_callback_info info);
napi_value BindNode_ColorIsEqual(napi_env env, napi_callback_info info);
napi_value BindNode_Fade(napi_env env, napi_callback_info info);
napi_value BindNode_ColorToInt(napi_env env, napi_callback_info info);
napi_value BindNode_ColorNormalize(napi_env env, napi_callback_info info);
napi_value BindNode_ColorFromNormalized(napi_env env, napi_callback_info info);
napi_value BindNode_ColorToHSV(napi_env env, napi_callback_info info);
napi_value BindNode_ColorFromHSV(napi_env env, napi_callback_info info);
napi_value BindNode_ColorTint(napi_env env, napi_callback_info info);
napi_value BindNode_ColorBrightness(napi_env env, napi_callback_info info);
napi_value BindNode_ColorContrast(napi_env env, napi_callback_info info);
napi_value BindNode_ColorAlpha(napi_env env, napi_callback_info info);
napi_value BindNode_ColorAlphaBlend(napi_env env, napi_callback_info info);
napi_value BindNode_ColorLerp(napi_env env, napi_callback_info info);
napi_value BindNode_GetColor(napi_env env, napi_callback_info info);
napi_value BindNode_GetPixelColor(napi_env env, napi_callback_info info);
napi_value BindNode_SetPixelColor(napi_env env, napi_callback_info info);
napi_value BindNode_GetPixelDataSize(napi_env env, napi_callback_info info);
napi_value BindNode_GetFontDefault(napi_env env, napi_callback_info info);
napi_value BindNode_LoadFont(napi_env env, napi_callback_info info);
napi_value BindNode_LoadFontEx(napi_env env, napi_callback_info info);
napi_value BindNode_LoadFontFromImage(napi_env env, napi_callback_info info);
napi_value BindNode_LoadFontFromMemory(napi_env env, napi_callback_info info);
napi_value BindNode_IsFontValid(napi_env env, napi_callback_info info);
napi_value BindNode_LoadFontData(napi_env env, napi_callback_info info);
napi_value BindNode_GenImageFontAtlas(napi_env env, napi_callback_info info);
napi_value BindNode_UnloadFontData(napi_env env, napi_callback_info info);
napi_value BindNode_UnloadFont(napi_env env, napi_callback_info info);
napi_value BindNode_ExportFontAsCode(napi_env env, napi_callback_info info);
napi_value BindNode_DrawFPS(napi_env env, napi_callback_info info);
napi_value BindNode_DrawText(napi_env env, napi_callback_info info);
napi_value BindNode_DrawTextEx(napi_env env, napi_callback_info info);
napi_value BindNode_DrawTextPro(napi_env env, napi_callback_info info);
napi_value BindNode_DrawTextCodepoint(napi_env env, napi_callback_info info);
napi_value BindNode_DrawTextCodepoints(napi_env env, napi_callback_info info);
napi_value BindNode_SetTextLineSpacing(napi_env env, napi_callback_info info);
napi_value BindNode_MeasureText(napi_env env, napi_callback_info info);
napi_value BindNode_MeasureTextEx(napi_env env, napi_callback_info info);
napi_value BindNode_GetGlyphIndex(napi_env env, napi_callback_info info);
napi_value BindNode_GetGlyphInfo(napi_env env, napi_callback_info info);
napi_value BindNode_GetGlyphAtlasRec(napi_env env, napi_callback_info info);
napi_value BindNode_LoadUTF8(napi_env env, napi_callback_info info);
napi_value BindNode_UnloadUTF8(napi_env env, napi_callback_info info);
napi_value BindNode_LoadCodepoints(napi_env env, napi_callback_info info);
napi_value BindNode_UnloadCodepoints(napi_env env, napi_callback_info info);
napi_value BindNode_GetCodepointCount(napi_env env, napi_callback_info info);
napi_value BindNode_GetCodepoint(napi_env env, napi_callback_info info);
napi_value BindNode_GetCodepointNext(napi_env env, napi_callback_info info);
napi_value BindNode_GetCodepointPrevious(napi_env env, napi_callback_info info);
napi_value BindNode_CodepointToUTF8(napi_env env, napi_callback_info info);
napi_value BindNode_TextCopy(napi_env env, napi_callback_info info);
napi_value BindNode_TextIsEqual(napi_env env, napi_callback_info info);
napi_value BindNode_TextLength(napi_env env, napi_callback_info info);
napi_value BindNode_TextFormat(napi_env env, napi_callback_info info);
napi_value BindNode_TextSubtext(napi_env env, napi_callback_info info);
napi_value BindNode_TextReplace(napi_env env, napi_callback_info info);
napi_value BindNode_TextInsert(napi_env env, napi_callback_info info);
napi_value BindNode_TextJoin(napi_env env, napi_callback_info info);
napi_value BindNode_TextSplit(napi_env env, napi_callback_info info);
napi_value BindNode_TextAppend(napi_env env, napi_callback_info info);
napi_value BindNode_TextFindIndex(napi_env env, napi_callback_info info);
napi_value BindNode_TextToUpper(napi_env env, napi_callback_info info);
napi_value BindNode_TextToLower(napi_env env, napi_callback_info info);
napi_value BindNode_TextToPascal(napi_env env, napi_callback_info info);
napi_value BindNode_TextToSnake(napi_env env, napi_callback_info info);
napi_value BindNode_TextToCamel(napi_env env, napi_callback_info info);
napi_value BindNode_TextToInteger(napi_env env, napi_callback_info info);
napi_value BindNode_TextToFloat(napi_env env, napi_callback_info info);
napi_value BindNode_DrawLine3D(napi_env env, napi_callback_info info);
napi_value BindNode_DrawPoint3D(napi_env env, napi_callback_info info);
napi_value BindNode_DrawCircle3D(napi_env env, napi_callback_info info);
napi_value BindNode_DrawTriangle3D(napi_env env, napi_callback_info info);
napi_value BindNode_DrawTriangleStrip3D(napi_env env, napi_callback_info info);
napi_value BindNode_DrawCube(napi_env env, napi_callback_info info);
napi_value BindNode_DrawCubeV(napi_env env, napi_callback_info info);
napi_value BindNode_DrawCubeWires(napi_env env, napi_callback_info info);
napi_value BindNode_DrawCubeWiresV(napi_env env, napi_callback_info info);
napi_value BindNode_DrawSphere(napi_env env, napi_callback_info info);
napi_value BindNode_DrawSphereEx(napi_env env, napi_callback_info info);
napi_value BindNode_DrawSphereWires(napi_env env, napi_callback_info info);
napi_value BindNode_DrawCylinder(napi_env env, napi_callback_info info);
napi_value BindNode_DrawCylinderEx(napi_env env, napi_callback_info info);
napi_value BindNode_DrawCylinderWires(napi_env env, napi_callback_info info);
napi_value BindNode_DrawCylinderWiresEx(napi_env env, napi_callback_info info);
napi_value BindNode_DrawCapsule(napi_env env, napi_callback_info info);
napi_value BindNode_DrawCapsuleWires(napi_env env, napi_callback_info info);
napi_value BindNode_DrawPlane(napi_env env, napi_callback_info info);
napi_value BindNode_DrawRay(napi_env env, napi_callback_info info);
napi_value BindNode_DrawGrid(napi_env env, napi_callback_info info);
napi_value BindNode_LoadModel(napi_env env, napi_callback_info info);
napi_value BindNode_LoadModelFromMesh(napi_env env, napi_callback_info info);
napi_value BindNode_IsModelValid(napi_env env, napi_callback_info info);
napi_value BindNode_UnloadModel(napi_env env, napi_callback_info info);
napi_value BindNode_GetModelBoundingBox(napi_env env, napi_callback_info info);
napi_value BindNode_DrawModel(napi_env env, napi_callback_info info);
napi_value BindNode_DrawModelEx(napi_env env, napi_callback_info info);
napi_value BindNode_DrawModelWires(napi_env env, napi_callback_info info);
napi_value BindNode_DrawModelWiresEx(napi_env env, napi_callback_info info);
napi_value BindNode_DrawModelPoints(napi_env env, napi_callback_info info);
napi_value BindNode_DrawModelPointsEx(napi_env env, napi_callback_info info);
napi_value BindNode_DrawBoundingBox(napi_env env, napi_callback_info info);
napi_value BindNode_DrawBillboard(napi_env env, napi_callback_info info);
napi_value BindNode_DrawBillboardRec(napi_env env, napi_callback_info info);
napi_value BindNode_DrawBillboardPro(napi_env env, napi_callback_info info);
napi_value BindNode_UploadMesh(napi_env env, napi_callback_info info);
napi_value BindNode_UpdateMeshBuffer(napi_env env, napi_callback_info info);
napi_value BindNode_UnloadMesh(napi_env env, napi_callback_info info);
napi_value BindNode_DrawMesh(napi_env env, napi_callback_info info);
napi_value BindNode_DrawMeshInstanced(napi_env env, napi_callback_info info);
napi_value BindNode_GetMeshBoundingBox(napi_env env, napi_callback_info info);
napi_value BindNode_GenMeshTangents(napi_env env, napi_callback_info info);
napi_value BindNode_ExportMesh(napi_env env, napi_callback_info info);
napi_value BindNode_ExportMeshAsCode(napi_env env, napi_callback_info info);
napi_value BindNode_GenMeshPoly(napi_env env, napi_callback_info info);
napi_value BindNode_GenMeshPlane(napi_env env, napi_callback_info info);
napi_value BindNode_GenMeshCube(napi_env env, napi_callback_info info);
napi_value BindNode_GenMeshSphere(napi_env env, napi_callback_info info);
napi_value BindNode_GenMeshHemiSphere(napi_env env, napi_callback_info info);
napi_value BindNode_GenMeshCylinder(napi_env env, napi_callback_info info);
napi_value BindNode_GenMeshCone(napi_env env, napi_callback_info info);
napi_value BindNode_GenMeshTorus(napi_env env, napi_callback_info info);
napi_value BindNode_GenMeshKnot(napi_env env, napi_callback_info info);
napi_value BindNode_GenMeshHeightmap(napi_env env, napi_callback_info info);
napi_value BindNode_GenMeshCubicmap(napi_env env, napi_callback_info info);
napi_value BindNode_LoadMaterials(napi_env env, napi_callback_info info);
napi_value BindNode_LoadMaterialDefault(napi_env env, napi_callback_info info);
napi_value BindNode_IsMaterialValid(napi_env env, napi_callback_info info);
napi_value BindNode_UnloadMaterial(napi_env env, napi_callback_info info);
napi_value BindNode_SetMaterialTexture(napi_env env, napi_callback_info info);
napi_value BindNode_SetModelMeshMaterial(napi_env env, napi_callback_info info);
napi_value BindNode_LoadModelAnimations(napi_env env, napi_callback_info info);
napi_value BindNode_UpdateModelAnimation(napi_env env, napi_callback_info info);
napi_value BindNode_UpdateModelAnimationBones(napi_env env, napi_callback_info info);
napi_value BindNode_UnloadModelAnimation(napi_env env, napi_callback_info info);
napi_value BindNode_UnloadModelAnimations(napi_env env, napi_callback_info info);
napi_value BindNode_IsModelAnimationValid(napi_env env, napi_callback_info info);
napi_value BindNode_CheckCollisionSpheres(napi_env env, napi_callback_info info);
napi_value BindNode_CheckCollisionBoxes(napi_env env, napi_callback_info info);
napi_value BindNode_CheckCollisionBoxSphere(napi_env env, napi_callback_info info);
napi_value BindNode_GetRayCollisionSphere(napi_env env, napi_callback_info info);
napi_value BindNode_GetRayCollisionBox(napi_env env, napi_callback_info info);
napi_value BindNode_GetRayCollisionMesh(napi_env env, napi_callback_info info);
napi_value BindNode_GetRayCollisionTriangle(napi_env env, napi_callback_info info);
napi_value BindNode_GetRayCollisionQuad(napi_env env, napi_callback_info info);
napi_value BindNode_InitAudioDevice(napi_env env, napi_callback_info info);
napi_value BindNode_CloseAudioDevice(napi_env env, napi_callback_info info);
napi_value BindNode_IsAudioDeviceReady(napi_env env, napi_callback_info info);
napi_value BindNode_SetMasterVolume(napi_env env, napi_callback_info info);
napi_value BindNode_GetMasterVolume(napi_env env, napi_callback_info info);
napi_value BindNode_LoadWave(napi_env env, napi_callback_info info);
napi_value BindNode_LoadWaveFromMemory(napi_env env, napi_callback_info info);
napi_value BindNode_IsWaveValid(napi_env env, napi_callback_info info);
napi_value BindNode_LoadSound(napi_env env, napi_callback_info info);
napi_value BindNode_LoadSoundFromWave(napi_env env, napi_callback_info info);
napi_value BindNode_LoadSoundAlias(napi_env env, napi_callback_info info);
napi_value BindNode_IsSoundValid(napi_env env, napi_callback_info info);
napi_value BindNode_UpdateSound(napi_env env, napi_callback_info info);
napi_value BindNode_UnloadWave(napi_env env, napi_callback_info info);
napi_value BindNode_UnloadSound(napi_env env, napi_callback_info info);
napi_value BindNode_UnloadSoundAlias(napi_env env, napi_callback_info info);
napi_value BindNode_ExportWave(napi_env env, napi_callback_info info);
napi_value BindNode_ExportWaveAsCode(napi_env env, napi_callback_info info);
napi_value BindNode_PlaySound(napi_env env, napi_callback_info info);
napi_value BindNode_StopSound(napi_env env, napi_callback_info info);
napi_value BindNode_PauseSound(napi_env env, napi_callback_info info);
napi_value BindNode_ResumeSound(napi_env env, napi_callback_info info);
napi_value BindNode_IsSoundPlaying(napi_env env, napi_callback_info info);
napi_value BindNode_SetSoundVolume(napi_env env, napi_callback_info info);
napi_value BindNode_SetSoundPitch(napi_env env, napi_callback_info info);
napi_value BindNode_SetSoundPan(napi_env env, napi_callback_info info);
napi_value BindNode_WaveCopy(napi_env env, napi_callback_info info);
napi_value BindNode_WaveCrop(napi_env env, napi_callback_info info);
napi_value BindNode_WaveFormat(napi_env env, napi_callback_info info);
napi_value BindNode_LoadWaveSamples(napi_env env, napi_callback_info info);
napi_value BindNode_UnloadWaveSamples(napi_env env, napi_callback_info info);
napi_value BindNode_LoadMusicStream(napi_env env, napi_callback_info info);
napi_value BindNode_LoadMusicStreamFromMemory(napi_env env, napi_callback_info info);
napi_value BindNode_IsMusicValid(napi_env env, napi_callback_info info);
napi_value BindNode_UnloadMusicStream(napi_env env, napi_callback_info info);
napi_value BindNode_PlayMusicStream(napi_env env, napi_callback_info info);
napi_value BindNode_IsMusicStreamPlaying(napi_env env, napi_callback_info info);
napi_value BindNode_UpdateMusicStream(napi_env env, napi_callback_info info);
napi_value BindNode_StopMusicStream(napi_env env, napi_callback_info info);
napi_value BindNode_PauseMusicStream(napi_env env, napi_callback_info info);
napi_value BindNode_ResumeMusicStream(napi_env env, napi_callback_info info);
napi_value BindNode_SeekMusicStream(napi_env env, napi_callback_info info);
napi_value BindNode_SetMusicVolume(napi_env env, napi_callback_info info);
napi_value BindNode_SetMusicPitch(napi_env env, napi_callback_info info);
napi_value BindNode_SetMusicPan(napi_env env, napi_callback_info info);
napi_value BindNode_GetMusicTimeLength(napi_env env, napi_callback_info info);
napi_value BindNode_GetMusicTimePlayed(napi_env env, napi_callback_info info);
napi_value BindNode_LoadAudioStream(napi_env env, napi_callback_info info);
napi_value BindNode_IsAudioStreamValid(napi_env env, napi_callback_info info);
napi_value BindNode_UnloadAudioStream(napi_env env, napi_callback_info info);
napi_value BindNode_UpdateAudioStream(napi_env env, napi_callback_info info);
napi_value BindNode_IsAudioStreamProcessed(napi_env env, napi_callback_info info);
napi_value BindNode_PlayAudioStream(napi_env env, napi_callback_info info);
napi_value BindNode_PauseAudioStream(napi_env env, napi_callback_info info);
napi_value BindNode_ResumeAudioStream(napi_env env, napi_callback_info info);
napi_value BindNode_IsAudioStreamPlaying(napi_env env, napi_callback_info info);
napi_value BindNode_StopAudioStream(napi_env env, napi_callback_info info);
napi_value BindNode_SetAudioStreamVolume(napi_env env, napi_callback_info info);
napi_value BindNode_SetAudioStreamPitch(napi_env env, napi_callback_info info);
napi_value BindNode_SetAudioStreamPan(napi_env env, napi_callback_info info);
napi_value BindNode_SetAudioStreamBufferSizeDefault(napi_env env, napi_callback_info info);
napi_value BindNode_SetAudioStreamCallback(napi_env env, napi_callback_info info);
napi_value BindNode_AttachAudioStreamProcessor(napi_env env, napi_callback_info info);
napi_value BindNode_DetachAudioStreamProcessor(napi_env env, napi_callback_info info);
napi_value BindNode_AttachAudioMixedProcessor(napi_env env, napi_callback_info info);
napi_value BindNode_DetachAudioMixedProcessor(napi_env env, napi_callback_info info);

// Enum definitions
napi_value Create_ConfigFlags(napi_env env) {
    napi_value enumObj;
    napi_create_object(env, &enumObj);

    // Set to try enabling V-Sync on GPU
    napi_value FLAG_VSYNC_HINT_val;
    napi_create_int32(env, 64, &FLAG_VSYNC_HINT_val);
    napi_set_named_property(env, enumObj, "FLAG_VSYNC_HINT", FLAG_VSYNC_HINT_val);

    // Set to run program in fullscreen
    napi_value FLAG_FULLSCREEN_MODE_val;
    napi_create_int32(env, 2, &FLAG_FULLSCREEN_MODE_val);
    napi_set_named_property(env, enumObj, "FLAG_FULLSCREEN_MODE", FLAG_FULLSCREEN_MODE_val);

    // Set to allow resizable window
    napi_value FLAG_WINDOW_RESIZABLE_val;
    napi_create_int32(env, 4, &FLAG_WINDOW_RESIZABLE_val);
    napi_set_named_property(env, enumObj, "FLAG_WINDOW_RESIZABLE", FLAG_WINDOW_RESIZABLE_val);

    // Set to disable window decoration (frame and buttons)
    napi_value FLAG_WINDOW_UNDECORATED_val;
    napi_create_int32(env, 8, &FLAG_WINDOW_UNDECORATED_val);
    napi_set_named_property(env, enumObj, "FLAG_WINDOW_UNDECORATED", FLAG_WINDOW_UNDECORATED_val);

    // Set to hide window
    napi_value FLAG_WINDOW_HIDDEN_val;
    napi_create_int32(env, 128, &FLAG_WINDOW_HIDDEN_val);
    napi_set_named_property(env, enumObj, "FLAG_WINDOW_HIDDEN", FLAG_WINDOW_HIDDEN_val);

    // Set to minimize window (iconify)
    napi_value FLAG_WINDOW_MINIMIZED_val;
    napi_create_int32(env, 512, &FLAG_WINDOW_MINIMIZED_val);
    napi_set_named_property(env, enumObj, "FLAG_WINDOW_MINIMIZED", FLAG_WINDOW_MINIMIZED_val);

    // Set to maximize window (expanded to monitor)
    napi_value FLAG_WINDOW_MAXIMIZED_val;
    napi_create_int32(env, 1024, &FLAG_WINDOW_MAXIMIZED_val);
    napi_set_named_property(env, enumObj, "FLAG_WINDOW_MAXIMIZED", FLAG_WINDOW_MAXIMIZED_val);

    // Set to window non focused
    napi_value FLAG_WINDOW_UNFOCUSED_val;
    napi_create_int32(env, 2048, &FLAG_WINDOW_UNFOCUSED_val);
    napi_set_named_property(env, enumObj, "FLAG_WINDOW_UNFOCUSED", FLAG_WINDOW_UNFOCUSED_val);

    // Set to window always on top
    napi_value FLAG_WINDOW_TOPMOST_val;
    napi_create_int32(env, 4096, &FLAG_WINDOW_TOPMOST_val);
    napi_set_named_property(env, enumObj, "FLAG_WINDOW_TOPMOST", FLAG_WINDOW_TOPMOST_val);

    // Set to allow windows running while minimized
    napi_value FLAG_WINDOW_ALWAYS_RUN_val;
    napi_create_int32(env, 256, &FLAG_WINDOW_ALWAYS_RUN_val);
    napi_set_named_property(env, enumObj, "FLAG_WINDOW_ALWAYS_RUN", FLAG_WINDOW_ALWAYS_RUN_val);

    // Set to allow transparent framebuffer
    napi_value FLAG_WINDOW_TRANSPARENT_val;
    napi_create_int32(env, 16, &FLAG_WINDOW_TRANSPARENT_val);
    napi_set_named_property(env, enumObj, "FLAG_WINDOW_TRANSPARENT", FLAG_WINDOW_TRANSPARENT_val);

    // Set to support HighDPI
    napi_value FLAG_WINDOW_HIGHDPI_val;
    napi_create_int32(env, 8192, &FLAG_WINDOW_HIGHDPI_val);
    napi_set_named_property(env, enumObj, "FLAG_WINDOW_HIGHDPI", FLAG_WINDOW_HIGHDPI_val);

    // Set to support mouse passthrough, only supported when FLAG_WINDOW_UNDECORATED
    napi_value FLAG_WINDOW_MOUSE_PASSTHROUGH_val;
    napi_create_int32(env, 16384, &FLAG_WINDOW_MOUSE_PASSTHROUGH_val);
    napi_set_named_property(env, enumObj, "FLAG_WINDOW_MOUSE_PASSTHROUGH", FLAG_WINDOW_MOUSE_PASSTHROUGH_val);

    // Set to run program in borderless windowed mode
    napi_value FLAG_BORDERLESS_WINDOWED_MODE_val;
    napi_create_int32(env, 32768, &FLAG_BORDERLESS_WINDOWED_MODE_val);
    napi_set_named_property(env, enumObj, "FLAG_BORDERLESS_WINDOWED_MODE", FLAG_BORDERLESS_WINDOWED_MODE_val);

    // Set to try enabling MSAA 4X
    napi_value FLAG_MSAA_4X_HINT_val;
    napi_create_int32(env, 32, &FLAG_MSAA_4X_HINT_val);
    napi_set_named_property(env, enumObj, "FLAG_MSAA_4X_HINT", FLAG_MSAA_4X_HINT_val);

    // Set to try enabling interlaced video format (for V3D)
    napi_value FLAG_INTERLACED_HINT_val;
    napi_create_int32(env, 65536, &FLAG_INTERLACED_HINT_val);
    napi_set_named_property(env, enumObj, "FLAG_INTERLACED_HINT", FLAG_INTERLACED_HINT_val);

    return enumObj;
}

napi_value Create_TraceLogLevel(napi_env env) {
    napi_value enumObj;
    napi_create_object(env, &enumObj);

    // Display all logs
    napi_value LOG_ALL_val;
    napi_create_int32(env, 0, &LOG_ALL_val);
    napi_set_named_property(env, enumObj, "LOG_ALL", LOG_ALL_val);

    // Trace logging, intended for internal use only
    napi_value LOG_TRACE_val;
    napi_create_int32(env, 1, &LOG_TRACE_val);
    napi_set_named_property(env, enumObj, "LOG_TRACE", LOG_TRACE_val);

    // Debug logging, used for internal debugging, it should be disabled on release builds
    napi_value LOG_DEBUG_val;
    napi_create_int32(env, 2, &LOG_DEBUG_val);
    napi_set_named_property(env, enumObj, "LOG_DEBUG", LOG_DEBUG_val);

    // Info logging, used for program execution info
    napi_value LOG_INFO_val;
    napi_create_int32(env, 3, &LOG_INFO_val);
    napi_set_named_property(env, enumObj, "LOG_INFO", LOG_INFO_val);

    // Warning logging, used on recoverable failures
    napi_value LOG_WARNING_val;
    napi_create_int32(env, 4, &LOG_WARNING_val);
    napi_set_named_property(env, enumObj, "LOG_WARNING", LOG_WARNING_val);

    // Error logging, used on unrecoverable failures
    napi_value LOG_ERROR_val;
    napi_create_int32(env, 5, &LOG_ERROR_val);
    napi_set_named_property(env, enumObj, "LOG_ERROR", LOG_ERROR_val);

    // Fatal logging, used to abort program: exit(EXIT_FAILURE)
    napi_value LOG_FATAL_val;
    napi_create_int32(env, 6, &LOG_FATAL_val);
    napi_set_named_property(env, enumObj, "LOG_FATAL", LOG_FATAL_val);

    // Disable logging
    napi_value LOG_NONE_val;
    napi_create_int32(env, 7, &LOG_NONE_val);
    napi_set_named_property(env, enumObj, "LOG_NONE", LOG_NONE_val);

    return enumObj;
}

napi_value Create_KeyboardKey(napi_env env) {
    napi_value enumObj;
    napi_create_object(env, &enumObj);

    // Key: NULL, used for no key pressed
    napi_value KEY_NULL_val;
    napi_create_int32(env, 0, &KEY_NULL_val);
    napi_set_named_property(env, enumObj, "KEY_NULL", KEY_NULL_val);

    // Key: '
    napi_value KEY_APOSTROPHE_val;
    napi_create_int32(env, 39, &KEY_APOSTROPHE_val);
    napi_set_named_property(env, enumObj, "KEY_APOSTROPHE", KEY_APOSTROPHE_val);

    // Key: ,
    napi_value KEY_COMMA_val;
    napi_create_int32(env, 44, &KEY_COMMA_val);
    napi_set_named_property(env, enumObj, "KEY_COMMA", KEY_COMMA_val);

    // Key: -
    napi_value KEY_MINUS_val;
    napi_create_int32(env, 45, &KEY_MINUS_val);
    napi_set_named_property(env, enumObj, "KEY_MINUS", KEY_MINUS_val);

    // Key: .
    napi_value KEY_PERIOD_val;
    napi_create_int32(env, 46, &KEY_PERIOD_val);
    napi_set_named_property(env, enumObj, "KEY_PERIOD", KEY_PERIOD_val);

    // Key: /
    napi_value KEY_SLASH_val;
    napi_create_int32(env, 47, &KEY_SLASH_val);
    napi_set_named_property(env, enumObj, "KEY_SLASH", KEY_SLASH_val);

    // Key: 0
    napi_value KEY_ZERO_val;
    napi_create_int32(env, 48, &KEY_ZERO_val);
    napi_set_named_property(env, enumObj, "KEY_ZERO", KEY_ZERO_val);

    // Key: 1
    napi_value KEY_ONE_val;
    napi_create_int32(env, 49, &KEY_ONE_val);
    napi_set_named_property(env, enumObj, "KEY_ONE", KEY_ONE_val);

    // Key: 2
    napi_value KEY_TWO_val;
    napi_create_int32(env, 50, &KEY_TWO_val);
    napi_set_named_property(env, enumObj, "KEY_TWO", KEY_TWO_val);

    // Key: 3
    napi_value KEY_THREE_val;
    napi_create_int32(env, 51, &KEY_THREE_val);
    napi_set_named_property(env, enumObj, "KEY_THREE", KEY_THREE_val);

    // Key: 4
    napi_value KEY_FOUR_val;
    napi_create_int32(env, 52, &KEY_FOUR_val);
    napi_set_named_property(env, enumObj, "KEY_FOUR", KEY_FOUR_val);

    // Key: 5
    napi_value KEY_FIVE_val;
    napi_create_int32(env, 53, &KEY_FIVE_val);
    napi_set_named_property(env, enumObj, "KEY_FIVE", KEY_FIVE_val);

    // Key: 6
    napi_value KEY_SIX_val;
    napi_create_int32(env, 54, &KEY_SIX_val);
    napi_set_named_property(env, enumObj, "KEY_SIX", KEY_SIX_val);

    // Key: 7
    napi_value KEY_SEVEN_val;
    napi_create_int32(env, 55, &KEY_SEVEN_val);
    napi_set_named_property(env, enumObj, "KEY_SEVEN", KEY_SEVEN_val);

    // Key: 8
    napi_value KEY_EIGHT_val;
    napi_create_int32(env, 56, &KEY_EIGHT_val);
    napi_set_named_property(env, enumObj, "KEY_EIGHT", KEY_EIGHT_val);

    // Key: 9
    napi_value KEY_NINE_val;
    napi_create_int32(env, 57, &KEY_NINE_val);
    napi_set_named_property(env, enumObj, "KEY_NINE", KEY_NINE_val);

    // Key: ;
    napi_value KEY_SEMICOLON_val;
    napi_create_int32(env, 59, &KEY_SEMICOLON_val);
    napi_set_named_property(env, enumObj, "KEY_SEMICOLON", KEY_SEMICOLON_val);

    // Key: =
    napi_value KEY_EQUAL_val;
    napi_create_int32(env, 61, &KEY_EQUAL_val);
    napi_set_named_property(env, enumObj, "KEY_EQUAL", KEY_EQUAL_val);

    // Key: A | a
    napi_value KEY_A_val;
    napi_create_int32(env, 65, &KEY_A_val);
    napi_set_named_property(env, enumObj, "KEY_A", KEY_A_val);

    // Key: B | b
    napi_value KEY_B_val;
    napi_create_int32(env, 66, &KEY_B_val);
    napi_set_named_property(env, enumObj, "KEY_B", KEY_B_val);

    // Key: C | c
    napi_value KEY_C_val;
    napi_create_int32(env, 67, &KEY_C_val);
    napi_set_named_property(env, enumObj, "KEY_C", KEY_C_val);

    // Key: D | d
    napi_value KEY_D_val;
    napi_create_int32(env, 68, &KEY_D_val);
    napi_set_named_property(env, enumObj, "KEY_D", KEY_D_val);

    // Key: E | e
    napi_value KEY_E_val;
    napi_create_int32(env, 69, &KEY_E_val);
    napi_set_named_property(env, enumObj, "KEY_E", KEY_E_val);

    // Key: F | f
    napi_value KEY_F_val;
    napi_create_int32(env, 70, &KEY_F_val);
    napi_set_named_property(env, enumObj, "KEY_F", KEY_F_val);

    // Key: G | g
    napi_value KEY_G_val;
    napi_create_int32(env, 71, &KEY_G_val);
    napi_set_named_property(env, enumObj, "KEY_G", KEY_G_val);

    // Key: H | h
    napi_value KEY_H_val;
    napi_create_int32(env, 72, &KEY_H_val);
    napi_set_named_property(env, enumObj, "KEY_H", KEY_H_val);

    // Key: I | i
    napi_value KEY_I_val;
    napi_create_int32(env, 73, &KEY_I_val);
    napi_set_named_property(env, enumObj, "KEY_I", KEY_I_val);

    // Key: J | j
    napi_value KEY_J_val;
    napi_create_int32(env, 74, &KEY_J_val);
    napi_set_named_property(env, enumObj, "KEY_J", KEY_J_val);

    // Key: K | k
    napi_value KEY_K_val;
    napi_create_int32(env, 75, &KEY_K_val);
    napi_set_named_property(env, enumObj, "KEY_K", KEY_K_val);

    // Key: L | l
    napi_value KEY_L_val;
    napi_create_int32(env, 76, &KEY_L_val);
    napi_set_named_property(env, enumObj, "KEY_L", KEY_L_val);

    // Key: M | m
    napi_value KEY_M_val;
    napi_create_int32(env, 77, &KEY_M_val);
    napi_set_named_property(env, enumObj, "KEY_M", KEY_M_val);

    // Key: N | n
    napi_value KEY_N_val;
    napi_create_int32(env, 78, &KEY_N_val);
    napi_set_named_property(env, enumObj, "KEY_N", KEY_N_val);

    // Key: O | o
    napi_value KEY_O_val;
    napi_create_int32(env, 79, &KEY_O_val);
    napi_set_named_property(env, enumObj, "KEY_O", KEY_O_val);

    // Key: P | p
    napi_value KEY_P_val;
    napi_create_int32(env, 80, &KEY_P_val);
    napi_set_named_property(env, enumObj, "KEY_P", KEY_P_val);

    // Key: Q | q
    napi_value KEY_Q_val;
    napi_create_int32(env, 81, &KEY_Q_val);
    napi_set_named_property(env, enumObj, "KEY_Q", KEY_Q_val);

    // Key: R | r
    napi_value KEY_R_val;
    napi_create_int32(env, 82, &KEY_R_val);
    napi_set_named_property(env, enumObj, "KEY_R", KEY_R_val);

    // Key: S | s
    napi_value KEY_S_val;
    napi_create_int32(env, 83, &KEY_S_val);
    napi_set_named_property(env, enumObj, "KEY_S", KEY_S_val);

    // Key: T | t
    napi_value KEY_T_val;
    napi_create_int32(env, 84, &KEY_T_val);
    napi_set_named_property(env, enumObj, "KEY_T", KEY_T_val);

    // Key: U | u
    napi_value KEY_U_val;
    napi_create_int32(env, 85, &KEY_U_val);
    napi_set_named_property(env, enumObj, "KEY_U", KEY_U_val);

    // Key: V | v
    napi_value KEY_V_val;
    napi_create_int32(env, 86, &KEY_V_val);
    napi_set_named_property(env, enumObj, "KEY_V", KEY_V_val);

    // Key: W | w
    napi_value KEY_W_val;
    napi_create_int32(env, 87, &KEY_W_val);
    napi_set_named_property(env, enumObj, "KEY_W", KEY_W_val);

    // Key: X | x
    napi_value KEY_X_val;
    napi_create_int32(env, 88, &KEY_X_val);
    napi_set_named_property(env, enumObj, "KEY_X", KEY_X_val);

    // Key: Y | y
    napi_value KEY_Y_val;
    napi_create_int32(env, 89, &KEY_Y_val);
    napi_set_named_property(env, enumObj, "KEY_Y", KEY_Y_val);

    // Key: Z | z
    napi_value KEY_Z_val;
    napi_create_int32(env, 90, &KEY_Z_val);
    napi_set_named_property(env, enumObj, "KEY_Z", KEY_Z_val);

    // Key: [
    napi_value KEY_LEFT_BRACKET_val;
    napi_create_int32(env, 91, &KEY_LEFT_BRACKET_val);
    napi_set_named_property(env, enumObj, "KEY_LEFT_BRACKET", KEY_LEFT_BRACKET_val);

    // Key: '\'
    napi_value KEY_BACKSLASH_val;
    napi_create_int32(env, 92, &KEY_BACKSLASH_val);
    napi_set_named_property(env, enumObj, "KEY_BACKSLASH", KEY_BACKSLASH_val);

    // Key: ]
    napi_value KEY_RIGHT_BRACKET_val;
    napi_create_int32(env, 93, &KEY_RIGHT_BRACKET_val);
    napi_set_named_property(env, enumObj, "KEY_RIGHT_BRACKET", KEY_RIGHT_BRACKET_val);

    // Key: `
    napi_value KEY_GRAVE_val;
    napi_create_int32(env, 96, &KEY_GRAVE_val);
    napi_set_named_property(env, enumObj, "KEY_GRAVE", KEY_GRAVE_val);

    // Key: Space
    napi_value KEY_SPACE_val;
    napi_create_int32(env, 32, &KEY_SPACE_val);
    napi_set_named_property(env, enumObj, "KEY_SPACE", KEY_SPACE_val);

    // Key: Esc
    napi_value KEY_ESCAPE_val;
    napi_create_int32(env, 256, &KEY_ESCAPE_val);
    napi_set_named_property(env, enumObj, "KEY_ESCAPE", KEY_ESCAPE_val);

    // Key: Enter
    napi_value KEY_ENTER_val;
    napi_create_int32(env, 257, &KEY_ENTER_val);
    napi_set_named_property(env, enumObj, "KEY_ENTER", KEY_ENTER_val);

    // Key: Tab
    napi_value KEY_TAB_val;
    napi_create_int32(env, 258, &KEY_TAB_val);
    napi_set_named_property(env, enumObj, "KEY_TAB", KEY_TAB_val);

    // Key: Backspace
    napi_value KEY_BACKSPACE_val;
    napi_create_int32(env, 259, &KEY_BACKSPACE_val);
    napi_set_named_property(env, enumObj, "KEY_BACKSPACE", KEY_BACKSPACE_val);

    // Key: Ins
    napi_value KEY_INSERT_val;
    napi_create_int32(env, 260, &KEY_INSERT_val);
    napi_set_named_property(env, enumObj, "KEY_INSERT", KEY_INSERT_val);

    // Key: Del
    napi_value KEY_DELETE_val;
    napi_create_int32(env, 261, &KEY_DELETE_val);
    napi_set_named_property(env, enumObj, "KEY_DELETE", KEY_DELETE_val);

    // Key: Cursor right
    napi_value KEY_RIGHT_val;
    napi_create_int32(env, 262, &KEY_RIGHT_val);
    napi_set_named_property(env, enumObj, "KEY_RIGHT", KEY_RIGHT_val);

    // Key: Cursor left
    napi_value KEY_LEFT_val;
    napi_create_int32(env, 263, &KEY_LEFT_val);
    napi_set_named_property(env, enumObj, "KEY_LEFT", KEY_LEFT_val);

    // Key: Cursor down
    napi_value KEY_DOWN_val;
    napi_create_int32(env, 264, &KEY_DOWN_val);
    napi_set_named_property(env, enumObj, "KEY_DOWN", KEY_DOWN_val);

    // Key: Cursor up
    napi_value KEY_UP_val;
    napi_create_int32(env, 265, &KEY_UP_val);
    napi_set_named_property(env, enumObj, "KEY_UP", KEY_UP_val);

    // Key: Page up
    napi_value KEY_PAGE_UP_val;
    napi_create_int32(env, 266, &KEY_PAGE_UP_val);
    napi_set_named_property(env, enumObj, "KEY_PAGE_UP", KEY_PAGE_UP_val);

    // Key: Page down
    napi_value KEY_PAGE_DOWN_val;
    napi_create_int32(env, 267, &KEY_PAGE_DOWN_val);
    napi_set_named_property(env, enumObj, "KEY_PAGE_DOWN", KEY_PAGE_DOWN_val);

    // Key: Home
    napi_value KEY_HOME_val;
    napi_create_int32(env, 268, &KEY_HOME_val);
    napi_set_named_property(env, enumObj, "KEY_HOME", KEY_HOME_val);

    // Key: End
    napi_value KEY_END_val;
    napi_create_int32(env, 269, &KEY_END_val);
    napi_set_named_property(env, enumObj, "KEY_END", KEY_END_val);

    // Key: Caps lock
    napi_value KEY_CAPS_LOCK_val;
    napi_create_int32(env, 280, &KEY_CAPS_LOCK_val);
    napi_set_named_property(env, enumObj, "KEY_CAPS_LOCK", KEY_CAPS_LOCK_val);

    // Key: Scroll down
    napi_value KEY_SCROLL_LOCK_val;
    napi_create_int32(env, 281, &KEY_SCROLL_LOCK_val);
    napi_set_named_property(env, enumObj, "KEY_SCROLL_LOCK", KEY_SCROLL_LOCK_val);

    // Key: Num lock
    napi_value KEY_NUM_LOCK_val;
    napi_create_int32(env, 282, &KEY_NUM_LOCK_val);
    napi_set_named_property(env, enumObj, "KEY_NUM_LOCK", KEY_NUM_LOCK_val);

    // Key: Print screen
    napi_value KEY_PRINT_SCREEN_val;
    napi_create_int32(env, 283, &KEY_PRINT_SCREEN_val);
    napi_set_named_property(env, enumObj, "KEY_PRINT_SCREEN", KEY_PRINT_SCREEN_val);

    // Key: Pause
    napi_value KEY_PAUSE_val;
    napi_create_int32(env, 284, &KEY_PAUSE_val);
    napi_set_named_property(env, enumObj, "KEY_PAUSE", KEY_PAUSE_val);

    // Key: F1
    napi_value KEY_F1_val;
    napi_create_int32(env, 290, &KEY_F1_val);
    napi_set_named_property(env, enumObj, "KEY_F1", KEY_F1_val);

    // Key: F2
    napi_value KEY_F2_val;
    napi_create_int32(env, 291, &KEY_F2_val);
    napi_set_named_property(env, enumObj, "KEY_F2", KEY_F2_val);

    // Key: F3
    napi_value KEY_F3_val;
    napi_create_int32(env, 292, &KEY_F3_val);
    napi_set_named_property(env, enumObj, "KEY_F3", KEY_F3_val);

    // Key: F4
    napi_value KEY_F4_val;
    napi_create_int32(env, 293, &KEY_F4_val);
    napi_set_named_property(env, enumObj, "KEY_F4", KEY_F4_val);

    // Key: F5
    napi_value KEY_F5_val;
    napi_create_int32(env, 294, &KEY_F5_val);
    napi_set_named_property(env, enumObj, "KEY_F5", KEY_F5_val);

    // Key: F6
    napi_value KEY_F6_val;
    napi_create_int32(env, 295, &KEY_F6_val);
    napi_set_named_property(env, enumObj, "KEY_F6", KEY_F6_val);

    // Key: F7
    napi_value KEY_F7_val;
    napi_create_int32(env, 296, &KEY_F7_val);
    napi_set_named_property(env, enumObj, "KEY_F7", KEY_F7_val);

    // Key: F8
    napi_value KEY_F8_val;
    napi_create_int32(env, 297, &KEY_F8_val);
    napi_set_named_property(env, enumObj, "KEY_F8", KEY_F8_val);

    // Key: F9
    napi_value KEY_F9_val;
    napi_create_int32(env, 298, &KEY_F9_val);
    napi_set_named_property(env, enumObj, "KEY_F9", KEY_F9_val);

    // Key: F10
    napi_value KEY_F10_val;
    napi_create_int32(env, 299, &KEY_F10_val);
    napi_set_named_property(env, enumObj, "KEY_F10", KEY_F10_val);

    // Key: F11
    napi_value KEY_F11_val;
    napi_create_int32(env, 300, &KEY_F11_val);
    napi_set_named_property(env, enumObj, "KEY_F11", KEY_F11_val);

    // Key: F12
    napi_value KEY_F12_val;
    napi_create_int32(env, 301, &KEY_F12_val);
    napi_set_named_property(env, enumObj, "KEY_F12", KEY_F12_val);

    // Key: Shift left
    napi_value KEY_LEFT_SHIFT_val;
    napi_create_int32(env, 340, &KEY_LEFT_SHIFT_val);
    napi_set_named_property(env, enumObj, "KEY_LEFT_SHIFT", KEY_LEFT_SHIFT_val);

    // Key: Control left
    napi_value KEY_LEFT_CONTROL_val;
    napi_create_int32(env, 341, &KEY_LEFT_CONTROL_val);
    napi_set_named_property(env, enumObj, "KEY_LEFT_CONTROL", KEY_LEFT_CONTROL_val);

    // Key: Alt left
    napi_value KEY_LEFT_ALT_val;
    napi_create_int32(env, 342, &KEY_LEFT_ALT_val);
    napi_set_named_property(env, enumObj, "KEY_LEFT_ALT", KEY_LEFT_ALT_val);

    // Key: Super left
    napi_value KEY_LEFT_SUPER_val;
    napi_create_int32(env, 343, &KEY_LEFT_SUPER_val);
    napi_set_named_property(env, enumObj, "KEY_LEFT_SUPER", KEY_LEFT_SUPER_val);

    // Key: Shift right
    napi_value KEY_RIGHT_SHIFT_val;
    napi_create_int32(env, 344, &KEY_RIGHT_SHIFT_val);
    napi_set_named_property(env, enumObj, "KEY_RIGHT_SHIFT", KEY_RIGHT_SHIFT_val);

    // Key: Control right
    napi_value KEY_RIGHT_CONTROL_val;
    napi_create_int32(env, 345, &KEY_RIGHT_CONTROL_val);
    napi_set_named_property(env, enumObj, "KEY_RIGHT_CONTROL", KEY_RIGHT_CONTROL_val);

    // Key: Alt right
    napi_value KEY_RIGHT_ALT_val;
    napi_create_int32(env, 346, &KEY_RIGHT_ALT_val);
    napi_set_named_property(env, enumObj, "KEY_RIGHT_ALT", KEY_RIGHT_ALT_val);

    // Key: Super right
    napi_value KEY_RIGHT_SUPER_val;
    napi_create_int32(env, 347, &KEY_RIGHT_SUPER_val);
    napi_set_named_property(env, enumObj, "KEY_RIGHT_SUPER", KEY_RIGHT_SUPER_val);

    // Key: KB menu
    napi_value KEY_KB_MENU_val;
    napi_create_int32(env, 348, &KEY_KB_MENU_val);
    napi_set_named_property(env, enumObj, "KEY_KB_MENU", KEY_KB_MENU_val);

    // Key: Keypad 0
    napi_value KEY_KP_0_val;
    napi_create_int32(env, 320, &KEY_KP_0_val);
    napi_set_named_property(env, enumObj, "KEY_KP_0", KEY_KP_0_val);

    // Key: Keypad 1
    napi_value KEY_KP_1_val;
    napi_create_int32(env, 321, &KEY_KP_1_val);
    napi_set_named_property(env, enumObj, "KEY_KP_1", KEY_KP_1_val);

    // Key: Keypad 2
    napi_value KEY_KP_2_val;
    napi_create_int32(env, 322, &KEY_KP_2_val);
    napi_set_named_property(env, enumObj, "KEY_KP_2", KEY_KP_2_val);

    // Key: Keypad 3
    napi_value KEY_KP_3_val;
    napi_create_int32(env, 323, &KEY_KP_3_val);
    napi_set_named_property(env, enumObj, "KEY_KP_3", KEY_KP_3_val);

    // Key: Keypad 4
    napi_value KEY_KP_4_val;
    napi_create_int32(env, 324, &KEY_KP_4_val);
    napi_set_named_property(env, enumObj, "KEY_KP_4", KEY_KP_4_val);

    // Key: Keypad 5
    napi_value KEY_KP_5_val;
    napi_create_int32(env, 325, &KEY_KP_5_val);
    napi_set_named_property(env, enumObj, "KEY_KP_5", KEY_KP_5_val);

    // Key: Keypad 6
    napi_value KEY_KP_6_val;
    napi_create_int32(env, 326, &KEY_KP_6_val);
    napi_set_named_property(env, enumObj, "KEY_KP_6", KEY_KP_6_val);

    // Key: Keypad 7
    napi_value KEY_KP_7_val;
    napi_create_int32(env, 327, &KEY_KP_7_val);
    napi_set_named_property(env, enumObj, "KEY_KP_7", KEY_KP_7_val);

    // Key: Keypad 8
    napi_value KEY_KP_8_val;
    napi_create_int32(env, 328, &KEY_KP_8_val);
    napi_set_named_property(env, enumObj, "KEY_KP_8", KEY_KP_8_val);

    // Key: Keypad 9
    napi_value KEY_KP_9_val;
    napi_create_int32(env, 329, &KEY_KP_9_val);
    napi_set_named_property(env, enumObj, "KEY_KP_9", KEY_KP_9_val);

    // Key: Keypad .
    napi_value KEY_KP_DECIMAL_val;
    napi_create_int32(env, 330, &KEY_KP_DECIMAL_val);
    napi_set_named_property(env, enumObj, "KEY_KP_DECIMAL", KEY_KP_DECIMAL_val);

    // Key: Keypad /
    napi_value KEY_KP_DIVIDE_val;
    napi_create_int32(env, 331, &KEY_KP_DIVIDE_val);
    napi_set_named_property(env, enumObj, "KEY_KP_DIVIDE", KEY_KP_DIVIDE_val);

    // Key: Keypad *
    napi_value KEY_KP_MULTIPLY_val;
    napi_create_int32(env, 332, &KEY_KP_MULTIPLY_val);
    napi_set_named_property(env, enumObj, "KEY_KP_MULTIPLY", KEY_KP_MULTIPLY_val);

    // Key: Keypad -
    napi_value KEY_KP_SUBTRACT_val;
    napi_create_int32(env, 333, &KEY_KP_SUBTRACT_val);
    napi_set_named_property(env, enumObj, "KEY_KP_SUBTRACT", KEY_KP_SUBTRACT_val);

    // Key: Keypad +
    napi_value KEY_KP_ADD_val;
    napi_create_int32(env, 334, &KEY_KP_ADD_val);
    napi_set_named_property(env, enumObj, "KEY_KP_ADD", KEY_KP_ADD_val);

    // Key: Keypad Enter
    napi_value KEY_KP_ENTER_val;
    napi_create_int32(env, 335, &KEY_KP_ENTER_val);
    napi_set_named_property(env, enumObj, "KEY_KP_ENTER", KEY_KP_ENTER_val);

    // Key: Keypad =
    napi_value KEY_KP_EQUAL_val;
    napi_create_int32(env, 336, &KEY_KP_EQUAL_val);
    napi_set_named_property(env, enumObj, "KEY_KP_EQUAL", KEY_KP_EQUAL_val);

    // Key: Android back button
    napi_value KEY_BACK_val;
    napi_create_int32(env, 4, &KEY_BACK_val);
    napi_set_named_property(env, enumObj, "KEY_BACK", KEY_BACK_val);

    // Key: Android menu button
    napi_value KEY_MENU_val;
    napi_create_int32(env, 5, &KEY_MENU_val);
    napi_set_named_property(env, enumObj, "KEY_MENU", KEY_MENU_val);

    // Key: Android volume up button
    napi_value KEY_VOLUME_UP_val;
    napi_create_int32(env, 24, &KEY_VOLUME_UP_val);
    napi_set_named_property(env, enumObj, "KEY_VOLUME_UP", KEY_VOLUME_UP_val);

    // Key: Android volume down button
    napi_value KEY_VOLUME_DOWN_val;
    napi_create_int32(env, 25, &KEY_VOLUME_DOWN_val);
    napi_set_named_property(env, enumObj, "KEY_VOLUME_DOWN", KEY_VOLUME_DOWN_val);

    return enumObj;
}

napi_value Create_MouseButton(napi_env env) {
    napi_value enumObj;
    napi_create_object(env, &enumObj);

    // Mouse button left
    napi_value MOUSE_BUTTON_LEFT_val;
    napi_create_int32(env, 0, &MOUSE_BUTTON_LEFT_val);
    napi_set_named_property(env, enumObj, "MOUSE_BUTTON_LEFT", MOUSE_BUTTON_LEFT_val);

    // Mouse button right
    napi_value MOUSE_BUTTON_RIGHT_val;
    napi_create_int32(env, 1, &MOUSE_BUTTON_RIGHT_val);
    napi_set_named_property(env, enumObj, "MOUSE_BUTTON_RIGHT", MOUSE_BUTTON_RIGHT_val);

    // Mouse button middle (pressed wheel)
    napi_value MOUSE_BUTTON_MIDDLE_val;
    napi_create_int32(env, 2, &MOUSE_BUTTON_MIDDLE_val);
    napi_set_named_property(env, enumObj, "MOUSE_BUTTON_MIDDLE", MOUSE_BUTTON_MIDDLE_val);

    // Mouse button side (advanced mouse device)
    napi_value MOUSE_BUTTON_SIDE_val;
    napi_create_int32(env, 3, &MOUSE_BUTTON_SIDE_val);
    napi_set_named_property(env, enumObj, "MOUSE_BUTTON_SIDE", MOUSE_BUTTON_SIDE_val);

    // Mouse button extra (advanced mouse device)
    napi_value MOUSE_BUTTON_EXTRA_val;
    napi_create_int32(env, 4, &MOUSE_BUTTON_EXTRA_val);
    napi_set_named_property(env, enumObj, "MOUSE_BUTTON_EXTRA", MOUSE_BUTTON_EXTRA_val);

    // Mouse button forward (advanced mouse device)
    napi_value MOUSE_BUTTON_FORWARD_val;
    napi_create_int32(env, 5, &MOUSE_BUTTON_FORWARD_val);
    napi_set_named_property(env, enumObj, "MOUSE_BUTTON_FORWARD", MOUSE_BUTTON_FORWARD_val);

    // Mouse button back (advanced mouse device)
    napi_value MOUSE_BUTTON_BACK_val;
    napi_create_int32(env, 6, &MOUSE_BUTTON_BACK_val);
    napi_set_named_property(env, enumObj, "MOUSE_BUTTON_BACK", MOUSE_BUTTON_BACK_val);

    return enumObj;
}

napi_value Create_MouseCursor(napi_env env) {
    napi_value enumObj;
    napi_create_object(env, &enumObj);

    // Default pointer shape
    napi_value MOUSE_CURSOR_DEFAULT_val;
    napi_create_int32(env, 0, &MOUSE_CURSOR_DEFAULT_val);
    napi_set_named_property(env, enumObj, "MOUSE_CURSOR_DEFAULT", MOUSE_CURSOR_DEFAULT_val);

    // Arrow shape
    napi_value MOUSE_CURSOR_ARROW_val;
    napi_create_int32(env, 1, &MOUSE_CURSOR_ARROW_val);
    napi_set_named_property(env, enumObj, "MOUSE_CURSOR_ARROW", MOUSE_CURSOR_ARROW_val);

    // Text writing cursor shape
    napi_value MOUSE_CURSOR_IBEAM_val;
    napi_create_int32(env, 2, &MOUSE_CURSOR_IBEAM_val);
    napi_set_named_property(env, enumObj, "MOUSE_CURSOR_IBEAM", MOUSE_CURSOR_IBEAM_val);

    // Cross shape
    napi_value MOUSE_CURSOR_CROSSHAIR_val;
    napi_create_int32(env, 3, &MOUSE_CURSOR_CROSSHAIR_val);
    napi_set_named_property(env, enumObj, "MOUSE_CURSOR_CROSSHAIR", MOUSE_CURSOR_CROSSHAIR_val);

    // Pointing hand cursor
    napi_value MOUSE_CURSOR_POINTING_HAND_val;
    napi_create_int32(env, 4, &MOUSE_CURSOR_POINTING_HAND_val);
    napi_set_named_property(env, enumObj, "MOUSE_CURSOR_POINTING_HAND", MOUSE_CURSOR_POINTING_HAND_val);

    // Horizontal resize/move arrow shape
    napi_value MOUSE_CURSOR_RESIZE_EW_val;
    napi_create_int32(env, 5, &MOUSE_CURSOR_RESIZE_EW_val);
    napi_set_named_property(env, enumObj, "MOUSE_CURSOR_RESIZE_EW", MOUSE_CURSOR_RESIZE_EW_val);

    // Vertical resize/move arrow shape
    napi_value MOUSE_CURSOR_RESIZE_NS_val;
    napi_create_int32(env, 6, &MOUSE_CURSOR_RESIZE_NS_val);
    napi_set_named_property(env, enumObj, "MOUSE_CURSOR_RESIZE_NS", MOUSE_CURSOR_RESIZE_NS_val);

    // Top-left to bottom-right diagonal resize/move arrow shape
    napi_value MOUSE_CURSOR_RESIZE_NWSE_val;
    napi_create_int32(env, 7, &MOUSE_CURSOR_RESIZE_NWSE_val);
    napi_set_named_property(env, enumObj, "MOUSE_CURSOR_RESIZE_NWSE", MOUSE_CURSOR_RESIZE_NWSE_val);

    // The top-right to bottom-left diagonal resize/move arrow shape
    napi_value MOUSE_CURSOR_RESIZE_NESW_val;
    napi_create_int32(env, 8, &MOUSE_CURSOR_RESIZE_NESW_val);
    napi_set_named_property(env, enumObj, "MOUSE_CURSOR_RESIZE_NESW", MOUSE_CURSOR_RESIZE_NESW_val);

    // The omnidirectional resize/move cursor shape
    napi_value MOUSE_CURSOR_RESIZE_ALL_val;
    napi_create_int32(env, 9, &MOUSE_CURSOR_RESIZE_ALL_val);
    napi_set_named_property(env, enumObj, "MOUSE_CURSOR_RESIZE_ALL", MOUSE_CURSOR_RESIZE_ALL_val);

    // The operation-not-allowed shape
    napi_value MOUSE_CURSOR_NOT_ALLOWED_val;
    napi_create_int32(env, 10, &MOUSE_CURSOR_NOT_ALLOWED_val);
    napi_set_named_property(env, enumObj, "MOUSE_CURSOR_NOT_ALLOWED", MOUSE_CURSOR_NOT_ALLOWED_val);

    return enumObj;
}

napi_value Create_GamepadButton(napi_env env) {
    napi_value enumObj;
    napi_create_object(env, &enumObj);

    // Unknown button, just for error checking
    napi_value GAMEPAD_BUTTON_UNKNOWN_val;
    napi_create_int32(env, 0, &GAMEPAD_BUTTON_UNKNOWN_val);
    napi_set_named_property(env, enumObj, "GAMEPAD_BUTTON_UNKNOWN", GAMEPAD_BUTTON_UNKNOWN_val);

    // Gamepad left DPAD up button
    napi_value GAMEPAD_BUTTON_LEFT_FACE_UP_val;
    napi_create_int32(env, 1, &GAMEPAD_BUTTON_LEFT_FACE_UP_val);
    napi_set_named_property(env, enumObj, "GAMEPAD_BUTTON_LEFT_FACE_UP", GAMEPAD_BUTTON_LEFT_FACE_UP_val);

    // Gamepad left DPAD right button
    napi_value GAMEPAD_BUTTON_LEFT_FACE_RIGHT_val;
    napi_create_int32(env, 2, &GAMEPAD_BUTTON_LEFT_FACE_RIGHT_val);
    napi_set_named_property(env, enumObj, "GAMEPAD_BUTTON_LEFT_FACE_RIGHT", GAMEPAD_BUTTON_LEFT_FACE_RIGHT_val);

    // Gamepad left DPAD down button
    napi_value GAMEPAD_BUTTON_LEFT_FACE_DOWN_val;
    napi_create_int32(env, 3, &GAMEPAD_BUTTON_LEFT_FACE_DOWN_val);
    napi_set_named_property(env, enumObj, "GAMEPAD_BUTTON_LEFT_FACE_DOWN", GAMEPAD_BUTTON_LEFT_FACE_DOWN_val);

    // Gamepad left DPAD left button
    napi_value GAMEPAD_BUTTON_LEFT_FACE_LEFT_val;
    napi_create_int32(env, 4, &GAMEPAD_BUTTON_LEFT_FACE_LEFT_val);
    napi_set_named_property(env, enumObj, "GAMEPAD_BUTTON_LEFT_FACE_LEFT", GAMEPAD_BUTTON_LEFT_FACE_LEFT_val);

    // Gamepad right button up (i.e. PS3: Triangle, Xbox: Y)
    napi_value GAMEPAD_BUTTON_RIGHT_FACE_UP_val;
    napi_create_int32(env, 5, &GAMEPAD_BUTTON_RIGHT_FACE_UP_val);
    napi_set_named_property(env, enumObj, "GAMEPAD_BUTTON_RIGHT_FACE_UP", GAMEPAD_BUTTON_RIGHT_FACE_UP_val);

    // Gamepad right button right (i.e. PS3: Circle, Xbox: B)
    napi_value GAMEPAD_BUTTON_RIGHT_FACE_RIGHT_val;
    napi_create_int32(env, 6, &GAMEPAD_BUTTON_RIGHT_FACE_RIGHT_val);
    napi_set_named_property(env, enumObj, "GAMEPAD_BUTTON_RIGHT_FACE_RIGHT", GAMEPAD_BUTTON_RIGHT_FACE_RIGHT_val);

    // Gamepad right button down (i.e. PS3: Cross, Xbox: A)
    napi_value GAMEPAD_BUTTON_RIGHT_FACE_DOWN_val;
    napi_create_int32(env, 7, &GAMEPAD_BUTTON_RIGHT_FACE_DOWN_val);
    napi_set_named_property(env, enumObj, "GAMEPAD_BUTTON_RIGHT_FACE_DOWN", GAMEPAD_BUTTON_RIGHT_FACE_DOWN_val);

    // Gamepad right button left (i.e. PS3: Square, Xbox: X)
    napi_value GAMEPAD_BUTTON_RIGHT_FACE_LEFT_val;
    napi_create_int32(env, 8, &GAMEPAD_BUTTON_RIGHT_FACE_LEFT_val);
    napi_set_named_property(env, enumObj, "GAMEPAD_BUTTON_RIGHT_FACE_LEFT", GAMEPAD_BUTTON_RIGHT_FACE_LEFT_val);

    // Gamepad top/back trigger left (first), it could be a trailing button
    napi_value GAMEPAD_BUTTON_LEFT_TRIGGER_1_val;
    napi_create_int32(env, 9, &GAMEPAD_BUTTON_LEFT_TRIGGER_1_val);
    napi_set_named_property(env, enumObj, "GAMEPAD_BUTTON_LEFT_TRIGGER_1", GAMEPAD_BUTTON_LEFT_TRIGGER_1_val);

    // Gamepad top/back trigger left (second), it could be a trailing button
    napi_value GAMEPAD_BUTTON_LEFT_TRIGGER_2_val;
    napi_create_int32(env, 10, &GAMEPAD_BUTTON_LEFT_TRIGGER_2_val);
    napi_set_named_property(env, enumObj, "GAMEPAD_BUTTON_LEFT_TRIGGER_2", GAMEPAD_BUTTON_LEFT_TRIGGER_2_val);

    // Gamepad top/back trigger right (first), it could be a trailing button
    napi_value GAMEPAD_BUTTON_RIGHT_TRIGGER_1_val;
    napi_create_int32(env, 11, &GAMEPAD_BUTTON_RIGHT_TRIGGER_1_val);
    napi_set_named_property(env, enumObj, "GAMEPAD_BUTTON_RIGHT_TRIGGER_1", GAMEPAD_BUTTON_RIGHT_TRIGGER_1_val);

    // Gamepad top/back trigger right (second), it could be a trailing button
    napi_value GAMEPAD_BUTTON_RIGHT_TRIGGER_2_val;
    napi_create_int32(env, 12, &GAMEPAD_BUTTON_RIGHT_TRIGGER_2_val);
    napi_set_named_property(env, enumObj, "GAMEPAD_BUTTON_RIGHT_TRIGGER_2", GAMEPAD_BUTTON_RIGHT_TRIGGER_2_val);

    // Gamepad center buttons, left one (i.e. PS3: Select)
    napi_value GAMEPAD_BUTTON_MIDDLE_LEFT_val;
    napi_create_int32(env, 13, &GAMEPAD_BUTTON_MIDDLE_LEFT_val);
    napi_set_named_property(env, enumObj, "GAMEPAD_BUTTON_MIDDLE_LEFT", GAMEPAD_BUTTON_MIDDLE_LEFT_val);

    // Gamepad center buttons, middle one (i.e. PS3: PS, Xbox: XBOX)
    napi_value GAMEPAD_BUTTON_MIDDLE_val;
    napi_create_int32(env, 14, &GAMEPAD_BUTTON_MIDDLE_val);
    napi_set_named_property(env, enumObj, "GAMEPAD_BUTTON_MIDDLE", GAMEPAD_BUTTON_MIDDLE_val);

    // Gamepad center buttons, right one (i.e. PS3: Start)
    napi_value GAMEPAD_BUTTON_MIDDLE_RIGHT_val;
    napi_create_int32(env, 15, &GAMEPAD_BUTTON_MIDDLE_RIGHT_val);
    napi_set_named_property(env, enumObj, "GAMEPAD_BUTTON_MIDDLE_RIGHT", GAMEPAD_BUTTON_MIDDLE_RIGHT_val);

    // Gamepad joystick pressed button left
    napi_value GAMEPAD_BUTTON_LEFT_THUMB_val;
    napi_create_int32(env, 16, &GAMEPAD_BUTTON_LEFT_THUMB_val);
    napi_set_named_property(env, enumObj, "GAMEPAD_BUTTON_LEFT_THUMB", GAMEPAD_BUTTON_LEFT_THUMB_val);

    // Gamepad joystick pressed button right
    napi_value GAMEPAD_BUTTON_RIGHT_THUMB_val;
    napi_create_int32(env, 17, &GAMEPAD_BUTTON_RIGHT_THUMB_val);
    napi_set_named_property(env, enumObj, "GAMEPAD_BUTTON_RIGHT_THUMB", GAMEPAD_BUTTON_RIGHT_THUMB_val);

    return enumObj;
}

napi_value Create_GamepadAxis(napi_env env) {
    napi_value enumObj;
    napi_create_object(env, &enumObj);

    // Gamepad left stick X axis
    napi_value GAMEPAD_AXIS_LEFT_X_val;
    napi_create_int32(env, 0, &GAMEPAD_AXIS_LEFT_X_val);
    napi_set_named_property(env, enumObj, "GAMEPAD_AXIS_LEFT_X", GAMEPAD_AXIS_LEFT_X_val);

    // Gamepad left stick Y axis
    napi_value GAMEPAD_AXIS_LEFT_Y_val;
    napi_create_int32(env, 1, &GAMEPAD_AXIS_LEFT_Y_val);
    napi_set_named_property(env, enumObj, "GAMEPAD_AXIS_LEFT_Y", GAMEPAD_AXIS_LEFT_Y_val);

    // Gamepad right stick X axis
    napi_value GAMEPAD_AXIS_RIGHT_X_val;
    napi_create_int32(env, 2, &GAMEPAD_AXIS_RIGHT_X_val);
    napi_set_named_property(env, enumObj, "GAMEPAD_AXIS_RIGHT_X", GAMEPAD_AXIS_RIGHT_X_val);

    // Gamepad right stick Y axis
    napi_value GAMEPAD_AXIS_RIGHT_Y_val;
    napi_create_int32(env, 3, &GAMEPAD_AXIS_RIGHT_Y_val);
    napi_set_named_property(env, enumObj, "GAMEPAD_AXIS_RIGHT_Y", GAMEPAD_AXIS_RIGHT_Y_val);

    // Gamepad back trigger left, pressure level: [1..-1]
    napi_value GAMEPAD_AXIS_LEFT_TRIGGER_val;
    napi_create_int32(env, 4, &GAMEPAD_AXIS_LEFT_TRIGGER_val);
    napi_set_named_property(env, enumObj, "GAMEPAD_AXIS_LEFT_TRIGGER", GAMEPAD_AXIS_LEFT_TRIGGER_val);

    // Gamepad back trigger right, pressure level: [1..-1]
    napi_value GAMEPAD_AXIS_RIGHT_TRIGGER_val;
    napi_create_int32(env, 5, &GAMEPAD_AXIS_RIGHT_TRIGGER_val);
    napi_set_named_property(env, enumObj, "GAMEPAD_AXIS_RIGHT_TRIGGER", GAMEPAD_AXIS_RIGHT_TRIGGER_val);

    return enumObj;
}

napi_value Create_MaterialMapIndex(napi_env env) {
    napi_value enumObj;
    napi_create_object(env, &enumObj);

    // Albedo material (same as: MATERIAL_MAP_DIFFUSE)
    napi_value MATERIAL_MAP_ALBEDO_val;
    napi_create_int32(env, 0, &MATERIAL_MAP_ALBEDO_val);
    napi_set_named_property(env, enumObj, "MATERIAL_MAP_ALBEDO", MATERIAL_MAP_ALBEDO_val);

    // Metalness material (same as: MATERIAL_MAP_SPECULAR)
    napi_value MATERIAL_MAP_METALNESS_val;
    napi_create_int32(env, 1, &MATERIAL_MAP_METALNESS_val);
    napi_set_named_property(env, enumObj, "MATERIAL_MAP_METALNESS", MATERIAL_MAP_METALNESS_val);

    // Normal material
    napi_value MATERIAL_MAP_NORMAL_val;
    napi_create_int32(env, 2, &MATERIAL_MAP_NORMAL_val);
    napi_set_named_property(env, enumObj, "MATERIAL_MAP_NORMAL", MATERIAL_MAP_NORMAL_val);

    // Roughness material
    napi_value MATERIAL_MAP_ROUGHNESS_val;
    napi_create_int32(env, 3, &MATERIAL_MAP_ROUGHNESS_val);
    napi_set_named_property(env, enumObj, "MATERIAL_MAP_ROUGHNESS", MATERIAL_MAP_ROUGHNESS_val);

    // Ambient occlusion material
    napi_value MATERIAL_MAP_OCCLUSION_val;
    napi_create_int32(env, 4, &MATERIAL_MAP_OCCLUSION_val);
    napi_set_named_property(env, enumObj, "MATERIAL_MAP_OCCLUSION", MATERIAL_MAP_OCCLUSION_val);

    // Emission material
    napi_value MATERIAL_MAP_EMISSION_val;
    napi_create_int32(env, 5, &MATERIAL_MAP_EMISSION_val);
    napi_set_named_property(env, enumObj, "MATERIAL_MAP_EMISSION", MATERIAL_MAP_EMISSION_val);

    // Heightmap material
    napi_value MATERIAL_MAP_HEIGHT_val;
    napi_create_int32(env, 6, &MATERIAL_MAP_HEIGHT_val);
    napi_set_named_property(env, enumObj, "MATERIAL_MAP_HEIGHT", MATERIAL_MAP_HEIGHT_val);

    // Cubemap material (NOTE: Uses GL_TEXTURE_CUBE_MAP)
    napi_value MATERIAL_MAP_CUBEMAP_val;
    napi_create_int32(env, 7, &MATERIAL_MAP_CUBEMAP_val);
    napi_set_named_property(env, enumObj, "MATERIAL_MAP_CUBEMAP", MATERIAL_MAP_CUBEMAP_val);

    // Irradiance material (NOTE: Uses GL_TEXTURE_CUBE_MAP)
    napi_value MATERIAL_MAP_IRRADIANCE_val;
    napi_create_int32(env, 8, &MATERIAL_MAP_IRRADIANCE_val);
    napi_set_named_property(env, enumObj, "MATERIAL_MAP_IRRADIANCE", MATERIAL_MAP_IRRADIANCE_val);

    // Prefilter material (NOTE: Uses GL_TEXTURE_CUBE_MAP)
    napi_value MATERIAL_MAP_PREFILTER_val;
    napi_create_int32(env, 9, &MATERIAL_MAP_PREFILTER_val);
    napi_set_named_property(env, enumObj, "MATERIAL_MAP_PREFILTER", MATERIAL_MAP_PREFILTER_val);

    // Brdf material
    napi_value MATERIAL_MAP_BRDF_val;
    napi_create_int32(env, 10, &MATERIAL_MAP_BRDF_val);
    napi_set_named_property(env, enumObj, "MATERIAL_MAP_BRDF", MATERIAL_MAP_BRDF_val);

    return enumObj;
}

napi_value Create_ShaderLocationIndex(napi_env env) {
    napi_value enumObj;
    napi_create_object(env, &enumObj);

    // Shader location: vertex attribute: position
    napi_value SHADER_LOC_VERTEX_POSITION_val;
    napi_create_int32(env, 0, &SHADER_LOC_VERTEX_POSITION_val);
    napi_set_named_property(env, enumObj, "SHADER_LOC_VERTEX_POSITION", SHADER_LOC_VERTEX_POSITION_val);

    // Shader location: vertex attribute: texcoord01
    napi_value SHADER_LOC_VERTEX_TEXCOORD01_val;
    napi_create_int32(env, 1, &SHADER_LOC_VERTEX_TEXCOORD01_val);
    napi_set_named_property(env, enumObj, "SHADER_LOC_VERTEX_TEXCOORD01", SHADER_LOC_VERTEX_TEXCOORD01_val);

    // Shader location: vertex attribute: texcoord02
    napi_value SHADER_LOC_VERTEX_TEXCOORD02_val;
    napi_create_int32(env, 2, &SHADER_LOC_VERTEX_TEXCOORD02_val);
    napi_set_named_property(env, enumObj, "SHADER_LOC_VERTEX_TEXCOORD02", SHADER_LOC_VERTEX_TEXCOORD02_val);

    // Shader location: vertex attribute: normal
    napi_value SHADER_LOC_VERTEX_NORMAL_val;
    napi_create_int32(env, 3, &SHADER_LOC_VERTEX_NORMAL_val);
    napi_set_named_property(env, enumObj, "SHADER_LOC_VERTEX_NORMAL", SHADER_LOC_VERTEX_NORMAL_val);

    // Shader location: vertex attribute: tangent
    napi_value SHADER_LOC_VERTEX_TANGENT_val;
    napi_create_int32(env, 4, &SHADER_LOC_VERTEX_TANGENT_val);
    napi_set_named_property(env, enumObj, "SHADER_LOC_VERTEX_TANGENT", SHADER_LOC_VERTEX_TANGENT_val);

    // Shader location: vertex attribute: color
    napi_value SHADER_LOC_VERTEX_COLOR_val;
    napi_create_int32(env, 5, &SHADER_LOC_VERTEX_COLOR_val);
    napi_set_named_property(env, enumObj, "SHADER_LOC_VERTEX_COLOR", SHADER_LOC_VERTEX_COLOR_val);

    // Shader location: matrix uniform: model-view-projection
    napi_value SHADER_LOC_MATRIX_MVP_val;
    napi_create_int32(env, 6, &SHADER_LOC_MATRIX_MVP_val);
    napi_set_named_property(env, enumObj, "SHADER_LOC_MATRIX_MVP", SHADER_LOC_MATRIX_MVP_val);

    // Shader location: matrix uniform: view (camera transform)
    napi_value SHADER_LOC_MATRIX_VIEW_val;
    napi_create_int32(env, 7, &SHADER_LOC_MATRIX_VIEW_val);
    napi_set_named_property(env, enumObj, "SHADER_LOC_MATRIX_VIEW", SHADER_LOC_MATRIX_VIEW_val);

    // Shader location: matrix uniform: projection
    napi_value SHADER_LOC_MATRIX_PROJECTION_val;
    napi_create_int32(env, 8, &SHADER_LOC_MATRIX_PROJECTION_val);
    napi_set_named_property(env, enumObj, "SHADER_LOC_MATRIX_PROJECTION", SHADER_LOC_MATRIX_PROJECTION_val);

    // Shader location: matrix uniform: model (transform)
    napi_value SHADER_LOC_MATRIX_MODEL_val;
    napi_create_int32(env, 9, &SHADER_LOC_MATRIX_MODEL_val);
    napi_set_named_property(env, enumObj, "SHADER_LOC_MATRIX_MODEL", SHADER_LOC_MATRIX_MODEL_val);

    // Shader location: matrix uniform: normal
    napi_value SHADER_LOC_MATRIX_NORMAL_val;
    napi_create_int32(env, 10, &SHADER_LOC_MATRIX_NORMAL_val);
    napi_set_named_property(env, enumObj, "SHADER_LOC_MATRIX_NORMAL", SHADER_LOC_MATRIX_NORMAL_val);

    // Shader location: vector uniform: view
    napi_value SHADER_LOC_VECTOR_VIEW_val;
    napi_create_int32(env, 11, &SHADER_LOC_VECTOR_VIEW_val);
    napi_set_named_property(env, enumObj, "SHADER_LOC_VECTOR_VIEW", SHADER_LOC_VECTOR_VIEW_val);

    // Shader location: vector uniform: diffuse color
    napi_value SHADER_LOC_COLOR_DIFFUSE_val;
    napi_create_int32(env, 12, &SHADER_LOC_COLOR_DIFFUSE_val);
    napi_set_named_property(env, enumObj, "SHADER_LOC_COLOR_DIFFUSE", SHADER_LOC_COLOR_DIFFUSE_val);

    // Shader location: vector uniform: specular color
    napi_value SHADER_LOC_COLOR_SPECULAR_val;
    napi_create_int32(env, 13, &SHADER_LOC_COLOR_SPECULAR_val);
    napi_set_named_property(env, enumObj, "SHADER_LOC_COLOR_SPECULAR", SHADER_LOC_COLOR_SPECULAR_val);

    // Shader location: vector uniform: ambient color
    napi_value SHADER_LOC_COLOR_AMBIENT_val;
    napi_create_int32(env, 14, &SHADER_LOC_COLOR_AMBIENT_val);
    napi_set_named_property(env, enumObj, "SHADER_LOC_COLOR_AMBIENT", SHADER_LOC_COLOR_AMBIENT_val);

    // Shader location: sampler2d texture: albedo (same as: SHADER_LOC_MAP_DIFFUSE)
    napi_value SHADER_LOC_MAP_ALBEDO_val;
    napi_create_int32(env, 15, &SHADER_LOC_MAP_ALBEDO_val);
    napi_set_named_property(env, enumObj, "SHADER_LOC_MAP_ALBEDO", SHADER_LOC_MAP_ALBEDO_val);

    // Shader location: sampler2d texture: metalness (same as: SHADER_LOC_MAP_SPECULAR)
    napi_value SHADER_LOC_MAP_METALNESS_val;
    napi_create_int32(env, 16, &SHADER_LOC_MAP_METALNESS_val);
    napi_set_named_property(env, enumObj, "SHADER_LOC_MAP_METALNESS", SHADER_LOC_MAP_METALNESS_val);

    // Shader location: sampler2d texture: normal
    napi_value SHADER_LOC_MAP_NORMAL_val;
    napi_create_int32(env, 17, &SHADER_LOC_MAP_NORMAL_val);
    napi_set_named_property(env, enumObj, "SHADER_LOC_MAP_NORMAL", SHADER_LOC_MAP_NORMAL_val);

    // Shader location: sampler2d texture: roughness
    napi_value SHADER_LOC_MAP_ROUGHNESS_val;
    napi_create_int32(env, 18, &SHADER_LOC_MAP_ROUGHNESS_val);
    napi_set_named_property(env, enumObj, "SHADER_LOC_MAP_ROUGHNESS", SHADER_LOC_MAP_ROUGHNESS_val);

    // Shader location: sampler2d texture: occlusion
    napi_value SHADER_LOC_MAP_OCCLUSION_val;
    napi_create_int32(env, 19, &SHADER_LOC_MAP_OCCLUSION_val);
    napi_set_named_property(env, enumObj, "SHADER_LOC_MAP_OCCLUSION", SHADER_LOC_MAP_OCCLUSION_val);

    // Shader location: sampler2d texture: emission
    napi_value SHADER_LOC_MAP_EMISSION_val;
    napi_create_int32(env, 20, &SHADER_LOC_MAP_EMISSION_val);
    napi_set_named_property(env, enumObj, "SHADER_LOC_MAP_EMISSION", SHADER_LOC_MAP_EMISSION_val);

    // Shader location: sampler2d texture: height
    napi_value SHADER_LOC_MAP_HEIGHT_val;
    napi_create_int32(env, 21, &SHADER_LOC_MAP_HEIGHT_val);
    napi_set_named_property(env, enumObj, "SHADER_LOC_MAP_HEIGHT", SHADER_LOC_MAP_HEIGHT_val);

    // Shader location: samplerCube texture: cubemap
    napi_value SHADER_LOC_MAP_CUBEMAP_val;
    napi_create_int32(env, 22, &SHADER_LOC_MAP_CUBEMAP_val);
    napi_set_named_property(env, enumObj, "SHADER_LOC_MAP_CUBEMAP", SHADER_LOC_MAP_CUBEMAP_val);

    // Shader location: samplerCube texture: irradiance
    napi_value SHADER_LOC_MAP_IRRADIANCE_val;
    napi_create_int32(env, 23, &SHADER_LOC_MAP_IRRADIANCE_val);
    napi_set_named_property(env, enumObj, "SHADER_LOC_MAP_IRRADIANCE", SHADER_LOC_MAP_IRRADIANCE_val);

    // Shader location: samplerCube texture: prefilter
    napi_value SHADER_LOC_MAP_PREFILTER_val;
    napi_create_int32(env, 24, &SHADER_LOC_MAP_PREFILTER_val);
    napi_set_named_property(env, enumObj, "SHADER_LOC_MAP_PREFILTER", SHADER_LOC_MAP_PREFILTER_val);

    // Shader location: sampler2d texture: brdf
    napi_value SHADER_LOC_MAP_BRDF_val;
    napi_create_int32(env, 25, &SHADER_LOC_MAP_BRDF_val);
    napi_set_named_property(env, enumObj, "SHADER_LOC_MAP_BRDF", SHADER_LOC_MAP_BRDF_val);

    // Shader location: vertex attribute: boneIds
    napi_value SHADER_LOC_VERTEX_BONEIDS_val;
    napi_create_int32(env, 26, &SHADER_LOC_VERTEX_BONEIDS_val);
    napi_set_named_property(env, enumObj, "SHADER_LOC_VERTEX_BONEIDS", SHADER_LOC_VERTEX_BONEIDS_val);

    // Shader location: vertex attribute: boneWeights
    napi_value SHADER_LOC_VERTEX_BONEWEIGHTS_val;
    napi_create_int32(env, 27, &SHADER_LOC_VERTEX_BONEWEIGHTS_val);
    napi_set_named_property(env, enumObj, "SHADER_LOC_VERTEX_BONEWEIGHTS", SHADER_LOC_VERTEX_BONEWEIGHTS_val);

    // Shader location: array of matrices uniform: boneMatrices
    napi_value SHADER_LOC_BONE_MATRICES_val;
    napi_create_int32(env, 28, &SHADER_LOC_BONE_MATRICES_val);
    napi_set_named_property(env, enumObj, "SHADER_LOC_BONE_MATRICES", SHADER_LOC_BONE_MATRICES_val);

    return enumObj;
}

napi_value Create_ShaderUniformDataType(napi_env env) {
    napi_value enumObj;
    napi_create_object(env, &enumObj);

    // Shader uniform type: float
    napi_value SHADER_UNIFORM_FLOAT_val;
    napi_create_int32(env, 0, &SHADER_UNIFORM_FLOAT_val);
    napi_set_named_property(env, enumObj, "SHADER_UNIFORM_FLOAT", SHADER_UNIFORM_FLOAT_val);

    // Shader uniform type: vec2 (2 float)
    napi_value SHADER_UNIFORM_VEC2_val;
    napi_create_int32(env, 1, &SHADER_UNIFORM_VEC2_val);
    napi_set_named_property(env, enumObj, "SHADER_UNIFORM_VEC2", SHADER_UNIFORM_VEC2_val);

    // Shader uniform type: vec3 (3 float)
    napi_value SHADER_UNIFORM_VEC3_val;
    napi_create_int32(env, 2, &SHADER_UNIFORM_VEC3_val);
    napi_set_named_property(env, enumObj, "SHADER_UNIFORM_VEC3", SHADER_UNIFORM_VEC3_val);

    // Shader uniform type: vec4 (4 float)
    napi_value SHADER_UNIFORM_VEC4_val;
    napi_create_int32(env, 3, &SHADER_UNIFORM_VEC4_val);
    napi_set_named_property(env, enumObj, "SHADER_UNIFORM_VEC4", SHADER_UNIFORM_VEC4_val);

    // Shader uniform type: int
    napi_value SHADER_UNIFORM_INT_val;
    napi_create_int32(env, 4, &SHADER_UNIFORM_INT_val);
    napi_set_named_property(env, enumObj, "SHADER_UNIFORM_INT", SHADER_UNIFORM_INT_val);

    // Shader uniform type: ivec2 (2 int)
    napi_value SHADER_UNIFORM_IVEC2_val;
    napi_create_int32(env, 5, &SHADER_UNIFORM_IVEC2_val);
    napi_set_named_property(env, enumObj, "SHADER_UNIFORM_IVEC2", SHADER_UNIFORM_IVEC2_val);

    // Shader uniform type: ivec3 (3 int)
    napi_value SHADER_UNIFORM_IVEC3_val;
    napi_create_int32(env, 6, &SHADER_UNIFORM_IVEC3_val);
    napi_set_named_property(env, enumObj, "SHADER_UNIFORM_IVEC3", SHADER_UNIFORM_IVEC3_val);

    // Shader uniform type: ivec4 (4 int)
    napi_value SHADER_UNIFORM_IVEC4_val;
    napi_create_int32(env, 7, &SHADER_UNIFORM_IVEC4_val);
    napi_set_named_property(env, enumObj, "SHADER_UNIFORM_IVEC4", SHADER_UNIFORM_IVEC4_val);

    // Shader uniform type: sampler2d
    napi_value SHADER_UNIFORM_SAMPLER2D_val;
    napi_create_int32(env, 8, &SHADER_UNIFORM_SAMPLER2D_val);
    napi_set_named_property(env, enumObj, "SHADER_UNIFORM_SAMPLER2D", SHADER_UNIFORM_SAMPLER2D_val);

    return enumObj;
}

napi_value Create_ShaderAttributeDataType(napi_env env) {
    napi_value enumObj;
    napi_create_object(env, &enumObj);

    // Shader attribute type: float
    napi_value SHADER_ATTRIB_FLOAT_val;
    napi_create_int32(env, 0, &SHADER_ATTRIB_FLOAT_val);
    napi_set_named_property(env, enumObj, "SHADER_ATTRIB_FLOAT", SHADER_ATTRIB_FLOAT_val);

    // Shader attribute type: vec2 (2 float)
    napi_value SHADER_ATTRIB_VEC2_val;
    napi_create_int32(env, 1, &SHADER_ATTRIB_VEC2_val);
    napi_set_named_property(env, enumObj, "SHADER_ATTRIB_VEC2", SHADER_ATTRIB_VEC2_val);

    // Shader attribute type: vec3 (3 float)
    napi_value SHADER_ATTRIB_VEC3_val;
    napi_create_int32(env, 2, &SHADER_ATTRIB_VEC3_val);
    napi_set_named_property(env, enumObj, "SHADER_ATTRIB_VEC3", SHADER_ATTRIB_VEC3_val);

    // Shader attribute type: vec4 (4 float)
    napi_value SHADER_ATTRIB_VEC4_val;
    napi_create_int32(env, 3, &SHADER_ATTRIB_VEC4_val);
    napi_set_named_property(env, enumObj, "SHADER_ATTRIB_VEC4", SHADER_ATTRIB_VEC4_val);

    return enumObj;
}

napi_value Create_PixelFormat(napi_env env) {
    napi_value enumObj;
    napi_create_object(env, &enumObj);

    // 8 bit per pixel (no alpha)
    napi_value PIXELFORMAT_UNCOMPRESSED_GRAYSCALE_val;
    napi_create_int32(env, 1, &PIXELFORMAT_UNCOMPRESSED_GRAYSCALE_val);
    napi_set_named_property(env, enumObj, "PIXELFORMAT_UNCOMPRESSED_GRAYSCALE", PIXELFORMAT_UNCOMPRESSED_GRAYSCALE_val);

    // 8*2 bpp (2 channels)
    napi_value PIXELFORMAT_UNCOMPRESSED_GRAY_ALPHA_val;
    napi_create_int32(env, 2, &PIXELFORMAT_UNCOMPRESSED_GRAY_ALPHA_val);
    napi_set_named_property(env, enumObj, "PIXELFORMAT_UNCOMPRESSED_GRAY_ALPHA", PIXELFORMAT_UNCOMPRESSED_GRAY_ALPHA_val);

    // 16 bpp
    napi_value PIXELFORMAT_UNCOMPRESSED_R5G6B5_val;
    napi_create_int32(env, 3, &PIXELFORMAT_UNCOMPRESSED_R5G6B5_val);
    napi_set_named_property(env, enumObj, "PIXELFORMAT_UNCOMPRESSED_R5G6B5", PIXELFORMAT_UNCOMPRESSED_R5G6B5_val);

    // 24 bpp
    napi_value PIXELFORMAT_UNCOMPRESSED_R8G8B8_val;
    napi_create_int32(env, 4, &PIXELFORMAT_UNCOMPRESSED_R8G8B8_val);
    napi_set_named_property(env, enumObj, "PIXELFORMAT_UNCOMPRESSED_R8G8B8", PIXELFORMAT_UNCOMPRESSED_R8G8B8_val);

    // 16 bpp (1 bit alpha)
    napi_value PIXELFORMAT_UNCOMPRESSED_R5G5B5A1_val;
    napi_create_int32(env, 5, &PIXELFORMAT_UNCOMPRESSED_R5G5B5A1_val);
    napi_set_named_property(env, enumObj, "PIXELFORMAT_UNCOMPRESSED_R5G5B5A1", PIXELFORMAT_UNCOMPRESSED_R5G5B5A1_val);

    // 16 bpp (4 bit alpha)
    napi_value PIXELFORMAT_UNCOMPRESSED_R4G4B4A4_val;
    napi_create_int32(env, 6, &PIXELFORMAT_UNCOMPRESSED_R4G4B4A4_val);
    napi_set_named_property(env, enumObj, "PIXELFORMAT_UNCOMPRESSED_R4G4B4A4", PIXELFORMAT_UNCOMPRESSED_R4G4B4A4_val);

    // 32 bpp
    napi_value PIXELFORMAT_UNCOMPRESSED_R8G8B8A8_val;
    napi_create_int32(env, 7, &PIXELFORMAT_UNCOMPRESSED_R8G8B8A8_val);
    napi_set_named_property(env, enumObj, "PIXELFORMAT_UNCOMPRESSED_R8G8B8A8", PIXELFORMAT_UNCOMPRESSED_R8G8B8A8_val);

    // 32 bpp (1 channel - float)
    napi_value PIXELFORMAT_UNCOMPRESSED_R32_val;
    napi_create_int32(env, 8, &PIXELFORMAT_UNCOMPRESSED_R32_val);
    napi_set_named_property(env, enumObj, "PIXELFORMAT_UNCOMPRESSED_R32", PIXELFORMAT_UNCOMPRESSED_R32_val);

    // 32*3 bpp (3 channels - float)
    napi_value PIXELFORMAT_UNCOMPRESSED_R32G32B32_val;
    napi_create_int32(env, 9, &PIXELFORMAT_UNCOMPRESSED_R32G32B32_val);
    napi_set_named_property(env, enumObj, "PIXELFORMAT_UNCOMPRESSED_R32G32B32", PIXELFORMAT_UNCOMPRESSED_R32G32B32_val);

    // 32*4 bpp (4 channels - float)
    napi_value PIXELFORMAT_UNCOMPRESSED_R32G32B32A32_val;
    napi_create_int32(env, 10, &PIXELFORMAT_UNCOMPRESSED_R32G32B32A32_val);
    napi_set_named_property(env, enumObj, "PIXELFORMAT_UNCOMPRESSED_R32G32B32A32", PIXELFORMAT_UNCOMPRESSED_R32G32B32A32_val);

    // 16 bpp (1 channel - half float)
    napi_value PIXELFORMAT_UNCOMPRESSED_R16_val;
    napi_create_int32(env, 11, &PIXELFORMAT_UNCOMPRESSED_R16_val);
    napi_set_named_property(env, enumObj, "PIXELFORMAT_UNCOMPRESSED_R16", PIXELFORMAT_UNCOMPRESSED_R16_val);

    // 16*3 bpp (3 channels - half float)
    napi_value PIXELFORMAT_UNCOMPRESSED_R16G16B16_val;
    napi_create_int32(env, 12, &PIXELFORMAT_UNCOMPRESSED_R16G16B16_val);
    napi_set_named_property(env, enumObj, "PIXELFORMAT_UNCOMPRESSED_R16G16B16", PIXELFORMAT_UNCOMPRESSED_R16G16B16_val);

    // 16*4 bpp (4 channels - half float)
    napi_value PIXELFORMAT_UNCOMPRESSED_R16G16B16A16_val;
    napi_create_int32(env, 13, &PIXELFORMAT_UNCOMPRESSED_R16G16B16A16_val);
    napi_set_named_property(env, enumObj, "PIXELFORMAT_UNCOMPRESSED_R16G16B16A16", PIXELFORMAT_UNCOMPRESSED_R16G16B16A16_val);

    // 4 bpp (no alpha)
    napi_value PIXELFORMAT_COMPRESSED_DXT1_RGB_val;
    napi_create_int32(env, 14, &PIXELFORMAT_COMPRESSED_DXT1_RGB_val);
    napi_set_named_property(env, enumObj, "PIXELFORMAT_COMPRESSED_DXT1_RGB", PIXELFORMAT_COMPRESSED_DXT1_RGB_val);

    // 4 bpp (1 bit alpha)
    napi_value PIXELFORMAT_COMPRESSED_DXT1_RGBA_val;
    napi_create_int32(env, 15, &PIXELFORMAT_COMPRESSED_DXT1_RGBA_val);
    napi_set_named_property(env, enumObj, "PIXELFORMAT_COMPRESSED_DXT1_RGBA", PIXELFORMAT_COMPRESSED_DXT1_RGBA_val);

    // 8 bpp
    napi_value PIXELFORMAT_COMPRESSED_DXT3_RGBA_val;
    napi_create_int32(env, 16, &PIXELFORMAT_COMPRESSED_DXT3_RGBA_val);
    napi_set_named_property(env, enumObj, "PIXELFORMAT_COMPRESSED_DXT3_RGBA", PIXELFORMAT_COMPRESSED_DXT3_RGBA_val);

    // 8 bpp
    napi_value PIXELFORMAT_COMPRESSED_DXT5_RGBA_val;
    napi_create_int32(env, 17, &PIXELFORMAT_COMPRESSED_DXT5_RGBA_val);
    napi_set_named_property(env, enumObj, "PIXELFORMAT_COMPRESSED_DXT5_RGBA", PIXELFORMAT_COMPRESSED_DXT5_RGBA_val);

    // 4 bpp
    napi_value PIXELFORMAT_COMPRESSED_ETC1_RGB_val;
    napi_create_int32(env, 18, &PIXELFORMAT_COMPRESSED_ETC1_RGB_val);
    napi_set_named_property(env, enumObj, "PIXELFORMAT_COMPRESSED_ETC1_RGB", PIXELFORMAT_COMPRESSED_ETC1_RGB_val);

    // 4 bpp
    napi_value PIXELFORMAT_COMPRESSED_ETC2_RGB_val;
    napi_create_int32(env, 19, &PIXELFORMAT_COMPRESSED_ETC2_RGB_val);
    napi_set_named_property(env, enumObj, "PIXELFORMAT_COMPRESSED_ETC2_RGB", PIXELFORMAT_COMPRESSED_ETC2_RGB_val);

    // 8 bpp
    napi_value PIXELFORMAT_COMPRESSED_ETC2_EAC_RGBA_val;
    napi_create_int32(env, 20, &PIXELFORMAT_COMPRESSED_ETC2_EAC_RGBA_val);
    napi_set_named_property(env, enumObj, "PIXELFORMAT_COMPRESSED_ETC2_EAC_RGBA", PIXELFORMAT_COMPRESSED_ETC2_EAC_RGBA_val);

    // 4 bpp
    napi_value PIXELFORMAT_COMPRESSED_PVRT_RGB_val;
    napi_create_int32(env, 21, &PIXELFORMAT_COMPRESSED_PVRT_RGB_val);
    napi_set_named_property(env, enumObj, "PIXELFORMAT_COMPRESSED_PVRT_RGB", PIXELFORMAT_COMPRESSED_PVRT_RGB_val);

    // 4 bpp
    napi_value PIXELFORMAT_COMPRESSED_PVRT_RGBA_val;
    napi_create_int32(env, 22, &PIXELFORMAT_COMPRESSED_PVRT_RGBA_val);
    napi_set_named_property(env, enumObj, "PIXELFORMAT_COMPRESSED_PVRT_RGBA", PIXELFORMAT_COMPRESSED_PVRT_RGBA_val);

    // 8 bpp
    napi_value PIXELFORMAT_COMPRESSED_ASTC_4x4_RGBA_val;
    napi_create_int32(env, 23, &PIXELFORMAT_COMPRESSED_ASTC_4x4_RGBA_val);
    napi_set_named_property(env, enumObj, "PIXELFORMAT_COMPRESSED_ASTC_4x4_RGBA", PIXELFORMAT_COMPRESSED_ASTC_4x4_RGBA_val);

    // 2 bpp
    napi_value PIXELFORMAT_COMPRESSED_ASTC_8x8_RGBA_val;
    napi_create_int32(env, 24, &PIXELFORMAT_COMPRESSED_ASTC_8x8_RGBA_val);
    napi_set_named_property(env, enumObj, "PIXELFORMAT_COMPRESSED_ASTC_8x8_RGBA", PIXELFORMAT_COMPRESSED_ASTC_8x8_RGBA_val);

    return enumObj;
}

napi_value Create_TextureFilter(napi_env env) {
    napi_value enumObj;
    napi_create_object(env, &enumObj);

    // No filter, just pixel approximation
    napi_value TEXTURE_FILTER_POINT_val;
    napi_create_int32(env, 0, &TEXTURE_FILTER_POINT_val);
    napi_set_named_property(env, enumObj, "TEXTURE_FILTER_POINT", TEXTURE_FILTER_POINT_val);

    // Linear filtering
    napi_value TEXTURE_FILTER_BILINEAR_val;
    napi_create_int32(env, 1, &TEXTURE_FILTER_BILINEAR_val);
    napi_set_named_property(env, enumObj, "TEXTURE_FILTER_BILINEAR", TEXTURE_FILTER_BILINEAR_val);

    // Trilinear filtering (linear with mipmaps)
    napi_value TEXTURE_FILTER_TRILINEAR_val;
    napi_create_int32(env, 2, &TEXTURE_FILTER_TRILINEAR_val);
    napi_set_named_property(env, enumObj, "TEXTURE_FILTER_TRILINEAR", TEXTURE_FILTER_TRILINEAR_val);

    // Anisotropic filtering 4x
    napi_value TEXTURE_FILTER_ANISOTROPIC_4X_val;
    napi_create_int32(env, 3, &TEXTURE_FILTER_ANISOTROPIC_4X_val);
    napi_set_named_property(env, enumObj, "TEXTURE_FILTER_ANISOTROPIC_4X", TEXTURE_FILTER_ANISOTROPIC_4X_val);

    // Anisotropic filtering 8x
    napi_value TEXTURE_FILTER_ANISOTROPIC_8X_val;
    napi_create_int32(env, 4, &TEXTURE_FILTER_ANISOTROPIC_8X_val);
    napi_set_named_property(env, enumObj, "TEXTURE_FILTER_ANISOTROPIC_8X", TEXTURE_FILTER_ANISOTROPIC_8X_val);

    // Anisotropic filtering 16x
    napi_value TEXTURE_FILTER_ANISOTROPIC_16X_val;
    napi_create_int32(env, 5, &TEXTURE_FILTER_ANISOTROPIC_16X_val);
    napi_set_named_property(env, enumObj, "TEXTURE_FILTER_ANISOTROPIC_16X", TEXTURE_FILTER_ANISOTROPIC_16X_val);

    return enumObj;
}

napi_value Create_TextureWrap(napi_env env) {
    napi_value enumObj;
    napi_create_object(env, &enumObj);

    // Repeats texture in tiled mode
    napi_value TEXTURE_WRAP_REPEAT_val;
    napi_create_int32(env, 0, &TEXTURE_WRAP_REPEAT_val);
    napi_set_named_property(env, enumObj, "TEXTURE_WRAP_REPEAT", TEXTURE_WRAP_REPEAT_val);

    // Clamps texture to edge pixel in tiled mode
    napi_value TEXTURE_WRAP_CLAMP_val;
    napi_create_int32(env, 1, &TEXTURE_WRAP_CLAMP_val);
    napi_set_named_property(env, enumObj, "TEXTURE_WRAP_CLAMP", TEXTURE_WRAP_CLAMP_val);

    // Mirrors and repeats the texture in tiled mode
    napi_value TEXTURE_WRAP_MIRROR_REPEAT_val;
    napi_create_int32(env, 2, &TEXTURE_WRAP_MIRROR_REPEAT_val);
    napi_set_named_property(env, enumObj, "TEXTURE_WRAP_MIRROR_REPEAT", TEXTURE_WRAP_MIRROR_REPEAT_val);

    // Mirrors and clamps to border the texture in tiled mode
    napi_value TEXTURE_WRAP_MIRROR_CLAMP_val;
    napi_create_int32(env, 3, &TEXTURE_WRAP_MIRROR_CLAMP_val);
    napi_set_named_property(env, enumObj, "TEXTURE_WRAP_MIRROR_CLAMP", TEXTURE_WRAP_MIRROR_CLAMP_val);

    return enumObj;
}

napi_value Create_CubemapLayout(napi_env env) {
    napi_value enumObj;
    napi_create_object(env, &enumObj);

    // Automatically detect layout type
    napi_value CUBEMAP_LAYOUT_AUTO_DETECT_val;
    napi_create_int32(env, 0, &CUBEMAP_LAYOUT_AUTO_DETECT_val);
    napi_set_named_property(env, enumObj, "CUBEMAP_LAYOUT_AUTO_DETECT", CUBEMAP_LAYOUT_AUTO_DETECT_val);

    // Layout is defined by a vertical line with faces
    napi_value CUBEMAP_LAYOUT_LINE_VERTICAL_val;
    napi_create_int32(env, 1, &CUBEMAP_LAYOUT_LINE_VERTICAL_val);
    napi_set_named_property(env, enumObj, "CUBEMAP_LAYOUT_LINE_VERTICAL", CUBEMAP_LAYOUT_LINE_VERTICAL_val);

    // Layout is defined by a horizontal line with faces
    napi_value CUBEMAP_LAYOUT_LINE_HORIZONTAL_val;
    napi_create_int32(env, 2, &CUBEMAP_LAYOUT_LINE_HORIZONTAL_val);
    napi_set_named_property(env, enumObj, "CUBEMAP_LAYOUT_LINE_HORIZONTAL", CUBEMAP_LAYOUT_LINE_HORIZONTAL_val);

    // Layout is defined by a 3x4 cross with cubemap faces
    napi_value CUBEMAP_LAYOUT_CROSS_THREE_BY_FOUR_val;
    napi_create_int32(env, 3, &CUBEMAP_LAYOUT_CROSS_THREE_BY_FOUR_val);
    napi_set_named_property(env, enumObj, "CUBEMAP_LAYOUT_CROSS_THREE_BY_FOUR", CUBEMAP_LAYOUT_CROSS_THREE_BY_FOUR_val);

    // Layout is defined by a 4x3 cross with cubemap faces
    napi_value CUBEMAP_LAYOUT_CROSS_FOUR_BY_THREE_val;
    napi_create_int32(env, 4, &CUBEMAP_LAYOUT_CROSS_FOUR_BY_THREE_val);
    napi_set_named_property(env, enumObj, "CUBEMAP_LAYOUT_CROSS_FOUR_BY_THREE", CUBEMAP_LAYOUT_CROSS_FOUR_BY_THREE_val);

    return enumObj;
}

napi_value Create_FontType(napi_env env) {
    napi_value enumObj;
    napi_create_object(env, &enumObj);

    // Default font generation, anti-aliased
    napi_value FONT_DEFAULT_val;
    napi_create_int32(env, 0, &FONT_DEFAULT_val);
    napi_set_named_property(env, enumObj, "FONT_DEFAULT", FONT_DEFAULT_val);

    // Bitmap font generation, no anti-aliasing
    napi_value FONT_BITMAP_val;
    napi_create_int32(env, 1, &FONT_BITMAP_val);
    napi_set_named_property(env, enumObj, "FONT_BITMAP", FONT_BITMAP_val);

    // SDF font generation, requires external shader
    napi_value FONT_SDF_val;
    napi_create_int32(env, 2, &FONT_SDF_val);
    napi_set_named_property(env, enumObj, "FONT_SDF", FONT_SDF_val);

    return enumObj;
}

napi_value Create_BlendMode(napi_env env) {
    napi_value enumObj;
    napi_create_object(env, &enumObj);

    // Blend textures considering alpha (default)
    napi_value BLEND_ALPHA_val;
    napi_create_int32(env, 0, &BLEND_ALPHA_val);
    napi_set_named_property(env, enumObj, "BLEND_ALPHA", BLEND_ALPHA_val);

    // Blend textures adding colors
    napi_value BLEND_ADDITIVE_val;
    napi_create_int32(env, 1, &BLEND_ADDITIVE_val);
    napi_set_named_property(env, enumObj, "BLEND_ADDITIVE", BLEND_ADDITIVE_val);

    // Blend textures multiplying colors
    napi_value BLEND_MULTIPLIED_val;
    napi_create_int32(env, 2, &BLEND_MULTIPLIED_val);
    napi_set_named_property(env, enumObj, "BLEND_MULTIPLIED", BLEND_MULTIPLIED_val);

    // Blend textures adding colors (alternative)
    napi_value BLEND_ADD_COLORS_val;
    napi_create_int32(env, 3, &BLEND_ADD_COLORS_val);
    napi_set_named_property(env, enumObj, "BLEND_ADD_COLORS", BLEND_ADD_COLORS_val);

    // Blend textures subtracting colors (alternative)
    napi_value BLEND_SUBTRACT_COLORS_val;
    napi_create_int32(env, 4, &BLEND_SUBTRACT_COLORS_val);
    napi_set_named_property(env, enumObj, "BLEND_SUBTRACT_COLORS", BLEND_SUBTRACT_COLORS_val);

    // Blend premultiplied textures considering alpha
    napi_value BLEND_ALPHA_PREMULTIPLY_val;
    napi_create_int32(env, 5, &BLEND_ALPHA_PREMULTIPLY_val);
    napi_set_named_property(env, enumObj, "BLEND_ALPHA_PREMULTIPLY", BLEND_ALPHA_PREMULTIPLY_val);

    // Blend textures using custom src/dst factors (use rlSetBlendFactors())
    napi_value BLEND_CUSTOM_val;
    napi_create_int32(env, 6, &BLEND_CUSTOM_val);
    napi_set_named_property(env, enumObj, "BLEND_CUSTOM", BLEND_CUSTOM_val);

    // Blend textures using custom rgb/alpha separate src/dst factors (use rlSetBlendFactorsSeparate())
    napi_value BLEND_CUSTOM_SEPARATE_val;
    napi_create_int32(env, 7, &BLEND_CUSTOM_SEPARATE_val);
    napi_set_named_property(env, enumObj, "BLEND_CUSTOM_SEPARATE", BLEND_CUSTOM_SEPARATE_val);

    return enumObj;
}

napi_value Create_Gesture(napi_env env) {
    napi_value enumObj;
    napi_create_object(env, &enumObj);

    // No gesture
    napi_value GESTURE_NONE_val;
    napi_create_int32(env, 0, &GESTURE_NONE_val);
    napi_set_named_property(env, enumObj, "GESTURE_NONE", GESTURE_NONE_val);

    // Tap gesture
    napi_value GESTURE_TAP_val;
    napi_create_int32(env, 1, &GESTURE_TAP_val);
    napi_set_named_property(env, enumObj, "GESTURE_TAP", GESTURE_TAP_val);

    // Double tap gesture
    napi_value GESTURE_DOUBLETAP_val;
    napi_create_int32(env, 2, &GESTURE_DOUBLETAP_val);
    napi_set_named_property(env, enumObj, "GESTURE_DOUBLETAP", GESTURE_DOUBLETAP_val);

    // Hold gesture
    napi_value GESTURE_HOLD_val;
    napi_create_int32(env, 4, &GESTURE_HOLD_val);
    napi_set_named_property(env, enumObj, "GESTURE_HOLD", GESTURE_HOLD_val);

    // Drag gesture
    napi_value GESTURE_DRAG_val;
    napi_create_int32(env, 8, &GESTURE_DRAG_val);
    napi_set_named_property(env, enumObj, "GESTURE_DRAG", GESTURE_DRAG_val);

    // Swipe right gesture
    napi_value GESTURE_SWIPE_RIGHT_val;
    napi_create_int32(env, 16, &GESTURE_SWIPE_RIGHT_val);
    napi_set_named_property(env, enumObj, "GESTURE_SWIPE_RIGHT", GESTURE_SWIPE_RIGHT_val);

    // Swipe left gesture
    napi_value GESTURE_SWIPE_LEFT_val;
    napi_create_int32(env, 32, &GESTURE_SWIPE_LEFT_val);
    napi_set_named_property(env, enumObj, "GESTURE_SWIPE_LEFT", GESTURE_SWIPE_LEFT_val);

    // Swipe up gesture
    napi_value GESTURE_SWIPE_UP_val;
    napi_create_int32(env, 64, &GESTURE_SWIPE_UP_val);
    napi_set_named_property(env, enumObj, "GESTURE_SWIPE_UP", GESTURE_SWIPE_UP_val);

    // Swipe down gesture
    napi_value GESTURE_SWIPE_DOWN_val;
    napi_create_int32(env, 128, &GESTURE_SWIPE_DOWN_val);
    napi_set_named_property(env, enumObj, "GESTURE_SWIPE_DOWN", GESTURE_SWIPE_DOWN_val);

    // Pinch in gesture
    napi_value GESTURE_PINCH_IN_val;
    napi_create_int32(env, 256, &GESTURE_PINCH_IN_val);
    napi_set_named_property(env, enumObj, "GESTURE_PINCH_IN", GESTURE_PINCH_IN_val);

    // Pinch out gesture
    napi_value GESTURE_PINCH_OUT_val;
    napi_create_int32(env, 512, &GESTURE_PINCH_OUT_val);
    napi_set_named_property(env, enumObj, "GESTURE_PINCH_OUT", GESTURE_PINCH_OUT_val);

    return enumObj;
}

napi_value Create_CameraMode(napi_env env) {
    napi_value enumObj;
    napi_create_object(env, &enumObj);

    // Camera custom, controlled by user (UpdateCamera() does nothing)
    napi_value CAMERA_CUSTOM_val;
    napi_create_int32(env, 0, &CAMERA_CUSTOM_val);
    napi_set_named_property(env, enumObj, "CAMERA_CUSTOM", CAMERA_CUSTOM_val);

    // Camera free mode
    napi_value CAMERA_FREE_val;
    napi_create_int32(env, 1, &CAMERA_FREE_val);
    napi_set_named_property(env, enumObj, "CAMERA_FREE", CAMERA_FREE_val);

    // Camera orbital, around target, zoom supported
    napi_value CAMERA_ORBITAL_val;
    napi_create_int32(env, 2, &CAMERA_ORBITAL_val);
    napi_set_named_property(env, enumObj, "CAMERA_ORBITAL", CAMERA_ORBITAL_val);

    // Camera first person
    napi_value CAMERA_FIRST_PERSON_val;
    napi_create_int32(env, 3, &CAMERA_FIRST_PERSON_val);
    napi_set_named_property(env, enumObj, "CAMERA_FIRST_PERSON", CAMERA_FIRST_PERSON_val);

    // Camera third person
    napi_value CAMERA_THIRD_PERSON_val;
    napi_create_int32(env, 4, &CAMERA_THIRD_PERSON_val);
    napi_set_named_property(env, enumObj, "CAMERA_THIRD_PERSON", CAMERA_THIRD_PERSON_val);

    return enumObj;
}

napi_value Create_CameraProjection(napi_env env) {
    napi_value enumObj;
    napi_create_object(env, &enumObj);

    // Perspective projection
    napi_value CAMERA_PERSPECTIVE_val;
    napi_create_int32(env, 0, &CAMERA_PERSPECTIVE_val);
    napi_set_named_property(env, enumObj, "CAMERA_PERSPECTIVE", CAMERA_PERSPECTIVE_val);

    // Orthographic projection
    napi_value CAMERA_ORTHOGRAPHIC_val;
    napi_create_int32(env, 1, &CAMERA_ORTHOGRAPHIC_val);
    napi_set_named_property(env, enumObj, "CAMERA_ORTHOGRAPHIC", CAMERA_ORTHOGRAPHIC_val);

    return enumObj;
}

napi_value Create_NPatchLayout(napi_env env) {
    napi_value enumObj;
    napi_create_object(env, &enumObj);

    // Npatch layout: 3x3 tiles
    napi_value NPATCH_NINE_PATCH_val;
    napi_create_int32(env, 0, &NPATCH_NINE_PATCH_val);
    napi_set_named_property(env, enumObj, "NPATCH_NINE_PATCH", NPATCH_NINE_PATCH_val);

    // Npatch layout: 1x3 tiles
    napi_value NPATCH_THREE_PATCH_VERTICAL_val;
    napi_create_int32(env, 1, &NPATCH_THREE_PATCH_VERTICAL_val);
    napi_set_named_property(env, enumObj, "NPATCH_THREE_PATCH_VERTICAL", NPATCH_THREE_PATCH_VERTICAL_val);

    // Npatch layout: 3x1 tiles
    napi_value NPATCH_THREE_PATCH_HORIZONTAL_val;
    napi_create_int32(env, 2, &NPATCH_THREE_PATCH_HORIZONTAL_val);
    napi_set_named_property(env, enumObj, "NPATCH_THREE_PATCH_HORIZONTAL", NPATCH_THREE_PATCH_HORIZONTAL_val);

    return enumObj;
}

// Struct conversions
Vector2 Vector2_from_js(napi_env env, napi_value jsObj) {
    Vector2 result;
    napi_value prop;
    bool has_property;

    // Get x
    napi_has_named_property(env, jsObj, "x", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "x", &prop);
        double temp_x;
        napi_get_value_double(env, prop, &temp_x);
        result.x = (float)temp_x;
    } else {
        // Set default value
        result.x = 0;
    }

    // Get y
    napi_has_named_property(env, jsObj, "y", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "y", &prop);
        double temp_y;
        napi_get_value_double(env, prop, &temp_y);
        result.y = (float)temp_y;
    } else {
        // Set default value
        result.y = 0;
    }

    return result;
}

napi_value Vector2_to_js(napi_env env, Vector2 data) {
    napi_value jsObj;
    napi_create_object(env, &jsObj);
    napi_value prop;

    // Set x
    napi_create_double(env, (double)data.x, &prop);
    napi_set_named_property(env, jsObj, "x", prop);

    // Set y
    napi_create_double(env, (double)data.y, &prop);
    napi_set_named_property(env, jsObj, "y", prop);

    return jsObj;
}

Vector3 Vector3_from_js(napi_env env, napi_value jsObj) {
    Vector3 result;
    napi_value prop;
    bool has_property;

    // Get x
    napi_has_named_property(env, jsObj, "x", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "x", &prop);
        double temp_x;
        napi_get_value_double(env, prop, &temp_x);
        result.x = (float)temp_x;
    } else {
        // Set default value
        result.x = 0;
    }

    // Get y
    napi_has_named_property(env, jsObj, "y", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "y", &prop);
        double temp_y;
        napi_get_value_double(env, prop, &temp_y);
        result.y = (float)temp_y;
    } else {
        // Set default value
        result.y = 0;
    }

    // Get z
    napi_has_named_property(env, jsObj, "z", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "z", &prop);
        double temp_z;
        napi_get_value_double(env, prop, &temp_z);
        result.z = (float)temp_z;
    } else {
        // Set default value
        result.z = 0;
    }

    return result;
}

napi_value Vector3_to_js(napi_env env, Vector3 data) {
    napi_value jsObj;
    napi_create_object(env, &jsObj);
    napi_value prop;

    // Set x
    napi_create_double(env, (double)data.x, &prop);
    napi_set_named_property(env, jsObj, "x", prop);

    // Set y
    napi_create_double(env, (double)data.y, &prop);
    napi_set_named_property(env, jsObj, "y", prop);

    // Set z
    napi_create_double(env, (double)data.z, &prop);
    napi_set_named_property(env, jsObj, "z", prop);

    return jsObj;
}

Vector4 Vector4_from_js(napi_env env, napi_value jsObj) {
    Vector4 result;
    napi_value prop;
    bool has_property;

    // Get x
    napi_has_named_property(env, jsObj, "x", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "x", &prop);
        double temp_x;
        napi_get_value_double(env, prop, &temp_x);
        result.x = (float)temp_x;
    } else {
        // Set default value
        result.x = 0;
    }

    // Get y
    napi_has_named_property(env, jsObj, "y", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "y", &prop);
        double temp_y;
        napi_get_value_double(env, prop, &temp_y);
        result.y = (float)temp_y;
    } else {
        // Set default value
        result.y = 0;
    }

    // Get z
    napi_has_named_property(env, jsObj, "z", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "z", &prop);
        double temp_z;
        napi_get_value_double(env, prop, &temp_z);
        result.z = (float)temp_z;
    } else {
        // Set default value
        result.z = 0;
    }

    // Get w
    napi_has_named_property(env, jsObj, "w", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "w", &prop);
        double temp_w;
        napi_get_value_double(env, prop, &temp_w);
        result.w = (float)temp_w;
    } else {
        // Set default value
        result.w = 0;
    }

    return result;
}

napi_value Vector4_to_js(napi_env env, Vector4 data) {
    napi_value jsObj;
    napi_create_object(env, &jsObj);
    napi_value prop;

    // Set x
    napi_create_double(env, (double)data.x, &prop);
    napi_set_named_property(env, jsObj, "x", prop);

    // Set y
    napi_create_double(env, (double)data.y, &prop);
    napi_set_named_property(env, jsObj, "y", prop);

    // Set z
    napi_create_double(env, (double)data.z, &prop);
    napi_set_named_property(env, jsObj, "z", prop);

    // Set w
    napi_create_double(env, (double)data.w, &prop);
    napi_set_named_property(env, jsObj, "w", prop);

    return jsObj;
}

Matrix Matrix_from_js(napi_env env, napi_value jsObj) {
    Matrix result;
    napi_value prop;
    bool has_property;

    // Get m0
    napi_has_named_property(env, jsObj, "m0", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "m0", &prop);
        double temp_m0;
        napi_get_value_double(env, prop, &temp_m0);
        result.m0 = (float)temp_m0;
    } else {
        // Set default value
        result.m0 = 0;
    }

    // Get m4
    napi_has_named_property(env, jsObj, "m4", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "m4", &prop);
        double temp_m4;
        napi_get_value_double(env, prop, &temp_m4);
        result.m4 = (float)temp_m4;
    } else {
        // Set default value
        result.m4 = 0;
    }

    // Get m8
    napi_has_named_property(env, jsObj, "m8", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "m8", &prop);
        double temp_m8;
        napi_get_value_double(env, prop, &temp_m8);
        result.m8 = (float)temp_m8;
    } else {
        // Set default value
        result.m8 = 0;
    }

    // Get m12
    napi_has_named_property(env, jsObj, "m12", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "m12", &prop);
        double temp_m12;
        napi_get_value_double(env, prop, &temp_m12);
        result.m12 = (float)temp_m12;
    } else {
        // Set default value
        result.m12 = 0;
    }

    // Get m1
    napi_has_named_property(env, jsObj, "m1", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "m1", &prop);
        double temp_m1;
        napi_get_value_double(env, prop, &temp_m1);
        result.m1 = (float)temp_m1;
    } else {
        // Set default value
        result.m1 = 0;
    }

    // Get m5
    napi_has_named_property(env, jsObj, "m5", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "m5", &prop);
        double temp_m5;
        napi_get_value_double(env, prop, &temp_m5);
        result.m5 = (float)temp_m5;
    } else {
        // Set default value
        result.m5 = 0;
    }

    // Get m9
    napi_has_named_property(env, jsObj, "m9", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "m9", &prop);
        double temp_m9;
        napi_get_value_double(env, prop, &temp_m9);
        result.m9 = (float)temp_m9;
    } else {
        // Set default value
        result.m9 = 0;
    }

    // Get m13
    napi_has_named_property(env, jsObj, "m13", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "m13", &prop);
        double temp_m13;
        napi_get_value_double(env, prop, &temp_m13);
        result.m13 = (float)temp_m13;
    } else {
        // Set default value
        result.m13 = 0;
    }

    // Get m2
    napi_has_named_property(env, jsObj, "m2", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "m2", &prop);
        double temp_m2;
        napi_get_value_double(env, prop, &temp_m2);
        result.m2 = (float)temp_m2;
    } else {
        // Set default value
        result.m2 = 0;
    }

    // Get m6
    napi_has_named_property(env, jsObj, "m6", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "m6", &prop);
        double temp_m6;
        napi_get_value_double(env, prop, &temp_m6);
        result.m6 = (float)temp_m6;
    } else {
        // Set default value
        result.m6 = 0;
    }

    // Get m10
    napi_has_named_property(env, jsObj, "m10", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "m10", &prop);
        double temp_m10;
        napi_get_value_double(env, prop, &temp_m10);
        result.m10 = (float)temp_m10;
    } else {
        // Set default value
        result.m10 = 0;
    }

    // Get m14
    napi_has_named_property(env, jsObj, "m14", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "m14", &prop);
        double temp_m14;
        napi_get_value_double(env, prop, &temp_m14);
        result.m14 = (float)temp_m14;
    } else {
        // Set default value
        result.m14 = 0;
    }

    // Get m3
    napi_has_named_property(env, jsObj, "m3", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "m3", &prop);
        double temp_m3;
        napi_get_value_double(env, prop, &temp_m3);
        result.m3 = (float)temp_m3;
    } else {
        // Set default value
        result.m3 = 0;
    }

    // Get m7
    napi_has_named_property(env, jsObj, "m7", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "m7", &prop);
        double temp_m7;
        napi_get_value_double(env, prop, &temp_m7);
        result.m7 = (float)temp_m7;
    } else {
        // Set default value
        result.m7 = 0;
    }

    // Get m11
    napi_has_named_property(env, jsObj, "m11", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "m11", &prop);
        double temp_m11;
        napi_get_value_double(env, prop, &temp_m11);
        result.m11 = (float)temp_m11;
    } else {
        // Set default value
        result.m11 = 0;
    }

    // Get m15
    napi_has_named_property(env, jsObj, "m15", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "m15", &prop);
        double temp_m15;
        napi_get_value_double(env, prop, &temp_m15);
        result.m15 = (float)temp_m15;
    } else {
        // Set default value
        result.m15 = 0;
    }

    return result;
}

napi_value Matrix_to_js(napi_env env, Matrix data) {
    napi_value jsObj;
    napi_create_object(env, &jsObj);
    napi_value prop;

    // Set m0
    napi_create_double(env, (double)data.m0, &prop);
    napi_set_named_property(env, jsObj, "m0", prop);

    // Set m4
    napi_create_double(env, (double)data.m4, &prop);
    napi_set_named_property(env, jsObj, "m4", prop);

    // Set m8
    napi_create_double(env, (double)data.m8, &prop);
    napi_set_named_property(env, jsObj, "m8", prop);

    // Set m12
    napi_create_double(env, (double)data.m12, &prop);
    napi_set_named_property(env, jsObj, "m12", prop);

    // Set m1
    napi_create_double(env, (double)data.m1, &prop);
    napi_set_named_property(env, jsObj, "m1", prop);

    // Set m5
    napi_create_double(env, (double)data.m5, &prop);
    napi_set_named_property(env, jsObj, "m5", prop);

    // Set m9
    napi_create_double(env, (double)data.m9, &prop);
    napi_set_named_property(env, jsObj, "m9", prop);

    // Set m13
    napi_create_double(env, (double)data.m13, &prop);
    napi_set_named_property(env, jsObj, "m13", prop);

    // Set m2
    napi_create_double(env, (double)data.m2, &prop);
    napi_set_named_property(env, jsObj, "m2", prop);

    // Set m6
    napi_create_double(env, (double)data.m6, &prop);
    napi_set_named_property(env, jsObj, "m6", prop);

    // Set m10
    napi_create_double(env, (double)data.m10, &prop);
    napi_set_named_property(env, jsObj, "m10", prop);

    // Set m14
    napi_create_double(env, (double)data.m14, &prop);
    napi_set_named_property(env, jsObj, "m14", prop);

    // Set m3
    napi_create_double(env, (double)data.m3, &prop);
    napi_set_named_property(env, jsObj, "m3", prop);

    // Set m7
    napi_create_double(env, (double)data.m7, &prop);
    napi_set_named_property(env, jsObj, "m7", prop);

    // Set m11
    napi_create_double(env, (double)data.m11, &prop);
    napi_set_named_property(env, jsObj, "m11", prop);

    // Set m15
    napi_create_double(env, (double)data.m15, &prop);
    napi_set_named_property(env, jsObj, "m15", prop);

    return jsObj;
}

Color Color_from_js(napi_env env, napi_value jsObj) {
    Color result;
    napi_value prop;
    bool has_property;

    // Get r
    napi_has_named_property(env, jsObj, "r", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "r", &prop);
        int32_t temp_r;
        napi_get_value_int32(env, prop, &temp_r);
        result.r = (unsigned char)temp_r;
    } else {
        // Set default value
        result.r = 0;
    }

    // Get g
    napi_has_named_property(env, jsObj, "g", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "g", &prop);
        int32_t temp_g;
        napi_get_value_int32(env, prop, &temp_g);
        result.g = (unsigned char)temp_g;
    } else {
        // Set default value
        result.g = 0;
    }

    // Get b
    napi_has_named_property(env, jsObj, "b", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "b", &prop);
        int32_t temp_b;
        napi_get_value_int32(env, prop, &temp_b);
        result.b = (unsigned char)temp_b;
    } else {
        // Set default value
        result.b = 0;
    }

    // Get a
    napi_has_named_property(env, jsObj, "a", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "a", &prop);
        int32_t temp_a;
        napi_get_value_int32(env, prop, &temp_a);
        result.a = (unsigned char)temp_a;
    } else {
        // Set default value
        result.a = 0;
    }

    return result;
}

napi_value Color_to_js(napi_env env, Color data) {
    napi_value jsObj;
    napi_create_object(env, &jsObj);
    napi_value prop;

    // Set r
    napi_create_int32(env, (int32_t)data.r, &prop);
    napi_set_named_property(env, jsObj, "r", prop);

    // Set g
    napi_create_int32(env, (int32_t)data.g, &prop);
    napi_set_named_property(env, jsObj, "g", prop);

    // Set b
    napi_create_int32(env, (int32_t)data.b, &prop);
    napi_set_named_property(env, jsObj, "b", prop);

    // Set a
    napi_create_int32(env, (int32_t)data.a, &prop);
    napi_set_named_property(env, jsObj, "a", prop);

    return jsObj;
}

Rectangle Rectangle_from_js(napi_env env, napi_value jsObj) {
    Rectangle result;
    napi_value prop;
    bool has_property;

    // Get x
    napi_has_named_property(env, jsObj, "x", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "x", &prop);
        double temp_x;
        napi_get_value_double(env, prop, &temp_x);
        result.x = (float)temp_x;
    } else {
        // Set default value
        result.x = 0;
    }

    // Get y
    napi_has_named_property(env, jsObj, "y", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "y", &prop);
        double temp_y;
        napi_get_value_double(env, prop, &temp_y);
        result.y = (float)temp_y;
    } else {
        // Set default value
        result.y = 0;
    }

    // Get width
    napi_has_named_property(env, jsObj, "width", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "width", &prop);
        double temp_width;
        napi_get_value_double(env, prop, &temp_width);
        result.width = (float)temp_width;
    } else {
        // Set default value
        result.width = 0;
    }

    // Get height
    napi_has_named_property(env, jsObj, "height", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "height", &prop);
        double temp_height;
        napi_get_value_double(env, prop, &temp_height);
        result.height = (float)temp_height;
    } else {
        // Set default value
        result.height = 0;
    }

    return result;
}

napi_value Rectangle_to_js(napi_env env, Rectangle data) {
    napi_value jsObj;
    napi_create_object(env, &jsObj);
    napi_value prop;

    // Set x
    napi_create_double(env, (double)data.x, &prop);
    napi_set_named_property(env, jsObj, "x", prop);

    // Set y
    napi_create_double(env, (double)data.y, &prop);
    napi_set_named_property(env, jsObj, "y", prop);

    // Set width
    napi_create_double(env, (double)data.width, &prop);
    napi_set_named_property(env, jsObj, "width", prop);

    // Set height
    napi_create_double(env, (double)data.height, &prop);
    napi_set_named_property(env, jsObj, "height", prop);

    return jsObj;
}

Image Image_from_js(napi_env env, napi_value jsObj) {
    Image result;
    napi_value prop;
    bool has_property;

    // Get data
    napi_has_named_property(env, jsObj, "data", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "data", &prop);
        // TODO: Handle field type void *
    } else {
        // Set default value
        // TODO: Set default for void *
        memset(&result.data, 0, sizeof(result.data));
    }

    // Get width
    napi_has_named_property(env, jsObj, "width", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "width", &prop);
        napi_get_value_int32(env, prop, (int32_t*)&result.width);
    } else {
        // Set default value
        result.width = 0;
    }

    // Get height
    napi_has_named_property(env, jsObj, "height", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "height", &prop);
        napi_get_value_int32(env, prop, (int32_t*)&result.height);
    } else {
        // Set default value
        result.height = 0;
    }

    // Get mipmaps
    napi_has_named_property(env, jsObj, "mipmaps", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "mipmaps", &prop);
        napi_get_value_int32(env, prop, (int32_t*)&result.mipmaps);
    } else {
        // Set default value
        result.mipmaps = 0;
    }

    // Get format
    napi_has_named_property(env, jsObj, "format", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "format", &prop);
        napi_get_value_int32(env, prop, (int32_t*)&result.format);
    } else {
        // Set default value
        result.format = 0;
    }

    return result;
}

napi_value Image_to_js(napi_env env, Image data) {
    napi_value jsObj;
    napi_create_object(env, &jsObj);
    napi_value prop;

    // Set data
    // TODO: Handle field type void *
    napi_get_null(env, &prop);
    napi_set_named_property(env, jsObj, "data", prop);

    // Set width
    napi_create_int32(env, (int32_t)data.width, &prop);
    napi_set_named_property(env, jsObj, "width", prop);

    // Set height
    napi_create_int32(env, (int32_t)data.height, &prop);
    napi_set_named_property(env, jsObj, "height", prop);

    // Set mipmaps
    napi_create_int32(env, (int32_t)data.mipmaps, &prop);
    napi_set_named_property(env, jsObj, "mipmaps", prop);

    // Set format
    napi_create_int32(env, (int32_t)data.format, &prop);
    napi_set_named_property(env, jsObj, "format", prop);

    return jsObj;
}

Texture Texture_from_js(napi_env env, napi_value jsObj) {
    Texture result;
    napi_value prop;
    bool has_property;

    // Get id
    napi_has_named_property(env, jsObj, "id", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "id", &prop);
        napi_get_value_int32(env, prop, (int32_t*)&result.id);
    } else {
        // Set default value
        result.id = 0;
    }

    // Get width
    napi_has_named_property(env, jsObj, "width", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "width", &prop);
        napi_get_value_int32(env, prop, (int32_t*)&result.width);
    } else {
        // Set default value
        result.width = 0;
    }

    // Get height
    napi_has_named_property(env, jsObj, "height", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "height", &prop);
        napi_get_value_int32(env, prop, (int32_t*)&result.height);
    } else {
        // Set default value
        result.height = 0;
    }

    // Get mipmaps
    napi_has_named_property(env, jsObj, "mipmaps", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "mipmaps", &prop);
        napi_get_value_int32(env, prop, (int32_t*)&result.mipmaps);
    } else {
        // Set default value
        result.mipmaps = 0;
    }

    // Get format
    napi_has_named_property(env, jsObj, "format", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "format", &prop);
        napi_get_value_int32(env, prop, (int32_t*)&result.format);
    } else {
        // Set default value
        result.format = 0;
    }

    return result;
}

napi_value Texture_to_js(napi_env env, Texture data) {
    napi_value jsObj;
    napi_create_object(env, &jsObj);
    napi_value prop;

    // Set id
    napi_create_int32(env, (int32_t)data.id, &prop);
    napi_set_named_property(env, jsObj, "id", prop);

    // Set width
    napi_create_int32(env, (int32_t)data.width, &prop);
    napi_set_named_property(env, jsObj, "width", prop);

    // Set height
    napi_create_int32(env, (int32_t)data.height, &prop);
    napi_set_named_property(env, jsObj, "height", prop);

    // Set mipmaps
    napi_create_int32(env, (int32_t)data.mipmaps, &prop);
    napi_set_named_property(env, jsObj, "mipmaps", prop);

    // Set format
    napi_create_int32(env, (int32_t)data.format, &prop);
    napi_set_named_property(env, jsObj, "format", prop);

    return jsObj;
}

RenderTexture RenderTexture_from_js(napi_env env, napi_value jsObj) {
    RenderTexture result;
    napi_value prop;
    bool has_property;

    // Get id
    napi_has_named_property(env, jsObj, "id", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "id", &prop);
        napi_get_value_int32(env, prop, (int32_t*)&result.id);
    } else {
        // Set default value
        result.id = 0;
    }

    // Get texture
    napi_has_named_property(env, jsObj, "texture", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "texture", &prop);
        result.texture = Texture_from_js(env, prop);
    } else {
        // Set default value
        // TODO: Set default for Texture
        memset(&result.texture, 0, sizeof(result.texture));
    }

    // Get depth
    napi_has_named_property(env, jsObj, "depth", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "depth", &prop);
        result.depth = Texture_from_js(env, prop);
    } else {
        // Set default value
        // TODO: Set default for Texture
        memset(&result.depth, 0, sizeof(result.depth));
    }

    return result;
}

napi_value RenderTexture_to_js(napi_env env, RenderTexture data) {
    napi_value jsObj;
    napi_create_object(env, &jsObj);
    napi_value prop;

    // Set id
    napi_create_int32(env, (int32_t)data.id, &prop);
    napi_set_named_property(env, jsObj, "id", prop);

    // Set texture
    prop = Texture_to_js(env, data.texture);
    napi_set_named_property(env, jsObj, "texture", prop);

    // Set depth
    prop = Texture_to_js(env, data.depth);
    napi_set_named_property(env, jsObj, "depth", prop);

    return jsObj;
}

NPatchInfo NPatchInfo_from_js(napi_env env, napi_value jsObj) {
    NPatchInfo result;
    napi_value prop;
    bool has_property;

    // Get source
    napi_has_named_property(env, jsObj, "source", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "source", &prop);
        result.source = Rectangle_from_js(env, prop);
    } else {
        // Set default value
        // TODO: Set default for Rectangle
        memset(&result.source, 0, sizeof(result.source));
    }

    // Get left
    napi_has_named_property(env, jsObj, "left", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "left", &prop);
        napi_get_value_int32(env, prop, (int32_t*)&result.left);
    } else {
        // Set default value
        result.left = 0;
    }

    // Get top
    napi_has_named_property(env, jsObj, "top", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "top", &prop);
        napi_get_value_int32(env, prop, (int32_t*)&result.top);
    } else {
        // Set default value
        result.top = 0;
    }

    // Get right
    napi_has_named_property(env, jsObj, "right", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "right", &prop);
        napi_get_value_int32(env, prop, (int32_t*)&result.right);
    } else {
        // Set default value
        result.right = 0;
    }

    // Get bottom
    napi_has_named_property(env, jsObj, "bottom", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "bottom", &prop);
        napi_get_value_int32(env, prop, (int32_t*)&result.bottom);
    } else {
        // Set default value
        result.bottom = 0;
    }

    // Get layout
    napi_has_named_property(env, jsObj, "layout", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "layout", &prop);
        napi_get_value_int32(env, prop, (int32_t*)&result.layout);
    } else {
        // Set default value
        result.layout = 0;
    }

    return result;
}

napi_value NPatchInfo_to_js(napi_env env, NPatchInfo data) {
    napi_value jsObj;
    napi_create_object(env, &jsObj);
    napi_value prop;

    // Set source
    prop = Rectangle_to_js(env, data.source);
    napi_set_named_property(env, jsObj, "source", prop);

    // Set left
    napi_create_int32(env, (int32_t)data.left, &prop);
    napi_set_named_property(env, jsObj, "left", prop);

    // Set top
    napi_create_int32(env, (int32_t)data.top, &prop);
    napi_set_named_property(env, jsObj, "top", prop);

    // Set right
    napi_create_int32(env, (int32_t)data.right, &prop);
    napi_set_named_property(env, jsObj, "right", prop);

    // Set bottom
    napi_create_int32(env, (int32_t)data.bottom, &prop);
    napi_set_named_property(env, jsObj, "bottom", prop);

    // Set layout
    napi_create_int32(env, (int32_t)data.layout, &prop);
    napi_set_named_property(env, jsObj, "layout", prop);

    return jsObj;
}

GlyphInfo GlyphInfo_from_js(napi_env env, napi_value jsObj) {
    GlyphInfo result;
    napi_value prop;
    bool has_property;

    // Get value
    napi_has_named_property(env, jsObj, "value", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "value", &prop);
        napi_get_value_int32(env, prop, (int32_t*)&result.value);
    } else {
        // Set default value
        result.value = 0;
    }

    // Get offsetX
    napi_has_named_property(env, jsObj, "offsetX", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "offsetX", &prop);
        napi_get_value_int32(env, prop, (int32_t*)&result.offsetX);
    } else {
        // Set default value
        result.offsetX = 0;
    }

    // Get offsetY
    napi_has_named_property(env, jsObj, "offsetY", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "offsetY", &prop);
        napi_get_value_int32(env, prop, (int32_t*)&result.offsetY);
    } else {
        // Set default value
        result.offsetY = 0;
    }

    // Get advanceX
    napi_has_named_property(env, jsObj, "advanceX", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "advanceX", &prop);
        napi_get_value_int32(env, prop, (int32_t*)&result.advanceX);
    } else {
        // Set default value
        result.advanceX = 0;
    }

    // Get image
    napi_has_named_property(env, jsObj, "image", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "image", &prop);
        result.image = Image_from_js(env, prop);
    } else {
        // Set default value
        // TODO: Set default for Image
        memset(&result.image, 0, sizeof(result.image));
    }

    return result;
}

napi_value GlyphInfo_to_js(napi_env env, GlyphInfo data) {
    napi_value jsObj;
    napi_create_object(env, &jsObj);
    napi_value prop;

    // Set value
    napi_create_int32(env, (int32_t)data.value, &prop);
    napi_set_named_property(env, jsObj, "value", prop);

    // Set offsetX
    napi_create_int32(env, (int32_t)data.offsetX, &prop);
    napi_set_named_property(env, jsObj, "offsetX", prop);

    // Set offsetY
    napi_create_int32(env, (int32_t)data.offsetY, &prop);
    napi_set_named_property(env, jsObj, "offsetY", prop);

    // Set advanceX
    napi_create_int32(env, (int32_t)data.advanceX, &prop);
    napi_set_named_property(env, jsObj, "advanceX", prop);

    // Set image
    prop = Image_to_js(env, data.image);
    napi_set_named_property(env, jsObj, "image", prop);

    return jsObj;
}

Font Font_from_js(napi_env env, napi_value jsObj) {
    Font result;
    napi_value prop;
    bool has_property;

    // Get baseSize
    napi_has_named_property(env, jsObj, "baseSize", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "baseSize", &prop);
        napi_get_value_int32(env, prop, (int32_t*)&result.baseSize);
    } else {
        // Set default value
        result.baseSize = 0;
    }

    // Get glyphCount
    napi_has_named_property(env, jsObj, "glyphCount", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "glyphCount", &prop);
        napi_get_value_int32(env, prop, (int32_t*)&result.glyphCount);
    } else {
        // Set default value
        result.glyphCount = 0;
    }

    // Get glyphPadding
    napi_has_named_property(env, jsObj, "glyphPadding", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "glyphPadding", &prop);
        napi_get_value_int32(env, prop, (int32_t*)&result.glyphPadding);
    } else {
        // Set default value
        result.glyphPadding = 0;
    }

    // Get texture
    napi_has_named_property(env, jsObj, "texture", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "texture", &prop);
        // TODO: Handle field type Texture2D
    } else {
        // Set default value
        // TODO: Set default for Texture2D
        memset(&result.texture, 0, sizeof(result.texture));
    }

    // Get recs
    napi_has_named_property(env, jsObj, "recs", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "recs", &prop);
        // TODO: Handle field type Rectangle *
    } else {
        // Set default value
        // TODO: Set default for Rectangle *
        memset(&result.recs, 0, sizeof(result.recs));
    }

    // Get glyphs
    napi_has_named_property(env, jsObj, "glyphs", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "glyphs", &prop);
        // TODO: Handle field type GlyphInfo *
    } else {
        // Set default value
        // TODO: Set default for GlyphInfo *
        memset(&result.glyphs, 0, sizeof(result.glyphs));
    }

    return result;
}

napi_value Font_to_js(napi_env env, Font data) {
    napi_value jsObj;
    napi_create_object(env, &jsObj);
    napi_value prop;

    // Set baseSize
    napi_create_int32(env, (int32_t)data.baseSize, &prop);
    napi_set_named_property(env, jsObj, "baseSize", prop);

    // Set glyphCount
    napi_create_int32(env, (int32_t)data.glyphCount, &prop);
    napi_set_named_property(env, jsObj, "glyphCount", prop);

    // Set glyphPadding
    napi_create_int32(env, (int32_t)data.glyphPadding, &prop);
    napi_set_named_property(env, jsObj, "glyphPadding", prop);

    // Set texture
    // TODO: Handle field type Texture2D
    napi_get_null(env, &prop);
    napi_set_named_property(env, jsObj, "texture", prop);

    // Set recs
    // TODO: Handle field type Rectangle *
    napi_get_null(env, &prop);
    napi_set_named_property(env, jsObj, "recs", prop);

    // Set glyphs
    // TODO: Handle field type GlyphInfo *
    napi_get_null(env, &prop);
    napi_set_named_property(env, jsObj, "glyphs", prop);

    return jsObj;
}

Camera3D Camera3D_from_js(napi_env env, napi_value jsObj) {
    Camera3D result;
    napi_value prop;
    bool has_property;

    // Get position
    napi_has_named_property(env, jsObj, "position", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "position", &prop);
        result.position = Vector3_from_js(env, prop);
    } else {
        // Set default value
        // TODO: Set default for Vector3
        memset(&result.position, 0, sizeof(result.position));
    }

    // Get target
    napi_has_named_property(env, jsObj, "target", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "target", &prop);
        result.target = Vector3_from_js(env, prop);
    } else {
        // Set default value
        // TODO: Set default for Vector3
        memset(&result.target, 0, sizeof(result.target));
    }

    // Get up
    napi_has_named_property(env, jsObj, "up", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "up", &prop);
        result.up = Vector3_from_js(env, prop);
    } else {
        // Set default value
        // TODO: Set default for Vector3
        memset(&result.up, 0, sizeof(result.up));
    }

    // Get fovy
    napi_has_named_property(env, jsObj, "fovy", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "fovy", &prop);
        double temp_fovy;
        napi_get_value_double(env, prop, &temp_fovy);
        result.fovy = (float)temp_fovy;
    } else {
        // Set default value
        result.fovy = 0;
    }

    // Get projection
    napi_has_named_property(env, jsObj, "projection", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "projection", &prop);
        napi_get_value_int32(env, prop, (int32_t*)&result.projection);
    } else {
        // Set default value
        result.projection = 0;
    }

    return result;
}

napi_value Camera3D_to_js(napi_env env, Camera3D data) {
    napi_value jsObj;
    napi_create_object(env, &jsObj);
    napi_value prop;

    // Set position
    prop = Vector3_to_js(env, data.position);
    napi_set_named_property(env, jsObj, "position", prop);

    // Set target
    prop = Vector3_to_js(env, data.target);
    napi_set_named_property(env, jsObj, "target", prop);

    // Set up
    prop = Vector3_to_js(env, data.up);
    napi_set_named_property(env, jsObj, "up", prop);

    // Set fovy
    napi_create_double(env, (double)data.fovy, &prop);
    napi_set_named_property(env, jsObj, "fovy", prop);

    // Set projection
    napi_create_int32(env, (int32_t)data.projection, &prop);
    napi_set_named_property(env, jsObj, "projection", prop);

    return jsObj;
}

Camera2D Camera2D_from_js(napi_env env, napi_value jsObj) {
    Camera2D result;
    napi_value prop;
    bool has_property;

    // Get offset
    napi_has_named_property(env, jsObj, "offset", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "offset", &prop);
        result.offset = Vector2_from_js(env, prop);
    } else {
        // Set default value
        // TODO: Set default for Vector2
        memset(&result.offset, 0, sizeof(result.offset));
    }

    // Get target
    napi_has_named_property(env, jsObj, "target", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "target", &prop);
        result.target = Vector2_from_js(env, prop);
    } else {
        // Set default value
        // TODO: Set default for Vector2
        memset(&result.target, 0, sizeof(result.target));
    }

    // Get rotation
    napi_has_named_property(env, jsObj, "rotation", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "rotation", &prop);
        double temp_rotation;
        napi_get_value_double(env, prop, &temp_rotation);
        result.rotation = (float)temp_rotation;
    } else {
        // Set default value
        result.rotation = 0;
    }

    // Get zoom
    napi_has_named_property(env, jsObj, "zoom", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "zoom", &prop);
        double temp_zoom;
        napi_get_value_double(env, prop, &temp_zoom);
        result.zoom = (float)temp_zoom;
    } else {
        // Set default value
        result.zoom = 0;
    }

    return result;
}

napi_value Camera2D_to_js(napi_env env, Camera2D data) {
    napi_value jsObj;
    napi_create_object(env, &jsObj);
    napi_value prop;

    // Set offset
    prop = Vector2_to_js(env, data.offset);
    napi_set_named_property(env, jsObj, "offset", prop);

    // Set target
    prop = Vector2_to_js(env, data.target);
    napi_set_named_property(env, jsObj, "target", prop);

    // Set rotation
    napi_create_double(env, (double)data.rotation, &prop);
    napi_set_named_property(env, jsObj, "rotation", prop);

    // Set zoom
    napi_create_double(env, (double)data.zoom, &prop);
    napi_set_named_property(env, jsObj, "zoom", prop);

    return jsObj;
}

Mesh Mesh_from_js(napi_env env, napi_value jsObj) {
    Mesh result;
    napi_value prop;
    bool has_property;

    // Get vertexCount
    napi_has_named_property(env, jsObj, "vertexCount", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "vertexCount", &prop);
        napi_get_value_int32(env, prop, (int32_t*)&result.vertexCount);
    } else {
        // Set default value
        result.vertexCount = 0;
    }

    // Get triangleCount
    napi_has_named_property(env, jsObj, "triangleCount", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "triangleCount", &prop);
        napi_get_value_int32(env, prop, (int32_t*)&result.triangleCount);
    } else {
        // Set default value
        result.triangleCount = 0;
    }

    // Get vertices
    napi_has_named_property(env, jsObj, "vertices", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "vertices", &prop);
        // TODO: Handle field type float *
    } else {
        // Set default value
        // TODO: Set default for float *
        memset(&result.vertices, 0, sizeof(result.vertices));
    }

    // Get texcoords
    napi_has_named_property(env, jsObj, "texcoords", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "texcoords", &prop);
        // TODO: Handle field type float *
    } else {
        // Set default value
        // TODO: Set default for float *
        memset(&result.texcoords, 0, sizeof(result.texcoords));
    }

    // Get texcoords2
    napi_has_named_property(env, jsObj, "texcoords2", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "texcoords2", &prop);
        // TODO: Handle field type float *
    } else {
        // Set default value
        // TODO: Set default for float *
        memset(&result.texcoords2, 0, sizeof(result.texcoords2));
    }

    // Get normals
    napi_has_named_property(env, jsObj, "normals", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "normals", &prop);
        // TODO: Handle field type float *
    } else {
        // Set default value
        // TODO: Set default for float *
        memset(&result.normals, 0, sizeof(result.normals));
    }

    // Get tangents
    napi_has_named_property(env, jsObj, "tangents", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "tangents", &prop);
        // TODO: Handle field type float *
    } else {
        // Set default value
        // TODO: Set default for float *
        memset(&result.tangents, 0, sizeof(result.tangents));
    }

    // Get colors
    napi_has_named_property(env, jsObj, "colors", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "colors", &prop);
        // TODO: Handle field type unsigned char *
    } else {
        // Set default value
        // TODO: Set default for unsigned char *
        memset(&result.colors, 0, sizeof(result.colors));
    }

    // Get indices
    napi_has_named_property(env, jsObj, "indices", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "indices", &prop);
        // TODO: Handle field type unsigned short *
    } else {
        // Set default value
        // TODO: Set default for unsigned short *
        memset(&result.indices, 0, sizeof(result.indices));
    }

    // Get animVertices
    napi_has_named_property(env, jsObj, "animVertices", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "animVertices", &prop);
        // TODO: Handle field type float *
    } else {
        // Set default value
        // TODO: Set default for float *
        memset(&result.animVertices, 0, sizeof(result.animVertices));
    }

    // Get animNormals
    napi_has_named_property(env, jsObj, "animNormals", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "animNormals", &prop);
        // TODO: Handle field type float *
    } else {
        // Set default value
        // TODO: Set default for float *
        memset(&result.animNormals, 0, sizeof(result.animNormals));
    }

    // Get boneIds
    napi_has_named_property(env, jsObj, "boneIds", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "boneIds", &prop);
        // TODO: Handle field type unsigned char *
    } else {
        // Set default value
        // TODO: Set default for unsigned char *
        memset(&result.boneIds, 0, sizeof(result.boneIds));
    }

    // Get boneWeights
    napi_has_named_property(env, jsObj, "boneWeights", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "boneWeights", &prop);
        // TODO: Handle field type float *
    } else {
        // Set default value
        // TODO: Set default for float *
        memset(&result.boneWeights, 0, sizeof(result.boneWeights));
    }

    // Get boneMatrices
    napi_has_named_property(env, jsObj, "boneMatrices", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "boneMatrices", &prop);
        // TODO: Handle field type Matrix *
    } else {
        // Set default value
        // TODO: Set default for Matrix *
        memset(&result.boneMatrices, 0, sizeof(result.boneMatrices));
    }

    // Get boneCount
    napi_has_named_property(env, jsObj, "boneCount", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "boneCount", &prop);
        napi_get_value_int32(env, prop, (int32_t*)&result.boneCount);
    } else {
        // Set default value
        result.boneCount = 0;
    }

    // Get vaoId
    napi_has_named_property(env, jsObj, "vaoId", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "vaoId", &prop);
        napi_get_value_int32(env, prop, (int32_t*)&result.vaoId);
    } else {
        // Set default value
        result.vaoId = 0;
    }

    // Get vboId
    napi_has_named_property(env, jsObj, "vboId", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "vboId", &prop);
        // TODO: Handle field type unsigned int *
    } else {
        // Set default value
        // TODO: Set default for unsigned int *
        memset(&result.vboId, 0, sizeof(result.vboId));
    }

    return result;
}

napi_value Mesh_to_js(napi_env env, Mesh data) {
    napi_value jsObj;
    napi_create_object(env, &jsObj);
    napi_value prop;

    // Set vertexCount
    napi_create_int32(env, (int32_t)data.vertexCount, &prop);
    napi_set_named_property(env, jsObj, "vertexCount", prop);

    // Set triangleCount
    napi_create_int32(env, (int32_t)data.triangleCount, &prop);
    napi_set_named_property(env, jsObj, "triangleCount", prop);

    // Set vertices
    // TODO: Handle field type float *
    napi_get_null(env, &prop);
    napi_set_named_property(env, jsObj, "vertices", prop);

    // Set texcoords
    // TODO: Handle field type float *
    napi_get_null(env, &prop);
    napi_set_named_property(env, jsObj, "texcoords", prop);

    // Set texcoords2
    // TODO: Handle field type float *
    napi_get_null(env, &prop);
    napi_set_named_property(env, jsObj, "texcoords2", prop);

    // Set normals
    // TODO: Handle field type float *
    napi_get_null(env, &prop);
    napi_set_named_property(env, jsObj, "normals", prop);

    // Set tangents
    // TODO: Handle field type float *
    napi_get_null(env, &prop);
    napi_set_named_property(env, jsObj, "tangents", prop);

    // Set colors
    // TODO: Handle field type unsigned char *
    napi_get_null(env, &prop);
    napi_set_named_property(env, jsObj, "colors", prop);

    // Set indices
    // TODO: Handle field type unsigned short *
    napi_get_null(env, &prop);
    napi_set_named_property(env, jsObj, "indices", prop);

    // Set animVertices
    // TODO: Handle field type float *
    napi_get_null(env, &prop);
    napi_set_named_property(env, jsObj, "animVertices", prop);

    // Set animNormals
    // TODO: Handle field type float *
    napi_get_null(env, &prop);
    napi_set_named_property(env, jsObj, "animNormals", prop);

    // Set boneIds
    // TODO: Handle field type unsigned char *
    napi_get_null(env, &prop);
    napi_set_named_property(env, jsObj, "boneIds", prop);

    // Set boneWeights
    // TODO: Handle field type float *
    napi_get_null(env, &prop);
    napi_set_named_property(env, jsObj, "boneWeights", prop);

    // Set boneMatrices
    // TODO: Handle field type Matrix *
    napi_get_null(env, &prop);
    napi_set_named_property(env, jsObj, "boneMatrices", prop);

    // Set boneCount
    napi_create_int32(env, (int32_t)data.boneCount, &prop);
    napi_set_named_property(env, jsObj, "boneCount", prop);

    // Set vaoId
    napi_create_int32(env, (int32_t)data.vaoId, &prop);
    napi_set_named_property(env, jsObj, "vaoId", prop);

    // Set vboId
    // TODO: Handle field type unsigned int *
    napi_get_null(env, &prop);
    napi_set_named_property(env, jsObj, "vboId", prop);

    return jsObj;
}

Shader Shader_from_js(napi_env env, napi_value jsObj) {
    Shader result;
    napi_value prop;
    bool has_property;

    // Get id
    napi_has_named_property(env, jsObj, "id", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "id", &prop);
        napi_get_value_int32(env, prop, (int32_t*)&result.id);
    } else {
        // Set default value
        result.id = 0;
    }

    // Get locs
    napi_has_named_property(env, jsObj, "locs", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "locs", &prop);
        // TODO: Handle field type int *
    } else {
        // Set default value
        // TODO: Set default for int *
        memset(&result.locs, 0, sizeof(result.locs));
    }

    return result;
}

napi_value Shader_to_js(napi_env env, Shader data) {
    napi_value jsObj;
    napi_create_object(env, &jsObj);
    napi_value prop;

    // Set id
    napi_create_int32(env, (int32_t)data.id, &prop);
    napi_set_named_property(env, jsObj, "id", prop);

    // Set locs
    // TODO: Handle field type int *
    napi_get_null(env, &prop);
    napi_set_named_property(env, jsObj, "locs", prop);

    return jsObj;
}

MaterialMap MaterialMap_from_js(napi_env env, napi_value jsObj) {
    MaterialMap result;
    napi_value prop;
    bool has_property;

    // Get texture
    napi_has_named_property(env, jsObj, "texture", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "texture", &prop);
        // TODO: Handle field type Texture2D
    } else {
        // Set default value
        // TODO: Set default for Texture2D
        memset(&result.texture, 0, sizeof(result.texture));
    }

    // Get color
    napi_has_named_property(env, jsObj, "color", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "color", &prop);
        result.color = Color_from_js(env, prop);
    } else {
        // Set default value
        // TODO: Set default for Color
        memset(&result.color, 0, sizeof(result.color));
    }

    // Get value
    napi_has_named_property(env, jsObj, "value", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "value", &prop);
        double temp_value;
        napi_get_value_double(env, prop, &temp_value);
        result.value = (float)temp_value;
    } else {
        // Set default value
        result.value = 0;
    }

    return result;
}

napi_value MaterialMap_to_js(napi_env env, MaterialMap data) {
    napi_value jsObj;
    napi_create_object(env, &jsObj);
    napi_value prop;

    // Set texture
    // TODO: Handle field type Texture2D
    napi_get_null(env, &prop);
    napi_set_named_property(env, jsObj, "texture", prop);

    // Set color
    prop = Color_to_js(env, data.color);
    napi_set_named_property(env, jsObj, "color", prop);

    // Set value
    napi_create_double(env, (double)data.value, &prop);
    napi_set_named_property(env, jsObj, "value", prop);

    return jsObj;
}

Material Material_from_js(napi_env env, napi_value jsObj) {
    Material result;
    napi_value prop;
    bool has_property;

    // Get shader
    napi_has_named_property(env, jsObj, "shader", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "shader", &prop);
        result.shader = Shader_from_js(env, prop);
    } else {
        // Set default value
        // TODO: Set default for Shader
        memset(&result.shader, 0, sizeof(result.shader));
    }

    // Get maps
    napi_has_named_property(env, jsObj, "maps", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "maps", &prop);
        // TODO: Handle field type MaterialMap *
    } else {
        // Set default value
        // TODO: Set default for MaterialMap *
        memset(&result.maps, 0, sizeof(result.maps));
    }

    // Get params
    napi_has_named_property(env, jsObj, "params", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "params", &prop);
        // TODO: Handle field type float[4]
    } else {
        // Set default value
        // TODO: Set default for float[4]
        memset(&result.params, 0, sizeof(result.params));
    }

    return result;
}

napi_value Material_to_js(napi_env env, Material data) {
    napi_value jsObj;
    napi_create_object(env, &jsObj);
    napi_value prop;

    // Set shader
    prop = Shader_to_js(env, data.shader);
    napi_set_named_property(env, jsObj, "shader", prop);

    // Set maps
    // TODO: Handle field type MaterialMap *
    napi_get_null(env, &prop);
    napi_set_named_property(env, jsObj, "maps", prop);

    // Set params
    // TODO: Handle field type float[4]
    napi_get_null(env, &prop);
    napi_set_named_property(env, jsObj, "params", prop);

    return jsObj;
}

Transform Transform_from_js(napi_env env, napi_value jsObj) {
    Transform result;
    napi_value prop;
    bool has_property;

    // Get translation
    napi_has_named_property(env, jsObj, "translation", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "translation", &prop);
        result.translation = Vector3_from_js(env, prop);
    } else {
        // Set default value
        // TODO: Set default for Vector3
        memset(&result.translation, 0, sizeof(result.translation));
    }

    // Get rotation
    napi_has_named_property(env, jsObj, "rotation", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "rotation", &prop);
        // TODO: Handle field type Quaternion
    } else {
        // Set default value
        // TODO: Set default for Quaternion
        memset(&result.rotation, 0, sizeof(result.rotation));
    }

    // Get scale
    napi_has_named_property(env, jsObj, "scale", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "scale", &prop);
        result.scale = Vector3_from_js(env, prop);
    } else {
        // Set default value
        // TODO: Set default for Vector3
        memset(&result.scale, 0, sizeof(result.scale));
    }

    return result;
}

napi_value Transform_to_js(napi_env env, Transform data) {
    napi_value jsObj;
    napi_create_object(env, &jsObj);
    napi_value prop;

    // Set translation
    prop = Vector3_to_js(env, data.translation);
    napi_set_named_property(env, jsObj, "translation", prop);

    // Set rotation
    // TODO: Handle field type Quaternion
    napi_get_null(env, &prop);
    napi_set_named_property(env, jsObj, "rotation", prop);

    // Set scale
    prop = Vector3_to_js(env, data.scale);
    napi_set_named_property(env, jsObj, "scale", prop);

    return jsObj;
}

BoneInfo BoneInfo_from_js(napi_env env, napi_value jsObj) {
    BoneInfo result;
    napi_value prop;
    bool has_property;

    // Get name
    napi_has_named_property(env, jsObj, "name", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "name", &prop);
        // TODO: Handle field type char[32]
    } else {
        // Set default value
        // TODO: Set default for char[32]
        memset(&result.name, 0, sizeof(result.name));
    }

    // Get parent
    napi_has_named_property(env, jsObj, "parent", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "parent", &prop);
        napi_get_value_int32(env, prop, (int32_t*)&result.parent);
    } else {
        // Set default value
        result.parent = 0;
    }

    return result;
}

napi_value BoneInfo_to_js(napi_env env, BoneInfo data) {
    napi_value jsObj;
    napi_create_object(env, &jsObj);
    napi_value prop;

    // Set name
    // TODO: Handle field type char[32]
    napi_get_null(env, &prop);
    napi_set_named_property(env, jsObj, "name", prop);

    // Set parent
    napi_create_int32(env, (int32_t)data.parent, &prop);
    napi_set_named_property(env, jsObj, "parent", prop);

    return jsObj;
}

Model Model_from_js(napi_env env, napi_value jsObj) {
    Model result;
    napi_value prop;
    bool has_property;

    // Get transform
    napi_has_named_property(env, jsObj, "transform", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "transform", &prop);
        result.transform = Matrix_from_js(env, prop);
    } else {
        // Set default value
        // TODO: Set default for Matrix
        memset(&result.transform, 0, sizeof(result.transform));
    }

    // Get meshCount
    napi_has_named_property(env, jsObj, "meshCount", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "meshCount", &prop);
        napi_get_value_int32(env, prop, (int32_t*)&result.meshCount);
    } else {
        // Set default value
        result.meshCount = 0;
    }

    // Get materialCount
    napi_has_named_property(env, jsObj, "materialCount", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "materialCount", &prop);
        napi_get_value_int32(env, prop, (int32_t*)&result.materialCount);
    } else {
        // Set default value
        result.materialCount = 0;
    }

    // Get meshes
    napi_has_named_property(env, jsObj, "meshes", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "meshes", &prop);
        // TODO: Handle field type Mesh *
    } else {
        // Set default value
        // TODO: Set default for Mesh *
        memset(&result.meshes, 0, sizeof(result.meshes));
    }

    // Get materials
    napi_has_named_property(env, jsObj, "materials", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "materials", &prop);
        // TODO: Handle field type Material *
    } else {
        // Set default value
        // TODO: Set default for Material *
        memset(&result.materials, 0, sizeof(result.materials));
    }

    // Get meshMaterial
    napi_has_named_property(env, jsObj, "meshMaterial", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "meshMaterial", &prop);
        // TODO: Handle field type int *
    } else {
        // Set default value
        // TODO: Set default for int *
        memset(&result.meshMaterial, 0, sizeof(result.meshMaterial));
    }

    // Get boneCount
    napi_has_named_property(env, jsObj, "boneCount", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "boneCount", &prop);
        napi_get_value_int32(env, prop, (int32_t*)&result.boneCount);
    } else {
        // Set default value
        result.boneCount = 0;
    }

    // Get bones
    napi_has_named_property(env, jsObj, "bones", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "bones", &prop);
        // TODO: Handle field type BoneInfo *
    } else {
        // Set default value
        // TODO: Set default for BoneInfo *
        memset(&result.bones, 0, sizeof(result.bones));
    }

    // Get bindPose
    napi_has_named_property(env, jsObj, "bindPose", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "bindPose", &prop);
        // TODO: Handle field type Transform *
    } else {
        // Set default value
        // TODO: Set default for Transform *
        memset(&result.bindPose, 0, sizeof(result.bindPose));
    }

    return result;
}

napi_value Model_to_js(napi_env env, Model data) {
    napi_value jsObj;
    napi_create_object(env, &jsObj);
    napi_value prop;

    // Set transform
    prop = Matrix_to_js(env, data.transform);
    napi_set_named_property(env, jsObj, "transform", prop);

    // Set meshCount
    napi_create_int32(env, (int32_t)data.meshCount, &prop);
    napi_set_named_property(env, jsObj, "meshCount", prop);

    // Set materialCount
    napi_create_int32(env, (int32_t)data.materialCount, &prop);
    napi_set_named_property(env, jsObj, "materialCount", prop);

    // Set meshes
    // TODO: Handle field type Mesh *
    napi_get_null(env, &prop);
    napi_set_named_property(env, jsObj, "meshes", prop);

    // Set materials
    // TODO: Handle field type Material *
    napi_get_null(env, &prop);
    napi_set_named_property(env, jsObj, "materials", prop);

    // Set meshMaterial
    // TODO: Handle field type int *
    napi_get_null(env, &prop);
    napi_set_named_property(env, jsObj, "meshMaterial", prop);

    // Set boneCount
    napi_create_int32(env, (int32_t)data.boneCount, &prop);
    napi_set_named_property(env, jsObj, "boneCount", prop);

    // Set bones
    // TODO: Handle field type BoneInfo *
    napi_get_null(env, &prop);
    napi_set_named_property(env, jsObj, "bones", prop);

    // Set bindPose
    // TODO: Handle field type Transform *
    napi_get_null(env, &prop);
    napi_set_named_property(env, jsObj, "bindPose", prop);

    return jsObj;
}

ModelAnimation ModelAnimation_from_js(napi_env env, napi_value jsObj) {
    ModelAnimation result;
    napi_value prop;
    bool has_property;

    // Get boneCount
    napi_has_named_property(env, jsObj, "boneCount", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "boneCount", &prop);
        napi_get_value_int32(env, prop, (int32_t*)&result.boneCount);
    } else {
        // Set default value
        result.boneCount = 0;
    }

    // Get frameCount
    napi_has_named_property(env, jsObj, "frameCount", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "frameCount", &prop);
        napi_get_value_int32(env, prop, (int32_t*)&result.frameCount);
    } else {
        // Set default value
        result.frameCount = 0;
    }

    // Get bones
    napi_has_named_property(env, jsObj, "bones", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "bones", &prop);
        // TODO: Handle field type BoneInfo *
    } else {
        // Set default value
        // TODO: Set default for BoneInfo *
        memset(&result.bones, 0, sizeof(result.bones));
    }

    // Get framePoses
    napi_has_named_property(env, jsObj, "framePoses", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "framePoses", &prop);
        // TODO: Handle field type Transform **
    } else {
        // Set default value
        // TODO: Set default for Transform **
        memset(&result.framePoses, 0, sizeof(result.framePoses));
    }

    // Get name
    napi_has_named_property(env, jsObj, "name", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "name", &prop);
        // TODO: Handle field type char[32]
    } else {
        // Set default value
        // TODO: Set default for char[32]
        memset(&result.name, 0, sizeof(result.name));
    }

    return result;
}

napi_value ModelAnimation_to_js(napi_env env, ModelAnimation data) {
    napi_value jsObj;
    napi_create_object(env, &jsObj);
    napi_value prop;

    // Set boneCount
    napi_create_int32(env, (int32_t)data.boneCount, &prop);
    napi_set_named_property(env, jsObj, "boneCount", prop);

    // Set frameCount
    napi_create_int32(env, (int32_t)data.frameCount, &prop);
    napi_set_named_property(env, jsObj, "frameCount", prop);

    // Set bones
    // TODO: Handle field type BoneInfo *
    napi_get_null(env, &prop);
    napi_set_named_property(env, jsObj, "bones", prop);

    // Set framePoses
    // TODO: Handle field type Transform **
    napi_get_null(env, &prop);
    napi_set_named_property(env, jsObj, "framePoses", prop);

    // Set name
    // TODO: Handle field type char[32]
    napi_get_null(env, &prop);
    napi_set_named_property(env, jsObj, "name", prop);

    return jsObj;
}

Ray Ray_from_js(napi_env env, napi_value jsObj) {
    Ray result;
    napi_value prop;
    bool has_property;

    // Get position
    napi_has_named_property(env, jsObj, "position", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "position", &prop);
        result.position = Vector3_from_js(env, prop);
    } else {
        // Set default value
        // TODO: Set default for Vector3
        memset(&result.position, 0, sizeof(result.position));
    }

    // Get direction
    napi_has_named_property(env, jsObj, "direction", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "direction", &prop);
        result.direction = Vector3_from_js(env, prop);
    } else {
        // Set default value
        // TODO: Set default for Vector3
        memset(&result.direction, 0, sizeof(result.direction));
    }

    return result;
}

napi_value Ray_to_js(napi_env env, Ray data) {
    napi_value jsObj;
    napi_create_object(env, &jsObj);
    napi_value prop;

    // Set position
    prop = Vector3_to_js(env, data.position);
    napi_set_named_property(env, jsObj, "position", prop);

    // Set direction
    prop = Vector3_to_js(env, data.direction);
    napi_set_named_property(env, jsObj, "direction", prop);

    return jsObj;
}

RayCollision RayCollision_from_js(napi_env env, napi_value jsObj) {
    RayCollision result;
    napi_value prop;
    bool has_property;

    // Get hit
    napi_has_named_property(env, jsObj, "hit", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "hit", &prop);
        napi_get_value_bool(env, prop, &result.hit);
    } else {
        // Set default value
        result.hit = false;
    }

    // Get distance
    napi_has_named_property(env, jsObj, "distance", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "distance", &prop);
        double temp_distance;
        napi_get_value_double(env, prop, &temp_distance);
        result.distance = (float)temp_distance;
    } else {
        // Set default value
        result.distance = 0;
    }

    // Get point
    napi_has_named_property(env, jsObj, "point", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "point", &prop);
        result.point = Vector3_from_js(env, prop);
    } else {
        // Set default value
        // TODO: Set default for Vector3
        memset(&result.point, 0, sizeof(result.point));
    }

    // Get normal
    napi_has_named_property(env, jsObj, "normal", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "normal", &prop);
        result.normal = Vector3_from_js(env, prop);
    } else {
        // Set default value
        // TODO: Set default for Vector3
        memset(&result.normal, 0, sizeof(result.normal));
    }

    return result;
}

napi_value RayCollision_to_js(napi_env env, RayCollision data) {
    napi_value jsObj;
    napi_create_object(env, &jsObj);
    napi_value prop;

    // Set hit
    napi_get_boolean(env, data.hit, &prop);
    napi_set_named_property(env, jsObj, "hit", prop);

    // Set distance
    napi_create_double(env, (double)data.distance, &prop);
    napi_set_named_property(env, jsObj, "distance", prop);

    // Set point
    prop = Vector3_to_js(env, data.point);
    napi_set_named_property(env, jsObj, "point", prop);

    // Set normal
    prop = Vector3_to_js(env, data.normal);
    napi_set_named_property(env, jsObj, "normal", prop);

    return jsObj;
}

BoundingBox BoundingBox_from_js(napi_env env, napi_value jsObj) {
    BoundingBox result;
    napi_value prop;
    bool has_property;

    // Get min
    napi_has_named_property(env, jsObj, "min", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "min", &prop);
        result.min = Vector3_from_js(env, prop);
    } else {
        // Set default value
        // TODO: Set default for Vector3
        memset(&result.min, 0, sizeof(result.min));
    }

    // Get max
    napi_has_named_property(env, jsObj, "max", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "max", &prop);
        result.max = Vector3_from_js(env, prop);
    } else {
        // Set default value
        // TODO: Set default for Vector3
        memset(&result.max, 0, sizeof(result.max));
    }

    return result;
}

napi_value BoundingBox_to_js(napi_env env, BoundingBox data) {
    napi_value jsObj;
    napi_create_object(env, &jsObj);
    napi_value prop;

    // Set min
    prop = Vector3_to_js(env, data.min);
    napi_set_named_property(env, jsObj, "min", prop);

    // Set max
    prop = Vector3_to_js(env, data.max);
    napi_set_named_property(env, jsObj, "max", prop);

    return jsObj;
}

Wave Wave_from_js(napi_env env, napi_value jsObj) {
    Wave result;
    napi_value prop;
    bool has_property;

    // Get frameCount
    napi_has_named_property(env, jsObj, "frameCount", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "frameCount", &prop);
        napi_get_value_int32(env, prop, (int32_t*)&result.frameCount);
    } else {
        // Set default value
        result.frameCount = 0;
    }

    // Get sampleRate
    napi_has_named_property(env, jsObj, "sampleRate", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "sampleRate", &prop);
        napi_get_value_int32(env, prop, (int32_t*)&result.sampleRate);
    } else {
        // Set default value
        result.sampleRate = 0;
    }

    // Get sampleSize
    napi_has_named_property(env, jsObj, "sampleSize", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "sampleSize", &prop);
        napi_get_value_int32(env, prop, (int32_t*)&result.sampleSize);
    } else {
        // Set default value
        result.sampleSize = 0;
    }

    // Get channels
    napi_has_named_property(env, jsObj, "channels", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "channels", &prop);
        napi_get_value_int32(env, prop, (int32_t*)&result.channels);
    } else {
        // Set default value
        result.channels = 0;
    }

    // Get data
    napi_has_named_property(env, jsObj, "data", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "data", &prop);
        // TODO: Handle field type void *
    } else {
        // Set default value
        // TODO: Set default for void *
        memset(&result.data, 0, sizeof(result.data));
    }

    return result;
}

napi_value Wave_to_js(napi_env env, Wave data) {
    napi_value jsObj;
    napi_create_object(env, &jsObj);
    napi_value prop;

    // Set frameCount
    napi_create_int32(env, (int32_t)data.frameCount, &prop);
    napi_set_named_property(env, jsObj, "frameCount", prop);

    // Set sampleRate
    napi_create_int32(env, (int32_t)data.sampleRate, &prop);
    napi_set_named_property(env, jsObj, "sampleRate", prop);

    // Set sampleSize
    napi_create_int32(env, (int32_t)data.sampleSize, &prop);
    napi_set_named_property(env, jsObj, "sampleSize", prop);

    // Set channels
    napi_create_int32(env, (int32_t)data.channels, &prop);
    napi_set_named_property(env, jsObj, "channels", prop);

    // Set data
    // TODO: Handle field type void *
    napi_get_null(env, &prop);
    napi_set_named_property(env, jsObj, "data", prop);

    return jsObj;
}

AudioStream AudioStream_from_js(napi_env env, napi_value jsObj) {
    AudioStream result;
    napi_value prop;
    bool has_property;

    // Get buffer
    napi_has_named_property(env, jsObj, "buffer", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "buffer", &prop);
        // TODO: Handle field type rAudioBuffer *
    } else {
        // Set default value
        // TODO: Set default for rAudioBuffer *
        memset(&result.buffer, 0, sizeof(result.buffer));
    }

    // Get processor
    napi_has_named_property(env, jsObj, "processor", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "processor", &prop);
        // TODO: Handle field type rAudioProcessor *
    } else {
        // Set default value
        // TODO: Set default for rAudioProcessor *
        memset(&result.processor, 0, sizeof(result.processor));
    }

    // Get sampleRate
    napi_has_named_property(env, jsObj, "sampleRate", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "sampleRate", &prop);
        napi_get_value_int32(env, prop, (int32_t*)&result.sampleRate);
    } else {
        // Set default value
        result.sampleRate = 0;
    }

    // Get sampleSize
    napi_has_named_property(env, jsObj, "sampleSize", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "sampleSize", &prop);
        napi_get_value_int32(env, prop, (int32_t*)&result.sampleSize);
    } else {
        // Set default value
        result.sampleSize = 0;
    }

    // Get channels
    napi_has_named_property(env, jsObj, "channels", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "channels", &prop);
        napi_get_value_int32(env, prop, (int32_t*)&result.channels);
    } else {
        // Set default value
        result.channels = 0;
    }

    return result;
}

napi_value AudioStream_to_js(napi_env env, AudioStream data) {
    napi_value jsObj;
    napi_create_object(env, &jsObj);
    napi_value prop;

    // Set buffer
    // TODO: Handle field type rAudioBuffer *
    napi_get_null(env, &prop);
    napi_set_named_property(env, jsObj, "buffer", prop);

    // Set processor
    // TODO: Handle field type rAudioProcessor *
    napi_get_null(env, &prop);
    napi_set_named_property(env, jsObj, "processor", prop);

    // Set sampleRate
    napi_create_int32(env, (int32_t)data.sampleRate, &prop);
    napi_set_named_property(env, jsObj, "sampleRate", prop);

    // Set sampleSize
    napi_create_int32(env, (int32_t)data.sampleSize, &prop);
    napi_set_named_property(env, jsObj, "sampleSize", prop);

    // Set channels
    napi_create_int32(env, (int32_t)data.channels, &prop);
    napi_set_named_property(env, jsObj, "channels", prop);

    return jsObj;
}

Sound Sound_from_js(napi_env env, napi_value jsObj) {
    Sound result;
    napi_value prop;
    bool has_property;

    // Get stream
    napi_has_named_property(env, jsObj, "stream", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "stream", &prop);
        result.stream = AudioStream_from_js(env, prop);
    } else {
        // Set default value
        // TODO: Set default for AudioStream
        memset(&result.stream, 0, sizeof(result.stream));
    }

    // Get frameCount
    napi_has_named_property(env, jsObj, "frameCount", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "frameCount", &prop);
        napi_get_value_int32(env, prop, (int32_t*)&result.frameCount);
    } else {
        // Set default value
        result.frameCount = 0;
    }

    return result;
}

napi_value Sound_to_js(napi_env env, Sound data) {
    napi_value jsObj;
    napi_create_object(env, &jsObj);
    napi_value prop;

    // Set stream
    prop = AudioStream_to_js(env, data.stream);
    napi_set_named_property(env, jsObj, "stream", prop);

    // Set frameCount
    napi_create_int32(env, (int32_t)data.frameCount, &prop);
    napi_set_named_property(env, jsObj, "frameCount", prop);

    return jsObj;
}

Music Music_from_js(napi_env env, napi_value jsObj) {
    Music result;
    napi_value prop;
    bool has_property;

    // Get stream
    napi_has_named_property(env, jsObj, "stream", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "stream", &prop);
        result.stream = AudioStream_from_js(env, prop);
    } else {
        // Set default value
        // TODO: Set default for AudioStream
        memset(&result.stream, 0, sizeof(result.stream));
    }

    // Get frameCount
    napi_has_named_property(env, jsObj, "frameCount", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "frameCount", &prop);
        napi_get_value_int32(env, prop, (int32_t*)&result.frameCount);
    } else {
        // Set default value
        result.frameCount = 0;
    }

    // Get looping
    napi_has_named_property(env, jsObj, "looping", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "looping", &prop);
        napi_get_value_bool(env, prop, &result.looping);
    } else {
        // Set default value
        result.looping = false;
    }

    // Get ctxType
    napi_has_named_property(env, jsObj, "ctxType", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "ctxType", &prop);
        napi_get_value_int32(env, prop, (int32_t*)&result.ctxType);
    } else {
        // Set default value
        result.ctxType = 0;
    }

    // Get ctxData
    napi_has_named_property(env, jsObj, "ctxData", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "ctxData", &prop);
        // TODO: Handle field type void *
    } else {
        // Set default value
        // TODO: Set default for void *
        memset(&result.ctxData, 0, sizeof(result.ctxData));
    }

    return result;
}

napi_value Music_to_js(napi_env env, Music data) {
    napi_value jsObj;
    napi_create_object(env, &jsObj);
    napi_value prop;

    // Set stream
    prop = AudioStream_to_js(env, data.stream);
    napi_set_named_property(env, jsObj, "stream", prop);

    // Set frameCount
    napi_create_int32(env, (int32_t)data.frameCount, &prop);
    napi_set_named_property(env, jsObj, "frameCount", prop);

    // Set looping
    napi_get_boolean(env, data.looping, &prop);
    napi_set_named_property(env, jsObj, "looping", prop);

    // Set ctxType
    napi_create_int32(env, (int32_t)data.ctxType, &prop);
    napi_set_named_property(env, jsObj, "ctxType", prop);

    // Set ctxData
    // TODO: Handle field type void *
    napi_get_null(env, &prop);
    napi_set_named_property(env, jsObj, "ctxData", prop);

    return jsObj;
}

VrDeviceInfo VrDeviceInfo_from_js(napi_env env, napi_value jsObj) {
    VrDeviceInfo result;
    napi_value prop;
    bool has_property;

    // Get hResolution
    napi_has_named_property(env, jsObj, "hResolution", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "hResolution", &prop);
        napi_get_value_int32(env, prop, (int32_t*)&result.hResolution);
    } else {
        // Set default value
        result.hResolution = 0;
    }

    // Get vResolution
    napi_has_named_property(env, jsObj, "vResolution", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "vResolution", &prop);
        napi_get_value_int32(env, prop, (int32_t*)&result.vResolution);
    } else {
        // Set default value
        result.vResolution = 0;
    }

    // Get hScreenSize
    napi_has_named_property(env, jsObj, "hScreenSize", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "hScreenSize", &prop);
        double temp_hScreenSize;
        napi_get_value_double(env, prop, &temp_hScreenSize);
        result.hScreenSize = (float)temp_hScreenSize;
    } else {
        // Set default value
        result.hScreenSize = 0;
    }

    // Get vScreenSize
    napi_has_named_property(env, jsObj, "vScreenSize", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "vScreenSize", &prop);
        double temp_vScreenSize;
        napi_get_value_double(env, prop, &temp_vScreenSize);
        result.vScreenSize = (float)temp_vScreenSize;
    } else {
        // Set default value
        result.vScreenSize = 0;
    }

    // Get eyeToScreenDistance
    napi_has_named_property(env, jsObj, "eyeToScreenDistance", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "eyeToScreenDistance", &prop);
        double temp_eyeToScreenDistance;
        napi_get_value_double(env, prop, &temp_eyeToScreenDistance);
        result.eyeToScreenDistance = (float)temp_eyeToScreenDistance;
    } else {
        // Set default value
        result.eyeToScreenDistance = 0;
    }

    // Get lensSeparationDistance
    napi_has_named_property(env, jsObj, "lensSeparationDistance", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "lensSeparationDistance", &prop);
        double temp_lensSeparationDistance;
        napi_get_value_double(env, prop, &temp_lensSeparationDistance);
        result.lensSeparationDistance = (float)temp_lensSeparationDistance;
    } else {
        // Set default value
        result.lensSeparationDistance = 0;
    }

    // Get interpupillaryDistance
    napi_has_named_property(env, jsObj, "interpupillaryDistance", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "interpupillaryDistance", &prop);
        double temp_interpupillaryDistance;
        napi_get_value_double(env, prop, &temp_interpupillaryDistance);
        result.interpupillaryDistance = (float)temp_interpupillaryDistance;
    } else {
        // Set default value
        result.interpupillaryDistance = 0;
    }

    // Get lensDistortionValues
    napi_has_named_property(env, jsObj, "lensDistortionValues", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "lensDistortionValues", &prop);
        // TODO: Handle field type float[4]
    } else {
        // Set default value
        // TODO: Set default for float[4]
        memset(&result.lensDistortionValues, 0, sizeof(result.lensDistortionValues));
    }

    // Get chromaAbCorrection
    napi_has_named_property(env, jsObj, "chromaAbCorrection", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "chromaAbCorrection", &prop);
        // TODO: Handle field type float[4]
    } else {
        // Set default value
        // TODO: Set default for float[4]
        memset(&result.chromaAbCorrection, 0, sizeof(result.chromaAbCorrection));
    }

    return result;
}

napi_value VrDeviceInfo_to_js(napi_env env, VrDeviceInfo data) {
    napi_value jsObj;
    napi_create_object(env, &jsObj);
    napi_value prop;

    // Set hResolution
    napi_create_int32(env, (int32_t)data.hResolution, &prop);
    napi_set_named_property(env, jsObj, "hResolution", prop);

    // Set vResolution
    napi_create_int32(env, (int32_t)data.vResolution, &prop);
    napi_set_named_property(env, jsObj, "vResolution", prop);

    // Set hScreenSize
    napi_create_double(env, (double)data.hScreenSize, &prop);
    napi_set_named_property(env, jsObj, "hScreenSize", prop);

    // Set vScreenSize
    napi_create_double(env, (double)data.vScreenSize, &prop);
    napi_set_named_property(env, jsObj, "vScreenSize", prop);

    // Set eyeToScreenDistance
    napi_create_double(env, (double)data.eyeToScreenDistance, &prop);
    napi_set_named_property(env, jsObj, "eyeToScreenDistance", prop);

    // Set lensSeparationDistance
    napi_create_double(env, (double)data.lensSeparationDistance, &prop);
    napi_set_named_property(env, jsObj, "lensSeparationDistance", prop);

    // Set interpupillaryDistance
    napi_create_double(env, (double)data.interpupillaryDistance, &prop);
    napi_set_named_property(env, jsObj, "interpupillaryDistance", prop);

    // Set lensDistortionValues
    // TODO: Handle field type float[4]
    napi_get_null(env, &prop);
    napi_set_named_property(env, jsObj, "lensDistortionValues", prop);

    // Set chromaAbCorrection
    // TODO: Handle field type float[4]
    napi_get_null(env, &prop);
    napi_set_named_property(env, jsObj, "chromaAbCorrection", prop);

    return jsObj;
}

VrStereoConfig VrStereoConfig_from_js(napi_env env, napi_value jsObj) {
    VrStereoConfig result;
    napi_value prop;
    bool has_property;

    // Get projection
    napi_has_named_property(env, jsObj, "projection", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "projection", &prop);
        // TODO: Handle field type Matrix[2]
    } else {
        // Set default value
        // TODO: Set default for Matrix[2]
        memset(&result.projection, 0, sizeof(result.projection));
    }

    // Get viewOffset
    napi_has_named_property(env, jsObj, "viewOffset", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "viewOffset", &prop);
        // TODO: Handle field type Matrix[2]
    } else {
        // Set default value
        // TODO: Set default for Matrix[2]
        memset(&result.viewOffset, 0, sizeof(result.viewOffset));
    }

    // Get leftLensCenter
    napi_has_named_property(env, jsObj, "leftLensCenter", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "leftLensCenter", &prop);
        // TODO: Handle field type float[2]
    } else {
        // Set default value
        // TODO: Set default for float[2]
        memset(&result.leftLensCenter, 0, sizeof(result.leftLensCenter));
    }

    // Get rightLensCenter
    napi_has_named_property(env, jsObj, "rightLensCenter", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "rightLensCenter", &prop);
        // TODO: Handle field type float[2]
    } else {
        // Set default value
        // TODO: Set default for float[2]
        memset(&result.rightLensCenter, 0, sizeof(result.rightLensCenter));
    }

    // Get leftScreenCenter
    napi_has_named_property(env, jsObj, "leftScreenCenter", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "leftScreenCenter", &prop);
        // TODO: Handle field type float[2]
    } else {
        // Set default value
        // TODO: Set default for float[2]
        memset(&result.leftScreenCenter, 0, sizeof(result.leftScreenCenter));
    }

    // Get rightScreenCenter
    napi_has_named_property(env, jsObj, "rightScreenCenter", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "rightScreenCenter", &prop);
        // TODO: Handle field type float[2]
    } else {
        // Set default value
        // TODO: Set default for float[2]
        memset(&result.rightScreenCenter, 0, sizeof(result.rightScreenCenter));
    }

    // Get scale
    napi_has_named_property(env, jsObj, "scale", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "scale", &prop);
        // TODO: Handle field type float[2]
    } else {
        // Set default value
        // TODO: Set default for float[2]
        memset(&result.scale, 0, sizeof(result.scale));
    }

    // Get scaleIn
    napi_has_named_property(env, jsObj, "scaleIn", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "scaleIn", &prop);
        // TODO: Handle field type float[2]
    } else {
        // Set default value
        // TODO: Set default for float[2]
        memset(&result.scaleIn, 0, sizeof(result.scaleIn));
    }

    return result;
}

napi_value VrStereoConfig_to_js(napi_env env, VrStereoConfig data) {
    napi_value jsObj;
    napi_create_object(env, &jsObj);
    napi_value prop;

    // Set projection
    // TODO: Handle field type Matrix[2]
    napi_get_null(env, &prop);
    napi_set_named_property(env, jsObj, "projection", prop);

    // Set viewOffset
    // TODO: Handle field type Matrix[2]
    napi_get_null(env, &prop);
    napi_set_named_property(env, jsObj, "viewOffset", prop);

    // Set leftLensCenter
    // TODO: Handle field type float[2]
    napi_get_null(env, &prop);
    napi_set_named_property(env, jsObj, "leftLensCenter", prop);

    // Set rightLensCenter
    // TODO: Handle field type float[2]
    napi_get_null(env, &prop);
    napi_set_named_property(env, jsObj, "rightLensCenter", prop);

    // Set leftScreenCenter
    // TODO: Handle field type float[2]
    napi_get_null(env, &prop);
    napi_set_named_property(env, jsObj, "leftScreenCenter", prop);

    // Set rightScreenCenter
    // TODO: Handle field type float[2]
    napi_get_null(env, &prop);
    napi_set_named_property(env, jsObj, "rightScreenCenter", prop);

    // Set scale
    // TODO: Handle field type float[2]
    napi_get_null(env, &prop);
    napi_set_named_property(env, jsObj, "scale", prop);

    // Set scaleIn
    // TODO: Handle field type float[2]
    napi_get_null(env, &prop);
    napi_set_named_property(env, jsObj, "scaleIn", prop);

    return jsObj;
}

FilePathList FilePathList_from_js(napi_env env, napi_value jsObj) {
    FilePathList result;
    napi_value prop;
    bool has_property;

    // Get capacity
    napi_has_named_property(env, jsObj, "capacity", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "capacity", &prop);
        napi_get_value_int32(env, prop, (int32_t*)&result.capacity);
    } else {
        // Set default value
        result.capacity = 0;
    }

    // Get count
    napi_has_named_property(env, jsObj, "count", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "count", &prop);
        napi_get_value_int32(env, prop, (int32_t*)&result.count);
    } else {
        // Set default value
        result.count = 0;
    }

    // Get paths
    napi_has_named_property(env, jsObj, "paths", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "paths", &prop);
        // TODO: Handle field type char **
    } else {
        // Set default value
        // TODO: Set default for char **
        memset(&result.paths, 0, sizeof(result.paths));
    }

    return result;
}

napi_value FilePathList_to_js(napi_env env, FilePathList data) {
    napi_value jsObj;
    napi_create_object(env, &jsObj);
    napi_value prop;

    // Set capacity
    napi_create_int32(env, (int32_t)data.capacity, &prop);
    napi_set_named_property(env, jsObj, "capacity", prop);

    // Set count
    napi_create_int32(env, (int32_t)data.count, &prop);
    napi_set_named_property(env, jsObj, "count", prop);

    // Set paths
    // TODO: Handle field type char **
    napi_get_null(env, &prop);
    napi_set_named_property(env, jsObj, "paths", prop);

    return jsObj;
}

AutomationEvent AutomationEvent_from_js(napi_env env, napi_value jsObj) {
    AutomationEvent result;
    napi_value prop;
    bool has_property;

    // Get frame
    napi_has_named_property(env, jsObj, "frame", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "frame", &prop);
        napi_get_value_int32(env, prop, (int32_t*)&result.frame);
    } else {
        // Set default value
        result.frame = 0;
    }

    // Get type
    napi_has_named_property(env, jsObj, "type", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "type", &prop);
        napi_get_value_int32(env, prop, (int32_t*)&result.type);
    } else {
        // Set default value
        result.type = 0;
    }

    // Get params
    napi_has_named_property(env, jsObj, "params", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "params", &prop);
        // TODO: Handle field type int[4]
    } else {
        // Set default value
        // TODO: Set default for int[4]
        memset(&result.params, 0, sizeof(result.params));
    }

    return result;
}

napi_value AutomationEvent_to_js(napi_env env, AutomationEvent data) {
    napi_value jsObj;
    napi_create_object(env, &jsObj);
    napi_value prop;

    // Set frame
    napi_create_int32(env, (int32_t)data.frame, &prop);
    napi_set_named_property(env, jsObj, "frame", prop);

    // Set type
    napi_create_int32(env, (int32_t)data.type, &prop);
    napi_set_named_property(env, jsObj, "type", prop);

    // Set params
    // TODO: Handle field type int[4]
    napi_get_null(env, &prop);
    napi_set_named_property(env, jsObj, "params", prop);

    return jsObj;
}

AutomationEventList AutomationEventList_from_js(napi_env env, napi_value jsObj) {
    AutomationEventList result;
    napi_value prop;
    bool has_property;

    // Get capacity
    napi_has_named_property(env, jsObj, "capacity", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "capacity", &prop);
        napi_get_value_int32(env, prop, (int32_t*)&result.capacity);
    } else {
        // Set default value
        result.capacity = 0;
    }

    // Get count
    napi_has_named_property(env, jsObj, "count", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "count", &prop);
        napi_get_value_int32(env, prop, (int32_t*)&result.count);
    } else {
        // Set default value
        result.count = 0;
    }

    // Get events
    napi_has_named_property(env, jsObj, "events", &has_property);
    if (has_property) {
        napi_get_named_property(env, jsObj, "events", &prop);
        // TODO: Handle field type AutomationEvent *
    } else {
        // Set default value
        // TODO: Set default for AutomationEvent *
        memset(&result.events, 0, sizeof(result.events));
    }

    return result;
}

napi_value AutomationEventList_to_js(napi_env env, AutomationEventList data) {
    napi_value jsObj;
    napi_create_object(env, &jsObj);
    napi_value prop;

    // Set capacity
    napi_create_int32(env, (int32_t)data.capacity, &prop);
    napi_set_named_property(env, jsObj, "capacity", prop);

    // Set count
    napi_create_int32(env, (int32_t)data.count, &prop);
    napi_set_named_property(env, jsObj, "count", prop);

    // Set events
    // TODO: Handle field type AutomationEvent *
    napi_get_null(env, &prop);
    napi_set_named_property(env, jsObj, "events", prop);

    return jsObj;
}

// Stub conversion for undefined struct RenderTexture2D
RenderTexture2D RenderTexture2D_from_js(napi_env env, napi_value jsObj) {
    // Warning: No struct definition available for RenderTexture2D
    RenderTexture2D result;
    memset(&result, 0, sizeof(result));
    return result;
}

napi_value RenderTexture2D_to_js(napi_env env, RenderTexture2D data) {
    // Warning: No struct definition available for RenderTexture2D
    napi_value jsObj;
    napi_create_object(env, &jsObj);
    return jsObj;
}

// Stub conversion for undefined struct Texture2D
Texture2D Texture2D_from_js(napi_env env, napi_value jsObj) {
    // Warning: No struct definition available for Texture2D
    Texture2D result;
    memset(&result, 0, sizeof(result));
    return result;
}

napi_value Texture2D_to_js(napi_env env, Texture2D data) {
    // Warning: No struct definition available for Texture2D
    napi_value jsObj;
    napi_create_object(env, &jsObj);
    return jsObj;
}

// Stub conversion for undefined struct Camera
Camera Camera_from_js(napi_env env, napi_value jsObj) {
    // Warning: No struct definition available for Camera
    Camera result;
    memset(&result, 0, sizeof(result));
    return result;
}

napi_value Camera_to_js(napi_env env, Camera data) {
    // Warning: No struct definition available for Camera
    napi_value jsObj;
    napi_create_object(env, &jsObj);
    return jsObj;
}

// Stub conversion for undefined struct int
int int_from_js(napi_env env, napi_value jsObj) {
    // Warning: No struct definition available for int
    int result;
    memset(&result, 0, sizeof(result));
    return result;
}

napi_value int_to_js(napi_env env, int data) {
    // Warning: No struct definition available for int
    napi_value jsObj;
    napi_create_object(env, &jsObj);
    return jsObj;
}

// Stub conversion for undefined struct TraceLogCallback
TraceLogCallback TraceLogCallback_from_js(napi_env env, napi_value jsObj) {
    // Warning: No struct definition available for TraceLogCallback
    TraceLogCallback result;
    memset(&result, 0, sizeof(result));
    return result;
}

napi_value TraceLogCallback_to_js(napi_env env, TraceLogCallback data) {
    // Warning: No struct definition available for TraceLogCallback
    napi_value jsObj;
    napi_create_object(env, &jsObj);
    return jsObj;
}

// Stub conversion for undefined struct LoadFileDataCallback
LoadFileDataCallback LoadFileDataCallback_from_js(napi_env env, napi_value jsObj) {
    // Warning: No struct definition available for LoadFileDataCallback
    LoadFileDataCallback result;
    memset(&result, 0, sizeof(result));
    return result;
}

napi_value LoadFileDataCallback_to_js(napi_env env, LoadFileDataCallback data) {
    // Warning: No struct definition available for LoadFileDataCallback
    napi_value jsObj;
    napi_create_object(env, &jsObj);
    return jsObj;
}

// Stub conversion for undefined struct SaveFileDataCallback
SaveFileDataCallback SaveFileDataCallback_from_js(napi_env env, napi_value jsObj) {
    // Warning: No struct definition available for SaveFileDataCallback
    SaveFileDataCallback result;
    memset(&result, 0, sizeof(result));
    return result;
}

napi_value SaveFileDataCallback_to_js(napi_env env, SaveFileDataCallback data) {
    // Warning: No struct definition available for SaveFileDataCallback
    napi_value jsObj;
    napi_create_object(env, &jsObj);
    return jsObj;
}

// Stub conversion for undefined struct LoadFileTextCallback
LoadFileTextCallback LoadFileTextCallback_from_js(napi_env env, napi_value jsObj) {
    // Warning: No struct definition available for LoadFileTextCallback
    LoadFileTextCallback result;
    memset(&result, 0, sizeof(result));
    return result;
}

napi_value LoadFileTextCallback_to_js(napi_env env, LoadFileTextCallback data) {
    // Warning: No struct definition available for LoadFileTextCallback
    napi_value jsObj;
    napi_create_object(env, &jsObj);
    return jsObj;
}

// Stub conversion for undefined struct SaveFileTextCallback
SaveFileTextCallback SaveFileTextCallback_from_js(napi_env env, napi_value jsObj) {
    // Warning: No struct definition available for SaveFileTextCallback
    SaveFileTextCallback result;
    memset(&result, 0, sizeof(result));
    return result;
}

napi_value SaveFileTextCallback_to_js(napi_env env, SaveFileTextCallback data) {
    // Warning: No struct definition available for SaveFileTextCallback
    napi_value jsObj;
    napi_create_object(env, &jsObj);
    return jsObj;
}

// Stub conversion for undefined struct unsigned char
unsigned char unsigned_char_from_js(napi_env env, napi_value jsObj) {
    // Warning: No struct definition available for unsigned char
    unsigned char result;
    memset(&result, 0, sizeof(result));
    return result;
}

napi_value unsigned_char_to_js(napi_env env, unsigned char data) {
    // Warning: No struct definition available for unsigned char
    napi_value jsObj;
    napi_create_object(env, &jsObj);
    return jsObj;
}

// Stub conversion for undefined struct float
float float_from_js(napi_env env, napi_value jsObj) {
    // Warning: No struct definition available for float
    float result;
    memset(&result, 0, sizeof(result));
    return result;
}

napi_value float_to_js(napi_env env, float data) {
    // Warning: No struct definition available for float
    napi_value jsObj;
    napi_create_object(env, &jsObj);
    return jsObj;
}

// Stub conversion for undefined struct TextureCubemap
TextureCubemap TextureCubemap_from_js(napi_env env, napi_value jsObj) {
    // Warning: No struct definition available for TextureCubemap
    TextureCubemap result;
    memset(&result, 0, sizeof(result));
    return result;
}

napi_value TextureCubemap_to_js(napi_env env, TextureCubemap data) {
    // Warning: No struct definition available for TextureCubemap
    napi_value jsObj;
    napi_create_object(env, &jsObj);
    return jsObj;
}

// Stub conversion for undefined struct Rectangle *
Rectangle * Rectangle___from_js(napi_env env, napi_value jsObj) {
    // Warning: No struct definition available for Rectangle *
    Rectangle * result;
    memset(&result, 0, sizeof(result));
    return result;
}

napi_value Rectangle___to_js(napi_env env, Rectangle * data) {
    // Warning: No struct definition available for Rectangle *
    napi_value jsObj;
    napi_create_object(env, &jsObj);
    return jsObj;
}

// Stub conversion for undefined struct AudioCallback
AudioCallback AudioCallback_from_js(napi_env env, napi_value jsObj) {
    // Warning: No struct definition available for AudioCallback
    AudioCallback result;
    memset(&result, 0, sizeof(result));
    return result;
}

napi_value AudioCallback_to_js(napi_env env, AudioCallback data) {
    // Warning: No struct definition available for AudioCallback
    napi_value jsObj;
    napi_create_object(env, &jsObj);
    return jsObj;
}

// Function bindings
napi_value BindNode_InitWindow(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value args[3];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 3) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    int width;
    napi_get_value_int32(env, args[0], (int32_t*)&width);

    int height;
    napi_get_value_int32(env, args[1], (int32_t*)&height);

    size_t title_len;
    napi_get_value_string_utf8(env, args[2], NULL, 0, &title_len);
    char* title = (char*)malloc(title_len + 1);
    napi_get_value_string_utf8(env, args[2], title, title_len + 1, &title_len);

    InitWindow(width, height, title);
    free(title);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_CloseWindow(napi_env env, napi_callback_info info) {
    CloseWindow();
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_WindowShouldClose(napi_env env, napi_callback_info info) {
    bool result = WindowShouldClose();
    napi_value jsResult;
    napi_get_boolean(env, result, &jsResult);
    return jsResult;
}

napi_value BindNode_IsWindowReady(napi_env env, napi_callback_info info) {
    bool result = IsWindowReady();
    napi_value jsResult;
    napi_get_boolean(env, result, &jsResult);
    return jsResult;
}

napi_value BindNode_IsWindowFullscreen(napi_env env, napi_callback_info info) {
    bool result = IsWindowFullscreen();
    napi_value jsResult;
    napi_get_boolean(env, result, &jsResult);
    return jsResult;
}

napi_value BindNode_IsWindowHidden(napi_env env, napi_callback_info info) {
    bool result = IsWindowHidden();
    napi_value jsResult;
    napi_get_boolean(env, result, &jsResult);
    return jsResult;
}

napi_value BindNode_IsWindowMinimized(napi_env env, napi_callback_info info) {
    bool result = IsWindowMinimized();
    napi_value jsResult;
    napi_get_boolean(env, result, &jsResult);
    return jsResult;
}

napi_value BindNode_IsWindowMaximized(napi_env env, napi_callback_info info) {
    bool result = IsWindowMaximized();
    napi_value jsResult;
    napi_get_boolean(env, result, &jsResult);
    return jsResult;
}

napi_value BindNode_IsWindowFocused(napi_env env, napi_callback_info info) {
    bool result = IsWindowFocused();
    napi_value jsResult;
    napi_get_boolean(env, result, &jsResult);
    return jsResult;
}

napi_value BindNode_IsWindowResized(napi_env env, napi_callback_info info) {
    bool result = IsWindowResized();
    napi_value jsResult;
    napi_get_boolean(env, result, &jsResult);
    return jsResult;
}

napi_value BindNode_IsWindowState(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    unsigned int flag;
    napi_get_value_int32(env, args[0], (int32_t*)&flag);

    bool result = IsWindowState(flag);
    napi_value jsResult;
    napi_get_boolean(env, result, &jsResult);
    return jsResult;
}

napi_value BindNode_SetWindowState(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    unsigned int flags;
    napi_get_value_int32(env, args[0], (int32_t*)&flags);

    SetWindowState(flags);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_ClearWindowState(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    unsigned int flags;
    napi_get_value_int32(env, args[0], (int32_t*)&flags);

    ClearWindowState(flags);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_ToggleFullscreen(napi_env env, napi_callback_info info) {
    ToggleFullscreen();
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_ToggleBorderlessWindowed(napi_env env, napi_callback_info info) {
    ToggleBorderlessWindowed();
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_MaximizeWindow(napi_env env, napi_callback_info info) {
    MaximizeWindow();
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_MinimizeWindow(napi_env env, napi_callback_info info) {
    MinimizeWindow();
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_RestoreWindow(napi_env env, napi_callback_info info) {
    RestoreWindow();
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_SetWindowIcon(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Image image = Image_from_js(env, args[0]);

    SetWindowIcon(image);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_SetWindowIcons(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Image images_value = Image_from_js(env, args[0]);
    Image * images = &images_value;

    int count;
    napi_get_value_int32(env, args[1], (int32_t*)&count);

    SetWindowIcons(images, count);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_SetWindowTitle(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    size_t title_len;
    napi_get_value_string_utf8(env, args[0], NULL, 0, &title_len);
    char* title = (char*)malloc(title_len + 1);
    napi_get_value_string_utf8(env, args[0], title, title_len + 1, &title_len);

    SetWindowTitle(title);
    free(title);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_SetWindowPosition(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    int x;
    napi_get_value_int32(env, args[0], (int32_t*)&x);

    int y;
    napi_get_value_int32(env, args[1], (int32_t*)&y);

    SetWindowPosition(x, y);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_SetWindowMonitor(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    int monitor;
    napi_get_value_int32(env, args[0], (int32_t*)&monitor);

    SetWindowMonitor(monitor);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_SetWindowMinSize(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    int width;
    napi_get_value_int32(env, args[0], (int32_t*)&width);

    int height;
    napi_get_value_int32(env, args[1], (int32_t*)&height);

    SetWindowMinSize(width, height);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_SetWindowMaxSize(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    int width;
    napi_get_value_int32(env, args[0], (int32_t*)&width);

    int height;
    napi_get_value_int32(env, args[1], (int32_t*)&height);

    SetWindowMaxSize(width, height);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_SetWindowSize(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    int width;
    napi_get_value_int32(env, args[0], (int32_t*)&width);

    int height;
    napi_get_value_int32(env, args[1], (int32_t*)&height);

    SetWindowSize(width, height);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_SetWindowOpacity(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    double temp_opacity;
    napi_get_value_double(env, args[0], &temp_opacity);
    float opacity = (float)temp_opacity;

    SetWindowOpacity(opacity);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_SetWindowFocused(napi_env env, napi_callback_info info) {
    SetWindowFocused();
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_GetWindowHandle(napi_env env, napi_callback_info info) {
    void * result = GetWindowHandle();
    // TODO: Handle return type void *
    napi_value jsResult;
    napi_get_null(env, &jsResult);
    return jsResult; // Placeholder
}

napi_value BindNode_GetScreenWidth(napi_env env, napi_callback_info info) {
    int result = GetScreenWidth();
    return int_to_js(env, result);
}

napi_value BindNode_GetScreenHeight(napi_env env, napi_callback_info info) {
    int result = GetScreenHeight();
    return int_to_js(env, result);
}

napi_value BindNode_GetRenderWidth(napi_env env, napi_callback_info info) {
    int result = GetRenderWidth();
    return int_to_js(env, result);
}

napi_value BindNode_GetRenderHeight(napi_env env, napi_callback_info info) {
    int result = GetRenderHeight();
    return int_to_js(env, result);
}

napi_value BindNode_GetMonitorCount(napi_env env, napi_callback_info info) {
    int result = GetMonitorCount();
    return int_to_js(env, result);
}

napi_value BindNode_GetCurrentMonitor(napi_env env, napi_callback_info info) {
    int result = GetCurrentMonitor();
    return int_to_js(env, result);
}

napi_value BindNode_GetMonitorPosition(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    int monitor;
    napi_get_value_int32(env, args[0], (int32_t*)&monitor);

    Vector2 result = GetMonitorPosition(monitor);
    return Vector2_to_js(env, result);
}

napi_value BindNode_GetMonitorWidth(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    int monitor;
    napi_get_value_int32(env, args[0], (int32_t*)&monitor);

    int result = GetMonitorWidth(monitor);
    return int_to_js(env, result);
}

napi_value BindNode_GetMonitorHeight(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    int monitor;
    napi_get_value_int32(env, args[0], (int32_t*)&monitor);

    int result = GetMonitorHeight(monitor);
    return int_to_js(env, result);
}

napi_value BindNode_GetMonitorPhysicalWidth(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    int monitor;
    napi_get_value_int32(env, args[0], (int32_t*)&monitor);

    int result = GetMonitorPhysicalWidth(monitor);
    return int_to_js(env, result);
}

napi_value BindNode_GetMonitorPhysicalHeight(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    int monitor;
    napi_get_value_int32(env, args[0], (int32_t*)&monitor);

    int result = GetMonitorPhysicalHeight(monitor);
    return int_to_js(env, result);
}

napi_value BindNode_GetMonitorRefreshRate(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    int monitor;
    napi_get_value_int32(env, args[0], (int32_t*)&monitor);

    int result = GetMonitorRefreshRate(monitor);
    return int_to_js(env, result);
}

napi_value BindNode_GetWindowPosition(napi_env env, napi_callback_info info) {
    Vector2 result = GetWindowPosition();
    return Vector2_to_js(env, result);
}

napi_value BindNode_GetWindowScaleDPI(napi_env env, napi_callback_info info) {
    Vector2 result = GetWindowScaleDPI();
    return Vector2_to_js(env, result);
}

napi_value BindNode_GetMonitorName(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    int monitor;
    napi_get_value_int32(env, args[0], (int32_t*)&monitor);

    const char * result = GetMonitorName(monitor);
    napi_value jsResult;
    if (result == NULL) {
        napi_get_null(env, &jsResult);
    } else {
        napi_create_string_utf8(env, result, NAPI_AUTO_LENGTH, &jsResult);
    }
    return jsResult;
}

napi_value BindNode_SetClipboardText(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    size_t text_len;
    napi_get_value_string_utf8(env, args[0], NULL, 0, &text_len);
    char* text = (char*)malloc(text_len + 1);
    napi_get_value_string_utf8(env, args[0], text, text_len + 1, &text_len);

    SetClipboardText(text);
    free(text);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_GetClipboardText(napi_env env, napi_callback_info info) {
    const char * result = GetClipboardText();
    napi_value jsResult;
    if (result == NULL) {
        napi_get_null(env, &jsResult);
    } else {
        napi_create_string_utf8(env, result, NAPI_AUTO_LENGTH, &jsResult);
    }
    return jsResult;
}

napi_value BindNode_GetClipboardImage(napi_env env, napi_callback_info info) {
    Image result = GetClipboardImage();
    return Image_to_js(env, result);
}

napi_value BindNode_EnableEventWaiting(napi_env env, napi_callback_info info) {
    EnableEventWaiting();
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DisableEventWaiting(napi_env env, napi_callback_info info) {
    DisableEventWaiting();
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_ShowCursor(napi_env env, napi_callback_info info) {
    ShowCursor();
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_HideCursor(napi_env env, napi_callback_info info) {
    HideCursor();
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_IsCursorHidden(napi_env env, napi_callback_info info) {
    bool result = IsCursorHidden();
    napi_value jsResult;
    napi_get_boolean(env, result, &jsResult);
    return jsResult;
}

napi_value BindNode_EnableCursor(napi_env env, napi_callback_info info) {
    EnableCursor();
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DisableCursor(napi_env env, napi_callback_info info) {
    DisableCursor();
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_IsCursorOnScreen(napi_env env, napi_callback_info info) {
    bool result = IsCursorOnScreen();
    napi_value jsResult;
    napi_get_boolean(env, result, &jsResult);
    return jsResult;
}

napi_value BindNode_ClearBackground(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Color color = Color_from_js(env, args[0]);

    ClearBackground(color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_BeginDrawing(napi_env env, napi_callback_info info) {
    BeginDrawing();
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_EndDrawing(napi_env env, napi_callback_info info) {
    EndDrawing();
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_BeginMode2D(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Camera2D camera = Camera2D_from_js(env, args[0]);

    BeginMode2D(camera);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_EndMode2D(napi_env env, napi_callback_info info) {
    EndMode2D();
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_BeginMode3D(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Camera3D camera = Camera3D_from_js(env, args[0]);

    BeginMode3D(camera);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_EndMode3D(napi_env env, napi_callback_info info) {
    EndMode3D();
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_BeginTextureMode(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    RenderTexture2D target = RenderTexture2D_from_js(env, args[0]);

    BeginTextureMode(target);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_EndTextureMode(napi_env env, napi_callback_info info) {
    EndTextureMode();
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_BeginShaderMode(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Shader shader = Shader_from_js(env, args[0]);

    BeginShaderMode(shader);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_EndShaderMode(napi_env env, napi_callback_info info) {
    EndShaderMode();
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_BeginBlendMode(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    int mode;
    napi_get_value_int32(env, args[0], (int32_t*)&mode);

    BeginBlendMode(mode);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_EndBlendMode(napi_env env, napi_callback_info info) {
    EndBlendMode();
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_BeginScissorMode(napi_env env, napi_callback_info info) {
    size_t argc = 4;
    napi_value args[4];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 4) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    int x;
    napi_get_value_int32(env, args[0], (int32_t*)&x);

    int y;
    napi_get_value_int32(env, args[1], (int32_t*)&y);

    int width;
    napi_get_value_int32(env, args[2], (int32_t*)&width);

    int height;
    napi_get_value_int32(env, args[3], (int32_t*)&height);

    BeginScissorMode(x, y, width, height);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_EndScissorMode(napi_env env, napi_callback_info info) {
    EndScissorMode();
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_BeginVrStereoMode(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    VrStereoConfig config = VrStereoConfig_from_js(env, args[0]);

    BeginVrStereoMode(config);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_EndVrStereoMode(napi_env env, napi_callback_info info) {
    EndVrStereoMode();
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_LoadVrStereoConfig(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    VrDeviceInfo device = VrDeviceInfo_from_js(env, args[0]);

    VrStereoConfig result = LoadVrStereoConfig(device);
    return VrStereoConfig_to_js(env, result);
}

napi_value BindNode_UnloadVrStereoConfig(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    VrStereoConfig config = VrStereoConfig_from_js(env, args[0]);

    UnloadVrStereoConfig(config);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_LoadShader(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    size_t vsFileName_len;
    napi_get_value_string_utf8(env, args[0], NULL, 0, &vsFileName_len);
    char* vsFileName = (char*)malloc(vsFileName_len + 1);
    napi_get_value_string_utf8(env, args[0], vsFileName, vsFileName_len + 1, &vsFileName_len);

    size_t fsFileName_len;
    napi_get_value_string_utf8(env, args[1], NULL, 0, &fsFileName_len);
    char* fsFileName = (char*)malloc(fsFileName_len + 1);
    napi_get_value_string_utf8(env, args[1], fsFileName, fsFileName_len + 1, &fsFileName_len);

    Shader result = LoadShader(vsFileName, fsFileName);
    free(vsFileName);
    free(fsFileName);
    return Shader_to_js(env, result);
}

napi_value BindNode_LoadShaderFromMemory(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    size_t vsCode_len;
    napi_get_value_string_utf8(env, args[0], NULL, 0, &vsCode_len);
    char* vsCode = (char*)malloc(vsCode_len + 1);
    napi_get_value_string_utf8(env, args[0], vsCode, vsCode_len + 1, &vsCode_len);

    size_t fsCode_len;
    napi_get_value_string_utf8(env, args[1], NULL, 0, &fsCode_len);
    char* fsCode = (char*)malloc(fsCode_len + 1);
    napi_get_value_string_utf8(env, args[1], fsCode, fsCode_len + 1, &fsCode_len);

    Shader result = LoadShaderFromMemory(vsCode, fsCode);
    free(vsCode);
    free(fsCode);
    return Shader_to_js(env, result);
}

napi_value BindNode_IsShaderValid(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Shader shader = Shader_from_js(env, args[0]);

    bool result = IsShaderValid(shader);
    napi_value jsResult;
    napi_get_boolean(env, result, &jsResult);
    return jsResult;
}

napi_value BindNode_GetShaderLocation(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Shader shader = Shader_from_js(env, args[0]);

    size_t uniformName_len;
    napi_get_value_string_utf8(env, args[1], NULL, 0, &uniformName_len);
    char* uniformName = (char*)malloc(uniformName_len + 1);
    napi_get_value_string_utf8(env, args[1], uniformName, uniformName_len + 1, &uniformName_len);

    int result = GetShaderLocation(shader, uniformName);
    free(uniformName);
    return int_to_js(env, result);
}

napi_value BindNode_GetShaderLocationAttrib(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Shader shader = Shader_from_js(env, args[0]);

    size_t attribName_len;
    napi_get_value_string_utf8(env, args[1], NULL, 0, &attribName_len);
    char* attribName = (char*)malloc(attribName_len + 1);
    napi_get_value_string_utf8(env, args[1], attribName, attribName_len + 1, &attribName_len);

    int result = GetShaderLocationAttrib(shader, attribName);
    free(attribName);
    return int_to_js(env, result);
}

napi_value BindNode_SetShaderValue(napi_env env, napi_callback_info info) {
    size_t argc = 4;
    napi_value args[4];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 4) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Shader shader = Shader_from_js(env, args[0]);

    int locIndex;
    napi_get_value_int32(env, args[1], (int32_t*)&locIndex);

    // Warning: No conversion available for const void
    const void * value = NULL;

    int uniformType;
    napi_get_value_int32(env, args[3], (int32_t*)&uniformType);

    SetShaderValue(shader, locIndex, value, uniformType);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_SetShaderValueV(napi_env env, napi_callback_info info) {
    size_t argc = 5;
    napi_value args[5];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 5) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Shader shader = Shader_from_js(env, args[0]);

    int locIndex;
    napi_get_value_int32(env, args[1], (int32_t*)&locIndex);

    // Warning: No conversion available for const void
    const void * value = NULL;

    int uniformType;
    napi_get_value_int32(env, args[3], (int32_t*)&uniformType);

    int count;
    napi_get_value_int32(env, args[4], (int32_t*)&count);

    SetShaderValueV(shader, locIndex, value, uniformType, count);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_SetShaderValueMatrix(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value args[3];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 3) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Shader shader = Shader_from_js(env, args[0]);

    int locIndex;
    napi_get_value_int32(env, args[1], (int32_t*)&locIndex);

    Matrix mat = Matrix_from_js(env, args[2]);

    SetShaderValueMatrix(shader, locIndex, mat);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_SetShaderValueTexture(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value args[3];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 3) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Shader shader = Shader_from_js(env, args[0]);

    int locIndex;
    napi_get_value_int32(env, args[1], (int32_t*)&locIndex);

    Texture2D texture = Texture2D_from_js(env, args[2]);

    SetShaderValueTexture(shader, locIndex, texture);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_UnloadShader(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Shader shader = Shader_from_js(env, args[0]);

    UnloadShader(shader);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_GetScreenToWorldRay(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Vector2 position = Vector2_from_js(env, args[0]);

    Camera camera = Camera_from_js(env, args[1]);

    Ray result = GetScreenToWorldRay(position, camera);
    return Ray_to_js(env, result);
}

napi_value BindNode_GetScreenToWorldRayEx(napi_env env, napi_callback_info info) {
    size_t argc = 4;
    napi_value args[4];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 4) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Vector2 position = Vector2_from_js(env, args[0]);

    Camera camera = Camera_from_js(env, args[1]);

    int width;
    napi_get_value_int32(env, args[2], (int32_t*)&width);

    int height;
    napi_get_value_int32(env, args[3], (int32_t*)&height);

    Ray result = GetScreenToWorldRayEx(position, camera, width, height);
    return Ray_to_js(env, result);
}

napi_value BindNode_GetWorldToScreen(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Vector3 position = Vector3_from_js(env, args[0]);

    Camera camera = Camera_from_js(env, args[1]);

    Vector2 result = GetWorldToScreen(position, camera);
    return Vector2_to_js(env, result);
}

napi_value BindNode_GetWorldToScreenEx(napi_env env, napi_callback_info info) {
    size_t argc = 4;
    napi_value args[4];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 4) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Vector3 position = Vector3_from_js(env, args[0]);

    Camera camera = Camera_from_js(env, args[1]);

    int width;
    napi_get_value_int32(env, args[2], (int32_t*)&width);

    int height;
    napi_get_value_int32(env, args[3], (int32_t*)&height);

    Vector2 result = GetWorldToScreenEx(position, camera, width, height);
    return Vector2_to_js(env, result);
}

napi_value BindNode_GetWorldToScreen2D(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Vector2 position = Vector2_from_js(env, args[0]);

    Camera2D camera = Camera2D_from_js(env, args[1]);

    Vector2 result = GetWorldToScreen2D(position, camera);
    return Vector2_to_js(env, result);
}

napi_value BindNode_GetScreenToWorld2D(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Vector2 position = Vector2_from_js(env, args[0]);

    Camera2D camera = Camera2D_from_js(env, args[1]);

    Vector2 result = GetScreenToWorld2D(position, camera);
    return Vector2_to_js(env, result);
}

napi_value BindNode_GetCameraMatrix(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Camera camera = Camera_from_js(env, args[0]);

    Matrix result = GetCameraMatrix(camera);
    return Matrix_to_js(env, result);
}

napi_value BindNode_GetCameraMatrix2D(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Camera2D camera = Camera2D_from_js(env, args[0]);

    Matrix result = GetCameraMatrix2D(camera);
    return Matrix_to_js(env, result);
}

napi_value BindNode_SetTargetFPS(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    int fps;
    napi_get_value_int32(env, args[0], (int32_t*)&fps);

    SetTargetFPS(fps);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_GetFrameTime(napi_env env, napi_callback_info info) {
    float result = GetFrameTime();
    return float_to_js(env, result);
}

napi_value BindNode_GetTime(napi_env env, napi_callback_info info) {
    double result = GetTime();
    napi_value jsResult;
    napi_create_double(env, (double)result, &jsResult);
    return jsResult;
}

napi_value BindNode_GetFPS(napi_env env, napi_callback_info info) {
    int result = GetFPS();
    return int_to_js(env, result);
}

napi_value BindNode_SwapScreenBuffer(napi_env env, napi_callback_info info) {
    SwapScreenBuffer();
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_PollInputEvents(napi_env env, napi_callback_info info) {
    PollInputEvents();
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_WaitTime(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    double seconds;
    napi_get_value_double(env, args[0], &seconds);

    WaitTime(seconds);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_SetRandomSeed(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    unsigned int seed;
    napi_get_value_int32(env, args[0], (int32_t*)&seed);

    SetRandomSeed(seed);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_GetRandomValue(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    int min;
    napi_get_value_int32(env, args[0], (int32_t*)&min);

    int max;
    napi_get_value_int32(env, args[1], (int32_t*)&max);

    int result = GetRandomValue(min, max);
    return int_to_js(env, result);
}

napi_value BindNode_LoadRandomSequence(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value args[3];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 3) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    unsigned int count;
    napi_get_value_int32(env, args[0], (int32_t*)&count);

    int min;
    napi_get_value_int32(env, args[1], (int32_t*)&min);

    int max;
    napi_get_value_int32(env, args[2], (int32_t*)&max);

    int * result = LoadRandomSequence(count, min, max);
    // TODO: Handle return type int *
    napi_value jsResult;
    napi_get_null(env, &jsResult);
    return jsResult; // Placeholder
}

napi_value BindNode_UnloadRandomSequence(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    int sequence_value = int_from_js(env, args[0]);
    int * sequence = &sequence_value;

    UnloadRandomSequence(sequence);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_TakeScreenshot(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    size_t fileName_len;
    napi_get_value_string_utf8(env, args[0], NULL, 0, &fileName_len);
    char* fileName = (char*)malloc(fileName_len + 1);
    napi_get_value_string_utf8(env, args[0], fileName, fileName_len + 1, &fileName_len);

    TakeScreenshot(fileName);
    free(fileName);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_SetConfigFlags(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    unsigned int flags;
    napi_get_value_int32(env, args[0], (int32_t*)&flags);

    SetConfigFlags(flags);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_OpenURL(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    size_t url_len;
    napi_get_value_string_utf8(env, args[0], NULL, 0, &url_len);
    char* url = (char*)malloc(url_len + 1);
    napi_get_value_string_utf8(env, args[0], url, url_len + 1, &url_len);

    OpenURL(url);
    free(url);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_TraceLog(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value args[3];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    int logLevel;
    napi_get_value_int32(env, args[0], (int32_t*)&logLevel);

    size_t text_len;
    napi_get_value_string_utf8(env, args[1], NULL, 0, &text_len);
    char* text = (char*)malloc(text_len + 1);
    napi_get_value_string_utf8(env, args[1], text, text_len + 1, &text_len);

    TraceLog(logLevel, text);
    free(text);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_SetTraceLogLevel(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    int logLevel;
    napi_get_value_int32(env, args[0], (int32_t*)&logLevel);

    SetTraceLogLevel(logLevel);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_MemAlloc(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    unsigned int size;
    napi_get_value_int32(env, args[0], (int32_t*)&size);

    void * result = MemAlloc(size);
    // TODO: Handle return type void *
    napi_value jsResult;
    napi_get_null(env, &jsResult);
    return jsResult; // Placeholder
}

napi_value BindNode_MemRealloc(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    void_ptr ptr_value = void_from_js(env, args[0]);
    void * ptr = ptr_value;

    unsigned int size;
    napi_get_value_int32(env, args[1], (int32_t*)&size);

    void * result = MemRealloc(ptr, size);
    // TODO: Handle return type void *
    napi_value jsResult;
    napi_get_null(env, &jsResult);
    return jsResult; // Placeholder
}

napi_value BindNode_MemFree(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    void_ptr ptr_value = void_from_js(env, args[0]);
    void * ptr = ptr_value;

    MemFree(ptr);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_SetTraceLogCallback(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    TraceLogCallback callback = TraceLogCallback_from_js(env, args[0]);

    SetTraceLogCallback(callback);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_SetLoadFileDataCallback(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    LoadFileDataCallback callback = LoadFileDataCallback_from_js(env, args[0]);

    SetLoadFileDataCallback(callback);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_SetSaveFileDataCallback(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    SaveFileDataCallback callback = SaveFileDataCallback_from_js(env, args[0]);

    SetSaveFileDataCallback(callback);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_SetLoadFileTextCallback(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    LoadFileTextCallback callback = LoadFileTextCallback_from_js(env, args[0]);

    SetLoadFileTextCallback(callback);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_SetSaveFileTextCallback(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    SaveFileTextCallback callback = SaveFileTextCallback_from_js(env, args[0]);

    SetSaveFileTextCallback(callback);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_LoadFileData(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    size_t fileName_len;
    napi_get_value_string_utf8(env, args[0], NULL, 0, &fileName_len);
    char* fileName = (char*)malloc(fileName_len + 1);
    napi_get_value_string_utf8(env, args[0], fileName, fileName_len + 1, &fileName_len);

    int dataSize_value = int_from_js(env, args[1]);
    int * dataSize = &dataSize_value;

    unsigned char * result = LoadFileData(fileName, dataSize);
    free(fileName);
    // TODO: Handle return type unsigned char *
    napi_value jsResult;
    napi_get_null(env, &jsResult);
    return jsResult; // Placeholder
}

napi_value BindNode_UnloadFileData(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    unsigned char data_value = unsigned_char_from_js(env, args[0]);
    unsigned char * data = &data_value;

    UnloadFileData(data);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_SaveFileData(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value args[3];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 3) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    size_t fileName_len;
    napi_get_value_string_utf8(env, args[0], NULL, 0, &fileName_len);
    char* fileName = (char*)malloc(fileName_len + 1);
    napi_get_value_string_utf8(env, args[0], fileName, fileName_len + 1, &fileName_len);

    void_ptr data_value = void_from_js(env, args[1]);
    void * data = data_value;

    int dataSize;
    napi_get_value_int32(env, args[2], (int32_t*)&dataSize);

    bool result = SaveFileData(fileName, data, dataSize);
    free(fileName);
    napi_value jsResult;
    napi_get_boolean(env, result, &jsResult);
    return jsResult;
}

napi_value BindNode_ExportDataAsCode(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value args[3];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 3) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    // Warning: No conversion available for const unsigned char
    const unsigned char * data = NULL;

    int dataSize;
    napi_get_value_int32(env, args[1], (int32_t*)&dataSize);

    size_t fileName_len;
    napi_get_value_string_utf8(env, args[2], NULL, 0, &fileName_len);
    char* fileName = (char*)malloc(fileName_len + 1);
    napi_get_value_string_utf8(env, args[2], fileName, fileName_len + 1, &fileName_len);

    bool result = ExportDataAsCode(data, dataSize, fileName);
    free(fileName);
    napi_value jsResult;
    napi_get_boolean(env, result, &jsResult);
    return jsResult;
}

napi_value BindNode_LoadFileText(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    size_t fileName_len;
    napi_get_value_string_utf8(env, args[0], NULL, 0, &fileName_len);
    char* fileName = (char*)malloc(fileName_len + 1);
    napi_get_value_string_utf8(env, args[0], fileName, fileName_len + 1, &fileName_len);

    char * result = LoadFileText(fileName);
    free(fileName);
    napi_value jsResult;
    if (result == NULL) {
        napi_get_null(env, &jsResult);
    } else {
        napi_create_string_utf8(env, result, NAPI_AUTO_LENGTH, &jsResult);
    }
    return jsResult;
}

napi_value BindNode_UnloadFileText(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    size_t text_len;
    napi_get_value_string_utf8(env, args[0], NULL, 0, &text_len);
    char* text = (char*)malloc(text_len + 1);
    napi_get_value_string_utf8(env, args[0], text, text_len + 1, &text_len);

    UnloadFileText(text);
    free(text);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_SaveFileText(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    size_t fileName_len;
    napi_get_value_string_utf8(env, args[0], NULL, 0, &fileName_len);
    char* fileName = (char*)malloc(fileName_len + 1);
    napi_get_value_string_utf8(env, args[0], fileName, fileName_len + 1, &fileName_len);

    size_t text_len;
    napi_get_value_string_utf8(env, args[1], NULL, 0, &text_len);
    char* text = (char*)malloc(text_len + 1);
    napi_get_value_string_utf8(env, args[1], text, text_len + 1, &text_len);

    bool result = SaveFileText(fileName, text);
    free(fileName);
    free(text);
    napi_value jsResult;
    napi_get_boolean(env, result, &jsResult);
    return jsResult;
}

napi_value BindNode_FileExists(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    size_t fileName_len;
    napi_get_value_string_utf8(env, args[0], NULL, 0, &fileName_len);
    char* fileName = (char*)malloc(fileName_len + 1);
    napi_get_value_string_utf8(env, args[0], fileName, fileName_len + 1, &fileName_len);

    bool result = FileExists(fileName);
    free(fileName);
    napi_value jsResult;
    napi_get_boolean(env, result, &jsResult);
    return jsResult;
}

napi_value BindNode_DirectoryExists(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    size_t dirPath_len;
    napi_get_value_string_utf8(env, args[0], NULL, 0, &dirPath_len);
    char* dirPath = (char*)malloc(dirPath_len + 1);
    napi_get_value_string_utf8(env, args[0], dirPath, dirPath_len + 1, &dirPath_len);

    bool result = DirectoryExists(dirPath);
    free(dirPath);
    napi_value jsResult;
    napi_get_boolean(env, result, &jsResult);
    return jsResult;
}

napi_value BindNode_IsFileExtension(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    size_t fileName_len;
    napi_get_value_string_utf8(env, args[0], NULL, 0, &fileName_len);
    char* fileName = (char*)malloc(fileName_len + 1);
    napi_get_value_string_utf8(env, args[0], fileName, fileName_len + 1, &fileName_len);

    size_t ext_len;
    napi_get_value_string_utf8(env, args[1], NULL, 0, &ext_len);
    char* ext = (char*)malloc(ext_len + 1);
    napi_get_value_string_utf8(env, args[1], ext, ext_len + 1, &ext_len);

    bool result = IsFileExtension(fileName, ext);
    free(fileName);
    free(ext);
    napi_value jsResult;
    napi_get_boolean(env, result, &jsResult);
    return jsResult;
}

napi_value BindNode_GetFileLength(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    size_t fileName_len;
    napi_get_value_string_utf8(env, args[0], NULL, 0, &fileName_len);
    char* fileName = (char*)malloc(fileName_len + 1);
    napi_get_value_string_utf8(env, args[0], fileName, fileName_len + 1, &fileName_len);

    int result = GetFileLength(fileName);
    free(fileName);
    return int_to_js(env, result);
}

napi_value BindNode_GetFileExtension(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    size_t fileName_len;
    napi_get_value_string_utf8(env, args[0], NULL, 0, &fileName_len);
    char* fileName = (char*)malloc(fileName_len + 1);
    napi_get_value_string_utf8(env, args[0], fileName, fileName_len + 1, &fileName_len);

    const char * result = GetFileExtension(fileName);
    free(fileName);
    napi_value jsResult;
    if (result == NULL) {
        napi_get_null(env, &jsResult);
    } else {
        napi_create_string_utf8(env, result, NAPI_AUTO_LENGTH, &jsResult);
    }
    return jsResult;
}

napi_value BindNode_GetFileName(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    size_t filePath_len;
    napi_get_value_string_utf8(env, args[0], NULL, 0, &filePath_len);
    char* filePath = (char*)malloc(filePath_len + 1);
    napi_get_value_string_utf8(env, args[0], filePath, filePath_len + 1, &filePath_len);

    const char * result = GetFileName(filePath);
    free(filePath);
    napi_value jsResult;
    if (result == NULL) {
        napi_get_null(env, &jsResult);
    } else {
        napi_create_string_utf8(env, result, NAPI_AUTO_LENGTH, &jsResult);
    }
    return jsResult;
}

napi_value BindNode_GetFileNameWithoutExt(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    size_t filePath_len;
    napi_get_value_string_utf8(env, args[0], NULL, 0, &filePath_len);
    char* filePath = (char*)malloc(filePath_len + 1);
    napi_get_value_string_utf8(env, args[0], filePath, filePath_len + 1, &filePath_len);

    const char * result = GetFileNameWithoutExt(filePath);
    free(filePath);
    napi_value jsResult;
    if (result == NULL) {
        napi_get_null(env, &jsResult);
    } else {
        napi_create_string_utf8(env, result, NAPI_AUTO_LENGTH, &jsResult);
    }
    return jsResult;
}

napi_value BindNode_GetDirectoryPath(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    size_t filePath_len;
    napi_get_value_string_utf8(env, args[0], NULL, 0, &filePath_len);
    char* filePath = (char*)malloc(filePath_len + 1);
    napi_get_value_string_utf8(env, args[0], filePath, filePath_len + 1, &filePath_len);

    const char * result = GetDirectoryPath(filePath);
    free(filePath);
    napi_value jsResult;
    if (result == NULL) {
        napi_get_null(env, &jsResult);
    } else {
        napi_create_string_utf8(env, result, NAPI_AUTO_LENGTH, &jsResult);
    }
    return jsResult;
}

napi_value BindNode_GetPrevDirectoryPath(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    size_t dirPath_len;
    napi_get_value_string_utf8(env, args[0], NULL, 0, &dirPath_len);
    char* dirPath = (char*)malloc(dirPath_len + 1);
    napi_get_value_string_utf8(env, args[0], dirPath, dirPath_len + 1, &dirPath_len);

    const char * result = GetPrevDirectoryPath(dirPath);
    free(dirPath);
    napi_value jsResult;
    if (result == NULL) {
        napi_get_null(env, &jsResult);
    } else {
        napi_create_string_utf8(env, result, NAPI_AUTO_LENGTH, &jsResult);
    }
    return jsResult;
}

napi_value BindNode_GetWorkingDirectory(napi_env env, napi_callback_info info) {
    const char * result = GetWorkingDirectory();
    napi_value jsResult;
    if (result == NULL) {
        napi_get_null(env, &jsResult);
    } else {
        napi_create_string_utf8(env, result, NAPI_AUTO_LENGTH, &jsResult);
    }
    return jsResult;
}

napi_value BindNode_GetApplicationDirectory(napi_env env, napi_callback_info info) {
    const char * result = GetApplicationDirectory();
    napi_value jsResult;
    if (result == NULL) {
        napi_get_null(env, &jsResult);
    } else {
        napi_create_string_utf8(env, result, NAPI_AUTO_LENGTH, &jsResult);
    }
    return jsResult;
}

napi_value BindNode_MakeDirectory(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    size_t dirPath_len;
    napi_get_value_string_utf8(env, args[0], NULL, 0, &dirPath_len);
    char* dirPath = (char*)malloc(dirPath_len + 1);
    napi_get_value_string_utf8(env, args[0], dirPath, dirPath_len + 1, &dirPath_len);

    int result = MakeDirectory(dirPath);
    free(dirPath);
    return int_to_js(env, result);
}

napi_value BindNode_ChangeDirectory(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    size_t dir_len;
    napi_get_value_string_utf8(env, args[0], NULL, 0, &dir_len);
    char* dir = (char*)malloc(dir_len + 1);
    napi_get_value_string_utf8(env, args[0], dir, dir_len + 1, &dir_len);

    bool result = ChangeDirectory(dir);
    free(dir);
    napi_value jsResult;
    napi_get_boolean(env, result, &jsResult);
    return jsResult;
}

napi_value BindNode_IsPathFile(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    size_t path_len;
    napi_get_value_string_utf8(env, args[0], NULL, 0, &path_len);
    char* path = (char*)malloc(path_len + 1);
    napi_get_value_string_utf8(env, args[0], path, path_len + 1, &path_len);

    bool result = IsPathFile(path);
    free(path);
    napi_value jsResult;
    napi_get_boolean(env, result, &jsResult);
    return jsResult;
}

napi_value BindNode_IsFileNameValid(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    size_t fileName_len;
    napi_get_value_string_utf8(env, args[0], NULL, 0, &fileName_len);
    char* fileName = (char*)malloc(fileName_len + 1);
    napi_get_value_string_utf8(env, args[0], fileName, fileName_len + 1, &fileName_len);

    bool result = IsFileNameValid(fileName);
    free(fileName);
    napi_value jsResult;
    napi_get_boolean(env, result, &jsResult);
    return jsResult;
}

napi_value BindNode_LoadDirectoryFiles(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    size_t dirPath_len;
    napi_get_value_string_utf8(env, args[0], NULL, 0, &dirPath_len);
    char* dirPath = (char*)malloc(dirPath_len + 1);
    napi_get_value_string_utf8(env, args[0], dirPath, dirPath_len + 1, &dirPath_len);

    FilePathList result = LoadDirectoryFiles(dirPath);
    free(dirPath);
    return FilePathList_to_js(env, result);
}

napi_value BindNode_LoadDirectoryFilesEx(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value args[3];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 3) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    size_t basePath_len;
    napi_get_value_string_utf8(env, args[0], NULL, 0, &basePath_len);
    char* basePath = (char*)malloc(basePath_len + 1);
    napi_get_value_string_utf8(env, args[0], basePath, basePath_len + 1, &basePath_len);

    size_t filter_len;
    napi_get_value_string_utf8(env, args[1], NULL, 0, &filter_len);
    char* filter = (char*)malloc(filter_len + 1);
    napi_get_value_string_utf8(env, args[1], filter, filter_len + 1, &filter_len);

    bool scanSubdirs;
    napi_get_value_bool(env, args[2], &scanSubdirs);

    FilePathList result = LoadDirectoryFilesEx(basePath, filter, scanSubdirs);
    free(basePath);
    free(filter);
    return FilePathList_to_js(env, result);
}

napi_value BindNode_UnloadDirectoryFiles(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    FilePathList files = FilePathList_from_js(env, args[0]);

    UnloadDirectoryFiles(files);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_IsFileDropped(napi_env env, napi_callback_info info) {
    bool result = IsFileDropped();
    napi_value jsResult;
    napi_get_boolean(env, result, &jsResult);
    return jsResult;
}

napi_value BindNode_LoadDroppedFiles(napi_env env, napi_callback_info info) {
    FilePathList result = LoadDroppedFiles();
    return FilePathList_to_js(env, result);
}

napi_value BindNode_UnloadDroppedFiles(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    FilePathList files = FilePathList_from_js(env, args[0]);

    UnloadDroppedFiles(files);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_GetFileModTime(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    size_t fileName_len;
    napi_get_value_string_utf8(env, args[0], NULL, 0, &fileName_len);
    char* fileName = (char*)malloc(fileName_len + 1);
    napi_get_value_string_utf8(env, args[0], fileName, fileName_len + 1, &fileName_len);

    long result = GetFileModTime(fileName);
    free(fileName);
    napi_value jsResult;
    napi_create_int64(env, (int64_t)result, &jsResult);
    return jsResult;
}

napi_value BindNode_CompressData(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value args[3];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 3) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    // Warning: No conversion available for const unsigned char
    const unsigned char * data = NULL;

    int dataSize;
    napi_get_value_int32(env, args[1], (int32_t*)&dataSize);

    int compDataSize_value = int_from_js(env, args[2]);
    int * compDataSize = &compDataSize_value;

    unsigned char * result = CompressData(data, dataSize, compDataSize);
    // TODO: Handle return type unsigned char *
    napi_value jsResult;
    napi_get_null(env, &jsResult);
    return jsResult; // Placeholder
}

napi_value BindNode_DecompressData(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value args[3];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 3) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    // Warning: No conversion available for const unsigned char
    const unsigned char * compData = NULL;

    int compDataSize;
    napi_get_value_int32(env, args[1], (int32_t*)&compDataSize);

    int dataSize_value = int_from_js(env, args[2]);
    int * dataSize = &dataSize_value;

    unsigned char * result = DecompressData(compData, compDataSize, dataSize);
    // TODO: Handle return type unsigned char *
    napi_value jsResult;
    napi_get_null(env, &jsResult);
    return jsResult; // Placeholder
}

napi_value BindNode_EncodeDataBase64(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value args[3];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 3) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    // Warning: No conversion available for const unsigned char
    const unsigned char * data = NULL;

    int dataSize;
    napi_get_value_int32(env, args[1], (int32_t*)&dataSize);

    int outputSize_value = int_from_js(env, args[2]);
    int * outputSize = &outputSize_value;

    char * result = EncodeDataBase64(data, dataSize, outputSize);
    napi_value jsResult;
    if (result == NULL) {
        napi_get_null(env, &jsResult);
    } else {
        napi_create_string_utf8(env, result, NAPI_AUTO_LENGTH, &jsResult);
    }
    return jsResult;
}

napi_value BindNode_DecodeDataBase64(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    // Warning: No conversion available for const unsigned char
    const unsigned char * data = NULL;

    int outputSize_value = int_from_js(env, args[1]);
    int * outputSize = &outputSize_value;

    unsigned char * result = DecodeDataBase64(data, outputSize);
    // TODO: Handle return type unsigned char *
    napi_value jsResult;
    napi_get_null(env, &jsResult);
    return jsResult; // Placeholder
}

napi_value BindNode_ComputeCRC32(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    unsigned char data_value = unsigned_char_from_js(env, args[0]);
    unsigned char * data = &data_value;

    int dataSize;
    napi_get_value_int32(env, args[1], (int32_t*)&dataSize);

    unsigned int result = ComputeCRC32(data, dataSize);
    napi_value jsResult;
    napi_create_int32(env, (int32_t)result, &jsResult);
    return jsResult;
}

napi_value BindNode_ComputeMD5(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    unsigned char data_value = unsigned_char_from_js(env, args[0]);
    unsigned char * data = &data_value;

    int dataSize;
    napi_get_value_int32(env, args[1], (int32_t*)&dataSize);

    unsigned int * result = ComputeMD5(data, dataSize);
    // TODO: Handle return type unsigned int *
    napi_value jsResult;
    napi_get_null(env, &jsResult);
    return jsResult; // Placeholder
}

napi_value BindNode_ComputeSHA1(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    unsigned char data_value = unsigned_char_from_js(env, args[0]);
    unsigned char * data = &data_value;

    int dataSize;
    napi_get_value_int32(env, args[1], (int32_t*)&dataSize);

    unsigned int * result = ComputeSHA1(data, dataSize);
    // TODO: Handle return type unsigned int *
    napi_value jsResult;
    napi_get_null(env, &jsResult);
    return jsResult; // Placeholder
}

napi_value BindNode_LoadAutomationEventList(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    size_t fileName_len;
    napi_get_value_string_utf8(env, args[0], NULL, 0, &fileName_len);
    char* fileName = (char*)malloc(fileName_len + 1);
    napi_get_value_string_utf8(env, args[0], fileName, fileName_len + 1, &fileName_len);

    AutomationEventList result = LoadAutomationEventList(fileName);
    free(fileName);
    return AutomationEventList_to_js(env, result);
}

napi_value BindNode_UnloadAutomationEventList(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    AutomationEventList list = AutomationEventList_from_js(env, args[0]);

    UnloadAutomationEventList(list);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_ExportAutomationEventList(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    AutomationEventList list = AutomationEventList_from_js(env, args[0]);

    size_t fileName_len;
    napi_get_value_string_utf8(env, args[1], NULL, 0, &fileName_len);
    char* fileName = (char*)malloc(fileName_len + 1);
    napi_get_value_string_utf8(env, args[1], fileName, fileName_len + 1, &fileName_len);

    bool result = ExportAutomationEventList(list, fileName);
    free(fileName);
    napi_value jsResult;
    napi_get_boolean(env, result, &jsResult);
    return jsResult;
}

napi_value BindNode_SetAutomationEventList(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    AutomationEventList list_value = AutomationEventList_from_js(env, args[0]);
    AutomationEventList * list = &list_value;

    SetAutomationEventList(list);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_SetAutomationEventBaseFrame(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    int frame;
    napi_get_value_int32(env, args[0], (int32_t*)&frame);

    SetAutomationEventBaseFrame(frame);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_StartAutomationEventRecording(napi_env env, napi_callback_info info) {
    StartAutomationEventRecording();
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_StopAutomationEventRecording(napi_env env, napi_callback_info info) {
    StopAutomationEventRecording();
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_PlayAutomationEvent(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    AutomationEvent event = AutomationEvent_from_js(env, args[0]);

    PlayAutomationEvent(event);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_IsKeyPressed(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    int key;
    napi_get_value_int32(env, args[0], (int32_t*)&key);

    bool result = IsKeyPressed(key);
    napi_value jsResult;
    napi_get_boolean(env, result, &jsResult);
    return jsResult;
}

napi_value BindNode_IsKeyPressedRepeat(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    int key;
    napi_get_value_int32(env, args[0], (int32_t*)&key);

    bool result = IsKeyPressedRepeat(key);
    napi_value jsResult;
    napi_get_boolean(env, result, &jsResult);
    return jsResult;
}

napi_value BindNode_IsKeyDown(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    int key;
    napi_get_value_int32(env, args[0], (int32_t*)&key);

    bool result = IsKeyDown(key);
    napi_value jsResult;
    napi_get_boolean(env, result, &jsResult);
    return jsResult;
}

napi_value BindNode_IsKeyReleased(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    int key;
    napi_get_value_int32(env, args[0], (int32_t*)&key);

    bool result = IsKeyReleased(key);
    napi_value jsResult;
    napi_get_boolean(env, result, &jsResult);
    return jsResult;
}

napi_value BindNode_IsKeyUp(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    int key;
    napi_get_value_int32(env, args[0], (int32_t*)&key);

    bool result = IsKeyUp(key);
    napi_value jsResult;
    napi_get_boolean(env, result, &jsResult);
    return jsResult;
}

napi_value BindNode_GetKeyPressed(napi_env env, napi_callback_info info) {
    int result = GetKeyPressed();
    return int_to_js(env, result);
}

napi_value BindNode_GetCharPressed(napi_env env, napi_callback_info info) {
    int result = GetCharPressed();
    return int_to_js(env, result);
}

napi_value BindNode_SetExitKey(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    int key;
    napi_get_value_int32(env, args[0], (int32_t*)&key);

    SetExitKey(key);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_IsGamepadAvailable(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    int gamepad;
    napi_get_value_int32(env, args[0], (int32_t*)&gamepad);

    bool result = IsGamepadAvailable(gamepad);
    napi_value jsResult;
    napi_get_boolean(env, result, &jsResult);
    return jsResult;
}

napi_value BindNode_GetGamepadName(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    int gamepad;
    napi_get_value_int32(env, args[0], (int32_t*)&gamepad);

    const char * result = GetGamepadName(gamepad);
    napi_value jsResult;
    if (result == NULL) {
        napi_get_null(env, &jsResult);
    } else {
        napi_create_string_utf8(env, result, NAPI_AUTO_LENGTH, &jsResult);
    }
    return jsResult;
}

napi_value BindNode_IsGamepadButtonPressed(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    int gamepad;
    napi_get_value_int32(env, args[0], (int32_t*)&gamepad);

    int button;
    napi_get_value_int32(env, args[1], (int32_t*)&button);

    bool result = IsGamepadButtonPressed(gamepad, button);
    napi_value jsResult;
    napi_get_boolean(env, result, &jsResult);
    return jsResult;
}

napi_value BindNode_IsGamepadButtonDown(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    int gamepad;
    napi_get_value_int32(env, args[0], (int32_t*)&gamepad);

    int button;
    napi_get_value_int32(env, args[1], (int32_t*)&button);

    bool result = IsGamepadButtonDown(gamepad, button);
    napi_value jsResult;
    napi_get_boolean(env, result, &jsResult);
    return jsResult;
}

napi_value BindNode_IsGamepadButtonReleased(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    int gamepad;
    napi_get_value_int32(env, args[0], (int32_t*)&gamepad);

    int button;
    napi_get_value_int32(env, args[1], (int32_t*)&button);

    bool result = IsGamepadButtonReleased(gamepad, button);
    napi_value jsResult;
    napi_get_boolean(env, result, &jsResult);
    return jsResult;
}

napi_value BindNode_IsGamepadButtonUp(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    int gamepad;
    napi_get_value_int32(env, args[0], (int32_t*)&gamepad);

    int button;
    napi_get_value_int32(env, args[1], (int32_t*)&button);

    bool result = IsGamepadButtonUp(gamepad, button);
    napi_value jsResult;
    napi_get_boolean(env, result, &jsResult);
    return jsResult;
}

napi_value BindNode_GetGamepadButtonPressed(napi_env env, napi_callback_info info) {
    int result = GetGamepadButtonPressed();
    return int_to_js(env, result);
}

napi_value BindNode_GetGamepadAxisCount(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    int gamepad;
    napi_get_value_int32(env, args[0], (int32_t*)&gamepad);

    int result = GetGamepadAxisCount(gamepad);
    return int_to_js(env, result);
}

napi_value BindNode_GetGamepadAxisMovement(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    int gamepad;
    napi_get_value_int32(env, args[0], (int32_t*)&gamepad);

    int axis;
    napi_get_value_int32(env, args[1], (int32_t*)&axis);

    float result = GetGamepadAxisMovement(gamepad, axis);
    return float_to_js(env, result);
}

napi_value BindNode_SetGamepadMappings(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    size_t mappings_len;
    napi_get_value_string_utf8(env, args[0], NULL, 0, &mappings_len);
    char* mappings = (char*)malloc(mappings_len + 1);
    napi_get_value_string_utf8(env, args[0], mappings, mappings_len + 1, &mappings_len);

    int result = SetGamepadMappings(mappings);
    free(mappings);
    return int_to_js(env, result);
}

napi_value BindNode_SetGamepadVibration(napi_env env, napi_callback_info info) {
    size_t argc = 4;
    napi_value args[4];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 4) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    int gamepad;
    napi_get_value_int32(env, args[0], (int32_t*)&gamepad);

    double temp_leftMotor;
    napi_get_value_double(env, args[1], &temp_leftMotor);
    float leftMotor = (float)temp_leftMotor;

    double temp_rightMotor;
    napi_get_value_double(env, args[2], &temp_rightMotor);
    float rightMotor = (float)temp_rightMotor;

    double temp_duration;
    napi_get_value_double(env, args[3], &temp_duration);
    float duration = (float)temp_duration;

    SetGamepadVibration(gamepad, leftMotor, rightMotor, duration);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_IsMouseButtonPressed(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    int button;
    napi_get_value_int32(env, args[0], (int32_t*)&button);

    bool result = IsMouseButtonPressed(button);
    napi_value jsResult;
    napi_get_boolean(env, result, &jsResult);
    return jsResult;
}

napi_value BindNode_IsMouseButtonDown(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    int button;
    napi_get_value_int32(env, args[0], (int32_t*)&button);

    bool result = IsMouseButtonDown(button);
    napi_value jsResult;
    napi_get_boolean(env, result, &jsResult);
    return jsResult;
}

napi_value BindNode_IsMouseButtonReleased(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    int button;
    napi_get_value_int32(env, args[0], (int32_t*)&button);

    bool result = IsMouseButtonReleased(button);
    napi_value jsResult;
    napi_get_boolean(env, result, &jsResult);
    return jsResult;
}

napi_value BindNode_IsMouseButtonUp(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    int button;
    napi_get_value_int32(env, args[0], (int32_t*)&button);

    bool result = IsMouseButtonUp(button);
    napi_value jsResult;
    napi_get_boolean(env, result, &jsResult);
    return jsResult;
}

napi_value BindNode_GetMouseX(napi_env env, napi_callback_info info) {
    int result = GetMouseX();
    return int_to_js(env, result);
}

napi_value BindNode_GetMouseY(napi_env env, napi_callback_info info) {
    int result = GetMouseY();
    return int_to_js(env, result);
}

napi_value BindNode_GetMousePosition(napi_env env, napi_callback_info info) {
    Vector2 result = GetMousePosition();
    return Vector2_to_js(env, result);
}

napi_value BindNode_GetMouseDelta(napi_env env, napi_callback_info info) {
    Vector2 result = GetMouseDelta();
    return Vector2_to_js(env, result);
}

napi_value BindNode_SetMousePosition(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    int x;
    napi_get_value_int32(env, args[0], (int32_t*)&x);

    int y;
    napi_get_value_int32(env, args[1], (int32_t*)&y);

    SetMousePosition(x, y);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_SetMouseOffset(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    int offsetX;
    napi_get_value_int32(env, args[0], (int32_t*)&offsetX);

    int offsetY;
    napi_get_value_int32(env, args[1], (int32_t*)&offsetY);

    SetMouseOffset(offsetX, offsetY);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_SetMouseScale(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    double temp_scaleX;
    napi_get_value_double(env, args[0], &temp_scaleX);
    float scaleX = (float)temp_scaleX;

    double temp_scaleY;
    napi_get_value_double(env, args[1], &temp_scaleY);
    float scaleY = (float)temp_scaleY;

    SetMouseScale(scaleX, scaleY);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_GetMouseWheelMove(napi_env env, napi_callback_info info) {
    float result = GetMouseWheelMove();
    return float_to_js(env, result);
}

napi_value BindNode_GetMouseWheelMoveV(napi_env env, napi_callback_info info) {
    Vector2 result = GetMouseWheelMoveV();
    return Vector2_to_js(env, result);
}

napi_value BindNode_SetMouseCursor(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    int cursor;
    napi_get_value_int32(env, args[0], (int32_t*)&cursor);

    SetMouseCursor(cursor);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_GetTouchX(napi_env env, napi_callback_info info) {
    int result = GetTouchX();
    return int_to_js(env, result);
}

napi_value BindNode_GetTouchY(napi_env env, napi_callback_info info) {
    int result = GetTouchY();
    return int_to_js(env, result);
}

napi_value BindNode_GetTouchPosition(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    int index;
    napi_get_value_int32(env, args[0], (int32_t*)&index);

    Vector2 result = GetTouchPosition(index);
    return Vector2_to_js(env, result);
}

napi_value BindNode_GetTouchPointId(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    int index;
    napi_get_value_int32(env, args[0], (int32_t*)&index);

    int result = GetTouchPointId(index);
    return int_to_js(env, result);
}

napi_value BindNode_GetTouchPointCount(napi_env env, napi_callback_info info) {
    int result = GetTouchPointCount();
    return int_to_js(env, result);
}

napi_value BindNode_SetGesturesEnabled(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    unsigned int flags;
    napi_get_value_int32(env, args[0], (int32_t*)&flags);

    SetGesturesEnabled(flags);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_IsGestureDetected(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    unsigned int gesture;
    napi_get_value_int32(env, args[0], (int32_t*)&gesture);

    bool result = IsGestureDetected(gesture);
    napi_value jsResult;
    napi_get_boolean(env, result, &jsResult);
    return jsResult;
}

napi_value BindNode_GetGestureDetected(napi_env env, napi_callback_info info) {
    int result = GetGestureDetected();
    return int_to_js(env, result);
}

napi_value BindNode_GetGestureHoldDuration(napi_env env, napi_callback_info info) {
    float result = GetGestureHoldDuration();
    return float_to_js(env, result);
}

napi_value BindNode_GetGestureDragVector(napi_env env, napi_callback_info info) {
    Vector2 result = GetGestureDragVector();
    return Vector2_to_js(env, result);
}

napi_value BindNode_GetGestureDragAngle(napi_env env, napi_callback_info info) {
    float result = GetGestureDragAngle();
    return float_to_js(env, result);
}

napi_value BindNode_GetGesturePinchVector(napi_env env, napi_callback_info info) {
    Vector2 result = GetGesturePinchVector();
    return Vector2_to_js(env, result);
}

napi_value BindNode_GetGesturePinchAngle(napi_env env, napi_callback_info info) {
    float result = GetGesturePinchAngle();
    return float_to_js(env, result);
}

napi_value BindNode_UpdateCamera(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Camera camera_value = Camera_from_js(env, args[0]);
    Camera * camera = &camera_value;

    int mode;
    napi_get_value_int32(env, args[1], (int32_t*)&mode);

    UpdateCamera(camera, mode);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_UpdateCameraPro(napi_env env, napi_callback_info info) {
    size_t argc = 4;
    napi_value args[4];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 4) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Camera camera_value = Camera_from_js(env, args[0]);
    Camera * camera = &camera_value;

    Vector3 movement = Vector3_from_js(env, args[1]);

    Vector3 rotation = Vector3_from_js(env, args[2]);

    double temp_zoom;
    napi_get_value_double(env, args[3], &temp_zoom);
    float zoom = (float)temp_zoom;

    UpdateCameraPro(camera, movement, rotation, zoom);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_SetShapesTexture(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Texture2D texture = Texture2D_from_js(env, args[0]);

    Rectangle source = Rectangle_from_js(env, args[1]);

    SetShapesTexture(texture, source);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_GetShapesTexture(napi_env env, napi_callback_info info) {
    Texture2D result = GetShapesTexture();
    return Texture2D_to_js(env, result);
}

napi_value BindNode_GetShapesTextureRectangle(napi_env env, napi_callback_info info) {
    Rectangle result = GetShapesTextureRectangle();
    return Rectangle_to_js(env, result);
}

napi_value BindNode_DrawPixel(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value args[3];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 3) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    int posX;
    napi_get_value_int32(env, args[0], (int32_t*)&posX);

    int posY;
    napi_get_value_int32(env, args[1], (int32_t*)&posY);

    Color color = Color_from_js(env, args[2]);

    DrawPixel(posX, posY, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawPixelV(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Vector2 position = Vector2_from_js(env, args[0]);

    Color color = Color_from_js(env, args[1]);

    DrawPixelV(position, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawLine(napi_env env, napi_callback_info info) {
    size_t argc = 5;
    napi_value args[5];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 5) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    int startPosX;
    napi_get_value_int32(env, args[0], (int32_t*)&startPosX);

    int startPosY;
    napi_get_value_int32(env, args[1], (int32_t*)&startPosY);

    int endPosX;
    napi_get_value_int32(env, args[2], (int32_t*)&endPosX);

    int endPosY;
    napi_get_value_int32(env, args[3], (int32_t*)&endPosY);

    Color color = Color_from_js(env, args[4]);

    DrawLine(startPosX, startPosY, endPosX, endPosY, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawLineV(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value args[3];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 3) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Vector2 startPos = Vector2_from_js(env, args[0]);

    Vector2 endPos = Vector2_from_js(env, args[1]);

    Color color = Color_from_js(env, args[2]);

    DrawLineV(startPos, endPos, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawLineEx(napi_env env, napi_callback_info info) {
    size_t argc = 4;
    napi_value args[4];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 4) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Vector2 startPos = Vector2_from_js(env, args[0]);

    Vector2 endPos = Vector2_from_js(env, args[1]);

    double temp_thick;
    napi_get_value_double(env, args[2], &temp_thick);
    float thick = (float)temp_thick;

    Color color = Color_from_js(env, args[3]);

    DrawLineEx(startPos, endPos, thick, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawLineStrip(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value args[3];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 3) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    // Warning: No conversion available for const Vector2
    const Vector2 * points = NULL;

    int pointCount;
    napi_get_value_int32(env, args[1], (int32_t*)&pointCount);

    Color color = Color_from_js(env, args[2]);

    DrawLineStrip(points, pointCount, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawLineBezier(napi_env env, napi_callback_info info) {
    size_t argc = 4;
    napi_value args[4];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 4) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Vector2 startPos = Vector2_from_js(env, args[0]);

    Vector2 endPos = Vector2_from_js(env, args[1]);

    double temp_thick;
    napi_get_value_double(env, args[2], &temp_thick);
    float thick = (float)temp_thick;

    Color color = Color_from_js(env, args[3]);

    DrawLineBezier(startPos, endPos, thick, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawCircle(napi_env env, napi_callback_info info) {
    size_t argc = 4;
    napi_value args[4];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 4) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    int centerX;
    napi_get_value_int32(env, args[0], (int32_t*)&centerX);

    int centerY;
    napi_get_value_int32(env, args[1], (int32_t*)&centerY);

    double temp_radius;
    napi_get_value_double(env, args[2], &temp_radius);
    float radius = (float)temp_radius;

    Color color = Color_from_js(env, args[3]);

    DrawCircle(centerX, centerY, radius, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawCircleSector(napi_env env, napi_callback_info info) {
    size_t argc = 6;
    napi_value args[6];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 6) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Vector2 center = Vector2_from_js(env, args[0]);

    double temp_radius;
    napi_get_value_double(env, args[1], &temp_radius);
    float radius = (float)temp_radius;

    double temp_startAngle;
    napi_get_value_double(env, args[2], &temp_startAngle);
    float startAngle = (float)temp_startAngle;

    double temp_endAngle;
    napi_get_value_double(env, args[3], &temp_endAngle);
    float endAngle = (float)temp_endAngle;

    int segments;
    napi_get_value_int32(env, args[4], (int32_t*)&segments);

    Color color = Color_from_js(env, args[5]);

    DrawCircleSector(center, radius, startAngle, endAngle, segments, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawCircleSectorLines(napi_env env, napi_callback_info info) {
    size_t argc = 6;
    napi_value args[6];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 6) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Vector2 center = Vector2_from_js(env, args[0]);

    double temp_radius;
    napi_get_value_double(env, args[1], &temp_radius);
    float radius = (float)temp_radius;

    double temp_startAngle;
    napi_get_value_double(env, args[2], &temp_startAngle);
    float startAngle = (float)temp_startAngle;

    double temp_endAngle;
    napi_get_value_double(env, args[3], &temp_endAngle);
    float endAngle = (float)temp_endAngle;

    int segments;
    napi_get_value_int32(env, args[4], (int32_t*)&segments);

    Color color = Color_from_js(env, args[5]);

    DrawCircleSectorLines(center, radius, startAngle, endAngle, segments, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawCircleGradient(napi_env env, napi_callback_info info) {
    size_t argc = 5;
    napi_value args[5];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 5) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    int centerX;
    napi_get_value_int32(env, args[0], (int32_t*)&centerX);

    int centerY;
    napi_get_value_int32(env, args[1], (int32_t*)&centerY);

    double temp_radius;
    napi_get_value_double(env, args[2], &temp_radius);
    float radius = (float)temp_radius;

    Color inner = Color_from_js(env, args[3]);

    Color outer = Color_from_js(env, args[4]);

    DrawCircleGradient(centerX, centerY, radius, inner, outer);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawCircleV(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value args[3];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 3) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Vector2 center = Vector2_from_js(env, args[0]);

    double temp_radius;
    napi_get_value_double(env, args[1], &temp_radius);
    float radius = (float)temp_radius;

    Color color = Color_from_js(env, args[2]);

    DrawCircleV(center, radius, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawCircleLines(napi_env env, napi_callback_info info) {
    size_t argc = 4;
    napi_value args[4];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 4) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    int centerX;
    napi_get_value_int32(env, args[0], (int32_t*)&centerX);

    int centerY;
    napi_get_value_int32(env, args[1], (int32_t*)&centerY);

    double temp_radius;
    napi_get_value_double(env, args[2], &temp_radius);
    float radius = (float)temp_radius;

    Color color = Color_from_js(env, args[3]);

    DrawCircleLines(centerX, centerY, radius, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawCircleLinesV(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value args[3];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 3) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Vector2 center = Vector2_from_js(env, args[0]);

    double temp_radius;
    napi_get_value_double(env, args[1], &temp_radius);
    float radius = (float)temp_radius;

    Color color = Color_from_js(env, args[2]);

    DrawCircleLinesV(center, radius, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawEllipse(napi_env env, napi_callback_info info) {
    size_t argc = 5;
    napi_value args[5];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 5) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    int centerX;
    napi_get_value_int32(env, args[0], (int32_t*)&centerX);

    int centerY;
    napi_get_value_int32(env, args[1], (int32_t*)&centerY);

    double temp_radiusH;
    napi_get_value_double(env, args[2], &temp_radiusH);
    float radiusH = (float)temp_radiusH;

    double temp_radiusV;
    napi_get_value_double(env, args[3], &temp_radiusV);
    float radiusV = (float)temp_radiusV;

    Color color = Color_from_js(env, args[4]);

    DrawEllipse(centerX, centerY, radiusH, radiusV, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawEllipseLines(napi_env env, napi_callback_info info) {
    size_t argc = 5;
    napi_value args[5];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 5) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    int centerX;
    napi_get_value_int32(env, args[0], (int32_t*)&centerX);

    int centerY;
    napi_get_value_int32(env, args[1], (int32_t*)&centerY);

    double temp_radiusH;
    napi_get_value_double(env, args[2], &temp_radiusH);
    float radiusH = (float)temp_radiusH;

    double temp_radiusV;
    napi_get_value_double(env, args[3], &temp_radiusV);
    float radiusV = (float)temp_radiusV;

    Color color = Color_from_js(env, args[4]);

    DrawEllipseLines(centerX, centerY, radiusH, radiusV, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawRing(napi_env env, napi_callback_info info) {
    size_t argc = 7;
    napi_value args[7];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 7) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Vector2 center = Vector2_from_js(env, args[0]);

    double temp_innerRadius;
    napi_get_value_double(env, args[1], &temp_innerRadius);
    float innerRadius = (float)temp_innerRadius;

    double temp_outerRadius;
    napi_get_value_double(env, args[2], &temp_outerRadius);
    float outerRadius = (float)temp_outerRadius;

    double temp_startAngle;
    napi_get_value_double(env, args[3], &temp_startAngle);
    float startAngle = (float)temp_startAngle;

    double temp_endAngle;
    napi_get_value_double(env, args[4], &temp_endAngle);
    float endAngle = (float)temp_endAngle;

    int segments;
    napi_get_value_int32(env, args[5], (int32_t*)&segments);

    Color color = Color_from_js(env, args[6]);

    DrawRing(center, innerRadius, outerRadius, startAngle, endAngle, segments, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawRingLines(napi_env env, napi_callback_info info) {
    size_t argc = 7;
    napi_value args[7];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 7) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Vector2 center = Vector2_from_js(env, args[0]);

    double temp_innerRadius;
    napi_get_value_double(env, args[1], &temp_innerRadius);
    float innerRadius = (float)temp_innerRadius;

    double temp_outerRadius;
    napi_get_value_double(env, args[2], &temp_outerRadius);
    float outerRadius = (float)temp_outerRadius;

    double temp_startAngle;
    napi_get_value_double(env, args[3], &temp_startAngle);
    float startAngle = (float)temp_startAngle;

    double temp_endAngle;
    napi_get_value_double(env, args[4], &temp_endAngle);
    float endAngle = (float)temp_endAngle;

    int segments;
    napi_get_value_int32(env, args[5], (int32_t*)&segments);

    Color color = Color_from_js(env, args[6]);

    DrawRingLines(center, innerRadius, outerRadius, startAngle, endAngle, segments, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawRectangle(napi_env env, napi_callback_info info) {
    size_t argc = 5;
    napi_value args[5];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 5) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    int posX;
    napi_get_value_int32(env, args[0], (int32_t*)&posX);

    int posY;
    napi_get_value_int32(env, args[1], (int32_t*)&posY);

    int width;
    napi_get_value_int32(env, args[2], (int32_t*)&width);

    int height;
    napi_get_value_int32(env, args[3], (int32_t*)&height);

    Color color = Color_from_js(env, args[4]);

    DrawRectangle(posX, posY, width, height, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawRectangleV(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value args[3];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 3) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Vector2 position = Vector2_from_js(env, args[0]);

    Vector2 size = Vector2_from_js(env, args[1]);

    Color color = Color_from_js(env, args[2]);

    DrawRectangleV(position, size, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawRectangleRec(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Rectangle rec = Rectangle_from_js(env, args[0]);

    Color color = Color_from_js(env, args[1]);

    DrawRectangleRec(rec, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawRectanglePro(napi_env env, napi_callback_info info) {
    size_t argc = 4;
    napi_value args[4];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 4) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Rectangle rec = Rectangle_from_js(env, args[0]);

    Vector2 origin = Vector2_from_js(env, args[1]);

    double temp_rotation;
    napi_get_value_double(env, args[2], &temp_rotation);
    float rotation = (float)temp_rotation;

    Color color = Color_from_js(env, args[3]);

    DrawRectanglePro(rec, origin, rotation, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawRectangleGradientV(napi_env env, napi_callback_info info) {
    size_t argc = 6;
    napi_value args[6];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 6) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    int posX;
    napi_get_value_int32(env, args[0], (int32_t*)&posX);

    int posY;
    napi_get_value_int32(env, args[1], (int32_t*)&posY);

    int width;
    napi_get_value_int32(env, args[2], (int32_t*)&width);

    int height;
    napi_get_value_int32(env, args[3], (int32_t*)&height);

    Color top = Color_from_js(env, args[4]);

    Color bottom = Color_from_js(env, args[5]);

    DrawRectangleGradientV(posX, posY, width, height, top, bottom);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawRectangleGradientH(napi_env env, napi_callback_info info) {
    size_t argc = 6;
    napi_value args[6];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 6) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    int posX;
    napi_get_value_int32(env, args[0], (int32_t*)&posX);

    int posY;
    napi_get_value_int32(env, args[1], (int32_t*)&posY);

    int width;
    napi_get_value_int32(env, args[2], (int32_t*)&width);

    int height;
    napi_get_value_int32(env, args[3], (int32_t*)&height);

    Color left = Color_from_js(env, args[4]);

    Color right = Color_from_js(env, args[5]);

    DrawRectangleGradientH(posX, posY, width, height, left, right);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawRectangleGradientEx(napi_env env, napi_callback_info info) {
    size_t argc = 5;
    napi_value args[5];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 5) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Rectangle rec = Rectangle_from_js(env, args[0]);

    Color topLeft = Color_from_js(env, args[1]);

    Color bottomLeft = Color_from_js(env, args[2]);

    Color topRight = Color_from_js(env, args[3]);

    Color bottomRight = Color_from_js(env, args[4]);

    DrawRectangleGradientEx(rec, topLeft, bottomLeft, topRight, bottomRight);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawRectangleLines(napi_env env, napi_callback_info info) {
    size_t argc = 5;
    napi_value args[5];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 5) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    int posX;
    napi_get_value_int32(env, args[0], (int32_t*)&posX);

    int posY;
    napi_get_value_int32(env, args[1], (int32_t*)&posY);

    int width;
    napi_get_value_int32(env, args[2], (int32_t*)&width);

    int height;
    napi_get_value_int32(env, args[3], (int32_t*)&height);

    Color color = Color_from_js(env, args[4]);

    DrawRectangleLines(posX, posY, width, height, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawRectangleLinesEx(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value args[3];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 3) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Rectangle rec = Rectangle_from_js(env, args[0]);

    double temp_lineThick;
    napi_get_value_double(env, args[1], &temp_lineThick);
    float lineThick = (float)temp_lineThick;

    Color color = Color_from_js(env, args[2]);

    DrawRectangleLinesEx(rec, lineThick, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawRectangleRounded(napi_env env, napi_callback_info info) {
    size_t argc = 4;
    napi_value args[4];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 4) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Rectangle rec = Rectangle_from_js(env, args[0]);

    double temp_roundness;
    napi_get_value_double(env, args[1], &temp_roundness);
    float roundness = (float)temp_roundness;

    int segments;
    napi_get_value_int32(env, args[2], (int32_t*)&segments);

    Color color = Color_from_js(env, args[3]);

    DrawRectangleRounded(rec, roundness, segments, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawRectangleRoundedLines(napi_env env, napi_callback_info info) {
    size_t argc = 4;
    napi_value args[4];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 4) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Rectangle rec = Rectangle_from_js(env, args[0]);

    double temp_roundness;
    napi_get_value_double(env, args[1], &temp_roundness);
    float roundness = (float)temp_roundness;

    int segments;
    napi_get_value_int32(env, args[2], (int32_t*)&segments);

    Color color = Color_from_js(env, args[3]);

    DrawRectangleRoundedLines(rec, roundness, segments, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawRectangleRoundedLinesEx(napi_env env, napi_callback_info info) {
    size_t argc = 5;
    napi_value args[5];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 5) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Rectangle rec = Rectangle_from_js(env, args[0]);

    double temp_roundness;
    napi_get_value_double(env, args[1], &temp_roundness);
    float roundness = (float)temp_roundness;

    int segments;
    napi_get_value_int32(env, args[2], (int32_t*)&segments);

    double temp_lineThick;
    napi_get_value_double(env, args[3], &temp_lineThick);
    float lineThick = (float)temp_lineThick;

    Color color = Color_from_js(env, args[4]);

    DrawRectangleRoundedLinesEx(rec, roundness, segments, lineThick, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawTriangle(napi_env env, napi_callback_info info) {
    size_t argc = 4;
    napi_value args[4];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 4) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Vector2 v1 = Vector2_from_js(env, args[0]);

    Vector2 v2 = Vector2_from_js(env, args[1]);

    Vector2 v3 = Vector2_from_js(env, args[2]);

    Color color = Color_from_js(env, args[3]);

    DrawTriangle(v1, v2, v3, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawTriangleLines(napi_env env, napi_callback_info info) {
    size_t argc = 4;
    napi_value args[4];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 4) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Vector2 v1 = Vector2_from_js(env, args[0]);

    Vector2 v2 = Vector2_from_js(env, args[1]);

    Vector2 v3 = Vector2_from_js(env, args[2]);

    Color color = Color_from_js(env, args[3]);

    DrawTriangleLines(v1, v2, v3, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawTriangleFan(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value args[3];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 3) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    // Warning: No conversion available for const Vector2
    const Vector2 * points = NULL;

    int pointCount;
    napi_get_value_int32(env, args[1], (int32_t*)&pointCount);

    Color color = Color_from_js(env, args[2]);

    DrawTriangleFan(points, pointCount, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawTriangleStrip(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value args[3];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 3) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    // Warning: No conversion available for const Vector2
    const Vector2 * points = NULL;

    int pointCount;
    napi_get_value_int32(env, args[1], (int32_t*)&pointCount);

    Color color = Color_from_js(env, args[2]);

    DrawTriangleStrip(points, pointCount, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawPoly(napi_env env, napi_callback_info info) {
    size_t argc = 5;
    napi_value args[5];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 5) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Vector2 center = Vector2_from_js(env, args[0]);

    int sides;
    napi_get_value_int32(env, args[1], (int32_t*)&sides);

    double temp_radius;
    napi_get_value_double(env, args[2], &temp_radius);
    float radius = (float)temp_radius;

    double temp_rotation;
    napi_get_value_double(env, args[3], &temp_rotation);
    float rotation = (float)temp_rotation;

    Color color = Color_from_js(env, args[4]);

    DrawPoly(center, sides, radius, rotation, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawPolyLines(napi_env env, napi_callback_info info) {
    size_t argc = 5;
    napi_value args[5];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 5) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Vector2 center = Vector2_from_js(env, args[0]);

    int sides;
    napi_get_value_int32(env, args[1], (int32_t*)&sides);

    double temp_radius;
    napi_get_value_double(env, args[2], &temp_radius);
    float radius = (float)temp_radius;

    double temp_rotation;
    napi_get_value_double(env, args[3], &temp_rotation);
    float rotation = (float)temp_rotation;

    Color color = Color_from_js(env, args[4]);

    DrawPolyLines(center, sides, radius, rotation, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawPolyLinesEx(napi_env env, napi_callback_info info) {
    size_t argc = 6;
    napi_value args[6];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 6) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Vector2 center = Vector2_from_js(env, args[0]);

    int sides;
    napi_get_value_int32(env, args[1], (int32_t*)&sides);

    double temp_radius;
    napi_get_value_double(env, args[2], &temp_radius);
    float radius = (float)temp_radius;

    double temp_rotation;
    napi_get_value_double(env, args[3], &temp_rotation);
    float rotation = (float)temp_rotation;

    double temp_lineThick;
    napi_get_value_double(env, args[4], &temp_lineThick);
    float lineThick = (float)temp_lineThick;

    Color color = Color_from_js(env, args[5]);

    DrawPolyLinesEx(center, sides, radius, rotation, lineThick, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawSplineLinear(napi_env env, napi_callback_info info) {
    size_t argc = 4;
    napi_value args[4];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 4) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    // Warning: No conversion available for const Vector2
    const Vector2 * points = NULL;

    int pointCount;
    napi_get_value_int32(env, args[1], (int32_t*)&pointCount);

    double temp_thick;
    napi_get_value_double(env, args[2], &temp_thick);
    float thick = (float)temp_thick;

    Color color = Color_from_js(env, args[3]);

    DrawSplineLinear(points, pointCount, thick, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawSplineBasis(napi_env env, napi_callback_info info) {
    size_t argc = 4;
    napi_value args[4];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 4) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    // Warning: No conversion available for const Vector2
    const Vector2 * points = NULL;

    int pointCount;
    napi_get_value_int32(env, args[1], (int32_t*)&pointCount);

    double temp_thick;
    napi_get_value_double(env, args[2], &temp_thick);
    float thick = (float)temp_thick;

    Color color = Color_from_js(env, args[3]);

    DrawSplineBasis(points, pointCount, thick, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawSplineCatmullRom(napi_env env, napi_callback_info info) {
    size_t argc = 4;
    napi_value args[4];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 4) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    // Warning: No conversion available for const Vector2
    const Vector2 * points = NULL;

    int pointCount;
    napi_get_value_int32(env, args[1], (int32_t*)&pointCount);

    double temp_thick;
    napi_get_value_double(env, args[2], &temp_thick);
    float thick = (float)temp_thick;

    Color color = Color_from_js(env, args[3]);

    DrawSplineCatmullRom(points, pointCount, thick, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawSplineBezierQuadratic(napi_env env, napi_callback_info info) {
    size_t argc = 4;
    napi_value args[4];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 4) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    // Warning: No conversion available for const Vector2
    const Vector2 * points = NULL;

    int pointCount;
    napi_get_value_int32(env, args[1], (int32_t*)&pointCount);

    double temp_thick;
    napi_get_value_double(env, args[2], &temp_thick);
    float thick = (float)temp_thick;

    Color color = Color_from_js(env, args[3]);

    DrawSplineBezierQuadratic(points, pointCount, thick, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawSplineBezierCubic(napi_env env, napi_callback_info info) {
    size_t argc = 4;
    napi_value args[4];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 4) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    // Warning: No conversion available for const Vector2
    const Vector2 * points = NULL;

    int pointCount;
    napi_get_value_int32(env, args[1], (int32_t*)&pointCount);

    double temp_thick;
    napi_get_value_double(env, args[2], &temp_thick);
    float thick = (float)temp_thick;

    Color color = Color_from_js(env, args[3]);

    DrawSplineBezierCubic(points, pointCount, thick, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawSplineSegmentLinear(napi_env env, napi_callback_info info) {
    size_t argc = 4;
    napi_value args[4];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 4) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Vector2 p1 = Vector2_from_js(env, args[0]);

    Vector2 p2 = Vector2_from_js(env, args[1]);

    double temp_thick;
    napi_get_value_double(env, args[2], &temp_thick);
    float thick = (float)temp_thick;

    Color color = Color_from_js(env, args[3]);

    DrawSplineSegmentLinear(p1, p2, thick, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawSplineSegmentBasis(napi_env env, napi_callback_info info) {
    size_t argc = 6;
    napi_value args[6];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 6) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Vector2 p1 = Vector2_from_js(env, args[0]);

    Vector2 p2 = Vector2_from_js(env, args[1]);

    Vector2 p3 = Vector2_from_js(env, args[2]);

    Vector2 p4 = Vector2_from_js(env, args[3]);

    double temp_thick;
    napi_get_value_double(env, args[4], &temp_thick);
    float thick = (float)temp_thick;

    Color color = Color_from_js(env, args[5]);

    DrawSplineSegmentBasis(p1, p2, p3, p4, thick, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawSplineSegmentCatmullRom(napi_env env, napi_callback_info info) {
    size_t argc = 6;
    napi_value args[6];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 6) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Vector2 p1 = Vector2_from_js(env, args[0]);

    Vector2 p2 = Vector2_from_js(env, args[1]);

    Vector2 p3 = Vector2_from_js(env, args[2]);

    Vector2 p4 = Vector2_from_js(env, args[3]);

    double temp_thick;
    napi_get_value_double(env, args[4], &temp_thick);
    float thick = (float)temp_thick;

    Color color = Color_from_js(env, args[5]);

    DrawSplineSegmentCatmullRom(p1, p2, p3, p4, thick, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawSplineSegmentBezierQuadratic(napi_env env, napi_callback_info info) {
    size_t argc = 5;
    napi_value args[5];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 5) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Vector2 p1 = Vector2_from_js(env, args[0]);

    Vector2 c2 = Vector2_from_js(env, args[1]);

    Vector2 p3 = Vector2_from_js(env, args[2]);

    double temp_thick;
    napi_get_value_double(env, args[3], &temp_thick);
    float thick = (float)temp_thick;

    Color color = Color_from_js(env, args[4]);

    DrawSplineSegmentBezierQuadratic(p1, c2, p3, thick, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawSplineSegmentBezierCubic(napi_env env, napi_callback_info info) {
    size_t argc = 6;
    napi_value args[6];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 6) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Vector2 p1 = Vector2_from_js(env, args[0]);

    Vector2 c2 = Vector2_from_js(env, args[1]);

    Vector2 c3 = Vector2_from_js(env, args[2]);

    Vector2 p4 = Vector2_from_js(env, args[3]);

    double temp_thick;
    napi_get_value_double(env, args[4], &temp_thick);
    float thick = (float)temp_thick;

    Color color = Color_from_js(env, args[5]);

    DrawSplineSegmentBezierCubic(p1, c2, c3, p4, thick, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_GetSplinePointLinear(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value args[3];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 3) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Vector2 startPos = Vector2_from_js(env, args[0]);

    Vector2 endPos = Vector2_from_js(env, args[1]);

    double temp_t;
    napi_get_value_double(env, args[2], &temp_t);
    float t = (float)temp_t;

    Vector2 result = GetSplinePointLinear(startPos, endPos, t);
    return Vector2_to_js(env, result);
}

napi_value BindNode_GetSplinePointBasis(napi_env env, napi_callback_info info) {
    size_t argc = 5;
    napi_value args[5];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 5) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Vector2 p1 = Vector2_from_js(env, args[0]);

    Vector2 p2 = Vector2_from_js(env, args[1]);

    Vector2 p3 = Vector2_from_js(env, args[2]);

    Vector2 p4 = Vector2_from_js(env, args[3]);

    double temp_t;
    napi_get_value_double(env, args[4], &temp_t);
    float t = (float)temp_t;

    Vector2 result = GetSplinePointBasis(p1, p2, p3, p4, t);
    return Vector2_to_js(env, result);
}

napi_value BindNode_GetSplinePointCatmullRom(napi_env env, napi_callback_info info) {
    size_t argc = 5;
    napi_value args[5];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 5) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Vector2 p1 = Vector2_from_js(env, args[0]);

    Vector2 p2 = Vector2_from_js(env, args[1]);

    Vector2 p3 = Vector2_from_js(env, args[2]);

    Vector2 p4 = Vector2_from_js(env, args[3]);

    double temp_t;
    napi_get_value_double(env, args[4], &temp_t);
    float t = (float)temp_t;

    Vector2 result = GetSplinePointCatmullRom(p1, p2, p3, p4, t);
    return Vector2_to_js(env, result);
}

napi_value BindNode_GetSplinePointBezierQuad(napi_env env, napi_callback_info info) {
    size_t argc = 4;
    napi_value args[4];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 4) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Vector2 p1 = Vector2_from_js(env, args[0]);

    Vector2 c2 = Vector2_from_js(env, args[1]);

    Vector2 p3 = Vector2_from_js(env, args[2]);

    double temp_t;
    napi_get_value_double(env, args[3], &temp_t);
    float t = (float)temp_t;

    Vector2 result = GetSplinePointBezierQuad(p1, c2, p3, t);
    return Vector2_to_js(env, result);
}

napi_value BindNode_GetSplinePointBezierCubic(napi_env env, napi_callback_info info) {
    size_t argc = 5;
    napi_value args[5];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 5) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Vector2 p1 = Vector2_from_js(env, args[0]);

    Vector2 c2 = Vector2_from_js(env, args[1]);

    Vector2 c3 = Vector2_from_js(env, args[2]);

    Vector2 p4 = Vector2_from_js(env, args[3]);

    double temp_t;
    napi_get_value_double(env, args[4], &temp_t);
    float t = (float)temp_t;

    Vector2 result = GetSplinePointBezierCubic(p1, c2, c3, p4, t);
    return Vector2_to_js(env, result);
}

napi_value BindNode_CheckCollisionRecs(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Rectangle rec1 = Rectangle_from_js(env, args[0]);

    Rectangle rec2 = Rectangle_from_js(env, args[1]);

    bool result = CheckCollisionRecs(rec1, rec2);
    napi_value jsResult;
    napi_get_boolean(env, result, &jsResult);
    return jsResult;
}

napi_value BindNode_CheckCollisionCircles(napi_env env, napi_callback_info info) {
    size_t argc = 4;
    napi_value args[4];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 4) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Vector2 center1 = Vector2_from_js(env, args[0]);

    double temp_radius1;
    napi_get_value_double(env, args[1], &temp_radius1);
    float radius1 = (float)temp_radius1;

    Vector2 center2 = Vector2_from_js(env, args[2]);

    double temp_radius2;
    napi_get_value_double(env, args[3], &temp_radius2);
    float radius2 = (float)temp_radius2;

    bool result = CheckCollisionCircles(center1, radius1, center2, radius2);
    napi_value jsResult;
    napi_get_boolean(env, result, &jsResult);
    return jsResult;
}

napi_value BindNode_CheckCollisionCircleRec(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value args[3];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 3) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Vector2 center = Vector2_from_js(env, args[0]);

    double temp_radius;
    napi_get_value_double(env, args[1], &temp_radius);
    float radius = (float)temp_radius;

    Rectangle rec = Rectangle_from_js(env, args[2]);

    bool result = CheckCollisionCircleRec(center, radius, rec);
    napi_value jsResult;
    napi_get_boolean(env, result, &jsResult);
    return jsResult;
}

napi_value BindNode_CheckCollisionCircleLine(napi_env env, napi_callback_info info) {
    size_t argc = 4;
    napi_value args[4];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 4) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Vector2 center = Vector2_from_js(env, args[0]);

    double temp_radius;
    napi_get_value_double(env, args[1], &temp_radius);
    float radius = (float)temp_radius;

    Vector2 p1 = Vector2_from_js(env, args[2]);

    Vector2 p2 = Vector2_from_js(env, args[3]);

    bool result = CheckCollisionCircleLine(center, radius, p1, p2);
    napi_value jsResult;
    napi_get_boolean(env, result, &jsResult);
    return jsResult;
}

napi_value BindNode_CheckCollisionPointRec(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Vector2 point = Vector2_from_js(env, args[0]);

    Rectangle rec = Rectangle_from_js(env, args[1]);

    bool result = CheckCollisionPointRec(point, rec);
    napi_value jsResult;
    napi_get_boolean(env, result, &jsResult);
    return jsResult;
}

napi_value BindNode_CheckCollisionPointCircle(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value args[3];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 3) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Vector2 point = Vector2_from_js(env, args[0]);

    Vector2 center = Vector2_from_js(env, args[1]);

    double temp_radius;
    napi_get_value_double(env, args[2], &temp_radius);
    float radius = (float)temp_radius;

    bool result = CheckCollisionPointCircle(point, center, radius);
    napi_value jsResult;
    napi_get_boolean(env, result, &jsResult);
    return jsResult;
}

napi_value BindNode_CheckCollisionPointTriangle(napi_env env, napi_callback_info info) {
    size_t argc = 4;
    napi_value args[4];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 4) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Vector2 point = Vector2_from_js(env, args[0]);

    Vector2 p1 = Vector2_from_js(env, args[1]);

    Vector2 p2 = Vector2_from_js(env, args[2]);

    Vector2 p3 = Vector2_from_js(env, args[3]);

    bool result = CheckCollisionPointTriangle(point, p1, p2, p3);
    napi_value jsResult;
    napi_get_boolean(env, result, &jsResult);
    return jsResult;
}

napi_value BindNode_CheckCollisionPointLine(napi_env env, napi_callback_info info) {
    size_t argc = 4;
    napi_value args[4];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 4) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Vector2 point = Vector2_from_js(env, args[0]);

    Vector2 p1 = Vector2_from_js(env, args[1]);

    Vector2 p2 = Vector2_from_js(env, args[2]);

    int threshold;
    napi_get_value_int32(env, args[3], (int32_t*)&threshold);

    bool result = CheckCollisionPointLine(point, p1, p2, threshold);
    napi_value jsResult;
    napi_get_boolean(env, result, &jsResult);
    return jsResult;
}

napi_value BindNode_CheckCollisionPointPoly(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value args[3];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 3) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Vector2 point = Vector2_from_js(env, args[0]);

    // Warning: No conversion available for const Vector2
    const Vector2 * points = NULL;

    int pointCount;
    napi_get_value_int32(env, args[2], (int32_t*)&pointCount);

    bool result = CheckCollisionPointPoly(point, points, pointCount);
    napi_value jsResult;
    napi_get_boolean(env, result, &jsResult);
    return jsResult;
}

napi_value BindNode_CheckCollisionLines(napi_env env, napi_callback_info info) {
    size_t argc = 5;
    napi_value args[5];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 5) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Vector2 startPos1 = Vector2_from_js(env, args[0]);

    Vector2 endPos1 = Vector2_from_js(env, args[1]);

    Vector2 startPos2 = Vector2_from_js(env, args[2]);

    Vector2 endPos2 = Vector2_from_js(env, args[3]);

    Vector2 collisionPoint_value = Vector2_from_js(env, args[4]);
    Vector2 * collisionPoint = &collisionPoint_value;

    bool result = CheckCollisionLines(startPos1, endPos1, startPos2, endPos2, collisionPoint);
    napi_value jsResult;
    napi_get_boolean(env, result, &jsResult);
    return jsResult;
}

napi_value BindNode_GetCollisionRec(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Rectangle rec1 = Rectangle_from_js(env, args[0]);

    Rectangle rec2 = Rectangle_from_js(env, args[1]);

    Rectangle result = GetCollisionRec(rec1, rec2);
    return Rectangle_to_js(env, result);
}

napi_value BindNode_LoadImage(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    size_t fileName_len;
    napi_get_value_string_utf8(env, args[0], NULL, 0, &fileName_len);
    char* fileName = (char*)malloc(fileName_len + 1);
    napi_get_value_string_utf8(env, args[0], fileName, fileName_len + 1, &fileName_len);

    Image result = LoadImage(fileName);
    free(fileName);
    return Image_to_js(env, result);
}

napi_value BindNode_LoadImageRaw(napi_env env, napi_callback_info info) {
    size_t argc = 5;
    napi_value args[5];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 5) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    size_t fileName_len;
    napi_get_value_string_utf8(env, args[0], NULL, 0, &fileName_len);
    char* fileName = (char*)malloc(fileName_len + 1);
    napi_get_value_string_utf8(env, args[0], fileName, fileName_len + 1, &fileName_len);

    int width;
    napi_get_value_int32(env, args[1], (int32_t*)&width);

    int height;
    napi_get_value_int32(env, args[2], (int32_t*)&height);

    int format;
    napi_get_value_int32(env, args[3], (int32_t*)&format);

    int headerSize;
    napi_get_value_int32(env, args[4], (int32_t*)&headerSize);

    Image result = LoadImageRaw(fileName, width, height, format, headerSize);
    free(fileName);
    return Image_to_js(env, result);
}

napi_value BindNode_LoadImageAnim(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    size_t fileName_len;
    napi_get_value_string_utf8(env, args[0], NULL, 0, &fileName_len);
    char* fileName = (char*)malloc(fileName_len + 1);
    napi_get_value_string_utf8(env, args[0], fileName, fileName_len + 1, &fileName_len);

    int frames_value = int_from_js(env, args[1]);
    int * frames = &frames_value;

    Image result = LoadImageAnim(fileName, frames);
    free(fileName);
    return Image_to_js(env, result);
}

napi_value BindNode_LoadImageAnimFromMemory(napi_env env, napi_callback_info info) {
    size_t argc = 4;
    napi_value args[4];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 4) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    size_t fileType_len;
    napi_get_value_string_utf8(env, args[0], NULL, 0, &fileType_len);
    char* fileType = (char*)malloc(fileType_len + 1);
    napi_get_value_string_utf8(env, args[0], fileType, fileType_len + 1, &fileType_len);

    // Warning: No conversion available for const unsigned char
    const unsigned char * fileData = NULL;

    int dataSize;
    napi_get_value_int32(env, args[2], (int32_t*)&dataSize);

    int frames_value = int_from_js(env, args[3]);
    int * frames = &frames_value;

    Image result = LoadImageAnimFromMemory(fileType, fileData, dataSize, frames);
    free(fileType);
    return Image_to_js(env, result);
}

napi_value BindNode_LoadImageFromMemory(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value args[3];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 3) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    size_t fileType_len;
    napi_get_value_string_utf8(env, args[0], NULL, 0, &fileType_len);
    char* fileType = (char*)malloc(fileType_len + 1);
    napi_get_value_string_utf8(env, args[0], fileType, fileType_len + 1, &fileType_len);

    // Warning: No conversion available for const unsigned char
    const unsigned char * fileData = NULL;

    int dataSize;
    napi_get_value_int32(env, args[2], (int32_t*)&dataSize);

    Image result = LoadImageFromMemory(fileType, fileData, dataSize);
    free(fileType);
    return Image_to_js(env, result);
}

napi_value BindNode_LoadImageFromTexture(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Texture2D texture = Texture2D_from_js(env, args[0]);

    Image result = LoadImageFromTexture(texture);
    return Image_to_js(env, result);
}

napi_value BindNode_LoadImageFromScreen(napi_env env, napi_callback_info info) {
    Image result = LoadImageFromScreen();
    return Image_to_js(env, result);
}

napi_value BindNode_IsImageValid(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Image image = Image_from_js(env, args[0]);

    bool result = IsImageValid(image);
    napi_value jsResult;
    napi_get_boolean(env, result, &jsResult);
    return jsResult;
}

napi_value BindNode_UnloadImage(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Image image = Image_from_js(env, args[0]);

    UnloadImage(image);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_ExportImage(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Image image = Image_from_js(env, args[0]);

    size_t fileName_len;
    napi_get_value_string_utf8(env, args[1], NULL, 0, &fileName_len);
    char* fileName = (char*)malloc(fileName_len + 1);
    napi_get_value_string_utf8(env, args[1], fileName, fileName_len + 1, &fileName_len);

    bool result = ExportImage(image, fileName);
    free(fileName);
    napi_value jsResult;
    napi_get_boolean(env, result, &jsResult);
    return jsResult;
}

napi_value BindNode_ExportImageToMemory(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value args[3];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 3) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Image image = Image_from_js(env, args[0]);

    size_t fileType_len;
    napi_get_value_string_utf8(env, args[1], NULL, 0, &fileType_len);
    char* fileType = (char*)malloc(fileType_len + 1);
    napi_get_value_string_utf8(env, args[1], fileType, fileType_len + 1, &fileType_len);

    int fileSize_value = int_from_js(env, args[2]);
    int * fileSize = &fileSize_value;

    unsigned char * result = ExportImageToMemory(image, fileType, fileSize);
    free(fileType);
    // TODO: Handle return type unsigned char *
    napi_value jsResult;
    napi_get_null(env, &jsResult);
    return jsResult; // Placeholder
}

napi_value BindNode_ExportImageAsCode(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Image image = Image_from_js(env, args[0]);

    size_t fileName_len;
    napi_get_value_string_utf8(env, args[1], NULL, 0, &fileName_len);
    char* fileName = (char*)malloc(fileName_len + 1);
    napi_get_value_string_utf8(env, args[1], fileName, fileName_len + 1, &fileName_len);

    bool result = ExportImageAsCode(image, fileName);
    free(fileName);
    napi_value jsResult;
    napi_get_boolean(env, result, &jsResult);
    return jsResult;
}

napi_value BindNode_GenImageColor(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value args[3];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 3) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    int width;
    napi_get_value_int32(env, args[0], (int32_t*)&width);

    int height;
    napi_get_value_int32(env, args[1], (int32_t*)&height);

    Color color = Color_from_js(env, args[2]);

    Image result = GenImageColor(width, height, color);
    return Image_to_js(env, result);
}

napi_value BindNode_GenImageGradientLinear(napi_env env, napi_callback_info info) {
    size_t argc = 5;
    napi_value args[5];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 5) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    int width;
    napi_get_value_int32(env, args[0], (int32_t*)&width);

    int height;
    napi_get_value_int32(env, args[1], (int32_t*)&height);

    int direction;
    napi_get_value_int32(env, args[2], (int32_t*)&direction);

    Color start = Color_from_js(env, args[3]);

    Color end = Color_from_js(env, args[4]);

    Image result = GenImageGradientLinear(width, height, direction, start, end);
    return Image_to_js(env, result);
}

napi_value BindNode_GenImageGradientRadial(napi_env env, napi_callback_info info) {
    size_t argc = 5;
    napi_value args[5];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 5) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    int width;
    napi_get_value_int32(env, args[0], (int32_t*)&width);

    int height;
    napi_get_value_int32(env, args[1], (int32_t*)&height);

    double temp_density;
    napi_get_value_double(env, args[2], &temp_density);
    float density = (float)temp_density;

    Color inner = Color_from_js(env, args[3]);

    Color outer = Color_from_js(env, args[4]);

    Image result = GenImageGradientRadial(width, height, density, inner, outer);
    return Image_to_js(env, result);
}

napi_value BindNode_GenImageGradientSquare(napi_env env, napi_callback_info info) {
    size_t argc = 5;
    napi_value args[5];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 5) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    int width;
    napi_get_value_int32(env, args[0], (int32_t*)&width);

    int height;
    napi_get_value_int32(env, args[1], (int32_t*)&height);

    double temp_density;
    napi_get_value_double(env, args[2], &temp_density);
    float density = (float)temp_density;

    Color inner = Color_from_js(env, args[3]);

    Color outer = Color_from_js(env, args[4]);

    Image result = GenImageGradientSquare(width, height, density, inner, outer);
    return Image_to_js(env, result);
}

napi_value BindNode_GenImageChecked(napi_env env, napi_callback_info info) {
    size_t argc = 6;
    napi_value args[6];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 6) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    int width;
    napi_get_value_int32(env, args[0], (int32_t*)&width);

    int height;
    napi_get_value_int32(env, args[1], (int32_t*)&height);

    int checksX;
    napi_get_value_int32(env, args[2], (int32_t*)&checksX);

    int checksY;
    napi_get_value_int32(env, args[3], (int32_t*)&checksY);

    Color col1 = Color_from_js(env, args[4]);

    Color col2 = Color_from_js(env, args[5]);

    Image result = GenImageChecked(width, height, checksX, checksY, col1, col2);
    return Image_to_js(env, result);
}

napi_value BindNode_GenImageWhiteNoise(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value args[3];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 3) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    int width;
    napi_get_value_int32(env, args[0], (int32_t*)&width);

    int height;
    napi_get_value_int32(env, args[1], (int32_t*)&height);

    double temp_factor;
    napi_get_value_double(env, args[2], &temp_factor);
    float factor = (float)temp_factor;

    Image result = GenImageWhiteNoise(width, height, factor);
    return Image_to_js(env, result);
}

napi_value BindNode_GenImagePerlinNoise(napi_env env, napi_callback_info info) {
    size_t argc = 5;
    napi_value args[5];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 5) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    int width;
    napi_get_value_int32(env, args[0], (int32_t*)&width);

    int height;
    napi_get_value_int32(env, args[1], (int32_t*)&height);

    int offsetX;
    napi_get_value_int32(env, args[2], (int32_t*)&offsetX);

    int offsetY;
    napi_get_value_int32(env, args[3], (int32_t*)&offsetY);

    double temp_scale;
    napi_get_value_double(env, args[4], &temp_scale);
    float scale = (float)temp_scale;

    Image result = GenImagePerlinNoise(width, height, offsetX, offsetY, scale);
    return Image_to_js(env, result);
}

napi_value BindNode_GenImageCellular(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value args[3];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 3) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    int width;
    napi_get_value_int32(env, args[0], (int32_t*)&width);

    int height;
    napi_get_value_int32(env, args[1], (int32_t*)&height);

    int tileSize;
    napi_get_value_int32(env, args[2], (int32_t*)&tileSize);

    Image result = GenImageCellular(width, height, tileSize);
    return Image_to_js(env, result);
}

napi_value BindNode_GenImageText(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value args[3];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 3) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    int width;
    napi_get_value_int32(env, args[0], (int32_t*)&width);

    int height;
    napi_get_value_int32(env, args[1], (int32_t*)&height);

    size_t text_len;
    napi_get_value_string_utf8(env, args[2], NULL, 0, &text_len);
    char* text = (char*)malloc(text_len + 1);
    napi_get_value_string_utf8(env, args[2], text, text_len + 1, &text_len);

    Image result = GenImageText(width, height, text);
    free(text);
    return Image_to_js(env, result);
}

napi_value BindNode_ImageCopy(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Image image = Image_from_js(env, args[0]);

    Image result = ImageCopy(image);
    return Image_to_js(env, result);
}

napi_value BindNode_ImageFromImage(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Image image = Image_from_js(env, args[0]);

    Rectangle rec = Rectangle_from_js(env, args[1]);

    Image result = ImageFromImage(image, rec);
    return Image_to_js(env, result);
}

napi_value BindNode_ImageFromChannel(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Image image = Image_from_js(env, args[0]);

    int selectedChannel;
    napi_get_value_int32(env, args[1], (int32_t*)&selectedChannel);

    Image result = ImageFromChannel(image, selectedChannel);
    return Image_to_js(env, result);
}

napi_value BindNode_ImageText(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value args[3];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 3) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    size_t text_len;
    napi_get_value_string_utf8(env, args[0], NULL, 0, &text_len);
    char* text = (char*)malloc(text_len + 1);
    napi_get_value_string_utf8(env, args[0], text, text_len + 1, &text_len);

    int fontSize;
    napi_get_value_int32(env, args[1], (int32_t*)&fontSize);

    Color color = Color_from_js(env, args[2]);

    Image result = ImageText(text, fontSize, color);
    free(text);
    return Image_to_js(env, result);
}

napi_value BindNode_ImageTextEx(napi_env env, napi_callback_info info) {
    size_t argc = 5;
    napi_value args[5];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 5) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Font font = Font_from_js(env, args[0]);

    size_t text_len;
    napi_get_value_string_utf8(env, args[1], NULL, 0, &text_len);
    char* text = (char*)malloc(text_len + 1);
    napi_get_value_string_utf8(env, args[1], text, text_len + 1, &text_len);

    double temp_fontSize;
    napi_get_value_double(env, args[2], &temp_fontSize);
    float fontSize = (float)temp_fontSize;

    double temp_spacing;
    napi_get_value_double(env, args[3], &temp_spacing);
    float spacing = (float)temp_spacing;

    Color tint = Color_from_js(env, args[4]);

    Image result = ImageTextEx(font, text, fontSize, spacing, tint);
    free(text);
    return Image_to_js(env, result);
}

napi_value BindNode_ImageFormat(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Image image_value = Image_from_js(env, args[0]);
    Image * image = &image_value;

    int newFormat;
    napi_get_value_int32(env, args[1], (int32_t*)&newFormat);

    ImageFormat(image, newFormat);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_ImageToPOT(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Image image_value = Image_from_js(env, args[0]);
    Image * image = &image_value;

    Color fill = Color_from_js(env, args[1]);

    ImageToPOT(image, fill);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_ImageCrop(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Image image_value = Image_from_js(env, args[0]);
    Image * image = &image_value;

    Rectangle crop = Rectangle_from_js(env, args[1]);

    ImageCrop(image, crop);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_ImageAlphaCrop(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Image image_value = Image_from_js(env, args[0]);
    Image * image = &image_value;

    double temp_threshold;
    napi_get_value_double(env, args[1], &temp_threshold);
    float threshold = (float)temp_threshold;

    ImageAlphaCrop(image, threshold);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_ImageAlphaClear(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value args[3];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 3) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Image image_value = Image_from_js(env, args[0]);
    Image * image = &image_value;

    Color color = Color_from_js(env, args[1]);

    double temp_threshold;
    napi_get_value_double(env, args[2], &temp_threshold);
    float threshold = (float)temp_threshold;

    ImageAlphaClear(image, color, threshold);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_ImageAlphaMask(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Image image_value = Image_from_js(env, args[0]);
    Image * image = &image_value;

    Image alphaMask = Image_from_js(env, args[1]);

    ImageAlphaMask(image, alphaMask);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_ImageAlphaPremultiply(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Image image_value = Image_from_js(env, args[0]);
    Image * image = &image_value;

    ImageAlphaPremultiply(image);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_ImageBlurGaussian(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Image image_value = Image_from_js(env, args[0]);
    Image * image = &image_value;

    int blurSize;
    napi_get_value_int32(env, args[1], (int32_t*)&blurSize);

    ImageBlurGaussian(image, blurSize);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_ImageKernelConvolution(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value args[3];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 3) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Image image_value = Image_from_js(env, args[0]);
    Image * image = &image_value;

    // Warning: No conversion available for const float
    const float * kernel = NULL;

    int kernelSize;
    napi_get_value_int32(env, args[2], (int32_t*)&kernelSize);

    ImageKernelConvolution(image, kernel, kernelSize);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_ImageResize(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value args[3];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 3) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Image image_value = Image_from_js(env, args[0]);
    Image * image = &image_value;

    int newWidth;
    napi_get_value_int32(env, args[1], (int32_t*)&newWidth);

    int newHeight;
    napi_get_value_int32(env, args[2], (int32_t*)&newHeight);

    ImageResize(image, newWidth, newHeight);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_ImageResizeNN(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value args[3];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 3) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Image image_value = Image_from_js(env, args[0]);
    Image * image = &image_value;

    int newWidth;
    napi_get_value_int32(env, args[1], (int32_t*)&newWidth);

    int newHeight;
    napi_get_value_int32(env, args[2], (int32_t*)&newHeight);

    ImageResizeNN(image, newWidth, newHeight);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_ImageResizeCanvas(napi_env env, napi_callback_info info) {
    size_t argc = 6;
    napi_value args[6];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 6) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Image image_value = Image_from_js(env, args[0]);
    Image * image = &image_value;

    int newWidth;
    napi_get_value_int32(env, args[1], (int32_t*)&newWidth);

    int newHeight;
    napi_get_value_int32(env, args[2], (int32_t*)&newHeight);

    int offsetX;
    napi_get_value_int32(env, args[3], (int32_t*)&offsetX);

    int offsetY;
    napi_get_value_int32(env, args[4], (int32_t*)&offsetY);

    Color fill = Color_from_js(env, args[5]);

    ImageResizeCanvas(image, newWidth, newHeight, offsetX, offsetY, fill);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_ImageMipmaps(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Image image_value = Image_from_js(env, args[0]);
    Image * image = &image_value;

    ImageMipmaps(image);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_ImageDither(napi_env env, napi_callback_info info) {
    size_t argc = 5;
    napi_value args[5];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 5) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Image image_value = Image_from_js(env, args[0]);
    Image * image = &image_value;

    int rBpp;
    napi_get_value_int32(env, args[1], (int32_t*)&rBpp);

    int gBpp;
    napi_get_value_int32(env, args[2], (int32_t*)&gBpp);

    int bBpp;
    napi_get_value_int32(env, args[3], (int32_t*)&bBpp);

    int aBpp;
    napi_get_value_int32(env, args[4], (int32_t*)&aBpp);

    ImageDither(image, rBpp, gBpp, bBpp, aBpp);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_ImageFlipVertical(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Image image_value = Image_from_js(env, args[0]);
    Image * image = &image_value;

    ImageFlipVertical(image);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_ImageFlipHorizontal(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Image image_value = Image_from_js(env, args[0]);
    Image * image = &image_value;

    ImageFlipHorizontal(image);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_ImageRotate(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Image image_value = Image_from_js(env, args[0]);
    Image * image = &image_value;

    int degrees;
    napi_get_value_int32(env, args[1], (int32_t*)&degrees);

    ImageRotate(image, degrees);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_ImageRotateCW(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Image image_value = Image_from_js(env, args[0]);
    Image * image = &image_value;

    ImageRotateCW(image);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_ImageRotateCCW(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Image image_value = Image_from_js(env, args[0]);
    Image * image = &image_value;

    ImageRotateCCW(image);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_ImageColorTint(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Image image_value = Image_from_js(env, args[0]);
    Image * image = &image_value;

    Color color = Color_from_js(env, args[1]);

    ImageColorTint(image, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_ImageColorInvert(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Image image_value = Image_from_js(env, args[0]);
    Image * image = &image_value;

    ImageColorInvert(image);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_ImageColorGrayscale(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Image image_value = Image_from_js(env, args[0]);
    Image * image = &image_value;

    ImageColorGrayscale(image);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_ImageColorContrast(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Image image_value = Image_from_js(env, args[0]);
    Image * image = &image_value;

    double temp_contrast;
    napi_get_value_double(env, args[1], &temp_contrast);
    float contrast = (float)temp_contrast;

    ImageColorContrast(image, contrast);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_ImageColorBrightness(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Image image_value = Image_from_js(env, args[0]);
    Image * image = &image_value;

    int brightness;
    napi_get_value_int32(env, args[1], (int32_t*)&brightness);

    ImageColorBrightness(image, brightness);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_ImageColorReplace(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value args[3];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 3) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Image image_value = Image_from_js(env, args[0]);
    Image * image = &image_value;

    Color color = Color_from_js(env, args[1]);

    Color replace = Color_from_js(env, args[2]);

    ImageColorReplace(image, color, replace);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_LoadImageColors(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Image image = Image_from_js(env, args[0]);

    Color * result = LoadImageColors(image);
    // TODO: Handle return type Color *
    napi_value jsResult;
    napi_get_null(env, &jsResult);
    return jsResult; // Placeholder
}

napi_value BindNode_LoadImagePalette(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value args[3];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 3) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Image image = Image_from_js(env, args[0]);

    int maxPaletteSize;
    napi_get_value_int32(env, args[1], (int32_t*)&maxPaletteSize);

    int colorCount_value = int_from_js(env, args[2]);
    int * colorCount = &colorCount_value;

    Color * result = LoadImagePalette(image, maxPaletteSize, colorCount);
    // TODO: Handle return type Color *
    napi_value jsResult;
    napi_get_null(env, &jsResult);
    return jsResult; // Placeholder
}

napi_value BindNode_UnloadImageColors(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Color colors_value = Color_from_js(env, args[0]);
    Color * colors = &colors_value;

    UnloadImageColors(colors);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_UnloadImagePalette(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Color colors_value = Color_from_js(env, args[0]);
    Color * colors = &colors_value;

    UnloadImagePalette(colors);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_GetImageAlphaBorder(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Image image = Image_from_js(env, args[0]);

    double temp_threshold;
    napi_get_value_double(env, args[1], &temp_threshold);
    float threshold = (float)temp_threshold;

    Rectangle result = GetImageAlphaBorder(image, threshold);
    return Rectangle_to_js(env, result);
}

napi_value BindNode_GetImageColor(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value args[3];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 3) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Image image = Image_from_js(env, args[0]);

    int x;
    napi_get_value_int32(env, args[1], (int32_t*)&x);

    int y;
    napi_get_value_int32(env, args[2], (int32_t*)&y);

    Color result = GetImageColor(image, x, y);
    return Color_to_js(env, result);
}

napi_value BindNode_ImageClearBackground(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Image dst_value = Image_from_js(env, args[0]);
    Image * dst = &dst_value;

    Color color = Color_from_js(env, args[1]);

    ImageClearBackground(dst, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_ImageDrawPixel(napi_env env, napi_callback_info info) {
    size_t argc = 4;
    napi_value args[4];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 4) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Image dst_value = Image_from_js(env, args[0]);
    Image * dst = &dst_value;

    int posX;
    napi_get_value_int32(env, args[1], (int32_t*)&posX);

    int posY;
    napi_get_value_int32(env, args[2], (int32_t*)&posY);

    Color color = Color_from_js(env, args[3]);

    ImageDrawPixel(dst, posX, posY, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_ImageDrawPixelV(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value args[3];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 3) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Image dst_value = Image_from_js(env, args[0]);
    Image * dst = &dst_value;

    Vector2 position = Vector2_from_js(env, args[1]);

    Color color = Color_from_js(env, args[2]);

    ImageDrawPixelV(dst, position, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_ImageDrawLine(napi_env env, napi_callback_info info) {
    size_t argc = 6;
    napi_value args[6];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 6) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Image dst_value = Image_from_js(env, args[0]);
    Image * dst = &dst_value;

    int startPosX;
    napi_get_value_int32(env, args[1], (int32_t*)&startPosX);

    int startPosY;
    napi_get_value_int32(env, args[2], (int32_t*)&startPosY);

    int endPosX;
    napi_get_value_int32(env, args[3], (int32_t*)&endPosX);

    int endPosY;
    napi_get_value_int32(env, args[4], (int32_t*)&endPosY);

    Color color = Color_from_js(env, args[5]);

    ImageDrawLine(dst, startPosX, startPosY, endPosX, endPosY, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_ImageDrawLineV(napi_env env, napi_callback_info info) {
    size_t argc = 4;
    napi_value args[4];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 4) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Image dst_value = Image_from_js(env, args[0]);
    Image * dst = &dst_value;

    Vector2 start = Vector2_from_js(env, args[1]);

    Vector2 end = Vector2_from_js(env, args[2]);

    Color color = Color_from_js(env, args[3]);

    ImageDrawLineV(dst, start, end, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_ImageDrawLineEx(napi_env env, napi_callback_info info) {
    size_t argc = 5;
    napi_value args[5];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 5) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Image dst_value = Image_from_js(env, args[0]);
    Image * dst = &dst_value;

    Vector2 start = Vector2_from_js(env, args[1]);

    Vector2 end = Vector2_from_js(env, args[2]);

    int thick;
    napi_get_value_int32(env, args[3], (int32_t*)&thick);

    Color color = Color_from_js(env, args[4]);

    ImageDrawLineEx(dst, start, end, thick, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_ImageDrawCircle(napi_env env, napi_callback_info info) {
    size_t argc = 5;
    napi_value args[5];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 5) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Image dst_value = Image_from_js(env, args[0]);
    Image * dst = &dst_value;

    int centerX;
    napi_get_value_int32(env, args[1], (int32_t*)&centerX);

    int centerY;
    napi_get_value_int32(env, args[2], (int32_t*)&centerY);

    int radius;
    napi_get_value_int32(env, args[3], (int32_t*)&radius);

    Color color = Color_from_js(env, args[4]);

    ImageDrawCircle(dst, centerX, centerY, radius, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_ImageDrawCircleV(napi_env env, napi_callback_info info) {
    size_t argc = 4;
    napi_value args[4];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 4) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Image dst_value = Image_from_js(env, args[0]);
    Image * dst = &dst_value;

    Vector2 center = Vector2_from_js(env, args[1]);

    int radius;
    napi_get_value_int32(env, args[2], (int32_t*)&radius);

    Color color = Color_from_js(env, args[3]);

    ImageDrawCircleV(dst, center, radius, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_ImageDrawCircleLines(napi_env env, napi_callback_info info) {
    size_t argc = 5;
    napi_value args[5];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 5) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Image dst_value = Image_from_js(env, args[0]);
    Image * dst = &dst_value;

    int centerX;
    napi_get_value_int32(env, args[1], (int32_t*)&centerX);

    int centerY;
    napi_get_value_int32(env, args[2], (int32_t*)&centerY);

    int radius;
    napi_get_value_int32(env, args[3], (int32_t*)&radius);

    Color color = Color_from_js(env, args[4]);

    ImageDrawCircleLines(dst, centerX, centerY, radius, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_ImageDrawCircleLinesV(napi_env env, napi_callback_info info) {
    size_t argc = 4;
    napi_value args[4];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 4) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Image dst_value = Image_from_js(env, args[0]);
    Image * dst = &dst_value;

    Vector2 center = Vector2_from_js(env, args[1]);

    int radius;
    napi_get_value_int32(env, args[2], (int32_t*)&radius);

    Color color = Color_from_js(env, args[3]);

    ImageDrawCircleLinesV(dst, center, radius, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_ImageDrawRectangle(napi_env env, napi_callback_info info) {
    size_t argc = 6;
    napi_value args[6];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 6) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Image dst_value = Image_from_js(env, args[0]);
    Image * dst = &dst_value;

    int posX;
    napi_get_value_int32(env, args[1], (int32_t*)&posX);

    int posY;
    napi_get_value_int32(env, args[2], (int32_t*)&posY);

    int width;
    napi_get_value_int32(env, args[3], (int32_t*)&width);

    int height;
    napi_get_value_int32(env, args[4], (int32_t*)&height);

    Color color = Color_from_js(env, args[5]);

    ImageDrawRectangle(dst, posX, posY, width, height, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_ImageDrawRectangleV(napi_env env, napi_callback_info info) {
    size_t argc = 4;
    napi_value args[4];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 4) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Image dst_value = Image_from_js(env, args[0]);
    Image * dst = &dst_value;

    Vector2 position = Vector2_from_js(env, args[1]);

    Vector2 size = Vector2_from_js(env, args[2]);

    Color color = Color_from_js(env, args[3]);

    ImageDrawRectangleV(dst, position, size, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_ImageDrawRectangleRec(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value args[3];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 3) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Image dst_value = Image_from_js(env, args[0]);
    Image * dst = &dst_value;

    Rectangle rec = Rectangle_from_js(env, args[1]);

    Color color = Color_from_js(env, args[2]);

    ImageDrawRectangleRec(dst, rec, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_ImageDrawRectangleLines(napi_env env, napi_callback_info info) {
    size_t argc = 4;
    napi_value args[4];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 4) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Image dst_value = Image_from_js(env, args[0]);
    Image * dst = &dst_value;

    Rectangle rec = Rectangle_from_js(env, args[1]);

    int thick;
    napi_get_value_int32(env, args[2], (int32_t*)&thick);

    Color color = Color_from_js(env, args[3]);

    ImageDrawRectangleLines(dst, rec, thick, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_ImageDrawTriangle(napi_env env, napi_callback_info info) {
    size_t argc = 5;
    napi_value args[5];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 5) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Image dst_value = Image_from_js(env, args[0]);
    Image * dst = &dst_value;

    Vector2 v1 = Vector2_from_js(env, args[1]);

    Vector2 v2 = Vector2_from_js(env, args[2]);

    Vector2 v3 = Vector2_from_js(env, args[3]);

    Color color = Color_from_js(env, args[4]);

    ImageDrawTriangle(dst, v1, v2, v3, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_ImageDrawTriangleEx(napi_env env, napi_callback_info info) {
    size_t argc = 7;
    napi_value args[7];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 7) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Image dst_value = Image_from_js(env, args[0]);
    Image * dst = &dst_value;

    Vector2 v1 = Vector2_from_js(env, args[1]);

    Vector2 v2 = Vector2_from_js(env, args[2]);

    Vector2 v3 = Vector2_from_js(env, args[3]);

    Color c1 = Color_from_js(env, args[4]);

    Color c2 = Color_from_js(env, args[5]);

    Color c3 = Color_from_js(env, args[6]);

    ImageDrawTriangleEx(dst, v1, v2, v3, c1, c2, c3);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_ImageDrawTriangleLines(napi_env env, napi_callback_info info) {
    size_t argc = 5;
    napi_value args[5];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 5) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Image dst_value = Image_from_js(env, args[0]);
    Image * dst = &dst_value;

    Vector2 v1 = Vector2_from_js(env, args[1]);

    Vector2 v2 = Vector2_from_js(env, args[2]);

    Vector2 v3 = Vector2_from_js(env, args[3]);

    Color color = Color_from_js(env, args[4]);

    ImageDrawTriangleLines(dst, v1, v2, v3, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_ImageDrawTriangleFan(napi_env env, napi_callback_info info) {
    size_t argc = 4;
    napi_value args[4];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 4) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Image dst_value = Image_from_js(env, args[0]);
    Image * dst = &dst_value;

    Vector2 points_value = Vector2_from_js(env, args[1]);
    Vector2 * points = &points_value;

    int pointCount;
    napi_get_value_int32(env, args[2], (int32_t*)&pointCount);

    Color color = Color_from_js(env, args[3]);

    ImageDrawTriangleFan(dst, points, pointCount, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_ImageDrawTriangleStrip(napi_env env, napi_callback_info info) {
    size_t argc = 4;
    napi_value args[4];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 4) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Image dst_value = Image_from_js(env, args[0]);
    Image * dst = &dst_value;

    Vector2 points_value = Vector2_from_js(env, args[1]);
    Vector2 * points = &points_value;

    int pointCount;
    napi_get_value_int32(env, args[2], (int32_t*)&pointCount);

    Color color = Color_from_js(env, args[3]);

    ImageDrawTriangleStrip(dst, points, pointCount, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_ImageDraw(napi_env env, napi_callback_info info) {
    size_t argc = 5;
    napi_value args[5];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 5) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Image dst_value = Image_from_js(env, args[0]);
    Image * dst = &dst_value;

    Image src = Image_from_js(env, args[1]);

    Rectangle srcRec = Rectangle_from_js(env, args[2]);

    Rectangle dstRec = Rectangle_from_js(env, args[3]);

    Color tint = Color_from_js(env, args[4]);

    ImageDraw(dst, src, srcRec, dstRec, tint);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_ImageDrawText(napi_env env, napi_callback_info info) {
    size_t argc = 6;
    napi_value args[6];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 6) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Image dst_value = Image_from_js(env, args[0]);
    Image * dst = &dst_value;

    size_t text_len;
    napi_get_value_string_utf8(env, args[1], NULL, 0, &text_len);
    char* text = (char*)malloc(text_len + 1);
    napi_get_value_string_utf8(env, args[1], text, text_len + 1, &text_len);

    int posX;
    napi_get_value_int32(env, args[2], (int32_t*)&posX);

    int posY;
    napi_get_value_int32(env, args[3], (int32_t*)&posY);

    int fontSize;
    napi_get_value_int32(env, args[4], (int32_t*)&fontSize);

    Color color = Color_from_js(env, args[5]);

    ImageDrawText(dst, text, posX, posY, fontSize, color);
    free(text);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_ImageDrawTextEx(napi_env env, napi_callback_info info) {
    size_t argc = 7;
    napi_value args[7];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 7) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Image dst_value = Image_from_js(env, args[0]);
    Image * dst = &dst_value;

    Font font = Font_from_js(env, args[1]);

    size_t text_len;
    napi_get_value_string_utf8(env, args[2], NULL, 0, &text_len);
    char* text = (char*)malloc(text_len + 1);
    napi_get_value_string_utf8(env, args[2], text, text_len + 1, &text_len);

    Vector2 position = Vector2_from_js(env, args[3]);

    double temp_fontSize;
    napi_get_value_double(env, args[4], &temp_fontSize);
    float fontSize = (float)temp_fontSize;

    double temp_spacing;
    napi_get_value_double(env, args[5], &temp_spacing);
    float spacing = (float)temp_spacing;

    Color tint = Color_from_js(env, args[6]);

    ImageDrawTextEx(dst, font, text, position, fontSize, spacing, tint);
    free(text);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_LoadTexture(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    size_t fileName_len;
    napi_get_value_string_utf8(env, args[0], NULL, 0, &fileName_len);
    char* fileName = (char*)malloc(fileName_len + 1);
    napi_get_value_string_utf8(env, args[0], fileName, fileName_len + 1, &fileName_len);

    Texture2D result = LoadTexture(fileName);
    free(fileName);
    return Texture2D_to_js(env, result);
}

napi_value BindNode_LoadTextureFromImage(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Image image = Image_from_js(env, args[0]);

    Texture2D result = LoadTextureFromImage(image);
    return Texture2D_to_js(env, result);
}

napi_value BindNode_LoadTextureCubemap(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Image image = Image_from_js(env, args[0]);

    int layout;
    napi_get_value_int32(env, args[1], (int32_t*)&layout);

    TextureCubemap result = LoadTextureCubemap(image, layout);
    return TextureCubemap_to_js(env, result);
}

napi_value BindNode_LoadRenderTexture(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    int width;
    napi_get_value_int32(env, args[0], (int32_t*)&width);

    int height;
    napi_get_value_int32(env, args[1], (int32_t*)&height);

    RenderTexture2D result = LoadRenderTexture(width, height);
    return RenderTexture2D_to_js(env, result);
}

napi_value BindNode_IsTextureValid(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Texture2D texture = Texture2D_from_js(env, args[0]);

    bool result = IsTextureValid(texture);
    napi_value jsResult;
    napi_get_boolean(env, result, &jsResult);
    return jsResult;
}

napi_value BindNode_UnloadTexture(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Texture2D texture = Texture2D_from_js(env, args[0]);

    UnloadTexture(texture);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_IsRenderTextureValid(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    RenderTexture2D target = RenderTexture2D_from_js(env, args[0]);

    bool result = IsRenderTextureValid(target);
    napi_value jsResult;
    napi_get_boolean(env, result, &jsResult);
    return jsResult;
}

napi_value BindNode_UnloadRenderTexture(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    RenderTexture2D target = RenderTexture2D_from_js(env, args[0]);

    UnloadRenderTexture(target);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_UpdateTexture(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Texture2D texture = Texture2D_from_js(env, args[0]);

    // Warning: No conversion available for const void
    const void * pixels = NULL;

    UpdateTexture(texture, pixels);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_UpdateTextureRec(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value args[3];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 3) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Texture2D texture = Texture2D_from_js(env, args[0]);

    Rectangle rec = Rectangle_from_js(env, args[1]);

    // Warning: No conversion available for const void
    const void * pixels = NULL;

    UpdateTextureRec(texture, rec, pixels);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_GenTextureMipmaps(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Texture2D texture_value = Texture2D_from_js(env, args[0]);
    Texture2D * texture = &texture_value;

    GenTextureMipmaps(texture);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_SetTextureFilter(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Texture2D texture = Texture2D_from_js(env, args[0]);

    int filter;
    napi_get_value_int32(env, args[1], (int32_t*)&filter);

    SetTextureFilter(texture, filter);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_SetTextureWrap(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Texture2D texture = Texture2D_from_js(env, args[0]);

    int wrap;
    napi_get_value_int32(env, args[1], (int32_t*)&wrap);

    SetTextureWrap(texture, wrap);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawTexture(napi_env env, napi_callback_info info) {
    size_t argc = 4;
    napi_value args[4];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 4) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Texture2D texture = Texture2D_from_js(env, args[0]);

    int posX;
    napi_get_value_int32(env, args[1], (int32_t*)&posX);

    int posY;
    napi_get_value_int32(env, args[2], (int32_t*)&posY);

    Color tint = Color_from_js(env, args[3]);

    DrawTexture(texture, posX, posY, tint);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawTextureV(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value args[3];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 3) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Texture2D texture = Texture2D_from_js(env, args[0]);

    Vector2 position = Vector2_from_js(env, args[1]);

    Color tint = Color_from_js(env, args[2]);

    DrawTextureV(texture, position, tint);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawTextureEx(napi_env env, napi_callback_info info) {
    size_t argc = 5;
    napi_value args[5];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 5) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Texture2D texture = Texture2D_from_js(env, args[0]);

    Vector2 position = Vector2_from_js(env, args[1]);

    double temp_rotation;
    napi_get_value_double(env, args[2], &temp_rotation);
    float rotation = (float)temp_rotation;

    double temp_scale;
    napi_get_value_double(env, args[3], &temp_scale);
    float scale = (float)temp_scale;

    Color tint = Color_from_js(env, args[4]);

    DrawTextureEx(texture, position, rotation, scale, tint);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawTextureRec(napi_env env, napi_callback_info info) {
    size_t argc = 4;
    napi_value args[4];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 4) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Texture2D texture = Texture2D_from_js(env, args[0]);

    Rectangle source = Rectangle_from_js(env, args[1]);

    Vector2 position = Vector2_from_js(env, args[2]);

    Color tint = Color_from_js(env, args[3]);

    DrawTextureRec(texture, source, position, tint);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawTexturePro(napi_env env, napi_callback_info info) {
    size_t argc = 6;
    napi_value args[6];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 6) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Texture2D texture = Texture2D_from_js(env, args[0]);

    Rectangle source = Rectangle_from_js(env, args[1]);

    Rectangle dest = Rectangle_from_js(env, args[2]);

    Vector2 origin = Vector2_from_js(env, args[3]);

    double temp_rotation;
    napi_get_value_double(env, args[4], &temp_rotation);
    float rotation = (float)temp_rotation;

    Color tint = Color_from_js(env, args[5]);

    DrawTexturePro(texture, source, dest, origin, rotation, tint);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawTextureNPatch(napi_env env, napi_callback_info info) {
    size_t argc = 6;
    napi_value args[6];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 6) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Texture2D texture = Texture2D_from_js(env, args[0]);

    NPatchInfo nPatchInfo = NPatchInfo_from_js(env, args[1]);

    Rectangle dest = Rectangle_from_js(env, args[2]);

    Vector2 origin = Vector2_from_js(env, args[3]);

    double temp_rotation;
    napi_get_value_double(env, args[4], &temp_rotation);
    float rotation = (float)temp_rotation;

    Color tint = Color_from_js(env, args[5]);

    DrawTextureNPatch(texture, nPatchInfo, dest, origin, rotation, tint);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_ColorIsEqual(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Color col1 = Color_from_js(env, args[0]);

    Color col2 = Color_from_js(env, args[1]);

    bool result = ColorIsEqual(col1, col2);
    napi_value jsResult;
    napi_get_boolean(env, result, &jsResult);
    return jsResult;
}

napi_value BindNode_Fade(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Color color = Color_from_js(env, args[0]);

    double temp_alpha;
    napi_get_value_double(env, args[1], &temp_alpha);
    float alpha = (float)temp_alpha;

    Color result = Fade(color, alpha);
    return Color_to_js(env, result);
}

napi_value BindNode_ColorToInt(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Color color = Color_from_js(env, args[0]);

    int result = ColorToInt(color);
    return int_to_js(env, result);
}

napi_value BindNode_ColorNormalize(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Color color = Color_from_js(env, args[0]);

    Vector4 result = ColorNormalize(color);
    return Vector4_to_js(env, result);
}

napi_value BindNode_ColorFromNormalized(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Vector4 normalized = Vector4_from_js(env, args[0]);

    Color result = ColorFromNormalized(normalized);
    return Color_to_js(env, result);
}

napi_value BindNode_ColorToHSV(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Color color = Color_from_js(env, args[0]);

    Vector3 result = ColorToHSV(color);
    return Vector3_to_js(env, result);
}

napi_value BindNode_ColorFromHSV(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value args[3];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 3) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    double temp_hue;
    napi_get_value_double(env, args[0], &temp_hue);
    float hue = (float)temp_hue;

    double temp_saturation;
    napi_get_value_double(env, args[1], &temp_saturation);
    float saturation = (float)temp_saturation;

    double temp_value;
    napi_get_value_double(env, args[2], &temp_value);
    float value = (float)temp_value;

    Color result = ColorFromHSV(hue, saturation, value);
    return Color_to_js(env, result);
}

napi_value BindNode_ColorTint(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Color color = Color_from_js(env, args[0]);

    Color tint = Color_from_js(env, args[1]);

    Color result = ColorTint(color, tint);
    return Color_to_js(env, result);
}

napi_value BindNode_ColorBrightness(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Color color = Color_from_js(env, args[0]);

    double temp_factor;
    napi_get_value_double(env, args[1], &temp_factor);
    float factor = (float)temp_factor;

    Color result = ColorBrightness(color, factor);
    return Color_to_js(env, result);
}

napi_value BindNode_ColorContrast(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Color color = Color_from_js(env, args[0]);

    double temp_contrast;
    napi_get_value_double(env, args[1], &temp_contrast);
    float contrast = (float)temp_contrast;

    Color result = ColorContrast(color, contrast);
    return Color_to_js(env, result);
}

napi_value BindNode_ColorAlpha(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Color color = Color_from_js(env, args[0]);

    double temp_alpha;
    napi_get_value_double(env, args[1], &temp_alpha);
    float alpha = (float)temp_alpha;

    Color result = ColorAlpha(color, alpha);
    return Color_to_js(env, result);
}

napi_value BindNode_ColorAlphaBlend(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value args[3];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 3) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Color dst = Color_from_js(env, args[0]);

    Color src = Color_from_js(env, args[1]);

    Color tint = Color_from_js(env, args[2]);

    Color result = ColorAlphaBlend(dst, src, tint);
    return Color_to_js(env, result);
}

napi_value BindNode_ColorLerp(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value args[3];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 3) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Color color1 = Color_from_js(env, args[0]);

    Color color2 = Color_from_js(env, args[1]);

    double temp_factor;
    napi_get_value_double(env, args[2], &temp_factor);
    float factor = (float)temp_factor;

    Color result = ColorLerp(color1, color2, factor);
    return Color_to_js(env, result);
}

napi_value BindNode_GetColor(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    unsigned int hexValue;
    napi_get_value_int32(env, args[0], (int32_t*)&hexValue);

    Color result = GetColor(hexValue);
    return Color_to_js(env, result);
}

napi_value BindNode_GetPixelColor(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    void_ptr srcPtr_value = void_from_js(env, args[0]);
    void * srcPtr = srcPtr_value;

    int format;
    napi_get_value_int32(env, args[1], (int32_t*)&format);

    Color result = GetPixelColor(srcPtr, format);
    return Color_to_js(env, result);
}

napi_value BindNode_SetPixelColor(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value args[3];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 3) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    void_ptr dstPtr_value = void_from_js(env, args[0]);
    void * dstPtr = dstPtr_value;

    Color color = Color_from_js(env, args[1]);

    int format;
    napi_get_value_int32(env, args[2], (int32_t*)&format);

    SetPixelColor(dstPtr, color, format);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_GetPixelDataSize(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value args[3];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 3) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    int width;
    napi_get_value_int32(env, args[0], (int32_t*)&width);

    int height;
    napi_get_value_int32(env, args[1], (int32_t*)&height);

    int format;
    napi_get_value_int32(env, args[2], (int32_t*)&format);

    int result = GetPixelDataSize(width, height, format);
    return int_to_js(env, result);
}

napi_value BindNode_GetFontDefault(napi_env env, napi_callback_info info) {
    Font result = GetFontDefault();
    return Font_to_js(env, result);
}

napi_value BindNode_LoadFont(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    size_t fileName_len;
    napi_get_value_string_utf8(env, args[0], NULL, 0, &fileName_len);
    char* fileName = (char*)malloc(fileName_len + 1);
    napi_get_value_string_utf8(env, args[0], fileName, fileName_len + 1, &fileName_len);

    Font result = LoadFont(fileName);
    free(fileName);
    return Font_to_js(env, result);
}

napi_value BindNode_LoadFontEx(napi_env env, napi_callback_info info) {
    size_t argc = 4;
    napi_value args[4];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 4) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    size_t fileName_len;
    napi_get_value_string_utf8(env, args[0], NULL, 0, &fileName_len);
    char* fileName = (char*)malloc(fileName_len + 1);
    napi_get_value_string_utf8(env, args[0], fileName, fileName_len + 1, &fileName_len);

    int fontSize;
    napi_get_value_int32(env, args[1], (int32_t*)&fontSize);

    int codepoints_value = int_from_js(env, args[2]);
    int * codepoints = &codepoints_value;

    int codepointCount;
    napi_get_value_int32(env, args[3], (int32_t*)&codepointCount);

    Font result = LoadFontEx(fileName, fontSize, codepoints, codepointCount);
    free(fileName);
    return Font_to_js(env, result);
}

napi_value BindNode_LoadFontFromImage(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value args[3];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 3) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Image image = Image_from_js(env, args[0]);

    Color key = Color_from_js(env, args[1]);

    int firstChar;
    napi_get_value_int32(env, args[2], (int32_t*)&firstChar);

    Font result = LoadFontFromImage(image, key, firstChar);
    return Font_to_js(env, result);
}

napi_value BindNode_LoadFontFromMemory(napi_env env, napi_callback_info info) {
    size_t argc = 6;
    napi_value args[6];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 6) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    size_t fileType_len;
    napi_get_value_string_utf8(env, args[0], NULL, 0, &fileType_len);
    char* fileType = (char*)malloc(fileType_len + 1);
    napi_get_value_string_utf8(env, args[0], fileType, fileType_len + 1, &fileType_len);

    // Warning: No conversion available for const unsigned char
    const unsigned char * fileData = NULL;

    int dataSize;
    napi_get_value_int32(env, args[2], (int32_t*)&dataSize);

    int fontSize;
    napi_get_value_int32(env, args[3], (int32_t*)&fontSize);

    int codepoints_value = int_from_js(env, args[4]);
    int * codepoints = &codepoints_value;

    int codepointCount;
    napi_get_value_int32(env, args[5], (int32_t*)&codepointCount);

    Font result = LoadFontFromMemory(fileType, fileData, dataSize, fontSize, codepoints, codepointCount);
    free(fileType);
    return Font_to_js(env, result);
}

napi_value BindNode_IsFontValid(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Font font = Font_from_js(env, args[0]);

    bool result = IsFontValid(font);
    napi_value jsResult;
    napi_get_boolean(env, result, &jsResult);
    return jsResult;
}

napi_value BindNode_LoadFontData(napi_env env, napi_callback_info info) {
    size_t argc = 6;
    napi_value args[6];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 6) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    // Warning: No conversion available for const unsigned char
    const unsigned char * fileData = NULL;

    int dataSize;
    napi_get_value_int32(env, args[1], (int32_t*)&dataSize);

    int fontSize;
    napi_get_value_int32(env, args[2], (int32_t*)&fontSize);

    int codepoints_value = int_from_js(env, args[3]);
    int * codepoints = &codepoints_value;

    int codepointCount;
    napi_get_value_int32(env, args[4], (int32_t*)&codepointCount);

    int type;
    napi_get_value_int32(env, args[5], (int32_t*)&type);

    GlyphInfo * result = LoadFontData(fileData, dataSize, fontSize, codepoints, codepointCount, type);
    // TODO: Handle return type GlyphInfo *
    napi_value jsResult;
    napi_get_null(env, &jsResult);
    return jsResult; // Placeholder
}

napi_value BindNode_GenImageFontAtlas(napi_env env, napi_callback_info info) {
    size_t argc = 6;
    napi_value args[6];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 6) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    // Warning: No conversion available for const GlyphInfo
    const GlyphInfo * glyphs = NULL;

    Rectangle * glyphRecs_value = Rectangle___from_js(env, args[1]);
    Rectangle ** glyphRecs = &glyphRecs_value;

    int glyphCount;
    napi_get_value_int32(env, args[2], (int32_t*)&glyphCount);

    int fontSize;
    napi_get_value_int32(env, args[3], (int32_t*)&fontSize);

    int padding;
    napi_get_value_int32(env, args[4], (int32_t*)&padding);

    int packMethod;
    napi_get_value_int32(env, args[5], (int32_t*)&packMethod);

    Image result = GenImageFontAtlas(glyphs, glyphRecs, glyphCount, fontSize, padding, packMethod);
    return Image_to_js(env, result);
}

napi_value BindNode_UnloadFontData(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    GlyphInfo glyphs_value = GlyphInfo_from_js(env, args[0]);
    GlyphInfo * glyphs = &glyphs_value;

    int glyphCount;
    napi_get_value_int32(env, args[1], (int32_t*)&glyphCount);

    UnloadFontData(glyphs, glyphCount);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_UnloadFont(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Font font = Font_from_js(env, args[0]);

    UnloadFont(font);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_ExportFontAsCode(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Font font = Font_from_js(env, args[0]);

    size_t fileName_len;
    napi_get_value_string_utf8(env, args[1], NULL, 0, &fileName_len);
    char* fileName = (char*)malloc(fileName_len + 1);
    napi_get_value_string_utf8(env, args[1], fileName, fileName_len + 1, &fileName_len);

    bool result = ExportFontAsCode(font, fileName);
    free(fileName);
    napi_value jsResult;
    napi_get_boolean(env, result, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawFPS(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    int posX;
    napi_get_value_int32(env, args[0], (int32_t*)&posX);

    int posY;
    napi_get_value_int32(env, args[1], (int32_t*)&posY);

    DrawFPS(posX, posY);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawText(napi_env env, napi_callback_info info) {
    size_t argc = 5;
    napi_value args[5];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 5) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    size_t text_len;
    napi_get_value_string_utf8(env, args[0], NULL, 0, &text_len);
    char* text = (char*)malloc(text_len + 1);
    napi_get_value_string_utf8(env, args[0], text, text_len + 1, &text_len);

    int posX;
    napi_get_value_int32(env, args[1], (int32_t*)&posX);

    int posY;
    napi_get_value_int32(env, args[2], (int32_t*)&posY);

    int fontSize;
    napi_get_value_int32(env, args[3], (int32_t*)&fontSize);

    Color color = Color_from_js(env, args[4]);

    DrawText(text, posX, posY, fontSize, color);
    free(text);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawTextEx(napi_env env, napi_callback_info info) {
    size_t argc = 6;
    napi_value args[6];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 6) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Font font = Font_from_js(env, args[0]);

    size_t text_len;
    napi_get_value_string_utf8(env, args[1], NULL, 0, &text_len);
    char* text = (char*)malloc(text_len + 1);
    napi_get_value_string_utf8(env, args[1], text, text_len + 1, &text_len);

    Vector2 position = Vector2_from_js(env, args[2]);

    double temp_fontSize;
    napi_get_value_double(env, args[3], &temp_fontSize);
    float fontSize = (float)temp_fontSize;

    double temp_spacing;
    napi_get_value_double(env, args[4], &temp_spacing);
    float spacing = (float)temp_spacing;

    Color tint = Color_from_js(env, args[5]);

    DrawTextEx(font, text, position, fontSize, spacing, tint);
    free(text);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawTextPro(napi_env env, napi_callback_info info) {
    size_t argc = 8;
    napi_value args[8];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 8) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Font font = Font_from_js(env, args[0]);

    size_t text_len;
    napi_get_value_string_utf8(env, args[1], NULL, 0, &text_len);
    char* text = (char*)malloc(text_len + 1);
    napi_get_value_string_utf8(env, args[1], text, text_len + 1, &text_len);

    Vector2 position = Vector2_from_js(env, args[2]);

    Vector2 origin = Vector2_from_js(env, args[3]);

    double temp_rotation;
    napi_get_value_double(env, args[4], &temp_rotation);
    float rotation = (float)temp_rotation;

    double temp_fontSize;
    napi_get_value_double(env, args[5], &temp_fontSize);
    float fontSize = (float)temp_fontSize;

    double temp_spacing;
    napi_get_value_double(env, args[6], &temp_spacing);
    float spacing = (float)temp_spacing;

    Color tint = Color_from_js(env, args[7]);

    DrawTextPro(font, text, position, origin, rotation, fontSize, spacing, tint);
    free(text);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawTextCodepoint(napi_env env, napi_callback_info info) {
    size_t argc = 5;
    napi_value args[5];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 5) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Font font = Font_from_js(env, args[0]);

    int codepoint;
    napi_get_value_int32(env, args[1], (int32_t*)&codepoint);

    Vector2 position = Vector2_from_js(env, args[2]);

    double temp_fontSize;
    napi_get_value_double(env, args[3], &temp_fontSize);
    float fontSize = (float)temp_fontSize;

    Color tint = Color_from_js(env, args[4]);

    DrawTextCodepoint(font, codepoint, position, fontSize, tint);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawTextCodepoints(napi_env env, napi_callback_info info) {
    size_t argc = 7;
    napi_value args[7];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 7) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Font font = Font_from_js(env, args[0]);

    // Warning: No conversion available for const int
    const int * codepoints = NULL;

    int codepointCount;
    napi_get_value_int32(env, args[2], (int32_t*)&codepointCount);

    Vector2 position = Vector2_from_js(env, args[3]);

    double temp_fontSize;
    napi_get_value_double(env, args[4], &temp_fontSize);
    float fontSize = (float)temp_fontSize;

    double temp_spacing;
    napi_get_value_double(env, args[5], &temp_spacing);
    float spacing = (float)temp_spacing;

    Color tint = Color_from_js(env, args[6]);

    DrawTextCodepoints(font, codepoints, codepointCount, position, fontSize, spacing, tint);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_SetTextLineSpacing(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    int spacing;
    napi_get_value_int32(env, args[0], (int32_t*)&spacing);

    SetTextLineSpacing(spacing);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_MeasureText(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    size_t text_len;
    napi_get_value_string_utf8(env, args[0], NULL, 0, &text_len);
    char* text = (char*)malloc(text_len + 1);
    napi_get_value_string_utf8(env, args[0], text, text_len + 1, &text_len);

    int fontSize;
    napi_get_value_int32(env, args[1], (int32_t*)&fontSize);

    int result = MeasureText(text, fontSize);
    free(text);
    return int_to_js(env, result);
}

napi_value BindNode_MeasureTextEx(napi_env env, napi_callback_info info) {
    size_t argc = 4;
    napi_value args[4];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 4) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Font font = Font_from_js(env, args[0]);

    size_t text_len;
    napi_get_value_string_utf8(env, args[1], NULL, 0, &text_len);
    char* text = (char*)malloc(text_len + 1);
    napi_get_value_string_utf8(env, args[1], text, text_len + 1, &text_len);

    double temp_fontSize;
    napi_get_value_double(env, args[2], &temp_fontSize);
    float fontSize = (float)temp_fontSize;

    double temp_spacing;
    napi_get_value_double(env, args[3], &temp_spacing);
    float spacing = (float)temp_spacing;

    Vector2 result = MeasureTextEx(font, text, fontSize, spacing);
    free(text);
    return Vector2_to_js(env, result);
}

napi_value BindNode_GetGlyphIndex(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Font font = Font_from_js(env, args[0]);

    int codepoint;
    napi_get_value_int32(env, args[1], (int32_t*)&codepoint);

    int result = GetGlyphIndex(font, codepoint);
    return int_to_js(env, result);
}

napi_value BindNode_GetGlyphInfo(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Font font = Font_from_js(env, args[0]);

    int codepoint;
    napi_get_value_int32(env, args[1], (int32_t*)&codepoint);

    GlyphInfo result = GetGlyphInfo(font, codepoint);
    return GlyphInfo_to_js(env, result);
}

napi_value BindNode_GetGlyphAtlasRec(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Font font = Font_from_js(env, args[0]);

    int codepoint;
    napi_get_value_int32(env, args[1], (int32_t*)&codepoint);

    Rectangle result = GetGlyphAtlasRec(font, codepoint);
    return Rectangle_to_js(env, result);
}

napi_value BindNode_LoadUTF8(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    // Warning: No conversion available for const int
    const int * codepoints = NULL;

    int length;
    napi_get_value_int32(env, args[1], (int32_t*)&length);

    char * result = LoadUTF8(codepoints, length);
    napi_value jsResult;
    if (result == NULL) {
        napi_get_null(env, &jsResult);
    } else {
        napi_create_string_utf8(env, result, NAPI_AUTO_LENGTH, &jsResult);
    }
    return jsResult;
}

napi_value BindNode_UnloadUTF8(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    size_t text_len;
    napi_get_value_string_utf8(env, args[0], NULL, 0, &text_len);
    char* text = (char*)malloc(text_len + 1);
    napi_get_value_string_utf8(env, args[0], text, text_len + 1, &text_len);

    UnloadUTF8(text);
    free(text);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_LoadCodepoints(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    size_t text_len;
    napi_get_value_string_utf8(env, args[0], NULL, 0, &text_len);
    char* text = (char*)malloc(text_len + 1);
    napi_get_value_string_utf8(env, args[0], text, text_len + 1, &text_len);

    int count_value = int_from_js(env, args[1]);
    int * count = &count_value;

    int * result = LoadCodepoints(text, count);
    free(text);
    // TODO: Handle return type int *
    napi_value jsResult;
    napi_get_null(env, &jsResult);
    return jsResult; // Placeholder
}

napi_value BindNode_UnloadCodepoints(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    int codepoints_value = int_from_js(env, args[0]);
    int * codepoints = &codepoints_value;

    UnloadCodepoints(codepoints);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_GetCodepointCount(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    size_t text_len;
    napi_get_value_string_utf8(env, args[0], NULL, 0, &text_len);
    char* text = (char*)malloc(text_len + 1);
    napi_get_value_string_utf8(env, args[0], text, text_len + 1, &text_len);

    int result = GetCodepointCount(text);
    free(text);
    return int_to_js(env, result);
}

napi_value BindNode_GetCodepoint(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    size_t text_len;
    napi_get_value_string_utf8(env, args[0], NULL, 0, &text_len);
    char* text = (char*)malloc(text_len + 1);
    napi_get_value_string_utf8(env, args[0], text, text_len + 1, &text_len);

    int codepointSize_value = int_from_js(env, args[1]);
    int * codepointSize = &codepointSize_value;

    int result = GetCodepoint(text, codepointSize);
    free(text);
    return int_to_js(env, result);
}

napi_value BindNode_GetCodepointNext(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    size_t text_len;
    napi_get_value_string_utf8(env, args[0], NULL, 0, &text_len);
    char* text = (char*)malloc(text_len + 1);
    napi_get_value_string_utf8(env, args[0], text, text_len + 1, &text_len);

    int codepointSize_value = int_from_js(env, args[1]);
    int * codepointSize = &codepointSize_value;

    int result = GetCodepointNext(text, codepointSize);
    free(text);
    return int_to_js(env, result);
}

napi_value BindNode_GetCodepointPrevious(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    size_t text_len;
    napi_get_value_string_utf8(env, args[0], NULL, 0, &text_len);
    char* text = (char*)malloc(text_len + 1);
    napi_get_value_string_utf8(env, args[0], text, text_len + 1, &text_len);

    int codepointSize_value = int_from_js(env, args[1]);
    int * codepointSize = &codepointSize_value;

    int result = GetCodepointPrevious(text, codepointSize);
    free(text);
    return int_to_js(env, result);
}

napi_value BindNode_CodepointToUTF8(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    int codepoint;
    napi_get_value_int32(env, args[0], (int32_t*)&codepoint);

    int utf8Size_value = int_from_js(env, args[1]);
    int * utf8Size = &utf8Size_value;

    const char * result = CodepointToUTF8(codepoint, utf8Size);
    napi_value jsResult;
    if (result == NULL) {
        napi_get_null(env, &jsResult);
    } else {
        napi_create_string_utf8(env, result, NAPI_AUTO_LENGTH, &jsResult);
    }
    return jsResult;
}

napi_value BindNode_TextCopy(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    size_t dst_len;
    napi_get_value_string_utf8(env, args[0], NULL, 0, &dst_len);
    char* dst = (char*)malloc(dst_len + 1);
    napi_get_value_string_utf8(env, args[0], dst, dst_len + 1, &dst_len);

    size_t src_len;
    napi_get_value_string_utf8(env, args[1], NULL, 0, &src_len);
    char* src = (char*)malloc(src_len + 1);
    napi_get_value_string_utf8(env, args[1], src, src_len + 1, &src_len);

    int result = TextCopy(dst, src);
    free(dst);
    free(src);
    return int_to_js(env, result);
}

napi_value BindNode_TextIsEqual(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    size_t text1_len;
    napi_get_value_string_utf8(env, args[0], NULL, 0, &text1_len);
    char* text1 = (char*)malloc(text1_len + 1);
    napi_get_value_string_utf8(env, args[0], text1, text1_len + 1, &text1_len);

    size_t text2_len;
    napi_get_value_string_utf8(env, args[1], NULL, 0, &text2_len);
    char* text2 = (char*)malloc(text2_len + 1);
    napi_get_value_string_utf8(env, args[1], text2, text2_len + 1, &text2_len);

    bool result = TextIsEqual(text1, text2);
    free(text1);
    free(text2);
    napi_value jsResult;
    napi_get_boolean(env, result, &jsResult);
    return jsResult;
}

napi_value BindNode_TextLength(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    size_t text_len;
    napi_get_value_string_utf8(env, args[0], NULL, 0, &text_len);
    char* text = (char*)malloc(text_len + 1);
    napi_get_value_string_utf8(env, args[0], text, text_len + 1, &text_len);

    unsigned int result = TextLength(text);
    free(text);
    napi_value jsResult;
    napi_create_int32(env, (int32_t)result, &jsResult);
    return jsResult;
}

napi_value BindNode_TextFormat(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    size_t text_len;
    napi_get_value_string_utf8(env, args[0], NULL, 0, &text_len);
    char* text = (char*)malloc(text_len + 1);
    napi_get_value_string_utf8(env, args[0], text, text_len + 1, &text_len);

    const char * result = TextFormat(text);
    free(text);
    napi_value jsResult;
    if (result == NULL) {
        napi_get_null(env, &jsResult);
    } else {
        napi_create_string_utf8(env, result, NAPI_AUTO_LENGTH, &jsResult);
    }
    return jsResult;
}

napi_value BindNode_TextSubtext(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value args[3];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 3) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    size_t text_len;
    napi_get_value_string_utf8(env, args[0], NULL, 0, &text_len);
    char* text = (char*)malloc(text_len + 1);
    napi_get_value_string_utf8(env, args[0], text, text_len + 1, &text_len);

    int position;
    napi_get_value_int32(env, args[1], (int32_t*)&position);

    int length;
    napi_get_value_int32(env, args[2], (int32_t*)&length);

    const char * result = TextSubtext(text, position, length);
    free(text);
    napi_value jsResult;
    if (result == NULL) {
        napi_get_null(env, &jsResult);
    } else {
        napi_create_string_utf8(env, result, NAPI_AUTO_LENGTH, &jsResult);
    }
    return jsResult;
}

napi_value BindNode_TextReplace(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value args[3];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 3) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    size_t text_len;
    napi_get_value_string_utf8(env, args[0], NULL, 0, &text_len);
    char* text = (char*)malloc(text_len + 1);
    napi_get_value_string_utf8(env, args[0], text, text_len + 1, &text_len);

    size_t replace_len;
    napi_get_value_string_utf8(env, args[1], NULL, 0, &replace_len);
    char* replace = (char*)malloc(replace_len + 1);
    napi_get_value_string_utf8(env, args[1], replace, replace_len + 1, &replace_len);

    size_t by_len;
    napi_get_value_string_utf8(env, args[2], NULL, 0, &by_len);
    char* by = (char*)malloc(by_len + 1);
    napi_get_value_string_utf8(env, args[2], by, by_len + 1, &by_len);

    char * result = TextReplace(text, replace, by);
    free(text);
    free(replace);
    free(by);
    napi_value jsResult;
    if (result == NULL) {
        napi_get_null(env, &jsResult);
    } else {
        napi_create_string_utf8(env, result, NAPI_AUTO_LENGTH, &jsResult);
    }
    return jsResult;
}

napi_value BindNode_TextInsert(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value args[3];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 3) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    size_t text_len;
    napi_get_value_string_utf8(env, args[0], NULL, 0, &text_len);
    char* text = (char*)malloc(text_len + 1);
    napi_get_value_string_utf8(env, args[0], text, text_len + 1, &text_len);

    size_t insert_len;
    napi_get_value_string_utf8(env, args[1], NULL, 0, &insert_len);
    char* insert = (char*)malloc(insert_len + 1);
    napi_get_value_string_utf8(env, args[1], insert, insert_len + 1, &insert_len);

    int position;
    napi_get_value_int32(env, args[2], (int32_t*)&position);

    char * result = TextInsert(text, insert, position);
    free(text);
    free(insert);
    napi_value jsResult;
    if (result == NULL) {
        napi_get_null(env, &jsResult);
    } else {
        napi_create_string_utf8(env, result, NAPI_AUTO_LENGTH, &jsResult);
    }
    return jsResult;
}

napi_value BindNode_TextJoin(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value args[3];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 3) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    // TODO: Handle parameter type const char **
    void* textList = NULL; // Placeholder

    int count;
    napi_get_value_int32(env, args[1], (int32_t*)&count);

    size_t delimiter_len;
    napi_get_value_string_utf8(env, args[2], NULL, 0, &delimiter_len);
    char* delimiter = (char*)malloc(delimiter_len + 1);
    napi_get_value_string_utf8(env, args[2], delimiter, delimiter_len + 1, &delimiter_len);

    const char * result = TextJoin(textList, count, delimiter);
    free(delimiter);
    napi_value jsResult;
    if (result == NULL) {
        napi_get_null(env, &jsResult);
    } else {
        napi_create_string_utf8(env, result, NAPI_AUTO_LENGTH, &jsResult);
    }
    return jsResult;
}

napi_value BindNode_TextSplit(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value args[3];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 3) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    size_t text_len;
    napi_get_value_string_utf8(env, args[0], NULL, 0, &text_len);
    char* text = (char*)malloc(text_len + 1);
    napi_get_value_string_utf8(env, args[0], text, text_len + 1, &text_len);

    char delimiter;
    napi_get_value_int32(env, args[1], (int32_t*)&delimiter);

    int count_value = int_from_js(env, args[2]);
    int * count = &count_value;

    const char ** result = TextSplit(text, delimiter, count);
    free(text);
    // TODO: Handle return type const char **
    napi_value jsResult;
    napi_get_null(env, &jsResult);
    return jsResult; // Placeholder
}

napi_value BindNode_TextAppend(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value args[3];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 3) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    size_t text_len;
    napi_get_value_string_utf8(env, args[0], NULL, 0, &text_len);
    char* text = (char*)malloc(text_len + 1);
    napi_get_value_string_utf8(env, args[0], text, text_len + 1, &text_len);

    size_t append_len;
    napi_get_value_string_utf8(env, args[1], NULL, 0, &append_len);
    char* append = (char*)malloc(append_len + 1);
    napi_get_value_string_utf8(env, args[1], append, append_len + 1, &append_len);

    int position_value = int_from_js(env, args[2]);
    int * position = &position_value;

    TextAppend(text, append, position);
    free(text);
    free(append);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_TextFindIndex(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    size_t text_len;
    napi_get_value_string_utf8(env, args[0], NULL, 0, &text_len);
    char* text = (char*)malloc(text_len + 1);
    napi_get_value_string_utf8(env, args[0], text, text_len + 1, &text_len);

    size_t find_len;
    napi_get_value_string_utf8(env, args[1], NULL, 0, &find_len);
    char* find = (char*)malloc(find_len + 1);
    napi_get_value_string_utf8(env, args[1], find, find_len + 1, &find_len);

    int result = TextFindIndex(text, find);
    free(text);
    free(find);
    return int_to_js(env, result);
}

napi_value BindNode_TextToUpper(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    size_t text_len;
    napi_get_value_string_utf8(env, args[0], NULL, 0, &text_len);
    char* text = (char*)malloc(text_len + 1);
    napi_get_value_string_utf8(env, args[0], text, text_len + 1, &text_len);

    const char * result = TextToUpper(text);
    free(text);
    napi_value jsResult;
    if (result == NULL) {
        napi_get_null(env, &jsResult);
    } else {
        napi_create_string_utf8(env, result, NAPI_AUTO_LENGTH, &jsResult);
    }
    return jsResult;
}

napi_value BindNode_TextToLower(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    size_t text_len;
    napi_get_value_string_utf8(env, args[0], NULL, 0, &text_len);
    char* text = (char*)malloc(text_len + 1);
    napi_get_value_string_utf8(env, args[0], text, text_len + 1, &text_len);

    const char * result = TextToLower(text);
    free(text);
    napi_value jsResult;
    if (result == NULL) {
        napi_get_null(env, &jsResult);
    } else {
        napi_create_string_utf8(env, result, NAPI_AUTO_LENGTH, &jsResult);
    }
    return jsResult;
}

napi_value BindNode_TextToPascal(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    size_t text_len;
    napi_get_value_string_utf8(env, args[0], NULL, 0, &text_len);
    char* text = (char*)malloc(text_len + 1);
    napi_get_value_string_utf8(env, args[0], text, text_len + 1, &text_len);

    const char * result = TextToPascal(text);
    free(text);
    napi_value jsResult;
    if (result == NULL) {
        napi_get_null(env, &jsResult);
    } else {
        napi_create_string_utf8(env, result, NAPI_AUTO_LENGTH, &jsResult);
    }
    return jsResult;
}

napi_value BindNode_TextToSnake(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    size_t text_len;
    napi_get_value_string_utf8(env, args[0], NULL, 0, &text_len);
    char* text = (char*)malloc(text_len + 1);
    napi_get_value_string_utf8(env, args[0], text, text_len + 1, &text_len);

    const char * result = TextToSnake(text);
    free(text);
    napi_value jsResult;
    if (result == NULL) {
        napi_get_null(env, &jsResult);
    } else {
        napi_create_string_utf8(env, result, NAPI_AUTO_LENGTH, &jsResult);
    }
    return jsResult;
}

napi_value BindNode_TextToCamel(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    size_t text_len;
    napi_get_value_string_utf8(env, args[0], NULL, 0, &text_len);
    char* text = (char*)malloc(text_len + 1);
    napi_get_value_string_utf8(env, args[0], text, text_len + 1, &text_len);

    const char * result = TextToCamel(text);
    free(text);
    napi_value jsResult;
    if (result == NULL) {
        napi_get_null(env, &jsResult);
    } else {
        napi_create_string_utf8(env, result, NAPI_AUTO_LENGTH, &jsResult);
    }
    return jsResult;
}

napi_value BindNode_TextToInteger(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    size_t text_len;
    napi_get_value_string_utf8(env, args[0], NULL, 0, &text_len);
    char* text = (char*)malloc(text_len + 1);
    napi_get_value_string_utf8(env, args[0], text, text_len + 1, &text_len);

    int result = TextToInteger(text);
    free(text);
    return int_to_js(env, result);
}

napi_value BindNode_TextToFloat(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    size_t text_len;
    napi_get_value_string_utf8(env, args[0], NULL, 0, &text_len);
    char* text = (char*)malloc(text_len + 1);
    napi_get_value_string_utf8(env, args[0], text, text_len + 1, &text_len);

    float result = TextToFloat(text);
    free(text);
    return float_to_js(env, result);
}

napi_value BindNode_DrawLine3D(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value args[3];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 3) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Vector3 startPos = Vector3_from_js(env, args[0]);

    Vector3 endPos = Vector3_from_js(env, args[1]);

    Color color = Color_from_js(env, args[2]);

    DrawLine3D(startPos, endPos, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawPoint3D(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Vector3 position = Vector3_from_js(env, args[0]);

    Color color = Color_from_js(env, args[1]);

    DrawPoint3D(position, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawCircle3D(napi_env env, napi_callback_info info) {
    size_t argc = 5;
    napi_value args[5];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 5) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Vector3 center = Vector3_from_js(env, args[0]);

    double temp_radius;
    napi_get_value_double(env, args[1], &temp_radius);
    float radius = (float)temp_radius;

    Vector3 rotationAxis = Vector3_from_js(env, args[2]);

    double temp_rotationAngle;
    napi_get_value_double(env, args[3], &temp_rotationAngle);
    float rotationAngle = (float)temp_rotationAngle;

    Color color = Color_from_js(env, args[4]);

    DrawCircle3D(center, radius, rotationAxis, rotationAngle, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawTriangle3D(napi_env env, napi_callback_info info) {
    size_t argc = 4;
    napi_value args[4];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 4) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Vector3 v1 = Vector3_from_js(env, args[0]);

    Vector3 v2 = Vector3_from_js(env, args[1]);

    Vector3 v3 = Vector3_from_js(env, args[2]);

    Color color = Color_from_js(env, args[3]);

    DrawTriangle3D(v1, v2, v3, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawTriangleStrip3D(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value args[3];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 3) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    // Warning: No conversion available for const Vector3
    const Vector3 * points = NULL;

    int pointCount;
    napi_get_value_int32(env, args[1], (int32_t*)&pointCount);

    Color color = Color_from_js(env, args[2]);

    DrawTriangleStrip3D(points, pointCount, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawCube(napi_env env, napi_callback_info info) {
    size_t argc = 5;
    napi_value args[5];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 5) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Vector3 position = Vector3_from_js(env, args[0]);

    double temp_width;
    napi_get_value_double(env, args[1], &temp_width);
    float width = (float)temp_width;

    double temp_height;
    napi_get_value_double(env, args[2], &temp_height);
    float height = (float)temp_height;

    double temp_length;
    napi_get_value_double(env, args[3], &temp_length);
    float length = (float)temp_length;

    Color color = Color_from_js(env, args[4]);

    DrawCube(position, width, height, length, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawCubeV(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value args[3];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 3) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Vector3 position = Vector3_from_js(env, args[0]);

    Vector3 size = Vector3_from_js(env, args[1]);

    Color color = Color_from_js(env, args[2]);

    DrawCubeV(position, size, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawCubeWires(napi_env env, napi_callback_info info) {
    size_t argc = 5;
    napi_value args[5];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 5) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Vector3 position = Vector3_from_js(env, args[0]);

    double temp_width;
    napi_get_value_double(env, args[1], &temp_width);
    float width = (float)temp_width;

    double temp_height;
    napi_get_value_double(env, args[2], &temp_height);
    float height = (float)temp_height;

    double temp_length;
    napi_get_value_double(env, args[3], &temp_length);
    float length = (float)temp_length;

    Color color = Color_from_js(env, args[4]);

    DrawCubeWires(position, width, height, length, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawCubeWiresV(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value args[3];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 3) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Vector3 position = Vector3_from_js(env, args[0]);

    Vector3 size = Vector3_from_js(env, args[1]);

    Color color = Color_from_js(env, args[2]);

    DrawCubeWiresV(position, size, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawSphere(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value args[3];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 3) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Vector3 centerPos = Vector3_from_js(env, args[0]);

    double temp_radius;
    napi_get_value_double(env, args[1], &temp_radius);
    float radius = (float)temp_radius;

    Color color = Color_from_js(env, args[2]);

    DrawSphere(centerPos, radius, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawSphereEx(napi_env env, napi_callback_info info) {
    size_t argc = 5;
    napi_value args[5];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 5) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Vector3 centerPos = Vector3_from_js(env, args[0]);

    double temp_radius;
    napi_get_value_double(env, args[1], &temp_radius);
    float radius = (float)temp_radius;

    int rings;
    napi_get_value_int32(env, args[2], (int32_t*)&rings);

    int slices;
    napi_get_value_int32(env, args[3], (int32_t*)&slices);

    Color color = Color_from_js(env, args[4]);

    DrawSphereEx(centerPos, radius, rings, slices, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawSphereWires(napi_env env, napi_callback_info info) {
    size_t argc = 5;
    napi_value args[5];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 5) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Vector3 centerPos = Vector3_from_js(env, args[0]);

    double temp_radius;
    napi_get_value_double(env, args[1], &temp_radius);
    float radius = (float)temp_radius;

    int rings;
    napi_get_value_int32(env, args[2], (int32_t*)&rings);

    int slices;
    napi_get_value_int32(env, args[3], (int32_t*)&slices);

    Color color = Color_from_js(env, args[4]);

    DrawSphereWires(centerPos, radius, rings, slices, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawCylinder(napi_env env, napi_callback_info info) {
    size_t argc = 6;
    napi_value args[6];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 6) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Vector3 position = Vector3_from_js(env, args[0]);

    double temp_radiusTop;
    napi_get_value_double(env, args[1], &temp_radiusTop);
    float radiusTop = (float)temp_radiusTop;

    double temp_radiusBottom;
    napi_get_value_double(env, args[2], &temp_radiusBottom);
    float radiusBottom = (float)temp_radiusBottom;

    double temp_height;
    napi_get_value_double(env, args[3], &temp_height);
    float height = (float)temp_height;

    int slices;
    napi_get_value_int32(env, args[4], (int32_t*)&slices);

    Color color = Color_from_js(env, args[5]);

    DrawCylinder(position, radiusTop, radiusBottom, height, slices, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawCylinderEx(napi_env env, napi_callback_info info) {
    size_t argc = 6;
    napi_value args[6];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 6) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Vector3 startPos = Vector3_from_js(env, args[0]);

    Vector3 endPos = Vector3_from_js(env, args[1]);

    double temp_startRadius;
    napi_get_value_double(env, args[2], &temp_startRadius);
    float startRadius = (float)temp_startRadius;

    double temp_endRadius;
    napi_get_value_double(env, args[3], &temp_endRadius);
    float endRadius = (float)temp_endRadius;

    int sides;
    napi_get_value_int32(env, args[4], (int32_t*)&sides);

    Color color = Color_from_js(env, args[5]);

    DrawCylinderEx(startPos, endPos, startRadius, endRadius, sides, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawCylinderWires(napi_env env, napi_callback_info info) {
    size_t argc = 6;
    napi_value args[6];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 6) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Vector3 position = Vector3_from_js(env, args[0]);

    double temp_radiusTop;
    napi_get_value_double(env, args[1], &temp_radiusTop);
    float radiusTop = (float)temp_radiusTop;

    double temp_radiusBottom;
    napi_get_value_double(env, args[2], &temp_radiusBottom);
    float radiusBottom = (float)temp_radiusBottom;

    double temp_height;
    napi_get_value_double(env, args[3], &temp_height);
    float height = (float)temp_height;

    int slices;
    napi_get_value_int32(env, args[4], (int32_t*)&slices);

    Color color = Color_from_js(env, args[5]);

    DrawCylinderWires(position, radiusTop, radiusBottom, height, slices, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawCylinderWiresEx(napi_env env, napi_callback_info info) {
    size_t argc = 6;
    napi_value args[6];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 6) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Vector3 startPos = Vector3_from_js(env, args[0]);

    Vector3 endPos = Vector3_from_js(env, args[1]);

    double temp_startRadius;
    napi_get_value_double(env, args[2], &temp_startRadius);
    float startRadius = (float)temp_startRadius;

    double temp_endRadius;
    napi_get_value_double(env, args[3], &temp_endRadius);
    float endRadius = (float)temp_endRadius;

    int sides;
    napi_get_value_int32(env, args[4], (int32_t*)&sides);

    Color color = Color_from_js(env, args[5]);

    DrawCylinderWiresEx(startPos, endPos, startRadius, endRadius, sides, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawCapsule(napi_env env, napi_callback_info info) {
    size_t argc = 6;
    napi_value args[6];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 6) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Vector3 startPos = Vector3_from_js(env, args[0]);

    Vector3 endPos = Vector3_from_js(env, args[1]);

    double temp_radius;
    napi_get_value_double(env, args[2], &temp_radius);
    float radius = (float)temp_radius;

    int slices;
    napi_get_value_int32(env, args[3], (int32_t*)&slices);

    int rings;
    napi_get_value_int32(env, args[4], (int32_t*)&rings);

    Color color = Color_from_js(env, args[5]);

    DrawCapsule(startPos, endPos, radius, slices, rings, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawCapsuleWires(napi_env env, napi_callback_info info) {
    size_t argc = 6;
    napi_value args[6];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 6) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Vector3 startPos = Vector3_from_js(env, args[0]);

    Vector3 endPos = Vector3_from_js(env, args[1]);

    double temp_radius;
    napi_get_value_double(env, args[2], &temp_radius);
    float radius = (float)temp_radius;

    int slices;
    napi_get_value_int32(env, args[3], (int32_t*)&slices);

    int rings;
    napi_get_value_int32(env, args[4], (int32_t*)&rings);

    Color color = Color_from_js(env, args[5]);

    DrawCapsuleWires(startPos, endPos, radius, slices, rings, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawPlane(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value args[3];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 3) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Vector3 centerPos = Vector3_from_js(env, args[0]);

    Vector2 size = Vector2_from_js(env, args[1]);

    Color color = Color_from_js(env, args[2]);

    DrawPlane(centerPos, size, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawRay(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Ray ray = Ray_from_js(env, args[0]);

    Color color = Color_from_js(env, args[1]);

    DrawRay(ray, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawGrid(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    int slices;
    napi_get_value_int32(env, args[0], (int32_t*)&slices);

    double temp_spacing;
    napi_get_value_double(env, args[1], &temp_spacing);
    float spacing = (float)temp_spacing;

    DrawGrid(slices, spacing);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_LoadModel(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    size_t fileName_len;
    napi_get_value_string_utf8(env, args[0], NULL, 0, &fileName_len);
    char* fileName = (char*)malloc(fileName_len + 1);
    napi_get_value_string_utf8(env, args[0], fileName, fileName_len + 1, &fileName_len);

    Model result = LoadModel(fileName);
    free(fileName);
    return Model_to_js(env, result);
}

napi_value BindNode_LoadModelFromMesh(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Mesh mesh = Mesh_from_js(env, args[0]);

    Model result = LoadModelFromMesh(mesh);
    return Model_to_js(env, result);
}

napi_value BindNode_IsModelValid(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Model model = Model_from_js(env, args[0]);

    bool result = IsModelValid(model);
    napi_value jsResult;
    napi_get_boolean(env, result, &jsResult);
    return jsResult;
}

napi_value BindNode_UnloadModel(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Model model = Model_from_js(env, args[0]);

    UnloadModel(model);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_GetModelBoundingBox(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Model model = Model_from_js(env, args[0]);

    BoundingBox result = GetModelBoundingBox(model);
    return BoundingBox_to_js(env, result);
}

napi_value BindNode_DrawModel(napi_env env, napi_callback_info info) {
    size_t argc = 4;
    napi_value args[4];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 4) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Model model = Model_from_js(env, args[0]);

    Vector3 position = Vector3_from_js(env, args[1]);

    double temp_scale;
    napi_get_value_double(env, args[2], &temp_scale);
    float scale = (float)temp_scale;

    Color tint = Color_from_js(env, args[3]);

    DrawModel(model, position, scale, tint);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawModelEx(napi_env env, napi_callback_info info) {
    size_t argc = 6;
    napi_value args[6];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 6) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Model model = Model_from_js(env, args[0]);

    Vector3 position = Vector3_from_js(env, args[1]);

    Vector3 rotationAxis = Vector3_from_js(env, args[2]);

    double temp_rotationAngle;
    napi_get_value_double(env, args[3], &temp_rotationAngle);
    float rotationAngle = (float)temp_rotationAngle;

    Vector3 scale = Vector3_from_js(env, args[4]);

    Color tint = Color_from_js(env, args[5]);

    DrawModelEx(model, position, rotationAxis, rotationAngle, scale, tint);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawModelWires(napi_env env, napi_callback_info info) {
    size_t argc = 4;
    napi_value args[4];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 4) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Model model = Model_from_js(env, args[0]);

    Vector3 position = Vector3_from_js(env, args[1]);

    double temp_scale;
    napi_get_value_double(env, args[2], &temp_scale);
    float scale = (float)temp_scale;

    Color tint = Color_from_js(env, args[3]);

    DrawModelWires(model, position, scale, tint);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawModelWiresEx(napi_env env, napi_callback_info info) {
    size_t argc = 6;
    napi_value args[6];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 6) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Model model = Model_from_js(env, args[0]);

    Vector3 position = Vector3_from_js(env, args[1]);

    Vector3 rotationAxis = Vector3_from_js(env, args[2]);

    double temp_rotationAngle;
    napi_get_value_double(env, args[3], &temp_rotationAngle);
    float rotationAngle = (float)temp_rotationAngle;

    Vector3 scale = Vector3_from_js(env, args[4]);

    Color tint = Color_from_js(env, args[5]);

    DrawModelWiresEx(model, position, rotationAxis, rotationAngle, scale, tint);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawModelPoints(napi_env env, napi_callback_info info) {
    size_t argc = 4;
    napi_value args[4];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 4) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Model model = Model_from_js(env, args[0]);

    Vector3 position = Vector3_from_js(env, args[1]);

    double temp_scale;
    napi_get_value_double(env, args[2], &temp_scale);
    float scale = (float)temp_scale;

    Color tint = Color_from_js(env, args[3]);

    DrawModelPoints(model, position, scale, tint);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawModelPointsEx(napi_env env, napi_callback_info info) {
    size_t argc = 6;
    napi_value args[6];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 6) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Model model = Model_from_js(env, args[0]);

    Vector3 position = Vector3_from_js(env, args[1]);

    Vector3 rotationAxis = Vector3_from_js(env, args[2]);

    double temp_rotationAngle;
    napi_get_value_double(env, args[3], &temp_rotationAngle);
    float rotationAngle = (float)temp_rotationAngle;

    Vector3 scale = Vector3_from_js(env, args[4]);

    Color tint = Color_from_js(env, args[5]);

    DrawModelPointsEx(model, position, rotationAxis, rotationAngle, scale, tint);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawBoundingBox(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    BoundingBox box = BoundingBox_from_js(env, args[0]);

    Color color = Color_from_js(env, args[1]);

    DrawBoundingBox(box, color);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawBillboard(napi_env env, napi_callback_info info) {
    size_t argc = 5;
    napi_value args[5];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 5) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Camera camera = Camera_from_js(env, args[0]);

    Texture2D texture = Texture2D_from_js(env, args[1]);

    Vector3 position = Vector3_from_js(env, args[2]);

    double temp_scale;
    napi_get_value_double(env, args[3], &temp_scale);
    float scale = (float)temp_scale;

    Color tint = Color_from_js(env, args[4]);

    DrawBillboard(camera, texture, position, scale, tint);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawBillboardRec(napi_env env, napi_callback_info info) {
    size_t argc = 6;
    napi_value args[6];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 6) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Camera camera = Camera_from_js(env, args[0]);

    Texture2D texture = Texture2D_from_js(env, args[1]);

    Rectangle source = Rectangle_from_js(env, args[2]);

    Vector3 position = Vector3_from_js(env, args[3]);

    Vector2 size = Vector2_from_js(env, args[4]);

    Color tint = Color_from_js(env, args[5]);

    DrawBillboardRec(camera, texture, source, position, size, tint);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawBillboardPro(napi_env env, napi_callback_info info) {
    size_t argc = 9;
    napi_value args[9];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 9) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Camera camera = Camera_from_js(env, args[0]);

    Texture2D texture = Texture2D_from_js(env, args[1]);

    Rectangle source = Rectangle_from_js(env, args[2]);

    Vector3 position = Vector3_from_js(env, args[3]);

    Vector3 up = Vector3_from_js(env, args[4]);

    Vector2 size = Vector2_from_js(env, args[5]);

    Vector2 origin = Vector2_from_js(env, args[6]);

    double temp_rotation;
    napi_get_value_double(env, args[7], &temp_rotation);
    float rotation = (float)temp_rotation;

    Color tint = Color_from_js(env, args[8]);

    DrawBillboardPro(camera, texture, source, position, up, size, origin, rotation, tint);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_UploadMesh(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Mesh mesh_value = Mesh_from_js(env, args[0]);
    Mesh * mesh = &mesh_value;

    bool dynamic;
    napi_get_value_bool(env, args[1], &dynamic);

    UploadMesh(mesh, dynamic);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_UpdateMeshBuffer(napi_env env, napi_callback_info info) {
    size_t argc = 5;
    napi_value args[5];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 5) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Mesh mesh = Mesh_from_js(env, args[0]);

    int index;
    napi_get_value_int32(env, args[1], (int32_t*)&index);

    // Warning: No conversion available for const void
    const void * data = NULL;

    int dataSize;
    napi_get_value_int32(env, args[3], (int32_t*)&dataSize);

    int offset;
    napi_get_value_int32(env, args[4], (int32_t*)&offset);

    UpdateMeshBuffer(mesh, index, data, dataSize, offset);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_UnloadMesh(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Mesh mesh = Mesh_from_js(env, args[0]);

    UnloadMesh(mesh);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawMesh(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value args[3];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 3) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Mesh mesh = Mesh_from_js(env, args[0]);

    Material material = Material_from_js(env, args[1]);

    Matrix transform = Matrix_from_js(env, args[2]);

    DrawMesh(mesh, material, transform);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DrawMeshInstanced(napi_env env, napi_callback_info info) {
    size_t argc = 4;
    napi_value args[4];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 4) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Mesh mesh = Mesh_from_js(env, args[0]);

    Material material = Material_from_js(env, args[1]);

    // Warning: No conversion available for const Matrix
    const Matrix * transforms = NULL;

    int instances;
    napi_get_value_int32(env, args[3], (int32_t*)&instances);

    DrawMeshInstanced(mesh, material, transforms, instances);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_GetMeshBoundingBox(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Mesh mesh = Mesh_from_js(env, args[0]);

    BoundingBox result = GetMeshBoundingBox(mesh);
    return BoundingBox_to_js(env, result);
}

napi_value BindNode_GenMeshTangents(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Mesh mesh_value = Mesh_from_js(env, args[0]);
    Mesh * mesh = &mesh_value;

    GenMeshTangents(mesh);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_ExportMesh(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Mesh mesh = Mesh_from_js(env, args[0]);

    size_t fileName_len;
    napi_get_value_string_utf8(env, args[1], NULL, 0, &fileName_len);
    char* fileName = (char*)malloc(fileName_len + 1);
    napi_get_value_string_utf8(env, args[1], fileName, fileName_len + 1, &fileName_len);

    bool result = ExportMesh(mesh, fileName);
    free(fileName);
    napi_value jsResult;
    napi_get_boolean(env, result, &jsResult);
    return jsResult;
}

napi_value BindNode_ExportMeshAsCode(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Mesh mesh = Mesh_from_js(env, args[0]);

    size_t fileName_len;
    napi_get_value_string_utf8(env, args[1], NULL, 0, &fileName_len);
    char* fileName = (char*)malloc(fileName_len + 1);
    napi_get_value_string_utf8(env, args[1], fileName, fileName_len + 1, &fileName_len);

    bool result = ExportMeshAsCode(mesh, fileName);
    free(fileName);
    napi_value jsResult;
    napi_get_boolean(env, result, &jsResult);
    return jsResult;
}

napi_value BindNode_GenMeshPoly(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    int sides;
    napi_get_value_int32(env, args[0], (int32_t*)&sides);

    double temp_radius;
    napi_get_value_double(env, args[1], &temp_radius);
    float radius = (float)temp_radius;

    Mesh result = GenMeshPoly(sides, radius);
    return Mesh_to_js(env, result);
}

napi_value BindNode_GenMeshPlane(napi_env env, napi_callback_info info) {
    size_t argc = 4;
    napi_value args[4];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 4) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    double temp_width;
    napi_get_value_double(env, args[0], &temp_width);
    float width = (float)temp_width;

    double temp_length;
    napi_get_value_double(env, args[1], &temp_length);
    float length = (float)temp_length;

    int resX;
    napi_get_value_int32(env, args[2], (int32_t*)&resX);

    int resZ;
    napi_get_value_int32(env, args[3], (int32_t*)&resZ);

    Mesh result = GenMeshPlane(width, length, resX, resZ);
    return Mesh_to_js(env, result);
}

napi_value BindNode_GenMeshCube(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value args[3];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 3) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    double temp_width;
    napi_get_value_double(env, args[0], &temp_width);
    float width = (float)temp_width;

    double temp_height;
    napi_get_value_double(env, args[1], &temp_height);
    float height = (float)temp_height;

    double temp_length;
    napi_get_value_double(env, args[2], &temp_length);
    float length = (float)temp_length;

    Mesh result = GenMeshCube(width, height, length);
    return Mesh_to_js(env, result);
}

napi_value BindNode_GenMeshSphere(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value args[3];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 3) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    double temp_radius;
    napi_get_value_double(env, args[0], &temp_radius);
    float radius = (float)temp_radius;

    int rings;
    napi_get_value_int32(env, args[1], (int32_t*)&rings);

    int slices;
    napi_get_value_int32(env, args[2], (int32_t*)&slices);

    Mesh result = GenMeshSphere(radius, rings, slices);
    return Mesh_to_js(env, result);
}

napi_value BindNode_GenMeshHemiSphere(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value args[3];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 3) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    double temp_radius;
    napi_get_value_double(env, args[0], &temp_radius);
    float radius = (float)temp_radius;

    int rings;
    napi_get_value_int32(env, args[1], (int32_t*)&rings);

    int slices;
    napi_get_value_int32(env, args[2], (int32_t*)&slices);

    Mesh result = GenMeshHemiSphere(radius, rings, slices);
    return Mesh_to_js(env, result);
}

napi_value BindNode_GenMeshCylinder(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value args[3];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 3) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    double temp_radius;
    napi_get_value_double(env, args[0], &temp_radius);
    float radius = (float)temp_radius;

    double temp_height;
    napi_get_value_double(env, args[1], &temp_height);
    float height = (float)temp_height;

    int slices;
    napi_get_value_int32(env, args[2], (int32_t*)&slices);

    Mesh result = GenMeshCylinder(radius, height, slices);
    return Mesh_to_js(env, result);
}

napi_value BindNode_GenMeshCone(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value args[3];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 3) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    double temp_radius;
    napi_get_value_double(env, args[0], &temp_radius);
    float radius = (float)temp_radius;

    double temp_height;
    napi_get_value_double(env, args[1], &temp_height);
    float height = (float)temp_height;

    int slices;
    napi_get_value_int32(env, args[2], (int32_t*)&slices);

    Mesh result = GenMeshCone(radius, height, slices);
    return Mesh_to_js(env, result);
}

napi_value BindNode_GenMeshTorus(napi_env env, napi_callback_info info) {
    size_t argc = 4;
    napi_value args[4];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 4) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    double temp_radius;
    napi_get_value_double(env, args[0], &temp_radius);
    float radius = (float)temp_radius;

    double temp_size;
    napi_get_value_double(env, args[1], &temp_size);
    float size = (float)temp_size;

    int radSeg;
    napi_get_value_int32(env, args[2], (int32_t*)&radSeg);

    int sides;
    napi_get_value_int32(env, args[3], (int32_t*)&sides);

    Mesh result = GenMeshTorus(radius, size, radSeg, sides);
    return Mesh_to_js(env, result);
}

napi_value BindNode_GenMeshKnot(napi_env env, napi_callback_info info) {
    size_t argc = 4;
    napi_value args[4];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 4) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    double temp_radius;
    napi_get_value_double(env, args[0], &temp_radius);
    float radius = (float)temp_radius;

    double temp_size;
    napi_get_value_double(env, args[1], &temp_size);
    float size = (float)temp_size;

    int radSeg;
    napi_get_value_int32(env, args[2], (int32_t*)&radSeg);

    int sides;
    napi_get_value_int32(env, args[3], (int32_t*)&sides);

    Mesh result = GenMeshKnot(radius, size, radSeg, sides);
    return Mesh_to_js(env, result);
}

napi_value BindNode_GenMeshHeightmap(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Image heightmap = Image_from_js(env, args[0]);

    Vector3 size = Vector3_from_js(env, args[1]);

    Mesh result = GenMeshHeightmap(heightmap, size);
    return Mesh_to_js(env, result);
}

napi_value BindNode_GenMeshCubicmap(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Image cubicmap = Image_from_js(env, args[0]);

    Vector3 cubeSize = Vector3_from_js(env, args[1]);

    Mesh result = GenMeshCubicmap(cubicmap, cubeSize);
    return Mesh_to_js(env, result);
}

napi_value BindNode_LoadMaterials(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    size_t fileName_len;
    napi_get_value_string_utf8(env, args[0], NULL, 0, &fileName_len);
    char* fileName = (char*)malloc(fileName_len + 1);
    napi_get_value_string_utf8(env, args[0], fileName, fileName_len + 1, &fileName_len);

    int materialCount_value = int_from_js(env, args[1]);
    int * materialCount = &materialCount_value;

    Material * result = LoadMaterials(fileName, materialCount);
    free(fileName);
    // TODO: Handle return type Material *
    napi_value jsResult;
    napi_get_null(env, &jsResult);
    return jsResult; // Placeholder
}

napi_value BindNode_LoadMaterialDefault(napi_env env, napi_callback_info info) {
    Material result = LoadMaterialDefault();
    return Material_to_js(env, result);
}

napi_value BindNode_IsMaterialValid(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Material material = Material_from_js(env, args[0]);

    bool result = IsMaterialValid(material);
    napi_value jsResult;
    napi_get_boolean(env, result, &jsResult);
    return jsResult;
}

napi_value BindNode_UnloadMaterial(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Material material = Material_from_js(env, args[0]);

    UnloadMaterial(material);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_SetMaterialTexture(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value args[3];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 3) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Material material_value = Material_from_js(env, args[0]);
    Material * material = &material_value;

    int mapType;
    napi_get_value_int32(env, args[1], (int32_t*)&mapType);

    Texture2D texture = Texture2D_from_js(env, args[2]);

    SetMaterialTexture(material, mapType, texture);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_SetModelMeshMaterial(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value args[3];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 3) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Model model_value = Model_from_js(env, args[0]);
    Model * model = &model_value;

    int meshId;
    napi_get_value_int32(env, args[1], (int32_t*)&meshId);

    int materialId;
    napi_get_value_int32(env, args[2], (int32_t*)&materialId);

    SetModelMeshMaterial(model, meshId, materialId);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_LoadModelAnimations(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    size_t fileName_len;
    napi_get_value_string_utf8(env, args[0], NULL, 0, &fileName_len);
    char* fileName = (char*)malloc(fileName_len + 1);
    napi_get_value_string_utf8(env, args[0], fileName, fileName_len + 1, &fileName_len);

    int animCount_value = int_from_js(env, args[1]);
    int * animCount = &animCount_value;

    ModelAnimation * result = LoadModelAnimations(fileName, animCount);
    free(fileName);
    // TODO: Handle return type ModelAnimation *
    napi_value jsResult;
    napi_get_null(env, &jsResult);
    return jsResult; // Placeholder
}

napi_value BindNode_UpdateModelAnimation(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value args[3];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 3) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Model model = Model_from_js(env, args[0]);

    ModelAnimation anim = ModelAnimation_from_js(env, args[1]);

    int frame;
    napi_get_value_int32(env, args[2], (int32_t*)&frame);

    UpdateModelAnimation(model, anim, frame);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_UpdateModelAnimationBones(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value args[3];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 3) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Model model = Model_from_js(env, args[0]);

    ModelAnimation anim = ModelAnimation_from_js(env, args[1]);

    int frame;
    napi_get_value_int32(env, args[2], (int32_t*)&frame);

    UpdateModelAnimationBones(model, anim, frame);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_UnloadModelAnimation(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    ModelAnimation anim = ModelAnimation_from_js(env, args[0]);

    UnloadModelAnimation(anim);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_UnloadModelAnimations(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    ModelAnimation animations_value = ModelAnimation_from_js(env, args[0]);
    ModelAnimation * animations = &animations_value;

    int animCount;
    napi_get_value_int32(env, args[1], (int32_t*)&animCount);

    UnloadModelAnimations(animations, animCount);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_IsModelAnimationValid(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Model model = Model_from_js(env, args[0]);

    ModelAnimation anim = ModelAnimation_from_js(env, args[1]);

    bool result = IsModelAnimationValid(model, anim);
    napi_value jsResult;
    napi_get_boolean(env, result, &jsResult);
    return jsResult;
}

napi_value BindNode_CheckCollisionSpheres(napi_env env, napi_callback_info info) {
    size_t argc = 4;
    napi_value args[4];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 4) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Vector3 center1 = Vector3_from_js(env, args[0]);

    double temp_radius1;
    napi_get_value_double(env, args[1], &temp_radius1);
    float radius1 = (float)temp_radius1;

    Vector3 center2 = Vector3_from_js(env, args[2]);

    double temp_radius2;
    napi_get_value_double(env, args[3], &temp_radius2);
    float radius2 = (float)temp_radius2;

    bool result = CheckCollisionSpheres(center1, radius1, center2, radius2);
    napi_value jsResult;
    napi_get_boolean(env, result, &jsResult);
    return jsResult;
}

napi_value BindNode_CheckCollisionBoxes(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    BoundingBox box1 = BoundingBox_from_js(env, args[0]);

    BoundingBox box2 = BoundingBox_from_js(env, args[1]);

    bool result = CheckCollisionBoxes(box1, box2);
    napi_value jsResult;
    napi_get_boolean(env, result, &jsResult);
    return jsResult;
}

napi_value BindNode_CheckCollisionBoxSphere(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value args[3];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 3) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    BoundingBox box = BoundingBox_from_js(env, args[0]);

    Vector3 center = Vector3_from_js(env, args[1]);

    double temp_radius;
    napi_get_value_double(env, args[2], &temp_radius);
    float radius = (float)temp_radius;

    bool result = CheckCollisionBoxSphere(box, center, radius);
    napi_value jsResult;
    napi_get_boolean(env, result, &jsResult);
    return jsResult;
}

napi_value BindNode_GetRayCollisionSphere(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value args[3];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 3) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Ray ray = Ray_from_js(env, args[0]);

    Vector3 center = Vector3_from_js(env, args[1]);

    double temp_radius;
    napi_get_value_double(env, args[2], &temp_radius);
    float radius = (float)temp_radius;

    RayCollision result = GetRayCollisionSphere(ray, center, radius);
    return RayCollision_to_js(env, result);
}

napi_value BindNode_GetRayCollisionBox(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Ray ray = Ray_from_js(env, args[0]);

    BoundingBox box = BoundingBox_from_js(env, args[1]);

    RayCollision result = GetRayCollisionBox(ray, box);
    return RayCollision_to_js(env, result);
}

napi_value BindNode_GetRayCollisionMesh(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value args[3];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 3) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Ray ray = Ray_from_js(env, args[0]);

    Mesh mesh = Mesh_from_js(env, args[1]);

    Matrix transform = Matrix_from_js(env, args[2]);

    RayCollision result = GetRayCollisionMesh(ray, mesh, transform);
    return RayCollision_to_js(env, result);
}

napi_value BindNode_GetRayCollisionTriangle(napi_env env, napi_callback_info info) {
    size_t argc = 4;
    napi_value args[4];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 4) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Ray ray = Ray_from_js(env, args[0]);

    Vector3 p1 = Vector3_from_js(env, args[1]);

    Vector3 p2 = Vector3_from_js(env, args[2]);

    Vector3 p3 = Vector3_from_js(env, args[3]);

    RayCollision result = GetRayCollisionTriangle(ray, p1, p2, p3);
    return RayCollision_to_js(env, result);
}

napi_value BindNode_GetRayCollisionQuad(napi_env env, napi_callback_info info) {
    size_t argc = 5;
    napi_value args[5];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 5) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Ray ray = Ray_from_js(env, args[0]);

    Vector3 p1 = Vector3_from_js(env, args[1]);

    Vector3 p2 = Vector3_from_js(env, args[2]);

    Vector3 p3 = Vector3_from_js(env, args[3]);

    Vector3 p4 = Vector3_from_js(env, args[4]);

    RayCollision result = GetRayCollisionQuad(ray, p1, p2, p3, p4);
    return RayCollision_to_js(env, result);
}

napi_value BindNode_InitAudioDevice(napi_env env, napi_callback_info info) {
    InitAudioDevice();
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_CloseAudioDevice(napi_env env, napi_callback_info info) {
    CloseAudioDevice();
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_IsAudioDeviceReady(napi_env env, napi_callback_info info) {
    bool result = IsAudioDeviceReady();
    napi_value jsResult;
    napi_get_boolean(env, result, &jsResult);
    return jsResult;
}

napi_value BindNode_SetMasterVolume(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    double temp_volume;
    napi_get_value_double(env, args[0], &temp_volume);
    float volume = (float)temp_volume;

    SetMasterVolume(volume);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_GetMasterVolume(napi_env env, napi_callback_info info) {
    float result = GetMasterVolume();
    return float_to_js(env, result);
}

napi_value BindNode_LoadWave(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    size_t fileName_len;
    napi_get_value_string_utf8(env, args[0], NULL, 0, &fileName_len);
    char* fileName = (char*)malloc(fileName_len + 1);
    napi_get_value_string_utf8(env, args[0], fileName, fileName_len + 1, &fileName_len);

    Wave result = LoadWave(fileName);
    free(fileName);
    return Wave_to_js(env, result);
}

napi_value BindNode_LoadWaveFromMemory(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value args[3];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 3) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    size_t fileType_len;
    napi_get_value_string_utf8(env, args[0], NULL, 0, &fileType_len);
    char* fileType = (char*)malloc(fileType_len + 1);
    napi_get_value_string_utf8(env, args[0], fileType, fileType_len + 1, &fileType_len);

    // Warning: No conversion available for const unsigned char
    const unsigned char * fileData = NULL;

    int dataSize;
    napi_get_value_int32(env, args[2], (int32_t*)&dataSize);

    Wave result = LoadWaveFromMemory(fileType, fileData, dataSize);
    free(fileType);
    return Wave_to_js(env, result);
}

napi_value BindNode_IsWaveValid(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Wave wave = Wave_from_js(env, args[0]);

    bool result = IsWaveValid(wave);
    napi_value jsResult;
    napi_get_boolean(env, result, &jsResult);
    return jsResult;
}

napi_value BindNode_LoadSound(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    size_t fileName_len;
    napi_get_value_string_utf8(env, args[0], NULL, 0, &fileName_len);
    char* fileName = (char*)malloc(fileName_len + 1);
    napi_get_value_string_utf8(env, args[0], fileName, fileName_len + 1, &fileName_len);

    Sound result = LoadSound(fileName);
    free(fileName);
    return Sound_to_js(env, result);
}

napi_value BindNode_LoadSoundFromWave(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Wave wave = Wave_from_js(env, args[0]);

    Sound result = LoadSoundFromWave(wave);
    return Sound_to_js(env, result);
}

napi_value BindNode_LoadSoundAlias(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Sound source = Sound_from_js(env, args[0]);

    Sound result = LoadSoundAlias(source);
    return Sound_to_js(env, result);
}

napi_value BindNode_IsSoundValid(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Sound sound = Sound_from_js(env, args[0]);

    bool result = IsSoundValid(sound);
    napi_value jsResult;
    napi_get_boolean(env, result, &jsResult);
    return jsResult;
}

napi_value BindNode_UpdateSound(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value args[3];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 3) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Sound sound = Sound_from_js(env, args[0]);

    // Warning: No conversion available for const void
    const void * data = NULL;

    int sampleCount;
    napi_get_value_int32(env, args[2], (int32_t*)&sampleCount);

    UpdateSound(sound, data, sampleCount);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_UnloadWave(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Wave wave = Wave_from_js(env, args[0]);

    UnloadWave(wave);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_UnloadSound(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Sound sound = Sound_from_js(env, args[0]);

    UnloadSound(sound);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_UnloadSoundAlias(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Sound alias = Sound_from_js(env, args[0]);

    UnloadSoundAlias(alias);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_ExportWave(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Wave wave = Wave_from_js(env, args[0]);

    size_t fileName_len;
    napi_get_value_string_utf8(env, args[1], NULL, 0, &fileName_len);
    char* fileName = (char*)malloc(fileName_len + 1);
    napi_get_value_string_utf8(env, args[1], fileName, fileName_len + 1, &fileName_len);

    bool result = ExportWave(wave, fileName);
    free(fileName);
    napi_value jsResult;
    napi_get_boolean(env, result, &jsResult);
    return jsResult;
}

napi_value BindNode_ExportWaveAsCode(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Wave wave = Wave_from_js(env, args[0]);

    size_t fileName_len;
    napi_get_value_string_utf8(env, args[1], NULL, 0, &fileName_len);
    char* fileName = (char*)malloc(fileName_len + 1);
    napi_get_value_string_utf8(env, args[1], fileName, fileName_len + 1, &fileName_len);

    bool result = ExportWaveAsCode(wave, fileName);
    free(fileName);
    napi_value jsResult;
    napi_get_boolean(env, result, &jsResult);
    return jsResult;
}

napi_value BindNode_PlaySound(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Sound sound = Sound_from_js(env, args[0]);

    PlaySound(sound);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_StopSound(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Sound sound = Sound_from_js(env, args[0]);

    StopSound(sound);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_PauseSound(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Sound sound = Sound_from_js(env, args[0]);

    PauseSound(sound);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_ResumeSound(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Sound sound = Sound_from_js(env, args[0]);

    ResumeSound(sound);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_IsSoundPlaying(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Sound sound = Sound_from_js(env, args[0]);

    bool result = IsSoundPlaying(sound);
    napi_value jsResult;
    napi_get_boolean(env, result, &jsResult);
    return jsResult;
}

napi_value BindNode_SetSoundVolume(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Sound sound = Sound_from_js(env, args[0]);

    double temp_volume;
    napi_get_value_double(env, args[1], &temp_volume);
    float volume = (float)temp_volume;

    SetSoundVolume(sound, volume);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_SetSoundPitch(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Sound sound = Sound_from_js(env, args[0]);

    double temp_pitch;
    napi_get_value_double(env, args[1], &temp_pitch);
    float pitch = (float)temp_pitch;

    SetSoundPitch(sound, pitch);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_SetSoundPan(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Sound sound = Sound_from_js(env, args[0]);

    double temp_pan;
    napi_get_value_double(env, args[1], &temp_pan);
    float pan = (float)temp_pan;

    SetSoundPan(sound, pan);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_WaveCopy(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Wave wave = Wave_from_js(env, args[0]);

    Wave result = WaveCopy(wave);
    return Wave_to_js(env, result);
}

napi_value BindNode_WaveCrop(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value args[3];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 3) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Wave wave_value = Wave_from_js(env, args[0]);
    Wave * wave = &wave_value;

    int initFrame;
    napi_get_value_int32(env, args[1], (int32_t*)&initFrame);

    int finalFrame;
    napi_get_value_int32(env, args[2], (int32_t*)&finalFrame);

    WaveCrop(wave, initFrame, finalFrame);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_WaveFormat(napi_env env, napi_callback_info info) {
    size_t argc = 4;
    napi_value args[4];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 4) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Wave wave_value = Wave_from_js(env, args[0]);
    Wave * wave = &wave_value;

    int sampleRate;
    napi_get_value_int32(env, args[1], (int32_t*)&sampleRate);

    int sampleSize;
    napi_get_value_int32(env, args[2], (int32_t*)&sampleSize);

    int channels;
    napi_get_value_int32(env, args[3], (int32_t*)&channels);

    WaveFormat(wave, sampleRate, sampleSize, channels);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_LoadWaveSamples(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Wave wave = Wave_from_js(env, args[0]);

    float * result = LoadWaveSamples(wave);
    // TODO: Handle return type float *
    napi_value jsResult;
    napi_get_null(env, &jsResult);
    return jsResult; // Placeholder
}

napi_value BindNode_UnloadWaveSamples(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    float samples_value = float_from_js(env, args[0]);
    float * samples = &samples_value;

    UnloadWaveSamples(samples);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_LoadMusicStream(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    size_t fileName_len;
    napi_get_value_string_utf8(env, args[0], NULL, 0, &fileName_len);
    char* fileName = (char*)malloc(fileName_len + 1);
    napi_get_value_string_utf8(env, args[0], fileName, fileName_len + 1, &fileName_len);

    Music result = LoadMusicStream(fileName);
    free(fileName);
    return Music_to_js(env, result);
}

napi_value BindNode_LoadMusicStreamFromMemory(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value args[3];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 3) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    size_t fileType_len;
    napi_get_value_string_utf8(env, args[0], NULL, 0, &fileType_len);
    char* fileType = (char*)malloc(fileType_len + 1);
    napi_get_value_string_utf8(env, args[0], fileType, fileType_len + 1, &fileType_len);

    // Warning: No conversion available for const unsigned char
    const unsigned char * data = NULL;

    int dataSize;
    napi_get_value_int32(env, args[2], (int32_t*)&dataSize);

    Music result = LoadMusicStreamFromMemory(fileType, data, dataSize);
    free(fileType);
    return Music_to_js(env, result);
}

napi_value BindNode_IsMusicValid(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Music music = Music_from_js(env, args[0]);

    bool result = IsMusicValid(music);
    napi_value jsResult;
    napi_get_boolean(env, result, &jsResult);
    return jsResult;
}

napi_value BindNode_UnloadMusicStream(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Music music = Music_from_js(env, args[0]);

    UnloadMusicStream(music);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_PlayMusicStream(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Music music = Music_from_js(env, args[0]);

    PlayMusicStream(music);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_IsMusicStreamPlaying(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Music music = Music_from_js(env, args[0]);

    bool result = IsMusicStreamPlaying(music);
    napi_value jsResult;
    napi_get_boolean(env, result, &jsResult);
    return jsResult;
}

napi_value BindNode_UpdateMusicStream(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Music music = Music_from_js(env, args[0]);

    UpdateMusicStream(music);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_StopMusicStream(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Music music = Music_from_js(env, args[0]);

    StopMusicStream(music);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_PauseMusicStream(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Music music = Music_from_js(env, args[0]);

    PauseMusicStream(music);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_ResumeMusicStream(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Music music = Music_from_js(env, args[0]);

    ResumeMusicStream(music);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_SeekMusicStream(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Music music = Music_from_js(env, args[0]);

    double temp_position;
    napi_get_value_double(env, args[1], &temp_position);
    float position = (float)temp_position;

    SeekMusicStream(music, position);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_SetMusicVolume(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Music music = Music_from_js(env, args[0]);

    double temp_volume;
    napi_get_value_double(env, args[1], &temp_volume);
    float volume = (float)temp_volume;

    SetMusicVolume(music, volume);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_SetMusicPitch(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Music music = Music_from_js(env, args[0]);

    double temp_pitch;
    napi_get_value_double(env, args[1], &temp_pitch);
    float pitch = (float)temp_pitch;

    SetMusicPitch(music, pitch);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_SetMusicPan(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Music music = Music_from_js(env, args[0]);

    double temp_pan;
    napi_get_value_double(env, args[1], &temp_pan);
    float pan = (float)temp_pan;

    SetMusicPan(music, pan);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_GetMusicTimeLength(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Music music = Music_from_js(env, args[0]);

    float result = GetMusicTimeLength(music);
    return float_to_js(env, result);
}

napi_value BindNode_GetMusicTimePlayed(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    Music music = Music_from_js(env, args[0]);

    float result = GetMusicTimePlayed(music);
    return float_to_js(env, result);
}

napi_value BindNode_LoadAudioStream(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value args[3];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 3) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    unsigned int sampleRate;
    napi_get_value_int32(env, args[0], (int32_t*)&sampleRate);

    unsigned int sampleSize;
    napi_get_value_int32(env, args[1], (int32_t*)&sampleSize);

    unsigned int channels;
    napi_get_value_int32(env, args[2], (int32_t*)&channels);

    AudioStream result = LoadAudioStream(sampleRate, sampleSize, channels);
    return AudioStream_to_js(env, result);
}

napi_value BindNode_IsAudioStreamValid(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    AudioStream stream = AudioStream_from_js(env, args[0]);

    bool result = IsAudioStreamValid(stream);
    napi_value jsResult;
    napi_get_boolean(env, result, &jsResult);
    return jsResult;
}

napi_value BindNode_UnloadAudioStream(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    AudioStream stream = AudioStream_from_js(env, args[0]);

    UnloadAudioStream(stream);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_UpdateAudioStream(napi_env env, napi_callback_info info) {
    size_t argc = 3;
    napi_value args[3];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 3) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    AudioStream stream = AudioStream_from_js(env, args[0]);

    // Warning: No conversion available for const void
    const void * data = NULL;

    int frameCount;
    napi_get_value_int32(env, args[2], (int32_t*)&frameCount);

    UpdateAudioStream(stream, data, frameCount);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_IsAudioStreamProcessed(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    AudioStream stream = AudioStream_from_js(env, args[0]);

    bool result = IsAudioStreamProcessed(stream);
    napi_value jsResult;
    napi_get_boolean(env, result, &jsResult);
    return jsResult;
}

napi_value BindNode_PlayAudioStream(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    AudioStream stream = AudioStream_from_js(env, args[0]);

    PlayAudioStream(stream);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_PauseAudioStream(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    AudioStream stream = AudioStream_from_js(env, args[0]);

    PauseAudioStream(stream);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_ResumeAudioStream(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    AudioStream stream = AudioStream_from_js(env, args[0]);

    ResumeAudioStream(stream);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_IsAudioStreamPlaying(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    AudioStream stream = AudioStream_from_js(env, args[0]);

    bool result = IsAudioStreamPlaying(stream);
    napi_value jsResult;
    napi_get_boolean(env, result, &jsResult);
    return jsResult;
}

napi_value BindNode_StopAudioStream(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    AudioStream stream = AudioStream_from_js(env, args[0]);

    StopAudioStream(stream);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_SetAudioStreamVolume(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    AudioStream stream = AudioStream_from_js(env, args[0]);

    double temp_volume;
    napi_get_value_double(env, args[1], &temp_volume);
    float volume = (float)temp_volume;

    SetAudioStreamVolume(stream, volume);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_SetAudioStreamPitch(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    AudioStream stream = AudioStream_from_js(env, args[0]);

    double temp_pitch;
    napi_get_value_double(env, args[1], &temp_pitch);
    float pitch = (float)temp_pitch;

    SetAudioStreamPitch(stream, pitch);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_SetAudioStreamPan(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    AudioStream stream = AudioStream_from_js(env, args[0]);

    double temp_pan;
    napi_get_value_double(env, args[1], &temp_pan);
    float pan = (float)temp_pan;

    SetAudioStreamPan(stream, pan);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_SetAudioStreamBufferSizeDefault(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    int size;
    napi_get_value_int32(env, args[0], (int32_t*)&size);

    SetAudioStreamBufferSizeDefault(size);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_SetAudioStreamCallback(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    AudioStream stream = AudioStream_from_js(env, args[0]);

    AudioCallback callback = AudioCallback_from_js(env, args[1]);

    SetAudioStreamCallback(stream, callback);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_AttachAudioStreamProcessor(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    AudioStream stream = AudioStream_from_js(env, args[0]);

    AudioCallback processor = AudioCallback_from_js(env, args[1]);

    AttachAudioStreamProcessor(stream, processor);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DetachAudioStreamProcessor(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 2) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    AudioStream stream = AudioStream_from_js(env, args[0]);

    AudioCallback processor = AudioCallback_from_js(env, args[1]);

    DetachAudioStreamProcessor(stream, processor);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_AttachAudioMixedProcessor(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    AudioCallback processor = AudioCallback_from_js(env, args[0]);

    AttachAudioMixedProcessor(processor);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}

napi_value BindNode_DetachAudioMixedProcessor(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Wrong number of arguments");
        napi_value undefined;
        napi_get_undefined(env, &undefined);
        return undefined;
    }

    AudioCallback processor = AudioCallback_from_js(env, args[0]);

    DetachAudioMixedProcessor(processor);
    napi_value jsResult;
    napi_get_undefined(env, &jsResult);
    return jsResult;
}


// Initialize module
napi_value Init(napi_env env, napi_value exports) {
    napi_value enumValue;
    // Register ConfigFlags enum
    enumValue = Create_ConfigFlags(env);
    napi_set_named_property(env, exports, "ConfigFlags", enumValue);

    // Register TraceLogLevel enum
    enumValue = Create_TraceLogLevel(env);
    napi_set_named_property(env, exports, "TraceLogLevel", enumValue);

    // Register KeyboardKey enum
    enumValue = Create_KeyboardKey(env);
    napi_set_named_property(env, exports, "KeyboardKey", enumValue);

    // Register MouseButton enum
    enumValue = Create_MouseButton(env);
    napi_set_named_property(env, exports, "MouseButton", enumValue);

    // Register MouseCursor enum
    enumValue = Create_MouseCursor(env);
    napi_set_named_property(env, exports, "MouseCursor", enumValue);

    // Register GamepadButton enum
    enumValue = Create_GamepadButton(env);
    napi_set_named_property(env, exports, "GamepadButton", enumValue);

    // Register GamepadAxis enum
    enumValue = Create_GamepadAxis(env);
    napi_set_named_property(env, exports, "GamepadAxis", enumValue);

    // Register MaterialMapIndex enum
    enumValue = Create_MaterialMapIndex(env);
    napi_set_named_property(env, exports, "MaterialMapIndex", enumValue);

    // Register ShaderLocationIndex enum
    enumValue = Create_ShaderLocationIndex(env);
    napi_set_named_property(env, exports, "ShaderLocationIndex", enumValue);

    // Register ShaderUniformDataType enum
    enumValue = Create_ShaderUniformDataType(env);
    napi_set_named_property(env, exports, "ShaderUniformDataType", enumValue);

    // Register ShaderAttributeDataType enum
    enumValue = Create_ShaderAttributeDataType(env);
    napi_set_named_property(env, exports, "ShaderAttributeDataType", enumValue);

    // Register PixelFormat enum
    enumValue = Create_PixelFormat(env);
    napi_set_named_property(env, exports, "PixelFormat", enumValue);

    // Register TextureFilter enum
    enumValue = Create_TextureFilter(env);
    napi_set_named_property(env, exports, "TextureFilter", enumValue);

    // Register TextureWrap enum
    enumValue = Create_TextureWrap(env);
    napi_set_named_property(env, exports, "TextureWrap", enumValue);

    // Register CubemapLayout enum
    enumValue = Create_CubemapLayout(env);
    napi_set_named_property(env, exports, "CubemapLayout", enumValue);

    // Register FontType enum
    enumValue = Create_FontType(env);
    napi_set_named_property(env, exports, "FontType", enumValue);

    // Register BlendMode enum
    enumValue = Create_BlendMode(env);
    napi_set_named_property(env, exports, "BlendMode", enumValue);

    // Register Gesture enum
    enumValue = Create_Gesture(env);
    napi_set_named_property(env, exports, "Gesture", enumValue);

    // Register CameraMode enum
    enumValue = Create_CameraMode(env);
    napi_set_named_property(env, exports, "CameraMode", enumValue);

    // Register CameraProjection enum
    enumValue = Create_CameraProjection(env);
    napi_set_named_property(env, exports, "CameraProjection", enumValue);

    // Register NPatchLayout enum
    enumValue = Create_NPatchLayout(env);
    napi_set_named_property(env, exports, "NPatchLayout", enumValue);

    napi_value InitWindow_fn;
    napi_create_function(env, NULL, 0, BindNode_InitWindow, NULL, &InitWindow_fn);
    napi_set_named_property(env, exports, "InitWindow", InitWindow_fn);

    napi_value CloseWindow_fn;
    napi_create_function(env, NULL, 0, BindNode_CloseWindow, NULL, &CloseWindow_fn);
    napi_set_named_property(env, exports, "CloseWindow", CloseWindow_fn);

    napi_value WindowShouldClose_fn;
    napi_create_function(env, NULL, 0, BindNode_WindowShouldClose, NULL, &WindowShouldClose_fn);
    napi_set_named_property(env, exports, "WindowShouldClose", WindowShouldClose_fn);

    napi_value IsWindowReady_fn;
    napi_create_function(env, NULL, 0, BindNode_IsWindowReady, NULL, &IsWindowReady_fn);
    napi_set_named_property(env, exports, "IsWindowReady", IsWindowReady_fn);

    napi_value IsWindowFullscreen_fn;
    napi_create_function(env, NULL, 0, BindNode_IsWindowFullscreen, NULL, &IsWindowFullscreen_fn);
    napi_set_named_property(env, exports, "IsWindowFullscreen", IsWindowFullscreen_fn);

    napi_value IsWindowHidden_fn;
    napi_create_function(env, NULL, 0, BindNode_IsWindowHidden, NULL, &IsWindowHidden_fn);
    napi_set_named_property(env, exports, "IsWindowHidden", IsWindowHidden_fn);

    napi_value IsWindowMinimized_fn;
    napi_create_function(env, NULL, 0, BindNode_IsWindowMinimized, NULL, &IsWindowMinimized_fn);
    napi_set_named_property(env, exports, "IsWindowMinimized", IsWindowMinimized_fn);

    napi_value IsWindowMaximized_fn;
    napi_create_function(env, NULL, 0, BindNode_IsWindowMaximized, NULL, &IsWindowMaximized_fn);
    napi_set_named_property(env, exports, "IsWindowMaximized", IsWindowMaximized_fn);

    napi_value IsWindowFocused_fn;
    napi_create_function(env, NULL, 0, BindNode_IsWindowFocused, NULL, &IsWindowFocused_fn);
    napi_set_named_property(env, exports, "IsWindowFocused", IsWindowFocused_fn);

    napi_value IsWindowResized_fn;
    napi_create_function(env, NULL, 0, BindNode_IsWindowResized, NULL, &IsWindowResized_fn);
    napi_set_named_property(env, exports, "IsWindowResized", IsWindowResized_fn);

    napi_value IsWindowState_fn;
    napi_create_function(env, NULL, 0, BindNode_IsWindowState, NULL, &IsWindowState_fn);
    napi_set_named_property(env, exports, "IsWindowState", IsWindowState_fn);

    napi_value SetWindowState_fn;
    napi_create_function(env, NULL, 0, BindNode_SetWindowState, NULL, &SetWindowState_fn);
    napi_set_named_property(env, exports, "SetWindowState", SetWindowState_fn);

    napi_value ClearWindowState_fn;
    napi_create_function(env, NULL, 0, BindNode_ClearWindowState, NULL, &ClearWindowState_fn);
    napi_set_named_property(env, exports, "ClearWindowState", ClearWindowState_fn);

    napi_value ToggleFullscreen_fn;
    napi_create_function(env, NULL, 0, BindNode_ToggleFullscreen, NULL, &ToggleFullscreen_fn);
    napi_set_named_property(env, exports, "ToggleFullscreen", ToggleFullscreen_fn);

    napi_value ToggleBorderlessWindowed_fn;
    napi_create_function(env, NULL, 0, BindNode_ToggleBorderlessWindowed, NULL, &ToggleBorderlessWindowed_fn);
    napi_set_named_property(env, exports, "ToggleBorderlessWindowed", ToggleBorderlessWindowed_fn);

    napi_value MaximizeWindow_fn;
    napi_create_function(env, NULL, 0, BindNode_MaximizeWindow, NULL, &MaximizeWindow_fn);
    napi_set_named_property(env, exports, "MaximizeWindow", MaximizeWindow_fn);

    napi_value MinimizeWindow_fn;
    napi_create_function(env, NULL, 0, BindNode_MinimizeWindow, NULL, &MinimizeWindow_fn);
    napi_set_named_property(env, exports, "MinimizeWindow", MinimizeWindow_fn);

    napi_value RestoreWindow_fn;
    napi_create_function(env, NULL, 0, BindNode_RestoreWindow, NULL, &RestoreWindow_fn);
    napi_set_named_property(env, exports, "RestoreWindow", RestoreWindow_fn);

    napi_value SetWindowIcon_fn;
    napi_create_function(env, NULL, 0, BindNode_SetWindowIcon, NULL, &SetWindowIcon_fn);
    napi_set_named_property(env, exports, "SetWindowIcon", SetWindowIcon_fn);

    napi_value SetWindowIcons_fn;
    napi_create_function(env, NULL, 0, BindNode_SetWindowIcons, NULL, &SetWindowIcons_fn);
    napi_set_named_property(env, exports, "SetWindowIcons", SetWindowIcons_fn);

    napi_value SetWindowTitle_fn;
    napi_create_function(env, NULL, 0, BindNode_SetWindowTitle, NULL, &SetWindowTitle_fn);
    napi_set_named_property(env, exports, "SetWindowTitle", SetWindowTitle_fn);

    napi_value SetWindowPosition_fn;
    napi_create_function(env, NULL, 0, BindNode_SetWindowPosition, NULL, &SetWindowPosition_fn);
    napi_set_named_property(env, exports, "SetWindowPosition", SetWindowPosition_fn);

    napi_value SetWindowMonitor_fn;
    napi_create_function(env, NULL, 0, BindNode_SetWindowMonitor, NULL, &SetWindowMonitor_fn);
    napi_set_named_property(env, exports, "SetWindowMonitor", SetWindowMonitor_fn);

    napi_value SetWindowMinSize_fn;
    napi_create_function(env, NULL, 0, BindNode_SetWindowMinSize, NULL, &SetWindowMinSize_fn);
    napi_set_named_property(env, exports, "SetWindowMinSize", SetWindowMinSize_fn);

    napi_value SetWindowMaxSize_fn;
    napi_create_function(env, NULL, 0, BindNode_SetWindowMaxSize, NULL, &SetWindowMaxSize_fn);
    napi_set_named_property(env, exports, "SetWindowMaxSize", SetWindowMaxSize_fn);

    napi_value SetWindowSize_fn;
    napi_create_function(env, NULL, 0, BindNode_SetWindowSize, NULL, &SetWindowSize_fn);
    napi_set_named_property(env, exports, "SetWindowSize", SetWindowSize_fn);

    napi_value SetWindowOpacity_fn;
    napi_create_function(env, NULL, 0, BindNode_SetWindowOpacity, NULL, &SetWindowOpacity_fn);
    napi_set_named_property(env, exports, "SetWindowOpacity", SetWindowOpacity_fn);

    napi_value SetWindowFocused_fn;
    napi_create_function(env, NULL, 0, BindNode_SetWindowFocused, NULL, &SetWindowFocused_fn);
    napi_set_named_property(env, exports, "SetWindowFocused", SetWindowFocused_fn);

    napi_value GetWindowHandle_fn;
    napi_create_function(env, NULL, 0, BindNode_GetWindowHandle, NULL, &GetWindowHandle_fn);
    napi_set_named_property(env, exports, "GetWindowHandle", GetWindowHandle_fn);

    napi_value GetScreenWidth_fn;
    napi_create_function(env, NULL, 0, BindNode_GetScreenWidth, NULL, &GetScreenWidth_fn);
    napi_set_named_property(env, exports, "GetScreenWidth", GetScreenWidth_fn);

    napi_value GetScreenHeight_fn;
    napi_create_function(env, NULL, 0, BindNode_GetScreenHeight, NULL, &GetScreenHeight_fn);
    napi_set_named_property(env, exports, "GetScreenHeight", GetScreenHeight_fn);

    napi_value GetRenderWidth_fn;
    napi_create_function(env, NULL, 0, BindNode_GetRenderWidth, NULL, &GetRenderWidth_fn);
    napi_set_named_property(env, exports, "GetRenderWidth", GetRenderWidth_fn);

    napi_value GetRenderHeight_fn;
    napi_create_function(env, NULL, 0, BindNode_GetRenderHeight, NULL, &GetRenderHeight_fn);
    napi_set_named_property(env, exports, "GetRenderHeight", GetRenderHeight_fn);

    napi_value GetMonitorCount_fn;
    napi_create_function(env, NULL, 0, BindNode_GetMonitorCount, NULL, &GetMonitorCount_fn);
    napi_set_named_property(env, exports, "GetMonitorCount", GetMonitorCount_fn);

    napi_value GetCurrentMonitor_fn;
    napi_create_function(env, NULL, 0, BindNode_GetCurrentMonitor, NULL, &GetCurrentMonitor_fn);
    napi_set_named_property(env, exports, "GetCurrentMonitor", GetCurrentMonitor_fn);

    napi_value GetMonitorPosition_fn;
    napi_create_function(env, NULL, 0, BindNode_GetMonitorPosition, NULL, &GetMonitorPosition_fn);
    napi_set_named_property(env, exports, "GetMonitorPosition", GetMonitorPosition_fn);

    napi_value GetMonitorWidth_fn;
    napi_create_function(env, NULL, 0, BindNode_GetMonitorWidth, NULL, &GetMonitorWidth_fn);
    napi_set_named_property(env, exports, "GetMonitorWidth", GetMonitorWidth_fn);

    napi_value GetMonitorHeight_fn;
    napi_create_function(env, NULL, 0, BindNode_GetMonitorHeight, NULL, &GetMonitorHeight_fn);
    napi_set_named_property(env, exports, "GetMonitorHeight", GetMonitorHeight_fn);

    napi_value GetMonitorPhysicalWidth_fn;
    napi_create_function(env, NULL, 0, BindNode_GetMonitorPhysicalWidth, NULL, &GetMonitorPhysicalWidth_fn);
    napi_set_named_property(env, exports, "GetMonitorPhysicalWidth", GetMonitorPhysicalWidth_fn);

    napi_value GetMonitorPhysicalHeight_fn;
    napi_create_function(env, NULL, 0, BindNode_GetMonitorPhysicalHeight, NULL, &GetMonitorPhysicalHeight_fn);
    napi_set_named_property(env, exports, "GetMonitorPhysicalHeight", GetMonitorPhysicalHeight_fn);

    napi_value GetMonitorRefreshRate_fn;
    napi_create_function(env, NULL, 0, BindNode_GetMonitorRefreshRate, NULL, &GetMonitorRefreshRate_fn);
    napi_set_named_property(env, exports, "GetMonitorRefreshRate", GetMonitorRefreshRate_fn);

    napi_value GetWindowPosition_fn;
    napi_create_function(env, NULL, 0, BindNode_GetWindowPosition, NULL, &GetWindowPosition_fn);
    napi_set_named_property(env, exports, "GetWindowPosition", GetWindowPosition_fn);

    napi_value GetWindowScaleDPI_fn;
    napi_create_function(env, NULL, 0, BindNode_GetWindowScaleDPI, NULL, &GetWindowScaleDPI_fn);
    napi_set_named_property(env, exports, "GetWindowScaleDPI", GetWindowScaleDPI_fn);

    napi_value GetMonitorName_fn;
    napi_create_function(env, NULL, 0, BindNode_GetMonitorName, NULL, &GetMonitorName_fn);
    napi_set_named_property(env, exports, "GetMonitorName", GetMonitorName_fn);

    napi_value SetClipboardText_fn;
    napi_create_function(env, NULL, 0, BindNode_SetClipboardText, NULL, &SetClipboardText_fn);
    napi_set_named_property(env, exports, "SetClipboardText", SetClipboardText_fn);

    napi_value GetClipboardText_fn;
    napi_create_function(env, NULL, 0, BindNode_GetClipboardText, NULL, &GetClipboardText_fn);
    napi_set_named_property(env, exports, "GetClipboardText", GetClipboardText_fn);

    napi_value GetClipboardImage_fn;
    napi_create_function(env, NULL, 0, BindNode_GetClipboardImage, NULL, &GetClipboardImage_fn);
    napi_set_named_property(env, exports, "GetClipboardImage", GetClipboardImage_fn);

    napi_value EnableEventWaiting_fn;
    napi_create_function(env, NULL, 0, BindNode_EnableEventWaiting, NULL, &EnableEventWaiting_fn);
    napi_set_named_property(env, exports, "EnableEventWaiting", EnableEventWaiting_fn);

    napi_value DisableEventWaiting_fn;
    napi_create_function(env, NULL, 0, BindNode_DisableEventWaiting, NULL, &DisableEventWaiting_fn);
    napi_set_named_property(env, exports, "DisableEventWaiting", DisableEventWaiting_fn);

    napi_value ShowCursor_fn;
    napi_create_function(env, NULL, 0, BindNode_ShowCursor, NULL, &ShowCursor_fn);
    napi_set_named_property(env, exports, "ShowCursor", ShowCursor_fn);

    napi_value HideCursor_fn;
    napi_create_function(env, NULL, 0, BindNode_HideCursor, NULL, &HideCursor_fn);
    napi_set_named_property(env, exports, "HideCursor", HideCursor_fn);

    napi_value IsCursorHidden_fn;
    napi_create_function(env, NULL, 0, BindNode_IsCursorHidden, NULL, &IsCursorHidden_fn);
    napi_set_named_property(env, exports, "IsCursorHidden", IsCursorHidden_fn);

    napi_value EnableCursor_fn;
    napi_create_function(env, NULL, 0, BindNode_EnableCursor, NULL, &EnableCursor_fn);
    napi_set_named_property(env, exports, "EnableCursor", EnableCursor_fn);

    napi_value DisableCursor_fn;
    napi_create_function(env, NULL, 0, BindNode_DisableCursor, NULL, &DisableCursor_fn);
    napi_set_named_property(env, exports, "DisableCursor", DisableCursor_fn);

    napi_value IsCursorOnScreen_fn;
    napi_create_function(env, NULL, 0, BindNode_IsCursorOnScreen, NULL, &IsCursorOnScreen_fn);
    napi_set_named_property(env, exports, "IsCursorOnScreen", IsCursorOnScreen_fn);

    napi_value ClearBackground_fn;
    napi_create_function(env, NULL, 0, BindNode_ClearBackground, NULL, &ClearBackground_fn);
    napi_set_named_property(env, exports, "ClearBackground", ClearBackground_fn);

    napi_value BeginDrawing_fn;
    napi_create_function(env, NULL, 0, BindNode_BeginDrawing, NULL, &BeginDrawing_fn);
    napi_set_named_property(env, exports, "BeginDrawing", BeginDrawing_fn);

    napi_value EndDrawing_fn;
    napi_create_function(env, NULL, 0, BindNode_EndDrawing, NULL, &EndDrawing_fn);
    napi_set_named_property(env, exports, "EndDrawing", EndDrawing_fn);

    napi_value BeginMode2D_fn;
    napi_create_function(env, NULL, 0, BindNode_BeginMode2D, NULL, &BeginMode2D_fn);
    napi_set_named_property(env, exports, "BeginMode2D", BeginMode2D_fn);

    napi_value EndMode2D_fn;
    napi_create_function(env, NULL, 0, BindNode_EndMode2D, NULL, &EndMode2D_fn);
    napi_set_named_property(env, exports, "EndMode2D", EndMode2D_fn);

    napi_value BeginMode3D_fn;
    napi_create_function(env, NULL, 0, BindNode_BeginMode3D, NULL, &BeginMode3D_fn);
    napi_set_named_property(env, exports, "BeginMode3D", BeginMode3D_fn);

    napi_value EndMode3D_fn;
    napi_create_function(env, NULL, 0, BindNode_EndMode3D, NULL, &EndMode3D_fn);
    napi_set_named_property(env, exports, "EndMode3D", EndMode3D_fn);

    napi_value BeginTextureMode_fn;
    napi_create_function(env, NULL, 0, BindNode_BeginTextureMode, NULL, &BeginTextureMode_fn);
    napi_set_named_property(env, exports, "BeginTextureMode", BeginTextureMode_fn);

    napi_value EndTextureMode_fn;
    napi_create_function(env, NULL, 0, BindNode_EndTextureMode, NULL, &EndTextureMode_fn);
    napi_set_named_property(env, exports, "EndTextureMode", EndTextureMode_fn);

    napi_value BeginShaderMode_fn;
    napi_create_function(env, NULL, 0, BindNode_BeginShaderMode, NULL, &BeginShaderMode_fn);
    napi_set_named_property(env, exports, "BeginShaderMode", BeginShaderMode_fn);

    napi_value EndShaderMode_fn;
    napi_create_function(env, NULL, 0, BindNode_EndShaderMode, NULL, &EndShaderMode_fn);
    napi_set_named_property(env, exports, "EndShaderMode", EndShaderMode_fn);

    napi_value BeginBlendMode_fn;
    napi_create_function(env, NULL, 0, BindNode_BeginBlendMode, NULL, &BeginBlendMode_fn);
    napi_set_named_property(env, exports, "BeginBlendMode", BeginBlendMode_fn);

    napi_value EndBlendMode_fn;
    napi_create_function(env, NULL, 0, BindNode_EndBlendMode, NULL, &EndBlendMode_fn);
    napi_set_named_property(env, exports, "EndBlendMode", EndBlendMode_fn);

    napi_value BeginScissorMode_fn;
    napi_create_function(env, NULL, 0, BindNode_BeginScissorMode, NULL, &BeginScissorMode_fn);
    napi_set_named_property(env, exports, "BeginScissorMode", BeginScissorMode_fn);

    napi_value EndScissorMode_fn;
    napi_create_function(env, NULL, 0, BindNode_EndScissorMode, NULL, &EndScissorMode_fn);
    napi_set_named_property(env, exports, "EndScissorMode", EndScissorMode_fn);

    napi_value BeginVrStereoMode_fn;
    napi_create_function(env, NULL, 0, BindNode_BeginVrStereoMode, NULL, &BeginVrStereoMode_fn);
    napi_set_named_property(env, exports, "BeginVrStereoMode", BeginVrStereoMode_fn);

    napi_value EndVrStereoMode_fn;
    napi_create_function(env, NULL, 0, BindNode_EndVrStereoMode, NULL, &EndVrStereoMode_fn);
    napi_set_named_property(env, exports, "EndVrStereoMode", EndVrStereoMode_fn);

    napi_value LoadVrStereoConfig_fn;
    napi_create_function(env, NULL, 0, BindNode_LoadVrStereoConfig, NULL, &LoadVrStereoConfig_fn);
    napi_set_named_property(env, exports, "LoadVrStereoConfig", LoadVrStereoConfig_fn);

    napi_value UnloadVrStereoConfig_fn;
    napi_create_function(env, NULL, 0, BindNode_UnloadVrStereoConfig, NULL, &UnloadVrStereoConfig_fn);
    napi_set_named_property(env, exports, "UnloadVrStereoConfig", UnloadVrStereoConfig_fn);

    napi_value LoadShader_fn;
    napi_create_function(env, NULL, 0, BindNode_LoadShader, NULL, &LoadShader_fn);
    napi_set_named_property(env, exports, "LoadShader", LoadShader_fn);

    napi_value LoadShaderFromMemory_fn;
    napi_create_function(env, NULL, 0, BindNode_LoadShaderFromMemory, NULL, &LoadShaderFromMemory_fn);
    napi_set_named_property(env, exports, "LoadShaderFromMemory", LoadShaderFromMemory_fn);

    napi_value IsShaderValid_fn;
    napi_create_function(env, NULL, 0, BindNode_IsShaderValid, NULL, &IsShaderValid_fn);
    napi_set_named_property(env, exports, "IsShaderValid", IsShaderValid_fn);

    napi_value GetShaderLocation_fn;
    napi_create_function(env, NULL, 0, BindNode_GetShaderLocation, NULL, &GetShaderLocation_fn);
    napi_set_named_property(env, exports, "GetShaderLocation", GetShaderLocation_fn);

    napi_value GetShaderLocationAttrib_fn;
    napi_create_function(env, NULL, 0, BindNode_GetShaderLocationAttrib, NULL, &GetShaderLocationAttrib_fn);
    napi_set_named_property(env, exports, "GetShaderLocationAttrib", GetShaderLocationAttrib_fn);

    napi_value SetShaderValue_fn;
    napi_create_function(env, NULL, 0, BindNode_SetShaderValue, NULL, &SetShaderValue_fn);
    napi_set_named_property(env, exports, "SetShaderValue", SetShaderValue_fn);

    napi_value SetShaderValueV_fn;
    napi_create_function(env, NULL, 0, BindNode_SetShaderValueV, NULL, &SetShaderValueV_fn);
    napi_set_named_property(env, exports, "SetShaderValueV", SetShaderValueV_fn);

    napi_value SetShaderValueMatrix_fn;
    napi_create_function(env, NULL, 0, BindNode_SetShaderValueMatrix, NULL, &SetShaderValueMatrix_fn);
    napi_set_named_property(env, exports, "SetShaderValueMatrix", SetShaderValueMatrix_fn);

    napi_value SetShaderValueTexture_fn;
    napi_create_function(env, NULL, 0, BindNode_SetShaderValueTexture, NULL, &SetShaderValueTexture_fn);
    napi_set_named_property(env, exports, "SetShaderValueTexture", SetShaderValueTexture_fn);

    napi_value UnloadShader_fn;
    napi_create_function(env, NULL, 0, BindNode_UnloadShader, NULL, &UnloadShader_fn);
    napi_set_named_property(env, exports, "UnloadShader", UnloadShader_fn);

    napi_value GetScreenToWorldRay_fn;
    napi_create_function(env, NULL, 0, BindNode_GetScreenToWorldRay, NULL, &GetScreenToWorldRay_fn);
    napi_set_named_property(env, exports, "GetScreenToWorldRay", GetScreenToWorldRay_fn);

    napi_value GetScreenToWorldRayEx_fn;
    napi_create_function(env, NULL, 0, BindNode_GetScreenToWorldRayEx, NULL, &GetScreenToWorldRayEx_fn);
    napi_set_named_property(env, exports, "GetScreenToWorldRayEx", GetScreenToWorldRayEx_fn);

    napi_value GetWorldToScreen_fn;
    napi_create_function(env, NULL, 0, BindNode_GetWorldToScreen, NULL, &GetWorldToScreen_fn);
    napi_set_named_property(env, exports, "GetWorldToScreen", GetWorldToScreen_fn);

    napi_value GetWorldToScreenEx_fn;
    napi_create_function(env, NULL, 0, BindNode_GetWorldToScreenEx, NULL, &GetWorldToScreenEx_fn);
    napi_set_named_property(env, exports, "GetWorldToScreenEx", GetWorldToScreenEx_fn);

    napi_value GetWorldToScreen2D_fn;
    napi_create_function(env, NULL, 0, BindNode_GetWorldToScreen2D, NULL, &GetWorldToScreen2D_fn);
    napi_set_named_property(env, exports, "GetWorldToScreen2D", GetWorldToScreen2D_fn);

    napi_value GetScreenToWorld2D_fn;
    napi_create_function(env, NULL, 0, BindNode_GetScreenToWorld2D, NULL, &GetScreenToWorld2D_fn);
    napi_set_named_property(env, exports, "GetScreenToWorld2D", GetScreenToWorld2D_fn);

    napi_value GetCameraMatrix_fn;
    napi_create_function(env, NULL, 0, BindNode_GetCameraMatrix, NULL, &GetCameraMatrix_fn);
    napi_set_named_property(env, exports, "GetCameraMatrix", GetCameraMatrix_fn);

    napi_value GetCameraMatrix2D_fn;
    napi_create_function(env, NULL, 0, BindNode_GetCameraMatrix2D, NULL, &GetCameraMatrix2D_fn);
    napi_set_named_property(env, exports, "GetCameraMatrix2D", GetCameraMatrix2D_fn);

    napi_value SetTargetFPS_fn;
    napi_create_function(env, NULL, 0, BindNode_SetTargetFPS, NULL, &SetTargetFPS_fn);
    napi_set_named_property(env, exports, "SetTargetFPS", SetTargetFPS_fn);

    napi_value GetFrameTime_fn;
    napi_create_function(env, NULL, 0, BindNode_GetFrameTime, NULL, &GetFrameTime_fn);
    napi_set_named_property(env, exports, "GetFrameTime", GetFrameTime_fn);

    napi_value GetTime_fn;
    napi_create_function(env, NULL, 0, BindNode_GetTime, NULL, &GetTime_fn);
    napi_set_named_property(env, exports, "GetTime", GetTime_fn);

    napi_value GetFPS_fn;
    napi_create_function(env, NULL, 0, BindNode_GetFPS, NULL, &GetFPS_fn);
    napi_set_named_property(env, exports, "GetFPS", GetFPS_fn);

    napi_value SwapScreenBuffer_fn;
    napi_create_function(env, NULL, 0, BindNode_SwapScreenBuffer, NULL, &SwapScreenBuffer_fn);
    napi_set_named_property(env, exports, "SwapScreenBuffer", SwapScreenBuffer_fn);

    napi_value PollInputEvents_fn;
    napi_create_function(env, NULL, 0, BindNode_PollInputEvents, NULL, &PollInputEvents_fn);
    napi_set_named_property(env, exports, "PollInputEvents", PollInputEvents_fn);

    napi_value WaitTime_fn;
    napi_create_function(env, NULL, 0, BindNode_WaitTime, NULL, &WaitTime_fn);
    napi_set_named_property(env, exports, "WaitTime", WaitTime_fn);

    napi_value SetRandomSeed_fn;
    napi_create_function(env, NULL, 0, BindNode_SetRandomSeed, NULL, &SetRandomSeed_fn);
    napi_set_named_property(env, exports, "SetRandomSeed", SetRandomSeed_fn);

    napi_value GetRandomValue_fn;
    napi_create_function(env, NULL, 0, BindNode_GetRandomValue, NULL, &GetRandomValue_fn);
    napi_set_named_property(env, exports, "GetRandomValue", GetRandomValue_fn);

    napi_value LoadRandomSequence_fn;
    napi_create_function(env, NULL, 0, BindNode_LoadRandomSequence, NULL, &LoadRandomSequence_fn);
    napi_set_named_property(env, exports, "LoadRandomSequence", LoadRandomSequence_fn);

    napi_value UnloadRandomSequence_fn;
    napi_create_function(env, NULL, 0, BindNode_UnloadRandomSequence, NULL, &UnloadRandomSequence_fn);
    napi_set_named_property(env, exports, "UnloadRandomSequence", UnloadRandomSequence_fn);

    napi_value TakeScreenshot_fn;
    napi_create_function(env, NULL, 0, BindNode_TakeScreenshot, NULL, &TakeScreenshot_fn);
    napi_set_named_property(env, exports, "TakeScreenshot", TakeScreenshot_fn);

    napi_value SetConfigFlags_fn;
    napi_create_function(env, NULL, 0, BindNode_SetConfigFlags, NULL, &SetConfigFlags_fn);
    napi_set_named_property(env, exports, "SetConfigFlags", SetConfigFlags_fn);

    napi_value OpenURL_fn;
    napi_create_function(env, NULL, 0, BindNode_OpenURL, NULL, &OpenURL_fn);
    napi_set_named_property(env, exports, "OpenURL", OpenURL_fn);

    napi_value TraceLog_fn;
    napi_create_function(env, NULL, 0, BindNode_TraceLog, NULL, &TraceLog_fn);
    napi_set_named_property(env, exports, "TraceLog", TraceLog_fn);

    napi_value SetTraceLogLevel_fn;
    napi_create_function(env, NULL, 0, BindNode_SetTraceLogLevel, NULL, &SetTraceLogLevel_fn);
    napi_set_named_property(env, exports, "SetTraceLogLevel", SetTraceLogLevel_fn);

    napi_value MemAlloc_fn;
    napi_create_function(env, NULL, 0, BindNode_MemAlloc, NULL, &MemAlloc_fn);
    napi_set_named_property(env, exports, "MemAlloc", MemAlloc_fn);

    napi_value MemRealloc_fn;
    napi_create_function(env, NULL, 0, BindNode_MemRealloc, NULL, &MemRealloc_fn);
    napi_set_named_property(env, exports, "MemRealloc", MemRealloc_fn);

    napi_value MemFree_fn;
    napi_create_function(env, NULL, 0, BindNode_MemFree, NULL, &MemFree_fn);
    napi_set_named_property(env, exports, "MemFree", MemFree_fn);

    napi_value SetTraceLogCallback_fn;
    napi_create_function(env, NULL, 0, BindNode_SetTraceLogCallback, NULL, &SetTraceLogCallback_fn);
    napi_set_named_property(env, exports, "SetTraceLogCallback", SetTraceLogCallback_fn);

    napi_value SetLoadFileDataCallback_fn;
    napi_create_function(env, NULL, 0, BindNode_SetLoadFileDataCallback, NULL, &SetLoadFileDataCallback_fn);
    napi_set_named_property(env, exports, "SetLoadFileDataCallback", SetLoadFileDataCallback_fn);

    napi_value SetSaveFileDataCallback_fn;
    napi_create_function(env, NULL, 0, BindNode_SetSaveFileDataCallback, NULL, &SetSaveFileDataCallback_fn);
    napi_set_named_property(env, exports, "SetSaveFileDataCallback", SetSaveFileDataCallback_fn);

    napi_value SetLoadFileTextCallback_fn;
    napi_create_function(env, NULL, 0, BindNode_SetLoadFileTextCallback, NULL, &SetLoadFileTextCallback_fn);
    napi_set_named_property(env, exports, "SetLoadFileTextCallback", SetLoadFileTextCallback_fn);

    napi_value SetSaveFileTextCallback_fn;
    napi_create_function(env, NULL, 0, BindNode_SetSaveFileTextCallback, NULL, &SetSaveFileTextCallback_fn);
    napi_set_named_property(env, exports, "SetSaveFileTextCallback", SetSaveFileTextCallback_fn);

    napi_value LoadFileData_fn;
    napi_create_function(env, NULL, 0, BindNode_LoadFileData, NULL, &LoadFileData_fn);
    napi_set_named_property(env, exports, "LoadFileData", LoadFileData_fn);

    napi_value UnloadFileData_fn;
    napi_create_function(env, NULL, 0, BindNode_UnloadFileData, NULL, &UnloadFileData_fn);
    napi_set_named_property(env, exports, "UnloadFileData", UnloadFileData_fn);

    napi_value SaveFileData_fn;
    napi_create_function(env, NULL, 0, BindNode_SaveFileData, NULL, &SaveFileData_fn);
    napi_set_named_property(env, exports, "SaveFileData", SaveFileData_fn);

    napi_value ExportDataAsCode_fn;
    napi_create_function(env, NULL, 0, BindNode_ExportDataAsCode, NULL, &ExportDataAsCode_fn);
    napi_set_named_property(env, exports, "ExportDataAsCode", ExportDataAsCode_fn);

    napi_value LoadFileText_fn;
    napi_create_function(env, NULL, 0, BindNode_LoadFileText, NULL, &LoadFileText_fn);
    napi_set_named_property(env, exports, "LoadFileText", LoadFileText_fn);

    napi_value UnloadFileText_fn;
    napi_create_function(env, NULL, 0, BindNode_UnloadFileText, NULL, &UnloadFileText_fn);
    napi_set_named_property(env, exports, "UnloadFileText", UnloadFileText_fn);

    napi_value SaveFileText_fn;
    napi_create_function(env, NULL, 0, BindNode_SaveFileText, NULL, &SaveFileText_fn);
    napi_set_named_property(env, exports, "SaveFileText", SaveFileText_fn);

    napi_value FileExists_fn;
    napi_create_function(env, NULL, 0, BindNode_FileExists, NULL, &FileExists_fn);
    napi_set_named_property(env, exports, "FileExists", FileExists_fn);

    napi_value DirectoryExists_fn;
    napi_create_function(env, NULL, 0, BindNode_DirectoryExists, NULL, &DirectoryExists_fn);
    napi_set_named_property(env, exports, "DirectoryExists", DirectoryExists_fn);

    napi_value IsFileExtension_fn;
    napi_create_function(env, NULL, 0, BindNode_IsFileExtension, NULL, &IsFileExtension_fn);
    napi_set_named_property(env, exports, "IsFileExtension", IsFileExtension_fn);

    napi_value GetFileLength_fn;
    napi_create_function(env, NULL, 0, BindNode_GetFileLength, NULL, &GetFileLength_fn);
    napi_set_named_property(env, exports, "GetFileLength", GetFileLength_fn);

    napi_value GetFileExtension_fn;
    napi_create_function(env, NULL, 0, BindNode_GetFileExtension, NULL, &GetFileExtension_fn);
    napi_set_named_property(env, exports, "GetFileExtension", GetFileExtension_fn);

    napi_value GetFileName_fn;
    napi_create_function(env, NULL, 0, BindNode_GetFileName, NULL, &GetFileName_fn);
    napi_set_named_property(env, exports, "GetFileName", GetFileName_fn);

    napi_value GetFileNameWithoutExt_fn;
    napi_create_function(env, NULL, 0, BindNode_GetFileNameWithoutExt, NULL, &GetFileNameWithoutExt_fn);
    napi_set_named_property(env, exports, "GetFileNameWithoutExt", GetFileNameWithoutExt_fn);

    napi_value GetDirectoryPath_fn;
    napi_create_function(env, NULL, 0, BindNode_GetDirectoryPath, NULL, &GetDirectoryPath_fn);
    napi_set_named_property(env, exports, "GetDirectoryPath", GetDirectoryPath_fn);

    napi_value GetPrevDirectoryPath_fn;
    napi_create_function(env, NULL, 0, BindNode_GetPrevDirectoryPath, NULL, &GetPrevDirectoryPath_fn);
    napi_set_named_property(env, exports, "GetPrevDirectoryPath", GetPrevDirectoryPath_fn);

    napi_value GetWorkingDirectory_fn;
    napi_create_function(env, NULL, 0, BindNode_GetWorkingDirectory, NULL, &GetWorkingDirectory_fn);
    napi_set_named_property(env, exports, "GetWorkingDirectory", GetWorkingDirectory_fn);

    napi_value GetApplicationDirectory_fn;
    napi_create_function(env, NULL, 0, BindNode_GetApplicationDirectory, NULL, &GetApplicationDirectory_fn);
    napi_set_named_property(env, exports, "GetApplicationDirectory", GetApplicationDirectory_fn);

    napi_value MakeDirectory_fn;
    napi_create_function(env, NULL, 0, BindNode_MakeDirectory, NULL, &MakeDirectory_fn);
    napi_set_named_property(env, exports, "MakeDirectory", MakeDirectory_fn);

    napi_value ChangeDirectory_fn;
    napi_create_function(env, NULL, 0, BindNode_ChangeDirectory, NULL, &ChangeDirectory_fn);
    napi_set_named_property(env, exports, "ChangeDirectory", ChangeDirectory_fn);

    napi_value IsPathFile_fn;
    napi_create_function(env, NULL, 0, BindNode_IsPathFile, NULL, &IsPathFile_fn);
    napi_set_named_property(env, exports, "IsPathFile", IsPathFile_fn);

    napi_value IsFileNameValid_fn;
    napi_create_function(env, NULL, 0, BindNode_IsFileNameValid, NULL, &IsFileNameValid_fn);
    napi_set_named_property(env, exports, "IsFileNameValid", IsFileNameValid_fn);

    napi_value LoadDirectoryFiles_fn;
    napi_create_function(env, NULL, 0, BindNode_LoadDirectoryFiles, NULL, &LoadDirectoryFiles_fn);
    napi_set_named_property(env, exports, "LoadDirectoryFiles", LoadDirectoryFiles_fn);

    napi_value LoadDirectoryFilesEx_fn;
    napi_create_function(env, NULL, 0, BindNode_LoadDirectoryFilesEx, NULL, &LoadDirectoryFilesEx_fn);
    napi_set_named_property(env, exports, "LoadDirectoryFilesEx", LoadDirectoryFilesEx_fn);

    napi_value UnloadDirectoryFiles_fn;
    napi_create_function(env, NULL, 0, BindNode_UnloadDirectoryFiles, NULL, &UnloadDirectoryFiles_fn);
    napi_set_named_property(env, exports, "UnloadDirectoryFiles", UnloadDirectoryFiles_fn);

    napi_value IsFileDropped_fn;
    napi_create_function(env, NULL, 0, BindNode_IsFileDropped, NULL, &IsFileDropped_fn);
    napi_set_named_property(env, exports, "IsFileDropped", IsFileDropped_fn);

    napi_value LoadDroppedFiles_fn;
    napi_create_function(env, NULL, 0, BindNode_LoadDroppedFiles, NULL, &LoadDroppedFiles_fn);
    napi_set_named_property(env, exports, "LoadDroppedFiles", LoadDroppedFiles_fn);

    napi_value UnloadDroppedFiles_fn;
    napi_create_function(env, NULL, 0, BindNode_UnloadDroppedFiles, NULL, &UnloadDroppedFiles_fn);
    napi_set_named_property(env, exports, "UnloadDroppedFiles", UnloadDroppedFiles_fn);

    napi_value GetFileModTime_fn;
    napi_create_function(env, NULL, 0, BindNode_GetFileModTime, NULL, &GetFileModTime_fn);
    napi_set_named_property(env, exports, "GetFileModTime", GetFileModTime_fn);

    napi_value CompressData_fn;
    napi_create_function(env, NULL, 0, BindNode_CompressData, NULL, &CompressData_fn);
    napi_set_named_property(env, exports, "CompressData", CompressData_fn);

    napi_value DecompressData_fn;
    napi_create_function(env, NULL, 0, BindNode_DecompressData, NULL, &DecompressData_fn);
    napi_set_named_property(env, exports, "DecompressData", DecompressData_fn);

    napi_value EncodeDataBase64_fn;
    napi_create_function(env, NULL, 0, BindNode_EncodeDataBase64, NULL, &EncodeDataBase64_fn);
    napi_set_named_property(env, exports, "EncodeDataBase64", EncodeDataBase64_fn);

    napi_value DecodeDataBase64_fn;
    napi_create_function(env, NULL, 0, BindNode_DecodeDataBase64, NULL, &DecodeDataBase64_fn);
    napi_set_named_property(env, exports, "DecodeDataBase64", DecodeDataBase64_fn);

    napi_value ComputeCRC32_fn;
    napi_create_function(env, NULL, 0, BindNode_ComputeCRC32, NULL, &ComputeCRC32_fn);
    napi_set_named_property(env, exports, "ComputeCRC32", ComputeCRC32_fn);

    napi_value ComputeMD5_fn;
    napi_create_function(env, NULL, 0, BindNode_ComputeMD5, NULL, &ComputeMD5_fn);
    napi_set_named_property(env, exports, "ComputeMD5", ComputeMD5_fn);

    napi_value ComputeSHA1_fn;
    napi_create_function(env, NULL, 0, BindNode_ComputeSHA1, NULL, &ComputeSHA1_fn);
    napi_set_named_property(env, exports, "ComputeSHA1", ComputeSHA1_fn);

    napi_value LoadAutomationEventList_fn;
    napi_create_function(env, NULL, 0, BindNode_LoadAutomationEventList, NULL, &LoadAutomationEventList_fn);
    napi_set_named_property(env, exports, "LoadAutomationEventList", LoadAutomationEventList_fn);

    napi_value UnloadAutomationEventList_fn;
    napi_create_function(env, NULL, 0, BindNode_UnloadAutomationEventList, NULL, &UnloadAutomationEventList_fn);
    napi_set_named_property(env, exports, "UnloadAutomationEventList", UnloadAutomationEventList_fn);

    napi_value ExportAutomationEventList_fn;
    napi_create_function(env, NULL, 0, BindNode_ExportAutomationEventList, NULL, &ExportAutomationEventList_fn);
    napi_set_named_property(env, exports, "ExportAutomationEventList", ExportAutomationEventList_fn);

    napi_value SetAutomationEventList_fn;
    napi_create_function(env, NULL, 0, BindNode_SetAutomationEventList, NULL, &SetAutomationEventList_fn);
    napi_set_named_property(env, exports, "SetAutomationEventList", SetAutomationEventList_fn);

    napi_value SetAutomationEventBaseFrame_fn;
    napi_create_function(env, NULL, 0, BindNode_SetAutomationEventBaseFrame, NULL, &SetAutomationEventBaseFrame_fn);
    napi_set_named_property(env, exports, "SetAutomationEventBaseFrame", SetAutomationEventBaseFrame_fn);

    napi_value StartAutomationEventRecording_fn;
    napi_create_function(env, NULL, 0, BindNode_StartAutomationEventRecording, NULL, &StartAutomationEventRecording_fn);
    napi_set_named_property(env, exports, "StartAutomationEventRecording", StartAutomationEventRecording_fn);

    napi_value StopAutomationEventRecording_fn;
    napi_create_function(env, NULL, 0, BindNode_StopAutomationEventRecording, NULL, &StopAutomationEventRecording_fn);
    napi_set_named_property(env, exports, "StopAutomationEventRecording", StopAutomationEventRecording_fn);

    napi_value PlayAutomationEvent_fn;
    napi_create_function(env, NULL, 0, BindNode_PlayAutomationEvent, NULL, &PlayAutomationEvent_fn);
    napi_set_named_property(env, exports, "PlayAutomationEvent", PlayAutomationEvent_fn);

    napi_value IsKeyPressed_fn;
    napi_create_function(env, NULL, 0, BindNode_IsKeyPressed, NULL, &IsKeyPressed_fn);
    napi_set_named_property(env, exports, "IsKeyPressed", IsKeyPressed_fn);

    napi_value IsKeyPressedRepeat_fn;
    napi_create_function(env, NULL, 0, BindNode_IsKeyPressedRepeat, NULL, &IsKeyPressedRepeat_fn);
    napi_set_named_property(env, exports, "IsKeyPressedRepeat", IsKeyPressedRepeat_fn);

    napi_value IsKeyDown_fn;
    napi_create_function(env, NULL, 0, BindNode_IsKeyDown, NULL, &IsKeyDown_fn);
    napi_set_named_property(env, exports, "IsKeyDown", IsKeyDown_fn);

    napi_value IsKeyReleased_fn;
    napi_create_function(env, NULL, 0, BindNode_IsKeyReleased, NULL, &IsKeyReleased_fn);
    napi_set_named_property(env, exports, "IsKeyReleased", IsKeyReleased_fn);

    napi_value IsKeyUp_fn;
    napi_create_function(env, NULL, 0, BindNode_IsKeyUp, NULL, &IsKeyUp_fn);
    napi_set_named_property(env, exports, "IsKeyUp", IsKeyUp_fn);

    napi_value GetKeyPressed_fn;
    napi_create_function(env, NULL, 0, BindNode_GetKeyPressed, NULL, &GetKeyPressed_fn);
    napi_set_named_property(env, exports, "GetKeyPressed", GetKeyPressed_fn);

    napi_value GetCharPressed_fn;
    napi_create_function(env, NULL, 0, BindNode_GetCharPressed, NULL, &GetCharPressed_fn);
    napi_set_named_property(env, exports, "GetCharPressed", GetCharPressed_fn);

    napi_value SetExitKey_fn;
    napi_create_function(env, NULL, 0, BindNode_SetExitKey, NULL, &SetExitKey_fn);
    napi_set_named_property(env, exports, "SetExitKey", SetExitKey_fn);

    napi_value IsGamepadAvailable_fn;
    napi_create_function(env, NULL, 0, BindNode_IsGamepadAvailable, NULL, &IsGamepadAvailable_fn);
    napi_set_named_property(env, exports, "IsGamepadAvailable", IsGamepadAvailable_fn);

    napi_value GetGamepadName_fn;
    napi_create_function(env, NULL, 0, BindNode_GetGamepadName, NULL, &GetGamepadName_fn);
    napi_set_named_property(env, exports, "GetGamepadName", GetGamepadName_fn);

    napi_value IsGamepadButtonPressed_fn;
    napi_create_function(env, NULL, 0, BindNode_IsGamepadButtonPressed, NULL, &IsGamepadButtonPressed_fn);
    napi_set_named_property(env, exports, "IsGamepadButtonPressed", IsGamepadButtonPressed_fn);

    napi_value IsGamepadButtonDown_fn;
    napi_create_function(env, NULL, 0, BindNode_IsGamepadButtonDown, NULL, &IsGamepadButtonDown_fn);
    napi_set_named_property(env, exports, "IsGamepadButtonDown", IsGamepadButtonDown_fn);

    napi_value IsGamepadButtonReleased_fn;
    napi_create_function(env, NULL, 0, BindNode_IsGamepadButtonReleased, NULL, &IsGamepadButtonReleased_fn);
    napi_set_named_property(env, exports, "IsGamepadButtonReleased", IsGamepadButtonReleased_fn);

    napi_value IsGamepadButtonUp_fn;
    napi_create_function(env, NULL, 0, BindNode_IsGamepadButtonUp, NULL, &IsGamepadButtonUp_fn);
    napi_set_named_property(env, exports, "IsGamepadButtonUp", IsGamepadButtonUp_fn);

    napi_value GetGamepadButtonPressed_fn;
    napi_create_function(env, NULL, 0, BindNode_GetGamepadButtonPressed, NULL, &GetGamepadButtonPressed_fn);
    napi_set_named_property(env, exports, "GetGamepadButtonPressed", GetGamepadButtonPressed_fn);

    napi_value GetGamepadAxisCount_fn;
    napi_create_function(env, NULL, 0, BindNode_GetGamepadAxisCount, NULL, &GetGamepadAxisCount_fn);
    napi_set_named_property(env, exports, "GetGamepadAxisCount", GetGamepadAxisCount_fn);

    napi_value GetGamepadAxisMovement_fn;
    napi_create_function(env, NULL, 0, BindNode_GetGamepadAxisMovement, NULL, &GetGamepadAxisMovement_fn);
    napi_set_named_property(env, exports, "GetGamepadAxisMovement", GetGamepadAxisMovement_fn);

    napi_value SetGamepadMappings_fn;
    napi_create_function(env, NULL, 0, BindNode_SetGamepadMappings, NULL, &SetGamepadMappings_fn);
    napi_set_named_property(env, exports, "SetGamepadMappings", SetGamepadMappings_fn);

    napi_value SetGamepadVibration_fn;
    napi_create_function(env, NULL, 0, BindNode_SetGamepadVibration, NULL, &SetGamepadVibration_fn);
    napi_set_named_property(env, exports, "SetGamepadVibration", SetGamepadVibration_fn);

    napi_value IsMouseButtonPressed_fn;
    napi_create_function(env, NULL, 0, BindNode_IsMouseButtonPressed, NULL, &IsMouseButtonPressed_fn);
    napi_set_named_property(env, exports, "IsMouseButtonPressed", IsMouseButtonPressed_fn);

    napi_value IsMouseButtonDown_fn;
    napi_create_function(env, NULL, 0, BindNode_IsMouseButtonDown, NULL, &IsMouseButtonDown_fn);
    napi_set_named_property(env, exports, "IsMouseButtonDown", IsMouseButtonDown_fn);

    napi_value IsMouseButtonReleased_fn;
    napi_create_function(env, NULL, 0, BindNode_IsMouseButtonReleased, NULL, &IsMouseButtonReleased_fn);
    napi_set_named_property(env, exports, "IsMouseButtonReleased", IsMouseButtonReleased_fn);

    napi_value IsMouseButtonUp_fn;
    napi_create_function(env, NULL, 0, BindNode_IsMouseButtonUp, NULL, &IsMouseButtonUp_fn);
    napi_set_named_property(env, exports, "IsMouseButtonUp", IsMouseButtonUp_fn);

    napi_value GetMouseX_fn;
    napi_create_function(env, NULL, 0, BindNode_GetMouseX, NULL, &GetMouseX_fn);
    napi_set_named_property(env, exports, "GetMouseX", GetMouseX_fn);

    napi_value GetMouseY_fn;
    napi_create_function(env, NULL, 0, BindNode_GetMouseY, NULL, &GetMouseY_fn);
    napi_set_named_property(env, exports, "GetMouseY", GetMouseY_fn);

    napi_value GetMousePosition_fn;
    napi_create_function(env, NULL, 0, BindNode_GetMousePosition, NULL, &GetMousePosition_fn);
    napi_set_named_property(env, exports, "GetMousePosition", GetMousePosition_fn);

    napi_value GetMouseDelta_fn;
    napi_create_function(env, NULL, 0, BindNode_GetMouseDelta, NULL, &GetMouseDelta_fn);
    napi_set_named_property(env, exports, "GetMouseDelta", GetMouseDelta_fn);

    napi_value SetMousePosition_fn;
    napi_create_function(env, NULL, 0, BindNode_SetMousePosition, NULL, &SetMousePosition_fn);
    napi_set_named_property(env, exports, "SetMousePosition", SetMousePosition_fn);

    napi_value SetMouseOffset_fn;
    napi_create_function(env, NULL, 0, BindNode_SetMouseOffset, NULL, &SetMouseOffset_fn);
    napi_set_named_property(env, exports, "SetMouseOffset", SetMouseOffset_fn);

    napi_value SetMouseScale_fn;
    napi_create_function(env, NULL, 0, BindNode_SetMouseScale, NULL, &SetMouseScale_fn);
    napi_set_named_property(env, exports, "SetMouseScale", SetMouseScale_fn);

    napi_value GetMouseWheelMove_fn;
    napi_create_function(env, NULL, 0, BindNode_GetMouseWheelMove, NULL, &GetMouseWheelMove_fn);
    napi_set_named_property(env, exports, "GetMouseWheelMove", GetMouseWheelMove_fn);

    napi_value GetMouseWheelMoveV_fn;
    napi_create_function(env, NULL, 0, BindNode_GetMouseWheelMoveV, NULL, &GetMouseWheelMoveV_fn);
    napi_set_named_property(env, exports, "GetMouseWheelMoveV", GetMouseWheelMoveV_fn);

    napi_value SetMouseCursor_fn;
    napi_create_function(env, NULL, 0, BindNode_SetMouseCursor, NULL, &SetMouseCursor_fn);
    napi_set_named_property(env, exports, "SetMouseCursor", SetMouseCursor_fn);

    napi_value GetTouchX_fn;
    napi_create_function(env, NULL, 0, BindNode_GetTouchX, NULL, &GetTouchX_fn);
    napi_set_named_property(env, exports, "GetTouchX", GetTouchX_fn);

    napi_value GetTouchY_fn;
    napi_create_function(env, NULL, 0, BindNode_GetTouchY, NULL, &GetTouchY_fn);
    napi_set_named_property(env, exports, "GetTouchY", GetTouchY_fn);

    napi_value GetTouchPosition_fn;
    napi_create_function(env, NULL, 0, BindNode_GetTouchPosition, NULL, &GetTouchPosition_fn);
    napi_set_named_property(env, exports, "GetTouchPosition", GetTouchPosition_fn);

    napi_value GetTouchPointId_fn;
    napi_create_function(env, NULL, 0, BindNode_GetTouchPointId, NULL, &GetTouchPointId_fn);
    napi_set_named_property(env, exports, "GetTouchPointId", GetTouchPointId_fn);

    napi_value GetTouchPointCount_fn;
    napi_create_function(env, NULL, 0, BindNode_GetTouchPointCount, NULL, &GetTouchPointCount_fn);
    napi_set_named_property(env, exports, "GetTouchPointCount", GetTouchPointCount_fn);

    napi_value SetGesturesEnabled_fn;
    napi_create_function(env, NULL, 0, BindNode_SetGesturesEnabled, NULL, &SetGesturesEnabled_fn);
    napi_set_named_property(env, exports, "SetGesturesEnabled", SetGesturesEnabled_fn);

    napi_value IsGestureDetected_fn;
    napi_create_function(env, NULL, 0, BindNode_IsGestureDetected, NULL, &IsGestureDetected_fn);
    napi_set_named_property(env, exports, "IsGestureDetected", IsGestureDetected_fn);

    napi_value GetGestureDetected_fn;
    napi_create_function(env, NULL, 0, BindNode_GetGestureDetected, NULL, &GetGestureDetected_fn);
    napi_set_named_property(env, exports, "GetGestureDetected", GetGestureDetected_fn);

    napi_value GetGestureHoldDuration_fn;
    napi_create_function(env, NULL, 0, BindNode_GetGestureHoldDuration, NULL, &GetGestureHoldDuration_fn);
    napi_set_named_property(env, exports, "GetGestureHoldDuration", GetGestureHoldDuration_fn);

    napi_value GetGestureDragVector_fn;
    napi_create_function(env, NULL, 0, BindNode_GetGestureDragVector, NULL, &GetGestureDragVector_fn);
    napi_set_named_property(env, exports, "GetGestureDragVector", GetGestureDragVector_fn);

    napi_value GetGestureDragAngle_fn;
    napi_create_function(env, NULL, 0, BindNode_GetGestureDragAngle, NULL, &GetGestureDragAngle_fn);
    napi_set_named_property(env, exports, "GetGestureDragAngle", GetGestureDragAngle_fn);

    napi_value GetGesturePinchVector_fn;
    napi_create_function(env, NULL, 0, BindNode_GetGesturePinchVector, NULL, &GetGesturePinchVector_fn);
    napi_set_named_property(env, exports, "GetGesturePinchVector", GetGesturePinchVector_fn);

    napi_value GetGesturePinchAngle_fn;
    napi_create_function(env, NULL, 0, BindNode_GetGesturePinchAngle, NULL, &GetGesturePinchAngle_fn);
    napi_set_named_property(env, exports, "GetGesturePinchAngle", GetGesturePinchAngle_fn);

    napi_value UpdateCamera_fn;
    napi_create_function(env, NULL, 0, BindNode_UpdateCamera, NULL, &UpdateCamera_fn);
    napi_set_named_property(env, exports, "UpdateCamera", UpdateCamera_fn);

    napi_value UpdateCameraPro_fn;
    napi_create_function(env, NULL, 0, BindNode_UpdateCameraPro, NULL, &UpdateCameraPro_fn);
    napi_set_named_property(env, exports, "UpdateCameraPro", UpdateCameraPro_fn);

    napi_value SetShapesTexture_fn;
    napi_create_function(env, NULL, 0, BindNode_SetShapesTexture, NULL, &SetShapesTexture_fn);
    napi_set_named_property(env, exports, "SetShapesTexture", SetShapesTexture_fn);

    napi_value GetShapesTexture_fn;
    napi_create_function(env, NULL, 0, BindNode_GetShapesTexture, NULL, &GetShapesTexture_fn);
    napi_set_named_property(env, exports, "GetShapesTexture", GetShapesTexture_fn);

    napi_value GetShapesTextureRectangle_fn;
    napi_create_function(env, NULL, 0, BindNode_GetShapesTextureRectangle, NULL, &GetShapesTextureRectangle_fn);
    napi_set_named_property(env, exports, "GetShapesTextureRectangle", GetShapesTextureRectangle_fn);

    napi_value DrawPixel_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawPixel, NULL, &DrawPixel_fn);
    napi_set_named_property(env, exports, "DrawPixel", DrawPixel_fn);

    napi_value DrawPixelV_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawPixelV, NULL, &DrawPixelV_fn);
    napi_set_named_property(env, exports, "DrawPixelV", DrawPixelV_fn);

    napi_value DrawLine_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawLine, NULL, &DrawLine_fn);
    napi_set_named_property(env, exports, "DrawLine", DrawLine_fn);

    napi_value DrawLineV_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawLineV, NULL, &DrawLineV_fn);
    napi_set_named_property(env, exports, "DrawLineV", DrawLineV_fn);

    napi_value DrawLineEx_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawLineEx, NULL, &DrawLineEx_fn);
    napi_set_named_property(env, exports, "DrawLineEx", DrawLineEx_fn);

    napi_value DrawLineStrip_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawLineStrip, NULL, &DrawLineStrip_fn);
    napi_set_named_property(env, exports, "DrawLineStrip", DrawLineStrip_fn);

    napi_value DrawLineBezier_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawLineBezier, NULL, &DrawLineBezier_fn);
    napi_set_named_property(env, exports, "DrawLineBezier", DrawLineBezier_fn);

    napi_value DrawCircle_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawCircle, NULL, &DrawCircle_fn);
    napi_set_named_property(env, exports, "DrawCircle", DrawCircle_fn);

    napi_value DrawCircleSector_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawCircleSector, NULL, &DrawCircleSector_fn);
    napi_set_named_property(env, exports, "DrawCircleSector", DrawCircleSector_fn);

    napi_value DrawCircleSectorLines_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawCircleSectorLines, NULL, &DrawCircleSectorLines_fn);
    napi_set_named_property(env, exports, "DrawCircleSectorLines", DrawCircleSectorLines_fn);

    napi_value DrawCircleGradient_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawCircleGradient, NULL, &DrawCircleGradient_fn);
    napi_set_named_property(env, exports, "DrawCircleGradient", DrawCircleGradient_fn);

    napi_value DrawCircleV_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawCircleV, NULL, &DrawCircleV_fn);
    napi_set_named_property(env, exports, "DrawCircleV", DrawCircleV_fn);

    napi_value DrawCircleLines_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawCircleLines, NULL, &DrawCircleLines_fn);
    napi_set_named_property(env, exports, "DrawCircleLines", DrawCircleLines_fn);

    napi_value DrawCircleLinesV_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawCircleLinesV, NULL, &DrawCircleLinesV_fn);
    napi_set_named_property(env, exports, "DrawCircleLinesV", DrawCircleLinesV_fn);

    napi_value DrawEllipse_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawEllipse, NULL, &DrawEllipse_fn);
    napi_set_named_property(env, exports, "DrawEllipse", DrawEllipse_fn);

    napi_value DrawEllipseLines_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawEllipseLines, NULL, &DrawEllipseLines_fn);
    napi_set_named_property(env, exports, "DrawEllipseLines", DrawEllipseLines_fn);

    napi_value DrawRing_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawRing, NULL, &DrawRing_fn);
    napi_set_named_property(env, exports, "DrawRing", DrawRing_fn);

    napi_value DrawRingLines_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawRingLines, NULL, &DrawRingLines_fn);
    napi_set_named_property(env, exports, "DrawRingLines", DrawRingLines_fn);

    napi_value DrawRectangle_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawRectangle, NULL, &DrawRectangle_fn);
    napi_set_named_property(env, exports, "DrawRectangle", DrawRectangle_fn);

    napi_value DrawRectangleV_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawRectangleV, NULL, &DrawRectangleV_fn);
    napi_set_named_property(env, exports, "DrawRectangleV", DrawRectangleV_fn);

    napi_value DrawRectangleRec_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawRectangleRec, NULL, &DrawRectangleRec_fn);
    napi_set_named_property(env, exports, "DrawRectangleRec", DrawRectangleRec_fn);

    napi_value DrawRectanglePro_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawRectanglePro, NULL, &DrawRectanglePro_fn);
    napi_set_named_property(env, exports, "DrawRectanglePro", DrawRectanglePro_fn);

    napi_value DrawRectangleGradientV_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawRectangleGradientV, NULL, &DrawRectangleGradientV_fn);
    napi_set_named_property(env, exports, "DrawRectangleGradientV", DrawRectangleGradientV_fn);

    napi_value DrawRectangleGradientH_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawRectangleGradientH, NULL, &DrawRectangleGradientH_fn);
    napi_set_named_property(env, exports, "DrawRectangleGradientH", DrawRectangleGradientH_fn);

    napi_value DrawRectangleGradientEx_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawRectangleGradientEx, NULL, &DrawRectangleGradientEx_fn);
    napi_set_named_property(env, exports, "DrawRectangleGradientEx", DrawRectangleGradientEx_fn);

    napi_value DrawRectangleLines_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawRectangleLines, NULL, &DrawRectangleLines_fn);
    napi_set_named_property(env, exports, "DrawRectangleLines", DrawRectangleLines_fn);

    napi_value DrawRectangleLinesEx_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawRectangleLinesEx, NULL, &DrawRectangleLinesEx_fn);
    napi_set_named_property(env, exports, "DrawRectangleLinesEx", DrawRectangleLinesEx_fn);

    napi_value DrawRectangleRounded_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawRectangleRounded, NULL, &DrawRectangleRounded_fn);
    napi_set_named_property(env, exports, "DrawRectangleRounded", DrawRectangleRounded_fn);

    napi_value DrawRectangleRoundedLines_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawRectangleRoundedLines, NULL, &DrawRectangleRoundedLines_fn);
    napi_set_named_property(env, exports, "DrawRectangleRoundedLines", DrawRectangleRoundedLines_fn);

    napi_value DrawRectangleRoundedLinesEx_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawRectangleRoundedLinesEx, NULL, &DrawRectangleRoundedLinesEx_fn);
    napi_set_named_property(env, exports, "DrawRectangleRoundedLinesEx", DrawRectangleRoundedLinesEx_fn);

    napi_value DrawTriangle_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawTriangle, NULL, &DrawTriangle_fn);
    napi_set_named_property(env, exports, "DrawTriangle", DrawTriangle_fn);

    napi_value DrawTriangleLines_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawTriangleLines, NULL, &DrawTriangleLines_fn);
    napi_set_named_property(env, exports, "DrawTriangleLines", DrawTriangleLines_fn);

    napi_value DrawTriangleFan_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawTriangleFan, NULL, &DrawTriangleFan_fn);
    napi_set_named_property(env, exports, "DrawTriangleFan", DrawTriangleFan_fn);

    napi_value DrawTriangleStrip_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawTriangleStrip, NULL, &DrawTriangleStrip_fn);
    napi_set_named_property(env, exports, "DrawTriangleStrip", DrawTriangleStrip_fn);

    napi_value DrawPoly_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawPoly, NULL, &DrawPoly_fn);
    napi_set_named_property(env, exports, "DrawPoly", DrawPoly_fn);

    napi_value DrawPolyLines_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawPolyLines, NULL, &DrawPolyLines_fn);
    napi_set_named_property(env, exports, "DrawPolyLines", DrawPolyLines_fn);

    napi_value DrawPolyLinesEx_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawPolyLinesEx, NULL, &DrawPolyLinesEx_fn);
    napi_set_named_property(env, exports, "DrawPolyLinesEx", DrawPolyLinesEx_fn);

    napi_value DrawSplineLinear_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawSplineLinear, NULL, &DrawSplineLinear_fn);
    napi_set_named_property(env, exports, "DrawSplineLinear", DrawSplineLinear_fn);

    napi_value DrawSplineBasis_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawSplineBasis, NULL, &DrawSplineBasis_fn);
    napi_set_named_property(env, exports, "DrawSplineBasis", DrawSplineBasis_fn);

    napi_value DrawSplineCatmullRom_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawSplineCatmullRom, NULL, &DrawSplineCatmullRom_fn);
    napi_set_named_property(env, exports, "DrawSplineCatmullRom", DrawSplineCatmullRom_fn);

    napi_value DrawSplineBezierQuadratic_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawSplineBezierQuadratic, NULL, &DrawSplineBezierQuadratic_fn);
    napi_set_named_property(env, exports, "DrawSplineBezierQuadratic", DrawSplineBezierQuadratic_fn);

    napi_value DrawSplineBezierCubic_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawSplineBezierCubic, NULL, &DrawSplineBezierCubic_fn);
    napi_set_named_property(env, exports, "DrawSplineBezierCubic", DrawSplineBezierCubic_fn);

    napi_value DrawSplineSegmentLinear_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawSplineSegmentLinear, NULL, &DrawSplineSegmentLinear_fn);
    napi_set_named_property(env, exports, "DrawSplineSegmentLinear", DrawSplineSegmentLinear_fn);

    napi_value DrawSplineSegmentBasis_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawSplineSegmentBasis, NULL, &DrawSplineSegmentBasis_fn);
    napi_set_named_property(env, exports, "DrawSplineSegmentBasis", DrawSplineSegmentBasis_fn);

    napi_value DrawSplineSegmentCatmullRom_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawSplineSegmentCatmullRom, NULL, &DrawSplineSegmentCatmullRom_fn);
    napi_set_named_property(env, exports, "DrawSplineSegmentCatmullRom", DrawSplineSegmentCatmullRom_fn);

    napi_value DrawSplineSegmentBezierQuadratic_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawSplineSegmentBezierQuadratic, NULL, &DrawSplineSegmentBezierQuadratic_fn);
    napi_set_named_property(env, exports, "DrawSplineSegmentBezierQuadratic", DrawSplineSegmentBezierQuadratic_fn);

    napi_value DrawSplineSegmentBezierCubic_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawSplineSegmentBezierCubic, NULL, &DrawSplineSegmentBezierCubic_fn);
    napi_set_named_property(env, exports, "DrawSplineSegmentBezierCubic", DrawSplineSegmentBezierCubic_fn);

    napi_value GetSplinePointLinear_fn;
    napi_create_function(env, NULL, 0, BindNode_GetSplinePointLinear, NULL, &GetSplinePointLinear_fn);
    napi_set_named_property(env, exports, "GetSplinePointLinear", GetSplinePointLinear_fn);

    napi_value GetSplinePointBasis_fn;
    napi_create_function(env, NULL, 0, BindNode_GetSplinePointBasis, NULL, &GetSplinePointBasis_fn);
    napi_set_named_property(env, exports, "GetSplinePointBasis", GetSplinePointBasis_fn);

    napi_value GetSplinePointCatmullRom_fn;
    napi_create_function(env, NULL, 0, BindNode_GetSplinePointCatmullRom, NULL, &GetSplinePointCatmullRom_fn);
    napi_set_named_property(env, exports, "GetSplinePointCatmullRom", GetSplinePointCatmullRom_fn);

    napi_value GetSplinePointBezierQuad_fn;
    napi_create_function(env, NULL, 0, BindNode_GetSplinePointBezierQuad, NULL, &GetSplinePointBezierQuad_fn);
    napi_set_named_property(env, exports, "GetSplinePointBezierQuad", GetSplinePointBezierQuad_fn);

    napi_value GetSplinePointBezierCubic_fn;
    napi_create_function(env, NULL, 0, BindNode_GetSplinePointBezierCubic, NULL, &GetSplinePointBezierCubic_fn);
    napi_set_named_property(env, exports, "GetSplinePointBezierCubic", GetSplinePointBezierCubic_fn);

    napi_value CheckCollisionRecs_fn;
    napi_create_function(env, NULL, 0, BindNode_CheckCollisionRecs, NULL, &CheckCollisionRecs_fn);
    napi_set_named_property(env, exports, "CheckCollisionRecs", CheckCollisionRecs_fn);

    napi_value CheckCollisionCircles_fn;
    napi_create_function(env, NULL, 0, BindNode_CheckCollisionCircles, NULL, &CheckCollisionCircles_fn);
    napi_set_named_property(env, exports, "CheckCollisionCircles", CheckCollisionCircles_fn);

    napi_value CheckCollisionCircleRec_fn;
    napi_create_function(env, NULL, 0, BindNode_CheckCollisionCircleRec, NULL, &CheckCollisionCircleRec_fn);
    napi_set_named_property(env, exports, "CheckCollisionCircleRec", CheckCollisionCircleRec_fn);

    napi_value CheckCollisionCircleLine_fn;
    napi_create_function(env, NULL, 0, BindNode_CheckCollisionCircleLine, NULL, &CheckCollisionCircleLine_fn);
    napi_set_named_property(env, exports, "CheckCollisionCircleLine", CheckCollisionCircleLine_fn);

    napi_value CheckCollisionPointRec_fn;
    napi_create_function(env, NULL, 0, BindNode_CheckCollisionPointRec, NULL, &CheckCollisionPointRec_fn);
    napi_set_named_property(env, exports, "CheckCollisionPointRec", CheckCollisionPointRec_fn);

    napi_value CheckCollisionPointCircle_fn;
    napi_create_function(env, NULL, 0, BindNode_CheckCollisionPointCircle, NULL, &CheckCollisionPointCircle_fn);
    napi_set_named_property(env, exports, "CheckCollisionPointCircle", CheckCollisionPointCircle_fn);

    napi_value CheckCollisionPointTriangle_fn;
    napi_create_function(env, NULL, 0, BindNode_CheckCollisionPointTriangle, NULL, &CheckCollisionPointTriangle_fn);
    napi_set_named_property(env, exports, "CheckCollisionPointTriangle", CheckCollisionPointTriangle_fn);

    napi_value CheckCollisionPointLine_fn;
    napi_create_function(env, NULL, 0, BindNode_CheckCollisionPointLine, NULL, &CheckCollisionPointLine_fn);
    napi_set_named_property(env, exports, "CheckCollisionPointLine", CheckCollisionPointLine_fn);

    napi_value CheckCollisionPointPoly_fn;
    napi_create_function(env, NULL, 0, BindNode_CheckCollisionPointPoly, NULL, &CheckCollisionPointPoly_fn);
    napi_set_named_property(env, exports, "CheckCollisionPointPoly", CheckCollisionPointPoly_fn);

    napi_value CheckCollisionLines_fn;
    napi_create_function(env, NULL, 0, BindNode_CheckCollisionLines, NULL, &CheckCollisionLines_fn);
    napi_set_named_property(env, exports, "CheckCollisionLines", CheckCollisionLines_fn);

    napi_value GetCollisionRec_fn;
    napi_create_function(env, NULL, 0, BindNode_GetCollisionRec, NULL, &GetCollisionRec_fn);
    napi_set_named_property(env, exports, "GetCollisionRec", GetCollisionRec_fn);

    napi_value LoadImage_fn;
    napi_create_function(env, NULL, 0, BindNode_LoadImage, NULL, &LoadImage_fn);
    napi_set_named_property(env, exports, "LoadImage", LoadImage_fn);

    napi_value LoadImageRaw_fn;
    napi_create_function(env, NULL, 0, BindNode_LoadImageRaw, NULL, &LoadImageRaw_fn);
    napi_set_named_property(env, exports, "LoadImageRaw", LoadImageRaw_fn);

    napi_value LoadImageAnim_fn;
    napi_create_function(env, NULL, 0, BindNode_LoadImageAnim, NULL, &LoadImageAnim_fn);
    napi_set_named_property(env, exports, "LoadImageAnim", LoadImageAnim_fn);

    napi_value LoadImageAnimFromMemory_fn;
    napi_create_function(env, NULL, 0, BindNode_LoadImageAnimFromMemory, NULL, &LoadImageAnimFromMemory_fn);
    napi_set_named_property(env, exports, "LoadImageAnimFromMemory", LoadImageAnimFromMemory_fn);

    napi_value LoadImageFromMemory_fn;
    napi_create_function(env, NULL, 0, BindNode_LoadImageFromMemory, NULL, &LoadImageFromMemory_fn);
    napi_set_named_property(env, exports, "LoadImageFromMemory", LoadImageFromMemory_fn);

    napi_value LoadImageFromTexture_fn;
    napi_create_function(env, NULL, 0, BindNode_LoadImageFromTexture, NULL, &LoadImageFromTexture_fn);
    napi_set_named_property(env, exports, "LoadImageFromTexture", LoadImageFromTexture_fn);

    napi_value LoadImageFromScreen_fn;
    napi_create_function(env, NULL, 0, BindNode_LoadImageFromScreen, NULL, &LoadImageFromScreen_fn);
    napi_set_named_property(env, exports, "LoadImageFromScreen", LoadImageFromScreen_fn);

    napi_value IsImageValid_fn;
    napi_create_function(env, NULL, 0, BindNode_IsImageValid, NULL, &IsImageValid_fn);
    napi_set_named_property(env, exports, "IsImageValid", IsImageValid_fn);

    napi_value UnloadImage_fn;
    napi_create_function(env, NULL, 0, BindNode_UnloadImage, NULL, &UnloadImage_fn);
    napi_set_named_property(env, exports, "UnloadImage", UnloadImage_fn);

    napi_value ExportImage_fn;
    napi_create_function(env, NULL, 0, BindNode_ExportImage, NULL, &ExportImage_fn);
    napi_set_named_property(env, exports, "ExportImage", ExportImage_fn);

    napi_value ExportImageToMemory_fn;
    napi_create_function(env, NULL, 0, BindNode_ExportImageToMemory, NULL, &ExportImageToMemory_fn);
    napi_set_named_property(env, exports, "ExportImageToMemory", ExportImageToMemory_fn);

    napi_value ExportImageAsCode_fn;
    napi_create_function(env, NULL, 0, BindNode_ExportImageAsCode, NULL, &ExportImageAsCode_fn);
    napi_set_named_property(env, exports, "ExportImageAsCode", ExportImageAsCode_fn);

    napi_value GenImageColor_fn;
    napi_create_function(env, NULL, 0, BindNode_GenImageColor, NULL, &GenImageColor_fn);
    napi_set_named_property(env, exports, "GenImageColor", GenImageColor_fn);

    napi_value GenImageGradientLinear_fn;
    napi_create_function(env, NULL, 0, BindNode_GenImageGradientLinear, NULL, &GenImageGradientLinear_fn);
    napi_set_named_property(env, exports, "GenImageGradientLinear", GenImageGradientLinear_fn);

    napi_value GenImageGradientRadial_fn;
    napi_create_function(env, NULL, 0, BindNode_GenImageGradientRadial, NULL, &GenImageGradientRadial_fn);
    napi_set_named_property(env, exports, "GenImageGradientRadial", GenImageGradientRadial_fn);

    napi_value GenImageGradientSquare_fn;
    napi_create_function(env, NULL, 0, BindNode_GenImageGradientSquare, NULL, &GenImageGradientSquare_fn);
    napi_set_named_property(env, exports, "GenImageGradientSquare", GenImageGradientSquare_fn);

    napi_value GenImageChecked_fn;
    napi_create_function(env, NULL, 0, BindNode_GenImageChecked, NULL, &GenImageChecked_fn);
    napi_set_named_property(env, exports, "GenImageChecked", GenImageChecked_fn);

    napi_value GenImageWhiteNoise_fn;
    napi_create_function(env, NULL, 0, BindNode_GenImageWhiteNoise, NULL, &GenImageWhiteNoise_fn);
    napi_set_named_property(env, exports, "GenImageWhiteNoise", GenImageWhiteNoise_fn);

    napi_value GenImagePerlinNoise_fn;
    napi_create_function(env, NULL, 0, BindNode_GenImagePerlinNoise, NULL, &GenImagePerlinNoise_fn);
    napi_set_named_property(env, exports, "GenImagePerlinNoise", GenImagePerlinNoise_fn);

    napi_value GenImageCellular_fn;
    napi_create_function(env, NULL, 0, BindNode_GenImageCellular, NULL, &GenImageCellular_fn);
    napi_set_named_property(env, exports, "GenImageCellular", GenImageCellular_fn);

    napi_value GenImageText_fn;
    napi_create_function(env, NULL, 0, BindNode_GenImageText, NULL, &GenImageText_fn);
    napi_set_named_property(env, exports, "GenImageText", GenImageText_fn);

    napi_value ImageCopy_fn;
    napi_create_function(env, NULL, 0, BindNode_ImageCopy, NULL, &ImageCopy_fn);
    napi_set_named_property(env, exports, "ImageCopy", ImageCopy_fn);

    napi_value ImageFromImage_fn;
    napi_create_function(env, NULL, 0, BindNode_ImageFromImage, NULL, &ImageFromImage_fn);
    napi_set_named_property(env, exports, "ImageFromImage", ImageFromImage_fn);

    napi_value ImageFromChannel_fn;
    napi_create_function(env, NULL, 0, BindNode_ImageFromChannel, NULL, &ImageFromChannel_fn);
    napi_set_named_property(env, exports, "ImageFromChannel", ImageFromChannel_fn);

    napi_value ImageText_fn;
    napi_create_function(env, NULL, 0, BindNode_ImageText, NULL, &ImageText_fn);
    napi_set_named_property(env, exports, "ImageText", ImageText_fn);

    napi_value ImageTextEx_fn;
    napi_create_function(env, NULL, 0, BindNode_ImageTextEx, NULL, &ImageTextEx_fn);
    napi_set_named_property(env, exports, "ImageTextEx", ImageTextEx_fn);

    napi_value ImageFormat_fn;
    napi_create_function(env, NULL, 0, BindNode_ImageFormat, NULL, &ImageFormat_fn);
    napi_set_named_property(env, exports, "ImageFormat", ImageFormat_fn);

    napi_value ImageToPOT_fn;
    napi_create_function(env, NULL, 0, BindNode_ImageToPOT, NULL, &ImageToPOT_fn);
    napi_set_named_property(env, exports, "ImageToPOT", ImageToPOT_fn);

    napi_value ImageCrop_fn;
    napi_create_function(env, NULL, 0, BindNode_ImageCrop, NULL, &ImageCrop_fn);
    napi_set_named_property(env, exports, "ImageCrop", ImageCrop_fn);

    napi_value ImageAlphaCrop_fn;
    napi_create_function(env, NULL, 0, BindNode_ImageAlphaCrop, NULL, &ImageAlphaCrop_fn);
    napi_set_named_property(env, exports, "ImageAlphaCrop", ImageAlphaCrop_fn);

    napi_value ImageAlphaClear_fn;
    napi_create_function(env, NULL, 0, BindNode_ImageAlphaClear, NULL, &ImageAlphaClear_fn);
    napi_set_named_property(env, exports, "ImageAlphaClear", ImageAlphaClear_fn);

    napi_value ImageAlphaMask_fn;
    napi_create_function(env, NULL, 0, BindNode_ImageAlphaMask, NULL, &ImageAlphaMask_fn);
    napi_set_named_property(env, exports, "ImageAlphaMask", ImageAlphaMask_fn);

    napi_value ImageAlphaPremultiply_fn;
    napi_create_function(env, NULL, 0, BindNode_ImageAlphaPremultiply, NULL, &ImageAlphaPremultiply_fn);
    napi_set_named_property(env, exports, "ImageAlphaPremultiply", ImageAlphaPremultiply_fn);

    napi_value ImageBlurGaussian_fn;
    napi_create_function(env, NULL, 0, BindNode_ImageBlurGaussian, NULL, &ImageBlurGaussian_fn);
    napi_set_named_property(env, exports, "ImageBlurGaussian", ImageBlurGaussian_fn);

    napi_value ImageKernelConvolution_fn;
    napi_create_function(env, NULL, 0, BindNode_ImageKernelConvolution, NULL, &ImageKernelConvolution_fn);
    napi_set_named_property(env, exports, "ImageKernelConvolution", ImageKernelConvolution_fn);

    napi_value ImageResize_fn;
    napi_create_function(env, NULL, 0, BindNode_ImageResize, NULL, &ImageResize_fn);
    napi_set_named_property(env, exports, "ImageResize", ImageResize_fn);

    napi_value ImageResizeNN_fn;
    napi_create_function(env, NULL, 0, BindNode_ImageResizeNN, NULL, &ImageResizeNN_fn);
    napi_set_named_property(env, exports, "ImageResizeNN", ImageResizeNN_fn);

    napi_value ImageResizeCanvas_fn;
    napi_create_function(env, NULL, 0, BindNode_ImageResizeCanvas, NULL, &ImageResizeCanvas_fn);
    napi_set_named_property(env, exports, "ImageResizeCanvas", ImageResizeCanvas_fn);

    napi_value ImageMipmaps_fn;
    napi_create_function(env, NULL, 0, BindNode_ImageMipmaps, NULL, &ImageMipmaps_fn);
    napi_set_named_property(env, exports, "ImageMipmaps", ImageMipmaps_fn);

    napi_value ImageDither_fn;
    napi_create_function(env, NULL, 0, BindNode_ImageDither, NULL, &ImageDither_fn);
    napi_set_named_property(env, exports, "ImageDither", ImageDither_fn);

    napi_value ImageFlipVertical_fn;
    napi_create_function(env, NULL, 0, BindNode_ImageFlipVertical, NULL, &ImageFlipVertical_fn);
    napi_set_named_property(env, exports, "ImageFlipVertical", ImageFlipVertical_fn);

    napi_value ImageFlipHorizontal_fn;
    napi_create_function(env, NULL, 0, BindNode_ImageFlipHorizontal, NULL, &ImageFlipHorizontal_fn);
    napi_set_named_property(env, exports, "ImageFlipHorizontal", ImageFlipHorizontal_fn);

    napi_value ImageRotate_fn;
    napi_create_function(env, NULL, 0, BindNode_ImageRotate, NULL, &ImageRotate_fn);
    napi_set_named_property(env, exports, "ImageRotate", ImageRotate_fn);

    napi_value ImageRotateCW_fn;
    napi_create_function(env, NULL, 0, BindNode_ImageRotateCW, NULL, &ImageRotateCW_fn);
    napi_set_named_property(env, exports, "ImageRotateCW", ImageRotateCW_fn);

    napi_value ImageRotateCCW_fn;
    napi_create_function(env, NULL, 0, BindNode_ImageRotateCCW, NULL, &ImageRotateCCW_fn);
    napi_set_named_property(env, exports, "ImageRotateCCW", ImageRotateCCW_fn);

    napi_value ImageColorTint_fn;
    napi_create_function(env, NULL, 0, BindNode_ImageColorTint, NULL, &ImageColorTint_fn);
    napi_set_named_property(env, exports, "ImageColorTint", ImageColorTint_fn);

    napi_value ImageColorInvert_fn;
    napi_create_function(env, NULL, 0, BindNode_ImageColorInvert, NULL, &ImageColorInvert_fn);
    napi_set_named_property(env, exports, "ImageColorInvert", ImageColorInvert_fn);

    napi_value ImageColorGrayscale_fn;
    napi_create_function(env, NULL, 0, BindNode_ImageColorGrayscale, NULL, &ImageColorGrayscale_fn);
    napi_set_named_property(env, exports, "ImageColorGrayscale", ImageColorGrayscale_fn);

    napi_value ImageColorContrast_fn;
    napi_create_function(env, NULL, 0, BindNode_ImageColorContrast, NULL, &ImageColorContrast_fn);
    napi_set_named_property(env, exports, "ImageColorContrast", ImageColorContrast_fn);

    napi_value ImageColorBrightness_fn;
    napi_create_function(env, NULL, 0, BindNode_ImageColorBrightness, NULL, &ImageColorBrightness_fn);
    napi_set_named_property(env, exports, "ImageColorBrightness", ImageColorBrightness_fn);

    napi_value ImageColorReplace_fn;
    napi_create_function(env, NULL, 0, BindNode_ImageColorReplace, NULL, &ImageColorReplace_fn);
    napi_set_named_property(env, exports, "ImageColorReplace", ImageColorReplace_fn);

    napi_value LoadImageColors_fn;
    napi_create_function(env, NULL, 0, BindNode_LoadImageColors, NULL, &LoadImageColors_fn);
    napi_set_named_property(env, exports, "LoadImageColors", LoadImageColors_fn);

    napi_value LoadImagePalette_fn;
    napi_create_function(env, NULL, 0, BindNode_LoadImagePalette, NULL, &LoadImagePalette_fn);
    napi_set_named_property(env, exports, "LoadImagePalette", LoadImagePalette_fn);

    napi_value UnloadImageColors_fn;
    napi_create_function(env, NULL, 0, BindNode_UnloadImageColors, NULL, &UnloadImageColors_fn);
    napi_set_named_property(env, exports, "UnloadImageColors", UnloadImageColors_fn);

    napi_value UnloadImagePalette_fn;
    napi_create_function(env, NULL, 0, BindNode_UnloadImagePalette, NULL, &UnloadImagePalette_fn);
    napi_set_named_property(env, exports, "UnloadImagePalette", UnloadImagePalette_fn);

    napi_value GetImageAlphaBorder_fn;
    napi_create_function(env, NULL, 0, BindNode_GetImageAlphaBorder, NULL, &GetImageAlphaBorder_fn);
    napi_set_named_property(env, exports, "GetImageAlphaBorder", GetImageAlphaBorder_fn);

    napi_value GetImageColor_fn;
    napi_create_function(env, NULL, 0, BindNode_GetImageColor, NULL, &GetImageColor_fn);
    napi_set_named_property(env, exports, "GetImageColor", GetImageColor_fn);

    napi_value ImageClearBackground_fn;
    napi_create_function(env, NULL, 0, BindNode_ImageClearBackground, NULL, &ImageClearBackground_fn);
    napi_set_named_property(env, exports, "ImageClearBackground", ImageClearBackground_fn);

    napi_value ImageDrawPixel_fn;
    napi_create_function(env, NULL, 0, BindNode_ImageDrawPixel, NULL, &ImageDrawPixel_fn);
    napi_set_named_property(env, exports, "ImageDrawPixel", ImageDrawPixel_fn);

    napi_value ImageDrawPixelV_fn;
    napi_create_function(env, NULL, 0, BindNode_ImageDrawPixelV, NULL, &ImageDrawPixelV_fn);
    napi_set_named_property(env, exports, "ImageDrawPixelV", ImageDrawPixelV_fn);

    napi_value ImageDrawLine_fn;
    napi_create_function(env, NULL, 0, BindNode_ImageDrawLine, NULL, &ImageDrawLine_fn);
    napi_set_named_property(env, exports, "ImageDrawLine", ImageDrawLine_fn);

    napi_value ImageDrawLineV_fn;
    napi_create_function(env, NULL, 0, BindNode_ImageDrawLineV, NULL, &ImageDrawLineV_fn);
    napi_set_named_property(env, exports, "ImageDrawLineV", ImageDrawLineV_fn);

    napi_value ImageDrawLineEx_fn;
    napi_create_function(env, NULL, 0, BindNode_ImageDrawLineEx, NULL, &ImageDrawLineEx_fn);
    napi_set_named_property(env, exports, "ImageDrawLineEx", ImageDrawLineEx_fn);

    napi_value ImageDrawCircle_fn;
    napi_create_function(env, NULL, 0, BindNode_ImageDrawCircle, NULL, &ImageDrawCircle_fn);
    napi_set_named_property(env, exports, "ImageDrawCircle", ImageDrawCircle_fn);

    napi_value ImageDrawCircleV_fn;
    napi_create_function(env, NULL, 0, BindNode_ImageDrawCircleV, NULL, &ImageDrawCircleV_fn);
    napi_set_named_property(env, exports, "ImageDrawCircleV", ImageDrawCircleV_fn);

    napi_value ImageDrawCircleLines_fn;
    napi_create_function(env, NULL, 0, BindNode_ImageDrawCircleLines, NULL, &ImageDrawCircleLines_fn);
    napi_set_named_property(env, exports, "ImageDrawCircleLines", ImageDrawCircleLines_fn);

    napi_value ImageDrawCircleLinesV_fn;
    napi_create_function(env, NULL, 0, BindNode_ImageDrawCircleLinesV, NULL, &ImageDrawCircleLinesV_fn);
    napi_set_named_property(env, exports, "ImageDrawCircleLinesV", ImageDrawCircleLinesV_fn);

    napi_value ImageDrawRectangle_fn;
    napi_create_function(env, NULL, 0, BindNode_ImageDrawRectangle, NULL, &ImageDrawRectangle_fn);
    napi_set_named_property(env, exports, "ImageDrawRectangle", ImageDrawRectangle_fn);

    napi_value ImageDrawRectangleV_fn;
    napi_create_function(env, NULL, 0, BindNode_ImageDrawRectangleV, NULL, &ImageDrawRectangleV_fn);
    napi_set_named_property(env, exports, "ImageDrawRectangleV", ImageDrawRectangleV_fn);

    napi_value ImageDrawRectangleRec_fn;
    napi_create_function(env, NULL, 0, BindNode_ImageDrawRectangleRec, NULL, &ImageDrawRectangleRec_fn);
    napi_set_named_property(env, exports, "ImageDrawRectangleRec", ImageDrawRectangleRec_fn);

    napi_value ImageDrawRectangleLines_fn;
    napi_create_function(env, NULL, 0, BindNode_ImageDrawRectangleLines, NULL, &ImageDrawRectangleLines_fn);
    napi_set_named_property(env, exports, "ImageDrawRectangleLines", ImageDrawRectangleLines_fn);

    napi_value ImageDrawTriangle_fn;
    napi_create_function(env, NULL, 0, BindNode_ImageDrawTriangle, NULL, &ImageDrawTriangle_fn);
    napi_set_named_property(env, exports, "ImageDrawTriangle", ImageDrawTriangle_fn);

    napi_value ImageDrawTriangleEx_fn;
    napi_create_function(env, NULL, 0, BindNode_ImageDrawTriangleEx, NULL, &ImageDrawTriangleEx_fn);
    napi_set_named_property(env, exports, "ImageDrawTriangleEx", ImageDrawTriangleEx_fn);

    napi_value ImageDrawTriangleLines_fn;
    napi_create_function(env, NULL, 0, BindNode_ImageDrawTriangleLines, NULL, &ImageDrawTriangleLines_fn);
    napi_set_named_property(env, exports, "ImageDrawTriangleLines", ImageDrawTriangleLines_fn);

    napi_value ImageDrawTriangleFan_fn;
    napi_create_function(env, NULL, 0, BindNode_ImageDrawTriangleFan, NULL, &ImageDrawTriangleFan_fn);
    napi_set_named_property(env, exports, "ImageDrawTriangleFan", ImageDrawTriangleFan_fn);

    napi_value ImageDrawTriangleStrip_fn;
    napi_create_function(env, NULL, 0, BindNode_ImageDrawTriangleStrip, NULL, &ImageDrawTriangleStrip_fn);
    napi_set_named_property(env, exports, "ImageDrawTriangleStrip", ImageDrawTriangleStrip_fn);

    napi_value ImageDraw_fn;
    napi_create_function(env, NULL, 0, BindNode_ImageDraw, NULL, &ImageDraw_fn);
    napi_set_named_property(env, exports, "ImageDraw", ImageDraw_fn);

    napi_value ImageDrawText_fn;
    napi_create_function(env, NULL, 0, BindNode_ImageDrawText, NULL, &ImageDrawText_fn);
    napi_set_named_property(env, exports, "ImageDrawText", ImageDrawText_fn);

    napi_value ImageDrawTextEx_fn;
    napi_create_function(env, NULL, 0, BindNode_ImageDrawTextEx, NULL, &ImageDrawTextEx_fn);
    napi_set_named_property(env, exports, "ImageDrawTextEx", ImageDrawTextEx_fn);

    napi_value LoadTexture_fn;
    napi_create_function(env, NULL, 0, BindNode_LoadTexture, NULL, &LoadTexture_fn);
    napi_set_named_property(env, exports, "LoadTexture", LoadTexture_fn);

    napi_value LoadTextureFromImage_fn;
    napi_create_function(env, NULL, 0, BindNode_LoadTextureFromImage, NULL, &LoadTextureFromImage_fn);
    napi_set_named_property(env, exports, "LoadTextureFromImage", LoadTextureFromImage_fn);

    napi_value LoadTextureCubemap_fn;
    napi_create_function(env, NULL, 0, BindNode_LoadTextureCubemap, NULL, &LoadTextureCubemap_fn);
    napi_set_named_property(env, exports, "LoadTextureCubemap", LoadTextureCubemap_fn);

    napi_value LoadRenderTexture_fn;
    napi_create_function(env, NULL, 0, BindNode_LoadRenderTexture, NULL, &LoadRenderTexture_fn);
    napi_set_named_property(env, exports, "LoadRenderTexture", LoadRenderTexture_fn);

    napi_value IsTextureValid_fn;
    napi_create_function(env, NULL, 0, BindNode_IsTextureValid, NULL, &IsTextureValid_fn);
    napi_set_named_property(env, exports, "IsTextureValid", IsTextureValid_fn);

    napi_value UnloadTexture_fn;
    napi_create_function(env, NULL, 0, BindNode_UnloadTexture, NULL, &UnloadTexture_fn);
    napi_set_named_property(env, exports, "UnloadTexture", UnloadTexture_fn);

    napi_value IsRenderTextureValid_fn;
    napi_create_function(env, NULL, 0, BindNode_IsRenderTextureValid, NULL, &IsRenderTextureValid_fn);
    napi_set_named_property(env, exports, "IsRenderTextureValid", IsRenderTextureValid_fn);

    napi_value UnloadRenderTexture_fn;
    napi_create_function(env, NULL, 0, BindNode_UnloadRenderTexture, NULL, &UnloadRenderTexture_fn);
    napi_set_named_property(env, exports, "UnloadRenderTexture", UnloadRenderTexture_fn);

    napi_value UpdateTexture_fn;
    napi_create_function(env, NULL, 0, BindNode_UpdateTexture, NULL, &UpdateTexture_fn);
    napi_set_named_property(env, exports, "UpdateTexture", UpdateTexture_fn);

    napi_value UpdateTextureRec_fn;
    napi_create_function(env, NULL, 0, BindNode_UpdateTextureRec, NULL, &UpdateTextureRec_fn);
    napi_set_named_property(env, exports, "UpdateTextureRec", UpdateTextureRec_fn);

    napi_value GenTextureMipmaps_fn;
    napi_create_function(env, NULL, 0, BindNode_GenTextureMipmaps, NULL, &GenTextureMipmaps_fn);
    napi_set_named_property(env, exports, "GenTextureMipmaps", GenTextureMipmaps_fn);

    napi_value SetTextureFilter_fn;
    napi_create_function(env, NULL, 0, BindNode_SetTextureFilter, NULL, &SetTextureFilter_fn);
    napi_set_named_property(env, exports, "SetTextureFilter", SetTextureFilter_fn);

    napi_value SetTextureWrap_fn;
    napi_create_function(env, NULL, 0, BindNode_SetTextureWrap, NULL, &SetTextureWrap_fn);
    napi_set_named_property(env, exports, "SetTextureWrap", SetTextureWrap_fn);

    napi_value DrawTexture_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawTexture, NULL, &DrawTexture_fn);
    napi_set_named_property(env, exports, "DrawTexture", DrawTexture_fn);

    napi_value DrawTextureV_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawTextureV, NULL, &DrawTextureV_fn);
    napi_set_named_property(env, exports, "DrawTextureV", DrawTextureV_fn);

    napi_value DrawTextureEx_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawTextureEx, NULL, &DrawTextureEx_fn);
    napi_set_named_property(env, exports, "DrawTextureEx", DrawTextureEx_fn);

    napi_value DrawTextureRec_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawTextureRec, NULL, &DrawTextureRec_fn);
    napi_set_named_property(env, exports, "DrawTextureRec", DrawTextureRec_fn);

    napi_value DrawTexturePro_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawTexturePro, NULL, &DrawTexturePro_fn);
    napi_set_named_property(env, exports, "DrawTexturePro", DrawTexturePro_fn);

    napi_value DrawTextureNPatch_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawTextureNPatch, NULL, &DrawTextureNPatch_fn);
    napi_set_named_property(env, exports, "DrawTextureNPatch", DrawTextureNPatch_fn);

    napi_value ColorIsEqual_fn;
    napi_create_function(env, NULL, 0, BindNode_ColorIsEqual, NULL, &ColorIsEqual_fn);
    napi_set_named_property(env, exports, "ColorIsEqual", ColorIsEqual_fn);

    napi_value Fade_fn;
    napi_create_function(env, NULL, 0, BindNode_Fade, NULL, &Fade_fn);
    napi_set_named_property(env, exports, "Fade", Fade_fn);

    napi_value ColorToInt_fn;
    napi_create_function(env, NULL, 0, BindNode_ColorToInt, NULL, &ColorToInt_fn);
    napi_set_named_property(env, exports, "ColorToInt", ColorToInt_fn);

    napi_value ColorNormalize_fn;
    napi_create_function(env, NULL, 0, BindNode_ColorNormalize, NULL, &ColorNormalize_fn);
    napi_set_named_property(env, exports, "ColorNormalize", ColorNormalize_fn);

    napi_value ColorFromNormalized_fn;
    napi_create_function(env, NULL, 0, BindNode_ColorFromNormalized, NULL, &ColorFromNormalized_fn);
    napi_set_named_property(env, exports, "ColorFromNormalized", ColorFromNormalized_fn);

    napi_value ColorToHSV_fn;
    napi_create_function(env, NULL, 0, BindNode_ColorToHSV, NULL, &ColorToHSV_fn);
    napi_set_named_property(env, exports, "ColorToHSV", ColorToHSV_fn);

    napi_value ColorFromHSV_fn;
    napi_create_function(env, NULL, 0, BindNode_ColorFromHSV, NULL, &ColorFromHSV_fn);
    napi_set_named_property(env, exports, "ColorFromHSV", ColorFromHSV_fn);

    napi_value ColorTint_fn;
    napi_create_function(env, NULL, 0, BindNode_ColorTint, NULL, &ColorTint_fn);
    napi_set_named_property(env, exports, "ColorTint", ColorTint_fn);

    napi_value ColorBrightness_fn;
    napi_create_function(env, NULL, 0, BindNode_ColorBrightness, NULL, &ColorBrightness_fn);
    napi_set_named_property(env, exports, "ColorBrightness", ColorBrightness_fn);

    napi_value ColorContrast_fn;
    napi_create_function(env, NULL, 0, BindNode_ColorContrast, NULL, &ColorContrast_fn);
    napi_set_named_property(env, exports, "ColorContrast", ColorContrast_fn);

    napi_value ColorAlpha_fn;
    napi_create_function(env, NULL, 0, BindNode_ColorAlpha, NULL, &ColorAlpha_fn);
    napi_set_named_property(env, exports, "ColorAlpha", ColorAlpha_fn);

    napi_value ColorAlphaBlend_fn;
    napi_create_function(env, NULL, 0, BindNode_ColorAlphaBlend, NULL, &ColorAlphaBlend_fn);
    napi_set_named_property(env, exports, "ColorAlphaBlend", ColorAlphaBlend_fn);

    napi_value ColorLerp_fn;
    napi_create_function(env, NULL, 0, BindNode_ColorLerp, NULL, &ColorLerp_fn);
    napi_set_named_property(env, exports, "ColorLerp", ColorLerp_fn);

    napi_value GetColor_fn;
    napi_create_function(env, NULL, 0, BindNode_GetColor, NULL, &GetColor_fn);
    napi_set_named_property(env, exports, "GetColor", GetColor_fn);

    napi_value GetPixelColor_fn;
    napi_create_function(env, NULL, 0, BindNode_GetPixelColor, NULL, &GetPixelColor_fn);
    napi_set_named_property(env, exports, "GetPixelColor", GetPixelColor_fn);

    napi_value SetPixelColor_fn;
    napi_create_function(env, NULL, 0, BindNode_SetPixelColor, NULL, &SetPixelColor_fn);
    napi_set_named_property(env, exports, "SetPixelColor", SetPixelColor_fn);

    napi_value GetPixelDataSize_fn;
    napi_create_function(env, NULL, 0, BindNode_GetPixelDataSize, NULL, &GetPixelDataSize_fn);
    napi_set_named_property(env, exports, "GetPixelDataSize", GetPixelDataSize_fn);

    napi_value GetFontDefault_fn;
    napi_create_function(env, NULL, 0, BindNode_GetFontDefault, NULL, &GetFontDefault_fn);
    napi_set_named_property(env, exports, "GetFontDefault", GetFontDefault_fn);

    napi_value LoadFont_fn;
    napi_create_function(env, NULL, 0, BindNode_LoadFont, NULL, &LoadFont_fn);
    napi_set_named_property(env, exports, "LoadFont", LoadFont_fn);

    napi_value LoadFontEx_fn;
    napi_create_function(env, NULL, 0, BindNode_LoadFontEx, NULL, &LoadFontEx_fn);
    napi_set_named_property(env, exports, "LoadFontEx", LoadFontEx_fn);

    napi_value LoadFontFromImage_fn;
    napi_create_function(env, NULL, 0, BindNode_LoadFontFromImage, NULL, &LoadFontFromImage_fn);
    napi_set_named_property(env, exports, "LoadFontFromImage", LoadFontFromImage_fn);

    napi_value LoadFontFromMemory_fn;
    napi_create_function(env, NULL, 0, BindNode_LoadFontFromMemory, NULL, &LoadFontFromMemory_fn);
    napi_set_named_property(env, exports, "LoadFontFromMemory", LoadFontFromMemory_fn);

    napi_value IsFontValid_fn;
    napi_create_function(env, NULL, 0, BindNode_IsFontValid, NULL, &IsFontValid_fn);
    napi_set_named_property(env, exports, "IsFontValid", IsFontValid_fn);

    napi_value LoadFontData_fn;
    napi_create_function(env, NULL, 0, BindNode_LoadFontData, NULL, &LoadFontData_fn);
    napi_set_named_property(env, exports, "LoadFontData", LoadFontData_fn);

    napi_value GenImageFontAtlas_fn;
    napi_create_function(env, NULL, 0, BindNode_GenImageFontAtlas, NULL, &GenImageFontAtlas_fn);
    napi_set_named_property(env, exports, "GenImageFontAtlas", GenImageFontAtlas_fn);

    napi_value UnloadFontData_fn;
    napi_create_function(env, NULL, 0, BindNode_UnloadFontData, NULL, &UnloadFontData_fn);
    napi_set_named_property(env, exports, "UnloadFontData", UnloadFontData_fn);

    napi_value UnloadFont_fn;
    napi_create_function(env, NULL, 0, BindNode_UnloadFont, NULL, &UnloadFont_fn);
    napi_set_named_property(env, exports, "UnloadFont", UnloadFont_fn);

    napi_value ExportFontAsCode_fn;
    napi_create_function(env, NULL, 0, BindNode_ExportFontAsCode, NULL, &ExportFontAsCode_fn);
    napi_set_named_property(env, exports, "ExportFontAsCode", ExportFontAsCode_fn);

    napi_value DrawFPS_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawFPS, NULL, &DrawFPS_fn);
    napi_set_named_property(env, exports, "DrawFPS", DrawFPS_fn);

    napi_value DrawText_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawText, NULL, &DrawText_fn);
    napi_set_named_property(env, exports, "DrawText", DrawText_fn);

    napi_value DrawTextEx_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawTextEx, NULL, &DrawTextEx_fn);
    napi_set_named_property(env, exports, "DrawTextEx", DrawTextEx_fn);

    napi_value DrawTextPro_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawTextPro, NULL, &DrawTextPro_fn);
    napi_set_named_property(env, exports, "DrawTextPro", DrawTextPro_fn);

    napi_value DrawTextCodepoint_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawTextCodepoint, NULL, &DrawTextCodepoint_fn);
    napi_set_named_property(env, exports, "DrawTextCodepoint", DrawTextCodepoint_fn);

    napi_value DrawTextCodepoints_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawTextCodepoints, NULL, &DrawTextCodepoints_fn);
    napi_set_named_property(env, exports, "DrawTextCodepoints", DrawTextCodepoints_fn);

    napi_value SetTextLineSpacing_fn;
    napi_create_function(env, NULL, 0, BindNode_SetTextLineSpacing, NULL, &SetTextLineSpacing_fn);
    napi_set_named_property(env, exports, "SetTextLineSpacing", SetTextLineSpacing_fn);

    napi_value MeasureText_fn;
    napi_create_function(env, NULL, 0, BindNode_MeasureText, NULL, &MeasureText_fn);
    napi_set_named_property(env, exports, "MeasureText", MeasureText_fn);

    napi_value MeasureTextEx_fn;
    napi_create_function(env, NULL, 0, BindNode_MeasureTextEx, NULL, &MeasureTextEx_fn);
    napi_set_named_property(env, exports, "MeasureTextEx", MeasureTextEx_fn);

    napi_value GetGlyphIndex_fn;
    napi_create_function(env, NULL, 0, BindNode_GetGlyphIndex, NULL, &GetGlyphIndex_fn);
    napi_set_named_property(env, exports, "GetGlyphIndex", GetGlyphIndex_fn);

    napi_value GetGlyphInfo_fn;
    napi_create_function(env, NULL, 0, BindNode_GetGlyphInfo, NULL, &GetGlyphInfo_fn);
    napi_set_named_property(env, exports, "GetGlyphInfo", GetGlyphInfo_fn);

    napi_value GetGlyphAtlasRec_fn;
    napi_create_function(env, NULL, 0, BindNode_GetGlyphAtlasRec, NULL, &GetGlyphAtlasRec_fn);
    napi_set_named_property(env, exports, "GetGlyphAtlasRec", GetGlyphAtlasRec_fn);

    napi_value LoadUTF8_fn;
    napi_create_function(env, NULL, 0, BindNode_LoadUTF8, NULL, &LoadUTF8_fn);
    napi_set_named_property(env, exports, "LoadUTF8", LoadUTF8_fn);

    napi_value UnloadUTF8_fn;
    napi_create_function(env, NULL, 0, BindNode_UnloadUTF8, NULL, &UnloadUTF8_fn);
    napi_set_named_property(env, exports, "UnloadUTF8", UnloadUTF8_fn);

    napi_value LoadCodepoints_fn;
    napi_create_function(env, NULL, 0, BindNode_LoadCodepoints, NULL, &LoadCodepoints_fn);
    napi_set_named_property(env, exports, "LoadCodepoints", LoadCodepoints_fn);

    napi_value UnloadCodepoints_fn;
    napi_create_function(env, NULL, 0, BindNode_UnloadCodepoints, NULL, &UnloadCodepoints_fn);
    napi_set_named_property(env, exports, "UnloadCodepoints", UnloadCodepoints_fn);

    napi_value GetCodepointCount_fn;
    napi_create_function(env, NULL, 0, BindNode_GetCodepointCount, NULL, &GetCodepointCount_fn);
    napi_set_named_property(env, exports, "GetCodepointCount", GetCodepointCount_fn);

    napi_value GetCodepoint_fn;
    napi_create_function(env, NULL, 0, BindNode_GetCodepoint, NULL, &GetCodepoint_fn);
    napi_set_named_property(env, exports, "GetCodepoint", GetCodepoint_fn);

    napi_value GetCodepointNext_fn;
    napi_create_function(env, NULL, 0, BindNode_GetCodepointNext, NULL, &GetCodepointNext_fn);
    napi_set_named_property(env, exports, "GetCodepointNext", GetCodepointNext_fn);

    napi_value GetCodepointPrevious_fn;
    napi_create_function(env, NULL, 0, BindNode_GetCodepointPrevious, NULL, &GetCodepointPrevious_fn);
    napi_set_named_property(env, exports, "GetCodepointPrevious", GetCodepointPrevious_fn);

    napi_value CodepointToUTF8_fn;
    napi_create_function(env, NULL, 0, BindNode_CodepointToUTF8, NULL, &CodepointToUTF8_fn);
    napi_set_named_property(env, exports, "CodepointToUTF8", CodepointToUTF8_fn);

    napi_value TextCopy_fn;
    napi_create_function(env, NULL, 0, BindNode_TextCopy, NULL, &TextCopy_fn);
    napi_set_named_property(env, exports, "TextCopy", TextCopy_fn);

    napi_value TextIsEqual_fn;
    napi_create_function(env, NULL, 0, BindNode_TextIsEqual, NULL, &TextIsEqual_fn);
    napi_set_named_property(env, exports, "TextIsEqual", TextIsEqual_fn);

    napi_value TextLength_fn;
    napi_create_function(env, NULL, 0, BindNode_TextLength, NULL, &TextLength_fn);
    napi_set_named_property(env, exports, "TextLength", TextLength_fn);

    napi_value TextFormat_fn;
    napi_create_function(env, NULL, 0, BindNode_TextFormat, NULL, &TextFormat_fn);
    napi_set_named_property(env, exports, "TextFormat", TextFormat_fn);

    napi_value TextSubtext_fn;
    napi_create_function(env, NULL, 0, BindNode_TextSubtext, NULL, &TextSubtext_fn);
    napi_set_named_property(env, exports, "TextSubtext", TextSubtext_fn);

    napi_value TextReplace_fn;
    napi_create_function(env, NULL, 0, BindNode_TextReplace, NULL, &TextReplace_fn);
    napi_set_named_property(env, exports, "TextReplace", TextReplace_fn);

    napi_value TextInsert_fn;
    napi_create_function(env, NULL, 0, BindNode_TextInsert, NULL, &TextInsert_fn);
    napi_set_named_property(env, exports, "TextInsert", TextInsert_fn);

    napi_value TextJoin_fn;
    napi_create_function(env, NULL, 0, BindNode_TextJoin, NULL, &TextJoin_fn);
    napi_set_named_property(env, exports, "TextJoin", TextJoin_fn);

    napi_value TextSplit_fn;
    napi_create_function(env, NULL, 0, BindNode_TextSplit, NULL, &TextSplit_fn);
    napi_set_named_property(env, exports, "TextSplit", TextSplit_fn);

    napi_value TextAppend_fn;
    napi_create_function(env, NULL, 0, BindNode_TextAppend, NULL, &TextAppend_fn);
    napi_set_named_property(env, exports, "TextAppend", TextAppend_fn);

    napi_value TextFindIndex_fn;
    napi_create_function(env, NULL, 0, BindNode_TextFindIndex, NULL, &TextFindIndex_fn);
    napi_set_named_property(env, exports, "TextFindIndex", TextFindIndex_fn);

    napi_value TextToUpper_fn;
    napi_create_function(env, NULL, 0, BindNode_TextToUpper, NULL, &TextToUpper_fn);
    napi_set_named_property(env, exports, "TextToUpper", TextToUpper_fn);

    napi_value TextToLower_fn;
    napi_create_function(env, NULL, 0, BindNode_TextToLower, NULL, &TextToLower_fn);
    napi_set_named_property(env, exports, "TextToLower", TextToLower_fn);

    napi_value TextToPascal_fn;
    napi_create_function(env, NULL, 0, BindNode_TextToPascal, NULL, &TextToPascal_fn);
    napi_set_named_property(env, exports, "TextToPascal", TextToPascal_fn);

    napi_value TextToSnake_fn;
    napi_create_function(env, NULL, 0, BindNode_TextToSnake, NULL, &TextToSnake_fn);
    napi_set_named_property(env, exports, "TextToSnake", TextToSnake_fn);

    napi_value TextToCamel_fn;
    napi_create_function(env, NULL, 0, BindNode_TextToCamel, NULL, &TextToCamel_fn);
    napi_set_named_property(env, exports, "TextToCamel", TextToCamel_fn);

    napi_value TextToInteger_fn;
    napi_create_function(env, NULL, 0, BindNode_TextToInteger, NULL, &TextToInteger_fn);
    napi_set_named_property(env, exports, "TextToInteger", TextToInteger_fn);

    napi_value TextToFloat_fn;
    napi_create_function(env, NULL, 0, BindNode_TextToFloat, NULL, &TextToFloat_fn);
    napi_set_named_property(env, exports, "TextToFloat", TextToFloat_fn);

    napi_value DrawLine3D_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawLine3D, NULL, &DrawLine3D_fn);
    napi_set_named_property(env, exports, "DrawLine3D", DrawLine3D_fn);

    napi_value DrawPoint3D_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawPoint3D, NULL, &DrawPoint3D_fn);
    napi_set_named_property(env, exports, "DrawPoint3D", DrawPoint3D_fn);

    napi_value DrawCircle3D_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawCircle3D, NULL, &DrawCircle3D_fn);
    napi_set_named_property(env, exports, "DrawCircle3D", DrawCircle3D_fn);

    napi_value DrawTriangle3D_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawTriangle3D, NULL, &DrawTriangle3D_fn);
    napi_set_named_property(env, exports, "DrawTriangle3D", DrawTriangle3D_fn);

    napi_value DrawTriangleStrip3D_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawTriangleStrip3D, NULL, &DrawTriangleStrip3D_fn);
    napi_set_named_property(env, exports, "DrawTriangleStrip3D", DrawTriangleStrip3D_fn);

    napi_value DrawCube_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawCube, NULL, &DrawCube_fn);
    napi_set_named_property(env, exports, "DrawCube", DrawCube_fn);

    napi_value DrawCubeV_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawCubeV, NULL, &DrawCubeV_fn);
    napi_set_named_property(env, exports, "DrawCubeV", DrawCubeV_fn);

    napi_value DrawCubeWires_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawCubeWires, NULL, &DrawCubeWires_fn);
    napi_set_named_property(env, exports, "DrawCubeWires", DrawCubeWires_fn);

    napi_value DrawCubeWiresV_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawCubeWiresV, NULL, &DrawCubeWiresV_fn);
    napi_set_named_property(env, exports, "DrawCubeWiresV", DrawCubeWiresV_fn);

    napi_value DrawSphere_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawSphere, NULL, &DrawSphere_fn);
    napi_set_named_property(env, exports, "DrawSphere", DrawSphere_fn);

    napi_value DrawSphereEx_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawSphereEx, NULL, &DrawSphereEx_fn);
    napi_set_named_property(env, exports, "DrawSphereEx", DrawSphereEx_fn);

    napi_value DrawSphereWires_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawSphereWires, NULL, &DrawSphereWires_fn);
    napi_set_named_property(env, exports, "DrawSphereWires", DrawSphereWires_fn);

    napi_value DrawCylinder_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawCylinder, NULL, &DrawCylinder_fn);
    napi_set_named_property(env, exports, "DrawCylinder", DrawCylinder_fn);

    napi_value DrawCylinderEx_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawCylinderEx, NULL, &DrawCylinderEx_fn);
    napi_set_named_property(env, exports, "DrawCylinderEx", DrawCylinderEx_fn);

    napi_value DrawCylinderWires_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawCylinderWires, NULL, &DrawCylinderWires_fn);
    napi_set_named_property(env, exports, "DrawCylinderWires", DrawCylinderWires_fn);

    napi_value DrawCylinderWiresEx_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawCylinderWiresEx, NULL, &DrawCylinderWiresEx_fn);
    napi_set_named_property(env, exports, "DrawCylinderWiresEx", DrawCylinderWiresEx_fn);

    napi_value DrawCapsule_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawCapsule, NULL, &DrawCapsule_fn);
    napi_set_named_property(env, exports, "DrawCapsule", DrawCapsule_fn);

    napi_value DrawCapsuleWires_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawCapsuleWires, NULL, &DrawCapsuleWires_fn);
    napi_set_named_property(env, exports, "DrawCapsuleWires", DrawCapsuleWires_fn);

    napi_value DrawPlane_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawPlane, NULL, &DrawPlane_fn);
    napi_set_named_property(env, exports, "DrawPlane", DrawPlane_fn);

    napi_value DrawRay_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawRay, NULL, &DrawRay_fn);
    napi_set_named_property(env, exports, "DrawRay", DrawRay_fn);

    napi_value DrawGrid_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawGrid, NULL, &DrawGrid_fn);
    napi_set_named_property(env, exports, "DrawGrid", DrawGrid_fn);

    napi_value LoadModel_fn;
    napi_create_function(env, NULL, 0, BindNode_LoadModel, NULL, &LoadModel_fn);
    napi_set_named_property(env, exports, "LoadModel", LoadModel_fn);

    napi_value LoadModelFromMesh_fn;
    napi_create_function(env, NULL, 0, BindNode_LoadModelFromMesh, NULL, &LoadModelFromMesh_fn);
    napi_set_named_property(env, exports, "LoadModelFromMesh", LoadModelFromMesh_fn);

    napi_value IsModelValid_fn;
    napi_create_function(env, NULL, 0, BindNode_IsModelValid, NULL, &IsModelValid_fn);
    napi_set_named_property(env, exports, "IsModelValid", IsModelValid_fn);

    napi_value UnloadModel_fn;
    napi_create_function(env, NULL, 0, BindNode_UnloadModel, NULL, &UnloadModel_fn);
    napi_set_named_property(env, exports, "UnloadModel", UnloadModel_fn);

    napi_value GetModelBoundingBox_fn;
    napi_create_function(env, NULL, 0, BindNode_GetModelBoundingBox, NULL, &GetModelBoundingBox_fn);
    napi_set_named_property(env, exports, "GetModelBoundingBox", GetModelBoundingBox_fn);

    napi_value DrawModel_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawModel, NULL, &DrawModel_fn);
    napi_set_named_property(env, exports, "DrawModel", DrawModel_fn);

    napi_value DrawModelEx_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawModelEx, NULL, &DrawModelEx_fn);
    napi_set_named_property(env, exports, "DrawModelEx", DrawModelEx_fn);

    napi_value DrawModelWires_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawModelWires, NULL, &DrawModelWires_fn);
    napi_set_named_property(env, exports, "DrawModelWires", DrawModelWires_fn);

    napi_value DrawModelWiresEx_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawModelWiresEx, NULL, &DrawModelWiresEx_fn);
    napi_set_named_property(env, exports, "DrawModelWiresEx", DrawModelWiresEx_fn);

    napi_value DrawModelPoints_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawModelPoints, NULL, &DrawModelPoints_fn);
    napi_set_named_property(env, exports, "DrawModelPoints", DrawModelPoints_fn);

    napi_value DrawModelPointsEx_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawModelPointsEx, NULL, &DrawModelPointsEx_fn);
    napi_set_named_property(env, exports, "DrawModelPointsEx", DrawModelPointsEx_fn);

    napi_value DrawBoundingBox_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawBoundingBox, NULL, &DrawBoundingBox_fn);
    napi_set_named_property(env, exports, "DrawBoundingBox", DrawBoundingBox_fn);

    napi_value DrawBillboard_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawBillboard, NULL, &DrawBillboard_fn);
    napi_set_named_property(env, exports, "DrawBillboard", DrawBillboard_fn);

    napi_value DrawBillboardRec_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawBillboardRec, NULL, &DrawBillboardRec_fn);
    napi_set_named_property(env, exports, "DrawBillboardRec", DrawBillboardRec_fn);

    napi_value DrawBillboardPro_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawBillboardPro, NULL, &DrawBillboardPro_fn);
    napi_set_named_property(env, exports, "DrawBillboardPro", DrawBillboardPro_fn);

    napi_value UploadMesh_fn;
    napi_create_function(env, NULL, 0, BindNode_UploadMesh, NULL, &UploadMesh_fn);
    napi_set_named_property(env, exports, "UploadMesh", UploadMesh_fn);

    napi_value UpdateMeshBuffer_fn;
    napi_create_function(env, NULL, 0, BindNode_UpdateMeshBuffer, NULL, &UpdateMeshBuffer_fn);
    napi_set_named_property(env, exports, "UpdateMeshBuffer", UpdateMeshBuffer_fn);

    napi_value UnloadMesh_fn;
    napi_create_function(env, NULL, 0, BindNode_UnloadMesh, NULL, &UnloadMesh_fn);
    napi_set_named_property(env, exports, "UnloadMesh", UnloadMesh_fn);

    napi_value DrawMesh_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawMesh, NULL, &DrawMesh_fn);
    napi_set_named_property(env, exports, "DrawMesh", DrawMesh_fn);

    napi_value DrawMeshInstanced_fn;
    napi_create_function(env, NULL, 0, BindNode_DrawMeshInstanced, NULL, &DrawMeshInstanced_fn);
    napi_set_named_property(env, exports, "DrawMeshInstanced", DrawMeshInstanced_fn);

    napi_value GetMeshBoundingBox_fn;
    napi_create_function(env, NULL, 0, BindNode_GetMeshBoundingBox, NULL, &GetMeshBoundingBox_fn);
    napi_set_named_property(env, exports, "GetMeshBoundingBox", GetMeshBoundingBox_fn);

    napi_value GenMeshTangents_fn;
    napi_create_function(env, NULL, 0, BindNode_GenMeshTangents, NULL, &GenMeshTangents_fn);
    napi_set_named_property(env, exports, "GenMeshTangents", GenMeshTangents_fn);

    napi_value ExportMesh_fn;
    napi_create_function(env, NULL, 0, BindNode_ExportMesh, NULL, &ExportMesh_fn);
    napi_set_named_property(env, exports, "ExportMesh", ExportMesh_fn);

    napi_value ExportMeshAsCode_fn;
    napi_create_function(env, NULL, 0, BindNode_ExportMeshAsCode, NULL, &ExportMeshAsCode_fn);
    napi_set_named_property(env, exports, "ExportMeshAsCode", ExportMeshAsCode_fn);

    napi_value GenMeshPoly_fn;
    napi_create_function(env, NULL, 0, BindNode_GenMeshPoly, NULL, &GenMeshPoly_fn);
    napi_set_named_property(env, exports, "GenMeshPoly", GenMeshPoly_fn);

    napi_value GenMeshPlane_fn;
    napi_create_function(env, NULL, 0, BindNode_GenMeshPlane, NULL, &GenMeshPlane_fn);
    napi_set_named_property(env, exports, "GenMeshPlane", GenMeshPlane_fn);

    napi_value GenMeshCube_fn;
    napi_create_function(env, NULL, 0, BindNode_GenMeshCube, NULL, &GenMeshCube_fn);
    napi_set_named_property(env, exports, "GenMeshCube", GenMeshCube_fn);

    napi_value GenMeshSphere_fn;
    napi_create_function(env, NULL, 0, BindNode_GenMeshSphere, NULL, &GenMeshSphere_fn);
    napi_set_named_property(env, exports, "GenMeshSphere", GenMeshSphere_fn);

    napi_value GenMeshHemiSphere_fn;
    napi_create_function(env, NULL, 0, BindNode_GenMeshHemiSphere, NULL, &GenMeshHemiSphere_fn);
    napi_set_named_property(env, exports, "GenMeshHemiSphere", GenMeshHemiSphere_fn);

    napi_value GenMeshCylinder_fn;
    napi_create_function(env, NULL, 0, BindNode_GenMeshCylinder, NULL, &GenMeshCylinder_fn);
    napi_set_named_property(env, exports, "GenMeshCylinder", GenMeshCylinder_fn);

    napi_value GenMeshCone_fn;
    napi_create_function(env, NULL, 0, BindNode_GenMeshCone, NULL, &GenMeshCone_fn);
    napi_set_named_property(env, exports, "GenMeshCone", GenMeshCone_fn);

    napi_value GenMeshTorus_fn;
    napi_create_function(env, NULL, 0, BindNode_GenMeshTorus, NULL, &GenMeshTorus_fn);
    napi_set_named_property(env, exports, "GenMeshTorus", GenMeshTorus_fn);

    napi_value GenMeshKnot_fn;
    napi_create_function(env, NULL, 0, BindNode_GenMeshKnot, NULL, &GenMeshKnot_fn);
    napi_set_named_property(env, exports, "GenMeshKnot", GenMeshKnot_fn);

    napi_value GenMeshHeightmap_fn;
    napi_create_function(env, NULL, 0, BindNode_GenMeshHeightmap, NULL, &GenMeshHeightmap_fn);
    napi_set_named_property(env, exports, "GenMeshHeightmap", GenMeshHeightmap_fn);

    napi_value GenMeshCubicmap_fn;
    napi_create_function(env, NULL, 0, BindNode_GenMeshCubicmap, NULL, &GenMeshCubicmap_fn);
    napi_set_named_property(env, exports, "GenMeshCubicmap", GenMeshCubicmap_fn);

    napi_value LoadMaterials_fn;
    napi_create_function(env, NULL, 0, BindNode_LoadMaterials, NULL, &LoadMaterials_fn);
    napi_set_named_property(env, exports, "LoadMaterials", LoadMaterials_fn);

    napi_value LoadMaterialDefault_fn;
    napi_create_function(env, NULL, 0, BindNode_LoadMaterialDefault, NULL, &LoadMaterialDefault_fn);
    napi_set_named_property(env, exports, "LoadMaterialDefault", LoadMaterialDefault_fn);

    napi_value IsMaterialValid_fn;
    napi_create_function(env, NULL, 0, BindNode_IsMaterialValid, NULL, &IsMaterialValid_fn);
    napi_set_named_property(env, exports, "IsMaterialValid", IsMaterialValid_fn);

    napi_value UnloadMaterial_fn;
    napi_create_function(env, NULL, 0, BindNode_UnloadMaterial, NULL, &UnloadMaterial_fn);
    napi_set_named_property(env, exports, "UnloadMaterial", UnloadMaterial_fn);

    napi_value SetMaterialTexture_fn;
    napi_create_function(env, NULL, 0, BindNode_SetMaterialTexture, NULL, &SetMaterialTexture_fn);
    napi_set_named_property(env, exports, "SetMaterialTexture", SetMaterialTexture_fn);

    napi_value SetModelMeshMaterial_fn;
    napi_create_function(env, NULL, 0, BindNode_SetModelMeshMaterial, NULL, &SetModelMeshMaterial_fn);
    napi_set_named_property(env, exports, "SetModelMeshMaterial", SetModelMeshMaterial_fn);

    napi_value LoadModelAnimations_fn;
    napi_create_function(env, NULL, 0, BindNode_LoadModelAnimations, NULL, &LoadModelAnimations_fn);
    napi_set_named_property(env, exports, "LoadModelAnimations", LoadModelAnimations_fn);

    napi_value UpdateModelAnimation_fn;
    napi_create_function(env, NULL, 0, BindNode_UpdateModelAnimation, NULL, &UpdateModelAnimation_fn);
    napi_set_named_property(env, exports, "UpdateModelAnimation", UpdateModelAnimation_fn);

    napi_value UpdateModelAnimationBones_fn;
    napi_create_function(env, NULL, 0, BindNode_UpdateModelAnimationBones, NULL, &UpdateModelAnimationBones_fn);
    napi_set_named_property(env, exports, "UpdateModelAnimationBones", UpdateModelAnimationBones_fn);

    napi_value UnloadModelAnimation_fn;
    napi_create_function(env, NULL, 0, BindNode_UnloadModelAnimation, NULL, &UnloadModelAnimation_fn);
    napi_set_named_property(env, exports, "UnloadModelAnimation", UnloadModelAnimation_fn);

    napi_value UnloadModelAnimations_fn;
    napi_create_function(env, NULL, 0, BindNode_UnloadModelAnimations, NULL, &UnloadModelAnimations_fn);
    napi_set_named_property(env, exports, "UnloadModelAnimations", UnloadModelAnimations_fn);

    napi_value IsModelAnimationValid_fn;
    napi_create_function(env, NULL, 0, BindNode_IsModelAnimationValid, NULL, &IsModelAnimationValid_fn);
    napi_set_named_property(env, exports, "IsModelAnimationValid", IsModelAnimationValid_fn);

    napi_value CheckCollisionSpheres_fn;
    napi_create_function(env, NULL, 0, BindNode_CheckCollisionSpheres, NULL, &CheckCollisionSpheres_fn);
    napi_set_named_property(env, exports, "CheckCollisionSpheres", CheckCollisionSpheres_fn);

    napi_value CheckCollisionBoxes_fn;
    napi_create_function(env, NULL, 0, BindNode_CheckCollisionBoxes, NULL, &CheckCollisionBoxes_fn);
    napi_set_named_property(env, exports, "CheckCollisionBoxes", CheckCollisionBoxes_fn);

    napi_value CheckCollisionBoxSphere_fn;
    napi_create_function(env, NULL, 0, BindNode_CheckCollisionBoxSphere, NULL, &CheckCollisionBoxSphere_fn);
    napi_set_named_property(env, exports, "CheckCollisionBoxSphere", CheckCollisionBoxSphere_fn);

    napi_value GetRayCollisionSphere_fn;
    napi_create_function(env, NULL, 0, BindNode_GetRayCollisionSphere, NULL, &GetRayCollisionSphere_fn);
    napi_set_named_property(env, exports, "GetRayCollisionSphere", GetRayCollisionSphere_fn);

    napi_value GetRayCollisionBox_fn;
    napi_create_function(env, NULL, 0, BindNode_GetRayCollisionBox, NULL, &GetRayCollisionBox_fn);
    napi_set_named_property(env, exports, "GetRayCollisionBox", GetRayCollisionBox_fn);

    napi_value GetRayCollisionMesh_fn;
    napi_create_function(env, NULL, 0, BindNode_GetRayCollisionMesh, NULL, &GetRayCollisionMesh_fn);
    napi_set_named_property(env, exports, "GetRayCollisionMesh", GetRayCollisionMesh_fn);

    napi_value GetRayCollisionTriangle_fn;
    napi_create_function(env, NULL, 0, BindNode_GetRayCollisionTriangle, NULL, &GetRayCollisionTriangle_fn);
    napi_set_named_property(env, exports, "GetRayCollisionTriangle", GetRayCollisionTriangle_fn);

    napi_value GetRayCollisionQuad_fn;
    napi_create_function(env, NULL, 0, BindNode_GetRayCollisionQuad, NULL, &GetRayCollisionQuad_fn);
    napi_set_named_property(env, exports, "GetRayCollisionQuad", GetRayCollisionQuad_fn);

    napi_value InitAudioDevice_fn;
    napi_create_function(env, NULL, 0, BindNode_InitAudioDevice, NULL, &InitAudioDevice_fn);
    napi_set_named_property(env, exports, "InitAudioDevice", InitAudioDevice_fn);

    napi_value CloseAudioDevice_fn;
    napi_create_function(env, NULL, 0, BindNode_CloseAudioDevice, NULL, &CloseAudioDevice_fn);
    napi_set_named_property(env, exports, "CloseAudioDevice", CloseAudioDevice_fn);

    napi_value IsAudioDeviceReady_fn;
    napi_create_function(env, NULL, 0, BindNode_IsAudioDeviceReady, NULL, &IsAudioDeviceReady_fn);
    napi_set_named_property(env, exports, "IsAudioDeviceReady", IsAudioDeviceReady_fn);

    napi_value SetMasterVolume_fn;
    napi_create_function(env, NULL, 0, BindNode_SetMasterVolume, NULL, &SetMasterVolume_fn);
    napi_set_named_property(env, exports, "SetMasterVolume", SetMasterVolume_fn);

    napi_value GetMasterVolume_fn;
    napi_create_function(env, NULL, 0, BindNode_GetMasterVolume, NULL, &GetMasterVolume_fn);
    napi_set_named_property(env, exports, "GetMasterVolume", GetMasterVolume_fn);

    napi_value LoadWave_fn;
    napi_create_function(env, NULL, 0, BindNode_LoadWave, NULL, &LoadWave_fn);
    napi_set_named_property(env, exports, "LoadWave", LoadWave_fn);

    napi_value LoadWaveFromMemory_fn;
    napi_create_function(env, NULL, 0, BindNode_LoadWaveFromMemory, NULL, &LoadWaveFromMemory_fn);
    napi_set_named_property(env, exports, "LoadWaveFromMemory", LoadWaveFromMemory_fn);

    napi_value IsWaveValid_fn;
    napi_create_function(env, NULL, 0, BindNode_IsWaveValid, NULL, &IsWaveValid_fn);
    napi_set_named_property(env, exports, "IsWaveValid", IsWaveValid_fn);

    napi_value LoadSound_fn;
    napi_create_function(env, NULL, 0, BindNode_LoadSound, NULL, &LoadSound_fn);
    napi_set_named_property(env, exports, "LoadSound", LoadSound_fn);

    napi_value LoadSoundFromWave_fn;
    napi_create_function(env, NULL, 0, BindNode_LoadSoundFromWave, NULL, &LoadSoundFromWave_fn);
    napi_set_named_property(env, exports, "LoadSoundFromWave", LoadSoundFromWave_fn);

    napi_value LoadSoundAlias_fn;
    napi_create_function(env, NULL, 0, BindNode_LoadSoundAlias, NULL, &LoadSoundAlias_fn);
    napi_set_named_property(env, exports, "LoadSoundAlias", LoadSoundAlias_fn);

    napi_value IsSoundValid_fn;
    napi_create_function(env, NULL, 0, BindNode_IsSoundValid, NULL, &IsSoundValid_fn);
    napi_set_named_property(env, exports, "IsSoundValid", IsSoundValid_fn);

    napi_value UpdateSound_fn;
    napi_create_function(env, NULL, 0, BindNode_UpdateSound, NULL, &UpdateSound_fn);
    napi_set_named_property(env, exports, "UpdateSound", UpdateSound_fn);

    napi_value UnloadWave_fn;
    napi_create_function(env, NULL, 0, BindNode_UnloadWave, NULL, &UnloadWave_fn);
    napi_set_named_property(env, exports, "UnloadWave", UnloadWave_fn);

    napi_value UnloadSound_fn;
    napi_create_function(env, NULL, 0, BindNode_UnloadSound, NULL, &UnloadSound_fn);
    napi_set_named_property(env, exports, "UnloadSound", UnloadSound_fn);

    napi_value UnloadSoundAlias_fn;
    napi_create_function(env, NULL, 0, BindNode_UnloadSoundAlias, NULL, &UnloadSoundAlias_fn);
    napi_set_named_property(env, exports, "UnloadSoundAlias", UnloadSoundAlias_fn);

    napi_value ExportWave_fn;
    napi_create_function(env, NULL, 0, BindNode_ExportWave, NULL, &ExportWave_fn);
    napi_set_named_property(env, exports, "ExportWave", ExportWave_fn);

    napi_value ExportWaveAsCode_fn;
    napi_create_function(env, NULL, 0, BindNode_ExportWaveAsCode, NULL, &ExportWaveAsCode_fn);
    napi_set_named_property(env, exports, "ExportWaveAsCode", ExportWaveAsCode_fn);

    napi_value PlaySound_fn;
    napi_create_function(env, NULL, 0, BindNode_PlaySound, NULL, &PlaySound_fn);
    napi_set_named_property(env, exports, "PlaySound", PlaySound_fn);

    napi_value StopSound_fn;
    napi_create_function(env, NULL, 0, BindNode_StopSound, NULL, &StopSound_fn);
    napi_set_named_property(env, exports, "StopSound", StopSound_fn);

    napi_value PauseSound_fn;
    napi_create_function(env, NULL, 0, BindNode_PauseSound, NULL, &PauseSound_fn);
    napi_set_named_property(env, exports, "PauseSound", PauseSound_fn);

    napi_value ResumeSound_fn;
    napi_create_function(env, NULL, 0, BindNode_ResumeSound, NULL, &ResumeSound_fn);
    napi_set_named_property(env, exports, "ResumeSound", ResumeSound_fn);

    napi_value IsSoundPlaying_fn;
    napi_create_function(env, NULL, 0, BindNode_IsSoundPlaying, NULL, &IsSoundPlaying_fn);
    napi_set_named_property(env, exports, "IsSoundPlaying", IsSoundPlaying_fn);

    napi_value SetSoundVolume_fn;
    napi_create_function(env, NULL, 0, BindNode_SetSoundVolume, NULL, &SetSoundVolume_fn);
    napi_set_named_property(env, exports, "SetSoundVolume", SetSoundVolume_fn);

    napi_value SetSoundPitch_fn;
    napi_create_function(env, NULL, 0, BindNode_SetSoundPitch, NULL, &SetSoundPitch_fn);
    napi_set_named_property(env, exports, "SetSoundPitch", SetSoundPitch_fn);

    napi_value SetSoundPan_fn;
    napi_create_function(env, NULL, 0, BindNode_SetSoundPan, NULL, &SetSoundPan_fn);
    napi_set_named_property(env, exports, "SetSoundPan", SetSoundPan_fn);

    napi_value WaveCopy_fn;
    napi_create_function(env, NULL, 0, BindNode_WaveCopy, NULL, &WaveCopy_fn);
    napi_set_named_property(env, exports, "WaveCopy", WaveCopy_fn);

    napi_value WaveCrop_fn;
    napi_create_function(env, NULL, 0, BindNode_WaveCrop, NULL, &WaveCrop_fn);
    napi_set_named_property(env, exports, "WaveCrop", WaveCrop_fn);

    napi_value WaveFormat_fn;
    napi_create_function(env, NULL, 0, BindNode_WaveFormat, NULL, &WaveFormat_fn);
    napi_set_named_property(env, exports, "WaveFormat", WaveFormat_fn);

    napi_value LoadWaveSamples_fn;
    napi_create_function(env, NULL, 0, BindNode_LoadWaveSamples, NULL, &LoadWaveSamples_fn);
    napi_set_named_property(env, exports, "LoadWaveSamples", LoadWaveSamples_fn);

    napi_value UnloadWaveSamples_fn;
    napi_create_function(env, NULL, 0, BindNode_UnloadWaveSamples, NULL, &UnloadWaveSamples_fn);
    napi_set_named_property(env, exports, "UnloadWaveSamples", UnloadWaveSamples_fn);

    napi_value LoadMusicStream_fn;
    napi_create_function(env, NULL, 0, BindNode_LoadMusicStream, NULL, &LoadMusicStream_fn);
    napi_set_named_property(env, exports, "LoadMusicStream", LoadMusicStream_fn);

    napi_value LoadMusicStreamFromMemory_fn;
    napi_create_function(env, NULL, 0, BindNode_LoadMusicStreamFromMemory, NULL, &LoadMusicStreamFromMemory_fn);
    napi_set_named_property(env, exports, "LoadMusicStreamFromMemory", LoadMusicStreamFromMemory_fn);

    napi_value IsMusicValid_fn;
    napi_create_function(env, NULL, 0, BindNode_IsMusicValid, NULL, &IsMusicValid_fn);
    napi_set_named_property(env, exports, "IsMusicValid", IsMusicValid_fn);

    napi_value UnloadMusicStream_fn;
    napi_create_function(env, NULL, 0, BindNode_UnloadMusicStream, NULL, &UnloadMusicStream_fn);
    napi_set_named_property(env, exports, "UnloadMusicStream", UnloadMusicStream_fn);

    napi_value PlayMusicStream_fn;
    napi_create_function(env, NULL, 0, BindNode_PlayMusicStream, NULL, &PlayMusicStream_fn);
    napi_set_named_property(env, exports, "PlayMusicStream", PlayMusicStream_fn);

    napi_value IsMusicStreamPlaying_fn;
    napi_create_function(env, NULL, 0, BindNode_IsMusicStreamPlaying, NULL, &IsMusicStreamPlaying_fn);
    napi_set_named_property(env, exports, "IsMusicStreamPlaying", IsMusicStreamPlaying_fn);

    napi_value UpdateMusicStream_fn;
    napi_create_function(env, NULL, 0, BindNode_UpdateMusicStream, NULL, &UpdateMusicStream_fn);
    napi_set_named_property(env, exports, "UpdateMusicStream", UpdateMusicStream_fn);

    napi_value StopMusicStream_fn;
    napi_create_function(env, NULL, 0, BindNode_StopMusicStream, NULL, &StopMusicStream_fn);
    napi_set_named_property(env, exports, "StopMusicStream", StopMusicStream_fn);

    napi_value PauseMusicStream_fn;
    napi_create_function(env, NULL, 0, BindNode_PauseMusicStream, NULL, &PauseMusicStream_fn);
    napi_set_named_property(env, exports, "PauseMusicStream", PauseMusicStream_fn);

    napi_value ResumeMusicStream_fn;
    napi_create_function(env, NULL, 0, BindNode_ResumeMusicStream, NULL, &ResumeMusicStream_fn);
    napi_set_named_property(env, exports, "ResumeMusicStream", ResumeMusicStream_fn);

    napi_value SeekMusicStream_fn;
    napi_create_function(env, NULL, 0, BindNode_SeekMusicStream, NULL, &SeekMusicStream_fn);
    napi_set_named_property(env, exports, "SeekMusicStream", SeekMusicStream_fn);

    napi_value SetMusicVolume_fn;
    napi_create_function(env, NULL, 0, BindNode_SetMusicVolume, NULL, &SetMusicVolume_fn);
    napi_set_named_property(env, exports, "SetMusicVolume", SetMusicVolume_fn);

    napi_value SetMusicPitch_fn;
    napi_create_function(env, NULL, 0, BindNode_SetMusicPitch, NULL, &SetMusicPitch_fn);
    napi_set_named_property(env, exports, "SetMusicPitch", SetMusicPitch_fn);

    napi_value SetMusicPan_fn;
    napi_create_function(env, NULL, 0, BindNode_SetMusicPan, NULL, &SetMusicPan_fn);
    napi_set_named_property(env, exports, "SetMusicPan", SetMusicPan_fn);

    napi_value GetMusicTimeLength_fn;
    napi_create_function(env, NULL, 0, BindNode_GetMusicTimeLength, NULL, &GetMusicTimeLength_fn);
    napi_set_named_property(env, exports, "GetMusicTimeLength", GetMusicTimeLength_fn);

    napi_value GetMusicTimePlayed_fn;
    napi_create_function(env, NULL, 0, BindNode_GetMusicTimePlayed, NULL, &GetMusicTimePlayed_fn);
    napi_set_named_property(env, exports, "GetMusicTimePlayed", GetMusicTimePlayed_fn);

    napi_value LoadAudioStream_fn;
    napi_create_function(env, NULL, 0, BindNode_LoadAudioStream, NULL, &LoadAudioStream_fn);
    napi_set_named_property(env, exports, "LoadAudioStream", LoadAudioStream_fn);

    napi_value IsAudioStreamValid_fn;
    napi_create_function(env, NULL, 0, BindNode_IsAudioStreamValid, NULL, &IsAudioStreamValid_fn);
    napi_set_named_property(env, exports, "IsAudioStreamValid", IsAudioStreamValid_fn);

    napi_value UnloadAudioStream_fn;
    napi_create_function(env, NULL, 0, BindNode_UnloadAudioStream, NULL, &UnloadAudioStream_fn);
    napi_set_named_property(env, exports, "UnloadAudioStream", UnloadAudioStream_fn);

    napi_value UpdateAudioStream_fn;
    napi_create_function(env, NULL, 0, BindNode_UpdateAudioStream, NULL, &UpdateAudioStream_fn);
    napi_set_named_property(env, exports, "UpdateAudioStream", UpdateAudioStream_fn);

    napi_value IsAudioStreamProcessed_fn;
    napi_create_function(env, NULL, 0, BindNode_IsAudioStreamProcessed, NULL, &IsAudioStreamProcessed_fn);
    napi_set_named_property(env, exports, "IsAudioStreamProcessed", IsAudioStreamProcessed_fn);

    napi_value PlayAudioStream_fn;
    napi_create_function(env, NULL, 0, BindNode_PlayAudioStream, NULL, &PlayAudioStream_fn);
    napi_set_named_property(env, exports, "PlayAudioStream", PlayAudioStream_fn);

    napi_value PauseAudioStream_fn;
    napi_create_function(env, NULL, 0, BindNode_PauseAudioStream, NULL, &PauseAudioStream_fn);
    napi_set_named_property(env, exports, "PauseAudioStream", PauseAudioStream_fn);

    napi_value ResumeAudioStream_fn;
    napi_create_function(env, NULL, 0, BindNode_ResumeAudioStream, NULL, &ResumeAudioStream_fn);
    napi_set_named_property(env, exports, "ResumeAudioStream", ResumeAudioStream_fn);

    napi_value IsAudioStreamPlaying_fn;
    napi_create_function(env, NULL, 0, BindNode_IsAudioStreamPlaying, NULL, &IsAudioStreamPlaying_fn);
    napi_set_named_property(env, exports, "IsAudioStreamPlaying", IsAudioStreamPlaying_fn);

    napi_value StopAudioStream_fn;
    napi_create_function(env, NULL, 0, BindNode_StopAudioStream, NULL, &StopAudioStream_fn);
    napi_set_named_property(env, exports, "StopAudioStream", StopAudioStream_fn);

    napi_value SetAudioStreamVolume_fn;
    napi_create_function(env, NULL, 0, BindNode_SetAudioStreamVolume, NULL, &SetAudioStreamVolume_fn);
    napi_set_named_property(env, exports, "SetAudioStreamVolume", SetAudioStreamVolume_fn);

    napi_value SetAudioStreamPitch_fn;
    napi_create_function(env, NULL, 0, BindNode_SetAudioStreamPitch, NULL, &SetAudioStreamPitch_fn);
    napi_set_named_property(env, exports, "SetAudioStreamPitch", SetAudioStreamPitch_fn);

    napi_value SetAudioStreamPan_fn;
    napi_create_function(env, NULL, 0, BindNode_SetAudioStreamPan, NULL, &SetAudioStreamPan_fn);
    napi_set_named_property(env, exports, "SetAudioStreamPan", SetAudioStreamPan_fn);

    napi_value SetAudioStreamBufferSizeDefault_fn;
    napi_create_function(env, NULL, 0, BindNode_SetAudioStreamBufferSizeDefault, NULL, &SetAudioStreamBufferSizeDefault_fn);
    napi_set_named_property(env, exports, "SetAudioStreamBufferSizeDefault", SetAudioStreamBufferSizeDefault_fn);

    napi_value SetAudioStreamCallback_fn;
    napi_create_function(env, NULL, 0, BindNode_SetAudioStreamCallback, NULL, &SetAudioStreamCallback_fn);
    napi_set_named_property(env, exports, "SetAudioStreamCallback", SetAudioStreamCallback_fn);

    napi_value AttachAudioStreamProcessor_fn;
    napi_create_function(env, NULL, 0, BindNode_AttachAudioStreamProcessor, NULL, &AttachAudioStreamProcessor_fn);
    napi_set_named_property(env, exports, "AttachAudioStreamProcessor", AttachAudioStreamProcessor_fn);

    napi_value DetachAudioStreamProcessor_fn;
    napi_create_function(env, NULL, 0, BindNode_DetachAudioStreamProcessor, NULL, &DetachAudioStreamProcessor_fn);
    napi_set_named_property(env, exports, "DetachAudioStreamProcessor", DetachAudioStreamProcessor_fn);

    napi_value AttachAudioMixedProcessor_fn;
    napi_create_function(env, NULL, 0, BindNode_AttachAudioMixedProcessor, NULL, &AttachAudioMixedProcessor_fn);
    napi_set_named_property(env, exports, "AttachAudioMixedProcessor", AttachAudioMixedProcessor_fn);

    napi_value DetachAudioMixedProcessor_fn;
    napi_create_function(env, NULL, 0, BindNode_DetachAudioMixedProcessor, NULL, &DetachAudioMixedProcessor_fn);
    napi_set_named_property(env, exports, "DetachAudioMixedProcessor", DetachAudioMixedProcessor_fn);

    return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, Init)