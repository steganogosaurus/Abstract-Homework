#include<iostream>
using namespace std;

int step = 1;
int ss = 1;
struct record{
    int value;
    struct record *next;
};

typedef struct record *Node;

Node insert(Node linkedList,int value);
Node *makeNullArray(int size);
Node *transpose(Node *arr,int size);
int *makeZeroArray(int size);
void DFS(Node *arr,int u,int *d_array,int *f_array,int *pred_arr);
void DSCG(Node *arr,int u,int *tr_array,int size);
void printDSCG(int *tr_array,int size);
void inputAdjList(Node *arr,int index,int value);
void printAll(Node linkedList);
void printArray(int *arr,int size);

int main(){
    int size = 8;
    int chose;
    int value;
    int start_node = 1;
    int *d_arr = makeZeroArray(size);
    int *f_arr = makeZeroArray(size);
    int *pred_arr = makeZeroArray(size);
    int *tr_arr = makeZeroArray(size);
    Node *arr = makeNullArray(size);
    Node *temp;
    while (true){
        cout<<"==========MENU========= "<<endl;
        printf("1) Insert Graph \n2) DFS\n3) Transpose graph\n4) Decompose strongly connected graph\n5) Exit\nPlease choose > ");
        cin >> chose;
        cout <<endl;
        switch(chose){
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
            d_arr = makeZeroArray(size);
            f_arr = makeZeroArray(size);
            step = 1;
            cout << "Input source vertex : ";
            cin >> start_node;
            DFS(arr,start_node,d_arr,f_arr,pred_arr);
            cout << "d : ";
            printArray(d_arr,size);
            cout << "f : ";
            printArray(f_arr,size);
            cout <<"pred : ";
            printArray(pred_arr,size);
            break;
        case 3:
             cout << "Adjacency list "<<endl;
            for(int i = 0;i < size;i++){
                cout <<"#"<<i<<" : ";
                printAll(arr[i]);
                cout << endl;
            }
             cout << "Adajacency list transpose"<<endl;
                temp = transpose(arr,size);
                for(int i = 0;i<size;i++){
                    cout <<"#"<<i<<" : ";
                    printAll(temp[i]);
                    cout << endl;
                }
            break;
        case 4:
            temp = transpose(arr,size);
            for(int i = 0;i<size;i++){
                DSCG(temp,i,tr_arr,size);
            }
            printDSCG(tr_arr,size);
            break;
        case 5:
            exit(0);
            break;
        default:
            cout << "Please Enter 1 - 5"<<endl;
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

int *makeZeroArray(int size){
    int *arr = new int[size];
    for(int i = 0;i<size;i++){
        arr[i] = 0;
    }
    return arr;
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

void DFS(Node *arr,int u,int *d_array,int *f_array,int *pred_arr){
    pred_arr[1] = -1;
    if(d_array[u] != 0 && f_array != 0){
        return;
    }
    d_array[u] = step;
    Node p = arr[u];
    int temp = -1;
    while(p!=NULL){
        temp = p->value;
        if(temp != u && d_array[temp] == 0 ){
            if(pred_arr[temp] == 0){
                pred_arr[temp] = u;
            }
            step++;
            DFS(arr,temp,d_array,f_array,pred_arr);
        }
        p = p->next;
    }
    step++;
    f_array[u] = step;
}

void printArray(int *arr,int size){
    for(int i = 0;i<size;i++){
        cout << arr[i] <<" ";
    }
    cout <<endl;
}

Node *transpose(Node *arr,int size){
    Node *temp = makeNullArray(size);
    for(int i = 0;i<size;i++){
        Node p = arr[i];
        while (p != NULL){
            temp[p->value] = insert(temp[p->value],i);
            p = p->next;
        }
    }
    return temp;
}

void DSCG(Node *arr,int u,int *tr_array,int size){
    Node temp = arr[u];
    if(tr_array[u] != 0){
        return;
    }
    tr_array[u] = ss;
    int x = temp->value; // 4
    while(x != u){ //4 != 0 True
        if(tr_array[x] == 0){ // arr[1] == 0 True
            tr_array[x] = ss; // arr[1] = 1
            temp = arr[x]; // temp = Node1
            x = temp->value; // x = 1
        }
        else if(temp->next != NULL){
            temp = temp->next;
            x = temp->value;
        }
    }
    ss+=1;
}
void printDSCG(int *tr_array,int size){
    for(int x = 1;x<ss;x++){
        cout <<x;
        for(int i = 0;i<size;i++){
            if(tr_array[i] == x){
                cout <<" ( "<<i;
            }
        }
        cout <<" ";
        for(int j = size-1;j>=0;j--){
            if(tr_array[j] == x){
                cout <<j<<" ) ";
            }
        }
        cout << endl;
    }
}