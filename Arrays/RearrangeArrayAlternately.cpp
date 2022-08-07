#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void rearrange(long long *arr, int n)
    {

        vector<long long int> temp(n);

        int left = 0, right = n - 1;
        bool flag = true;

        for (int i = 0; i < n; i++)
        {
            if (flag)
                temp[i] = arr[right--];
            else
                temp[i] = arr[left++];

            flag = !flag;
        }

        for (int i = 0; i < n; i++)
            arr[i] = temp[i];
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

        long long arr[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        Solution ob;

        ob.rearrange(arr, n);

        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";

        cout << endl;
    }
    return 0;
}
