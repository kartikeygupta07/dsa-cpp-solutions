class Solution {
public:
    int helper(int index, int target, vector<int> &squares, vector<vector<int>> &dp){
        if(index == 0){
            return target ;
        }

        if(dp[index][target] != -1) return dp[index][target] ;

        int notPick = helper(index - 1, target, squares, dp);
        int pick = 1e9 ;
        if(squares[index] <= target){
            pick = 1 + helper(index, target - squares[index], squares, dp);
        }

        return dp[index][target] = min(pick , notPick);
    }
    int numSquares(int n) {
        vector<int> squares ;
        for(int i = 1 ; i * i <= n ; i++){
            squares.push_back(i * i);
        }

        int m = squares.size() ;
        vector<vector<int>> dp(m, vector<int>(n + 1, -1));
        return helper(m - 1, n, squares, dp);
    }
};