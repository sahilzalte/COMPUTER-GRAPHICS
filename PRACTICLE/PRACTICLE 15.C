#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>

void bezier(int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3) {
    float t;
    int x, y, prevX, prevY;
    
    // Initialize the previous point with the starting point P0
    prevX = x0;
    prevY = y0;
    
    // Loop to calculate the Bezier curve and draw lines between the points
    for(t = 0; t <= 1; t += 0.001) {  // Decreased t increment to make the curve smoother
        // Calculate the x and y coordinates using the Bezier formula
        x = pow(1 - t, 3) * x0 + 3 * pow(1 - t, 2) * t * x1 + 3 * (1 - t) * t * t * x2 + pow(t, 3) * x3;
        y = pow(1 - t, 3) * y0 + 3 * pow(1 - t, 2) * t * y1 + 3 * (1 - t) * t * t * y2 + pow(t, 3) * y3;
        
        // Draw a line from the previous point to the current point
        line(prevX, prevY, x, y);
        
        // Update previous point to current point
        prevX = x;
        prevY = y;
    }
}

int main() {
    int gd = DETECT, gm;
    int x0, y0, x1, y1, x2, y2, x3, y3;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    
    // Display clear prompts for the user to enter control points
    printf("Bezier Curve Drawing Program\n");
    printf("Please enter the coordinates for the four control points:\n");
    
    // User-friendly prompts for control points
    printf("Enter the coordinates for Point P0 (x0, y0) as the starting point of the curve: ");
    scanf("%d %d", &x0, &y0);
    printf("Enter the coordinates for Point P1 (x1, y1) as the first control point: ");
    scanf("%d %d", &x1, &y1);
    printf("Enter the coordinates for Point P2 (x2, y2) as the second control point: ");
    scanf("%d %d", &x2, &y2);
    printf("Enter the coordinates for Point P3 (x3, y3) as the ending point of the curve: ");
    scanf("%d %d", &x3, &y3);

    // Draw the Bezier curve
    bezier(x0, y0, x1, y1, x2, y2, x3, y3);
    
    getch();  // Wait for user input
    closegraph();  // Close graphics mode
    return 0;
}
