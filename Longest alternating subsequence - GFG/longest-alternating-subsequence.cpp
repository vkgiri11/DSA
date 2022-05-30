// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
	    /* 
	        arr -> 1 17  5  10  13 15 10 5  16 8
	        inc -> 1  2' 2  4'  4  4  4  4  6' 6
	        dec -> 1' 1  3' 3   3  3  3  5' 5  7'
	        
	        x' -> part of ans sequence
	    */
		int AlternatingaMaxLength(vector<int>&arr){
		    int inc = 1, dec = 1;
		    
		    for(int i = 1;  i < arr.size(); i++) {
		        if(arr[i] > arr[i-1]) inc = dec + 1;
		        if(arr[i] < arr[i-1]) dec = inc + 1; 
		    }
		    
		    return max(inc, dec);
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.AlternatingaMaxLength(nums);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends