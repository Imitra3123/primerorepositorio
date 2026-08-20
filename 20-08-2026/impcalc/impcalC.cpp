#include <iostream>

//Prototype for the functions
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
double divide(int a, int b);
int root(int a, int b);

using namespace std;

int main() {
    int num1, num2;
    int operation;

    cout << "Welcome to impCalc! (v. 1.1)\n" << endl;
    cout << "Available operations:\n" << endl;
    cout << "1. Add\n" << endl;
    cout << "2. Subtract\n" << endl;
    cout << "3. Multiply\n" << endl;
    cout << "4. Divide\n" << endl;
    cout << "5. Root\n" << endl;
    cout << "Enter the number corresponding to the operation you want to perform: ";
    cin >> operation;

    cout << "Enter two numbers to do the conduct the operation on: ";
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
        case 5:
            cout << "Result: "<< num1 << " √ " << num2 << " = " << root(num1, num2) << endl;
            break;
        default:
            cout << "Invalid operation." << endl;
    }

    return 0;
}