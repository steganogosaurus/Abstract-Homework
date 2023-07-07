#include<iostream>
using namespace std;

int main(){
    int row;
    string result = "";
    char puzzle_arr[5][5] = {{'S','T','L','Y','R'},
                            {'T','H','E','M','E'},
                            {'A','N','A','G','O'},
                            {'R','O','P','E','S'},
                            {'K','T','T','U','C'},};
    cout << "Input : ";
    cin >> row;
    for(int i = 0;i<5;i++){
        result+= puzzle_arr[row-1][i];
        cout << result <<" ";
    }
    cout << endl;
    return 0;
}