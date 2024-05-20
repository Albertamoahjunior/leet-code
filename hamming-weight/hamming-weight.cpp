class Solution {
public:
    int weight = 0; //set a variable to count the set variables
    int hammingWeight(int n) {
        //Set up while loop and find the modulo after which the number should be divided by 2 per every iteration
        while(n > 0){
            if(n%2 == 1){
                weight += 1;
            }
            n = n/2;
        }

        //return the weight
        return weight;
    }
};
