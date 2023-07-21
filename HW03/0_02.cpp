#include <iostream>
#include <string>
using namespace std;

struct record
{
    char value;
    struct record *next;
};
struct record *putchar(struct record *head, char value)
{
    struct record *p = head;
    if (head == NULL)
    {
        struct record *temp = new struct record;
        head = temp;
        head->value = value;
        head->next = NULL;
    }
    else
    {
        while (p->next != NULL)
        {
            p = p->next;
        }
        struct record *temp = new struct record;
        p->next = temp;
        p->next->value = value;
        p->next->next = NULL;
    }
    return head;
}
void decode(struct record *head){
    if (head == NULL)
    {
        cout << "Empty list!" << endl;
    }
    else
    {
        int index = 1;
        struct record *p = head;

        cout << "List : ";
        while (p != NULL)
        {
            if(index%2 == 0){
                cout << p->value;
            }
            index++;
            p = p->next;
        }
        cout << endl;
    }
}
void printAll(struct record *head)
{
    if (head == NULL)
    {
        cout << "Empty list!" << endl;
    }
    else
    {
        struct record *p = head->next;
        cout << "List : ";
        while (p != NULL)
        {
            cout << p->value;
            p = p->next;
        }
        cout << endl;
    }
}
int main()
{
    struct record *head = NULL;
    int choose;
    while (true)
    {
        cout << "========MENU========" << endl;
        printf("1)Insert\n2)Odd, even\n3)Decode\n4)Exit\nPlease choose> ");
        cin >> choose;
        char c;
        switch (choose)
        {
        case 1:
            cout << "Enter text('.' to exit)  :";
            while (true)
            {
                c = getchar();
                if (c != '.')
                {
                    head = putchar(head, c);
                }
                else
                {
                    break;
                }
            }
            printAll(head);
            cout << head->next->value;
            break;
        case 2:
            break;
        case 3:
            decode(head);
            break;
        case 4:
            exit(0);
            break;
        default:
            cout << "Please Enter number 1-4";
            break;
        }
    }
}