class Solution {
public:
    int minimum(vector<int> &nums){
        int mini = INT_MAX ;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i]!= 0){
                mini = min(mini , nums[i]);
            }
        }
        return mini ;
    }

    bool allZero(vector<int> &nums){
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] != 0){
                return false ;
            }
        }
        return true ;
    }

    int minimumOperations(vector<int>& nums) {
        int operations = 0 ;
        while(!allZero(nums)){
            int minVal = minimum(nums);

            for(int j = 0 ; j < nums.size() ; j++){
                if(nums[j]!= 0){
                    nums[j] -= minVal ;
                }
            }
            operations ++ ;
        }
        return operations ;
    }
};