class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int mini = INT_MAX;
        for(int i = 0 ; i < nums.size() ; i = i + 2){
            int mul = 1;
            int temp = nums[i+ 1];
            while(temp > 0){
                mul = mul * 10 ;
                temp = temp / 10;
            }
            int x = nums[i] * mul + nums[i + 1];
            if(x < mini){
                mini = x;
            }
        }
        return mini ;
    }
};