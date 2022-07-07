#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
    set<int> final = {2};
    set<int> current = {0};
    set<int> next;
    set<int>::iterator itr, itr2;

    int transition[2][3][3] = {{{0, 1, 0}, {0, 1, 0}, {0, 0, 0}},
                               {{0, 0, 0}, {0, 1, 1}, {0, 0, 0}}};

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
            for (int j = 0; j < 3; j++)
            {
                if (transition[val][*itr][j] == 1)
                {
                    next.insert(j);
                }
            }
        }
        current = next;
    }
    for (itr = current.begin(); itr != current.end(); itr++)
    {
        for (itr2 = final.begin(); itr2 != final.end(); itr2++)
        {
            if (*itr == *itr2)
            {
                cout << "Accepted";
                exit(0);
            }
        }
    }
    cout << "Rejected";
    return 0;
}