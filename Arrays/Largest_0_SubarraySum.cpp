#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxLen(vector<int> &arr, int n)
    {

        unordered_map<int, int> mp;

        int sum = 0;
        int max_len = 0;

        for (int i = 0; i < n; i++)
        {
            sum += arr[i];

            if (sum == 0)
                max_len = i + 1;

            if (mp.find(sum) != mp.end())
            {
                max_len = max(max_len, i - mp[sum]);
            }
            else
            {
                mp[sum] = i;
            }
        }
        return max_len;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m;
        cin >> m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i)
        {
            cin >> array1[i];
        }
        Solution ob;
        cout << ob.maxLen(array1, m) << endl;
    }
    return 0;
}

// } Driver Code Ends