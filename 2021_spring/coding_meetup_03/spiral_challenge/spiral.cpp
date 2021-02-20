/// @author Benjamin Alcocer

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 50000
#define ll long long
vector<ll> lookupTable(MAX);

void init()
{
    ll sq = 1;
    for (int i = 0; i < MAX; ++i)
    {
        lookupTable[i] = sq * sq;
        sq += 2;
    }
}

void solve(ll row, ll pos)
{
    auto search = lower_bound(lookupTable.begin(), lookupTable.end(), pos);
    int index = distance(lookupTable.begin(), search);
    row += index;
    ll col = row;
    if (lookupTable[index] != pos)
    {
        ll nMinusOne = 2 * index;
        ll location = (lookupTable[index] - pos) / nMinusOne;
        ll remainder = (lookupTable[index] - pos) % nMinusOne;
        
        if (location == 0) // right
        {
            row -= remainder;
        }
        else if (location == 1) // bottom
        {
            row -= nMinusOne;
            col -= remainder;
        }
        else if (location == 2) // left
        {
            row = row - (nMinusOne - remainder);
            col -= nMinusOne;
        }
        else // top
        {
            col = col - (nMinusOne - remainder);
        }
    }
    printf("Line = %lld, column = %lld.\n", row, col);
}


int main()
{
    init();

    ll size, position;
    cin >> size >> position;
    
    while (size != 0)
    {
        // solve
        solve(size / 2 + 1, position);

        cin >> size >> position;
    }
    

    return 0;
}
