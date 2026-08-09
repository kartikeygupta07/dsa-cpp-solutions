class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.rbegin(), prices.rend());
        sort(discounts.rbegin(), discounts.rend());

        int n = prices.size();
        int m = discounts.size();
        
        double total = 0;
        int pairs = min(n, m);

        for(int i = 0 ; i < pairs ; i++){
            int price = prices[i];
            int discount = discounts[i];

            double totalDiscount = (price * (100 - discount)) / 100.0;
            total += totalDiscount;
        }

        for(int i = pairs ; i < n ; i++){
            total += prices[i];
        }
        return total ;
    }
};