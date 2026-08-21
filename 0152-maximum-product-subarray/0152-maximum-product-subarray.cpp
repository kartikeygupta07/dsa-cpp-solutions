class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd = nums[0];
        int currMax = nums[0];
        int currMin = nums[0];

        for(int i = 1 ; i < nums.size() ; i++){
            int option1 = nums[i];
            int option2 = currMax * nums[i];
            int option3 = currMin * nums[i];

            int newMax = max({option1 , option2 , option3});
            int newMin = min({option1 , option2 , option3});

            currMax = newMax ; 
            currMin = newMin ;

            maxProd = max(maxProd , currMax);
        }  
        return maxProd ; 
    }
};