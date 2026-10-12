#include <stdexcept>
double divide(double a, double b);
double sin(double theta);
double cos(double theta);

double tan(double theta){
    if ((theta) == 90.0 || (theta) == 270.0) {
        throw std::invalid_argument("Error: Division by zero in tan function.");
    } else {
        return divide(sin(theta), cos(theta));
    }

}