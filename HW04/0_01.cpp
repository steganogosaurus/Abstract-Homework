#include<iostream>
using namespace std;

struct record {
    int value;
    struct record *prev;
    struct record *next;
};
struct head_tail {
    struct record *head;
    struct record *tail;
};

struct head_tail insert_sum(struct record *head,struct record *tail,int base,int pow){
    struct record *p_h = head;
    struct record *p_t = tail;
    struct head_tail box;
    int count = 1;
    if(p_h == NULL && p_t == NULL){
        struct record *temp1 = new struct record;
        struct record *temp2 = new struct record;
        temp1->value = base;
        temp2->value = pow;
        temp1->next = temp2;
        temp2->prev = temp1;
        head = temp1;
        tail = temp2;
        head->prev = NULL;
        tail->next = NULL;
    }
    else if(head->next->value < pow){
        struct record *temp1 = new struct record;
        struct record *temp2 = new struct record;
        temp1->value = base;
        temp2->value = pow;
        temp1->next = temp2;
        temp2->prev = temp1;
        temp2->next = p_h;
        p_h->prev = temp2;
        head = temp1;
        head->prev = NULL;
    }
    else if(head->next->value == pow){
        head->value = head->value+base;
    }
    else if(tail->value > pow){
        struct record *temp1 = new struct record;
        struct record *temp2 = new struct record;
        temp1->value = base;
        temp2->value = pow;
        temp1->next = temp2;
        temp2->prev = temp1;
        temp1->prev = p_t;
        p_t->next = temp1;
        tail = temp2;
        tail->next = NULL;
    }
    else if(tail->value == pow){
        tail->prev->value = tail->prev->value+base;
    }
    else{
        while(p_h != NULL){
            if(count % 2 == 0){
                if(p_h->value == pow){
                    p_h->prev->value = p_h->prev->value+base;
                    break;
                }
                else if(p_h->value < pow){
                    struct record *temp1 = new struct record;
                    struct record *temp2 = new struct record;
                    temp1->value = base;
                    temp2->value = pow;
                    temp1->next = temp2;
                    temp2->prev = temp1;
                    temp2->next = p_h->prev;
                    temp1->prev = p_h->prev->prev;
                    temp1->prev->next = temp1;
                    temp2->next->prev = temp2;
                    break;
                }
            }
            count++;
            p_h = p_h->next;
        }
        
    }
    box.head = head;
    box.tail = tail;
    return box;
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
        cout << "Output : ";
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
        struct record *p = head;
        cout << "List : ";
        while (p != NULL)
        {
            cout << p->value<<" ";
            p = p->next;
        }
        cout << endl;
    }
}
int main(){
    int choose;
    int value;
    int pow;
    struct record *head = NULL;
    struct record *tail = NULL;
    struct head_tail box;

    cout << "P1 : ";
    while (true){
        cin >> value;
        if(value != -99){
            cin >> pow;
        }
        else if(value == -99){
            break;
        }
        box = insert_sum(head,tail,value,pow);
        head = box.head;
        tail = box.tail;
    }
    // printAll(head);
    cout << "P2 : ";
    while (true){
        cin >> value;
        if(value != -99){
            cin >> pow;
        }
        else if(value == -99){
            break;
        }
        box = insert_sum(head,tail,value,pow);
        head = box.head;
        tail = box.tail;
    }
    // printAll(head);
    cout << endl;
    print(head,tail);
}