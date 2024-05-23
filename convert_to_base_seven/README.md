# README

## Convert to Base 7

### Problem Description

The task is to convert a given integer to its base 7 representation. The base 7 numeral system uses digits from 0 to 6. The solution must handle both positive and negative integers.

### Solution

This solution involves converting an integer from base 10 to base 7. It handles negative numbers, performs the conversion using repeated division and modulo operations, and constructs the base 7 representation as a string.

### Code Explanation

Here is the C++ code to solve the problem:

```cpp
#include <string>
#include <sstream>
#include <algorithm>

class Solution {
public:
    std::string convertToBase7(int num) {
        // Initialize variables to hold negative state and stringstream for conversion
        std::stringstream p_convert;
        bool negative = false;

        // Handle the special case where the number is between 0 and 6 (inclusive)
        if (num < 7 && num >= 0) {
            return std::to_string(num);
        }

        // While the base 10 number is not 0, find the modulo and divide by 7
        while (num != 0) {
            p_convert << abs(num % 7);
            num /= 7;
        }

        // Convert the stringstream to a string and reverse the order
        std::string f_convert = p_convert.str();
        std::reverse(f_convert.begin(), f_convert.end());

        // Check if the original number was negative
        if (num < 0) {
            f_convert.insert(0, 1, '-');
        }

        // Return the final string
        return f_convert;
    }
};
```

### Detailed Explanation

1. **Initialization**:
   - `p_convert`: A stringstream to build the base 7 representation.
   - `negative`: A boolean to track if the input number is negative.

2. **Special Case Handling**:
   - If the number is between 0 and 6 (inclusive), it directly returns the string representation of the number.

3. **Conversion Loop**:
   - The loop runs while `num` is not zero.
   - It calculates the remainder when `num` is divided by 7 and appends this value to the stringstream.
   - The number is then divided by 7 to continue the conversion process.

4. **Reverse the String**:
   - After the loop, the stringstream is converted to a string and reversed to correct the order of digits.

5. **Handling Negative Numbers**:
   - If the original number is negative, a '-' sign is inserted at the beginning of the string.

6. **Return**:
   - The function returns the final base 7 string representation of the number.

### Example Usage

To use this solution, you can create an instance of the `Solution` class and call the `convertToBase7` method with an integer input:

```cpp
#include <iostream>

int main() {
    Solution solution;
    int num = -100;
    std::string result = solution.convertToBase7(num);
    std::cout << "The base 7 representation of " << num << " is: " << result << std::endl;
    return 0;
}
```

### Constraints

- The input integer can be any valid 32-bit signed integer.
- The function must handle both positive and negative inputs correctly.

### Conclusion

This solution efficiently converts a base 10 integer to its base 7 representation by leveraging string manipulation and arithmetic operations. It ensures that the sign of the number is correctly handled and provides a straightforward implementation for the conversion process.
