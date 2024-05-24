# Final Prices with Special Discount

## Description

This repository contains a C++ solution for calculating the final prices of items with a special discount applied. Each item's price may be reduced by the price of the first subsequent item that is less than or equal to its price. If no such item exists, the price remains unchanged.

## Problem Statement

Given an array of prices, for each price, if a subsequent price is found that is less than or equal to the current price, subtract the subsequent price from the current price. Return a new array of the final prices.

## Solution

The solution is implemented in the `Solution` class, which contains the method `finalPrices`. This method takes a vector of integers representing prices and returns a new vector of integers representing the final prices after discounts have been applied.

### Method: `finalPrices`

```cpp
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> final_price_list;

        // Loop through vector to find which prices qualify for discounts and calculate the discounted price
        for (int i = 0; i < size(prices); i++) {
            bool nodiscount = true;
            for (int j = i + 1; j < size(prices); j++) {
                if (prices[j] <= prices[i]) {
                    final_price_list.push_back(prices[i] - prices[j]);
                    nodiscount = false;
                    break;
                }
            }

            // If no discount is found, keep the original price
            if (nodiscount) {
                final_price_list.push_back(prices[i]);
            }
        }

        // Return the final vector
        return final_price_list;
    }
};
```

## Usage

1. **Include the header files**:
   Ensure that the necessary header files are included in your main file to run the code.

2. **Create an instance of the `Solution` class**:
   ```cpp
   Solution solution;
   ```

3. **Call the `finalPrices` method**:
   Pass a vector of prices to the `finalPrices` method and receive the final discounted prices.
   ```cpp
   vector<int> prices = {8, 4, 6, 2, 3};
   vector<int> final_prices = solution.finalPrices(prices);
   ```

4. **Output the result**:
   Print or use the resulting vector as needed.
   ```cpp
   for (int price : final_prices) {
       cout << price << " ";
   }
   ```

## Example

Given the input:
```
prices = [8, 4, 6, 2, 3]
```

The output will be:
```
final_prices = [4, 2, 4, 2, 3]
```

