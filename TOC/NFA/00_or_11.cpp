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

    int transition[2][4][4] = {{{1, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}},
                               {{1, 0, 0, 1}, {0, 0, 0, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}}};

    string input;

    cout << "Enter input string: ";
    cin >> input;

    for (int i = 0; input[i] != '\0'; i++)
    {
        next = {};
        for (itr = current.begin(); itr != current.end(); itr++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (transition[stoi(string(1, input[i]))][*itr][j] == 1)
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