// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
#define ll long long
class Solution{
    public:
    ll f(int start, int end, int arr[], vector<vector<int>> &dp) {
        if(start > end) return 0;
        
        if(start == end) return arr[start];
        
        if(dp[start][end] != -1) return dp[start][end];
        
        /*
        The user chooses the ‘ith’ coin with value ‘Vi’: 
        The opponent either chooses (i+1)th coin or jth coin. 
        The opponent intends to choose the coin which leaves 
        the user with minimum value. 
        */
        ll pickFirst = arr[start] + min(f(start+2, end, arr, dp),
                                        f(start+1, end-1, arr, dp));
        
        /*
        The user chooses the ‘jth’ coin with value ‘Vj’: 
        The opponent either chooses ‘ith’ coin or ‘(j-1)th’ coin. 
        The opponent intends to choose the coin which leaves 
        the user with minimum value.
        */
        ll pickLast = arr[end] + min(f(start, end-2, arr, dp), 
                                     f(start+1, end-1, arr, dp));
        
        return dp[start][end] = max(pickFirst, pickLast);
    }
    long long maximumAmount(int arr[], int n){
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return f(0, n-1, arr, dp);
    }
};

// { Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(a,n)<<endl;
	}
	return 0;
}  // } Driver Code Ends