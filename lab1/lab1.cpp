#include <GL/glut.h>
#include <iostream>
#include <cstdlib> // For rand()
using namespace std;

int xCenter = 320, yCenter = 240; // Center of the screen

void myinit(void)
{
    glClearColor(0.5, 0.5, 0.5, 1.0); // Windows 98 background gray
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void setPixel(GLint x, GLint y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void drawDesktop()
{
    glColor3f(0.4, 0.6, 0.9); // Light blue for desktop
    glBegin(GL_POLYGON);
    glVertex2i(0, 0);
    glVertex2i(640, 0);
    glVertex2i(640, 480);
    glVertex2i(0, 480);
    glEnd();

    glColor3f(0.1, 0.1, 0.1); // Dark gray for window outlines
    glBegin(GL_LINE_LOOP);
    glVertex2i(100, 100);
    glVertex2i(300, 100);
    glVertex2i(300, 300);
    glVertex2i(100, 300);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2i(400, 150);
    glVertex2i(600, 150);
    glVertex2i(600, 350);
    glVertex2i(400, 350);
    glEnd();

    glColor3f(0.8, 0.8, 0.8); // Light gray for icons
    for (int i = 0; i < 5; ++i)
    {
        glBegin(GL_POLYGON);
        glVertex2i(50 + i * 100, 50);
        glVertex2i(90 + i * 100, 50);
        glVertex2i(90 + i * 100, 90);
        glVertex2i(50 + i * 100, 90);
        glEnd();
    }

    glColor3f(0.2, 0.2, 0.2); // Dark gray for taskbar
    glBegin(GL_POLYGON);
    glVertex2i(0, 0);
    glVertex2i(640, 0);
    glVertex2i(640, 30);
    glVertex2i(0, 30);
    glEnd();

    glColor3f(0.5, 0.5, 0.5); // Light gray for Start button
    glBegin(GL_POLYGON);
    glVertex2i(10, 5);
    glVertex2i(90, 5);
    glVertex2i(90, 25);
    glVertex2i(10, 25);
    glEnd();

    glColor3f(1.0, 1.0, 1.0); // White for Start text
    glRasterPos2i(25, 15);
    glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'S');
    glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 't');
    glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'a');
    glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'r');
    glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 't');

    glColor3f(1.0, 1.0, 1.0); // White for search icon
    glBegin(GL_TRIANGLES);
    glVertex2i(610, 10);
    glVertex2i(630, 25);
    glVertex2i(630, 5);
    glEnd();
}

void drawWindows98Logo()
{
    glColor3f(0.0, 0.0, 1.0); // Blue color for the logo
    glBegin(GL_POLYGON);
    glVertex2i(xCenter - 50, yCenter - 50);
    glVertex2i(xCenter + 50, yCenter - 50);
    glVertex2i(xCenter + 50, yCenter + 50);
    glVertex2i(xCenter - 50, yCenter + 50);
    glEnd();

    glColor3f(1.0, 1.0, 0.0); // Yellow color for the flag
    glBegin(GL_POLYGON);
    glVertex2i(xCenter - 30, yCenter - 40);
    glVertex2i(xCenter - 10, yCenter - 40);
    glVertex2i(xCenter - 10, yCenter + 40);
    glVertex2i(xCenter - 30, yCenter + 40);
    glEnd();

    glColor3f(1.0, 1.0, 1.0); // White color for the window
    glBegin(GL_POLYGON);
    glVertex2i(xCenter - 20, yCenter - 30);
    glVertex2i(xCenter + 10, yCenter - 30);
    glVertex2i(xCenter + 10, yCenter + 30);
    glVertex2i(xCenter - 20, yCenter + 30);
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    drawDesktop();
    drawWindows98Logo();

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(10, 10);
    glutCreateWindow("Windows 98 Simulation");
    myinit();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
