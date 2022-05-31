// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int f(int N, int X, int Y, vector<int> &dp) {
	    if(N == 0) return 0;
	    
	    if(N == 1) return 1;
	    
	    if(dp[N] != -1) return dp[N];
	    
	    if(N-X >= 0 && !f(N-X, X, Y, dp)) return dp[N] = true;
	    
	    else if(N-Y >= 0 && !f(N-Y, X, Y, dp)) return dp[N] = true;
	    
	    else if(N-1 >= 0 && !f(N-1, X, Y, dp)) return dp[N] = true;
	    
	    return dp[N] = false;
	}
	int findWinner(int N, int X, int Y) {
	    vector<int> dp(N+1, -1);
	    return f(N, X, Y, dp);
	    /*
		vector<int> dp(N+1, 0);
		
		// 0 coins 
		dp[0] = 0;
		// 1coin, geek wins
		dp[1] = 1;
		
		for(int i = 2; i <= N; i++) {
		    
		    // If geek losses any of i-1 or i-x
            // or i-y game then he will
            // definitely win game i
		    if(i-1 >= 0 && !dp[i-1]) dp[i] = true;
		    
		    else if(i-X >= 0 && !dp[i-X]) dp[i] = true;
		    
		    else if(i-Y >= 0 && !dp[i-Y]) dp[i] = true;
		        
		    // geek loses
            else dp[i] = false;
		}
		
		return dp[N];
		*/
	}

};
	

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
       	int n, x, y;
       	cin >> n >> x >> y;

       

        Solution ob;
        cout << ob.findWinner(n, x, y);
	    cout << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends