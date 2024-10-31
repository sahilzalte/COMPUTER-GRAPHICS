#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    // Draw the top rectangle (smaller one)
    rectangle(250, 100, 350, 150);

    // Draw an additional smaller rectangle inside the top rectangle
    rectangle(270, 120, 330, 140);

    // Draw the middle rectangle (larger one)
    rectangle(150, 180, 450, 230);

    // Draw lines connecting the rectangles
    line(250, 150, 150, 180); // Left line
    line(350, 150, 450, 180); // Right line

    getch();
    closegraph();
    return 0;
}
