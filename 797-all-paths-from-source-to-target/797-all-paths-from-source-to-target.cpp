class Solution {
public:
    void dfs(int currNode, vector<int> &currPath, vector<vector<int>> &allPaths,
                         vector<vector<int>> &graph) {
        
        currPath.push_back(currNode);
        
        // if the node is equal to 'n-1', which is our target node
        if(currNode == graph.size()-1)
            allPaths.push_back(currPath);
        
        else {
            for(auto it: graph[currNode])
                dfs(it, currPath, allPaths, graph);
        }
        
        // backtracking
        // remove currNode
        currPath.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> allPaths;
        vector<int> currPath;
        
        // the starting node is 0
        dfs(0, currPath, allPaths, graph);
        
        return allPaths;
    }
};