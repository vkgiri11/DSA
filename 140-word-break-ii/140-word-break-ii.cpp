class Solution {
public:
    bool contains(string word, vector<string>& wordDict) {
        for(int i = 0; i < wordDict.size(); i++) {
            if((word.compare(wordDict[i])) == 0) return true;
        }
        
        return false;
    } 
    vector<string> combine(string word, vector<string> prev) {
        // attach the word at the end of prev elem
        // since recursion returns the last found at first
        for(int i = 0; i < prev.size(); i++) {
            prev[i] += " " + word;
        }
        
        return prev;
    }
    vector<string> wordBreakHelper(string s, vector<string>& wordDict, 
                             unordered_map<string, vector<string>> &mp) {
        
        // memiozation 
        // if s already exists return that
        if(mp.count(s)) return mp[s];
        
        vector<string> result;
        
        // if the whole word is present in dict
        if(contains(s, wordDict))
            result.push_back(s);
        
        for(int i = 1; i < s.size(); i++) {
            string word = s.substr(i);
            
            if(contains(word, wordDict)) {
                // word is from index 'i' to end of string
                // the remainder of string
                string rem = s.substr(0, i);
                
                // wordBreak returns a vector of found strings
                // combine this with the word found
                vector<string> prev = combine(word, wordBreak(rem, wordDict));
                
                // add all the elements of prev to result at the end
                result.insert(result.end(), prev.begin(), prev.end());
            }
        }
        
        // memoize, for the string 's' store the result
        mp[s] = result;
        
        return result;
    }
    vector<string> wordBreak(string str, vector<string>& wordDict) {
        unordered_map<string, vector<string>> mp;
        return wordBreakHelper(str, wordDict, mp);
    }
};