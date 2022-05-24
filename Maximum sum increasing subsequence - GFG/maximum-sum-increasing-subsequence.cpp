// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	int f(int ind, int prevInd, int n, int arr[], vector<vector<int>> &dp) {
    	if(ind == n) return 0;
    	
    	if(dp[ind][prevInd+1] != -1) return dp[ind][prevInd+1];
    	
    	int notTakeSum = 0 + f(ind+1, prevInd, n, arr, dp);
    	
    	int takeSum = 0;
    	if(prevInd == -1 || arr[ind] > arr[prevInd]) 
    		takeSum = arr[ind] + f(ind+1, ind, n, arr, dp);
    	
    	return dp[ind][prevInd+1] = max(notTakeSum, takeSum);
    }	

	public:
	int maxSumIS(int arr[], int n)  {  
	    vector<vector<int>> dp(n, vector<int>(n+1, -1));
	    
	    return f(0, -1, n, arr, dp);
	}  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends