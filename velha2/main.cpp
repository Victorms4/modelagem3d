#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>

#define MAXX 1200
#define MAXY 700
#define PI 3.1415926535898

bool check=true;
int turno=1;
int estado=0;
int campo[9]={0,0,0,
              0,0,0,
              0,0,0};


void hashtag();
void desenha();
void mouse(int, int, int, int);
void escolha(int mousex, int mousey);
void xis();
void bola();
void fim();

int main(int argc, char* argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(MAXX,MAXY);
    glutInitWindowPosition(100,0);
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

    hashtag();
    xis();
    bola();

    glFlush();
}

void mouse(int button, int state, int mousex, int mousey){
    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN){
        check=true;
        escolha(mousex, mousey);
    }

}

void hashtag(){
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

void escolha(int mousex, int mousey){
    if(mousex >= 50 && mousex <= 250 && MAXY-mousey >= 450 && MAXY-mousey <= 650){
        if(turno%2==1 && campo[0]==0){
            campo[0]=1;
            turno++;
            fim(0);
        }
        else if(campo[0]==0){
            campo[0]=2;
            turno++;
            fim(0);
        }
        printf("%d %d", turno, campo[0]);
    }

    if(mousex > 250 && mousex <= 450 && MAXY-mousey >= 450 && MAXY-mousey <= 650){
        if(turno%2==1 && campo[1]==0){
            campo[1]=1;
            turno++;
            fim(1);
        }
        else if(campo[1]==0){
            campo[1]=2;
            turno++;
            fim(1);
        }
        printf("%d %d", turno, campo[1]);
    }
    if(mousex > 450 && mousex <= 650 && MAXY-mousey >= 450 && MAXY-mousey <= 650){
        if(turno%2==1 && campo[2]==0){
            campo[2]=1;
            turno++;
            fim(2);
        }
        else if(campo[2]==0){
            campo[2]=2;
            turno++;
            fim(2);
        }
        printf("%d %d", turno, campo[2]);
    }
    if(mousex >= 50 && mousex <= 250 && MAXY-mousey >= 250 && MAXY-mousey < 450){
        if(turno%2==1 && campo[3]==0){
            campo[3]=1;
            turno++;
            fim(3);
        }
        else if(campo[3]==0){
            campo[3]=2;
            turno++;
            fim(3);
        }
        printf("%d %d", turno, campo[3]);
    }
    if(mousex > 250 && mousex <= 450 && MAXY-mousey >= 250 && MAXY-mousey < 450){
        if(turno%2==1 && campo[4]==0){
            campo[4]=1;
            turno++;
            fim(4);
        }
        else if(campo[4]==0){
            campo[4]=2;
            turno++;
            fim(4);
        }
        printf("%d %d", turno, campo[4]);
    }
    if(mousex > 450 && mousex <= 650 && MAXY-mousey >= 250 && MAXY-mousey < 450){
        if(turno%2==1 && campo[5]==0){
            campo[5]=1;
            turno++;
            fim(5);
        }
        else if(campo[5]==0){
            campo[5]=2;
            turno++;
            fim(5);
        }
        printf("%d %d", turno, campo[5]);
    }
    if(mousex >= 50 && mousex <= 250 && MAXY-mousey >= 50 && MAXY-mousey < 250){
        if(turno%2==1 && campo[6]==0){
            campo[6]=1;
            turno++;
            fim(6);
        }
        else if(campo[6]==0){
            campo[6]=2;
            turno++;
            fim(6);
        }
        printf("%d %d", turno, campo[6]);
    }
    if(mousex > 250 && mousex <= 450 && MAXY-mousey >= 50 && MAXY-mousey < 250){
        if(turno%2==1 && campo[7]==0){
            campo[7]=1;
            turno++;
            fim(7);
        }
        else if(campo[7]==0){
            campo[7]=2;
            turno++;
            fim(7);
        }
        printf("%d %d", turno, campo[7]);
    }
    if(mousex > 450 && mousex <= 650 && MAXY-mousey >= 50 && MAXY-mousey < 250)
{
        if(turno%2==1 && campo[8]==0){
            campo[8]=1;
            turno++;
            fim(8);
        }
        else if(campo[8]==0){
            campo[8]=2;
            turno++;
            fim(8);
        }
        printf("%d %d", turno, campo[8]);
    }
}

void xis(){
    if(campo[0]==1){
        glBegin(GL_LINES);
            glVertex2f(60,640);
            glVertex2f(240,460);
            glVertex2f(240,640);
            glVertex2f(60,460);
        glEnd();
    }
    if(campo[1]==1){
        glBegin(GL_LINES);
            glVertex2f(260,640);
            glVertex2f(440,460);
            glVertex2f(440,640);
            glVertex2f(260,460);
        glEnd();
    }
    if(campo[2]==1){
        glBegin(GL_LINES);
            glVertex2f(460,640);
            glVertex2f(640,460);
            glVertex2f(640,640);
            glVertex2f(460,460);
        glEnd();
    }
    if(campo[3]==1){
        glBegin(GL_LINES);
            glVertex2f(60,440);
            glVertex2f(240,260);
            glVertex2f(240,440);
            glVertex2f(60,260);
        glEnd();
    }
    if(campo[4]==1){
        glBegin(GL_LINES);
            glVertex2f(260,440);
            glVertex2f(440,260);
            glVertex2f(440,440);
            glVertex2f(260,260);
        glEnd();
    }
    if(campo[5]==1){
        glBegin(GL_LINES);
            glVertex2f(460,440);
            glVertex2f(640,260);
            glVertex2f(640,440);
            glVertex2f(460,260);
        glEnd();
    }
    if(campo[6]==1){
        glBegin(GL_LINES);
            glVertex2f(60,240);
            glVertex2f(240,60);
            glVertex2f(240,240);
            glVertex2f(60,60);
        glEnd();
    }
    if(campo[7]==1){
        glBegin(GL_LINES);
            glVertex2f(260,240);
            glVertex2f(440,60);
            glVertex2f(440,240);
            glVertex2f(260,60);
        glEnd();
    }
    if(campo[8]==1){
        glBegin(GL_LINES);
            glVertex2f(460,240);
            glVertex2f(640,60);
            glVertex2f(640,240);
            glVertex2f(460,60);
        glEnd();
    }
}

void bola(){
    GLfloat escala = 1;
    int i = 0;
    float ang, x, y;
    if(campo[0]==2){
        glBegin(GL_LINE_LOOP);
        for (i = 0; i < 360; i++) {
            ang = (i * PI) / 180.0;
            x = 150 + (cos(ang) * 90);
            y = 550 + (sin(ang) * 90);
            glVertex2f(x, y);
        }
     glEnd();
    }
    if(campo[1]==2){
        glBegin(GL_LINE_LOOP);
        for (i = 0; i < 360; i++) {
            ang = (i * PI) / 180.0;
            x = 350 + (cos(ang) * 90);
            y = 550 + (sin(ang) * 90);
            glVertex2f(x, y);
        }
     glEnd();
    }
    if(campo[2]==2){
        glBegin(GL_LINE_LOOP);
        for (i = 0; i < 360; i++) {
            ang = (i * PI) / 180.0;
            x = 550 + (cos(ang) * 90);
            y = 550 + (sin(ang) * 90);
            glVertex2f(x, y);
        }
     glEnd();
    }
    if(campo[3]==2){
        glBegin(GL_LINE_LOOP);
        for (i = 0; i < 360; i++) {
            ang = (i * PI) / 180.0;
            x = 150 + (cos(ang) * 90);
            y = 350 + (sin(ang) * 90);
            glVertex2f(x, y);
        }
     glEnd();
    }
    if(campo[4]==2){
        glBegin(GL_LINE_LOOP);
        for (i = 0; i < 360; i++) {
            ang = (i * PI) / 180.0;
            x = 350 + (cos(ang) * 90);
            y = 350 + (sin(ang) * 90);
            glVertex2f(x, y);
        }
     glEnd();
    }
    if(campo[5]==2){
        glBegin(GL_LINE_LOOP);
        for (i = 0; i < 360; i++) {
            ang = (i * PI) / 180.0;
            x = 550 + (cos(ang) * 90);
            y = 350 + (sin(ang) * 90);
            glVertex2f(x, y);
        }
     glEnd();
    }
    if(campo[6]==2){
        glBegin(GL_LINE_LOOP);
        for (i = 0; i < 360; i++) {
            ang = (i * PI) / 180.0;
            x = 150 + (cos(ang) * 90);
            y = 150 + (sin(ang) * 90);
            glVertex2f(x, y);
        }
     glEnd();
    }
    if(campo[7]==2){
        glBegin(GL_LINE_LOOP);
        for (i = 0; i < 360; i++) {
            ang = (i * PI) / 180.0;
            x = 350 + (cos(ang) * 90);
            y = 150 + (sin(ang) * 90);
            glVertex2f(x, y);
        }
     glEnd();
    }
    if(campo[8]==2){
        glBegin(GL_LINE_LOOP);
        for (i = 0; i < 360; i++) {
            ang = (i * PI) / 180.0;
            x = 550 + (cos(ang) * 90);
            y = 150 + (sin(ang) * 90);
            glVertex2f(x, y);
        }
     glEnd();
    }
}

void fim(int campo){
    if(turno >= 10){
        estado = 3;
        return;
    }
}
