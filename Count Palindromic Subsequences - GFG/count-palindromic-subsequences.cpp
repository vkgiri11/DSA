// { Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    long long int mod = 1e9+7;
    long long int f(int start, int end, string &str, vector<vector<int>> &dp) {
        if(start > end) return 0;
        
        if(start == end) return 1;
        
        if(dp[start][end] != -1) return dp[start][end];
        
        if(str[start] == str[end])
            return dp[start][end] = (1 + f(start+1, end, str, dp) 
                                        + f(start, end-1, str, dp))%mod;
        
        // adding mod so that ans doesnt get negative
        else
            return dp[start][end] = (mod + f(start+1, end, str, dp) 
                                         + f(start, end-1, str, dp) 
                                         - f(start+1, end-1, str, dp))%mod;
    }
    long long int  countPS(string str) {
        int n = str.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return f(0, n-1, str, dp);
    }
     
};

// { Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}  // } Driver Code Ends