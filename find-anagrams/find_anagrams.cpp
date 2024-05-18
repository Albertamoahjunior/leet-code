class Solution{
public:
    bool isAnagram(string s, string t) {
        // If the lengths of the strings are not the same, they cannot be anagrams
        if (s.length() != t.length()) {
            return false;
        }

        // Create a frequency map for the characters in string s
        unordered_map<char, int> charCount;

        // Count the characters in s
        for (char c : s) {
            charCount[c]++;
        }

        // Subtract the counts for the characters in t
        for (char c : t) {
            if (charCount.find(c) == charCount.end() || charCount[c] == 0) {
                return false;  // If a character in t is not in s, they are not anagrams
            } else {
                charCount[c]--;
            }
        }

        // Check if all counts are zero
        for (const auto& count : charCount) {
            if (count.second != 0) {
                return false;
            }
        }

        return true;
    }
};
