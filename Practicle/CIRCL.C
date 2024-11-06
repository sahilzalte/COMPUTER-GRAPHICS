#include<stdio.h>
#include<conio.h>
#include<graphics.h>
int main ()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\TURBOC3\\BGI");
setcolor(RED);
circle(260,200,60);
getch();
closegraph();
return 0;
}