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

    bool canPartition(vector<int>& nums) {
    int totalSum = 0;
    int n = nums.size();
    for(int i = 0; i < n; i++){
        totalSum += nums[i];
    }
    if(totalSum % 2 != 0) return false;

    int target = totalSum / 2;                           
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));  

    int res = helper(n - 1, target, nums, dp);
    return res > 0;    
}
};