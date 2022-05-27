// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
#define llu long long int
int mod = 1e9 + 7;
class Solution {
  public:
    // Possible values of left right subtrees
    // (h-1, h-2) (h-2, h-1) , (h-1, h-1) 
    long long int countBT(int h) { 
        vector<llu> dp(h+1, 0);
        
        // One tree is possible with height 0 or 1
        dp[0] = dp[1] = 1;
        
        for(llu i = 2; i <= h; i++) {
            dp[i] = (dp[i-1] * ((2 * dp[i-2])%mod + dp[i-1])%mod)%mod;
        }
        
        return dp[h];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int h;
        cin >> h;
        Solution ob;
        cout<<ob.countBT(h)<<endl;  
    }
    return 0;
}
  // } Driver Code Ends