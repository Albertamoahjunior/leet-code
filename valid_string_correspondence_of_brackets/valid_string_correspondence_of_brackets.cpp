class Solution {
public:
    bool isValid(string s) {
        //initializing a stack to hold current values
        stack<char> st;

        //iterate through the string 
        //if a bracket is an open bracket push it to the stack.
        //if not check if the stack is empty, if empty return false.
        //if not empty pop the top element to compare with the current character to know if it is a corresponding 
        //closing tag. if yes return true otherwise return false.
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else {
                if (st.empty()){
                    return false;
                }
                char top = st.top();
                st.pop();
                if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{')) {
                    return false;
                }
            }
        }

        //finally return the state the of them stack, if all opening tags had a corresponding ending tags, the
        //stack should empty otherwise not all tags have their correspondence hence not a valid string.
        return st.empty();
    }
};
