class Solution {
public:
    int maxPower(string s) {
        //initializing important variables: current count and previous power
        int power = 0;
        int curr = 0; 
        
        //loop through string looking continuous characters and count them.
        //for every run of characters, count them and compare with previous ones commit the maximum to power
        for(int i = 1; i < size(s); i++){
            if(s[i] == s[i-1]){
                curr += 1;
            }else{
                power = max(curr, power);
                curr = 0;
            }
        }

        //when done, compare power and current run and again and commit the maximum 
        power = max(curr, power);
         
        //return the power plus one(this is take care of the index character)
        return power + 1;
    }
};
