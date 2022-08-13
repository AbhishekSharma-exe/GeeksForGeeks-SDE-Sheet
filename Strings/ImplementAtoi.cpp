#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int atoi(string str)
    {
        int n = str.size();
        int ans = 0;
        int i = 0, j;
        if (str[0] == '-')
        {
            i = 1;
        }

        for (j = i; j < n; j++)
        {

            if (str[j] >= '0' && str[j] <= '9')
            {
                int temp = str[j] - '0';
                ans = (ans * 10) + temp;
            }
            else
            {

                return -1;
            }
        }

        if (str[0] == '-')
        {
            ans = ans * -1;
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
        string s;
        cin >> s;
        Solution ob;
        cout << ob.atoi(s) << endl;
    }
}
