#include <iostream>
#include <cstdlib>
using namespace std;

struct Node
{
    char value;
    struct Node *next;
};
typedef struct Node *Stack;

Stack create_stack(void);
void infix(Stack s);
char pare_symbol(char ch);
void push(Stack s, char value);
void pop(Stack s);
char top(Stack s);
bool isEmpty(Stack s);

int main()
{
    int choose;
    Stack s = create_stack();

    string result = "";

    while (true)
    {
        cout << "=======MENU=======" << endl;
        cout << "1 Infix" << endl
             << "2 Infix()" << endl
             << "3 Exit" << endl
             << "Please choose > ";
        cin >> choose;
        switch (choose)
        {
        case 1:
            infix(s);
            break;
        case 2:
            infix(s);
            break;
        case 3:
            exit(0);
            break;
        default:
            cout << "Please Enter 1-3" << endl;
            break;
        }
    }

    return 0;
}

Stack create_stack(void)
{
    Stack s = new struct Node;
    if (s == NULL)
    {
        cout << "Out of Space!!" << endl;
    }
    else
    {
        s->next = NULL;
    }
}
bool isEmpty(Stack s)
{
    return s->next == NULL;
}
void push(Stack s, char value)
{
    Stack temp_cell = new struct Node;
    if (temp_cell == NULL)
    {
        cout << "Out of Space!!" << endl;
    }
    else
    {
        temp_cell->next = s->next;
        temp_cell->value = value;
        s->next = temp_cell;
    }
}
void pop(Stack s)
{
    Stack temp_cell = s->next;
    s->next = s->next->next;
    delete (temp_cell);
}
char top(Stack s)
{
    if (isEmpty(s))
    {
        // cout << "Stack Empty!"<<endl;
        return -1;
    }
    else
    {
        return s->next->value;
    }
}
void infix(Stack s)
{
    char ch[20];
    int number;
    while (true)
    {
        cin >> ch;
        if (ch[0] >= '0' && ch[0] <= '9')
        {
            number = atoi(ch);
            cout << number << " ";
        }
        else if (ch[0] == '.')
        {
            break;
        }
        else
        {
            if (!isEmpty(s))
            {
                if (ch[0] == '*' || ch[0] == '/')
                {
                    if ((top(s) != ch[0]))
                    {
                        push(s, ch[0]);
                    }
                }
                else if (ch[0] == '(')
                {
                    push(s, ch[0]);
                }
                else if (ch[0] == ')')
                {
                    while (top(s) != '(')
                    {
                        cout << top(s) << " ";
                        pop(s);
                    }
                    pop(s);
                }
                else
                {
                    while (!isEmpty(s))
                    {
                        if (ch[0] == '+' || ch[0] == '-')
                        {
                            if (top(s) != '(')
                            {
                                cout << top(s) << " ";
                                pop(s);
                            }
                            else
                            {
                                break;
                            }
                        }
                    }
                    push(s, ch[0]);
                }
            }
            else
            {

                push(s, ch[0]);
            }
        }
    }
    while (!isEmpty(s))
    {
        cout << top(s) << " ";
        pop(s);
    }
    cout << endl;
}