#include<iostream>
#include <string>
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

struct record* delete_node(struct record *head , int value){
    struct record *p = head;
    if(p->value == value){
        struct record *temp = head;
        head = head->next;
        delete temp;
        cout << "Success!"<<endl;
    }
    else{
        while(p->next != NULL){
            if(p->next->value == value){
                struct record *temp = p->next;
                p->next = p->next->next;
                cout << "Success!"<<endl;
                delete temp;
                return head;
            }
            else{
                p = p->next;
            }
        }
        cout << "No have that value in this LinkedList!"<<endl;
    }
    return head;
}

void m_to_m(struct record *head){
    struct record *p = head;
    string min_to_max = "";
    string max_to_min = "";
    while(p!=NULL){
        min_to_max = min_to_max+" "+to_string(p->value);
        max_to_min = to_string(p->value)+" "+max_to_min;
        p = p->next;
    }
    cout <<"Min to Max :"<<min_to_max << endl<< "Max to Min : " <<max_to_min<<endl;
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
void odd_node(struct record *head){
    struct record *p = head;
    int count = 1; 
    cout << "Odd node = ";
    while(p!=NULL){
        if(count%2!=0){
            cout << p->value <<" ";
        }
        count++;
        p = p->next;
    }
    cout << endl;
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
        printf("1)Insert\n2)Delet\n3)Print min to max/max to min\n4)Count node\n5)Print only odd node\n6)Exit\nPlease choose> ");
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
            cout << "Delete : ";
            cin >> value; 
            head = delete_node(head,value);
            printAll(head);
            break;
        case 3:
            m_to_m(head);
            break;
        case 4:
            cout << "Number of node = "<<conut_node(head)<<endl;
            break;
        case 5:
            odd_node(head);
            break;
        case 6:
            exit(0);
            break;
        default:
            cout << "Please Enter number 1-6";
            break;
        }
    }
}