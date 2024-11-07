#include <graphics.h>
#include <conio.h>
#include <dos.h>
void boundaryFill(int x, int y, int fillColor, int boundaryColor) {
    int currentColor = getpixel(x, y);
    if (currentColor != boundaryColor && currentColor != fillColor) {
        putpixel(x, y, fillColor);

        // Recursively fill the neighboring pixels
        boundaryFill(x + 1, y, fillColor, boundaryColor);
        boundaryFill(x - 1, y, fillColor, boundaryColor);
        boundaryFill(x, y + 1, fillColor, boundaryColor);
        boundaryFill(x, y - 1, fillColor, boundaryColor);
    }
}
int main() {
    int gd = DETECT, gm;
    int boundaryColor = WHITE;
    int left, top, right, bottom;
    int seedX, seedY;
    int fillColor;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");
    printf("Enter the top-left corner of the rectangle (x, y): ");
    scanf("%d %d", &left, &top);
    printf("Enter the bottom-right corner of the rectangle (x, y): ");
    scanf("%d %d", &right, &bottom);
    printf("Enter the seed point (x, y) inside the rectangle: ");
    scanf("%d %d", &seedX, &seedY);
    printf("Enter the fill color code (1-15): ");
    scanf("%d", &fillColor);
    setcolor(boundaryColor);
    rectangle(left, top, right, bottom);
    boundaryFill(seedX, seedY, fillColor, boundaryColor);
    getch();
    closegraph();
    return 0;
}
