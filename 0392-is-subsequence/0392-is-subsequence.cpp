class Solution {
public:
    int helper(int i, int j , string &s , string &t,vector<vector<int>> &dp){
        if(j < 0) return 1;
        if(i < 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(t[i] == s[j]){
            return dp[i][j] = helper(i - 1 , j - 1, s, t, dp);
        }

        return dp[i][j] = helper(i - 1, j, s, t, dp);
    }
    bool isSubsequence(string s, string t) {
        int n = t.size();
        int m = s.size();
        vector<vector<int>> dp(n, vector<int>(m , -1));
        return helper(n - 1, m - 1, s, t, dp);
    }
};