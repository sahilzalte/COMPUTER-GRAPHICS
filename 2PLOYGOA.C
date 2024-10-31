#include<stdio.h>
#include<graphics.h>
#include<conio.h>
int main ()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
line(150,100,200,150);
line(200,150,175,200);
line(175,200,125,200);
line(125,200,100,150);
line(100,150,150,100);
getch();
closegraph();
return 0;
}