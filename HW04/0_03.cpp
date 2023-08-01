#include<iostream>
using namespace std;

struct record{
    int value;
    struct record *next;
};
typedef struct record *Stack;
bool isEmpty(Stack s);

Stack create(){
    Stack s;
    s = new struct record;
    if(s == NULL){
        cout << "Out of Space!!"<<endl;
    }
    s->next=NULL;
    return s;
}

void push(Stack s,int value){
    Stack tempCell = new struct record;
    if(tempCell == NULL){
        cout << "Out of Space!!"<<endl;
    }
    else{
        tempCell->value = value;
        tempCell->next = s->next;
        s->next = tempCell;
        cout << "Success!"<<endl;
    }
}

void pop(Stack s){
    Stack tempCell = new struct record;
    if(tempCell == NULL){
        cout << "Out of Space!!"<<endl;
    }
    else if(isEmpty(s)){
        cout << "Stack Empty!"<<endl;
    }
    else{
        cout << "Pop : " << s->next->value<<endl;
        tempCell = s->next;
        s->next = s->next->next;
        delete(tempCell);
    }
}
void top(Stack s){
    if(isEmpty(s)){
        cout << "Stack Empty!"<<endl;
    }
    else{
        cout << "Top : " << s->next->value<<endl;
    }
}

bool isEmpty(Stack s){
    return s->next == NULL;
}

int main(){
    int choose;
    Stack s = create();
    while (true){
        printf("1)Push\n2)Pop\n3)Top\n4)Exit\nPlease choose> ");
        cin >> choose;
        int value;
        switch (choose){
        case 1:
            cout << "Push : ";
            cin >> value;
            push(s,value);
            break;
        case 2:
            pop(s);
            break;
        case 3:
            top(s);
            break;
        case 4:
            exit(0);
            break;
        default:
            break;
        } 
    }
    
    return 0;
}