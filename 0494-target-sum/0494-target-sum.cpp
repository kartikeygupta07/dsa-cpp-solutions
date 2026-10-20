class Solution {
public:
    int helper(int idx , vector<int> &arr, int K, vector<vector<int>> &dp){
        if (idx == 0) {
            if (K == 0 && arr[0] == 0) return 2;   // {} aur {0}
            if (K == 0 || K == arr[0]) return 1;   // {} ya {arr[0]}
            return 0;
        }

        if(dp[idx][K] != -1) return dp[idx][K];

        int notPick = helper(idx - 1, arr , K, dp);
        int pick = 0;
        if(K >= arr[idx]){
            pick = helper(idx - 1 , arr , K - arr[idx], dp);
        }

        return dp[idx][K] = (pick + notPick);
    }
    int countPartitions(int n, int diff, vector<int>& arr) {
        int totSum = 0;
        for(auto it : arr){
            totSum += it;
        }

        if(totSum - diff < 0 || (totSum - diff) % 2 != 0) return false;
        int target =  (totSum - diff) / 2 ;
        vector<vector<int>> dp(n , vector<int>( target + 1, -1));

        return helper(n - 1, arr , target , dp);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return countPartitions(nums.size() , target, nums);
    }
};