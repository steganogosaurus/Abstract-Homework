#include<iostream>
using namespace std;

struct record{
    int value;
    struct record *next;
};
struct record *p;

int main(){
    p = new struct record;
    int temp;
    cout << "Enter : ";
    cin >> temp;
    p->value = temp;
    cout << "Value : " << p->value;
}