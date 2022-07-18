class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int time = -1;
        // total num of oranges(fresh+rotten)
        int total = 0;
        // co-ord (x, y) of rotten oranges
        queue<pair<int, int>> q;
        
        // directions of subsequent moves
        vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                // if orange found
                if(grid[i][j] > 0) total++;
                
                // storing co-ord of rotten oranges
                if(grid[i][j] == 2) q.push({i, j});
            }
        }

        while(!q.empty()) {
            int size = q.size();
            
            for(int k = 0; k < size; k++) {
                auto curr = q.front();
                q.pop();
                
                // no of computed oranges decreases
                total--;
                
                for(int i = 0; i < 4; i++) {
                    int next_x = curr.first + dir[i][0];
                    int next_y = curr.second + dir[i][1];
                    
                    // if we go out of boundary or find a non fresh orange
                    if(next_x < 0 || next_y < 0 || next_x >= grid.size()
                        || next_y >= grid[0].size() || grid[next_x][next_y] != 1 )
                        continue;
                    
                    // the current orange becomes rotten
                    grid[next_x][next_y] = 2;
                    
                    // push rotten orange in queue
                    q.push({next_x, next_y});
                }
            }
            
            // increase time elapsed after visiting every rotten orange
            time++;
        }
        
        // if all the oranges has been computed(or rotten)
        if(total == 0) return max(0, time);
        
        // if it's not possible for every orange to rot
        return -1;
    }
};