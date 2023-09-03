#include<iostream>
#include <string>
#include <cstdlib>
using namespace std;


struct node{
    string value;
    struct node*left;
    struct node*right;
};
typedef struct node*Tree;
struct record{
    Tree data;
    struct record*next;
};
typedef struct record *Stack;

Stack CreateStack(void);
void push(Stack s,Tree tree);
void pop(Stack s);
Tree top(Stack s);
bool isEmpty(Stack s);
Tree insert(Tree tree,Tree value);
void PrintInorder(Tree tree);
void PrintPostorder(Tree tree);

int main(){
    Stack s = CreateStack();
    char data[30];
    int number;
    string str_num;
    cout << "Input : ";
    while(data[0]!='.'){    
        cin >> data;
        if(data[0]>='0'&& data[0]<='9'){
            number=atoi(data);
            str_num = to_string(number);
            Tree tree = new struct node;
            tree->left = NULL;
            tree->right = NULL;
            tree->value = str_num;
            push(s,tree);
        }
        else
            if(data[0] != '.'){
                Tree tree = new struct node;
                tree->value = data[0];
                tree->right = top(s);
                pop(s);
                tree->left = top(s);
                pop(s);
                push(s,tree);
            }
    }
    cout << "Inorder : ";
    PrintInorder(s->next->data);
    cout << endl;
    cout << "Postorder : ";
    PrintPostorder(s->next->data);
    cout << endl;
    return 0;
}
Stack CreateStack(){
    Stack s = new struct record;
    s->next = NULL;
    return s;
}
bool isEmpty(Stack s){
    return s->next == NULL;
}
void push(Stack s,Tree tree){
    Stack temp = new struct record;
    temp->data = tree;
    temp->next = s->next;
    s->next = temp;
}
void pop(Stack s){
    if(isEmpty(s)){
        cout << "Stack is Empty!"<<endl;
    }
    else{
        Stack temp = s->next;
        s->next = temp->next;
        delete(temp);
    }
}
Tree top(Stack s){
    if(isEmpty(s)){
        cout << "Stack is Empty!"<<endl;
    }
    else{
        return s->next->data;
    }
}
Tree insert(Tree tree,Tree value){
    if(tree->right == NULL){
        tree->right = insert(tree->right,value);
    }
    else if(tree->left==NULL){
        tree->left = insert(tree->left,value);
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
void PrintPostorder(Tree tree){
    if(tree == NULL){
        return;
    }
    else{
        PrintPostorder(tree->left);
        PrintPostorder(tree->right);
        cout << tree->value<<" ";
    }
}