class Solution {
public:
    int knightDialer(int n) {
        int mod = 1e9+7;
        vector<vector<int>> paths = {{4,6}, {6,8}, {7,9}, {4,8}, {3,9,0}, { }, 
                                     {1,7,0}, {2,6}, {1,3}, {2,4}};
        
        // dp[i][j] will store number count starting with digit i and length j
        vector<vector<long>> dp (n+1, vector<long>(10, 0));
        
        // base case, for n = 1, at every state only 1 possible way
        for(int j = 0; j < 10; j++) dp[1][j] = 1;
        
        for(int i = 2; i <= n; i++) 
            for(int j = 0; j < 10; j++) 
                for(int p:paths[j]) 
                    dp[i][j] = (dp[i][j] + dp[i-1][p]) % mod;
                
        int sum = 0;
        for(int j = 0; j < 10; j++) sum = (sum + dp[n][j]) % mod;
        
        return sum;
    }
};