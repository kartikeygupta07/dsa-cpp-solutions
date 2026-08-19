class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size() ;
        unordered_map<int , int> freq ;
        for(int i = 0 ; i < nums.size() ; i++){
            freq[nums[i]]++;
        }
        
        if(k == n ){
            int largestNum = INT_MIN;
            for(int i = 0 ; i < nums.size() ; i++){
                largestNum = max(largestNum , nums[i]);
            }
            return largestNum ;
        }

        if(k == 1){
            int ans = -1;
            for(auto entry : freq){
                int val = entry.first;
                int count = entry.second;

                if(count == 1){
                    ans = max(ans , val);
                }
            }
            return ans ;
        }

        int ans = -1;

        if(freq[nums[0]] == 1){
            ans  = max(ans , nums[0]);
        }

        if(freq[nums[n - 1]] == 1){
            ans  = max(ans , nums[n - 1]);
        }

        return ans ;

    }
};