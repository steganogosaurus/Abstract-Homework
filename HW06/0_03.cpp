#include<iostream>

using  namespace std;

struct record{
    int value;
    struct record *left;
    struct record *right;
};
typedef struct record *Node;
Node insert(Node tree,int value);
void PrintInorder(Node tree);
void PrintPeroder(Node tree);
void PrintPostorder(Node tree);
int Find_min(Node tree);
int main(){
    Node tree = NULL;
    int choose,value;
    while(true){
        cout <<"======MENU======"<<endl;
        printf("1.) Insert\n2.) Print\n3.) Find min\n4.) Exit\nPlease choose>");
        cin >> choose;
        switch (choose){
        case 1:
            cout <<"Enter data : ";
            cin >> value;
            tree = insert(tree,value);
            break;
        case 2:
            cout <<"Preorder ";
            PrintPeroder(tree);
            cout <<endl;
            cout <<"Inorder ";
            PrintInorder(tree);
            cout <<endl;
            cout <<"Postorder ";
            PrintPostorder(tree);
            cout <<endl;
            break;
        case 3:
            cout << "Min = " << Find_min(tree)<<endl;
            break;
        case 4:
            exit(0);
            break;
        default:
            cout <<"Please Enter 1-3"<<endl;
            break;
        }
    }
    return 0;
}
Node insert(Node tree,int value){
    if(tree == NULL){
        tree = new struct record;
        tree->value = value;
        tree->left = NULL;
        tree->right = NULL;
    }
    else{
        if(tree->value > value){
            tree->left = insert(tree->left,value);
        }
        else if(tree->value < value){
            tree->right = insert(tree->right,value);
        }
    }
    return tree;
}
void PrintInorder(Node tree){
    if(tree == NULL){
        return;
    }
    else{
        PrintInorder(tree->left);
        cout << tree->value<<" ";
        PrintInorder(tree->right);
    }
    return;
}
void PrintPeroder(Node tree){
    if(tree == NULL){
        return;
    }
    else{
        cout << tree->value<<" ";
        PrintInorder(tree->left);
        PrintInorder(tree->right);
    }
    return;
}
void PrintPostorder(Node tree){
     if(tree == NULL){
        return;
    }
    else{
        PrintInorder(tree->left);
        PrintInorder(tree->right);
        cout << tree->value<<" ";
    }
    return;
}
int Find_min(Node tree){
    if(tree->left == NULL){
        return tree->value;
    }
    else{
        Find_min(tree->left);
    }
}

