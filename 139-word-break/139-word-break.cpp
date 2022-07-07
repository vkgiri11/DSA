class Solution {
public:
    bool contains(string word, vector<string>& wordDict) {
        for(int i = 0; i < wordDict.size(); i++) {
            if((word.compare(wordDict[i])) == 0) return true;
        }
        
        return false;
    }
    bool f(int start, string &s, vector<string>& wordDict, vector<int> &dp) {
        if(start == s.size()) return true;
        
        if(dp[start] != -1) return dp[start];
        
        string temp;
        for(int i = start; i < s.size(); i++) {
            // keep checking from start position if any word is in dict
            // if found, check further starting from next position 
            if(contains(temp+=s[i], wordDict) && f(i+1, s, wordDict, dp))
                return dp[start] = true;
        }
        
        return dp[start] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int> dp(n+1);
        
        dp[n] = 1;
    
        for(int start = n-1; start >= 0; start--) {
            string temp;
            for(int i = start; i < n; i++) {
                if(contains(temp+=s[i], wordDict) && dp[i+1]) {
                    dp[start] = true;
                    break;
                }
            }
        }
        
        return dp[0];
    }
};