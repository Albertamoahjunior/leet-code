# README

## Max Power of a String

### Problem Description

Given a string `s`, the task is to find the maximum power of the string. The power of a string is defined as the maximum length of a non-empty substring that contains only one unique character. For example, the power of the string `"abbcccddddeee"` is `4` because the substring `"dddd"` has the maximum length of four consecutive identical characters.

### Solution

This solution iterates through the string `s` to calculate the maximum length of contiguous characters. It maintains a counter for the current sequence of identical characters and updates the maximum power whenever a new character is encountered.

### Code Explanation

Here is the C++ code to solve the problem:

```cpp
#include <string>
#include <algorithm>

class Solution {
public:
    int maxPower(std::string s) {
        // Initialize variables to keep track of the maximum power and current sequence length.
        int power = 0;
        int curr = 0; 
        
        // Loop through the string starting from the second character.
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i-1]) {
                // If the current character is the same as the previous one, increment the current sequence length.
                curr += 1;
            } else {
                // If a different character is found, update the maximum power and reset the current sequence length.
                power = std::max(curr, power);
                curr = 0;
            }
        }

        // After the loop, ensure the last sequence is considered in the maximum power.
        power = std::max(curr, power);
         
        // Return the maximum power plus one to account for the first character of the sequence.
        return power + 1;
    }
};
```

### Detailed Explanation

1. **Initialization**:
   - `power` is initialized to 0 to store the maximum length of contiguous characters.
   - `curr` is initialized to 0 to keep track of the current sequence length.

2. **Loop Through the String**:
   - Start the loop from the second character (index 1) and compare each character with the previous one.
   - If the current character is the same as the previous one (`s[i] == s[i-1]`), increment `curr`.
   - If the current character is different, update `power` with the maximum of `curr` and `power`, and reset `curr` to 0.

3. **Final Comparison**:
   - After exiting the loop, compare `curr` and `power` one last time to ensure the last sequence is considered.
   - Add 1 to the result to account for the first character of the sequence.

4. **Return**:
   - Return the maximum power plus one.

### Example Usage

To use this solution, you can create an instance of the `Solution` class and call the `maxPower` method with a string input:

```cpp
#include <iostream>

int main() {
    Solution solution;
    std::string s = "abbcccddddeee";
    int result = solution.maxPower(s);
    std::cout << "The maximum power of the string is: " << result << std::endl;
    return 0;
}
```

### Constraints

- `1 <= s.length <= 500`
- `s` consists of only lowercase English letters.

### Conclusion

This solution efficiently computes the maximum power of a string by iterating through it once and using a few integer variables for tracking the current sequence length and the maximum power. It ensures that all contiguous sequences are correctly considered and handled.
