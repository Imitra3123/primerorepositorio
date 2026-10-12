double add(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
double factorial(int n); // Changed return type to double to prevent overflow

double sin(double theta) {
    double rotations = static_cast<double>(static_cast<long long>(theta / 360.0));
    double x_0 = theta - multiply(rotations, 360.0); 
    
    if (x_0 < 0.0) {
        x_0 = add(x_0, 360.0);
    }

    double pi = 3.14159265358979323846;
    double x_1 = multiply(x_0, divide(pi, 180.0)); 
    
    double result = 0.0;

    for (int i = 0; i < 7; ++i) {
        int exponent = (2 * i) + 1; // 1, 3, 5, 7, 9, 11, 1

        double x_power = 1.0;
        for (int j = 0; j < exponent; ++j) {
            x_power = multiply(x_power, x_1);
        }

        double sign = (i % 2 == 0) ? 1.0 : -1.0;
        
        double term = divide(multiply(sign, x_power), factorial(exponent));
        result = add(result, term);
    }

    return result;
}
