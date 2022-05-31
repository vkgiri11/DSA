// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isPalindrome(int i, int j, string &str) {
    	while(i < j) {
    		if(str[i] != str[j]) return false;
    		i++;
    		j--;
    	}
    	return true;
    }
    int palindromicPartition(string str) {
        int n = str.size();
    	vector<int> dp(n+1, 0);
    	
    	dp[n] = 0;
    	
    	for(int i = n-1; i >= 0; i--) {
    		int minCuts = 1e9;
    		for(int j = i; j < n; j++) {
    			if(isPalindrome(i, j, str)) {
    				int cuts = 1 + dp[j+1];
    				minCuts = min(minCuts, cuts);
    			}
    		}
    		
    		dp[i] = minCuts;
    	}
    	
    	return dp[0] - 1; 
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends