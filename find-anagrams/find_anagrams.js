/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function(s, t) {
    if (s.length !== t.length) {
        return false;
    }

    //create a map object for the objects
    const charCount = {};

    // Count the frequency of each character in string s
    for (let char of s) {
        charCount[char] = (charCount[char] || 0) + 1;
    }

    // Decrease the frequency based on characters in string t
    for (let char of t) {
        if (!charCount[char]) {
            return false; // if char is not found or frequency is 0
        }
        charCount[char]--;
    }

    // If all counts are zero, it's an anagram
    return true;
}
