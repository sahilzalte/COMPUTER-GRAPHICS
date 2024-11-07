#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>

int main() {
    int gd = DETECT, gm;


    int x, y;          // Original coordinates
    float angle;       // Angle of rotation
    float radian;      // Angle in radians
    int rotatedX, rotatedY;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    printf("Enter the coordinates of the point (x, y): ");
    scanf("%d %d", &x, &y);

    printf("Enter the angle of rotation (in degrees): ");
    scanf("%f", &angle);

    radian = angle * (M_PI / 180);
    rotatedX = x * cos(radian) - y * sin(radian);
    rotatedY = x * sin(radian) + y * cos(radian);
    printf("\nOriginal Coordinates: (%d, %d)", x, y);
    printf("\nRotated Coordinates: (%d, %d)", rotatedX, rotatedY);
    putpixel(x, y, WHITE);            // Original point in white
    putpixel(rotatedX, rotatedY, YELLOW);  // Rotated point in yellow
    getch();
    closegraph();
    return 0;
}
