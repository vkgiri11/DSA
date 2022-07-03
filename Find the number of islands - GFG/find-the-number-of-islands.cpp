// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    void dfsHelper(int x, int y, int dx[], int dy[], vector<vector<char>>& grid) {
        if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == '0')
            return;
            
        grid[x][y] = '0';
        
        for(int i = 0; i < 8; i++) {
            int next_x = x + dx[i];
            int next_y = y + dy[i];
            
            dfsHelper(next_x, next_y, dx, dy, grid);
        }
        
        return ;
    }
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        
        int count = 0;
        
        int dx[8] = {0, 1, 1, 1, 0,-1,-1,-1};
        int dy[8] = {1, 1, 0,-1,-1,-1, 0, 1};
        
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(grid[i][j] == '1') {
                    count++;
                    dfsHelper(i, j, dx, dy, grid);
                }
            }
        }
        
        return count;
        
        
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends