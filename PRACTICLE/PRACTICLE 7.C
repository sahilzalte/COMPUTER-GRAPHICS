#include <graphics.h>
#include <conio.h>
#include <stdio.h>
int main() {
    int gd = DETECT, gm;
    int x, y;         // Original coordinates
    int tx, ty;       // Translation values
    float sx, sy;     // Scaling factors
    int translatedX, translatedY, scaledX, scaledY;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");
    printf("Enter the coordinates of the point (x, y): ");
    scanf("%d %d", &x, &y);
    printf("Enter the translation values (tx, ty): ");
    scanf("%d %d", &tx, &ty);
    printf("Enter the scaling factors (sx, sy): ");
    scanf("%f %f", &sx, &sy);
    translatedX = x + tx;
    translatedY = y + ty;
    scaledX = translatedX * sx;
    scaledY = translatedY * sy;
    printf("\nOriginal Coordinates: (%d, %d)", x, y);
    printf("\nTranslated Coordinates: (%d, %d)", translatedX, translatedY);
    printf("\nScaled Coordinates after Translation: (%.2f, %.2f)", scaledX, scaledY);
    putpixel(x, y, WHITE);            // Original point in white
    putpixel(translatedX, translatedY, YELLOW);  // Translated point in yellow
    putpixel(scaledX, scaledY, GREEN);           // Scaled point in green
    getch();
    closegraph();
    return 0;
}
