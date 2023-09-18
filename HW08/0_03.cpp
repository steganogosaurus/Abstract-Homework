#include<iostream>
using namespace std;

struct record{
    int value;
    struct record *next;
};

typedef struct record *Node;

struct headTail{
    Node font;
    Node back;
};
typedef struct headTail Queue;

Queue enqueue(Queue q,int value);
Queue dequeue(Queue q);
bool isEmpty(Queue q);
Node top(Queue q);
Node insert(Node linkedList,int value);
void printAll(Node linkedList);
void inputAdjList(Node *arr,int index,int value);
void BFS(int numberNode,Node *nodeArr,int *d,int *pred);
Node *makeNullArray(int size);
int *makearrayBegin(int size);
void printArray(int *arr,int size);

int main(){
    int size = 8;
    Node *arr = makeNullArray(size);
    int *d = makearrayBegin(size);
    int *pred = makearrayBegin(size);
    int value;
    for(int i = 0;i < size;i++){
        cout <<"Enter #"<<i<<" : ";
        while (true){
            cin >> value;
            if(value != -1){
                inputAdjList(arr,i,value);
            }
            else{
                break;
            }
        }
    }
    for(int i = 0;i < size;i++){
        cout <<"#"<<i<<" : ";
        printAll(arr[i]);
        cout << endl;
    }
    BFS(2,arr,d,pred);
    cout <<"   | d | pred "<<endl<<"=============="<<endl;
    for(int x = 0;x<size;x++){
        printf(" %d | %d |  %d \n",x,d[x],pred[x]);
    }
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

Node *makeNullArray(int size){
    Node *arr = new Node[size];
    for(int i = 0;i<size;i++){
        arr[i] = NULL;
    }
    return arr;
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
    return q;
}

bool isEmpty(Queue q){
    return q.font == NULL;
}
Queue dequeue(Queue q){
    if(!isEmpty(q)){
        if(q.font->next == NULL){
            Node temp = q.font;
            delete(temp);
            q.back = NULL;
            q.font = NULL;
        }
        else{
            Node temp = q.font;
            q.font = q.font->next;
            delete temp;
        }
    }
    else{
        cout << "Empty! Can't Dequeue"<<endl;
    }
    return q;
}

Node top(Queue q){
    return q.font;
}

void inputAdjList(Node *arr,int index,int value){
    arr[index] = insert(arr[index],value);
}

void printAll(Node linkedList){
    Node p = linkedList;
    while (p != NULL){
        cout << p->value<<" ";
        p = p->next;
    }
}
void printArray(int *arr,int size){
    for(int j = 0;j<size;j++){
        cout << arr[j] <<" ";
    }
    cout << endl;
    
}
int *makearrayBegin(int size){
    int *arr = new int[size];
    for(int i = 0;i<size;i++){
        arr[i] = -1;
    }
    return arr;
}
void BFS(int numberNode,Node *nodeArr,int *d,int *pred){
    Queue q;
    q.font = NULL;
    q.back = NULL;
    if(d[numberNode] == -1){
        d[numberNode] = 0;
        q = enqueue(q,numberNode);
        pred[numberNode] = numberNode;
    }
    // cout << top(q)->value;
    while(q.font != NULL){
        int u = top(q)->value;
        Node p =  nodeArr[u];
        while(p != NULL){
            int v = p->value;
            if(d[v] == -1){
                d[v] = d[u]+1;
                pred[v] = u;
                q = enqueue(q,v);
            }
            p = p->next;
        }            
        q = dequeue(q);
    }
}