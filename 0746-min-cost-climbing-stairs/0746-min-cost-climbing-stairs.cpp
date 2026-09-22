class Solution {
public:
    int helper(vector<int> &cost, int index , vector<int> &dp){
        if(index == 0){
            return cost[0] ;
        }

        if(index == 1){
            return cost[1] ;
        }

        if(dp[index] != -1) return dp[index];

        int left = helper(cost , index -1 , dp) + cost[index];
        int right = INT_MAX ;
        if(index > 1){
            right = helper(cost , index -2 , dp) + cost[index];
        }

        return dp[index] = min(left , right);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size() ;
        vector<int> dp(n+1 , -1);
        return min(helper(cost, n - 1, dp), helper(cost, n - 2, dp));
    }
};