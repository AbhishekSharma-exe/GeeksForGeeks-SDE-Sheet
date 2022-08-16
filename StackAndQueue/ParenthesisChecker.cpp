#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool matching(char a, char b)
    {

        return ((a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}'));
    }
    bool ispar(string str)
    {
        stack<char> s;

        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == '(' || str[i] == '[' || str[i] == '{')
            {
                s.push(str[i]);
            }
            else
            {
                if (s.empty() == true)
                    return false;
                else if (matching(s.top(), str[i]) == false)
                    return false;
                else
                    s.pop();
            }
        }
        return (s.empty() == true);
    }
};

int main()
{
    int t;
    string a;
    cin >> t;
    while (t--)
    {
        cin >> a;
        Solution obj;
        if (obj.ispar(a))
            cout << "balanced" << endl;
        else
            cout << "not balanced" << endl;
    }
}