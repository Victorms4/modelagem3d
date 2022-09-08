#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#define MAXX 900
#define MAXY 700

bool check=true;
int jogo[3][3]={0,0,0,
                0,0,0,
                0,0,0};
int turno=1, lugar=0;
void desenha();
void mouse(int, int, int, int);
void cancela();
void xis();
void circulo();


int main(int argc, char* argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(MAXX,MAXY);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Jogo da velha");
    glutDisplayFunc(desenha);
    glutMouseFunc(mouse);
    glClearColor(1,1,1,0);
    glutMainLoop();
    return 0;
}

void desenha(){
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, MAXX, 0, MAXY);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    cancela();
    xis();
    //circulo();

    glFlush();
}

void mouse(int button, int state, int mousex, int mousey){
    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN){
        check=true;
        if(mousex >= 50 && mousex <= 250 && MAXY-mousey >= 450 && MAXY-mousey <= 650){
            if(turno%2==1 && jogo[0][0]==0)
                jogo[0][0]=1;
            else if(jogo[0][0]==0)
                jogo[0][0]=2;
            turno++;
        }
        if(mousex > 250 && mousex <= 450 && MAXY-mousey >= 450 && MAXY-mousey <= 650){
            if(turno%2==1 && jogo[0][1]==0)
                jogo[0][1]=1;
            else if(jogo[0][1]==0)
                jogo[0][1]=2;
            turno++;
        }
        if(mousex > 450 && mousex <= 650 && MAXY-mousey >= 450 && MAXY-mousey <= 650){
            if(turno%2==1 && jogo[0][2]==0)
                jogo[0][2]=1;
            else if(jogo[0][2]==0)
                jogo[0][2]=2;
            turno++;
        }
        if(mousex >= 50 && mousex <= 250 && MAXY-mousey >= 250 && MAXY-mousey < 450){
            if(turno%2==1 && jogo[1][0]==0)
                jogo[1][0]=1;
            else if(jogo[1][0]==0)
                jogo[1][0]=2;
            turno++;
        }
        if(mousex > 250 && mousex <= 450 && MAXY-mousey >= 250 && MAXY-mousey < 450){
            if(turno%2==1 && jogo[1][1]==0)
                jogo[1][1]=1;
            else if(jogo[1][1]==0)
                jogo[1][1]=2;
            turno++;
        }
        if(mousex > 450 && mousex <= 650 && MAXY-mousey >= 250 && MAXY-mousey < 450){
            if(turno%2==1 && jogo[1][2]==0)
                jogo[1][2]=1;
            else if(jogo[1][2]==0)
                jogo[1][2]=2;
            turno++;
        }
        if(mousex >= 50 && mousex <= 250 && MAXY-mousey >= 50 && MAXY-mousey < 250){
            if(turno%2==1 && jogo[2][0]==0)
                jogo[2][0]=1;
            else if(jogo[2][0]==0)
                jogo[2][0]=2;
            turno++;
        }
        if(mousex > 250 && mousex <= 450 && MAXY-mousey >= 50 && MAXY-mousey < 250){
            if(turno%2==1 && jogo[2][1]==0)
                jogo[2][1]=1;
            else if(jogo[2][1]==0)
                jogo[2][1]=2;
            turno++;
        }
        if(mousex > 450 && mousex <= 650 && MAXY-mousey >= 50 && MAXY-mousey < 250){
            if(turno%2==1 && jogo[2][2]==0)
                jogo[2][2]=1;
            else if(jogo[2][2]==0)
                jogo[2][2]=2;
            turno++;
        }
    }
}

void cancela(){
    glBegin(GL_LINES);
        glColor3f(0,0,0);
        glVertex2f(50, 250);
        glVertex2f(650, 250);
        glVertex2f(50, 450);
        glVertex2f(650, 450);
        glVertex2f(250, 50);
        glVertex2f(250, 650);
        glVertex2f(450, 50);
        glVertex2f(450, 650);
    glEnd();
}

void xis(){
    if(jogo[0][0]==1){
        glBegin(GL_LINES);
            glVertex2f(60,640);
            glVertex2f(240,460);
            glVertex2f(240,640);
            glVertex2f(60,460);
        glEnd();
    }
    if(jogo[0][1]==1){
        glBegin(GL_LINES);
            glVertex2f(60,640);
            glVertex2f(240,460);
            glVertex2f(240,640);
            glVertex2f(60,460);
        glEnd();
    }
    if(jogo[0][2]==1){
        glBegin(GL_LINES);
            glVertex2f(60,640);
            glVertex2f(240,460);
            glVertex2f(240,640);
            glVertex2f(60,460);
        glEnd();
    }
    if(jogo[1][0]==1){
        glBegin(GL_LINES);
            glVertex2f(60,640);
            glVertex2f(240,460);
            glVertex2f(240,640);
            glVertex2f(60,460);
        glEnd();
    }
    if(jogo[1][1]==1){
        glBegin(GL_LINES);
            glVertex2f(60,640);
            glVertex2f(240,460);
            glVertex2f(240,640);
            glVertex2f(60,460);
        glEnd();
    }
    if(jogo[1][2]==1){
        glBegin(GL_LINES);
            glVertex2f(60,640);
            glVertex2f(240,460);
            glVertex2f(240,640);
            glVertex2f(60,460);
        glEnd();
    }
    if(jogo[2][0]==1){
        glBegin(GL_LINES);
            glVertex2f(60,640);
            glVertex2f(240,460);
            glVertex2f(240,640);
            glVertex2f(60,460);
        glEnd();
    }
    if(jogo[2][1]==1){
        glBegin(GL_LINES);
            glVertex2f(60,640);
            glVertex2f(240,460);
            glVertex2f(240,640);
            glVertex2f(60,460);
        glEnd();
    }
    if(jogo[2][2]==1){
        glBegin(GL_LINES);
            glVertex2f(60,640);
            glVertex2f(240,460);
            glVertex2f(240,640);
            glVertex2f(60,460);
        glEnd();
    }
}

void circulo(){
    float ang, x, y;
    glBegin(GL_LINE_LOOP);
        for (i = 0; i < 360; i++) {
            ang = (i * PI) / 180.0;
            x = 0 + (cos(ang) * 4);
            y = 0 + (sin(ang) * 4);
            glVertex2f(x, y);
        }
}
