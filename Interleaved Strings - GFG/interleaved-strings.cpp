// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    bool f(int ind1, int ind2, string &a, string &b, string &c,
            vector<vector<int>> &dp) {
                
        if(ind1 == a.size() && ind2 == b.size()) return true;
        
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        
        // ind c = ind a + ind b
        
        // matches with char of str a
        if(ind1 < a.size() && a[ind1] == c[ind1+ind2] && f(ind1+1, ind2, a, b, c, dp))
            return dp[ind1][ind2] = true;
           
        // matches with char of str b 
        if(ind2 < b.size() && b[ind2] == c[ind1+ind2] && f(ind1, ind2+1, a, b, c, dp))
            return dp[ind1][ind2] = true;
            
         return dp[ind1][ind2] = false;
    }
    bool isInterleave(string a, string b, string c) {
        if(a.size() + b.size() != c.size()) return false;
        
        vector<vector<int>> dp(a.size()+1, vector<int>(b.size()+1, -1));
        
        return f(0, 0, a, b, c, dp);
    }

};

// { Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}  // } Driver Code Ends