class Solution {
public:
    void dfs(int node, vector<int> &visited, vector<vector<int>>& isConnected) {
        visited[node] = 1;
        
        for(int neighbour = 0; neighbour < isConnected[0].size(); neighbour++) {
            if(node != neighbour && isConnected[node][neighbour] && !visited[neighbour]) {
                visited[neighbour] = 1;
                dfs(neighbour, visited, isConnected);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> visited(isConnected.size(), 0);
        int count = 0;
        
        for(int i = 0; i < isConnected.size(); i++) {
            if(!visited[i]) {
                count++;
                dfs(i, visited, isConnected);
            }
        }
        
        return count;
    }
};