#include<iostream>
using namespace std;

struct Node{
    char value;
    struct Node *next;
};
typedef struct Node *Stack;

Stack create_stack(void);
char pare_symbol(char ch);
void push(Stack s,char value);
void pop(Stack s);
char top(Stack s);
bool isEmpty(Stack s);

int main(){
    char ch;
    Stack s;
    bool complete = true;
    s = create_stack();
    string result = "Expected ";
    while (true){
        ch = getchar();
        if(ch == '<' || ch == '(' || ch == '[' || ch == '{'){
            push(s,ch);
        }
        else if(ch == '.'){
            break;
        }
        else if(ch == '>' || ch == ')' || ch == ']' || ch == '}'){
            while(!isEmpty(s)){
                if(((int)ch - (int)top(s) <=2) && ((int)ch - (int)top(s) > 0)){
                    pop(s);
                    break;
                }
                else{
                    complete = false;
                    result += pare_symbol(top(s));
                    pop(s);
                }
            }
        }
        else{
            cout << "Error!" << endl;
        }
    }
    if(!isEmpty(s)){
        complete = false;
        while(!isEmpty(s)){
            result += pare_symbol(top(s));
            pop(s);
        }
        cout << result << endl;
    }
    else{
        if(complete){
            cout << "Complete!"<<endl;
        }
        else{
            cout << result << endl;
        }
    }
    return 0;
}
Stack create_stack(void){
    Stack s = new struct Node;
    if(s == NULL){
        cout << "Out of Space!!"<<endl;
    }
    else{
        s->next = NULL;
    }
}
bool isEmpty(Stack s){
    return s->next == NULL;
}
void push(Stack s,char value){
    Stack temp_cell = new struct Node;
    if(temp_cell == NULL){
        cout << "Out of Space!!"<<endl;
    }
    else{
        temp_cell->next = s->next;
        temp_cell->value = value;
        s->next = temp_cell;
    }
}
void pop(Stack s){
    Stack temp_cell = s->next;
    s->next = s->next->next;
    delete(temp_cell);
}
char top(Stack s){
    if(isEmpty(s)){
        // cout << "Stack Empty!"<<endl;
        return -1;
    }
    else{
        return s->next->value;
    }
}
char pare_symbol(char ch){
    char chars[] = {'(',')','{','}','[',']','<','>'};
    for(int i = 0;i<8;i++){
        if(ch == chars[i]){
            if(i%2 == 0){
                return (chars[i+1]);
            }
            else{
                return (chars[i-1]);
            }
        }
    }
}