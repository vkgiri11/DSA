// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int f(int i, int j, vector<vector<int>> &a, vector<vector<int>> &dp) {
        if(j < 0 || j >= a[0].size()) return INT_MIN;
        
        if(i == 0) return a[i][j];
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int up = a[i][j] + f(i-1, j, a, dp);
        int left_dia = a[i][j] + f(i-1, j-1, a, dp);
        int right_dia = a[i][j] + f(i-1, j+1, a, dp);
        
        return dp[i][j] = max(up, max(left_dia, right_dia));
    }
    int maximumPath(int N, vector<vector<int>> Matrix) {
        vector<vector<int>> dp(N, vector<int>(N, -1));
        
        int ans = INT_MIN;
        
        for(int j = 0; j < N; j++)
            ans = max(ans, f(N-1, j, Matrix, dp));
        
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}  // } Driver Code Ends