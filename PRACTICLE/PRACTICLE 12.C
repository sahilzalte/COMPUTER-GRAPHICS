#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#define LEFT 1    // Binary codes for the 4 regions
#define RIGHT 2
#define BOTTOM 4
#define TOP 8
int x_min, y_min, x_max, y_max; // Clipping window coordinates
int computeCode(int x, int y) {
    int code = 0;
    if (x < x_min) code |= LEFT;
    if (x > x_max) code |= RIGHT;
    if (y < y_min) code |= BOTTOM;
    if (y > y_max) code |= TOP;
    return code;
}
void cohenSutherlandClip(int x1, int y1, int x2, int y2) {
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);
    int accept = 0;
    while (1) {
        if ((code1 == 0) && (code2 == 0)) { // Both endpoints inside rectangle
            accept = 1;
            break;
        } else if (code1 & code2) {         // Both endpoints share an outside region
            break;
        } else {
            int code_out;
            int x, y;
            if (code1 != 0)
                code_out = code1;
            else
                code_out = code2;
            if (code_out & TOP) {           // Point above the clip rectangle
                x = x1 + (x2 - x1) * (y_max - y1) / (y2 - y1);
                y = y_max;
            } else if (code_out & BOTTOM) {  // Point below the clip rectangle
                x = x1 + (x2 - x1) * (y_min - y1) / (y2 - y1);
                y = y_min;
            } else if (code_out & RIGHT) {   // Point to the right of clip rectangle
                y = y1 + (y2 - y1) * (x_max - x1) / (x2 - x1);
                x = x_max;
            } else if (code_out & LEFT) {    // Point to the left of clip rectangle
                y = y1 + (y2 - y1) * (x_min - x1) / (x2 - x1);
                x = x_min;
            }
            if (code_out == code1) {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            } else {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    }
    if (accept) {
        setcolor(RED);
        line(x1, y1, x2, y2);  // Draw clipped line in red
    } else {
        printf("Line is outside the clipping window.\n");
    }
}
int main() {
    int gd = DETECT, gm;
       int x1, y1, x2, y2;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");
    printf("Enter the clipping window coordinates (x_min, y_min, x_max, y_max): ");
    scanf("%d %d %d %d", &x_min, &y_min, &x_max, &y_max);
    printf("Enter the line coordinates (x1, y1) and (x2, y2): ");
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    setcolor(WHITE);
    rectangle(x_min, y_min, x_max, y_max);
    setcolor(WHITE);
    line(x1, y1, x2, y2);
    cohenSutherlandClip(x1, y1, x2, y2);
    getch();
    closegraph();
    return 0;
}
