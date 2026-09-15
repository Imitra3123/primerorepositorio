#include <stdexcept>

double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
int factorial(int n);

int combination(int n, int r) {
    if (n < 0 || r < 0 || r > n) {
        throw std::invalid_argument("Invalid input for combination");
    }
    return divide(factorial(n),multiply(factorial(r),factorial(subtract(n, r))));
}