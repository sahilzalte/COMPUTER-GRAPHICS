#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;

    // Initialize graphics mode
    initgraph(&gd, &gm, "");

    // Set color and draw an Ellipse with center (320, 240), width radius 150, and height radius 100
    setcolor(BLUE);
    ellipse(320, 240, 0, 360, 150, 100);

    // Wait for a key press before closing the graphics window
    getch();
    closegraph();
    return 0;
}
