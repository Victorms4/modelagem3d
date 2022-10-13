#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#define PI 3.1415926535898

void desenha();
void teclado(unsigned char, int, int);
void chute(int);

GLfloat transX=1, transY=1;
int i = 0, chutou=0;
float ang, x, y;


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("bola");
    glutDisplayFunc(desenha);
    glutKeyboardFunc(teclado);
    //glutTimerFunc(5, chute, 0);
    glClearColor(0,0.6,0.1,0);
    glutMainLoop();

    return EXIT_SUCCESS;
}

void desenha(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glOrtho(-100, 100, -50, 100, -100, 100);
    glColor3f(1, 1, 1);
    glRotatef(-45, 1, 0, 0);

    glLineWidth(2);
    glBegin(GL_LINES);
        glVertex3f(-100, 80, 0);
        glVertex3f(100, 80, 0);
        glVertex3f(-80, 80, 0);
        glVertex3f(-80, 20, 0);
        glVertex3f(-80, 20, 0);
        glVertex3f(80, 20, 0);
        glVertex3f(80, 20, 0);
        glVertex3f(80, 80, 0);
        glVertex3f(-40, 80, 0);
        glVertex3f(-40, 60, 0);
        glVertex3f(-40, 60, 0);
        glVertex3f(40, 60, 0);
        glVertex3f(40, 60, 0);
        glVertex3f(40, 80, 0);
    glEnd();

    glBegin(GL_POLYGON);
        for (i = 0; i < 360; i++) {
            ang = (i * PI) / 180.0;
            x = 0 + (cos(ang) * 1);
            y = 40 + (sin(ang) * 1);
            glVertex2f(x, y);
            glColor3f(1,1,1);
        }
     glEnd();

     glBegin(GL_LINE_LOOP);
        for (i = 180; i < 360; i++) {
            ang = (i * PI) / 180.0;
            x = 0 + (cos(ang) * 30);
            y = 20 + (sin(ang) * 30);
            glVertex2f(x, y);
        }
     glEnd();

     glLineWidth(5);
     glBegin(GL_LINES);
        glVertex3f(-20, 80, 0);
        glVertex3f(-20, 80, 20);
        glVertex3f(-20, 80, 20);
        glVertex3f(20, 80, 20);
        glVertex3f(20, 80, 20);
        glVertex3f(20, 80, 0);
     glEnd();

    glTranslatef(transX, 2, transY);
    glutSolidSphere(2, 40, 20);

    glutSwapBuffers();
}

void teclado(unsigned char tecla, int x, int y){
    switch(tecla){
        case 'w':
            transY++;
            break;
        case 's': transY--;
            break;
        case 'd': transX++;
            break;
        case 'a': transX--;
            break;
        //case ' ':
    }
    glutPostRedisplay();
}

/*void chute(int valor){
    if(x1 > windowWidth-rsize || x1 < 0)
        xstep = -xstep;
    if(y1 > windowHeight-rsize || y1 < 0)
        ystep = -ystep;
    if(x1 > windowWidth-rsize)
        x1 = windowWidth-rsize-1;
    if(y1 > windowHeight-rsize)
        y1 = windowHeight-rsize-1;
    x1 += xstep;
    y1 += ystep;
    glutPostRedisplay();
    glutTimerFunc(5,Timer, 0);
}*/
