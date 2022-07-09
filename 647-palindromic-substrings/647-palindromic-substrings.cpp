class Solution {
public:
    void expandFromMid(int left, int right, int &count, string &s) {
        while(left >= 0 && right < s.length() && s[left] == s[right]) {
            count++;
            left--;
            right++;
        }
    }
    int countSubstrings(string s) {
        int count = 0;
        
        for(int i = 0; i < s.length(); i++) {
            // odd length
            expandFromMid(i, i, count, s);
            //even length
            expandFromMid(i, i+1, count, s);
        }
        
        return count;
    }
};