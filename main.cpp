#include <iostream>
#include <graphics.h>


typedef struct
{
    int x=70,y=160;
    int tip;
}TBoton;

using namespace std;
void dibuja_men();
void hacerbotons();
void dibuja_btn(TBoton Btn);
int detectaClic(int cx,int cy);
int checaClick(void);
void dibujaInst(void);

int main(void)
{
    int men=4;
    initwindow(600,600);
    while(men!=1)
    {
        switch(men)
        {
            case 2:
                readimagefile("rules.jpg",0,0,600,600);
                break;
            case 3:
                closegraph();
                break;
            case 4:
                cleardevice();
                dibuja_men();
                hacerbotons();
                break;
        }
        men=checaClick();
    }
    return 0;
}

void dibuja_men()
{
    setcolor(YELLOW);
    rectangle(40,20,330,130);
    settextstyle(3,HORIZ_DIR,2);
    outtextxy(50,25,"Damas Inglesas\n");
    outtextxy(50,50,"Juego hecho por:\n");
    outtextxy(50,75,"Jose Martin Cerda Estrada\n");
    outtextxy(50,100,"Luis Felipe Mondragon Cuevas");
    readimagefile("00.jpg",380,20,150,200);
}

void hacerbotons(void)
{
    TBoton B1,B2,B3;
    B1.tip =1;
    dibuja_btn(B1);
    B2.tip =2;
    B2.y+=40;
    dibuja_btn(B2);
    B3.tip=3;
    B3.y+=80;
    dibuja_btn(B3);
}

void dibuja_btn(TBoton Btn)
{
    setcolor(YELLOW);
    circle(Btn.x,Btn.y,10);
    settextstyle(5,HORIZ_DIR,4);
    switch(Btn.tip)
    {
        case 1:
            outtextxy(Btn.x+10,Btn.y+10,"Jugar");
            break;
        case 2:
            outtextxy(Btn.x+10,Btn.y+10,"Instrucciones");
            break;
        case 3:
            outtextxy(Btn.x+10,Btn.y+10,"Salir");
            break;
    }
}

int detectaClic(int cx,int cy)
{
    int opc=0;
    if((cx>=70&&cx<=80)&&(cy>=160&&cy<=200))
    {
        opc=1;
    }
    if((cx>=70&&cx<=80)&&(cy>=200&&cy<=240))
    {
        opc=2;
    }
    if((cx>=70&&cx<=80)&&(cy>=240&&cy<=280))
    {
        opc=3;
    }
    if((cx>=448&&cx<=542)&&(cy>=538&&cy<=597))
    {
        opc=4;
    }
    return(opc);
}

int checaClick(void)
{
    POINT click;
    int band=0;
    do
    {
        while(!GetAsyncKeyState(VK_LBUTTON)){}
        GetCursorPos(&click);
        band=detectaClic(click.x,click.y);
    }while(!band);
    return(band);
}


