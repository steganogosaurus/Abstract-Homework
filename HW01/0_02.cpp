#include <iostream>
using namespace std;

int main()
{
    int in_choose;
    int arr[10];
    int data;
    int size = 0;
    bool runing = true;
    int position = 0;
    while (runing)
    {
        cout << "========MENU========" << endl;
        cout << "1) Insert the frist value" << endl;
        cout << "2) Insert front " << endl;
        cout << "3) Insert last " << endl;
        cout << "4) Insert middle" << endl;
        cout << "5) Exit" << endl;
        cout << endl;
        cout << "Please choose > ";
        cin >> in_choose;
        switch (in_choose)
        {
        case 1:
            if (size <= 0)
            {
                cout << "Enter data : ";
                cin >> data;
                arr[size] = data;
                cout << "Data in list = " << arr[size];
                size++;
                cout << endl;
            }
            else
            {
                cout << "Your have list can not crate list in program now!" << endl;
            }
            break;
        case 2:
            cout << "Enter data : ";
            cin >> data;
            for (int i = size; i >= 0; i--)
            {
                if (i != 0)
                {
                    position++;
                    arr[i] = arr[i - 1];
                }
                else
                {

                    arr[0] = data;
                }
            }
            size++;
            cout << "Move = " << position << " Position" << endl;
            cout << "Data move = ";
            position = 0;
            for (int i = 1; i < size; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
            cout << "Data in list : ";
            for (int i = 0; i < size; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
            cout << endl;
            break;
        case 3:
            cout << "Enter data : ";
            cin >> data;
            arr[size] = data;
            size++;
            cout << "Data in list : ";
            for (int i = 0; i < size; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
            cout << endl;
            break;
        case 4:
            cout << "Enter data : ";
            cin >> data;
            for (int i = size; i >= (size+1)/2; i--)
            {
                if (i != (size+1)/2)
                {
                    position++;
                    arr[i] = arr[i - 1];
                }
                else
                {

                    arr[(size+1)/2] = data;
                }
            }
            size++;
            cout << "Move = " << position << " Position" << endl;
            cout << "Data move = ";
            position = 0;
            for (int i = (size+1)/2; i < size; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
            cout << "Data in list : ";
            for (int i = 0; i < size; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
            cout << endl;
            break;
        case 5:
            runing = false;
            cout << "Output = Bye"<<endl;
            break;
        default:
            cout << "please choose in 1-5" << endl;
            cout << endl;
            break;
        }
    }
    return 0;
}