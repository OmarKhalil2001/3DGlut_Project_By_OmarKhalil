#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

float angle=0.1; //Speed Of Rotation
void display()
{
    glClearColor(1,1,1,0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glColor3f(0,0.5,1);
    glLineWidth(1.5);
    glMatrixMode(GL_MODELVIEW);

    glColor3f(0,0.5,1);
    glPushMatrix();
    glRotatef(-90, 1, 0, 0);
    glutSolidCone(20, 20,20,20);
    glPopMatrix();
    glFlush();
    glutSwapBuffers();
}
void texture (void){

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);


}
int main()
{
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(800, 800);
    glutInitDisplayMode(GLUT_RGB | GL_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Omar H. Khalil || 20101110");

    glutDisplayFunc(display);
    glutIdleFunc(display); //the same function of glutPostRedisplay();
    glOrtho(-44.0,44,-44.0,44,-44.0,44); //not gluOrtho

    glRotatef(1,0,0,0);
    glClearColor(1,1,1,1);
    texture(); // Lighting and textures
    glutMainLoop();
}
