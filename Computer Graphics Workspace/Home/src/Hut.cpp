#include <graphics.h>   // Ensure you have set up graphics.h correctly
#include <iostream>
using namespace std;

int main() {
    int gdriver = DETECT, gmode;

    // Initialize graphics mode
    initgraph(&gdriver, &gmode, (char*)"");

    if (graphresult() != 0) {
        cerr << "Graphics initialization failed." << endl;
        return 1;
    }

    // Your drawing code here

    closegraph();
    return 0;
}
