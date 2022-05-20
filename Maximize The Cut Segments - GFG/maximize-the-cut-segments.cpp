// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution
{
    public:
    int f(int ind, int x, int y, int z, vector<int> &dp) {
        if(ind == 0) return 0;
        
        if(dp[ind] != -1) return dp[ind];
        
        int xcut = -1e9, ycut = -1e9, zcut = -1e9;
        
        if(ind-x >= 0) xcut = f(ind-x, x, y, z, dp);
        if(ind-y >= 0) ycut = f(ind-y, x, y, z, dp);
        if(ind-z >= 0) zcut = f(ind-z, x, y, z, dp);
        
        return dp[ind] = 1 + max(xcut, max(ycut, zcut));
    }
  
    int maximizeTheCuts(int n, int x, int y, int z) {
        vector<int> dp(n+1, -1);
        int ans =  f(n, x, y, z, dp);
        
        //if returned answer is negative
        // no cuts possible
        if(ans < 0) return 0;
        else return ans;
    }
};

// { Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}  // } Driver Code Ends