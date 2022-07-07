#include <iostream>
#include <set>

using namespace std;

int main()
{
    set<int> final = {1, 2, 3};
    set<int> current = {0};
    set<int> next;
    set<int>::iterator itr;

    int transition[2][4][4] = {{
                                   {1, 1, 0, 0},
                                   {0, 0, 1, 0},
                                   {0, 0, 0, 1},
                                   {0, 0, 0, 0},
                               },
                               {{1, 0, 0, 0},
                                {0, 0, 1, 0},
                                {0, 0, 0, 1},
                                {0, 0, 0, 0}}};

    string input;
    int val;

    cout << "Enter input string: ";
    cin >> input;

    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] == 'a')
        {
            val = 0;
        }
        else
        {
            val = 1;
        }
        next = {};
        for (itr = current.begin(); itr != current.end(); itr++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (transition[val][*itr][j] == 1)
                {
                    next.insert(j);
                }
            }
        }
        current = next;
    }
    for (itr = final.begin(); itr != final.end(); itr++)
    {
        if (current.count(*itr) == 1)
        {
            cout << "Accepted";
            exit(0);
        }
    }
    cout << "Rejected";
    return 0;
}