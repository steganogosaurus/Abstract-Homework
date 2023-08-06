#include<iostream>
using namespace std;

int main(){
    cout << "Input : ";
    int number1,number2;
    char symbol;
    cin >> number1 >> symbol >> number2;
    cout << number1 <<"   digit"<<endl;
    cout << symbol <<"   symbol"<<endl;
    cout << number2 <<"   digit"<<endl;
    cout << "Output = "<<number1+number2;
    return 0;
}