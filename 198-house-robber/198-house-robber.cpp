class Solution {
public:
    int f(int ind, vector<int>& nums, vector<int> &dp) {
        if(ind < 0) return 0;
        
        if(dp[ind] != -1) return dp[ind];
        
        int notPick = f(ind-1, nums, dp);
        
        int pick = nums[ind] + f(ind-2, nums, dp);
        
        return dp[ind] = max(pick, notPick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        
        vector<int> dp(n, 0);
        
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        
        for(int ind = 2; ind < n; ind++) {
            int notPick = dp[ind-1];
        
            int pick = nums[ind] + dp[ind-2];

            dp[ind] = max(pick, notPick);
        }
        
        return dp[n-1];
    }
};