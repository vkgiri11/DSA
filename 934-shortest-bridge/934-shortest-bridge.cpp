class Solution {
public:
    // This paints(increases) the value of nodes in a island to 2 and
    // stores them in a queue (DFS traversal on one of island)
    void paint(int x, int y, vector<vector<int>>& grid, queue<pair<int, int>> &q) {
        
        // allow only valid moves in same island which is not painted
        if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size()
            || grid[x][y] == 0 || grid[x][y] == 2)
            return;
        
        // paint the node to 2
        grid[x][y] = 2;
        q.push({x, y});
        
        paint(x-1, y, grid, q);
        paint(x+1, y, grid, q);
        paint(x, y-1, grid, q);
        paint(x, y+1, grid, q);     
    }
    int bfsHelper(vector<vector<int>>& grid, queue<pair<int, int>> &q) {
        vector<int> moves = {0, 1, 0, -1, 0};
        int ans = 0;
        
        while(!q.empty()) {
            int size = q.size();
            
            while(size-- > 0) {
                auto curr = q.front();
                q.pop();
                
                for(int k = 0; k < 4; k++) {
                    int next_x = curr.first + moves[k];
                    int next_y = curr.second + moves[k+1];
                    
                    // out of bound or already visited
                    if(next_x < 0 || next_y < 0 || next_x >= grid.size() 
                       || next_y >= grid[0].size() || grid[next_x][next_y] == 2)
                        continue;
                    
                    // found the second island
                    if(grid[next_x][next_y] == 1) return ans;
                    
                    q.push({next_x, next_y});
                    // mark visited
                    grid[next_x][next_y] = 2;
                }
            }
                            
            ans++;
        }
        
        // no bridge found
        return -1;
    }
    int shortestBridge(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        bool flag = false;
        
        for(int i = 0; i < grid.size(); i++) {          
            // used to control that we paint only one island
            if(flag) break;
            
            for(int j = 0; j < grid[0].size(); j++) {  
                // find any of the island, call paint function
                if(grid[i][j] == 1 && !flag) {
                    paint(i, j, grid, q);
                    flag = true;
                    break;
                }
            }
        }
        
        return bfsHelper(grid, q);
    }
};