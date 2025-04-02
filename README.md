# 3D Shapes in OpenGL

This project is an OpenGL program that allows users to render and manipulate different 3D shapes (cube). The program supports transformations such as rotation, scaling, translation, and shearing, as well as dynamic color changes.

## Features
- Render3D shaped Cube
- Rotate shapes along the X and Y axes
- Scale shapes up and down
- Translate (move) shapes in different directions
- Apply shearing transformations
- Change colors dynamically
- Reset transformations to default
- Switch between cube, sphere, and 3D triangle

## Controls
### Transformations
- **Rotation:**
  - Press **'w'** to rotate up
  - Press **'s'** to rotate down
  - Press **'a'** to rotate left
  - Press **'d'** to rotate right

- **Scaling:**
  - Press **'b'** to increase size
  - Press **'n'** to decrease size

- **Translation (Movement):**
  - Press **'i'** to move up
  - Press **'k'** to move down
  - Press **'j'** to move left
  - Press **'l'** to move right

- **Shearing:**
  - Press **'u'** to shear along X-axis positively
  - Press **'o'** to shear along X-axis negatively
  - Press **'y'** to shear along Y-axis positively
  - Press **'h'** to shear along Y-axis negatively

### Other Controls
- Press **'c'** to change the color of the shape
- Press **'q'** to reset all transformations

## Requirements
- OpenGL and GLUT library installed

## Compilation & Execution
Use the following command to compile and run the program:
```sh
 g++ your_file.cpp -o output -lGL -lGLU -lglut && ./output
```
![image](https://github.com/user-attachments/assets/29944801-6062-45db-b714-21ba178a0e18)

## Notes
- All transformations allow real-time manipulation using keyboard inputs.

Enjoy experimenting with 3D transformations in OpenGL! 🚀

