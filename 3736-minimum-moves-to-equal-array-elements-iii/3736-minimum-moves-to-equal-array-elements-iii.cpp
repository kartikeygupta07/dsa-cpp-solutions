class Solution {
public:
    int maximum(vector<int> &nums){
        int maxi = INT_MIN;
        for(int i = 0 ; i < nums.size() ; i++){
            maxi = max(maxi , nums[i]);
        }
        return maxi ;
    }
    int minMoves(vector<int>& nums) {
        int moves = 0;
        int maxi = maximum(nums);
        for(int i = 0 ; i < nums.size() ; i++){
            moves += maxi - nums[i];
        }
        return moves;
    }
};