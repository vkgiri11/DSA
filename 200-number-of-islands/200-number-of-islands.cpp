class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& grid) {
        if(row < 0 || row >= grid.size() || col < 0 || 
           col >= grid[0].size() || grid[row][col] == '0')
            return;
        
        // mark current as visited = 0, so that it cant 
        // be visited again in same recursive call
        grid[row][col] = '0';
        
        dfs(row+1, col, grid);
        dfs(row-1, col, grid);
        dfs(row, col+1, grid);
        dfs(row, col-1, grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        
        int islands = 0;
        
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++) 
                if(grid[i][j] == '1') {
                    dfs(i, j, grid);
                    islands++;
                }

        
        return islands;
    }
};