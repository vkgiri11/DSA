class Solution {
public:
    // Variation of kadane
    int maxProduct(vector<int>& nums) {
        int maxAns = INT_MIN;

        // max positive product ending at the current position
        int maxEndingHere = 1;
        // min negative product ending at the current position
        int minEndingHere = 1;
        
        /* Traverse through the array.
        the maximum product subarray ending at an index
        will be the maximum of the element itself,
        the product of element and max product ending previously
        and the min product ending previously. */
        for(auto num : nums) {
            int prod1 = num * maxEndingHere;
            int prod2 = num * minEndingHere;
            
            maxEndingHere = max(num, max(prod1, prod2));
            minEndingHere = min(num, min(prod1, prod2));
            
            maxAns = max(maxAns, maxEndingHere);
        }
        
        return maxAns;
    }
};