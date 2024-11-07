#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    // Draw the body of the truck (rectangle)
    rectangle(150, 100, 350, 170);

    // Draw the wheels of the truck (circles)
    circle(200, 210, 40); // Left wheel
    circle(300, 210, 40); // Right wheel

    getch();
    closegraph();
    return 0;
}
