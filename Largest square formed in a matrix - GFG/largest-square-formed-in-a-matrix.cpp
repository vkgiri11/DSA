// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int f(int i, int j, vector<vector<int>> &mat,
            vector<vector<int>> &dp) {
                
        if(i < 0 || j < 0) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        // the largest square matrix ending at mat[n][m-1]
        int left = f(i, j-1, mat, dp);
        
        // the largest square matrix ending at mat[n-1][m]
        int top = f(i-1, j, mat, dp);
        
        // the largest square matrix ending at mat[n-1][m-1]
        int top_left = f(i-1, j-1, mat, dp);
        
        /* The largest square matrix ending at mat[m][n] 
        will be 1 plus minimum of largest square matrix 
        ending at mat[m][n-1], mat[m-1][n] and mat[m-1][n-1] */
        
        int size = 0;
        if(mat[i][j])
            size =  1 + min(top_left, min(left, top));
        
        return dp[i][j] = size;
    }
    int maxSquare(int n, int m, vector<vector<int>> mat){
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        f(n-1, m-1, mat, dp);
        
        int ans = 0;
        
        for(int i = 0; i < n; i++) 
            for(int j = 0; j < m; j++) 
                ans = max(ans, dp[i][j]);
          
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n*m;i++)
            cin>>mat[i/m][i%m];
        
        Solution ob;
        cout<<ob.maxSquare(n, m, mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends