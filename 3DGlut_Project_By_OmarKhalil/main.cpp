#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

float angle=1.0; //Speed Of Rotation
void display()
{
    glClearColor(1,1,1,0);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0,0.5,1);
    glLineWidth(1.5);
    glMatrixMode(GL_MODELVIEW);

    glRotatef(angle,0,1,0); //Rotate Around Y-axis
    glutWireCube(30);

    glRotatef(angle,0,1,0); //Rotate Around Y-axis
    glColor3f(1,0,1);
    glutWireTeapot(20);

    glFlush();
    glutSwapBuffers();
}
int main()
{
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(800, 800);
    glutInitDisplayMode(GLUT_RGB | GL_DOUBLE);
    glutCreateWindow("Omar H. Khalil || 20101110");

    glutDisplayFunc(display);
    glutIdleFunc(display); //the same function of glutPostRedisplay();
    glOrtho(-44.0,44,-44.0,44,-44.0,44); //not gluOrtho

    glRotatef(1,1,0,0);
    glutMainLoop();
}
