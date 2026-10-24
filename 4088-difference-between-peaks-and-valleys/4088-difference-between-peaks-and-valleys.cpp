class Solution {
public:
    int peakValleyDifference(vector<int>& nums) {
        int n = nums.size();
        int peakValues = 0;
        int valleys = 0;
        for(int i = 1 ; i < n - 1 ; i++){
            if(nums[i] > nums[i - 1] && nums[i] > nums[i + 1]){
                peakValues += nums[i] ;
            }
            else if(nums[i] < nums[i - 1] && nums[i] < nums[i + 1]){
                valleys += nums[i] ;
            }
        }
        return peakValues - valleys ;
    }
};