class Solution {
public:
    int minimum(vector<int> &nums){
        int mini = INT_MAX;
        for(int i = 0 ; i < nums.size() ; i++){
            mini = min(mini , nums[i]);
        }
        return mini ;
    }
    int minMoves(vector<int>& nums) {
        int min = minimum(nums);
        int moves = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            moves += nums[i] - min;
        }
        return moves ;
    }
};