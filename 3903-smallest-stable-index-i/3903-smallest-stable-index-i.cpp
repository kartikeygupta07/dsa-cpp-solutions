class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            // Bayi taraf ka max nikalo: index 0 se i tak
            int leftMax = INT_MIN;
            for (int j = 0; j <= i; j++) {
                leftMax = max(leftMax, nums[j]);
            }
            
            // Dayi taraf ka min nikalo: index i se end tak
            int rightMin = INT_MAX;
            for (int j = i; j < n; j++) {
                rightMin = min(rightMin, nums[j]);
            }
            
            // Check karo stable hai kya
            if (leftMax - rightMin <= k) {
                return i;
            }
        }
        
        return -1;
    }
};