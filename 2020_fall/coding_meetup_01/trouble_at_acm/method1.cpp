/// @author Benjamin Alcocer

#include <iostream>

using namespace std;

int main()
{
    int n, current;
    int count = 0;

    cin >> n;
    while (cin >> current)
    {
        count++;

        while (count < current)
        {
            cout << count << "\n";
            count++;
        }
    }
    if (count == n)
    {
        cout << "good job" << "\n";
    }

    return 0;
}
