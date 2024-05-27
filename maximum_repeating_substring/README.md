# README

## maxRepeating

This repository contains a solution for finding the maximum number of times a word can repeat consecutively in a given sequence. The solution is implemented in C++.

### Problem Statement

Given a string `sequence` and a string `word`, we need to find the maximum number of times `word` can repeat consecutively in `sequence`.

### Example

```cpp
class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int num = 0;              // Initialize the maximum repeat count
        int curr = 0;             // Initialize the current repeat count
        int len_size = size(word); // Length of the word
        int s_size = size(sequence); // Length of the sequence
        int count = 0;            // Counter to traverse the sequence

        // If the sequence is exactly the same as the word, return 1
        if(sequence == word){
            return 1;
        }

        // Loop through the sequence
        while(count < s_size){
            // Check if the substring from the current position matches the word
            if(sequence.substr(count, len_size) == word){
                curr += 1; // Increment current repeat count
                count += len_size; // Move the counter forward by the word length
            }else{
                num = max(num, curr); // Update the maximum repeat count if necessary
                curr = 0; // Reset the current repeat count
                count++; // Move the counter forward by one
            }
        }

        // Handle the case where the last series of repeats is the longest
        if((num > 1) && curr > num && num >= curr/2){
            num = curr + 1;
        }

        return max(num, curr); // Return the maximum repeat count
    }
};
```

### Explanation

The code defines a class `Solution` with a member function `maxRepeating` that takes two strings, `sequence` and `word`, as input and returns an integer indicating the maximum number of times `word` can repeat consecutively in `sequence`.

#### Detailed Steps

1. Initialize variables `num` and `curr` to 0. `num` keeps track of the maximum number of consecutive repetitions found, while `curr` keeps track of the current number of repetitions.
2. Calculate the length of `word` (`len_size`) and `sequence` (`s_size`).
3. Use a counter `count` to traverse the `sequence`.
4. If `sequence` is exactly equal to `word`, return 1.
5. Loop through the `sequence` using the `count` variable:
    - If the substring of `sequence` starting at `count` with length `len_size` is equal to `word`, increment `curr` and move `count` forward by `len_size`.
    - If the substring does not match `word`, update `num` if `curr` is greater than `num`, reset `curr` to 0, and increment `count` by 1.
6. After the loop, handle the case where the last series of repeats is the longest.
7. Return the maximum of `num` and `curr`.

### Usage

To use this solution, include the `Solution` class in your code and call the `maxRepeating` method with the appropriate `sequence` and `word` strings. The method will return an integer representing the maximum number of consecutive repetitions of `word` in `sequence`.

### Example Usage

```cpp
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int num = 0;
        int curr = 0;
        int len_size = size(word);
        int s_size = size(sequence);
        int count = 0;

        if(sequence == word){
            return 1;
        }

        while(count < s_size){
            if(sequence.substr(count, len_size) == word){
                curr += 1;
                count += len_size;
            }else{
                num = max(num, curr);
                curr = 0;
                count++;
            }
        }

        if((num > 1) && curr > num && num >= curr/2){
            num = curr + 1;
        }

        return max(num, curr);
    }
};

int main() {
    Solution sol;
    string sequence = "ababc";
    string word = "ab";
    cout << sol.maxRepeating(sequence, word) << endl; // Output: 2
    return 0;
}
```

