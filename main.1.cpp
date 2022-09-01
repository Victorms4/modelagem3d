#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

GLfloat escala = 1, transladarX = 1, transladarY = 1, rotacao=0;
void desenha();
void listeningKey(unsigned char tecla, GLint x, GLint y);
void letraV(void);
void letraI(void);
void letraC(void);
void letraT(void);
void letraO(void);
void letraR(void);


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(2000,1000);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Ola Glut");
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glClearColor(0, 0, 0, 0);
    glutDisplayFunc(desenha);
    glutKeyboardFunc(listeningKey);


    glutMainLoop();

    return EXIT_SUCCESS;
}

void desenha(){
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100, 100, -100, 100);

    glScalef(escala, escala, 0);
    glTranslatef(transladarX, transladarY, 0);
    glRotatef(rotacao, 0, 0, 1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    letraV();
    letraI();
    letraC();
    letraT();
    letraO();
    letraR();

    glFlush();
}

void listeningKey(unsigned char tecla, GLint x, GLint y){
    switch(tecla){
    case '+': escala++;
        break;
    case '-':
        if(escala >= 2)
            escala--;
        if(escala < 0.75){}
        else
            escala = escala - (escala/2);
        break;
    case 'd': transladarX++;
        break;
    case 'a': transladarX--;
        break;
    case 'w': transladarY++;
        break;
    case 's': transladarY--;
        break;
    case 'e': rotacao++;
        break;
    case 'q': rotacao--;
        break;

    }
    desenha();
}

void letraV(void){
    glBegin(GL_LINE_STRIP);
        glVertex2f(-6,-1);
        glVertex2f(-5.5,-3);
        glVertex2f(-5,-1);
    glEnd();
}
void letraI(void){
    glBegin(GL_LINE_STRIP);
        glVertex2f(-4.5,-1);
        glVertex2f(-4.5,-3);
    glEnd();
}
void letraC(void){
    glBegin(GL_LINE_STRIP);
        glVertex2f(-3.25,-3);
        glVertex2f(-4,-3);
        glVertex2f(-4,-1);
        glVertex2f(-3.25,-1);
    glEnd();
}
void letraT(void){
    glBegin(GL_LINE_STRIP);
        glVertex2f(-2.5,-3);
        glVertex2f(-2.5,-1);
        glVertex2f(-3,-1);
        glVertex2f(-2,-1);
    glEnd();
}
void letraO(void){
    glBegin(GL_LINE_LOOP);
        glVertex2f(-1.75,-3);
        glVertex2f(-1.75,-1);
        glVertex2f(-0.75,-1);
        glVertex2f(-0.75,-3);
    glEnd();
}
void letraR(void){
    glBegin(GL_LINE_STRIP);
        glVertex2f(-0.5,-3);
        glVertex2f(-0.5,-1);
        glVertex2f(0.5,-1);
        glVertex2f(0.5,-2);
        glVertex2f(-0.5,-2);
        glVertex2f(0.5,-3);
    glEnd();
}
