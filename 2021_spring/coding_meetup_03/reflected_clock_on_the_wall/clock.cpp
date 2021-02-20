/// @author Benjamin Alcocer

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string intToStr(int num)
{
    return num >= 10 ? to_string(num) : "0" + to_string(num);
}

int main()
{
    // initialize minArr
    vector<string> minArr(60, "");
    minArr[0] = "00";
    int left = 59;
    for (int right = 1; right < 60; ++right)
    {
        minArr[right] = intToStr(left);
        --left;
    }

    // declare hour arrays (or initialize)
    vector<string> notZeroHour =   {"", "10", "09", "08", "07", "06", "05", "04", "03", "02", "01", "12", "11"};
    vector<string> zeroHour =      {"", "11", "10", "09", "08", "07", "06", "05", "04", "03", "02", "01", "12"};

    // begin program and output
    int t, hour, minute;
    string buffer, hourStr, minStr;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        cin >> buffer;
        hourStr = {buffer[0], buffer[1]};
        minStr = {buffer[3], buffer[4]};
        hour = stoi(hourStr);
        minute = stoi(minStr);

        if (minute != 0)
        {
            cout << notZeroHour[hour] << ":" << minArr[minute] << "\n";
        }
        else
        {
            cout << zeroHour[hour] << ":" << minArr[minute] << "\n";
        }
    }

    return 0;
}
