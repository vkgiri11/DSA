class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;
        int n = potions.size();
        
        sort(potions.begin(), potions.end());
        
        for(auto it: spells) {
            int start = 0, end = n;
            
            // find the index of the smallest elem which satisfies the success
            while(start < end) {
                int mid = start + (end-start)/2;
                
                if((long long)it * potions[mid] >= success) end = mid;
                else start = mid+1;
            }
            ans.push_back(n-start);
        }
        
        return ans;
    }
};