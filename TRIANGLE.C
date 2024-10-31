#include<stdio.h>
#include<graphics.h>
#include<conio.h>
int main ()
{
int gd=DETECT,gm;
int x1=150,y1=100;
int x2=200,y2=200;
int x3=100,y3=200;
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
line(x1,y1,x2,y2);
line(x2,y2,x3,y3);
line(x3,y3,x1,y1);
getch();
closegraph();
}
