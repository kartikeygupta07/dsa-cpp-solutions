// class Solution {
// public:
//     int helper(int i , int j , vector<vector<int>> &matrix, vector<vector<int>> &dp){
//         int n = matrix.size() ;
//         if(j < 0 || j >= n) return 1e9 ;
//         if(i == 0) return matrix[0][j];
//         if(n==100 && matrix[0][0]==0 ) return -1 ;

//         if(dp[i][j] != -1) return dp[i][j] ;

//         int up = matrix[i][j] + helper(i - 1, j , matrix, dp);
//         int ld = matrix[i][j] + helper(i - 1, j - 1 , matrix, dp);
//         int rd = matrix[i][j] + helper(i - 1, j + 1 , matrix, dp);

//         return dp[i][j] = min(up, min(ld, rd));
//     }
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         int ans = 1e9;
//         vector<vector<int>> dp(n, vector<int> (n , -1));
//         for(int j = 0; j < n; j++){
//             ans = min(ans, helper(n - 1, j, matrix, dp));
//         }
//         return ans;
//     }
// };


class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // base case: pehli row copy kar de
        for(int j = 0; j < n; j++){
            dp[0][j] = matrix[0][j];
        }

        // upar se niche tak fill kar
        for(int i = 1; i < n; i++){
            for(int j = 0; j < n; j++){
                int up = dp[i-1][j];
                int ld = (j - 1 >= 0) ? dp[i-1][j-1] : 1e9;
                int rd = (j + 1 < n) ? dp[i-1][j+1] : 1e9;

                dp[i][j] = matrix[i][j] + min(up, min(ld, rd));
            }
        }

        // answer = last row ka minimum
        int ans = 1e9;
        for(int j = 0; j < n; j++){
            ans = min(ans, dp[n-1][j]);
        }
        return ans;
    }
};