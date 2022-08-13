#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        string str = "";
        string B = "";
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] != '.')
                B = s[i] + B;
            else
            {
                str = str + B + ".";
                B = "";
            }
        }
        str = str + B;
        return str;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}