double add(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
int factorial(int n);

double sin(double theta) {
    double x_0 = static_cast<double>(static_cast<long long>(theta / 360.0)); 
    if (x_0 < 0.0) {
        x_0 += 360.0;
    }

    double x_1 = multiply(x_0, divide(3.14159265358979323846, 180.0)); // Convert degrees to radians
    double result = 0.0;

    for (int i = 0; i < 7; ++i) {
        int exponent = add(multiply(2, i), 1);
        double x_power = 1.0;
            
        for (int j = 0; j < exponent; ++j) {
            x_power = multiply(x_power, x_1);
        }

        double sign = (i % 2 == 0) ? 1.0 : -1.0;
        double term = divide(multiply(sign, x_power), static_cast<double>(factorial(exponent)));
        result = add(result, term);
    }

    return result;
}