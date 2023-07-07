#include<iostream>
using namespace std;

int main(){
    cout << "Enter : ";
    int arr[5];
    for(int i = 0;i<5;i++){
        cin >> arr[i];
    }
    cout << "(index) | ";
    for(int i = 0;i<5;i++){
        cout << i <<" ";
    }
    cout << endl;
    cout << "--------|-----------";
    cout << endl;
    cout << "(value) | ";
    for(int i = 0;i<5;i++){
        cout << arr[i] <<" ";
    }
    cout << endl;
    int num;
    cout << "Enter value : ";
    cin >> num;
    if(arr[(sizeof(arr)/sizeof(int))-1] < num){
        cout << "No number"<<endl;
    }
    else{
        for(int i = 0;i<(sizeof(arr)/sizeof(int));i++){
            if(arr[i]>num){
                cout <<"Index = " << i<<endl;
                break;
            }
        }
    }
    return 0;
}