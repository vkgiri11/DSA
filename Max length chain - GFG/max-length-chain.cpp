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
    
    // prev+1 : right shift index since prev starts with -1
    if(dp[ind][prev+1] != -1) return dp[ind][prev+1];
    
    // notTake -> move ind, prev remains at place
    int notTake = f(ind+1, prev, n, p, dp);
    
    int take = 0;
    // if first elem, or condition satisfy we can take
    if(prev == -1 || p[ind].first > p[prev].second)
        // ind moves to next elem, prev becomes the current elem
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