class Solution {
public:
    string largestOddNumber(string num) {
        //initialise is odd variable and the position of the last odd number
        int odd_pos = 0;
        bool is_odd = false;

        //loop through the string if there is an odd number, commit it position to memory
        for(int i = 0; i<size(num); i++){
            if(int(num[i] - '0')%2 != 0){
                odd_pos = i;
                is_odd = true;
            }
        }

        //if the position of the odd number is the last number in the string, then the whole number is an odd number
        if(odd_pos == size(num) - 1 && is_odd){
            return num;
        }

        //if not and the numer has an odd substring, add one to the position as the length odf the substring
        is_odd ? odd_pos += 1 : odd_pos+=0;


        //return the substring
        return num.substr(0, odd_pos);
    }
};
