class Solution {
public:  
    int uniquePaths(int m, int n) {
        int num = m + n - 2;
        int r = m - 1;
        double res = 1;
        
        for(int i = 1; i <= r; i++)
            res = res * (num - r + i)/i;
        
        return (int)res;
    }
    
    /*
    //DP Memoization 
    int count_paths(int i, int j, int row, int col, vector<vector<int>>& dp)    {
        if(i == row-1 && j == col-1)
            return 1;
        if(i >= row || j >= col)
            return 0;
        if(dp[i][j] != -1) 
            return dp[i][j];
        
        return count_paths(i+1, j, row, col, dp) + count_paths(i, j+1, row, col, dp);
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m , vector<int> (n));
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                dp[i][j] = -1;
        
        return count_paths(0, 0, m, n, dp); 
    }
    */
    
    /*
    //Recursive Solution
    int count_paths(int i, int j, int row, int col) {
        if(i == row-1 && j == col-1)
            return 1;
        if(i >= row || j >= col)
            return 0;
        
        return count_paths(i+1, j, row, col) + count_paths(i, j+1, row, col);
    }
    
    int uniquePaths(int m, int n) {
        return count_paths(0, 0, m, n); 
    }
    */
};