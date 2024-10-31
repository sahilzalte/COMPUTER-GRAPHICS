#include<graphics.h>
#include<conio.h>
#include<graphics.h>
void drawline(int x0,int y0,int x1,int y1)
{
int dx,dy,p,x,y;
dx=x1-x0;
dy=y1-y0;
x=x0;
y=y0;
p=2*dy-dx;
putpixel(x,y,WHITE);
while(x<x1)
{
x++;
if(p<0)
{
p=p+2*dy;
}
else
{
y++;
p=p+2*dy-2*dx;
}
putpixel(x,y,WHITE);
}
}
int main()
{
int gd=DETECT,gm;
int x0,y0,x1,y1;
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
printf("Enter the co-ordinates of the first point(x0,y0):");
scanf("%d %d",&x0,&y0);
printf("Enter the co-ordinates of the first point(x1,y1):");
scanf("%d %d",&x1,&y1);
drawline(x0,y0,x1,y1);
getch();
closegraph();
return 0;
}