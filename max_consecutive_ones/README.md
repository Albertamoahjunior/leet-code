# Find Max Consecutive Ones

## Description

This project contains a function that finds the maximum number of consecutive 1s in a binary array. The function iterates through the array, counting the consecutive 1s and tracking the maximum number of consecutive 1s found.

## Usage

### Function Definition

```cpp
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums);
};
```

### Parameters

- `nums` (vector<int>): A binary array (vector of integers containing only 0s and 1s).

### Returns

- `int`: The maximum number of consecutive 1s in the input binary array.

## Example

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    Solution sol;
    vector<int> nums = {1, 1, 0, 1, 1, 1};
    cout << sol.findMaxConsecutiveOnes(nums) << endl; // Output: 3
    return 0;
}
```

## Implementation

The function uses a simple loop to traverse the binary array. It maintains two variables:

1. `curr`: The current count of consecutive 1s.
2. `max_consecutive`: The maximum count of consecutive 1s found so far.

The algorithm works as follows:
1. Initialize `curr` and `max_consecutive` to 0.
2. Iterate through each number in the array:
   - If the number is 1, increment `curr`.
   - If the number is 0, update `max_consecutive` with the maximum value between `max_consecutive` and `curr`, then reset `curr` to 0.
3. After the loop, return the maximum value between `curr` and `max_consecutive` to handle the case where the array ends with a sequence of 1s.

### Code

```cpp
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int curr = 0;
        int max_consecutive = 0;

        for(int num : nums){
            if(num == 1){
                curr += 1;
            }else{
                max_consecutive = max(max_consecutive, curr);
                curr = 0;
            }
        }

        return max(curr, max_consecutive);
    }
};
```

## Dependencies

- C++ Standard Library
- `vector` for the dynamic array data structure
- `algorithm` for the `max` function

## Compilation

To compile and run the example code, you can use the following commands:

```bash
g++ -o findMaxConsecutiveOnes main.cpp
./findMaxConsecutiveOnes
```

Replace `main.cpp` with the name of your source file containing the example usage and the implementation of the `Solution` class.

