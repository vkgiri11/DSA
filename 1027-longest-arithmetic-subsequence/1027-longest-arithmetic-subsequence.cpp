class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        vector<vector<int>> dp(n, vector<int>(1001,0));
        
        // iterating over all non- zero length sequence forming indices
        for(int i = 0; i < n; i++) {
            // iterating over all previous values to get all possible solutions
            for(int j = 0; j < i; j++) {
                int diff = nums[i] - nums[j] + 500;
                // what was longest till j with difference diff
                dp[i][diff] = dp[j][diff] > 0 ? dp[j][diff] + 1 : 2;
                ans = max(ans, dp[i][diff]);
            }
        }
        
        return ans;
    }
};