class Solution {
public:
    int helper(int curr , int prev,  vector<int> &nums, int n, vector<vector<int>> &dp){
        if(curr == n){
            return 0;
        }

        if(dp[curr][prev +1] != -1) return dp[curr][prev + 1];

        int notTake = 0 + helper(curr + 1 , prev , nums, n, dp);
        int take = 0;
        if(prev == -1 || nums[curr] > nums[prev]){
            take = 1 + helper(curr + 1, curr , nums, n, dp);
        }

        return dp[curr][prev +1] = max(take , notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n , vector<int>(n + 1, -1));
        return helper(0 ,-1 , nums ,n, dp);
    }
};