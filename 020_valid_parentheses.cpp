class Solution {
public:
    /**
     * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', 
     * determine if the input string is valid.
     * An input string is valid if: 
     *    Open brackets must be closed by the same type of brackets.
     *    Open brackets must be closed in the correct order.
     * Note that an empty string is also considered valid.
     */
    bool isValid(string s) {
        stack<char> openParentheses;
        openParentheses.push('$');
        for (int i = 0; i < s.size(); i++) {
            switch(s.at(i)) {
                // push openin parentheses to stack
                case '(' : openParentheses.push('('); break;
                case '{' : openParentheses.push('{'); break;
                case '[' : openParentheses.push('['); break;
                // check if closing parentheses are on top of stack
                case ')' : if (openParentheses.top() == '(') {
                               openParentheses.pop();
                               break;
                           } else return false;
                case '}' : if (openParentheses.top() == '{') {
                               openParentheses.pop();
                               break;
                           } else return false;
                case ']' : if (openParentheses.top() == '[') {
                               openParentheses.pop();
                               break;
                           } else return false;
                // no other chars allowed
                default: return false;
            }
        }
        // not all opened parentheses were closed
        if (openParentheses.size() != 1) return false;
        else return true;
    }
};
