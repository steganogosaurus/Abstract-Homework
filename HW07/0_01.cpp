#include<iostream>
using namespace std;

struct node{
    int value;
    struct node*left;
    struct node*right;
};

typedef struct node*Tree;

Tree insert(Tree tree,int value);
Tree deleteTree(Tree tree,int value);
Tree findMin(Tree tree);
bool find(Tree tree,int value);
void PrintInorder(Tree tree);
void PrintLeaveNode(Tree tree);
void PrintNonLeaveNode(Tree tree);


int main(){
    Tree tree = NULL;
    int chose;
    int value;
    string result ;
    while(true){
        cout << "========MENU======"<<endl;
    printf("1) Insert\n2) PrintInorder, print leave node, print nonleave node\n3) Delete\n4) Find\n5) Exit\n Please choose > ");
        cin >> chose;
        switch (chose)
        {
        case 1:
            cout << "Enter : ";
            cin >> value;
            tree = insert(tree,value);
            cout << "Success!" <<endl;
            break;
        case 2:
            cout << "Inorder : ";
            PrintInorder(tree);
            cout << endl;
            cout << "Leave : ";
            PrintLeaveNode(tree);
            cout << endl;
            cout << "Nonleave : ";
            PrintNonLeaveNode(tree);
            cout << endl;
            break;
        case 3:
            cout << "Delete : ";
            cin >> value;
            tree = deleteTree(tree,value);
            cout << "Success!" <<endl;
            break;
        case 4:
            cout << "Search : ";
            cin >> value;
            result = find(tree,value)? "Found!" : "Not Found!";
            cout << result <<endl;
            break;
        case 5:
            exit(0);
            break;
        default:
            cout << "Plase Enter 1-5"<<endl; 
            break;
        }
    }
    
    return 0;
}

Tree insert(Tree tree,int value){
    if(tree == NULL){
        tree = new struct node;
        tree->value = value;
        tree->left = NULL;
        tree->right = NULL;
    }
    else{
        if(tree->value > value){
            tree->left =  insert(tree->left,value);
        }
        else{
            tree->right = insert(tree->right,value);
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
        PrintInorder(tree->right);
    }
}
void PrintLeaveNode(Tree tree){
    if(tree == NULL){
        return;
    }
    else{
        PrintLeaveNode(tree->left);
        if(tree->right == NULL && tree->right == NULL){
            cout << tree->value <<" ";
        }
        PrintLeaveNode(tree->right);
    }
}
void PrintNonLeaveNode(Tree tree){
    if(tree == NULL){
        return;
    }
    else{
        PrintNonLeaveNode(tree->left);
        if(tree->right != NULL && tree->right != NULL){
            cout << tree->value <<" ";
        }
        PrintNonLeaveNode(tree->right);
    }
}
bool find(Tree tree,int value){
    if(tree == NULL){
        return false;
    }
    else{
        if(tree->value == value){
            return true;
        }
        else if(tree->value > value){
            return find(tree->left,value);
        }
        else{
            return find(tree->right,value);
        }
    }
}
Tree findMin(Tree tree){
    if(tree->left == NULL){
        return tree;
    }
    else{
        findMin(tree->left);
    }
}
Tree deleteTree(Tree tree,int value){
    if(tree == NULL){
        cout <<"No Node!"<<endl;
    }
    else{
        if(tree->value > value){
            tree->left = deleteTree(tree->left,value);
        }
        else if(tree->value < value){
            tree->right = deleteTree(tree->right,value);
        }
        else{
            if(tree->right != NULL && tree->left != NULL){
                Tree temp = findMin(tree->right);
                tree->value = temp->value;
                tree->right = deleteTree(tree->right,tree->value);
                return tree;
            }
            else{
                if(tree->left == NULL){
                    Tree temp = tree;
                    Tree child = tree->right;
                    delete(temp);
                    return child;
                }
                if(tree->right == NULL){
                    Tree temp = tree;
                    Tree child = tree->left;
                    delete(temp);
                    return child;
                }
            }
        }
    }
    return tree;
}