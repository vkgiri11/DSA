class Solution {
public:
    string f(int &ind, string str) {
        string ans = "";
        
        int num = 0;
        for( ; ind < str.size(); ind++) {
            char currCh = str[ind];
            
            // if at current index we have a digit
            // store this is in num
            if(isdigit(currCh)) 
                num = num * 10 + currCh - '0';
            
            else if(currCh == '[') {
                // recursively collect the word that is inside [] 
                string currWord = f(++ind, str);
                
                // copy this word num times
                for( ; num > 0; num--) ans += currWord;
            }
            
            else if(currCh == ']') return ans;
            
            // if it is a standalone char, just copy it
            else ans += currCh;      
        }
        
        return ans;
    }
    string decodeString(string s) {
        int initialPos = 0;
        return f(initialPos, s);
    }
};