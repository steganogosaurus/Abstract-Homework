#include<iostream>
using namespace std;

struct node{
    int value;
    int high;
    struct node*left;
    struct node*right;
};

typedef struct node*Tree;

Tree insert(Tree tree,int value);
int fHigh(Tree tree);
void PrintInorder(Tree tree);

int main(){
    Tree tree = NULL;
    int chose;
    int value;
    string result ;
    while(true){
        cout << "========MENU======"<<endl;
    printf("1) Insert\n2) PrintInorder\n3) Exit\n Please choose > ");
        cin >> chose;
        switch (chose)
        {
        case 1:
            cout << "Enter : ";
            cin >> value;
            tree = insert(tree,value);
            if(fHigh(tree->left)-fHigh(tree->right) == 2 ||fHigh(tree->right)-fHigh(tree->left) == 2){
                cout <<"You have to rotate trees!" <<endl;
                exit(0);
            }
            else{
                cout << "Success!" <<endl;
            }
            break;
        case 2:
            cout << "Inorder : ";
            PrintInorder(tree);
            cout << endl;
            break;
        case 3:
            exit(0);
            break;
        default:
            cout << "Plase Enter 1-3"<<endl; 
            break;
        }
    }
}
int fHigh(Tree tree){
    if(tree == NULL){
        return -1;
    }
    else{
        return tree->high;
    }
}
Tree insert(Tree tree,int value){
    if(tree == NULL){
        tree = new struct node;
        tree->value = value;
        tree->high = 0;
        tree->left = NULL;
        tree->right = NULL;
        return tree;
    }
    else{
        if(tree->value > value){
            tree->left =  insert(tree->left,value);
            tree->high = 1;
        }
        else{
            tree->right = insert(tree->right,value);
            tree->high = 1;
        }
    }
    return tree;
}
void PrintInorder(Tree tree){
    if(tree == NULL){
        return;
    }
    else{
        PrintInorder(tree->left);
        cout << tree->value<<" ";
        // cout <<tree->high<<"|";
        PrintInorder(tree->right);
    }
}