#include <iostream>
#include <cmath>
int root(int a, int b) {
    if (a < 0 && b % 2 == 0) {
        std::cerr << "Error: Cannot compute even root of a negative number." << std::endl;
        return -1; // Indicate an error
    }
    return static_cast<int>(pow(a, 1.0 / b));
}