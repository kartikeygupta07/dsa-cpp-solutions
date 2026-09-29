class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int totalSum = 0 ;
        for(int x : nums){
            totalSum += x;
        }

        if(totalSum % 2 == 0) return nums.size() - 1;
        return 0;
    }
};