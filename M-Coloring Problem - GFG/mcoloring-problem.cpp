// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to determine if graph can be coloured with at most M colours such
// that no two adjacent vertices of graph are coloured with same colour.
bool isSafe(int node, int color[], bool graph[101][101], int N, int col) {
    
    for(int k = 0; k < N; k++) {
        // col -> color we are trying for the present node
        // If its is not the node itself, and its adjacent node 
        // is not of the color 'col' -> true
        if(k != node && graph[k][node] == 1 && color[k] == col)
            return false;
    }
    
    return true;
}

bool isPossible(int node, int color[], int m, int N, bool graph[101][101]) {
    
    //All nodes traversed
    if(node == N)
        return true;
        
    for(int i = 1; i <= m; i++) {
        //If we can apply a particular color to this node
        if(isSafe(node, color, graph, N, i)) {
            color[node] = i;
            
            if(isPossible(node+1, color, m, N, graph))
                return true;
            
            // If assigning color c doesn't
            // lead to a solution then remove it  
            color[node] = 0;
        }
    }
    
    //If tried every color from  1-m and nothing can be put
    return false;
}

bool graphColoring(bool graph[101][101], int m, int N) {
    int color[N] = {0};
    
    if(isPossible(0, color, m, N, graph))
        return true;
        
    return false;
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends