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
void fim(int);
void desenhaXis(int, int);
void desenhaBola(int, int);

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
    if(estado==0){
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
    }
    }
}

void xis(){
    if(campo[0]==1){
        desenhaXis(150,550);
    }
    if(campo[1]==1){
        desenhaXis(350,550);
    }
    if(campo[2]==1){
        desenhaXis(550,550);
    }
    if(campo[3]==1){
        desenhaXis(150,350);
    }
    if(campo[4]==1){
        desenhaXis(350,350);
    }
    if(campo[5]==1){
        desenhaXis(550,350);
    }
    if(campo[6]==1){
        desenhaXis(150,150);
    }
    if(campo[7]==1){
        desenhaXis(350,150);
    }
    if(campo[8]==1){
        desenhaXis(550,150);
    }
}

void bola(){
    if(campo[0]==2){
        desenhaBola(150, 550);
    }
    if(campo[1]==2){
        desenhaBola(350, 550);
    }
    if(campo[2]==2){
        desenhaBola(550, 550);
    }
    if(campo[3]==2){
        desenhaBola(150, 350);
    }
    if(campo[4]==2){
        desenhaBola(350, 350);
    }
    if(campo[5]==2){
        desenhaBola(550, 350);
    }
    if(campo[6]==2){
        desenhaBola(150, 150);
    }
    if(campo[7]==2){
        desenhaBola(350, 150);
    }
    if(campo[8]==2){
        desenhaBola(550, 150);
    }
}

void fim(int lugar){
    printf("%d %d\n", turno, campo[lugar]);
    if(turno >= 10){
        estado = 3;
        return;
    }
    if(turno%2==0){
        if(lugar==0){
            if(campo[1]==1 && campo[2]==1)
                estado = 1;
            if(campo[3]==1 && campo[6]==1)
                estado = 1;
            if(campo[4]==1 && campo[8]==1)
                estado = 1;
        }
        if(lugar==1){
            if(campo[0]==1 && campo[2]==1)
                estado = 1;
            if(campo[4]==1 && campo[7]==1)
                estado = 1;
        }
        if(lugar==2){
            if(campo[1]==1 && campo[0]==1)
                estado = 1;
            if(campo[5]==1 && campo[8]==1)
                estado = 1;
            if(campo[4]==1 && campo[6]==1)
                estado = 1;
        }
        if(lugar==3){
            if(campo[0]==1 && campo[6]==1)
                estado = 1;
            if(campo[4]==1 && campo[5]==1)
                estado = 1;
        }
        if(lugar==4){
            if(campo[0]==1 && campo[8]==1)
                estado = 1;
            if(campo[2]==1 && campo[6]==1)
                estado = 1;
            if(campo[3]==1 && campo[5]==1)
                estado = 1;
            if(campo[1]==1 && campo[7]==1)
                estado = 1;
        }
        if(lugar==5){
            if(campo[4]==1 && campo[3]==1)
                estado = 1;
            if(campo[2]==1 && campo[8]==1)
                estado = 1;
        }
        if(lugar==6){
            if(campo[4]==1 && campo[2]==1)
                estado = 1;
            if(campo[0]==1 && campo[3]==1)
                estado = 1;
            if(campo[7]==1 && campo[8]==1)
                estado = 1;
        }
        if(lugar==7){
            if(campo[1]==1 && campo[4]==1)
                estado = 1;
            if(campo[8]==1 && campo[6]==1)
                estado = 1;
        }
        if(lugar==8){
            if(campo[0]==1 && campo[4]==1)
                estado = 1;
            if(campo[2]==1 && campo[5]==1)
                estado = 1;
            if(campo[6]==1 && campo[7]==1)
                estado = 1;
        }
    }
    if(turno%2==1){
        if(lugar==0){
            if(campo[1]==2 && campo[2]==2)
                estado = 2;
            if(campo[3]==2 && campo[6]==2)
                estado = 2;
            if(campo[4]==2 && campo[8]==2)
                estado = 2;
        }
        if(lugar==1){
            if(campo[0]==2 && campo[2]==2)
                estado = 2;
            if(campo[4]==2 && campo[7]==2)
                estado = 2;
        }
        if(lugar==2){
            if(campo[1]==2 && campo[0]==2)
                estado = 2;
            if(campo[5]==2 && campo[8]==2)
                estado = 2;
            if(campo[4]==2 && campo[6]==2)
                estado = 2;
        }
        if(lugar==3){
            if(campo[0]==2 && campo[6]==2)
                estado = 2;
            if(campo[4]==2 && campo[5]==2)
                estado = 2;
        }
        if(lugar==4){
            if(campo[0]==2 && campo[8]==2)
                estado = 2;
            if(campo[2]==2 && campo[6]==2)
                estado = 2;
            if(campo[3]==2 && campo[5]==2)
                estado = 2;
            if(campo[1]==2 && campo[7]==2)
                estado = 2;
        }
        if(lugar==5){
            if(campo[4]==2 && campo[3]==2)
                estado = 2;
            if(campo[2]==2 && campo[8]==2)
                estado = 2;
        }
        if(lugar==6){
            if(campo[4]==2 && campo[2]==2)
                estado = 2;
            if(campo[0]==2 && campo[3]==2)
                estado = 2;
            if(campo[7]==2 && campo[8]==2)
                estado = 2;
        }
        if(lugar==7){
            if(campo[1]==2 && campo[4]==2)
                estado = 2;
            if(campo[8]==2 && campo[6]==2)
                estado = 2;
        }
        if(lugar==8){
            if(campo[0]==2 && campo[4]==2)
                estado = 2;
            if(campo[2]==2 && campo[5]==2)
                estado = 2;
            if(campo[6]==2 && campo[7]==2)
                estado = 2;

        }
    }
}

void desenhaXis(int x, int y){
    glBegin(GL_LINES);
            glVertex2f(x-90,y+90);
            glVertex2f(x+90,y-90);
            glVertex2f(x+90,y+90);
            glVertex2f(x-90,y-90);
    glEnd();
}

void desenhaBola(int centrox, int centroy){
    GLfloat escala = 1;
    int i = 0;
    float ang, x, y;
    glBegin(GL_LINE_LOOP);
        for (i = 0; i < 360; i++) {
            ang = (i * PI) / 180.0;
            x = centrox + (cos(ang) * 90);
            y = centroy + (sin(ang) * 90);
            glVertex2f(x, y);
        }
     glEnd();
}
