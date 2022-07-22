class Solution {
public:
    string removeDuplicates(string s, int k) {
        // char, its frequency
        // dummy data added to avoid empty array
        vector<pair<char, int>> v = {{'#', 0}};
        
        for(char ch: s) {
            // if the last character is not equal to current
            if(v.back().first != ch)
                v.push_back({ch, 1});
            else{
                // since the last char matches the curr
                // increase its frequenccy
                v.back().second++;
                
                // remove if frequency becomes k
                if(v.back().second == k)
                    v.pop_back();
            }
        }
        
        string ans;
        
        // append (size_type num, char c)
        // adds the char 'c' 'num' times at the back of string 
        for(auto it: v) ans.append(it.second, it.first);
            
        return ans;
    }
};