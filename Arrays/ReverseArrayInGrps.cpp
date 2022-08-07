#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //Function to reverse every sub-array group of size k.
    void reverseInGroups(vector<long long> &arr, int n, int k)
    {

        int l, r;
        for (int i = 0; i < n; i += k)
        {
            l = i;
            r = i + k - 1;
            if (r > n - 1)
            {
                r = n - 1;
            }

            while (l < r)
            {
                swap(arr[l++], arr[r--]);
            }
        }
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
        vector<long long> arr;
        int k;
        cin >> k;

        for (long long i = 0; i < n; i++)
        {
            long long x;
            cin >> x;
            arr.push_back(x);
        }
        Solution ob;
        ob.reverseInGroups(arr, n, k);

        for (long long i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}
