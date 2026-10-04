class Solution {
public: 
    int helper(int i , int j , string &s , string &p, vector<vector<int>> &dp){
        if(i < 0 && j < 0) return true ;
        if(i < 0 && j >= 0) return false ;
        if(j < 0 && i >= 0){
            for(int ii = 0 ; ii <= i ; ii++){
                if(p[ii] != '*') return false ;
            }
            return true ;
        }

        if(dp[i][j] != -1) return dp[i][j] ;

        if(p[i] == s[j] || p[i] == '?'){
            return dp[i][j] = helper(i - 1 , j - 1 , s, p, dp);
        }

        if(p[i] == '*'){
            return dp[i][j] = helper(i - 1 ,j , s, p, dp) || helper( i , j -1 , s, p, dp);
        }
        return false ;
    }

    bool isMatch(string s, string p) {
        int n = p.size() ;
        int m = s.size() ;
        vector<vector<int>> dp(n , vector<int>(m, -1));
        return helper(n -1 , m - 1, s, p, dp);
    }
};