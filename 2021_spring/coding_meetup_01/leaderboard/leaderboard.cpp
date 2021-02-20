/// @author Benjamin Alcocer

#include <iostream>
#include <vector>
#include <algorithm>

#define endl "\n"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int players, games;
    int place = 1;
    int temp;

    cin >> players;
    vector<int> leaderboard(players);
    vector<int> position(players);
    
    cin >> temp;
    leaderboard[0] = temp;
    position[0] = 1;
    for (int i = 1; i < players; i++)
    {
        cin >> temp;
        leaderboard[i] = temp;
        if (temp != leaderboard[i - 1])
        {
            place++;
        }
        position[i] = place;
    }

    cin >> games;
    while (games--)
    {
        cin >> temp;
        auto it = lower_bound(leaderboard.begin(), leaderboard.end(), temp, greater<int>());
        if (it == leaderboard.end())
        {
            cout << position.back() + 1 << endl;
        }
        else
        {
            cout << position[distance(leaderboard.begin(), it)] << endl;
        }
    }

    return 0;
}
