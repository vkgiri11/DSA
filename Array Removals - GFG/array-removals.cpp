// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int f(int start, int end, vector<int>& a, int k, vector<vector<int>> &dp) {
        if(start >= end) return 0;
        
        if(a[end] - a[start] <= k) return 0;
        
        if(dp[start][end] != -1) return dp[start][end];
        
        int move_start = 1 + f(start+1, end, a, k, dp);
        int move_end = 1 + f(start, end-1, a, k, dp);
        
        return dp[start][end] = min(move_start, move_end);
    }
    int removals(vector<int>& a, int k){
        sort(a.begin(), a.end());
        
        int n = a.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return f(0, n-1, a, k, dp);
    }
};


// { Driver Code Starts.


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        Solution ob;
        int ans = ob.removals(a,k);
        
        cout<<ans<<endl;
    }
}


  // } Driver Code Ends