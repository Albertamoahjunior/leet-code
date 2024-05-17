# Max Profit from Stock Prices

## Description

This repository contains a solution to the problem of finding the maximum profit from stock prices, given an array where each element represents the price of a given stock on a particular day. The goal is to determine the maximum profit that can be made by buying on one day and selling on a later day. If no profit can be made, the solution returns 0.

## Problem Statement

You are given an array `prices` where `prices[i]` is the price of a given stock on the `i`-th day. You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock. 

**Example:**

```
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
```

If no profit can be achieved, the function should return 0.

## Solution

The solution is implemented in C++ in the `Solution` class and the javascript function maxProfit, which contains the method `maxProfit`.

### Method Signature

```cpp
int maxProfit(vector<int>& prices);
```

### Implementation Details

- **Initialization**:
  - The method first checks if the `prices` array is empty. If it is, the function returns 0, as no transactions can be made.
  - Two variables are initialized: `minprice` to store the minimum price observed so far (starting with the first day's price), and `maxProfit` to store the maximum profit observed so far (starting with 0).

- **Iterating through Prices**:
  - The method iterates through the `prices` array starting from the second element.
  - For each price, it checks if the current price is lower than the `minprice`. If it is, `minprice` is updated to the current price.
  - If the current price is higher than `minprice`, it calculates the potential profit by subtracting `minprice` from the current price.
  - If this potential profit is greater than `maxProfit`, `maxProfit` is updated to this new profit.

- **Return Value**:
  - After iterating through all the prices, the method returns the `maxProfit`, which represents the maximum profit achievable.

### Code

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) {
            return 0;
        }

        int minprice = prices[0];
        int maxProfit = 0;

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < minprice) {
                minprice = prices[i];
            } else {
                int profit = prices[i] - minprice;

                if (profit > maxProfit) {
                    maxProfit = profit;
                }
            }
        }

        return maxProfit;
    }
};
```

## Usage

1. **Include the Header**: Ensure you include the necessary header for using `std::vector`.
   
   ```cpp
   #include <vector>
   ```

2. **Create an Instance of Solution**: Instantiate the `Solution` class.

   ```cpp
   Solution solution;
   ```

3. **Prepare the Input**: Prepare the input vector of prices.

   ```cpp
   std::vector<int> prices = {7, 1, 5, 3, 6, 4};
   ```

4. **Call the Method**: Call the `maxProfit` method with the prices vector.

   ```cpp
   int profit = solution.maxProfit(prices);
   ```

5. **Output the Result**: Output the returned profit.

   ```cpp
   std::cout << "Maximum Profit: " << profit << std::endl; // Output: 5
   ```

## Conclusion

This method provides an efficient way to calculate the maximum profit from a series of stock prices with a time complexity of \(O(n)\), making it suitable for large datasets. The approach ensures only a single pass through the prices array, maintaining optimal performance.
