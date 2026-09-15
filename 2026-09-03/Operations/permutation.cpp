#include <stdexcept>

double subtract(double a, double b);
double divide(double a, double b);
int factorial(int n);

int permute(int n, int r) {
    if (n < 0 || r < 0 || r > n) {
        throw std::invalid_argument("Invalid input for permutation");
    }
    return divide(factorial(n),factorial(subtract(n, r)));
}