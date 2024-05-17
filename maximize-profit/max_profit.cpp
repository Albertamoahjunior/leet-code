class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(size(prices) == 0){
            return 0;
        }

        int minprice = prices[0];
        int maxProfit = 0;

        for(int i = 1; i < size(prices); i++){
            if(prices[i] < minprice){
                minprice = prices[i];
            }else{
                int profit = prices[i] - minprice;

                if(profit > maxProfit){
                    maxProfit = profit;
                }
            }
        }

        return maxProfit;
    }
};
