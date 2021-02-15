/// @author Benjamin Alcocer

#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    int n, num;
    int count = 0;
    cin >> n;
    // or unordered_map<int, bool> but did it like this to make it more clear
    unordered_map<int, int> map; 

    // You can also do an unordered_set<int> and if found in set, delete it.
    // I'd imagine this method is better though.
    for (int i = 0; i < n; ++i)
    {
        cin >> num;
        auto search = map.find(num);
        if (search != map.end())
        {
            if (search->second == 1)
            {
                ++count;
                search->second = 0;
            }
            else
            {
                search->second = 1;
            }
        }
        else
        {
            map[num] = 1;
        }
    }

    cout << count;

    return 0;
}
