#include <iostream>

using namespace std;

void TOH(int n, char start = 'A', char end = 'C', char mid = 'B')
{
    if (n == 1)
    {
        cout << "Move disk 1 from " << start << " to " << end << endl;
    }
    else
    {
        TOH(n - 1, start, mid, end);
        cout << "Move disk " << n << " from " << start << " to " << end << endl;
        TOH(n - 1, mid, end, start);
    }
}

int main()
{
    int n;
    cout << "Enter the number of disks: ";
    cin >> n;
    TOH(n);
    return 0;
}