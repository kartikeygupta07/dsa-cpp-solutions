class Solution {
public:
    bool isPalindrome(string &s){
        int l = 0, r = s.size() - 1;
        while(l < r){
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    int helper(int i , string &s, int n, vector<int> &dp){
        if(i == n) return 0 ;
        if(dp[i] != -1) return dp[i] ;

        string temp = "";
        int minCount = INT_MAX;
        for(int j = i ; j < n ; j++){
            temp += s[j];

            if(isPalindrome(temp)){
                int count = 1 + helper(j + 1 , s, n, dp) ;
                if(count < minCount){
                    minCount = count ;
                }
            }
        }
        return dp[i] = minCount ;
    }
    int minCut(string s) {
        int n = s.size() ;
        vector<int>dp(n , -1);
        return helper(0 , s , n, dp) - 1;
    }
};