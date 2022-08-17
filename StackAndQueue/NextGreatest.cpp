#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<long long> nextLargerElement(vector<long long> arr, int n)
    {
        vector<long long> ans;
        stack<long long> st;
        st.push(arr[n - 1]);
        ans.push_back(-1);

        for (int i = n - 2; i >= 0; i--)
        {
            while (!st.empty() && st.top() <= arr[i])
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
            st.push(arr[i]);
        }
        reverse(ans.begin(), ans.end());
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
        vector<long long> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution obj;
        vector<long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
