class Solution {
public:
    int f(int ind, vector<int>& nums, vector<int> &dp) {
        if(ind == nums.size()) return 0;
        
        if(dp[ind] != -1) return dp[ind];
        
        // delete and earning this element
        int earned = nums[ind];
        int skip = ind+1;
        
        // add all similar values at once
        while(skip < nums.size() && nums[skip] == nums[ind]) {
            earned += nums[ind];
            skip++;
        }
        
        // move past all elements with value = nums[ind]+1
        // this is instead of deleting the elements = nums[ind] + 1
        while(skip < nums.size() && nums[skip] == nums[ind]+1)
            skip++;
        
        earned += f(skip, nums, dp);
        
        // dont delete and earn this elem
        int notEarned = f(ind+1, nums, dp);
            
        return dp[ind] = max(earned, notEarned);
        
    }
    int deleteAndEarn(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        sort(nums.begin(), nums.end());
        return f(0, nums, dp);       
    }
};