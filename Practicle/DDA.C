#include <stdio.h>
#include <math.h>
#include<graphics.h>

int roundToInt(float value)
{
    return (int)(value + 0.5f);
}
void DDA(int x1, int y1, int x2, int y2)
{
    float dx = x2 - x1;
    float dy = y2 - y1;
    int i;
    int steps = (fabs(dx) > fabs(dy)) ? fabs(dx) : fabs(dy);
    float xIncrement = dx / steps;
    float yIncrement = dy / steps;
    float x = x1;
    float y = y1;
    for (i = 0; i <= steps; i++)
    {
        putpixel(roundToInt(x),roundToInt(y),WHITE);
        x+=xIncrement;
        y+=yIncrement;
    }
}
int main()
{
    int x1,y1,x2,y2;
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

    printf("Enter x1 y1: ");
    scanf("%d %d",&x1,&y1);
    printf("Enter x2 y2: ");
    scanf("%d %d",&x2,&y2);
    DDA(x1,y1,x2,y2);
    getch();
    closegraph();
    return 0;
}