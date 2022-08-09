#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int findMidSum(int ar1[], int ar2[], int n)
    {
        int i = 0, j = 0;
        int count = 0, sum = 0;

        while (i < n && j < n)
        {
            if (ar1[i] >= ar2[j])
            {
                count++;
                if (count == n)
                {
                    sum += ar2[j];
                }
                if (count == n + 1)
                {
                    sum += ar2[j];
                    break;
                }

                j++;
            }
            else
            {
                count++;
                if (count == n)
                {
                    sum += ar1[i];
                }
                if (count == n + 1)
                {
                    sum += ar1[i];
                    break;
                }

                i++;
            }
        }
        while (i < n && count <= n + 1)
        {
            count++;
            if (count == n)
            {
                sum += ar1[i];
            }
            if (count == n + 1)
            {
                sum += ar1[i];
                break;
            }

            i++;
        }

        while (j < n && count <= n + 1)
        {
            count++;
            if (count == n)
            {
                sum += ar2[j];
            }
            if (count == n + 1)
            {
                sum += ar2[j];
                break;
            }

            j++;
        }

        return sum;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n;
        int ar1[n], ar2[n];
        for (i = 0; i < n; i++)
        {
            cin >> ar1[i];
        }
        for (i = 0; i < n; i++)
        {
            cin >> ar2[i];
        }
        Solution ob;
        auto ans = ob.findMidSum(ar1, ar2, n);
        cout << ans << "\n";
    }
    return 0;
}
