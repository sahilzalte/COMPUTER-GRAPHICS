#include <graphics.h>
#include <conio.h>
#include <stdio.h>
int x_min, y_min, x_max, y_max; // Clipping window coordinates
int isInside(int x, int y) {
    return (x >= x_min && x <= x_max && y >= y_min && y <= y_max);
}
void midpointClip(int x1, int y1, int x2, int y2) {
    if (isInside(x1, y1) && isInside(x2, y2)) {
        setcolor(RED);
        line(x1, y1, x2, y2); // Draw the clipped line in red
    }
    else if ((x1 < x_min && x2 < x_min) || (x1 > x_max && x2 > x_max) || 
             (y1 < y_min && y2 < y_min) || (y1 > y_max && y2 > y_max)) {
        return; // The line is outside the window and completely invisible
    }
    else {
        int mid_x = (x1 + x2) / 2;
        int mid_y = (y1 + y2) / 2;
        midpointClip(x1, y1, mid_x, mid_y);
        midpointClip(mid_x, mid_y, x2, y2);
    }
}
int main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");
    // Input for clipping window coordinates
    printf("Enter the clipping window coordinates (x_min, y_min, x_max, y_max): ");
    scanf("%d %d %d %d", &x_min, &y_min, &x_max, &y_max);

    // Input for the line coordinates
    printf("Enter the line coordinates (x1, y1) and (x2, y2): ");
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    setcolor(WHITE);
    rectangle(x_min, y_min, x_max, y_max);

    setcolor(WHITE);
    line(x1, y1, x2, y2);

    midpointClip(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}
