class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int even_numbers = 0;


        for(int num : nums){
            if(size(to_string(num)) % 2 == 0){
                even_numbers ++;
            }
        }

        return even_numbers;
    }
};
