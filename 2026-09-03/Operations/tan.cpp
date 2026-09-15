double divide(double a, double b);
double sin(double theta);
double cos(double theta);

double tan(double theta){
    return divide(sin(theta),cos(theta));
}