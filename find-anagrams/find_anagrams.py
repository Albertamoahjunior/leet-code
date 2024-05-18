class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        #first if two strings are not of the same size, they are cannot be anagrams
        if(len(s) != len(t)):
            return False

        #create a dictionary to as a character map
        charCount = {}

        #pick one string and map its characters with its frequency
        for c in s:
            if c in charCount:
                charCount[c] += 1
            else:
                charCount[c] = 1

        #now take the other string and loop through, while looping through if you find a foreign character(a character not in the first string)
        #return false else decrement the frequency of the character by 1
        for c in t:
            if c in charCount:
                charCount[c] -= 1
            else:
                return False

        #loop through all characters if any has a frequency which is not 0 return false
        for c in charCount:
            if charCount[c] != 0:
                return False


        #return true otherwise
        return True
