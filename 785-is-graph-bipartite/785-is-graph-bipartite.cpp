class Solution {
public:
    bool bipartiteBFS(int curr, vector<vector<int>>& adj, vector<int> &colors) {
        queue<int>q;
        q.push(curr);
        // initial color: 1
        colors[curr] = 1;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(auto it: adj[node]) {
                // adj node not colored
                if(colors[it] == -1) {
                    q.push(it);
                    // color alloted opposite of current
                    colors[it] = 1 - colors[node];
                }
                else if(colors[it] == colors[node]) return false;
            }
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> colors(v, -1);
        for(int i = 0; i < v; i++) {
            if(colors[i] == -1) {
                if(!bipartiteBFS(i, graph, colors)) return false;
            }
        }

        return true;
    }
};