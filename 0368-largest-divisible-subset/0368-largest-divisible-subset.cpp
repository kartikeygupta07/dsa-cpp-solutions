//This is the answer i know :

// class Solution {
// public:
//     int helper(int curr , int prev , vector<int> &nums, int n, vector<vector<int>> &dp){
//         if(curr == n) return 0;
//         if(dp[curr][prev + 1] != -1) return dp[curr][prev + 1] ;

//         int notTake = 0 + helper(curr + 1, prev , nums, n, dp);
//         int take = 0;
//         if(prev == -1 || nums[curr] % nums[prev] == 0){
//             take = 1 + helper(curr + 1 , curr, nums, n, dp);
//         }

//         return dp[curr][prev + 1] = max(take , notTake);
//     }
//     int largestDivisibleSubset(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         int n = nums.size();
//         vector<vector<int>> dp(n, vector<int>(n +1 , -1));
//         return helper(0 , - 1, nums ,n, dp);
//     }
// };

// This is what i copied :

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<int> dp(n, 1);        // dp[i] = size of the largest valid subset ending at nums[i]
        vector<int> parent(n);       // parent[i] = index before i in that subset
        for (int i = 0; i < n; i++) parent[i] = i;   // initially no parent

        int best = 0;                // index where the best subset ends
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
            if (dp[i] > dp[best]) best = i;
        }

        vector<int> ans;
        for (int i = best; ; i = parent[i]) {
            ans.push_back(nums[i]);
            if (parent[i] == i) break;   // reached the start
        }
        return ans;
    }
};