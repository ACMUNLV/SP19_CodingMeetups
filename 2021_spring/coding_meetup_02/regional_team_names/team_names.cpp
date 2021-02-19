/// @author Benjamin Alcocer

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string input;
    getline(cin, input);

    int index = input.find_first_of("-");

    // Another way: (we just want the index of the first '-')
    /*
    for (int i = 0; i < input.size(); ++i)
    {
        if (input[i] == '-')
        {
            index = i;
            break;
        }
    }
    */

    int teamSize = input.size() - (index + 1);
    if (index > 1 && index <= 8 && teamSize >= 1 && teamSize <= 24)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}
