/// @author Benjamin A

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> topic(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> topic[i];
    }

    int topics, greatest, count;
    greatest = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            topics = 0;
            for (int k = 0; k < m; ++k)
            {
                if ((topic[i][k] == '1') || (topic[j][k] == '1'))
                {
                    ++topics;
                }
            }
            if (greatest < topics)
            {
                greatest = topics;
                count = 1;
            }
            else if (greatest == topics)
            {
                ++count;
            }
        }
    }
    cout << greatest << "\n" << count << "\n";

    return 0;
}
