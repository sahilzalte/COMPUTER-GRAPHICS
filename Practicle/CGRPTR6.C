#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    // Draw the circle (sun)
    circle(300, 200, 100);

    // Top triangle (outside the circle)
    line(280, 90, 320, 90);
    line(280, 90, 300, 50);
    line(320, 90, 300, 50);

    // Bottom triangle (outside the circle)
    line(280, 310, 320, 310);
    line(280, 310, 300, 350);
    line(320, 310, 300, 350);

    // Right triangle (outside the circle)
    line(400, 180, 400, 220);
    line(400, 180, 440, 200);
    line(400, 220, 440, 200);

    // Left triangle (outside the circle)
    line(200, 180, 200, 220);
    line(200, 180, 160, 200);
    line(200, 220, 160, 200);

    // Bottom-right diagonal triangle (outside the circle)
    line(375, 295, 405, 255); // Adjusted
    line(378, 290, 460, 320);
    line(400, 265, 460, 320);

    // Bottom-left diagonal triangle (outside the circle)
    line(225, 295, 195, 255); // Adjusted
    line(222, 290, 140, 320);
    line(200, 265, 140, 320);

    // Top-left diagonal triangle (outside the circle)
    line(225, 105, 195, 145); // Adjusted
    line(222, 110, 140, 80);
    line(200, 135, 140, 80);

    // Top-right diagonal triangle (outside the circle)
    line(375, 105, 405, 145); // Adjusted
    line(378, 110, 460, 80);
    line(400, 135, 460, 80);

    getch();
    closegraph();
    return 0;
}
