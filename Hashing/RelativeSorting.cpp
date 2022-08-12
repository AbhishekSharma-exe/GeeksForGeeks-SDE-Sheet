#include <bits/stdc++.h> 
using namespace std;

class Solution{
    public:

    vector<int> sortA1ByA2(vector<int> arr1, int n, vector<int> arr2, int m) 
    {
        vector<int> ans;
        
        map<int,int> mp;
        
        
        for(int i=0;i<n;i++){
            mp[arr1[i]]++;
        }
        
        for(int i=0;i<m;i++){
            int freq = mp[arr2[i]];
            
            for(int j=0;j<freq;j++){
                ans.push_back(arr2[i]);
            }
            
            mp[arr2[i]] = 0;
        }
        
        for (auto i : mp)
        {
            if(i.second !=0){
                for(int j=1;j<=i.second;j++){
                    ans.push_back(i.first);
                }
            }
        }
        
     return ans;   
        
    } 
};

int main(int argc, char *argv[]) 
{ 
	
	int t;
	
	cin >> t;
	
	while(t--){
	    
	    int n, m;
	    cin >> n >> m;
	    
	    vector<int> a1(n);
	    vector<int> a2(m);
	    
	    for(int i = 0;i<n;i++){
	        cin >> a1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> a2[i];
	    }
	    
	    Solution ob;
	    a1 = ob.sortA1ByA2(a1, n, a2, m); 
	
	   
	    for (int i = 0; i < n; i++) 
		    cout<<a1[i]<<" ";
		
	    cout << endl;
	    
	    
	}
	return 0; 
} 
