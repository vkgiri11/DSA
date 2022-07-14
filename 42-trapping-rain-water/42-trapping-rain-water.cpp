class Solution {
public:
    int trap(vector<int>& height) {
    
        int n = height.size();
        if(n == 0)
            return 0;
        
        //Two Pointer Approach
        int left = 0, right = n-1;
        int ans = 0;
        int left_max = 0, right_max = 0;
        
        while(left < right) {
            if(height[left] <= height[right]) {
                if(height[left] >= left_max)
                    left_max = height[left];
                else
                    ans += left_max - height[left];
                
                left++;
            }
            else {
                if(height[right] >= right_max)
                    right_max = height[right];
                else
                    ans += right_max - height[right];
                
                right--;
            }
        }
        
        return ans;
        /*
        //Prefix sum approach
        int ans = 0;
        //Contains the maxm height of bar so far
        //to the left of ith element self included
        int prefix_arr[n];
        //Contains the maxm height of bar so far
        //to the right of ith element self included
        int suffix_arr[n];
        
        prefix_arr[0] = height[0];
        for(int i = 1; i < n; i++) 
            prefix_arr[i] = max(prefix_arr[i-1], height[i]);
        
        suffix_arr[n-1] = height[n-1];
        for(int i = n-2; i >= 0; i--) 
            suffix_arr[i] = max(suffix_arr[i+1], height[i]);
        
        for(int i = 0; i < n; i++)
            ans += (min(prefix_arr[i], suffix_arr[i]) - height[i]);
            
        return ans;
        */
        
        
        /*
        //Brute force
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            int left_max = 0, right_max = 0;
            
            //Finding max in left
            for(int j = 0; j <= i; j++)
                left_max = max(left_max, height[j]);
            
            //Finding max in right
            for(int j = i; j < n; j++)
                right_max = max(right_max, height[j]);
            
            ans += (min(left_max, right_max) - height[i]);
        }
        
        return ans;
        */
    }
};