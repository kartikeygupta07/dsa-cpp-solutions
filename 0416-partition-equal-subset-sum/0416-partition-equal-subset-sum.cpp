class Solution {
public:
    bool helper(int idx , vector<int> &nums , int target, vector<vector<int>> &dp){
        if(target == 0) return true ;
        if(idx == 0) return nums[0] == target;
        if(dp[idx][target] != -1) return dp[idx][target];

        int notTake = helper(idx - 1, nums , target, dp);;
        int take = 0 ;
        if(target >= nums[idx]){
            take = helper(idx - 1, nums , target - nums[idx], dp);
        }

        return  dp[idx][target] = take || notTake ;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size() ;
        int totSum = 0 ;
        for(int i = 0 ; i < n ; i++){
            totSum += nums[i];
        }
        if(totSum % 2 != 0) return false ;
        int target = totSum / 2;
        vector<vector<int>> dp(n , vector<int>(target + 1 , -1));
        return helper(n -1 , nums , target, dp);
    }
};