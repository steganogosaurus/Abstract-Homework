#include<iostream>
using namespace std;

struct record{
    int value;
    struct record *next;
};

typedef struct record *Node;

Node insert(Node linkedList,int value);
void printAll(Node linkedList);
void inputAdjList(Node *arr,int index,int value);
void showSelfLoop(Node *arr,int size);
int **makeZeroMatrix(int size);
void inputAdjMatrix(int **arr,int row,int colum);
void printMatrix(int **arr,int width,int height);
Node *makeNullArray(int size);

int main(){
    int size = 6;
    int chose;
    int value;
    Node *arr = makeNullArray(size);
    int **zeroMatrix = makeZeroMatrix(size);
    while(true){
        printf("\n1) Input adjacency list\n2) Input adjacency matrix\n3) Show self loop from adjacency list\n4) Exit\nPlease choose > ");
        cin >> chose;
        switch (chose){
        case 1:
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
            break;
        case 2:
            for(int i = 0;i < size;i++){
                cout <<"Enter #"<<i<<" : ";
                while (true){
                    cin >> value;
                    if(value != -1){
                        inputAdjMatrix(zeroMatrix,i,value);
                    }
                    else{
                        break;
                    }
                }
            }
            cout<<endl<<"ADJACENCY MATRIX"<<endl;
            cout <<"---------------------------"<<endl;
            printMatrix(zeroMatrix,size,size);
             break;
        case 3:
            cout << "SelfLoop : "; 
            showSelfLoop(arr,size);
            cout <<endl;
            break;
        case 4:
            exit(0);
            break;
        default:
            cout <<"Please Enter 1-4";
            break;
        }
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

int **makeZeroMatrix(int size){
    int **arr = new int*[size];
    for(int y = 0;y<size;y++){
        arr[y] = new int[size];
        for(int x = 0;x<size;x++){
            arr[y][x] = 0;
        }
    }
    return arr;
}
void inputAdjList(Node *arr,int index,int value){
    arr[index] = insert(arr[index],value);
}

void inputAdjMatrix(int **arr,int row,int colum){
    arr[row][colum] = 1;
}

void showSelfLoop(Node *arr,int size){
    for(int i = 0;i<size;i++){
        Node p = arr[i];
        while(p != NULL){
            if(p->value == i){
                cout << i <<" ";
                break;
            }
            else{
                p = p->next;
            }
        }
        
    }
}

void printMatrix(int **arr,int width,int height){
    for(int i = 0;i<height;i++){
        for(int j = 0;j<width;j++){
            cout << arr[i][j] <<" ";
        }
        cout << endl;
    }
}

void printAll(Node linkedList){
    Node p = linkedList;
    while (p != NULL){
        cout << p->value<<" ";
        p = p->next;
    }
}