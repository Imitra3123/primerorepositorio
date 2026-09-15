#include <iostream>
double divide(double a, double b) {
    if (b == 0) {
        std::cout << "Division by zero is not allowed." << std::endl;
        return 0; 
    }
    return a / b; 
}