class Solution {
public:
    /**
     *  Given n pairs of parentheses, write a function to generate all combinations of
     * well-formed parentheses.
     * For example, given n = 3, a solution set is:
     * [
     *  "((()))",
     * "(()())",
     * "(())()",
     * "()(())",
     *  "()()()"
     * ]
     */
    vector<string> generateParenthesis(int n) {
        if (n == 0) return vector<string>{""};
        
        vector<string> output;
        generateParenthesisInternal(output, "", n, 0);
        return output;
    }
    
private:
    void generateParenthesisInternal(vector<string>& parentheses, string s, int neededLeft, 
                                     int unclosedLeft) {
        // if all needed left parentheses are opened and closed again, we can append s to the 
        // output
        if (neededLeft == 0 && unclosedLeft == 0) parentheses.emplace_back(s);
        else {
            // open a new parenthesis, if one is needed
            if (neededLeft > 0) generateParenthesisInternal(parentheses, s + "(", neededLeft - 1, 
                                                            unclosedLeft + 1);
            // close a parenthesis, if one is needed
            if (unclosedLeft > 0) generateParenthesisInternal(parentheses, s + ")", neededLeft, 
                                                              unclosedLeft - 1);
        }
        return;
    }
};
