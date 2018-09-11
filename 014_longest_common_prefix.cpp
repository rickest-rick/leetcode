// TECHNICALLY, WE COULD HAVE USED A WHILE-TRUE-LOOP AS WELL. THE bool prefixEndReached
// IS USED FOR READABILITY PURPOSES ONLY.
enum EndReached : char {
    END = 0,
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // check for empty input
        if (strs.size() == 0) return "";
        
        string output = "";
        bool prefixEndReached = false;
        int i = 0;
        while(!prefixEndReached) {
            // next char of first string has to be equal to next chars of all strings
            char nextChar = (strs.at(0).size() > i) ? strs.at(0).at(i) : END;
            for(auto& str : strs) {
                // end of a string reached or no match - no longer common prefix possible
                if (i >= str.size() || str.at(i) != nextChar) {
                    return output;
                }
            }
            // append common character to output
            if (!prefixEndReached) output.push_back(nextChar);
            // check next char
            i++;
        }
    }
};
