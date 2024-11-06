#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    // Draw face (circle)
    setcolor(RED);
    circle(200, 200, 100);

    // Draw eyes (circles)
    circle(160, 170, 20);
    circle(240, 170, 20);

    // Draw nose (triangle)
    line(200, 190, 180, 240);
    line(180, 240, 220, 240);
    line(200, 190, 220, 240);

    // Draw mouth (rectangle)
    rectangle(160, 260, 240, 280);

    getch();
    closegraph();
    return 0;
}
