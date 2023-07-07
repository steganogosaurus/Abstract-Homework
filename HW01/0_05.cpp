#include<iostream>
using namespace std;

int fibonacciNumber(int Xn){
    int fibonacci[15];
    fibonacci[0] = 1;
    fibonacci[1] = 1;
    for(int i = 2;i<15;i++){
        fibonacci[i] = fibonacci[i-1]+fibonacci[i-2];
    }
    return fibonacci[Xn-1];
}


int main(){
    int Xn;
    cout << "Enter : ";
    cin >> Xn;
    if(Xn > 15){
        cout << "Error,more than 15"<<endl;
    }
    else{
        cout << "Fibonacci of "<<Xn<<" = "<<fibonacciNumber(Xn);
    }
    
    return 0;
}