#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>
#define PI 3.14159265
void plot_point(int x, int y, int color) {
    putpixel(320 + x, 240 - y, color);  // Offset to center the plot on screen
}
int main() {
    int gd = DETECT, gm;
    float x, y, z;              // Original coordinates of the point
    float angle;                // Rotation angle in degrees
    int choice;                 // Axis of rotation choice
    float radian;               // Angle in radians for rotation
    float rotatedX, rotatedY, rotatedZ;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");
    printf("Enter the coordinates of the point (x, y, z): ");
    scanf("%f %f %f", &x, &y, &z);
    printf("Enter the angle of rotation (in degrees): ");
    scanf("%f", &angle);
    radian = angle * (PI / 180.0);
    printf("Choose the axis of rotation (1 for X-axis, 2 for Y-axis, 3 for Z-axis): ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:  // Rotation around X-axis
            rotatedX = x;
            rotatedY = y * cos(radian) - z * sin(radian);
            rotatedZ = y * sin(radian) + z * cos(radian);
            break;
        case 2:  // Rotation around Y-axis
            rotatedX = x * cos(radian) + z * sin(radian);
            rotatedY = y;
            rotatedZ = -x * sin(radian) + z * cos(radian);
            break;
        case 3:  // Rotation around Z-axis
            rotatedX = x * cos(radian) - y * sin(radian);
            rotatedY = x * sin(radian) + y * cos(radian);
            rotatedZ = z;
            break;
        default:
            printf("Invalid choice! No rotation applied.\n");
            rotatedX = x;
            rotatedY = y;
            rotatedZ = z;
    }
    plot_point((int)x, (int)y, WHITE);
    outtextxy(320 + (int)x, 240 - (int)y, "Original");
    plot_point((int)rotatedX, (int)rotatedY, YELLOW);
    outtextxy(320 + (int)rotatedX, 240 - (int)rotatedY, "Rotated");
    printf("\nOriginal Coordinates: (%.2f, %.2f, %.2f)", x, y, z);
    printf("\nRotated Coordinates: (%.2f, %.2f, %.2f)", rotatedX, rotatedY, rotatedZ);
    getch();
    closegraph();
    return 0;
}
