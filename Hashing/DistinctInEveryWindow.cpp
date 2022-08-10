#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> countDistinct(int arr[], int n, int k)
    {
        vector<int> ans;
        unordered_map<int, int> mp;
        int count = 0;
        for (int i = 0; i < k; i++)
        {
            if (mp[arr[i]] == 0)
            {
                count++;
            }
            mp[arr[i]]++;
        }
        ans.push_back(count);
        for (int i = k; i < n; i++)
        {
            if (mp[arr[i]] == 0)
            {
                count++;
            }
            mp[arr[i]]++;
            if (mp[arr[i - k]] == 1)
            {
                count--;
            }
            mp[arr[i - k]]--;
            ans.push_back(count);
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

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        vector<int> result = obj.countDistinct(a, n, k);
        for (int i : result)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
