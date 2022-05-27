// { Driver Code Starts
// Driver Code
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

 // } Driver Code Ends
// Complete this function
#define llu long long int

llu f(int ind, llu target, int arr[], vector<vector<llu>> &dp) {
    if(ind == 0) {
        if(target % arr[ind] == 0) return 1;
        else return 0;
    }
    
    if(dp[ind][target] != -1) return dp[ind][target];
    
    int notPick = f(ind-1, target, arr, dp);
    
    int pick = 0;
    if(arr[ind] <= target) pick = f(ind, target-arr[ind], arr, dp);
    
    return dp[ind][target] = pick+notPick;
}

long long int count(long long int n) {
    int arr[] = {3, 5, 10};
    
    vector<vector<llu>> dp(3, vector<llu>(n+1, -1));
    
    return f(2, n, arr, dp);
}

// { Driver Code Starts.



int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		cout<<count(n)<<endl;
	}
	return 0;
}  // } Driver Code Ends