#include <stdio.h>
#include <graphics.h>
#include <conio.h>
int main()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
putpixel(100,200,RED) ;
putpixel(200,200,GREEN);
putpixel(300,200,BLUE) ;



    getch();
    closegraph();
    return 0;
}
