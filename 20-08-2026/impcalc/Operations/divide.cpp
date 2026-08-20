#include <iostream>
double divide(int a, int b) {
    if (b == 0) {
        std::cout << "Division by zero is not allowed." << std::endl;
        return 0; // Or handle the error in a way that makes sense for your application
    }
    return static_cast<double>(a) / b; 
}