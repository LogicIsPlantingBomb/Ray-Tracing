# Ray Tracing Simulation with SDL2

## Overview
This project is a simple ray tracing simulation built using C and SDL2. It visualizes light rays originating from a moving light source (represented as a circle) and how they interact with an object (another circle). The rays stop when they hit the object's surface, creating a basic shadow effect.

## Screenshot

![raytracing](https://github.com/user-attachments/assets/88daecc0-d828-40a1-a60d-6ab5ab186029)

## Features
- **Dynamic light source**: Move the light source using mouse motion.
- **Real-time rendering**: Rays are cast from the light source and stop when they collide with the object.
- **Simple ray-object intersection**: Uses distance checking to detect ray hits.

## Technologies Used
- **C**
- **SDL2**

## How to Run
1. Install SDL2:
   ```bash
   sudo apt-get install libsdl2-dev
   ```
2. Compile the program:
   ```bash
   gcc -o raytracing raytracing.c -lSDL2 -lm
   ```
3. Run the executable:
   ```bash
   ./raytracing
   ```

## Notes
This is a small part of a big project ,while the program simulates rays of light and their interaction with a circular object, it is **not** a full ray tracing engine. Proper ray tracing involves more complex physics — like calculating light reflection, refraction, and color blending — which this code does not cover. 

Instead, this is more of a basic **ray casting** demonstration, as it only traces rays from a single light source in straight lines and stops at the first object hit(which is a small part of **Ray Tracing**).

## To-Do
- Add support for multiple objects.
- Implement light reflection and refraction.
- Introduce color blending for more realistic lighting.

---
Feel free to add your own customizations and expand this project!

