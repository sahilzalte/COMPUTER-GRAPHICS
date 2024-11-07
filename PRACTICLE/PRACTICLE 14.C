#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#define MAX_POINTS 20
int x_min, y_min, x_max, y_max;
typedef struct {
    int x, y;
} Point;
int isInside(Point p, int edge) {
    switch(edge) {
        case 1: return (p.x >= x_min); // Left
        case 2: return (p.x <= x_max); // Right
        case 3: return (p.y >= y_min); // Bottom
        case 4: return (p.y <= y_max); // Top
    }
    return 0;
}
Point intersect(Point p1, Point p2, int edge) {
    Point temp;
    float m;

    if (p1.x != p2.x) m = (float)(p2.y - p1.y) / (p2.x - p1.x);
    else m = 100000.0; // Large number to avoid division by zero

    switch(edge) {
        case 1: // Left
            temp.x = x_min;
            temp.y = p1.y + (x_min - p1.x) * m;
            break;
        case 2: // Right
            temp.x = x_max;
            temp.y = p1.y + (x_max - p1.x) * m;
            break;
        case 3: // Bottom
            temp.y = y_min;
            if (p1.x != p2.x) temp.x = p1.x + (y_min - p1.y) / m;
            else temp.x = p1.x;
            break;
        case 4: // Top
            temp.y = y_max;
            if (p1.x != p2.x) temp.x = p1.x + (y_max - p1.y) / m;
            else temp.x = p1.x;
            break;
    }
    return temp;
}
void clipEdge(Point *poly_points, int *poly_size, int edge) {
    Point new_points[MAX_POINTS];
    int new_size = 0;
    int i;

    Point v1 = poly_points[*poly_size - 1];
    for (i = 0; i < *poly_size; i++) {
        Point v2 = poly_points[i];

        if (isInside(v2, edge)) {
            if (isInside(v1, edge)) {
                new_points[new_size++] = v2;
            } else {
                new_points[new_size++] = intersect(v1, v2, edge);
                new_points[new_size++] = v2;
            }
        } else if (isInside(v1, edge)) {
            new_points[new_size++] = intersect(v1, v2, edge);
        }
        v1 = v2;
    }

    *poly_size = new_size;
    for (i = 0; i < new_size; i++) {
        poly_points[i] = new_points[i];
    }
}

void sutherlandHodgmanClip(Point *poly_points, int *poly_size) {
    clipEdge(poly_points, poly_size, 1); // Left edge
    clipEdge(poly_points, poly_size, 2); // Right edge
    clipEdge(poly_points, poly_size, 3); // Bottom edge
    clipEdge(poly_points, poly_size, 4); // Top edge
}

int main() {
    int gd = DETECT, gm;
    Point poly_points[MAX_POINTS];
    int poly_size, i;
    clrscr();

    printf("Enter the clipping window coordinates (x_min, y_min, x_max, y_max): ");
    scanf("%d %d %d %d", &x_min, &y_min, &x_max, &y_max);

    printf("Enter the number of vertices in the polygon: ");
    scanf("%d", &poly_size);

    printf("Enter the coordinates of the polygon vertices (x y):\n");
    for (i = 0; i < poly_size; i++) {
        printf("Vertex %d: ", i + 1);
        scanf("%d %d", &poly_points[i].x, &poly_points[i].y);
    }

    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    setcolor(WHITE);
    rectangle(x_min, y_min, x_max, y_max);

    for (i = 0; i < poly_size - 1; i++) {
        line(poly_points[i].x, poly_points[i].y, poly_points[i + 1].x, poly_points[i + 1].y);
    }
    line(poly_points[poly_size - 1].x, poly_points[poly_size - 1].y, poly_points[0].x, poly_points[0].y);

    sutherlandHodgmanClip(poly_points, &poly_size);
    setcolor(RED);
    for (i = 0; i < poly_size - 1; i++) {
        line(poly_points[i].x, poly_points[i].y, poly_points[i + 1].x, poly_points[i + 1].y);
    }
    line(poly_points[poly_size - 1].x, poly_points[poly_size - 1].y, poly_points[0].x, poly_points[0].y);

    getch();
    closegraph();
    return 0;
}
