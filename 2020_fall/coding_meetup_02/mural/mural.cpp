/// @author Benjamin Alcocer
/// @brief Google Kick Start 2019 Practice Problem.
/// Coding meetup #2 for UNLV ACM

#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, N, sumValue, greatest;
    string readIn;

    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        cin >> N >> readIn;

        sumValue = 0;
        for (int j = 0; j < (N + 1) / 2; ++j)
        {
            sumValue += readIn[j] - '0';
        }

        greatest = sumValue;
        for (int k = 0; k + (N + 1) / 2 < N; ++k)
        {
            sumValue += readIn[k + (N + 1) / 2] - '0';
            sumValue -= readIn[k] - '0';

            if (greatest < sumValue)
            {
                greatest = sumValue;
            }
        }
        printf("Case #%i: %i\n", i, greatest);
    }

    return 0;
}

