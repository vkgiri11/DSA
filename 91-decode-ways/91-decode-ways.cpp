class Solution {
public:
    int f(int ind, string &s, vector<int> &dp) {
        if(ind == s.size()) return 1;
        
        //0 cant be mapped to any number
        if(s[ind] == '0') return 0;
        
        if(dp[ind] != -1) return dp[ind];
        
        // taking only one number
        int ways = f(ind+1, s, dp);
        
        // possible values for all grouping with 2 numbers
        if(ind < s.size()-1 && (s[ind] == '1' || (s[ind] == '2' && s[ind+1] < '7')))
            ways += f(ind+2, s, dp);
        
        return dp[ind] = ways;
    }
    int numDecodings(string s) {
        int n = s.size();
        
        vector<int> dp(n+1, 0);
        dp[n] = 1;
        
        for(int ind = n-1; ind >= 0; ind--) {
            if(s[ind] == '0') dp[ind] = 0;
            
            else {
                dp[ind] = dp[ind+1];
                
                if(ind < n-1 && (s[ind] == '1' || (s[ind] == '2' && s[ind+1] < '7')))
                    dp[ind] += dp[ind+2];
            }
        }
        
        return s.size() == 0 ? 0 : dp[0];
    }
};