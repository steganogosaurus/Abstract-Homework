#include<iostream>
using namespace std;

int heap_size = 0;

void exchange(int *arr,int a,int b);
void heapify(int *arr,int index);
void heapSort(int *arr);
void buildHeap(int *arr);
int left(int index);
int right(int index);
int extractMax(int *arr);

int main(){
    int max = -99;
    int min = 99;
    int heap[30];
    int data;
    int heap_size_main;
    int chose;
    while(true){
        cout <<"=======MENU ======= "<<endl;
        printf("1) Insert data to array \n2) Build Heap \n3) Heap Sort \n4) Heap insert \n5) Priority Queue \n6) Extract Max \n7) Exit\nPlease choose > ");
        cin >> chose;
        switch (chose)
        {
        case 1:
            cout << "Input : ";
            do{
            cin >> data;
            if(data != -1){
                if(data > max){
                    max = data;
                }
                else if(data < min){
                    min = data;
                }
                heap_size++;
                heap[heap_size] = data;
                }
            }while(data != -1);
            heap_size_main = heap_size;
            break;
        case 2:
            buildHeap(heap);
            cout << "Heap : ";
            for(int i = 1;i<=heap_size_main;i++){
                cout <<heap[i]<<" ";
            }
            cout << endl;
            break;
        case 3:
            cout << "Heap Sort : ";
            heapSort(heap);
            heap_size = heap_size_main;
            for(int i = 1;i<=heap_size_main;i++){
                cout <<heap[i]<<" ";
            }
            cout << endl;
            break;
        case 4:
            cout << "Insert : ";
            cin >> data;
            heap_size++;
            heap[heap_size] = data;
            cout << "Array : ";
            for(int i = 1;i<=heap_size;i++){
                cout <<heap[i]<<" ";
            }
            cout << endl;
            exchange(heap,1,heap_size);
            buildHeap(heap);
            cout << "Heap : ";
            for(int i = 1;i<=heap_size;i++){
                cout <<heap[i]<<" ";
            }
            cout << endl;
            break;
        case 5:
            cout << "Priority Queue Heap : ";
            for(int i = 1;i<=heap_size;i++){
                cout <<heap[i]<<" ";
            }
            cout << endl;
            break;
        case 6:
            cout << "Max = " <<extractMax(heap)<<" Heap : ";
            for(int i = 1;i<=heap_size;i++){
                cout <<heap[i]<<" ";
            }
            cout << endl;
            break;
        case 7:
            exit(0);
            break;
        default:
            cout << "Plase Enter 1-7"<<endl;
            break;
        }
    }
    return 0;
}

int left(int index){
    return (2*index);
}

int right(int index){
    return (2*index)+1;
}

void exchange(int *arr,int a,int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void heapify(int *arr,int index){
    int L = left(index);
    int R = right(index);
    int largest = index;

    if(L <= heap_size && arr[L] > arr[index]){
        largest = L;
    }
    if(R <= heap_size && arr[R] > arr[index]){
        largest = R;
    }
    if(L <= heap_size && R <= heap_size && arr[L] > arr[index] && arr[R] > arr[index]){
        if(arr[L] > arr[R]){
            largest = L;
        }
        else{
            largest = R;
        }
    }
    if(largest != index){
        exchange(arr,index,largest);
        heapify(arr,largest);
    }
}

void buildHeap(int *arr){
    for(int x = heap_size/2;x >=1;x--){
        heapify(arr,x);
    }
}

void heapSort(int *arr){
    buildHeap(arr);
    int len = heap_size;
    for(int i = len;i>=2;i--){
        exchange(arr,i,1);
        heap_size = heap_size-1;
        heapify(arr,1);
    }
}

int extractMax(int *arr){
    int max = arr[1];
    for(int i = 1;i<heap_size;i++){
        arr[i] = arr[i+1];
    }
    heap_size = heap_size - 1;
    return max;
}

