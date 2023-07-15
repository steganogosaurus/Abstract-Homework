#include<iostream>
using namespace std;

struct record{
    int value;
    struct record *next;
};

struct record *insert(struct record *head,int value){
    if(head == NULL){
        struct record *temp = new struct record;
        head = temp;
        head->value = value;
        head->next = NULL;
        return head;
    }
    else{
        struct record *p = head;
        if(p->value > value){
            struct record *temp = new struct record;
            temp->value = value;
            temp->next = p;
            head = temp;
            return head; 
        }
        else{
            while (p->next != NULL){
            if(p->next->value > value){
                struct record *temp = new struct record;
                temp->value = value;
                temp->next = p->next;
                p->next = temp;
                return head;
            }
            p = p->next;
            }
            if(p->next == NULL){
                struct record *temp = new struct record;
                p->next = temp;
                p->next->value = value;
                p->next->next = NULL;
            }
            return head;
        }
    }
}
void printAll(struct record *head){
    if(head == NULL){
        cout <<"Empty list!"<<endl;
    }
    else{
        cout << "List = ";
        struct record *p = head;
        while(p != NULL){
            cout << p->value<<" ";
            p = p->next;
        }
        cout << endl;
    }
}

void printFAD(struct record *head){
    struct record *p = head;
        cout << "Frist : " <<p->value<<endl;
        while(p->next != NULL){
            p = p->next;
        }
        cout << "Last : " <<p->value<<endl;
}

int main(){
    int check;
    int value;
    struct record *head = NULL;
    while (true)
    {
        cout << "========MENU========"<<endl;
        printf("1)Insert\n2)Print All data\n3)Print frist and last\n4)Exit\nPlease choose> ");
        cin >> check;
        switch (check)
        {
        case 1:
            cout << "Insert : ";
            cin >> value;
            head = insert(head,value);
            cout << "Success!"<<endl;
            printAll(head);
            break;
        case 2:
            printAll(head);
            break;
        case 3:
            printFAD(head);
            break;
        case 4:
            exit(0);
            break;
        default:
            cout << "Please Enter number 1-4";
            break;
        }
    }
}