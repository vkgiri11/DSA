// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxProfit(int k, int n, int prices[]) {
        vector<vector<int>> dp(n+1, vector<int>(2*k + 1, 0));

    	for(int ind = n-1; ind >= 0; ind--) {
    		for(int transNum = 2*k-1; transNum >= 0; transNum--) {
    				int profit = 0;
    				
    				if(transNum % 2 == 0) {
    					int buy = -prices[ind] + dp[ind+1][transNum+1];
    					int notBuy = dp[ind+1][transNum];
    					profit = max(buy, notBuy);
    				}
    				else {
    					int sell = prices[ind] + dp[ind+1][transNum+1];
    					int notSell = dp[ind+1][transNum];
    					profit = max(sell, notSell);
    				}
    				
    				dp[ind][transNum] = profit;
    		}
    	}
    	
    	return dp[0][0];  
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}  // } Driver Code Ends