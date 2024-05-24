class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int>final_price_list;

        //loop through vector to find which prices qualify for discounts and calculate the discounted price
        for(int i = 0; i<size(prices); i++){
            bool nodiscount = true;
            for(int j = 0; j<size(prices); j++){
                if(prices[j] <= prices[i] && j > i){
                    final_price_list.push_back(prices[i] - prices[j]);
                    nodiscount = false;
                    break;
                }
            }

            //check if they qualify for discount
            if(nodiscount){
                final_price_list.push_back(prices[i]);
            }
        }

        //return the final vector
        return final_price_list;
    }
};
