class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;

        while(n != 1){
            if(seen.count(n)) return false;
            seen.insert(n);

            int ans = 0;
            while(n > 0){
                int x = n % 10 ;
                ans += x*x ;
                n = n / 10 ;
            }
            n = ans ;
        }
        return true ;
    }
};