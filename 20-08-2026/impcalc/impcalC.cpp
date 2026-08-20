#include <iostream>

//Prototype for the functions
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
double divide(int a, int b);

using namespace std;

int main() {
    int num1, num2;
    int operation;

    cout << "Welcome to impCalc!\n" << endl;
    cout << "Choose an operation:\n" << endl;
    cout << "1. Add\n" << endl;
    cout << "2. Subtract\n" << endl;
    cout << "3. Multiply\n" << endl;
    cout << "4. Divide\n" << endl;
    cin >> operation;

    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    switch (operation) {
        case 1:
            cout << "Result: "<< num1 << " + " << num2 << " = " << add(num1, num2) << endl;
            break;
        case 2:
            cout << "Result: "<< num1 << " - " << num2 << " = " << subtract(num1, num2) << endl;
            break;
        case 3:
            cout << "Result: "<< num1 << " * " << num2 << " = " << multiply(num1, num2) << endl;
            break;
        case 4:
            cout << "Result: "<< num1 << " / " << num2 << " = " << divide(num1, num2) << endl;
            break;
        default:
            cout << "Invalid operation." << endl;
    }

    return 0;
}