//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeDups(string S)
    {
        unordered_map<char, int> mp;
        for (int i = 0; i < S.length(); i++)
        {
            mp[S[i]]++;
        }
        string ans;
        for (int i = 0; i < S.length(); i++)
        {
            if (mp[S[i]] >= 1)
            {
                ans += S[i];
                mp[S[i]] = 0;
            }
        }
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.removeDups(s) << "\n";
    }

    return 0;
}
