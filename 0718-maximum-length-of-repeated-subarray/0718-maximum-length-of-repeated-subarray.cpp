class Solution {
public:
    int helper(int index1 , int index2 , vector<int> &nums1, vector<int> &nums2 , int &ans , vector<vector<int>> &dp){
        if(index1 < 0 || index2 < 0){
            return 0;
        }

        if(dp[index1][index2] != -1) return dp[index1][index2] ;

        int match = 0;
        if(nums1[index1] == nums2[index2]){
            match = 1 + helper(index1 -1 , index2 -1 , nums1 , nums2, ans , dp);
            ans = max(ans , match);
        }

        int a = helper(index1 -1, index2 , nums1 , nums2 , ans , dp);
        int b = helper(index1, index2 -1 , nums1 , nums2 , ans , dp);
        return dp[index1][index2] = match ;

    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() ;
        int m = nums2.size() ;
        int ans = 0 ;
        vector<vector<int>> dp(n , vector<int>(m , -1));
        helper(n -1 , m-1, nums1 , nums2 ,ans , dp);
        return ans;
    }
};