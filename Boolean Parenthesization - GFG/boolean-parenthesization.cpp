// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
int mod = 1003;
class Solution{
public:
    int f(int i, int j, int isTrue, string &s, vector<vector<vector<int>>> &dp) {
        if(i > j) return 0;
        
        if(i == j) {
            if(isTrue) return s[i] == 'T';
            else return s[i] == 'F';
        }
        
        if(dp[i][j][isTrue] != -1) return dp[i][j][isTrue];
        
        int ways = 0;
        for(int ind = i+1; ind <= j-1; ind++) {
            int lt = f(i, ind-1, 1, s, dp);
    		int lf = f(i, ind-1, 0, s, dp);
    		int rt = f(ind+1, j, 1, s, dp);
    		int rf = f(ind+1, j, 0, s, dp);
    		
    		if(s[ind] == '&') {
    			if(isTrue) ways = (ways + (lt * rt)%mod) % mod;
    			
    			else ways = (ways + (lt * rf)%mod + (lf * rt)%mod
    						 + (lf * rf)%mod) % mod;
    		}
		
    		else if(s[ind] == '|') {
    			if(isTrue) ways = (ways + (lt * rt)%mod + (lt * rf)%mod
    							   + (lf * rt)%mod) % mod;
    			else ways = (ways + (rf * lf)%mod) % mod;
    		}
    		
    		else {
    			if(isTrue) ways = (ways + (lt * rf)%mod + (rt * lf)%mod) % mod;
    			else ways = (ways + (lt * rt)%mod + (lf * rf)%mod) % mod;
    		}
        }
        
        return dp[i][j][isTrue] = ways;
    }
    int countWays(int n, string S){
        vector<vector<vector<int>>> dp(n,  
                   vector<vector<int>>(n, 
                            vector<int>(2, -1)));
                            
        return f(0, n-1, 1, S, dp);
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends