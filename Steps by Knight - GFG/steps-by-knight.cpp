// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    bool isValid(int x, int y, int N) {
        if (x >= 1 && x <= N && y >= 1 && y <= N)
            return true;
            
        return false;
    }
	int minStepToReachTarget(vector<int>&initial,vector<int>&target,int N){
	    int dx[] = { -2, -1, 1, 2, -2, -1, 1, 2 };
        int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
        
        vector<vector<int>> vis(N+1, vector<int>(N+1, 0));
        
        // (steps, x, y) steps, initial position
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {initial[0], initial[1]}});
        
        while(!q.empty()) {
            int steps = q.front().first;
            int curr_x = q.front().second.first;
            int curr_y = q.front().second.second;
            q.pop();
            
            // if current cell is equal to target cell,
            // return its distance
            if(curr_x == target[0] && curr_y == target[1]) 
                return steps;
            
            // loop for all reachable states
            for(int i = 0; i < 8; i++) {
                // next positin of knight
                int next_x = curr_x + dx[i];
                int next_y = curr_y + dy[i];
                
                // If reachable state is not yet visited and
                // inside board, push that state into queue
                if(isValid(next_x, next_y, N) && !vis[next_x][next_y]) {
                    vis[next_x][next_y] = true;
                    q.push({steps+1, {next_x, next_y}});
                }
            }
        }
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends