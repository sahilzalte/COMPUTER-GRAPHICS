#include <graphics.h>
#include <conio.h>
int main() {

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");


    setcolor(WHITE);

    line(100, 300, 400, 300);


    getch();


    closegraph();
    return 0;
}
