#include <iostream>
using namespace std;

bool isResult(string *result_arr, string result)
{
    bool ans = false;
    for (int x = 0; x < 14; x++)
    {
        if (*(result_arr + x) == result)
        {
            string a = " ";
            *(result_arr + x) = a;
            ans = true;
        }
    }
    return ans;
}
int main()
{
    char puzzle_arr[5][5] = {
        {'S', 'T', 'L', 'Y', 'R'},
        {'T', 'H', 'E', 'M', 'E'},
        {'A', 'N', 'A', 'G', 'O'},
        {'R', 'O', 'P', 'E', 'S'},
        {'K', 'T', 'T', 'U', 'C'},
    };
    string result_arr[] = {"STLY", "THEME", "THE", "THEM", "HE", "ME", "AN",
                           "GO", "AGO", "ROPE", "OPE", "OGA", "CUT", "OR"};
    string result = "";
    int num_of_result = 0;
    int chooseNumber;
    cout << "==================================" << endl;
    cout << "               MENU" << endl;
    cout << "==================================" << endl;
    printf("1.Print from front \n2.Print from back \n3.Match data base\n\n");
    cout << "Please choose > ";
    cin >> chooseNumber;
    switch (chooseNumber)
    {
    case 1:
        for (int row = 0; row < 5; row++)
        {
            for (int i = 0; i < 5; i++)
            {
                for (int j = i; j < 5; j++)
                {
                    result += puzzle_arr[row][j];
                    cout << result << " ";
                }
                result.clear();
            }
            cout << endl;
        }
        break;
    case 2:
        for (int row = 0; row < 5; row++)
        {
            for (int i = 4; i >= 0; i--)
            {
                for (int j = i; j >= 0; j--)
                {
                    result += puzzle_arr[row][j];
                    cout << result << " ";
                }
                result.clear();
            }
            cout << endl;
        }
        break;
    case 3:
        for (int row = 0; row < 5; row++)
        {
            for (int i = 0; i < 5; i++)
            {
                for (int j = i; j < 5; j++)
                {
                    result += puzzle_arr[row][j];
                    cout << result << " ";
                    if (isResult(result_arr, result))
                    {
                        num_of_result++;
                        cout << "Found " << num_of_result << " ";
                    }
                    cout << endl;
                }
                result.clear();
            }
            for (int i = 4; i >= 0; i--)
            {
                for (int j = i; j >= 0; j--)
                {
                    result += puzzle_arr[row][j];
                    cout << result << " ";
                    if (isResult(result_arr, result))
                    {
                        num_of_result++;
                        cout << "Found " << num_of_result << " ";
                    }
                    cout << endl;
                }
                result.clear();
            }
        }
        cout << "Total = " << num_of_result;
        break;

    default:
        cout << "please choose in 1-5" << endl;
        cout << endl;
        break;
    }
    return 0;
}