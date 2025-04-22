# Node-Raylib Examples

This directory contains examples of using node-raylib, a Node.js binding for the raylib game development library.

## Running Examples

To run an example, use:

```bash
node examples/example_name.js
```

For example:

```bash
node examples/core_basic_window.js
```

## Example Categories

### Core Examples

- `core_basic_window.js` - Basic raylib window creation and handling
- `core_input_keys.js` - Keyboard input handling
- `core_input_mouse.js` - Mouse input handling
- `core_random_values.js` - Generate random values
- `core_window_should_close.js` - Window closing confirmation logic
- `core_2d_camera.js` - 2D camera and basic controls
- `core_3d_camera_free.js` - 3D free camera controls
- `core_drop_files.js` - Drag and drop files handling
- `core_input_gamepad.js` - Gamepad input handling

### Shapes Examples

- `shapes_basic_shapes.js` - Drawing basic 2D shapes
- `shapes_colors_palette.js` - Color palette and picker
- `shapes_lines_bezier.js` - Drawing bezier lines
- `shapes_logo_raylib.js` - Draw raylib logo using shapes
- `shapes_rectangle_scaling.js` - Rectangle scaling with mouse
- `shapes_bouncing_ball.js` - Bouncing ball physics
- `shapes_following_eyes.js` - Interactive eyes that follow mouse pointer
- `shapes_collision_area.js` - Basic collision detection between rectangles

### Textures Examples

- `textures_logo_raylib.js` - Loading and drawing textures
- `textures_image_loading.js` - Image loading and texture creation
- `textures_image_text.js` - Image text drawing with TTF fonts
- `textures_background_scrolling.js` - Background scrolling and parallax
- `textures_blend_modes.js` - Texture blending modes
- `textures_draw_tiled.js` - Draw part of a texture tiled
- `textures_sprite_button.js` - Button with sprite animation
- `textures_sprite_explosion.js` - Sprite explosion animation
- `textures_bunnymark.js` - Performance benchmark with many sprites
- `textures_mouse_painting.js` - Interactive painting application

### Text Examples

- `text_format_text.js` - Formatting and displaying text
- `text_raylib_fonts.js` - Raylib fonts loading and usage
- `text_input_box.js` - Input box for text

### Models Examples

- `models_geometric_shapes.js` - Drawing 3D shapes (cube, sphere, etc.)
- `models_first_person_maze.js` - First person maze game using a cubemap
- `models_animation.js` - Loading and animating 3D models

### Audio Examples

- `audio_sound_loading.js` - Loading and playing audio files
- `audio_music_stream.js` - Streaming music playback

## Notes

- These examples have been ported from the original raylib C examples to JavaScript
- The API closely follows the original raylib design
- Make sure to check for the correct paths when loading resources (textures, fonts, etc.)
- The examples folder includes necessary resources in the `resources` subdirectory