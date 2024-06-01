class Solution{
    public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size();
        vector<int> answers(n, n); // Initialize all distances to a large value
        vector<int> char_pos;
        int start_point = 0;

        // First pass to collect all positions of character c
        for(int i = 0; i < n; i++){
            if(s[i] == c){
                char_pos.push_back(i);
            }
        }
        
        // Second pass: Calculate distances from left to right
        for(int i = 0; i < n; i++){
            int curr = abs(char_pos[start_point] - i);
            answers[i] = curr; // Assign the distance

            // Increment start_point when at position of c
            if(i == char_pos[start_point] && start_point < char_pos.size() - 1){
                start_point++;
            }
        }

        // Third pass: Calculate distances from right to left
        start_point = char_pos.size() - 1;
        for(int i = n - 1; i >= 0; i--){
            int curr = abs(char_pos[start_point] - i);
            answers[i] = min(curr, answers[i]); // Take the minimum distance

            // Decrement start_point when at position of c
            if(i == char_pos[start_point] && start_point > 0){
                start_point--;
            }
        }

        return answers;
    }
};
