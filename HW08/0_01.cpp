#include<iostream>
using namespace std;

struct record{
    int value;
    struct record *next;
};

typedef struct record *Node;

Node insert(Node linkedList,int value);
void printAll(Node linkedList);

int main(){
    int value;
    Node linkedList = NULL;
    cout << "Input : ";
    while (true){
        cin >> value;
        if(value != -1){
            linkedList = insert(linkedList,value);
        }
        else{
            break;
        }
    }
    cout << "List : ";
    printAll(linkedList);
    return 0;
}

Node insert(Node linkedList,int value){
    Node p = linkedList;
    Node temp = new struct record;
    if(linkedList == NULL){
        linkedList = temp;
        linkedList->value = value;
        linkedList->next = NULL;
    }
    else{
        while(p->next != NULL){
            p = p->next;
        }
        p->next = temp;
        p->next->value = value;
        p->next->next = NULL;
     }
    return linkedList;
}
void printAll(Node linkedList){
    Node p = linkedList;
    while (p != NULL){
        cout << p->value<<" ";
        p = p->next;
    }
}