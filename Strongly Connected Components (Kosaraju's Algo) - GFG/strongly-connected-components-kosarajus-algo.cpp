// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	void topoSort(int node, stack<int> &st, vector<int> &vis, 
	vector<int> adj[]) {
	    
        vis[node] = 1; 
        for(auto it: adj[node]) {
            if(!vis[it]) {
                topoSort(it, st, vis, adj); 
            }
        }
        
        st.push(node); 
    }
    // simple dfs on a reverse graph
    void dfs(int node, vector<int> &vis, vector<int> transpose[]) {
        vis[node] = 1; 
        
        for(auto it: transpose[node]) {
            if(!vis[it]) {
                dfs(it, vis, transpose); 
            }
        }
    }
    int kosaraju(int V, vector<int> adj[]) {
        // Find topo sort
        stack<int> st;
        vector<int> vis(V, 0);
        for(int i = 0; i < V; i++) {
            if(!vis[i]) topoSort(i, st, vis, adj);
        }
        
        // adj list for graph with reversed edge dirn
        vector<int> transpose[V];
        for(int i = 0; i < V; i++) {
            vis[i] = 0;
            for(auto it: adj[i])
                transpose[it].push_back(i);
        }
        
        int ans = 0;
        
        // dfs visit in topo sort order
        while(!st.empty()) {
            int node = st.top();
            st.pop();
            if(!vis[node]) {
                ans++;
                dfs(node, vis, transpose);
            }
        }
        
        return ans;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends