#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isRotated(string str1, string str2)
    {
        if (str1.length() != str2.length())
            return false;
        if (str1.length() < 2)
        {
            return str1.compare(str2) == 0;
        }

        string clockw = "";
        string anticlockw = "";
        int len = str2.length();

        anticlockw = anticlockw + str2.substr(len - 2, 2) + str2.substr(0, len - 2);

        clockw = clockw + str2.substr(2) + str2.substr(0, 2);

        return (str1.compare(clockw) == 0 || str1.compare(anticlockw) == 0);
    }
};

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        string b;
        cin >> s >> b;
        Solution obj;
        cout << obj.isRotated(s, b) << endl;
    }
    return 0;
}
