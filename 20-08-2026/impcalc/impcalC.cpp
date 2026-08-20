#include <iostream>

// Functions
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
double divide(int a, int b);

using namespace std;

int main{
    int a, b;
    int operation;
    
    cout<<"Welcome to the impCalC!\n"<<"Available operations:\n"<<"1. Addition\n"<<"2. Subtraction\n"<<"3. Multiplication\n"<<"4. Division\n" <<"Please choose an operation: " << endl;
    cin >> operation;

    cout << "Please enter two integers: ";
    cin >> a >> b;

    switch (operation) {
        case 1:
            cout << "Result: " <<a<< " + " <<b<< " = " << add(a, b) << endl;
            break;
        case 2:
            cout << "Result: " <<a<< " - " <<b<< " =    " << subtract(a, b) << endl;
            break;
        case 3:
            cout << "Result: " <<a<< " * " <<b<< " = " << multiply(a, b) << endl;
            break;
        case 4:
            cout << "Result: " <<a<< " / " <<b<< " = " << divide(a, b) << endl;
            break;
        default:
            cout << "Invalid operation selected." << endl;
    }
    
}