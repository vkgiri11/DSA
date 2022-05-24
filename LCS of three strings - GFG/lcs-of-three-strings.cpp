// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int LCSof3 (string A, string B, string C, int n1, int n2, int n3);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        cout << LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends

    int f(int ind1, int ind2, int ind3, string &s1, string &s2, string &s3,
            vector<vector<vector<int>>> &dp) {
                
        if(ind1 == 0 || ind2 == 0 || ind3 == 0) return 0;
        
        if(dp[ind1][ind2][ind3] != -1) return dp[ind1][ind2][ind3];
        
        if(s1[ind1-1] == s2[ind2-1] && s2[ind2-1] == s3[ind3-1]) 
            return 1 + f(ind1-1, ind2-1, ind3-1, s1, s2, s3, dp);
        
        return dp[ind1][ind2][ind3] = max(f(ind1-1, ind2, ind3, s1, s2, s3, dp), 
                                            max(f(ind1, ind2-1, ind3, s1, s2, s3, dp),
                                                f(ind1, ind2, ind3-1, s1, s2, s3, dp)));
    }
    
    int LCSof3 (string A, string B, string C, int n1, int n2, int n3) {
        vector<vector<vector<int>>> dp(n1+1, 
                                        vector<vector<int>>(n2+1, 
                                                    vector<int>(n3+1, -1)));
                            
        return f(n1, n2, n3, A, B, C, dp);
    }