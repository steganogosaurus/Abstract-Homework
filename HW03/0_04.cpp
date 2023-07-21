#include<iostream>
using namespace std;

struct record{
    int value;
    struct record *next;
    struct record *prev;
};
struct head_tail{
    struct record *head;
    struct record *tail;
};

struct head_tail insert(struct record *head,struct record *tail,int value){
    struct head_tail box;
    struct record *p_h = head;
    struct record *p_t = tail;
    if((p_t) == NULL && (p_h) == NULL){
        struct record *temp = new struct record;
        temp->value = value;
        temp->next = NULL;
        temp->prev = NULL;
        head = temp;
        tail = temp;
    }
    else if(p_h->value > value){
        struct record *temp = new struct record;
        temp->value = value;
        temp->prev = NULL;
        temp->next = p_h;
        p_h->prev = temp;
        head = temp;
    }
    else
    {
        while (p_h->next != NULL)
        {
            if(p_h->next->value > value){
                struct record *temp = new struct record;
                temp->value = value; 
                temp->prev = p_h;
                temp->next = p_h->next;
                p_h->next->prev = temp;
                p_h->next = temp;
                break;
            }
            else{
                p_h = p_h->next;
            }
        }
        if(p_h->next == NULL){
            struct record *temp = new struct record;
            temp->value = value; 
            temp->prev = p_h;
            temp->next = NULL;
            p_h->next = temp;
            tail = temp;
        }
    }
    box.head = head;
    box.tail = tail;
    return box;
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
void m_to_m(struct record *head,struct record *tail){
    struct record *p_h = head;
    struct record *p_t = tail;
    if (head == NULL)
    {
        cout << "Empty list!" << endl;
    }
    else{
        cout << "Min to max : ";
        while (p_h!=NULL){
            cout << p_h->value<<" ";
            p_h = p_h->next;
        }
        cout << endl;
        cout << "Max to min : ";
        while (p_t!=NULL){
            cout << p_t->value<<" ";
            p_t = p_t->prev;
        }
        cout << endl;
    }
}
int main(){
    int choose;
    int value;
    struct record *head = NULL;
    struct record *tail = NULL;
    struct head_tail box;
    while(true){
        cout << "========MENU========" << endl;
        printf("1)Insert\n2)Print min to max / max to min\n3)Exit\nPlease choose> ");
        cin >> choose;
        switch (choose)
        {
        case 1:
            cout << "Insert : ";
            cin >> value;
            box = insert(head,tail,value);
            head = box.head;
            tail = box.tail;
            cout << "Success!"<<endl;
            printAll(head);
            // cout << head->next <<" "<<tail;
            break;
        case 2:
            m_to_m(head,tail);
            break;
        case 3:
            exit(0);
            break;
        default:
            break;
        }
    }
}