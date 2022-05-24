// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    int f(int ind, int prev_ind, int n, int a[], vector<vector<int>> &dp) {
        if(ind == n) return 0;
        
        if(dp[ind][prev_ind+1] != -1) return dp[ind][prev_ind+1];
        
        int notTake = f(ind+1, prev_ind, n, a, dp);
        
        int take = 0;
        //prev_ind = 1: selecting the first elem of LIS
        if(prev_ind == -1 || a[ind] > a[prev_ind])
            take = 1 + f(ind+1, ind, n, a, dp);
            
        return dp[ind][prev_ind+1] = max(take, notTake);
    }
    
    int longestSubsequence(int n, int a[]) {
       vector<vector<int>> dp(n, vector<int>(n+1, -1));
       
       return f(0, -1, n, a, dp);
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
  // } Driver Code Ends