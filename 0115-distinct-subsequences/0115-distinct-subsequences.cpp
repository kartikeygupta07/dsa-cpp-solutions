class Solution {
public:
    // dp table: dp[i][j] = solve(i, j) ka answer, agar already calculate ho chuka hai
    vector<vector<int>> dp;
    
    int solve(string &s, string &t, int i, int j) {
        if (j == t.size()) {
            return 1;
        }
        if (i == s.size()) {
            return 0;
        }
        
        // Agar ye (i, j) pehle hi solve ho chuka hai, toh seedha wahi answer utha lo
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        
        int ways = 0;
        
        if (s[i] == t[j]) {
            ways = ways + solve(s, t, i + 1, j + 1);
        }
        
        ways = ways + solve(s, t, i + 1, j);
        
        // Answer ko table mein store kar do, taaki agli baar dobara calculate na karna pade
        dp[i][j] = ways;
        
        return ways;
    }
    
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        dp.assign(n + 1, vector<int>(m + 1, -1));  // -1 matlab "abhi tak solve nahi hua"
        return solve(s, t, 0, 0);
    }
};