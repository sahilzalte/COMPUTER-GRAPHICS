#include <graphics.h>
#include <conio.h>
#include <dos.h>

// Flood fill function to replace the target color with the fill color
void floodFill(int x, int y, int fillColor, int borderColor) {
    int currentColor = getpixel(x, y);

    // Check if the current pixel is not the border color or the fill color
    if (currentColor != borderColor && currentColor != fillColor) {
        putpixel(x, y, fillColor);

        // Recursively fill neighboring pixels
        floodFill(x + 1, y, fillColor, borderColor);
        floodFill(x - 1, y, fillColor, borderColor);
        floodFill(x, y + 1, fillColor, borderColor);
        floodFill(x, y - 1, fillColor, borderColor);
    }
}

int main() {
    int gd = DETECT, gm;
     int borderColor = WHITE; // Define border color
    int left, top, right, bottom;
    int seedX, seedY;
    int fillColor;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    // User input prompts
    printf("Enter the top-left corner of the rectangle (x, y): ");
    scanf("%d %d", &left, &top);
    printf("Enter the bottom-right corner of the rectangle (x, y): ");
    scanf("%d %d", &right, &bottom);

    printf("Enter the seed point (x, y) inside the rectangle: ");
    scanf("%d %d", &seedX, &seedY);

    printf("Enter the fill color code (1-15): ");
    scanf("%d", &fillColor);



    // Draw the rectangle as a boundary
    setcolor(borderColor);
    rectangle(left, top, right, bottom);

    // Apply flood fill algorithm
    floodFill(seedX, seedY, fillColor, borderColor);

    getch();
    closegraph();
    return 0;
}
