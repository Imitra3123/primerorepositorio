double add(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
double factorial(int n);
double sin(double theta);

double cos(double theta) {
   return sin(add(theta, 90.0));
}