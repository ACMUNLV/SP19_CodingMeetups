/// @author Benjamin Alcocer

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    long long int n, m, d;

    // https://www.geeksforgeeks.org/stdgcd-c-inbuilt-function-finding-gcd/
    // Since it is not C++17
    // Otherwise, C++17: https://en.cppreference.com/w/cpp/numeric/gcd
    cin >> n >> m;
    d = __gcd(n, m);
    n /= d;
    m /= d;
    n % 2 == 1 && m % 2 == 1 ? cout << d : cout << '0';

    return 0;
}
