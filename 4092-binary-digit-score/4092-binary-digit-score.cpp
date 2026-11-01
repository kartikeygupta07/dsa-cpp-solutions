class Solution {
public:
    int countBits(int n){
        int count = 0;
        while(n > 0){
            count = count + (n & 1);
            n = n >> 1;
        }
        return count ;
    }
    int calculateScore(int a, int b) {
        int s1 = countBits(a);
        int s2 = countBits(b);

        if(s1 >= s2) return s1 * s2;
        return s2 / s1 ;
    }
};