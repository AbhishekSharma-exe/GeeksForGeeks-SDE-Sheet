#include<bits/stdc++.h>
using namespace std;

class Solution
{

public:
    int findSwapValues(int A[], int n, int B[], int m)
    {
        int sum1 = 0, sum2 = 0;

        for (int i = 0; i < n; i++)
            sum1 += A[i];

        for (int i = 0; i < m; i++)
            sum2 += B[i];

        if ((sum1 - sum2) % 2 == 1)
        {
            return -1;
        }
        int sub = (sum1 - sum2) / 2;

        sort(A, A + n);
        sort(B, B + m);

        int i = 0, j = 0;
        while (i < n && j < m)
        {
            if (A[i] - B[j] == sub)
            {
                return 1;
            }
            else if (A[i] - B[j] > sub)
            {
                j++;
            }
            else
            {
                i++;
            }
        }
        return -1;
    }
};

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int a[n];
        int b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        Solution ob;
        cout << ob.findSwapValues(a, n, b, m);
        cout << "\n";
    }
    return 0;
}
