#include <iostream>
#include <cmath>  // For fabs()

using namespace std;

int main() {
    float dx, dy;

    // Input the two values dx and dy
    cout << "Enter the value of dx: ";
    cin >> dx;
    cout << "Enter the value of dy: ";
    cin >> dy;

    // Find the maximum of the absolute values of dx and dy
    float max_value = max(fabs(dx), fabs(dy));

    // Output the maximum value
    cout << "The maximum value between |dx| and |dy| is: " << max_value << endl;

    return 0;
}
