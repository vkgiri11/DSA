class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long x = 0, minX = 0, maxX = 0;
        
        for(int it: differences) {
            x += it;
            minX = min(minX, x);
            maxX = max(maxX, x);
        }
        
        return max(0L, (upper-lower) - (maxX-minX) + 1);
    }
};