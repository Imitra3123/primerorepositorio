#include <stdexcept>

double subtract(double a, double b);
double multiply(double a, double b);

int factorial(int n) {
    if (n < 0) {
        throw std::invalid_argument("Negative input not allowed");
    }
    if (n == 0 || n == 1) {
        return 1;
    }
    return multiply(n,factorial(subtract(n, 1)));
}