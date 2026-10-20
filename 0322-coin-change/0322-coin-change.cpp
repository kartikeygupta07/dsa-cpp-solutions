class Solution {
public:
    int helper(int idx , vector<int> &coins , int amount, vector<vector<int>> &dp){
        if(amount == 0) return 0 ;
        if (idx == 0) {
            if (amount % coins[0] == 0) return amount / coins[0];
            return 1e9;
        }

        if(dp[idx][amount] != -1) return dp[idx][amount];

        int notPick = 0 + helper(idx - 1, coins , amount, dp);
        int pick = 1e9 ;
        if(amount >= coins[idx]){
            pick = 1 + helper(idx , coins , amount - coins[idx], dp);
        }

        return dp[idx][amount] = min(pick , notPick) ;
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n , vector<int>(amount + 1, -1));
        int res = helper(n -1 , coins , amount, dp);
        if(res >= 1e9){
            return -1;
        }
        return res ;
    }
};