class Solution {
public:
    int helper(int i , int j , string &s, string &revStr , vector<vector<int>> &dp){
        if(i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int ans = 0 ;
        if(s[i] == revStr[j]){
            ans = 1 + helper(i - 1, j - 1, s, revStr, dp);
        }
        else{
            ans = max(helper(i - 1, j , s, revStr, dp), helper(i , j -1 , s, revStr, dp));
        }

        return dp[i][j] = ans ;
    }
    int minInsertions(string s) {
        string revStr = s;
        reverse(revStr.begin(), revStr.end());
        int n = s.size();
        int m = revStr.size();
        vector<vector<int>> dp(n , vector<int>(m , -1));
        int x = helper(n - 1, m - 1, s, revStr, dp);
        return n - x ;
    }
};