#include<iostream>
using namespace std;
int main(){
    char ch;
    int count = 0;
    while (true){
        ch = getchar();
        if ((ch == '[' || ch == '{' || ch == '<' || ch == '(')){
            cout << ch << endl;
            count++;
        }
        else if(ch == '.'){
            break;
        }
    }
    cout << "Open = " << count;
}