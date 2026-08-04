class Solution {
public:
    int maximum(vector<int>& nums){
        int maxi = INT_MIN ;
        for(int i = 0 ; i < nums.size() ; i++){
            maxi = max(maxi , nums[i]);
        }
        return maxi ;
    }

    int minimum(vector<int>& nums){
        int mini = INT_MAX;
        for(int i = 0 ; i < nums.size() ; i++){
            mini = min(mini , nums[i]);
        }
        return mini ;
    }
    vector<int> findMissingElements(vector<int>& nums) {
        int maxi = maximum(nums);
        int mini = minimum(nums);

        unordered_set<int> present(nums.begin() , nums.end()) ;
        vector<int> ans ;

        for(int i = mini ; i < maxi ; i++){
            if (present.find(i) == present.end()){
                ans.push_back(i);
            }
        }
        return ans ;
    }
};