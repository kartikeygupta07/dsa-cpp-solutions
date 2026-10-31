class Solution {
public:
    int helper(int idx , vector<int> &arr , int k , int n, vector<int> &dp){
        if(idx == n) return 0 ;
        if(dp[idx] != -1) return dp[idx] ;

        int len = 0 ;
        int maxElement = INT_MIN;
        int maxSum = INT_MIN ;
        for(int j = idx ; j < min(n , idx + k) ; j++){
            len ++;
            maxElement = max(maxElement, arr[j]);
            int sum = (len * maxElement) + helper(j + 1, arr, k , n, dp);
            if(sum > maxSum){
                maxSum = sum;
            }
        }
        return dp[idx] = maxSum ;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n , -1);
        return helper(0, arr , k , n , dp);
    }
};