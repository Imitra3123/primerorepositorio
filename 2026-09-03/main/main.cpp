#include <iostream>
#include <sstream>
#include <string>

double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
int factorial(int n);
int combination(int n, int r);
int permute(int n, int r);
double sin(double theta);
double cos(double theta);
double tan(double theta);

using namespace std;
int main(){
    int operation;

    cout << "\n------------------------------------------\nWelcome to the C++ Operations Program!\n" << endl;
    cout << "Please select an operation(its number):\n-----------------------------------------\n" << endl;
    cout << "1. Addition|"<<"2. Subtraction|"<<"3. Multiplication|" <<"4. Division" << endl;
    cout << "5. Factorial|"<<"6. Combination|"<<"7. Permutation" << endl;
    cout << "8. Sine|"<<"9. Cosine|"<<"10. Tangent" << endl;

    cin >> operation;

    switch (operation) {
        case 1: {
            double a, b;
            cout << "Enter two numbers to add: ";
            cin >> a >> b;
            cout << "Result: " << add(a, b) << endl;
            break;
        }
        case 2: {
            double a, b;
            cout << "Enter two numbers to subtract: ";
            cin >> a >> b;
            cout << "Result: " << subtract(a, b) << endl;
            break;
        }
        case 3: {
            double a, b;
            cout << "Enter two numbers to multiply: ";
            cin >> a >> b;
            cout << "Result: " << multiply(a, b) << endl;
            break;
        }
        case 4: {
            double a, b;
            cout << "Enter two numbers to divide: ";
            cin >> a >> b;
            cout << "Result: " << divide(a, b) << endl;
            break;
        }
        case 5: {
            int n;
            cout << "Enter a number to calculate its factorial: ";
            cin >> n;
            try {
                cout << "Result: " << factorial(n) << endl;
            } catch (const std::invalid_argument& e) {
                cout << e.what() << endl;
            }
            break;
        }
        case 6: {  
            string nCr; 
            cout << "Enter n and r for combination (nCr): "; 
            std::getline(cin, nCr); 
    
            std::istringstream stream(nCr); 
            int n, r; 
            char C; 
    
            if (stream >> n >> C >> r && (C == 'C' || C == 'c')) { 
                try { 
                    cout << "Result: " << combination(n, r) << endl; 
                } catch (const std::invalid_argument& e) { 
                    cout << e.what() << endl; 
            } 
            } else { 
                 cout << "Invalid input format. Please use the format nCr." << endl; 
            } 
            break;
        


        }
        case 7: {
            string nPr; 
            cout << "Enter n and r for permutation (nPr): "; 
            std::getline(cin, nPr); 
    
            std::istringstream stream(nPr); 
            int n, r; 
            char P; 
    
            if (stream >> n >> P >> r && (P == 'P' || P == 'p')) { 
                try { 
                    cout << "Result: " << permute(n, r) << endl; 
                } catch (const std::invalid_argument& e) { 
                    cout << e.what() << endl;
                } 
            } else { 
                 cout << "Invalid input format. Please use the format nPr." << endl; 
            } 
            break;
        }
        case 8: {
            double theta;
            cout << "Enter an angle in degrees to calculate its sine: ";
            cin >> theta;
            cout << "Result: " << sin(theta) << endl;
            break;
        }
        case 9: {
            double theta;
            cout << "Enter an angle in degrees to calculate its cosine: ";
            cin >> theta;
            cout << "Result: " << cos(theta) << endl;
            break;
        }
        case 10: {
            double theta;
            cout << "Enter an angle in degrees to calculate its tangent: ";
            cin >> theta;
            cout << "Result: " << tan(theta) << endl;
            break;
        }
        default:
            cout << "Invalid operation selected." << endl;
            break;
    }

}