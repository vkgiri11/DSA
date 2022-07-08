class Solution {
public:
    int f(int ind, int target, vector<int>& coins, vector<vector<int>> &dp) {
        if(ind == 0) {
            if(target % coins[ind] == 0)
                return target/coins[ind];
            else
                return 1e9;
        }
        
        if(dp[ind][target] != -1) return dp[ind][target];
        
        int notPick = f(ind-1, target, coins, dp);
        
        int pick = 1e9;
        if(coins[ind] <= target)
            pick = 1 + f(ind, target-coins[ind], coins, dp);
        
        return dp[ind][target] = min(pick, notPick);
        
    }
    int coinChange(vector<int>& coins, int target) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(target+1, 0));
        
        for(int T = 0; T <= target; T++) {
            if(T % coins[0] == 0) dp[0][T] = T/coins[0];
            else dp[0][T] = 1e9;
        }
        
        for(int ind = 1; ind < n; ind++) {
            for(int T = 0; T <= target; T++) {
                int notPick = dp[ind-1][T];
        
                int pick = 1e9;
                if(coins[ind] <= T)
                    pick = 1 + dp[ind][T-coins[ind]];

                dp[ind][T] = min(pick, notPick);
            }
        }
        
        int ans = dp[n-1][target];
        
        if(ans == 1e9) return -1;
        else return ans;
    }
};