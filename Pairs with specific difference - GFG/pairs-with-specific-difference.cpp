// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    int f(int ind, int arr[], int k, vector<int> &dp) {
        if(ind < 0) return 0;
        
        if(dp[ind] != -1) return dp[ind];
        
        int notTake = f(ind-1, arr, k, dp);
        
        int take = 0;
        if(ind-1 >= 0 && arr[ind] - arr[ind-1] < k)
            take = arr[ind] + arr[ind-1] + f(ind-2, arr, k, dp);
            
        return dp[ind] = max(take, notTake);
    }
    int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K) {
        sort(arr,arr+N);
        
        vector<int> dp(N, -1);
        return f(N-1, arr, K, dp);
    }
};

// { Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int N;
		cin>>N;
		int arr[N];
		for(int i=0;i<N;i++)
		cin>>arr[i];

		int K;
		cin>>K;
        Solution ob;
		cout<<ob.maxSumPairWithDifferenceLessThanK(arr,N,K)<<endl;
	}
	return 0;
}
  // } Driver Code Ends