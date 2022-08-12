#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isAnagram(string a, string b)
    {

        int len1 = a.length();
        int len2 = b.length();

        if (len1 != len2)
        {
            return false;
        }

        unordered_map<char, int> mp;
        for (int i = 0; i < len1; i++)
        {
            mp[a[i]]++;
            mp[b[i]]--;
        }

        for (int i = 0; i < mp.size(); i++)
        {
            if (mp[i] != 0)
            {
                return false;
            }
        }

        return true;
    }
};

int main()
{

    int t;

    cin >> t;

    while (t--)
    {
        string c, d;

        cin >> c >> d;
        Solution obj;
        if (obj.isAnagram(c, d))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
