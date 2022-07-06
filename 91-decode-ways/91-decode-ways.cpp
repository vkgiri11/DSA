class Solution {
public:
    int f(int ind, string &s, vector<int> &dp) {
        if(ind == s.size()) return 1;
        
        //0 cant be mapped to any number
        if(s[ind] == '0') return dp[ind] = 0;
        
        if(dp[ind] != -1) return dp[ind];
        
        // taking only one number
        int ways = f(ind+1, s, dp);
        
        // possible values for all grouping with 2 numbers
        if(ind < s.size()-1 && (s[ind] == '1' || (s[ind] == '2' && s[ind+1] < '7')))
            ways += f(ind+2, s, dp);
        
        return dp[ind] = ways;
    }
    int numDecodings(string s) {
        vector<int> dp(s.size(), -1);
        
        return s.size() == 0 ? 0 : f(0, s, dp);
    }
};