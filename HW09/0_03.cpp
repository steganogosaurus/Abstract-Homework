#include<iostream>
#include <algorithm>
using namespace std;

int step = 1;
int predMax = 999;

struct record{
    int value;
    struct record *next;
};

typedef struct record *Node;

Node insert(Node linkedList,int value);
Node *makeNullArray(int size);
int *makeZeroArray(int size);
void DFS(Node *arr,int size,int *d_array,int *f_array,int *pred_arr);
void inputAdjList(Node *arr,int index,int value);
void printAll(Node linkedList);
void printArray(int *arr,int size);

int main(){
    int size = 9;
    string *name = new string[size];
    int chose;
    int value;
    int start_node = 1;
    int *d_arr = makeZeroArray(size);
    int *f_arr = makeZeroArray(size);
    int *pred_arr = makeZeroArray(size);
    Node *arr = makeNullArray(size);
    Node *toplogical  = makeNullArray(size);
    int *arrResult = new int[size];
    int max;
    int index;
    while (true){
        cout<<"======================= "<<endl;
        cout<<"          MENU          "<<endl;
        cout<<"======================= "<<endl;

        printf("\n1) Insert Graph \n2) Topologiacal\n3) Exit\nPlease choose > ");
        cin >> chose;
        switch(chose){
        case 1:
            for(int i = 0;i < size;i++){
                cout <<"Enter Name #"<<i<<" : ";
                cin >> name[i];
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
                cout <<name[i]<<" ";
                cout <<"#"<<i<<" : ";
                printAll(arr[i]);
                cout << endl;
            }
            break;
        case 2:
            d_arr = makeZeroArray(size);
            f_arr = makeZeroArray(size);
            step = 1;
            DFS(arr,0,d_arr,f_arr,pred_arr);

            for(int i = 0;i<size;i++){
                start_node = i;
                if(f_arr[i] == 0){
                        step++;
                    DFS(arr,start_node,d_arr,f_arr,pred_arr);
                }
            }
            
            for(int x = 0;x<size;x++){
                max = -99;
                for(int i = 0;i<size;i++){
                    if(max < f_arr[i]){
                        max = f_arr[i];
                        index = i;
                    }
                }
                f_arr[index] = -1;
                arrResult[x] = index;
            }
            for(int i = 0;i<size;i++){
                cout <<name[arrResult[i]]<<" ";
            }
            cout << endl;
            break;
        case 3:
            exit(0);
            break;
        default:
            cout << "Please Enter 1 - 3"<<endl;
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