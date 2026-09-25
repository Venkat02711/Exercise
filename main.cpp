#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

int xa = 1, ya = 2;

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 100.0, 0.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void display(void) {
    int dx = xb - xa;
    int dy = yb - ya;
    int steps = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);
    float xInc = (float)dx / steps;
    float yInc = (float)dy / steps;
    float x = xb;
    float y = yb;

    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(5.0);

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i <= steps; i++) {
        int plotX = (x >= 0) ? (int)(x + 0.5f) : (int)(x - 0.5f);
        int plotY = (y >= 0) ? (int)(y + 0.5f) : (int)(y - 0.5f);

        glVertex2i(plotX, plotY);

        x += xInc;
        y += yInc;
    }
    glEnd();

    glFlush();
}

int main(int argc, char* argv[]) {
    int dx = xb - xa;
    int dy = yb - ya;
    int steps = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);
    float xInc = (float)dx / steps;
    float yInc = (float)dy / steps;
    float x = xa;
    float y = ya;

    printf("Step", "Exact X", "Exact Y", "Plotted Point");
    printf("---------------------------------------------\n");

    for (int i = 0; i <= steps; i++) {
        int pX = (x >= 0) ? (int)(x + 0.5f) : (int)(x - 0.5f);
        int pY = (y >= 0) ? (int)(y + 0.5f) : (int)(y - 0.5f);

        printf("%-6d %-10.2f %-10.2f (%d, %d)\n", i, x, y, pX, pY);

        x += xInc;
        y += yInc;
    }
    printf("\n");
    fflush(stdout);

    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 150);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("DDA Line");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
