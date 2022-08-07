#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int MissingNumber(vector<int> &array, int n)
    {
        int hash[n] = {0};
        for (int i = 0; i < n - 1; i++)
        {
            hash[array[i]]++;
        }
        for (int i = 1; i <= n; i++)
        {
            if (hash[i] == 0)
            {
                return i;
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

        vector<int> array(n - 1);
        for (int i = 0; i < n - 1; ++i)
            cin >> array[i];
        Solution obj;
        cout << obj.MissingNumber(array, n) << "\n";
    }
    return 0;
}