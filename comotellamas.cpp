#include<iostream>
#include<string>
using namespace std;
int main(){
    string nombre;
    cout << "¿Como te llamas?\n" << endl;
    getline(cin, nombre);
    cout << "Hola " << nombre << "!\n" << endl;
    return 0;
}