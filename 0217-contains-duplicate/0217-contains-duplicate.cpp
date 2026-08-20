class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int , int> mp ;

        for(int i = 0 ; i < nums.size() ; i++){
            mp[nums[i]]++ ;
        }

        for(auto f : mp){
            int count = f.second ;

            if(count >= 2){
                return true ;
            }
        }
        return false ;
    }
};