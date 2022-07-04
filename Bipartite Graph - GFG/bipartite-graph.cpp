// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool bipartiteDFS(int curr, vector<int> adj[], vector<int> &colors) {
        // assign initial color as 1
        if(colors[curr] == -1) colors[curr] = 1;
        
        for(auto it : adj[curr]) {
            if(colors[it] == -1) {
                colors[it] = 1 - colors[curr];
                if(!bipartiteDFS(it, adj, colors)) return false;
            }
            else if(colors[it] == colors[curr]) return false;
        }
        
        return true;
    }
	bool isBipartite(int v, vector<int>adj[]){
	    vector<int> colors(v, -1);
        for(int i = 0; i < v; i++) {
            if(colors[i] == -1) {
                if(!bipartiteDFS(i, adj, colors)) return false;
            }
        }
        
        return true;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends