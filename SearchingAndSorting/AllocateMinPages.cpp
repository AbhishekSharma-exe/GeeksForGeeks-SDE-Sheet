#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPossible(int a[], int n, int m, int mid)
    {
        int count = 1;
        int pages = 0;
        for (int i = 0; i < n; i++)
        {
            if (pages + a[i] <= mid)
            {
                pages += a[i];
            }
            else
            {
                count++;
                if (count > m || a[i] > mid)
                {
                    return false;
                }
                pages = a[i];
            }
        }
        return true;
    }
    int findPages(int a[], int n, int m)
    {
        int s = 0, mid, sum = 0;
        int ans = -1;
        for (int i = 0; i < n; i++)
        {
            sum += a[i];
        }
        int e = sum;
        mid = s + (e - s) / 2;
        while (s <= e)
        {
            if (isPossible(a, n, m, mid))
            {
                ans = mid;
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
            mid = s + (e - s) / 2;
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
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        int m;
        cin >> m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
