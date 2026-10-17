class Solution {
public:
    bool isPal(int left , int right , string &s){
        while(left < right){
            if(s[left] != s[right]){
                return false ;
            }
            left ++;
            right --;
        }
        return true ;
    }
    bool validPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        while(left < right){
            if(s[left] == s[right]){
                left ++ ;
                right --;
            }
            else{
                return isPal(left + 1, right , s) || isPal(left, right - 1, s );
            }
        }
        return true ;
    }
};