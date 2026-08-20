class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1;
        vector<int> arr2;

        arr1.push_back(nums[0]);   // arr1 shuru hota hai nums[0] se
        arr2.push_back(nums[1]);   // arr2 shuru hota hai nums[1] se

        for (int i = 2; i < nums.size(); i++) {
            if (arr1.back() > arr2.back()) {   // last elements compare karo
                arr1.push_back(nums[i]);
            } else {
                arr2.push_back(nums[i]);
            }
        }

        // dono vectors ko jod do (concatenate)
        for(int i=0;i<arr2.size();i++){
            arr1.push_back(arr2[i]);
        }
        return arr1;
    }
};