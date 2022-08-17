#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  
    vector<long long> nextSmallest(long long arr[], int n)
    {
        stack<int> st;
        st.push(n - 1);

        vector<long long> ans;
        ans.push_back(-1);
        for (int i = n - 2; i >= 0; i--)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }

            if (st.empty())
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(st.top());
            }
            st.push(i);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    vector<long long> prevSmallest(long long arr[], int n)
    {
        stack<long long> st;
        st.push(0);

        vector<long long> ans;
        ans.push_back(-1);
        for (int i = 1; i < n; i++)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }

            if (st.empty())
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(st.top());
            }
            st.push(i);
        }
        return ans;
    }

    long long getMaxArea(long long arr[], int n)
    {
        vector<long long> next(n);
        next = nextSmallest(arr, n);

        vector<long long> prev(n);
        prev = prevSmallest(arr, n);

        long long area = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            long long l = arr[i];

            if (next[i] == -1)
            {
                next[i] = n;
            }

            long long b = next[i] - prev[i] - 1;
            long long newArea = l * b;

            area = max(area, newArea);
        }

        return area;
    }
};


int main()
{
    long long t;

    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        long long arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.getMaxArea(arr, n) << endl;
    }
    return 0;
}
