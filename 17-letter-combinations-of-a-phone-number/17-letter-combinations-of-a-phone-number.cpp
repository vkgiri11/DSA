class Solution {
public:
    void f(int ind, string &combi, string &digits, vector<string> &mappings, vector<string> &ans) {
        // end of string reached, must have found some combination
        if(ind == digits.size()) {
            ans.push_back(combi);
            return;
        }
        
        // -'2', to offset the index 0 and 1 who dont have numbers on keypad
        for(auto &ch : mappings[digits[ind] - '2']) {
            // add this in our combi
            combi += ch;
            // recurse for next positions
            f(ind+1, combi, digits, mappings, ans);
            // backtrack
            combi.pop_back();
        }
        
    }
    vector<string> letterCombinations(string digits) {
        vector<string> mappings = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        
        if(digits == "") return ans;
        
        // keeps a track of different combinations possible
        string combi = "";
        
        f(0, combi, digits, mappings, ans);
        
        return ans;
        
    }
};