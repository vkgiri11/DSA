// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    // Minimum no. of ways to find the critical floor
    int f(int eggs, int floors, vector<vector<int>> &dp) {
        // no floors -> 0 trials needed,
        // one floor -> 1 trial needed to determine critical floor
        if(floors == 0 || floors == 1) return floors;
        
        // only 1 egg: start from bottom and keep throwing
        // the egg from every floor till critical is found
        // worst case - critical found at topmost floor k
        if(eggs == 1) return floors;
        
        if(dp[eggs][floors] != -1) return dp[eggs][floors];
        
        int minWays = INT_MAX;
        
        // consider dropping the eggs from all floors
        for(int currentFloor = 1; currentFloor <= floors; currentFloor++) {
            // critical floor will exist below the floor where egg breaks
            int eggBreaks = f(eggs-1, currentFloor-1, dp);
            
            // critical floor will exist above the current floor
            int eggSurvives = f(eggs, floors-currentFloor, dp);
            
            // we will consider max - since we need to find that at
            // this particular floor, if either egg breaks or egg survives, 
            // what will the largest no. of ways(worst case scenario) 
            // to find critical floor
            int worstCase = max(eggBreaks, eggSurvives);
            
            // keep track of minimum no. of ways at every floor
            minWays = min(minWays, worstCase);
        }
        
        
        return dp[eggs][floors] = 1 + minWays;
    }
    int eggDrop(int n, int k) {
        vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
        
        return f(n, k, dp);
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends