// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++
int f(int ind, int n, int transactionNum, vector<int> &price, 
        vector<vector<int>> &dp) {
            
    if(ind == n || transactionNum == 4) return 0;
    
    if(dp[ind][transactionNum] != -1) return dp[ind][transactionNum];
    
    // BUY STOCK
    if(transactionNum % 2 == 0) {
        int buy = -price[ind] + f(ind+1, n, transactionNum+1, price, dp);
        int notBuy = 0 + f(ind+1, n, transactionNum, price, dp);
        
        return dp[ind][transactionNum] = max(buy, notBuy);
    }
    // SELL STOCK
    else {
        int sell = price[ind] + f(ind+1, n, transactionNum+1, price, dp);
        int notSell = 0 + f(ind+1, n, transactionNum, price, dp);
        
        return dp[ind][transactionNum] = max(sell, notSell);
    }
}
int maxProfit(vector<int> &price) {
    int n = price.size();
    
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return f(0, n, 0, price, dp);
}

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        cout<<maxProfit(price)<<endl;
    }

}
  // } Driver Code Ends