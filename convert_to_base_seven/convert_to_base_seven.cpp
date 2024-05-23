class Solution {
public:
    string convertToBase7(int num) {

        //initialise variables to hold negative state and also string
        stringstream p_convert;
        bool negative = false;

        //if a number is less than 7 and greater than or equal to 0 it should be returned of course it is mode 7
        if(num < 7 && num >= 0){
            return to_string(num);
        }


        //while the base 10 number is still not 0 finf the modulo and divide by 7
        while(num != 0){
            p_convert << num%7;
            num /= 7;
        }

        //convert the string stream to string and reverse the order
        string f_convert = p_convert.str();
        std::reverse(f_convert.begin(), f_convert.end());


        //look for the negative signs and remove them if you find any commit negative boolean to true
        for(char c : f_convert){
            if(c == '-'){
                f_convert.erase(f_convert.find(c), 1);
                negative = true;
            }
        }

        //if the negative value is true insert the negative sign at the index position
        if(negative){
            f_convert.insert(0, 1, '-');
        }


        //return the final string
        return f_convert;
    }
};
