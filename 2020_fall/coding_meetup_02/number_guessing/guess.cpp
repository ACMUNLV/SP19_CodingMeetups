/// @author Benjamin A
/// @brief Google Kick Start 2019 Practice Problem.
/// Coding meetup #2 for UNLV ACM

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int t, a, b, N, temp, guess;
    string readin;
    cin >> t;

    for (int i = 0; i < t; ++i)
    {
        cin >> a >> b >> N;
        ++a;

        while (N--)
        {
            guess = (a + b) / 2;
            cout << guess << endl;
            cin >> readin;

            if (readin == "CORRECT")
            {
                break;
            }
            else if (readin == "TOO_BIG")
            {
                b = guess - 1;
            }
            else
            {
                a = guess + 1;
            }
        }
    }

    return 0;
}
