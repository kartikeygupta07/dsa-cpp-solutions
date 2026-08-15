class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int totalXOR = 0 ;
        bool hasNonZero = false;
        for(int x : nums){
            totalXOR ^= x ;
            if(x != 0){
                hasNonZero = true ;
            }
        }
        if(hasNonZero == false) return 0;
        if(totalXOR != 0){
            return nums.size();
        }
        return nums.size() -1 ;
    }
};