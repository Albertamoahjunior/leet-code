Sure, here's a README file for the given code:

---

# Find Numbers with Even Number of Digits

## Description

This repository contains a solution to the problem of finding numbers with an even number of digits in a given array of integers. The solution is implemented in C++.

## Problem Statement

Given an array of integers, we need to find how many numbers contain an even number of digits.

### Example

```cpp
Input: [12, 345, 2, 6, 7896]
Output: 2
Explanation: 
12 contains 2 digits (even).
345 contains 3 digits (odd).
2 contains 1 digit (odd).
6 contains 1 digit (odd).
7896 contains 4 digits (even).
Therefore, there are 2 numbers with an even number of digits.
```

## Solution

The solution involves iterating through the array, converting each number to a string, checking the length of the string, and counting how many numbers have an even length.

### Code

```cpp
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int even_numbers = 0;

        for(int num : nums){
            if(size(to_string(num)) % 2 == 0){
                even_numbers++;
            }
        }

        return even_numbers;
    }
};
```

### Explanation

1. **Initialization**:
   - We initialize a variable `even_numbers` to keep track of the count of numbers with an even number of digits.

2. **Iteration**:
   - We iterate through each number in the input vector `nums`.

3. **Conversion and Check**:
   - For each number, we convert it to a string using `to_string()`.
   - We check the size of the resulting string using `size()`.
   - If the size is even, we increment the `even_numbers` counter.

4. **Result**:
   - Finally, we return the count of numbers with an even number of digits.

## Requirements

- C++11 or later

## How to Run

1. Clone the repository.
2. Ensure you have a C++ compiler installed (e.g., `g++`).
3. Create a main function to test the `findNumbers` method or use a testing framework.

### Sample Main Function

```cpp
#include <iostream>
#include <vector>
#include "Solution.h"

int main() {
    Solution solution;
    std::vector<int> nums = {12, 345, 2, 6, 7896};
    int result = solution.findNumbers(nums);
    std::cout << "Number of integers with even number of digits: " << result << std::endl;
    return 0;
}
```
