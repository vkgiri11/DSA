// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int f(int ind, int prevInd, int n, int arr[], vector<vector<int>> &dp) {
    	if(ind == n) return 0;
    	
    	if(dp[ind][prevInd+1] != -1) return dp[ind][prevInd+1];
    	
    	int notTake = 0 + f(ind+1, prevInd, n, arr, dp);
    	
    	int take = 0;
    	if(prevInd == -1 || abs(arr[ind] - arr[prevInd]) == 1) 
    		take = 1 + f(ind+1, ind, n, arr, dp);
    	
    	return dp[ind][prevInd+1] = max(notTake, take);
    }
    int longestSubsequence(int N, int A[]) {
        vector<vector<int>> dp(N, vector<int>(N+1, -1));
	
	    return f(0, -1, N, A, dp);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int A[N];
        for(int i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.longestSubsequence(N, A)<<endl;
    }
    return 0;
}  // } Driver Code Ends