#include <stdio.h>

void main() {
    float x, y, z;          // Original coordinates of the point
    float tx, ty, tz;       // Translation values for x, y, and z
    float sx, sy, sz;       // Scaling factors for x, y, and z
    float translatedX, translatedY, translatedZ;  // Translated coordinates
    float scaledX, scaledY, scaledZ;
    clrscr();              // Scaled coordinates

    // Input for original coordinates of the point
    printf("Enter the coordinates of the point (x, y, z): ");
    scanf("%f %f %f", &x, &y, &z);

    // Input for translation values
    printf("Enter the translation values (tx, ty, tz): ");
    scanf("%f %f %f", &tx, &ty, &tz);

    // Perform translation
    translatedX = x + tx;
    translatedY = y + ty;
    translatedZ = z + tz;

    // Input for scaling factors
    printf("Enter the scaling factors (sx, sy, sz): ");
    scanf("%f %f %f", &sx, &sy, &sz);

    // Perform scaling on the translated coordinates
    scaledX = translatedX * sx;
    scaledY = translatedY * sy;
    scaledZ = translatedZ * sz;

    // Display results
    printf("\nOriginal Coordinates: (%.2f, %.2f, %.2f)", x, y, z);
    printf("\nTranslated Coordinates: (%.2f, %.2f, %.2f)", translatedX, translatedY, translatedZ);
    printf("\nScaled Coordinates after Translation: (%.2f, %.2f, %.2f)", scaledX, scaledY, scaledZ);

   getch();
}