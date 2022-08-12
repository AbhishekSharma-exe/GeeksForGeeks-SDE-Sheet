
#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution
{
public:
    ll findSubarray(vector<ll> arr, int n)
    {
        long long count = 0, sum = 0;
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            if (sum == 0)
            {
                count++;
            }
            count += mp[sum];
            mp[sum]++;
        }

        return count;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<ll> arr(n, 0);

        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.findSubarray(arr, n) << "\n";
    }
    return 0;
}
