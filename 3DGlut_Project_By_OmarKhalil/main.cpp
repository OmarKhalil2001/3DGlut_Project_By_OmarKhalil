#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

float angle=0.1; //Speed Of Rotation
void display()
{
    //The sky is blue with a hint of red
    glClearColor(0.1,0, 0.6,0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    angle++;
    //The Sun is up
    glPushMatrix();
        glColor3f(1,0.9,0);
        glTranslatef(90, 80, -60);
        glRotatef(angle, 0, 1, 0);
        glutSolidSphere(15, 8, 20);
    glPopMatrix();

    //The Land is Green
    glPushMatrix();
        glColor3f(0,0.7,0);
        glTranslatef(0, -180, 0);
        glutSolidCube(200);
    glPopMatrix();

    //The pot is awesome
    for(int i = 1; i <= 20; i++){
        glPushMatrix();
            glColor3f(0.4,0,0);
            glTranslatef(0, -i*5, 0);
            glRotatef(90, 1, 0, 0);
            glutSolidTorus(3,40-i, 60,60);
        glPopMatrix();
    }

    //the teapot is cooler tho
    glPushMatrix();
        glColor3f(0.1,0.1,0.1);
        glTranslatef(-100, 100, 0);
        glRotatef(-45, 0, 0, 1);
        glutSolidTeapot(50);
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
    glutInitWindowSize(600, 600);
    glutInitDisplayMode(GLUT_RGB | GL_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Omar H. Khalil || 20101110");

    glutDisplayFunc(display);
    glutIdleFunc(display); //the same function of glutPostRedisplay();
    glOrtho(-100.0,100,-100.0,100,-100.0,100); //not gluOrtho

    glRotatef(0,1,0,0);
    glClearColor(1,1,1,1);
    texture(); // Lighting and textures
    glutMainLoop();
}
