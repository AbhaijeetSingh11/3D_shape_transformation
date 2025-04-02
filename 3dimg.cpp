#include <GL/glut.h>
#include <stdlib.h>

float angleX = 30.0f, angleY = 30.0f, scale = 1.0f;
float transX = 0.0f, transY = 0.0f;
float shearX = 0.0f, shearY = 0.0f;
float colors[6][3] = {
    {1.0, 0.0, 0.0}, // Front face
    {0.0, 1.0, 0.0}, // Back face
    {0.0, 0.0, 1.0}, // Left face
    {1.0, 1.0, 0.0}, // Right face
    {0.0, 1.0, 1.0}, // Top face
    {1.0, 0.0, 1.0}  // Bottom face
};

void resetTransformations() {
    angleX = 30.0f;
    angleY = 30.0f;
    scale = 1.0f;
    transX = 0.0f;
    transY = 0.0f;
    shearX = 0.0f;
    shearY = 0.0f;
    glutPostRedisplay();
}

void changeColors() {
    for (int i = 0; i < 6; i++) {
        colors[i][0] = (float)rand() / RAND_MAX;
        colors[i][1] = (float)rand() / RAND_MAX;
        colors[i][2] = (float)rand() / RAND_MAX;
    }
    glutPostRedisplay();
}

void applyShearMatrix() {
    float shearMatrix[16] = {
        1, shearX, 0, 0,
        shearY, 1, 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1
    };
    glMultMatrixf(shearMatrix);
}

void drawCube() {
    glBegin(GL_QUADS);

    glColor3fv(colors[0]);
    glVertex3f(-0.5, -0.5, 0.5);
    glVertex3f(0.5, -0.5, 0.5);
    glVertex3f(0.5, 0.5, 0.5);
    glVertex3f(-0.5, 0.5, 0.5);

    glColor3fv(colors[1]);
    glVertex3f(-0.5, -0.5, -0.5);
    glVertex3f(0.5, -0.5, -0.5);
    glVertex3f(0.5, 0.5, -0.5);
    glVertex3f(-0.5, 0.5, -0.5);

    glColor3fv(colors[2]);
    glVertex3f(-0.5, -0.5, -0.5);
    glVertex3f(-0.5, -0.5, 0.5);
    glVertex3f(-0.5, 0.5, 0.5);
    glVertex3f(-0.5, 0.5, -0.5);

    glColor3fv(colors[3]);
    glVertex3f(0.5, -0.5, -0.5);
    glVertex3f(0.5, -0.5, 0.5);
    glVertex3f(0.5, 0.5, 0.5);
    glVertex3f(0.5, 0.5, -0.5);

    glColor3fv(colors[4]);
    glVertex3f(-0.5, 0.5, -0.5);
    glVertex3f(0.5, 0.5, -0.5);
    glVertex3f(0.5, 0.5, 0.5);
    glVertex3f(-0.5, 0.5, 0.5);

    glColor3fv(colors[5]);
    glVertex3f(-0.5, -0.5, -0.5);
    glVertex3f(0.5, -0.5, -0.5);
    glVertex3f(0.5, -0.5, 0.5);
    glVertex3f(-0.5, -0.5, 0.5);

    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(transX, transY, -2.5);
    glScalef(scale, scale, scale);
    applyShearMatrix();
    glRotatef(angleX, 1.0, 0.0, 0.0);
    glRotatef(angleY, 0.0, 1.0, 0.0);
    drawCube();
    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
    if (key == 'a') angleY -= 5.0;
    if (key == 'd') angleY += 5.0;
    if (key == 'w') angleX -= 5.0;
    if (key == 's') angleX += 5.0;
    if (key == 'b') scale += 0.1f;
    if (key == 'n' && scale > 0.1f) scale -= 0.1f;
    if (key == 'j') transX -= 0.1f;
    if (key == 'l') transX += 0.1f;
    if (key == 'i') transY += 0.1f;
    if (key == 'k') transY -= 0.1f;
    if (key == 'u') shearX += 0.1f;
    if (key == 'o') shearX -= 0.1f;
    if (key == 'y') shearY += 0.1f;
    if (key == 'h') shearY -= 0.1f;
    if (key == 'q') resetTransformations();
    if (key == 'c') changeColors();
    glutPostRedisplay();
}

void init() {
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 1.0, 1.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("3D Cube");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}