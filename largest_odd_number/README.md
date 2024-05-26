# Largest Odd Number in a String

## Overview
This repository contains a C++ solution for finding the largest odd number that can be obtained by trimming a given numeric string. The code is designed to iterate through the string, identify the last occurrence of an odd digit, and return the largest odd number as a substring.

## Problem Statement
Given a string `num` representing a large integer, the goal is to find the largest odd number that can be formed by trimming some digits from the right. If no odd number exists, an empty string should be returned.

## Code Explanation

### Function Definition

```cpp
class Solution {
public:
    string largestOddNumber(string num) {
        // Initialize variables to track the position of the last odd number and whether an odd number exists
        int odd_pos = 0;
        bool is_odd = false;

        // Loop through the string to find the last occurrence of an odd digit
        for(int i = 0; i < size(num); i++) {
            if(int(num[i] - '0') % 2 != 0) {
                odd_pos = i;
                is_odd = true;
            }
        }

        // If the last odd number is at the end of the string, return the whole string
        if(odd_pos == size(num) - 1 && is_odd) {
            return num;
        }

        // If an odd number exists, adjust the position for substring extraction
        is_odd ? odd_pos += 1 : odd_pos += 0;

        // Return the largest odd number as a substring
        return num.substr(0, odd_pos);
    }
};
```

### Explanation

1. **Initialization**:
   - `odd_pos`: Tracks the position of the last odd digit found in the string.
   - `is_odd`: A boolean flag to indicate if any odd digit is found.

2. **Loop Through String**:
   - The code iterates through each character of the string.
   - If the character (converted to an integer) is odd, the position `odd_pos` is updated, and `is_odd` is set to true.

3. **Check Position of Last Odd Number**:
   - If the last odd number is at the end of the string and an odd number exists, the entire string is returned.

4. **Substring Extraction**:
   - If an odd digit is found, `odd_pos` is incremented by one to include the digit in the final substring.
   - The substring from the beginning of the string to the position `odd_pos` is returned as the largest odd number.

## Usage
To use this function, create an instance of the `Solution` class and call the `largestOddNumber` method with the numeric string as an argument:

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    Solution sol;
    string num = "12345678";
    cout << sol.largestOddNumber(num) << endl; // Output: "1234567"
    return 0;
}
```

## Constraints
- The input string consists only of digits and is non-empty.
- The input string length is between 1 and 10^5.

## Conclusion
This solution efficiently finds the largest odd number by trimming the input string. It ensures minimal computational overhead by iterating through the string only once and performs necessary checks to identify and extract the largest odd number.
