class Solution {
public:

    int helper(int index , vector<int> &nums, vector<int> &dp){
        if(index == 0) return nums[index];
        if(index < 0) return 0 ;

        if(dp[index] != -1) return dp[index];

        int pick = nums[index] + helper(index - 2 , nums , dp);
        int notPick = 0 + helper(index - 1 , nums, dp);

        return dp[index] = max(pick, notPick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return nums[0];

        vector<int> temp1, temp2 ;
        for(int i = 0 ; i < n ; i++){
            if(i != 0) temp1.push_back(nums[i]);
            if(i != n-1) temp2.push_back(nums[i]);
        }
        vector<int> dp1(temp1.size(), -1);  
        vector<int> dp2(temp2.size(), -1);   
        
        int result1 = helper(temp1.size() - 1, temp1, dp1);
        int result2 = helper(temp2.size() - 1, temp2, dp2);
        
        return max(result1, result2);
    }
};