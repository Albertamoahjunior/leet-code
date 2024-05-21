---

# Unique Email Addresses

## Problem Description

Given an array of strings `emails` where each string represents an email address, return the number of unique email addresses that actually receive mails. 

### Email Address Rules:

1. **Local name and domain name**:
    - Every email consists of a local name and a domain name, separated by the '@' sign.
    - For example, in "alice@leetcode.com", "alice" is the local name, and "leetcode.com" is the domain name.
  
2. **Dots in the local name**:
    - You can add periods ('.') between some characters in the local name part of an email address.
    - Emails sent to addresses with dots in the local name will be forwarded to the same address without dots.
    - Example: "alice.z@leetcode.com" and "alicez@leetcode.com" are considered the same.

3. **Plus sign in the local name**:
    - If you add a plus ('+') in the local name, everything after the first plus sign will be ignored.
    - Example: "m.y+name@email.com" will be forwarded to "my@email.com".

## Solution

The solution processes each email to standardize it according to the rules above and then counts unique standardized email addresses.

### Code

```cpp
#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>

class Solution {
public:
    std::string processEmail(const std::string &email) {
        size_t at_position = email.find('@');
        std::string local = email.substr(0, at_position);
        std::string domain = email.substr(at_position);
        
        // Remove dots from the local part
        local.erase(std::remove(local.begin(), local.end(), '.'), local.end());
        
        // Ignore everything after the first plus
        size_t plus_pos = local.find('+');
        if (plus_pos != std::string::npos) {
            local = local.substr(0, plus_pos);
        }
        
        // Combine local and domain
        return local + domain;
    }

    int numUniqueEmails(std::vector<std::string>& emails) {
        std::unordered_set<std::string> uniqueEmails;
    
        // Process each email and insert into the set
        for (const std::string& email : emails) {
            uniqueEmails.insert(processEmail(email));
        }
        
        // Return the number of unique emails
        return uniqueEmails.size();
    }
};

int main() {
    Solution solution;
    std::vector<std::string> emails = {
        "test.email+alex@leetcode.com",
        "test.e.mail+bob.cathy@leetcode.com",
        "testemail+david@lee.tcode.com"
    };
    
    int uniqueCount = solution.numUniqueEmails(emails);
    std::cout << "Number of unique email addresses: " << uniqueCount << std::endl;
    
    return 0;
}
```

### Explanation

1. **processEmail Function**:
    - **Splitting**: Splits the email into local and domain parts using the '@' symbol.
    - **Removing Dots**: Removes all periods ('.') from the local part.
    - **Handling Plus Sign**: Ignores everything after the first plus ('+') in the local part.
    - **Combining**: Combines the processed local part with the domain part.

2. **numUniqueEmails Function**:
    - Uses an `unordered_set` to store unique email addresses after processing.
    - Iterates over each email, processes it, and inserts the processed email into the set.
    - The size of the set represents the number of unique email addresses.

## Usage

To use this code:

1. Compile the code using a C++ compiler.
2. Run the compiled program.
3. The output will be the number of unique email addresses from the input list.

### Example

For the input:
```cpp
std::vector<std::string> emails = {
    "test.email+alex@leetcode.com",
    "test.e.mail+bob.cathy@leetcode.com",
    "testemail+david@lee.tcode.com"
};
```

The output will be:
```
Number of unique email addresses: 2
```

## Constraints

- `1 <= emails.length <= 100`
- `1 <= emails[i].length <= 100`
- `emails[i]` consist of lowercase English letters, '+', '.' and '@'.
- Each `emails[i]` contains exactly one '@' character.
- All local and domain names are non-empty.
- Domain names end with the ".com" suffix.

## Conclusion

This program efficiently processes email addresses to determine the number of unique addresses using standard string manipulation techniques in C++. The key operations involve handling periods and plus signs in the local part of the email addresses while leaving the domain part unchanged.

---
