#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#define PI 3.1415926535898

void desenha();
void teclado(unsigned char, int, int);
void listeningSpKey (GLint , GLint , GLint );
void chute(int);
void texto(char *aux);
void mouse(int button, int state, int mousex, int mousey)
void campo();

GLfloat transX=1, transY=1, transZ=2;
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
    glutSpecialFunc(listeningSpKey);
    glutTimerFunc(5, chute, 0);
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

    glTranslatef(transX, transY, transZ);
    glutSolidSphere(2, 40, 20);

    campo();

    if(chutou = 2){
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glColor3f(0,0,0);
        glTranslatef(-50,90, 0);
        if(transX >= -20 && transX <= 20 && transZ <= 20)
            texto("GOL!\n");
        else
            texto("Pra fora!\n");
        glTranslatef(100,0,0);
        texto("Jogar novamente\n")
    }

    glutSwapBuffers();
}

void teclado(unsigned char tecla, int x, int y){
    switch(tecla){
        case ' ': chutou = 1;
            break;
    }
    glutPostRedisplay();
}

void  listeningSpKey (GLint tecla, GLint x, GLint y) {
	switch(tecla) {
		case GLUT_KEY_UP:
		        transY++;
				break;
		case GLUT_KEY_DOWN:
		        transY--;
				break;
		case GLUT_KEY_LEFT:
		        transX--;
				break;
		case GLUT_KEY_RIGHT:
                transX++;
				break;
	}
	glutPostRedisplay();
}

void chute(int valor){
    GLfloat passoY=2, passoZ=1;
    if(chutou==1){
        if(transZ-2 <= 0 || transZ >= 30)
            passoZ = -passoZ;
        transY += passoY;
        transZ += passoZ;
        if(transY >= 80)
            chutou = 2;
        glutPostRedisplay();
        glutTimerFunc(5, chute, 0);
    }
}

void texto(char *aux)
{
	char *p;
	p = aux;
	while(*p)
		glutStrokeCharacter(GLUT_STROKE_ROMAN,*p++);
}

void mouse(int button, int state, int mousex, int mousey){
    if(button==GLUT_LEFT_BUTTON){
    }

    glutPostRedisplay();
}

void campo(){
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
}
