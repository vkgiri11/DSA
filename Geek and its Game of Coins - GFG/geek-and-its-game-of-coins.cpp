// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int f(int coins, int X, int Y, vector<int> &dp) {
	    if(coins == 0) return 0;
	    
	    if(coins == 1) return 1;
	    
	    if(dp[coins] != -1) return dp[coins];
	    
	    if(coins-X >= 0 && !f(coins-X, X, Y, dp)) 
	        return dp[coins] = true;
	    
	    else if(coins-Y >= 0 && !f(coins-Y, X, Y, dp)) 
	        return dp[coins] = true;
	    
	    else if(coins-1 >= 0 && !f(coins-1, X, Y, dp)) 
	        return dp[coins] = true;
	    
	    return dp[coins] = false;
	}
	int findWinner(int N, int X, int Y) {
	    vector<int> dp(N+1, -1);
	    return f(N, X, Y, dp);
	    /*
		vector<int> dp(N+1, 0);
		
		// 0 coins 
		dp[0] = 0;
		// 1 coin, geek wins
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