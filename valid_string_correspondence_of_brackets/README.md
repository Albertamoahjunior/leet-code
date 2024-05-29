# Valid Parentheses Checker

## Description

This project contains a function that checks if a given string of parentheses is valid. A valid string must have matching opening and closing parentheses in the correct order. The function uses a stack data structure to ensure that each opening parenthesis has a corresponding closing parenthesis and that they are properly nested.

## Usage

### Function Definition

```cpp
class Solution {
public:
    bool isValid(string s);
};
```

### Parameters

- `s` (string): A string consisting of characters `(`, `)`, `{`, `}`, `[` and `]`.

### Returns

- `bool`: Returns `true` if the string is a valid parentheses string, `false` otherwise.

## Example

```cpp
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    Solution sol;
    string s = "{[()]}";
    cout << boolalpha << sol.isValid(s) << endl; // Output: true
    return 0;
}
```

## Implementation

The function uses a stack to check the validity of the parentheses string. It follows these steps:

1. Iterate through each character in the string.
   - If the character is an opening parenthesis (`(`, `[`, `{`), push it onto the stack.
   - If it is a closing parenthesis (`)`, `]`, `}`), check if the stack is empty. If the stack is empty, return `false` because there is no matching opening parenthesis.
   - If the stack is not empty, pop the top element and check if it matches the current closing parenthesis. If it does not match, return `false`.
2. After processing all characters, return `true` if the stack is empty (all opening parentheses had matching closing parentheses), otherwise return `false`.

### Code

```cpp
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else {
                if (st.empty()){
                    return false;
                }
                char top = st.top();
                st.pop();
                if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{')) {
                    return false;
                }
            }
        }
        return st.empty();
    }
};
```

## Dependencies

- C++ Standard Library
- `stack` for the stack data structure
- `string` for handling the input string

## Compilation

To compile and run the example code, you can use the following commands:

```bash
g++ -o validParentheses main.cpp
./validParentheses
```

Replace `main.cpp` with the name of your source file containing the example usage and the implementation of the `Solution` class.
