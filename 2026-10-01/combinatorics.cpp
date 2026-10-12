#include<iostream>
using namespace std;
int add(int a, int b);
int main(){
    cout << "Input:  "; //take user input whichcould literally be anything
    char input[50]; //declaring a typesafe (char) array of length 50
    cin >> input; //taking user input
    cout << input;
    int length = 0;
    while (input[length] != '\0') {
        length++;
    }
    cout << length;
    int firstNumber[50];
    int lastNumber[50];
    int fact[50];
    int n;
    int r;
    int f;
    if(input[0] <= 57 && input[length] <= 57 && input[0] >= 48 && input[length] >= 48){
        //combination or permutation
        for (int i = 0; input[i] != '\0'; i++) {
        // Cast the char to an int to print its ASCII value
        int asciiValue = (int)input[i];
        if(asciiValue == 99 || asciiValue == 67){
            //flag it combination
            int C = i;

        }
        else if (asciiValue == 112 || asciiValue == 80){
            //flag it permutation
            int P = i;
        }
        else cout << "error: contains no valid char inside or only numeric characters detected";
    }
    }
    else if (input[0] <= 57 && input[length] == 33 && input[0] >= 48){
        //factorial
        for (int i = 0; input[i] < length-1; i++) {
        // Cast the char to an int to print its ASCII value
        int asciiValue = (int)input[i];
        if(asciiValue > 57 || asciiValue < 48){
            
        }
    }
    }
    else cout << "error: contains invalid characters";
}