#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    // Draw the front rectangle of the house
    rectangle(150, 200, 250, 300);
	// Draw the side rectangle of the house
    line(250, 200, 390, 200); // Top line of the side rectangle
    line(390, 300, 390, 200); // Right side of the side rectangle
    line(390, 300, 250, 300); // Bottom line of the side rectangle

    // Draw the roof of the house
    line(150, 200, 200, 120); // Left side of the roof
    line(200, 120, 330, 120); // Right side of the roof

    // Draw the inner roof line connecting front and side
    line(200, 120, 250, 200);
    line(330, 120, 390, 200);

    getch();
    closegraph();
    return 0;
}
