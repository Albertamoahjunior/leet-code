/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {

    //Return 0 if the there are no prices to even begin with
    if (prices.length === 0) return 0;

    //initialize minimum and maximum prices; set minimum price to the first index
    //logically should be least price if want profit
    //set maxprofit to 0 so we can always update if we find higher profit
    let minPrice = prices[0];
    let maxProfit = 0;

   /*
   loop through the list beginning from the index after the first index.
   First assumption is that the first index by hook or crook should be the least of the list if we want to make 
   profit at all. The current minimum price and the current price in the price list are compared and the least is 
   is put in the minimum price variable. If the current price is higher, the minimum price is subtracted from the
   current price the profit is compared with the max profit and the maximum is used to update the maxProfit variable
   */
   
    for (let i = 1; i < prices.length; i++) {
        if (prices[i] < minPrice) {
            minPrice = prices[i];
        } else {
            let profit = prices[i] - minPrice;
            maxProfit = Math.max(profit, maxProfit)
        }
    }


    //return the max profit arrived after the caculation
    return maxProfit;
}
