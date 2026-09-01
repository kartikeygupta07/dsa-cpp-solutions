class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> present ;

        for(int i = 0 ; i < nums.size() ;i++){
            present.insert(nums[i]);
        }

        int i = 1 ;
        while(true){
            int multiple = k * i ;

            int count = present.count(multiple);
            if(count == 0){
                return multiple ;
            }

            i++;
        }
    }
};