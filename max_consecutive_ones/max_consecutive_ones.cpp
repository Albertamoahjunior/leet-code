class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        //intiliasing counting variables
        int curr = 0;
        int max_consecutive = 0;


        //iterating through the list, we count the number of ones we see per each run
        //curr is used for counting in current run and max_consecutive is used to keep the current maximum
        for(int num : nums){
            if(num == 1){
                curr += 1;
            }else{
                max_consecutive = max(max_consecutive, curr);
                curr = 0;
            }
        }




        //we return the current maximum between the two.
        return max(curr, max_consecutive);
    }
};
