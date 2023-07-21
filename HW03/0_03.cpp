#include<iostream>
using namespace std;

struct record{
    int value;
    struct record *next;
};

struct record *insert(struct record *head,int value){
    struct record *p = head;
    if (head == NULL)
    {
        struct record *temp = new struct record;
        head = temp;
        head->value = value;
        head->next = NULL;
    }
    else
    {
        while (p->next != NULL)
        {
            p = p->next;
        }
        struct record *temp = new struct record;
        p->next = temp;
        p->next->value = value;
        p->next->next = NULL;
    }
    return head;
}

int conut_node(struct record *head){
    struct record *p = head;
    int count = 0;
    while(p!=NULL){
        count++;
        p = p->next;
    }
    return count;
}

void print(struct record *head1,struct record *head2){
     struct record *p;
    if(head1 == NULL &&head2 == NULL ){
        cout <<"Empty list!"<<endl;
    }
    else{
        int index = 1;
        if(conut_node(head1) > conut_node(head2)){
            p = head1;    
        }
        else{
            p = head2;    
        }
        cout << "Longer : ";
        while(p != NULL){
            if(index%2 != 0){
                if(p->value != 1){
                    cout << p->value;
                }
            }
            else{
                if(p->value >1){
                    cout << "x^"<<p->value;
                }
                else if(p->value == 1){
                    cout << "x";
                }
                if(p->next != NULL){
                    cout << " + ";
                }
            }
            index++;
            p = p->next;
        }
        cout << endl;
    }
}
void printAll(struct record *head)
{
    if (head == NULL)
    {
        cout << "Empty list!" << endl;
    }
    else
    {
        struct record *p = head->next;
        cout << "List : ";
        while (p != NULL)
        {
            cout << p->value;
            p = p->next;
        }
        cout << endl;
    }
}

int main(){
    int check;
    int value;
    struct record *head1 = NULL;
    struct record *head2 = NULL;
    cout << "Input P1:";
    while (true){
        int number;
        cin >> number;
        if(number != -99){
            head1 = insert(head1,number);
        }
        else{
            break;
        }
    }
    cout << "Input P2:";
    while (true){
        int number;
        cin >> number;
        if(number != -99){
            head2 = insert(head2,number);
        }
        else{
            break;
        }
    }
    print(head1,head2);
}