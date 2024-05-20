# Hamming Weight Calculation

This repository contains a C++ class named `Solution` which includes a method for calculating the Hamming Weight of an integer. The Hamming Weight of a number is the number of `1`s in its binary representation.

## Class Description

### Solution

This class provides a method to compute the Hamming Weight of an integer.

#### Public Methods:
- `int hammingWeight(int n)`: This method takes an integer `n` as input and returns the Hamming Weight of the integer.

## Method Details

### `hammingWeight(int n)`

- **Parameter**: 
  - `int n`: The integer whose Hamming Weight is to be calculated.
- **Returns**: 
  - `int`: The number of `1`s in the binary representation of `n`.

#### Method Implementation

The method initializes a variable `weight` to zero, which will count the number of set bits (1s). It then uses a while loop to check each bit of the integer `n`:
- If the least significant bit of `n` (i.e., `n % 2`) is `1`, it increments the `weight`.
- It then divides `n` by `2` to shift the bits to the right.
- The loop continues until `n` becomes zero.
- Finally, the method returns the `weight`.

## Usage

### Example

To use the `Solution` class to compute the Hamming Weight of a number, follow the steps below:

1. **Include the `Solution` class in your code.**
2. **Create an instance of the `Solution` class.**
3. **Call the `hammingWeight` method with the desired integer.**

Here is a sample code snippet:

```cpp
#include <iostream>
using namespace std;

class Solution {
public:
    int hammingWeight(int n) {
        int weight = 0; // Set a variable to count the set bits
        // Set up a while loop to check each bit
        while (n > 0) {
            if (n % 2 == 1) {
                weight += 1;
            }
            n = n / 2;
        }
        // Return the weight
        return weight;
    }
};

int main() {
    Solution solution;
    int number = 11; // Example number
    cout << "Hamming Weight of " << number << " is: " << solution.hammingWeight(number) << endl;
    return 0;
}
```

### Output

For the example number `11`, the binary representation is `1011`, which contains three `1`s. Thus, the Hamming Weight is `3`.

```
Hamming Weight of 11 is: 3
```

## Explanation

1. **Initialization**: An integer variable `weight` is initialized to zero to keep track of the number of set bits.
2. **Loop Through Bits**: A while loop is used to iterate through each bit of the integer `n`:
   - If the least significant bit of `n` is `1` (i.e., `n % 2 == 1`), increment the `weight` by one.
   - Divide `n` by `2` to shift right and check the next bit.
3. **Return Result**: After processing all bits, return the `weight`.
