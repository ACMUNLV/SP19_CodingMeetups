/// @author Benjamin Alcocer
/// https://www.hackerrank.com/challenges/cats-and-a-mouse

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n, x, y, z, value;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y >> z;
        value = abs(z - x) - abs(z - y);
        value == 0 ? cout << "Mouse C" : (value < 0 ? cout << "Cat A" : cout << "Cat B");
        cout << endl;
    }

    return 0;
}
