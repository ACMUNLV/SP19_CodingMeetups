// @author Benjamin Alcocer

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int cloud(vector<bool>& data)
{
    int jump = 0;
    int pos = 0;
    while (pos != data.size() - 1)
    {
        if (pos + 2 < data.size() && data[pos + 2])
        {
            pos += 2;
        }
        else
        {
            pos++;
        }
        jump++;
    }
    return jump;
}

int main()
{
    vector<bool> data;
    int n;
    cin >> n;

    while (n--)
    {
        bool temp;
        cin >> temp;
        data.push_back(!temp);
    }

    cout << cloud(data) << endl;

    return 0;
}
