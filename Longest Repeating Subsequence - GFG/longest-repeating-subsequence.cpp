// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
	    int f(int ind1, int ind2, string &s1, string &s2, vector<vector<int>> &dp) {
        if(ind1 == 0 || ind2 == 0) return 0;
        
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        
        if(s1[ind1-1] == s2[ind2-1])
            if(ind1 != ind2)
                return 1 + f(ind1-1, ind2-1, s1, s2, dp);
        
        return dp[ind1][ind2] = max(f(ind1-1, ind2, s1, s2, dp), 
                                    f(ind1, ind2-1, s1, s2, dp));
        }
		int LongestRepeatingSubsequence(string str){
		    int n = str.size();
		    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
		    
		    return f(n, n, str, str, dp);
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends