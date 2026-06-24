class Solution {
public:
    int helper(vector<int>& nums, int k) {
        int l = 0;
        int r = 0 ;
        int n = nums.size() ;
        int sum = 0;
        int count = 0 ;

        while(r < n ){
            sum += (nums[r] % 2);

            while(sum > k){
                sum = sum - (nums[l] % 2);
                l++;
            }
            count = count + (r - l + 1);
            r = r + 1;
        }
        return count ;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return helper(nums, k) - helper(nums, k - 1 );
    }
};