class Solution {
public:
    int helper(int index, int target, vector<int>& nums, vector<vector<int>> &dp){
        if(target == 0) return 0;

        if(index == 0){
            if(nums[0] == target) return 1;
            else return -1e9;
        }

        if(dp[index][target] != -1) return dp[index][target];

        int notPick = helper(index - 1, target, nums , dp);

        int pick = -1e9;
        if(nums[index] <= target){
            pick = 1 + helper(index - 1, target - nums[index], nums , dp);
        }

        return dp[index][target] = max(pick, notPick);
    }

    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        int res = helper(n - 1, target, nums, dp);

        if(res < 0) return -1;
        return res;
    }
};