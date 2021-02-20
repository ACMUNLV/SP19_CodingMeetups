#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct pixelCross
{
   int start;
   int addUp;
   char type;
};

/// that way sort() works
bool operator<(const pixelCross& a, const pixelCross& b)
{
    if (a.start != b.start)
    {
       return a.start < b.start;
    }
    if (a.addUp != b.addUp)
    {
       return a.addUp < b.addUp;
    }

    return a.type < b.type;
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(nullptr);

    int n, start, length, wireNum;
    char type;
    cin >> n;

    vector<pixelCross> pixelInfo;
    for (int i = 0; i < n; ++i)
    {
        cin >> type >> start >> length >> wireNum;
        pixelInfo.push_back({start - wireNum, 1, type});
        pixelInfo.push_back({start - wireNum + length, -1, type});
    }
    sort(pixelInfo.begin(), pixelInfo.end());

    long long horizAmount = 0;
    long long count = 0;
    long long verticalAmount = 0;

    for (auto obj : pixelInfo)
    {
        if (obj.type == 'h')
        {
            horizAmount += obj.addUp;
            if (obj.addUp > 0)
            {
                count += verticalAmount;
            }
        }
        else
        {
            verticalAmount += obj.addUp;
            if (obj.addUp > 0)
            {
                count += horizAmount;
            }
        }
    }
    cout << count << endl;
}
