// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int maxSubstring(string S) {
        int cur_sum = 0, max_sum = 0;
        
        for(int i = 0; i < S.size(); i++) {
            cur_sum += (S[i] == '0' ? 1 : -1);
            
            if(cur_sum < 0) cur_sum = 0;
            
            max_sum = max(max_sum, cur_sum);
        }	   
	    
	    // if no zero in string, return -1
	    return max_sum == 0 ? -1 : max_sum;
	    
	}
};

// { Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.maxSubstring(s) << "\n";
   	}

    return 0;
}
  // } Driver Code Ends