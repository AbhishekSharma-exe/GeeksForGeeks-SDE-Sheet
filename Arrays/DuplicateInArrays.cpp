#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int a[] = {2,1,5,3,4,2,3,1,5,2};
    vector<int> ans;
    int n = sizeof(a)/sizeof(int);
    sort(a,a+n);
    bool flag=false;
    for(int i=0;i<n-1;i++){
        if(a[i]==a[i+1] && flag==false){
            ans.push_back(a[i]);
            flag=true;
        }
        else if(a[i]!=a[i+1]){
            flag=false;
        }
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i];
    }
    return 0;
}