// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
#include <bits/stdc++.h>
using namespace std;

class Solution{
	public:
	int f(int ind, int maxWeight, int cost[], vector<vector<int>> &dp) {
	    // last elem
	    if(ind == 0 ) {
	       if(maxWeight == 0) return 0;
	       else return 1e8;
	    }
	    
	    if(dp[ind][maxWeight] != -1) return dp[ind][maxWeight];
	    
	    int notPick = 0 + f(ind-1, maxWeight, cost, dp);
	    
	    int pick = 1e8;
	    if(ind <= maxWeight && cost[ind-1] != -1)
	        pick = cost[ind-1] + f(ind, maxWeight - ind, cost, dp);
	        
	        
	    return dp[ind][maxWeight] = min(pick, notPick);
	}
	int minimumCost(int cost[], int N, int W) { 
	    vector<vector<int>> dp(N+1, vector<int>(W+1, -1));
	    
	    int ans = f(N, W, cost, dp);
	    
	    if(ans == 0) return -1;
	    else return ans;
	} 
};


// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minimumCost(a, n, w) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends