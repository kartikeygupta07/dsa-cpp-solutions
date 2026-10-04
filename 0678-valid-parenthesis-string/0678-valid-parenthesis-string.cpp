class Solution {
public:
    bool helper(int i, int open, string &s, vector<vector<int>> &dp) {
        if (open < 0) return false;                
        if (open > (int)s.size() - i) return false;  
        if (i == s.size()) return open == 0;

        if (dp[i][open] != -1) return dp[i][open];

        if (s[i] == '(')
            return dp[i][open] = helper(i + 1, open + 1, s, dp);

        if (s[i] == ')')
            return dp[i][open] = helper(i + 1, open - 1, s, dp);

        // '*' as '(' , ')' or empty
        return dp[i][open] = helper(i + 1, open + 1, s, dp)
                          || helper(i + 1, open - 1, s, dp)
                          || helper(i + 1, open, s, dp);
    }

    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return helper(0, 0, s, dp);
    }
};