// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};



int maxChainLen(struct val p[],int n);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		
		cout<<maxChainLen(p,n)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

int f(int ind, int prev, int n, struct val p[], vector<vector<int>> &dp) {
    if(ind == n) return 0;
    
    if(dp[ind][prev+1] != -1) return dp[ind][prev+1];
    
    int notTake = f(ind+1, prev, n, p, dp);
    
    int take = 0;
    if(prev == -1 || p[ind].first > p[prev].second)
        take = 1 + f(ind+1, ind, n, p, dp);
    
    return dp[ind][prev+1] = max(take, notTake);
}

static bool comp(struct val a,struct val b){
   return a.second<b.second;
}

int maxChainLen(struct val p[],int n) {
    sort(p,p+n,comp);
    
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return f(0, -1, n, p, dp);
}