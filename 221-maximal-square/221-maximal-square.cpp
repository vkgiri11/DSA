class Solution {
public:
    int f(int row, int col, vector<vector<char>>& mat, vector<vector<int>>& dp) {
        if(row < 0 || col < 0) return 0;
        
        if(dp[row][col] != -1) return dp[row][col];
        
        // the largest square matrix ending at mat[n][m-1]
        int left = f(row, col-1, mat, dp);
        
        // the largest square matrix ending at mat[n-1][m]
        int top = f(row-1, col, mat, dp);
        
        // the largest square matrix ending at mat[n-1][m-1]
        int top_left = f(row-1, col-1, mat, dp);
        
        /* The largest square matrix ending at mat[m][n] 
        will be 1 plus minimum of largest square matrix 
        ending at mat[m][n-1], mat[m-1][n] and mat[m-1][n-1] */
        
        int size = 0;
        if(mat[row][col] == '1')
            size =  1 + min(top_left, min(left, top));
        
        return dp[row][col] = size;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        
        vector<vector<int>> dp(row, vector<int>(col, -1));
        
        // dp table stores the largest size of matrix ending at i,j
        f(row-1, col-1, matrix, dp);
        
        int ans = 0;
        
        // ans will be the max of all sizes
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++) 
                ans = max(ans, dp[i][j]);
        
        return ans*ans;
    }
};