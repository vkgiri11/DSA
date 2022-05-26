// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
  /*
    int f(int ind, int n, int arr[], vector<int> &dp) {
        // if reached last element or try to go beyond that
        if(ind >= n-1) return 0;
        
        if(dp[ind] != -1) return dp[ind];
        
        int minJumps = 1e8;
        
        for(int steps = 1; steps <= arr[ind]; steps++) {
            // only jump if the elem is not zero OR jumping straight to last element
            // 1 2 0 0 -> we can jump to 0 at 4th index since that is the last elem
            // and after that we dont need to pass through it
            if(arr[ind+steps] != 0 || ind+steps == n-1)
                minJumps = min(minJumps, 1 + f(ind+steps, n ,arr, dp));
        }

        return dp[ind] = minJumps;
    }
    */
    int minJumps(int arr[], int n){
        /*
        if(n == 1) return 0;
        
        vector<int> dp(n, -1);
        
        int ans = f(0, n, arr, dp);
        
        // if cant reach the end return -1
        if(ans == 1e8) return -1;
        else return ans;
        */
        
        // single elem, that is last elem
        // no jump
        if(n <= 1) return 0;
        
        // not possible to reach end
        if(arr[0] == 0) return -1;
        
        // initialization
        
        // stores all time the maximal
        // reachable index in the array.
        int maxReachableIndex = arr[0];
        // stores the number of steps
        // we can still take
        int step = arr[0];
        // num of jumps necessary to reach
        // max reachable position
        int jump = 1;
        
        int i = 1;
        for(int i = 1; i < n; i++) {
            if(i == n-1) return jump;
            
            maxReachableIndex = max(maxReachableIndex, i + arr[i]);
            
            // we use a step to get to the current index
            step--;
            
            if(step == 0) {
                // we must have used a jump
                jump++;
                
                // Check if the current index/position or lesser index
                // is the maximum reach point from the previous indexes
                if (i >= maxReachableIndex)
                    return -1;
                    
                // re-initialize the steps to the amount
                // of steps to reach maxReachableIndex from position i.
                step = maxReachableIndex - i;
            }
        }
        
        return -1;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends