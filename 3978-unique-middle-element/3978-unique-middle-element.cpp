class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int freq = 0;
        int midEl = nums.size() / 2 ;

        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == nums[midEl])freq ++;
        }
        if(freq == 1){
            return true ;
        }
        return false ;
    }
};