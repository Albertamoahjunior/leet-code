#include <algorithm>

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int minprice = prices[0];
        int maxProfit = 0;

        for(int price : prices){
            minprice = std::min(price, minprice);
            maxProfit = std::max(maxProfit, price- minprice);
        }

        return maxProfit;
    }
};
