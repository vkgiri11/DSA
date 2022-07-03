// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    bool checkCycle(int src, vector<bool> &vis, vector<bool> &dfsVis, 
                    vector<int> adj[]) {
        
        vis[src] = 1;
        dfsVis[src] = 1;
        
        for(auto it: adj[src]) {
            if(!vis[it]){
                if(checkCycle(it, vis, dfsVis, adj)) 
                return true;
            }
            else if (dfsVis[it]) return true;
        }
        
        dfsVis[src] = 0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> vis(V, 0);
        vector<bool> dfsVis(V, 0);
        
        for(int i = 0; i < V; i++) {
            if(!vis[i])
                if(checkCycle(i, vis, dfsVis, adj)) return true;
        }
        
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends