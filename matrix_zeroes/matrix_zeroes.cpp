class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int, int>> zero_positions;

        // Collect positions of zeroes
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[i].size(); j++) {
                if(matrix[i][j] == 0) {
                    zero_positions.push_back({i, j});
                }
            }
        }

        // Set rows and columns to zero
        for(auto& pos : zero_positions) {
            int row = pos.first;
            int col = pos.second;

            // Set entire row to zero
            for(int j = 0; j < matrix[row].size(); j++) {
                matrix[row][j] = 0;
            }

            // Set entire column to zero
            for(int i = 0; i < matrix.size(); i++) {
                matrix[i][col] = 0;
            }
        }
    }
};
