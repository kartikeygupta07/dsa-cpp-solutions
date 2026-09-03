class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minOdd = INT_MAX;
        int minEven = INT_MAX;
        
        // Step 1: sabse chhota odd aur sabse chhota even dhoondo
        for (int x : nums1) {
            if (x % 2 == 0) {
                minEven = min(minEven, x);
            } else {
                minOdd = min(minOdd, x);
            }
        }
        
        // Step 2: agar sirf ek hi parity hai, already uniform hai
        if (minOdd == INT_MAX || minEven == INT_MAX) {
            return true;
        }
        
        // Step 3: warna check karo minOdd chhota hai ya nahi
        return minOdd < minEven;
    }
};