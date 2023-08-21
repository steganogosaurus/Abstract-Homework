#include<iostream>
using namespace std;
struct record{
    int value;
    struct record *next;
};
typedef struct record Node;
typedef Node *LinkList;
struct box{
    LinkList head;
    LinkList tail;
};
box createLinkList(int member);
box deLinkList(box q,int value);
int find_winner(box q,int M);
// void printAll(box q);
bool isEmpty(box q);

int main(){
    int M,N;
    box q;
    cout << "Input M : ";
    cin >> M;
    cout << "Input N : ";
    cin >> N;
    q = createLinkList(N);
    int winner = find_winner(q,M);
    cout <<"Winner is : "<<winner<<endl;
    return 0;
}
box createLinkList(int member){
    box q;
    LinkList head = new Node;
    LinkList tail = new Node;
    LinkList p = head;
    head->value = 1;
    tail = head;
    for(int i = 2;i<=member;i++){
        LinkList temp = new Node;
        temp->value = i;
        p->next = temp;
        tail = temp;
        tail->next = head;
        p = p->next;
    }
    q.head = head;
    q.tail = tail;
    return q;
}
// void printAll(box q){
//     LinkList p_h = q.head;
//     LinkList p_t = q.tail;
//     do{
//         cout << p_h->value << " ";
//         p_h = p_h->next;
//     }while(p_h!=p_t->next);
//     cout <<endl;
// }
box deLinkList(box q,int value){
    LinkList p_h = q.head;
    LinkList p_t = q.tail;
    LinkList p = p_h;
    if(p_h->value == value){
        LinkList temp;
        temp = p_h;
        p_h = p_h->next;
        p_t->next = p_h;
        delete(temp);
    }
    else if(p_h == p_t){
        LinkList temp = p_h;
        p_h = NULL;
        p_t = NULL;
        delete(temp);
    }
    else{
        do{
            if(p->next == p_t){
                LinkList temp;
                temp = p->next;
                p->next = p->next->next;
                p_t = p;
                delete(temp);
                break;
            }
            else if(p->next->value == value){
                LinkList temp;
                temp = p->next;
                p->next = temp->next;
                delete(temp);
                break;
            }
            p = p->next;
        }while(p->next!=p_h);
    }
    q.head = p_h;
    q.tail = p_t;
    return q;
}
bool isEmpty(box q){
    return q.head == NULL;
}
int find_winner(box q,int M){
    LinkList p_h = q.head;
    LinkList p_t = q.tail;
    LinkList p = p_h;
    while(p_h != p_t){
        for(int i = 0;i<M-1;i++){
            p = p->next;
        }
        q = deLinkList(q,p->next->value);
        p_h = q.head;
        p_t = q.tail;
        p = p->next;
    }
    return p_h->value;
}   