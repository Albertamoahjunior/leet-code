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
