// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int N, vector<vector<int>> adj[]) {
        vector<int> key(N+1, 1e9);
        vector<bool> mst(N+1, false);
        vector<int> parent(N+1, -1);
        
        priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq;
        
        key[0] = 0;
        parent[0] = -1;
        // weight of edge/key[index], index
        pq.push({0,0});
        
        while(!pq.empty()) {

            // returns the minm value in key array 
            int curr = pq.top().second; // nlogn
            pq.pop();
            
            mst[curr] = true;
            
            for(auto it: adj[curr]) {
                int adjNode = it[0];
                int weight = it[1];
                if(mst[adjNode] == false && weight < key[adjNode]) {
                    parent[adjNode] = curr;
                    key[adjNode] = weight;
                    pq.push({key[adjNode], adjNode});
                }
            }
        }
        
        // parent stores the parent of every index
        // key stores all the edge weight of MST
        
        int sum = 0;
        for(int i = 1; i <= N; i++)
            if(key[i] != 1e9) sum += key[i];
            
        return sum;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends