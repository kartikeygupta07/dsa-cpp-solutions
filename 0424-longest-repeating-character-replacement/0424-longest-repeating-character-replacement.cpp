class Solution {
public:
    int characterReplacement(string s, int k) {
        int r = 0 ;
        int l = 0 ;
        int maxFreq = 0 ;
        int maxLen = 0 ;
        int n = s.size() ;
        unordered_map<char,int> freq ;

        for(r = 0 ; r < n ; r++){
            freq[s[r]]++;
            maxFreq = max(maxFreq , freq[s[r]]);

            if((r - l + 1) - maxFreq > k){
                freq[s[l]] --;
                l++;
            }
            else{
                maxLen = max(maxLen , r - l + 1);
            }
        }
        return maxLen ;
    }
};