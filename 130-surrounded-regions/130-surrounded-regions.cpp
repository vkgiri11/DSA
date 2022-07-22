class Solution {
public:
    // iterate in 4-directions and change all O to *
    void dfs(int i, int j, vector<vector<char>>& board) {
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size()
           || board[i][j] != 'O') return;
        
        board[i][j] = '*';
        
        dfs(i+1, j, board);
        dfs(i-1, j, board);
        dfs(i, j+1, board);
        dfs(i, j-1, board);
    }
    void solve(vector<vector<char>>& board) {
        if(board.size() == 0) return;
        
        int rows = board.size();
        int col = board[0].size();
        
        // traverse the boundary of the board, 
        // and call dfs if we find O
        
        // check first and last col
        for(int i = 0; i < rows; i++) {
            if(board[i][0] == 'O') dfs(i, 0, board);
            if(board[i][col-1] == 'O') dfs(i, col-1, board);
        }
        
        // check first and last row
        for(int j = 0; j < col; j++) {
            if(board[0][j] == 'O') dfs(0, j, board);
            if(board[rows-1][j] == 'O') dfs(rows-1, j, board);
        }
        
        // flip all the 0 -> X, and * -> 0
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < col; j++) {
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == '*') board[i][j] = 'O';
            }
        }
    }
};