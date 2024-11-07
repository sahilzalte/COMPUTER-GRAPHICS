#include <stdio.h>
#include <graphics.h>
#include <dos.h>

void drawCircle(int xc, int yc, int x, int y) {
    putpixel(xc + x, yc + y, RED);
    putpixel(xc - x, yc + y, RED);
    putpixel(xc + x, yc - y, RED);
    putpixel(xc - x, yc - y, RED);
    putpixel(xc + y, yc + x, RED);
    putpixel(xc - y, yc + x, RED);
    putpixel(xc + y, yc - x, RED);
    putpixel(xc - y, yc - x, RED);
}

void circleBres(int xc, int yc, int r) {
    int x = 0, y = r;
    int d = 3 - 2 * r;

    drawCircle(xc, yc, x, y);
    while (y >= x) {
	x++;

	if (d > 0) {
	    y--;
	    d = d + 4 * (x - y) + 10;
	} else {
	    d = d + 4 * x + 6;
	}

	drawCircle(xc, yc, x, y);
	delay(50);
    }
}

void main() {
    int gd = DETECT, gm;
    int xc = 200, yc = 200, r = 100;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    circleBres(xc, yc, r);
    getch();
   closegraph();
}