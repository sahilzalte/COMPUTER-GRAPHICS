#include <graphics.h>
#include <math.h>
#include <conio.h>

void DDA_Line(int x1, int y1, int x2, int y2) {
    int dx, dy, steps, k;
    float xIncrement, yIncrement, x = x1, y = y1;

    dx = x2 - x1;
    dy = y2 - y1;

    // Determine the number of steps required for drawing the line
    if (abs(dx) > abs(dy)) {
        steps = abs(dx);
    } else {
        steps = abs(dy);
    }

    // Calculate the increment values for x and y
    xIncrement = dx / (float)steps;
    yIncrement = dy / (float)steps;

    // Plot the points
    for (k = 0; k <= steps; k++) {
        putpixel(round(x), round(y), WHITE);
        x += xIncrement;
        y += yIncrement;
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Define the starting and ending points
    int x1 = 100, y1 = 100, x2 = 300, y2 = 200;

    // Draw the line using DDA algorithm
    DDA_Line(x1, y1, x2, y2);

    // Wait for a key press
    getch();
    closegraph();
    return 0;
}
