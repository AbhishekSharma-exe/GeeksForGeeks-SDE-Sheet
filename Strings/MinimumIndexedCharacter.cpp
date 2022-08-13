#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minIndexChar(string str, string patt)
    {
        set<char> st;

        for (int i = 0; i < patt.size(); i++)
        {
            st.insert(patt[i]);
        }
        int ans = -1;
        for (int i = 0; i < str.length(); i++)
        {
            if (st.find(str[i]) != st.end())
            {
                return i;
            }
        }
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        string patt;
        cin >> str;
        cin >> patt;
        Solution obj;
        cout << obj.minIndexChar(str, patt) << endl;
    }
    return 0;
}
