
# Raytracing Circle with SDL2

## Overview
This project is a simple raytracing program using SDL2 to draw a circle on a window. The circle follows the mouse cursor when you hold down any mouse button.

## Features
- Draws a circle at a specified position.
- The circle moves with the mouse when a mouse button is held down.
- The screen refreshes with each frame, erasing the previous circle.

## Dependencies
Ensure you have the following installed:
- SDL2
- GCC or any C compiler

On Linux, you can install SDL2 with:
```bash
sudo apt-get install libsdl2-dev
```

## Compilation
To compile the program, run:
```bash
gcc -o raytracing main.c -lSDL2 -lm
```
- `main.c` is the name of your source file.
- `-lSDL2` links the SDL2 library.
- `-lm` links the math library.

## Running the Program
Once compiled, run the program:
```bash
./raytracing
```

## How it Works
- **Circle struct:** Contains `x`, `y` (coordinates) and `r` (radius).
- **FillCircle function:** Iterates through a bounding box around the circle, checks if each pixel is within the circle’s radius, and draws it.
- **Main loop:**
  - Polls for events.
  - Updates circle position on mouse motion with a button held down.
  - Clears the screen and redraws the circle.

## Event Handling
- **SDL_QUIT:** Exits the program.
- **SDL_MOUSEMOTION:** Moves the circle to the mouse’s position if a mouse button is pressed.

## Known Issues
- The circle redraw uses a brute-force method. Optimization with Bresenham’s circle algorithm could improve performance.

## Future Improvements
- Add smooth animations.
- Implement color changing with keypresses.
- Optimize circle drawing.

## License
This project is licensed under the MIT License.

---

Enjoy experimenting with real-time graphics using SDL2!

