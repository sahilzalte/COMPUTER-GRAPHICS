#include <graphics.h>
#include <conio.h>

int main() {
    // Initialize graphics mode
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    // Draw the head (circle)
    circle(250, 100, 30); // (x, y, radius)

    // Draw the eyes (circles)
    circle(240, 90, 5);  // Left eye
    circle(260, 90, 5);  // Right eye

    // Draw the body (ellipse)
    ellipse(250, 210, 0, 360, 30, 80); // (x, y, start_angle, end_angle, x_radius, y_radius)

    // Draw the arms (lines)
    line(220, 200, 180, 240);  // Left arm
    line(280, 200, 320, 240);  // Right arm

    getch(); // Wait for a key press
    closegraph(); // Close the graphics mode
    return 0;
}