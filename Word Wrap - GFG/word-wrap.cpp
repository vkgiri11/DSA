// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int f(int ind, int n, vector<int> &nums, int k, vector<int> &dp) {
        if(ind >= n) return 0;
        
        if(dp[ind] != -1) return dp[ind];
        
        int ans = INT_MAX, sum = 0;
        for(int j = ind; j < n; j++) {
            // sum -> total chars in curr len
            sum += nums[j];
            
            // word len + spaces betwween them <= line len
            if(sum + (j - ind) <= k) {
                int cost = 0;
                
                // excluding last word, since spaces after 
                // last word is not be considered
                if(j != n-1)
                    // cost = spaces in the line squared
                    cost = pow(k - (sum + j - ind), 2);
                 
                // keep updating for every line    
                ans = min(ans, cost + f(j+1, n, nums, k, dp));
            }
        }
        
        return dp[ind] = ans;
    }
    int solveWordWrap(vector<int>nums, int k) { 
        vector<int> dp(nums.size(), -1);
        return f(0, nums.size(), nums, k, dp);
    } 
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}  // } Driver Code Ends