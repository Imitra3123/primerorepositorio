#include<iostream>
#include<string>
using namespace std;
int main() {
    string nombre;
    int edad = 0;
    cout << "¿Como te llamas?\n" << endl;
    getline(cin, nombre);
    cout << "¿Cuantos años tienes?\n" << endl;
    cin >> edad;
    cout << "Hola " << nombre << "!\n" << endl;
    cout << "Tienes " << edad << " años.\n" << endl;
    return 0;
}