class Solution {
public:
    int GCD(int a , int b){
        if(b == 0){
            return a ;
        }

        return GCD(b, a%b);
    }

    int maxi(vector<int> &nums){
        int maxi = INT_MIN;

        for(int x : nums){
            maxi = max(maxi , x);
        }

        return maxi;
    }

    int mini(vector<int> &nums){
        int mini = INT_MAX;

        for(int x : nums){
            mini = min(mini , x);
        }

        return mini;
    }
    int findGCD(vector<int>& nums) {
        int mx = maxi(nums);
        int mn = mini(nums);

        return GCD(mx, mn);
    }
};