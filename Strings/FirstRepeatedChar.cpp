#include <bits/stdc++.h>
using namespace std;
string firstRepChar(string s);
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << firstRepChar(s) << endl;
    }
    return 0;
}

string firstRepChar(string s)
{
    unordered_map<char, bool> mp;
    string ans = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (mp[s[i]] == true)
        {
            ans += s[i];
            return ans;
        }
        mp[s[i]] = true;
    }
    return "-1";
}