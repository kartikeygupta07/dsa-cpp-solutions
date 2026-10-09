class Solution {
public:
    int helper(int idx, int buy, vector<int> &prices, int n, vector<vector<int>> &dp) {
        if (idx == n) return 0;

        if (dp[idx][buy] != -1) return dp[idx][buy];

        int profit;
        if (buy) {
            profit = max(-prices[idx] + helper(idx + 1, 0, prices, n, dp),  // buy
                         helper(idx + 1, 1, prices, n, dp));                // skip
        } else {
            profit = max(prices[idx] + helper(idx + 1, 1, prices, n, dp),   // sell
                         helper(idx + 1, 0, prices, n, dp));                // skip
        }

        return dp[idx][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return helper(0, 1, prices, n, dp);
    }
};