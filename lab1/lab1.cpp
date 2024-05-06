#include <GL/glut.h>
#include <iostream>
#include <cstdlib> // For rand()
#include <ctime>   // For getting current time
#include <iomanip> // For formatting time
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

   
    
    glColor3f(0.2, 0.2, 0.2); // Dark gray for taskbar
    glBegin(GL_POLYGON);
    glVertex2i(0, 0);
    glVertex2i(640, 0);
    glVertex2i(640, 30);
    glVertex2i(0, 30);
    glEnd();
    // Icon 1 (rectangle)
    glColor3f(0.8, 0.3, 0.3); // Red color for icon 1
    glBegin(GL_POLYGON);
    glVertex2i(40, 5);
    glVertex2i(80, 5);
    glVertex2i(80, 25);
    glVertex2i(40, 25);
    glEnd();

    // Icon 2 (rectangle)
    glColor3f(0.3, 0.8, 0.3); // Green color for icon 2
    glBegin(GL_POLYGON);
    glVertex2i(120, 5);
    glVertex2i(160, 5);
    glVertex2i(160, 25);
    glVertex2i(120, 25);
    glEnd();

    // Icon 3 (rectangle)
    glColor3f(0.3, 0.3, 0.8); // Blue color for icon 3
    glBegin(GL_POLYGON);
    glVertex2i(200, 5);
    glVertex2i(240, 5);
    glVertex2i(240, 25);
    glVertex2i(200, 25);
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
void drawSearchIcon()
{
    // Draw globe (circle)
    glColor3f(0.2, 0.7, 0.3); // Green color for globe
    glBegin(GL_TRIANGLE_FAN);
    glVertex2i(0, 0); // Center of the globe
    int numSegments = 50;
    for (int i = 0; i <= numSegments; ++i) {
        float angle = i * (2.0f * 3.14159f / numSegments);
        float x = 15 * cos(angle); // Radius of the globe
        float y = 15 * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();

    // Draw magnifying glass (handle)
    glColor3f(0.8, 0.8, 0.8); // Light gray for handle
    glBegin(GL_POLYGON);
    glVertex2i(-5, -20);
    glVertex2i(-5, 0);
    glVertex2i(5, 0);
    glVertex2i(5, -20);
    glEnd();

    // Draw magnifying glass (lens)
    glColor3f(0.8, 0.8, 0.8); // Light gray for lens
    glBegin(GL_LINE_LOOP);
    glVertex2i(-15, -5);
    glVertex2i(-5, -15);
    glVertex2i(5, -15);
    glVertex2i(15, -5);
    glVertex2i(15, 5);
    glVertex2i(5, 15);
    glVertex2i(-5, 15);
    glVertex2i(-15, 5);
    glEnd();

    // Draw text "Internet"
    glColor3f(1.0, 1.0, 1.0); // White color for text
    glRasterPos2i(-20, -30); // Position for text
    const char* text = "Internet";
    while (*text) {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, *text);
        ++text;
    }
}

void drawWindows98Logo()
{

    glColor3f(0.0, 0.0, 1.0); // Blue color for the logo
    glBegin(GL_POLYGON);
    glVertex2i(xCenter - 20, yCenter + 47); //top right
    glVertex2i(xCenter - 40, yCenter - 43  ); //bottom right
    glVertex2i(xCenter - 55, yCenter - 50  ); //bottom left
    glVertex2i(xCenter - 35, yCenter + 40  ); //top left

    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(xCenter - 10, yCenter + 52  );
    glVertex2i(xCenter - 30, yCenter - 38  );
    glVertex2i(xCenter - 40, yCenter - 43  );
    glVertex2i(xCenter - 20, yCenter + 47  );
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(xCenter, yCenter + 57  );
    glVertex2i(xCenter - 20, yCenter - 33  );
    glVertex2i(xCenter - 30, yCenter - 38  );
    glVertex2i(xCenter - 10, yCenter + 52  );
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(xCenter + 10, yCenter + 58  );
    glVertex2i(xCenter - 10, yCenter - 32  );
    glVertex2i(xCenter - 20, yCenter - 33  );
    glVertex2i(xCenter, yCenter + 57  );
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(xCenter + 20, yCenter + 55  );
    glVertex2i(xCenter, yCenter - 35  );
    glVertex2i(xCenter - 10, yCenter - 32  );
    glVertex2i(xCenter + 10, yCenter + 58  );
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(xCenter + 35, yCenter + 45  );
    glVertex2i(xCenter + 15, yCenter - 45  );
    glVertex2i(xCenter, yCenter - 35  );
    glVertex2i(xCenter + 20, yCenter + 55  );
    glEnd();


    int shifty = 100;
    int shiftx = 20;
    glColor3f(0.929, 0.329, 0.023); // red color for the logo
    glBegin(GL_POLYGON);
    glVertex2i(xCenter - 20 +shiftx, yCenter + 47 + shifty); //top right
    glVertex2i(xCenter - 40 + shiftx, yCenter - 43 + shifty); //bottom right
    glVertex2i(xCenter - 55 + shiftx, yCenter - 50 + shifty); //bottom left
    glVertex2i(xCenter - 35 + shiftx, yCenter + 40 + shifty); //top left

    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(xCenter - 10 + shiftx, yCenter + 52 + shifty);
    glVertex2i(xCenter - 30 + shiftx, yCenter - 38 + shifty);
    glVertex2i(xCenter - 40 + shiftx, yCenter - 43 + shifty);
    glVertex2i(xCenter - 20 + shiftx, yCenter + 47 + shifty);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(xCenter + shiftx, yCenter + 57 + shifty);
    glVertex2i(xCenter - 20 + shiftx, yCenter - 33 + shifty);
    glVertex2i(xCenter - 30 + shiftx, yCenter - 38 + shifty);
    glVertex2i(xCenter - 10 + shiftx, yCenter + 52 + shifty);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(xCenter + 10 + shiftx, yCenter + 58 + shifty);
    glVertex2i(xCenter - 10 + shiftx, yCenter - 32 + shifty);
    glVertex2i(xCenter - 20 + shiftx, yCenter - 33 + shifty);
    glVertex2i(xCenter + shiftx, yCenter + 57 + shifty);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(xCenter + 20 + shiftx, yCenter + 55 + shifty);
    glVertex2i(xCenter + shiftx, yCenter - 35 + shifty);
    glVertex2i(xCenter - 10 + shiftx, yCenter - 32 + shifty);
    glVertex2i(xCenter + 10 + shiftx, yCenter + 58 + shifty);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(xCenter + 35 + shiftx, yCenter + 45 + shifty);
    glVertex2i(xCenter + 15 + shiftx, yCenter - 45 + shifty);
    glVertex2i(xCenter + shiftx, yCenter - 35 + shifty);
    glVertex2i(xCenter + 20 + shiftx, yCenter + 55 + shifty);
    glEnd();

    int shiftx2 = 10;
    glColor3f(0.956, 0.788, 0.121); // yellow color for the logo
    glBegin(GL_POLYGON);
    glVertex2i(xCenter +50 +shiftx2, yCenter + 35); //top right
    glVertex2i(xCenter +30 + shiftx2, yCenter - 55); //bottom right
    glVertex2i(xCenter + 15 + shiftx2, yCenter - 45); //bottom left
    glVertex2i(xCenter + 35 + shiftx2, yCenter + 45); //top left
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(xCenter +60 + shiftx2, yCenter +32);
    glVertex2i(xCenter +40 + shiftx2, yCenter -58);
    glVertex2i(xCenter + 30 + shiftx2, yCenter - 55);
    glVertex2i(xCenter + 50 + shiftx2, yCenter + 35);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(xCenter +70 + shiftx2, yCenter + 33);
    glVertex2i(xCenter +50 + shiftx2, yCenter - 57);
    glVertex2i(xCenter + 40 + shiftx2, yCenter - 58);
    glVertex2i(xCenter + 60 + shiftx2, yCenter + 32);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(xCenter + 80 + shiftx2, yCenter + 38);
    glVertex2i(xCenter +60 + shiftx2, yCenter - 52);
    glVertex2i(xCenter + 50 + shiftx2, yCenter - 57);
    glVertex2i(xCenter + 70 + shiftx2, yCenter + 33);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(xCenter + 90 + shiftx2, yCenter + 42);
    glVertex2i(xCenter+70 + shiftx2, yCenter - 48);
    glVertex2i(xCenter + 60 + shiftx2, yCenter - 52);
    glVertex2i(xCenter + 80 + shiftx2, yCenter + 38);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(xCenter + 95 + shiftx2, yCenter + 45);
    glVertex2i(xCenter + 75 + shiftx2, yCenter - 45);
    glVertex2i(xCenter + 70 + shiftx2, yCenter - 48);
    glVertex2i(xCenter + 90 + shiftx2, yCenter + 42);
    glEnd();



    glColor3f(0.217, 0.803, 0.0); // greeen color for the logo
    glBegin(GL_POLYGON);
    glVertex2i(xCenter + 50 +shiftx + shiftx2, yCenter + 35 + shifty); //top right
    glVertex2i(xCenter + 30 + shiftx + shiftx2, yCenter - 55 + shifty); //bottom right
    glVertex2i(xCenter + 15 + shiftx + shiftx2, yCenter - 45 + shifty); //bottom left
    glVertex2i(xCenter + 35 + shiftx + shiftx2, yCenter + 45 + shifty); //top left
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(xCenter + 60 + shiftx + shiftx2, yCenter + 32 + shifty);
    glVertex2i(xCenter + 40 + shiftx + shiftx2, yCenter - 58 + shifty);
    glVertex2i(xCenter + 30 + shiftx + shiftx2, yCenter - 55 + shifty);
    glVertex2i(xCenter + 50 + shiftx + shiftx2, yCenter + 35 + shifty);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(xCenter + 70 + shiftx + shiftx2, yCenter + 33 + shifty);
    glVertex2i(xCenter + 50 + shiftx + shiftx2, yCenter - 57 + shifty);
    glVertex2i(xCenter + 40 + shiftx + shiftx2, yCenter - 58 + shifty);
    glVertex2i(xCenter + 60 + shiftx + shiftx2, yCenter + 32 + shifty);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(xCenter + 80 + shiftx + shiftx2, yCenter + 38 + shifty);
    glVertex2i(xCenter + 60 + shiftx + shiftx2, yCenter - 52 + shifty);
    glVertex2i(xCenter + 50 + shiftx + shiftx2, yCenter - 57 + shifty);
    glVertex2i(xCenter + 70 + shiftx + shiftx2, yCenter + 33 + shifty);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(xCenter + 90 + shiftx + shiftx2, yCenter + 42 + shifty);
    glVertex2i(xCenter + 70 + shiftx + shiftx2, yCenter - 48 + shifty);
    glVertex2i(xCenter + 60 + shiftx + shiftx2, yCenter - 52 + shifty);
    glVertex2i(xCenter + 80 + shiftx + shiftx2, yCenter + 38 + shifty);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(xCenter + 95 + shiftx + shiftx2, yCenter + 45 + shifty);
    glVertex2i(xCenter + 75 + shiftx + shiftx2, yCenter - 45 + shifty);
    glVertex2i(xCenter + 70 + shiftx + shiftx2, yCenter - 48 + shifty);
    glVertex2i(xCenter + 90 + shiftx + shiftx2, yCenter + 42 +shifty);
    glEnd();

}

void drawIcon(int x, int y)
{
    glBegin(GL_POLYGON);
    glVertex2i(x, y);
    glVertex2i(x + 20, y);
    glVertex2i(x + 20, y + 20);
    glVertex2i(x, y + 20);
    glEnd();
}

void drawCircle(float cx, float cy, float r, int num_segments) {
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0, 1.0, 1.0); // White fill color
    glVertex2f(cx, cy); // Center of circle
    for (int i = 0; i <= num_segments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments); // Get the current angle
        float x = r * cosf(theta); // Calculate the x component
        float y = r * sinf(theta); // Calculate the y component
        glVertex2f(x + cx, y + cy); // Output vertex
    }
    glEnd();

    // Draw circle boundary
    glColor3f(0.0, 0.0, 0.0); // Black boundary color
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i <= num_segments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments); // Get the current angle
        float x = r * cosf(theta); // Calculate the x component
        float y = r * sinf(theta); // Calculate the y component
        glVertex2f(x + cx, y + cy); // Output vertex
    }
    glEnd();
}
void drawText(float x, float y, const char* text) {
    glColor3f(1.0, 0.0, 0.0); // Black text color
    glRasterPos2f(x, y);
    while (*text) {
        if (*text == 'n') {
            glColor3f(1.0, 0.0, 0.0); // Red color for 'n'
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *text);
            glColor3f(0.0, 0.0, 0.0); // Reset color back to black
        }
        else {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *text);
        }
        ++text;
    }
}
void drawFolderIcon() {
    // Draw the folder body (rectangle)
    glColor3f(1.0, 1.0, 0.0); // yellow
    glBegin(GL_POLYGON);
    glVertex2f(0.0, 0.0);
    glVertex2f(105.0, 0.0);
    glVertex2f(105.0, 80.0);
    /*    */glVertex2f(20.0, 80.0);
    glVertex2f(0.0, 80.0);
    glEnd();


    // Draw the folder tab (smaller rectangle on top)
    glColor3f(1.0, 1.0, 0.5); // Light yellow
    glBegin(GL_POLYGON);
    glVertex2f(0.0, 70.0);
    glVertex2f(15.0, 90.0);
    glVertex2f(50.0, 90.0);
    glVertex2f(60.0, 80.0);
    glEnd();

    // Draw the folder label (optional)
    glColor3f(0.0, 0.0, 0.0); // Black
    glRasterPos2f(10.0, 40.0); // Adjust position as needed
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'F');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'o');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'l');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'd');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'e');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'r');
}



//cube ------

float ver[8][3] =
{
    {-1.0,-1.0,1.0},
    {-1.0,1.0,1.0},
    {1.0,1.0,1.0},
    {1.0,-1.0,1.0},
    {-1.0,-1.0,-1.0},
    {-1.0,1.0,-1.0},
    {1.0,1.0,-1.0},
    {1.0,-1.0,-1.0},
};

GLfloat color[8][3] =
{
    {0.0,0.0,0.0},
    {1.0,0.0,0.0},
    {1.0,1.0,0.0},
    {0.0,1.0,0.0},
    {0.0,0.0,1.0},
    {1.0,0.0,1.0},
    {1.0,1.0,1.0},
    {0.0,1.0,1.0},
};

void quad(int a, int b, int c, int d)
{
    glBegin(GL_QUADS);
    glColor3fv(color[a]);
    glVertex3fv(ver[a]);

    glColor3fv(color[b]);
    glVertex3fv(ver[b]);

    glColor3fv(color[c]);
    glVertex3fv(ver[c]);

    glColor3fv(color[d]);
    glVertex3fv(ver[d]);
    glEnd();
}

void colorcube()
{
    quad(0, 3, 2, 1);
    quad(2, 3, 7, 6);
    quad(0, 4, 7, 3);
    quad(1, 2, 6, 5);
    quad(4, 5, 6, 7);
    quad(0, 1, 5, 4);
}

double rotate_y = 0;
double rotate_x = 0;
void specialKeys(int key, int x, int y)
{
    if (key == GLUT_KEY_RIGHT)
        rotate_y += 5;
    else if (key == GLUT_KEY_LEFT)
        rotate_y -= 5;
    else if (key == GLUT_KEY_UP)
        rotate_x += 5;
    else if (key == GLUT_KEY_DOWN)
        rotate_x -= 5;
    glutPostRedisplay();
}

void c_display()
{
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    int w = glutGet(GLUT_WINDOW_WIDTH);
    int h = glutGet(GLUT_WINDOW_HEIGHT);
    gluPerspective(60, w / h, 0.1, 100);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt
    (
        3, 3, 3,
        0, 0, 0,
        0, 0, 1
    );

    glRotatef(rotate_x, 1.0, 0.0, 0.0);
    glRotatef(rotate_y, 0.0, 1.0, 0.0);
    colorcube();

    glutSwapBuffers();
}

void drawRecycleBinIcon()
{
    // Define the dimensions of the glass tumbler
    float baseWidth = 30.0;   // Width of the base
    float topWidth = 40.0;    // Width of the top
    float height = 60.0;      // Height of the tumbler
    float lipHeight = 5.0;    // Height of the lip

    // Draw the main body of the glass tumbler (trapezoidal shape)
    glColor3f(0.5, 0.5, 0.5); // Gray color for glass body
    glBegin(GL_POLYGON);
    glVertex2f(-baseWidth / 2, 0.0);
    glVertex2f(baseWidth / 2, 0.0);
    glVertex2f(topWidth / 2, height);
    glVertex2f(-topWidth / 2, height);
    glEnd();

    // Draw the lip of the glass tumbler
    glColor3f(0.4, 0.4, 0.4); // Dark gray color for lip
    glBegin(GL_POLYGON);
    glVertex2f(-topWidth / 2, height);
    glVertex2f(topWidth / 2, height);
    glVertex2f(topWidth / 2, height + lipHeight);
    glVertex2f(-topWidth / 2, height + lipHeight);
    glEnd();

    // Draw the rim of the glass tumbler
    glBegin(GL_LINE_LOOP);
    glVertex2f(-topWidth / 2, height + lipHeight);
    glVertex2f(topWidth / 2, height + lipHeight);
    glEnd();

    // Draw the base of the glass tumbler (ellipse)
    glColor3f(0.5, 0.5, 0.5); // Gray color for base
    int numSegments = 2;
    float radiusX = baseWidth / 2;
    float radiusY = 8; // Ellipse radius for the base
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i <= numSegments; ++i)
    {
        float angle = 2.0f * 3.1415926f * i / numSegments;
        float x = radiusX * cos(angle);
        float y = radiusY * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();

    // Draw the recycle symbol (arrows and circle)
    glColor3f(0.0, 1.0, 0.0); // Green color for recycle symbol

  

    // Draw the bottom arrow
    glBegin(GL_TRIANGLES);
    glVertex2f(-6.0, height + lipHeight - 14.0);
    glVertex2f(6.0, height + lipHeight - 14.0);
    glVertex2f(0.0, height + lipHeight - 24.0);
    glEnd();

    glColor3f(0.0, 0.0, 0.0); // Black
    glRasterPos2f(2, 0.5);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ' ');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ' ');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ' ');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ' ');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'R');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'e');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'c');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'y');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'c');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'l');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'e');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ' ');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'b');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'i');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'n');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ' ');

    // Draw the circle in the center of the symbol
    float circleRadius = 3.0;
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i <= numSegments; ++i)
    {
        float angle = 2.0f * 3.1415926f * i / numSegments;
        float x = 0.0 + (circleRadius * cos(angle));
        float y = height + lipHeight + (circleRadius * sin(angle));
        glVertex2f(x, y);
    }
    glEnd();
}


// Global variables
int windowWidth = 640;
int windowHeight = 480;
time_t lastUpdateTime = time(nullptr); // Variable to store the last update time
extern int windowWidth;

void drawCurrentTime()
{
    // Get current time
    time_t currentTime = time(nullptr);
    tm localTime;

    // Call localtime_s to convert current time to local time
    if (localtime_s(&localTime, &currentTime) == 0) {
        // Successfully obtained local time
        std::cout << "Current local time: "
            << localTime.tm_hour << ":" << localTime.tm_min << ":" << localTime.tm_sec
            << std::endl;
    }
    else {
        // Error handling if localtime_s fails
        std::cerr << "Failed to get local time!" << std::endl;
        return; // Return early if localtime_s fails
    }

    // Format current time
    char buffer[80];
    if (strftime(buffer, sizeof(buffer), "%H:%M:%S", &localTime) == 0) {
        // Error handling if strftime fails
        std::cerr << "Error formatting time!" << std::endl;
        return; // Return early if strftime fails
    }
    std::string timeStr = buffer;

    // Calculate the position for the text
    int textWidth = 9 * timeStr.length(); // Width of text in pixels
    int textHeight = 15; // Height of text in pixels
    int margin = 50; // Margin from window edge
    int textPosX = windowWidth - textWidth - margin; // X coordinate for bottom-right corner
    int textPosY = 10; // Y coordinate for bottom-right corner

    // Draw current time at the bottom of the window
    glColor3f(1.0, 1.0, 1.0); // White color for text
    glRasterPos2i(textPosX, textPosY); // Set the raster position for drawing
    for (char c : timeStr) {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, c); // Draw each character using GLUT's bitmap font
    }
}void display()
{
    // Update the current time
    lastUpdateTime = time(nullptr);

    glClear(GL_COLOR_BUFFER_BIT);

    drawDesktop();
    drawWindows98Logo();

    // Draw recycle bin icon
    glPushMatrix();
    glTranslatef(50.0, 100.0, 0.0); // Position the recycle bin
    drawRecycleBinIcon();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(430, 130, 0); // Position of the search icon
    drawSearchIcon();
    glPopMatrix();

    // Draw folder icon
    glPushMatrix();
    glTranslatef(30.0, 190.0, 0.0); // Position the folder icon
    drawFolderIcon();
   
    glPopMatrix();
    glPushMatrix();
    glTranslatef(150, 90, 0.0); // Position the folder icon
    drawFolderIcon();

    glPopMatrix();

    // Draw circle icon
    glPushMatrix();
    glTranslatef(30.0, 300.0, 0.0); // Position the circle icon
    drawCircle(40.0, 40.0, 40.0, 100); // Centered at (200, 200) with radius 40
    drawText(29.0, 40.0, "MSn"); // Adjusted position to fit within the circle
    glPopMatrix();

    drawCurrentTime();

    glFlush();
    // Request a redraw
    glutSwapBuffers();

    // Schedule the next display() call
    glutPostRedisplay();
}
bool depthEnabled = false; 

void enableDepthTest()
{
    glEnable(GL_DEPTH_TEST);
    depthEnabled = true;
}

void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        // Check if the click is within the bounding box of the "Start" text
        // Bounding box coordinates
        int startX = 10;    // X-coordinate of the "Start" text
        int startY = 5;     // Y-coordinate of the "Start" text
        int endX = 90;      // End X-coordinate of the "Start" text
        int endY = 25;      // End Y-coordinate of the "Start" text

        // Check if the click coordinates are within the bounding box
        if (x >= startX && x <= endX && y >= startY && y <= endY)
        {
            // Change display function to c_display
            glutDisplayFunc(c_display);

            // Enable depth test (only if not already enabled)
            if (!depthEnabled)
                enableDepthTest();

            // Request redisplay to show updated scene with c_display
            glutPostRedisplay();
            cout << "Clicked on Start button!" << endl;
        }
    }
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(10, 10);
    glutCreateWindow("Windows 98 Simulation");
    myinit();

    // Initially set the display function to the default display
    glutDisplayFunc(display);
    glutSpecialFunc(specialKeys);
    glutMouseFunc(mouse);

    glutMainLoop();
    return 0;
}