#include<iostream>
using namespace std;

struct record{
    int value;
    struct record *next;
};
typedef struct record *Node;

struct box{
    Node font;
    Node back;
};
typedef struct box Queue;

Queue enqueue(Queue q,int value);
Queue dequeue(Queue q);
bool isEmpty(Queue q);

int main(){
    Queue box;
    box.font = NULL;
    box.back = NULL;
    int choose;
    int value;
    while(true){
        cout <<"======MENU======"<<endl;
        printf("1.) Enqueue\n2.) Dequeue\n3.) Exit\nPlease choose>");
        cin >> choose;
        switch (choose){
        case 1:
            cout <<"Enter data : ";
            cin >> value;
            box = enqueue(box,value);
            break;
        case 2:
            box = dequeue(box);
            break;
        case 3:
            exit(0);
            break;
        default:
            cout <<"Please Enter 1-3"<<endl;
            break;
        }
    }
}
bool isEmpty(Queue q){
    return q.font == NULL;
}
Queue enqueue(Queue q,int value){
    if(q.back == NULL){
        Node temp = new struct record;
        temp->value = value;
        temp->next = NULL;
        q.back = temp;
        q.font = temp;
    }
    else{
        Node temp = new struct record;
        temp->value = value;
        temp->next = q.back->next;
        q.back->next = temp;
        q.back = temp;
    }
    cout << "Success!" <<endl;
    return q;
}
Queue dequeue(Queue q){
    if(!isEmpty(q)){
        if(q.font->next == NULL){
            Node temp = q.font;
            cout <<"Dequeue "<< q.font->value<<endl;
            delete(temp);
            q.back = NULL;
            q.font = NULL;
        }
        else{
            Node temp = q.font;
            cout <<"Dequeue "<< q.font->value<<endl;
            q.font = q.font->next;
            delete(temp);
        }
    }
    else{
        cout << "Empty! Can't Dequeue"<<endl;
    }
    return q;
}
