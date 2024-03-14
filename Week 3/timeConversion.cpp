#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    int hour = stoi(s.substr(0,2));
    if (s.substr(8,2)=="PM")
    {
        if (hour!=12) hour +=12;
    }
    else
    {
        if (hour==12) hour=0;
    }
    string militaryTime = (hour < 10 ? "0" : "") + to_string(hour) + s.substr(2, 6);
    return militaryTime;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

