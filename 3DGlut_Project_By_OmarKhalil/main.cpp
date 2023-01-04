#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

using namespace std;
float angle=0.1, h = 0, f1 = 0, f2 = 0, c = 0.1;
bool runWater = false;

void fly(){
    f1++;
    glBegin(GL_QUADS);
        glVertex3f(0.5, 0, 0.5);
        glVertex3f(0.5, 0, -0.5);
        glVertex3f(-0.5, 0, -0.5);
        glVertex3f(-0.5, 0, 0.5);

        glVertex3f(0.5,0,-0.5);
        glVertex3f(0.5,1,-0.5);
        glVertex3f(-0.5,1,-0.5);
        glVertex3f(-0.5,0,-0.5);

        glVertex3f(0.5,1,-0.5);
        glVertex3f(-0.5,1,-0.5);
        glVertex3f(-0.5,0,0.5);
        glVertex3f(0.5,0,0.5);
    glEnd();
    glBegin(GL_TRIANGLES);
        glVertex3f(0.5,0,0.5);
        glVertex3f(0.5,1,-0.5);
        glVertex3f(0.5,0,-0.5);

        glVertex3f(-0.5,0,0.5);
        glVertex3f(-0.5,1,-0.5);
        glVertex3f(-0.5,0,-0.5);
    glEnd();
}
void grass(float x, float y, float z,  float r, float g, float b, int width, float len, float len2, float len3){
    glLineWidth(width);

    glBegin(GL_LINES);
        glColor3d(r, g, b);
        glVertex3d( x,  y, z);
        glVertex3d( x + len/2.0,  y + len, z);
    glEnd();

    x += len/2.0;
    y += len;
    len = len2;
    len = len2;

    glBegin(GL_LINES);
        glColor3d(r, g, b);
        glVertex3d( x,  y, z);
        glVertex3d( x - len/2.0,  y + len, z);
    glEnd();

    x -= len/2.0;
    y += len;
    len = len3;
    len = len3;

    glBegin(GL_LINES);
        glColor3d(r, g, b);
        glVertex3d( x,  y-0.5, z);
        glVertex3d( x + len/2,  y + len/2, z);
    glEnd();
}
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
        glutSolidSphere(15, 30, 20);
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

    //the soil is where it all starts
    glPushMatrix();
        glColor3f(0.2,0,0);
        glTranslatef(0, -1, 0);
        glRotatef(90, 1, 0, 0);
        glutSolidCone(35, 20, 30,30);
    glPopMatrix();

    //the teapot is cooler tho
    glPushMatrix();
        glColor3f(0.1,0.1,0.1);
        glTranslatef(-45, 145, 0);
        glRotatef(-80, 0, 0, 1);
        glutSolidTeapot(50);
    glPopMatrix();

    //some grass
    glPushMatrix();
        grass(0, -10, 0, 0, 0.8, 0, 15, 15, 20, 15);
        grass(-10, -10, 0, 0, 0.9, 0, 12, 12, 18, 14);
        grass(10, -10, 0, 0.1, 0.6, 0, 17, 8, 10, 7.5);
        grass(20, -10, 0, 0.2, 0, 0, 12, 12, 18, 14);
        grass(-14, -10, 0, 0.3, 0.75, 0, 17, 8, 10, 7.5);
    glPopMatrix();

    //Watering the Plants
    if(runWater){
        glPushMatrix();
            glColor3f(0,0,0.5);
            glTranslatef(0,65,0);
            GLUquadric *p = gluNewQuadric();
            gluQuadricDrawStyle(p,GLU_LINE);
            glRotatef(90, 1, 0, 0);
            gluCylinder(p,5,5,h,100,100);
        glPopMatrix();
        h += 0.35;
        if(h >= 65) h = 65;

        glPushMatrix();
            glColor3f(0,0,0.4);
            glTranslatef(0,70,0);
            glRotatef(90, 1, 0, 0);
            glutSolidCube(16);
        glPopMatrix();
    }else{
        h = 0;
    }
    //flies
    glPushMatrix();
        glColor3f(1,.9,0);
        glTranslatef(f2, 40, 0);
        glRotatef(f1, 0,1,1);
        glScalef(2, 2, 2);
        fly();
    glPopMatrix();

    glPushMatrix();
        glColor3f(1,.9,0);
        glTranslatef(-30+f2, 20, 0);
        glRotatef(f1, 0,1,1);
        glScalef(2, 2, 2);
        fly();
    glPopMatrix();

    glPushMatrix();
        glColor3f(1,.9,0);
        glTranslatef(20+f2, 40, 0);
        glRotatef(f1, 0,1,1);
        glScalef(2, 2, 2);
        fly();
    glPopMatrix();
    f2 += c;
    if(f2 > 5) c = -c;
    else if(f2 < -5) c = -c;
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
void waterThePlants(int key, int x, int y){
    if(key == GLUT_KEY_DOWN){
        runWater = true;
    }else{
        runWater = false;
    }
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
    glutSpecialFunc(waterThePlants);
    texture(); // Lighting and textures
    glutMainLoop();
}
