class Solution {
public:
    int mini(vector<int>& nums){
        int minIdx = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < nums[minIdx]){
                minIdx = i;
            }
        }
        return minIdx; 
    }

    int maxi(vector<int>& nums){
        int maxIdx = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > nums[maxIdx]){
                maxIdx = i;
            }
        }
        return maxIdx;   
    }

    int minimumDeletions(vector<int>& nums) {
        int n = nums.size() ;

        int maxIdx = maxi(nums) ;
        int minIdx = mini(nums) ;

        int hi = max(maxIdx, minIdx);
        int lo = min(maxIdx, minIdx);

        int option1 = hi + 1;

        int option2 = n - lo ;

        int option3 = (lo + 1) + (n - hi);

        return min({option1, option2, option3});
    }
};