// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string expandFromMid(int left, int right, string &s) {
        while(left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        
        return s.substr(left+1, right-left-1);
    }
    string longestPalindrome(string S){
        // code here 
        string ans = "";
        
        for(int i = 0; i < S.length(); i++) {
            // odd length
            string s1 = expandFromMid(i, i, S);
            //even length
            string s2 = expandFromMid(i, i+1, S);
            
            if(s1.length() > ans.length()) ans = s1;
            if(s2.length() > ans.length()) ans = s2;
        }
        
        return ans;
    }
};

// { Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.longestPalindrome(S)<<endl;
    }
    return 0;
}
  // } Driver Code Ends