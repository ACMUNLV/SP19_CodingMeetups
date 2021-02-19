/// @author Benjamin Alcocer

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string mine, other;
    int ansAmount, same;
    
    cin >> ansAmount >> mine >> other;
    for (int i = 0; i < mine.size(); ++i)
    {
        if (mine[i] == other[i])
            ++same;
    }
    cout << min(ansAmount, same) + min(mine.size() - same, mine.size() - ansAmount);

    return 0;
}
