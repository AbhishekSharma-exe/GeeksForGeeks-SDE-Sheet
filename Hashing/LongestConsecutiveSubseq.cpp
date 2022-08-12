#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findLongestConseqSubseq(int arr[], int n)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[arr[i]]++;
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            if (mp.find(arr[i] - 1) == mp.end())
            {
                int start = arr[i];
                //cout<<start;
                while (mp.find(start) != mp.end())
                {
                    count++;
                    // cout<<count<<" " <<start<<endl;
                    start++;
                    //cout<<count<<" " <<start<<endl;
                }

                ans = max(ans, count);
            }
        }

        return ans;
    }
};

int main()
{
    int t, n, i, a[100001];
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        cout << obj.findLongestConseqSubseq(a, n) << endl;
    }

    return 0;
}