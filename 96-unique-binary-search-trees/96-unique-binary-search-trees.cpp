class Solution {
public:
    int numTrees(int n) {
        if(n <= 1) return 1;
        
        vector<int> dp(n+1);
        
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i = 2; i <= n; i++)
            for(int j = 1; j <= i; j++)
                dp[i] += dp[j-1] * dp[i-j];
        
        return dp[n];
    }
//     int numTrees(int n) {
//         if(n <= 1) return 1;
        
//         int ans = 0;
//         for(int i = 1; i <= n; i++) 
//             // no. of trees with 'i' as node
//             // left subtree will have 'i-1' nodes
//             // right subtree will have 'n-i' nodes
//             ans += numTrees(i-1) * numTrees(n-i);
        
//         return ans;
        
//     }
};