// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    bool isMoveValid(int x, int y, int numPad[4][3]) {
        if(x < 0 || x > 3 || y < 0 || y > 2)
            return false;
            
        if(numPad[x][y] == -1) return false;
        
        else return true;
    }
	long long f(int x, int y, int n, int numPad[4][3], 
	                vector<vector<long long>> &dp) {
	                    
	    if(n == 1) return 1;
	    
	    if(dp[numPad[x][y]][n] != -1) return dp[numPad[x][y]][n];
	    
	    // left, up, right, down move from current location
	    int dy[] = {0, 0, -1, 0, 1};
        int dx[] = {0, -1, 0, 1, 0};
	    
	    long long count = 0;
	    
	    for(int i = 0; i < 5; i++) {
	        int moveX = x + dx[i];
	        int moveY = y + dy[i];
	        
	        if(isMoveValid(moveX, moveY, numPad))
	            count += f(moveX, moveY, n-1, numPad, dp);
	    }
	    
	    return dp[numPad[x][y]][n] = count;
	}
	long long getCount(int N) {
	    int numPad[4][3] = {
                            {1, 2, 3},
                            {4, 5, 6},
                            {7, 8, 9},
                            {-1, 0, -1}
                        };
		
		long long ans = 0;
		
		// dp[i][j] will store number count starting with digit i and length j
		vector<vector<long long>> dp(10, vector<long long>(N+1, -1));
		
		for(int i = 0; i < 4; i++) {
		    for(int j = 0; j < 3; j++) {
		        if(numPad[i][j] != -1)
		            ans += f(i, j, N, numPad, dp);
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
    while (t--)
    {
        int n;
        cin >> n;

       

	    Solution ob;
	    cout << ob.getCount(n) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends