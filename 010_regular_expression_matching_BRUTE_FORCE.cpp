// BRUTE FORCE SOLUTIOM - WORKS WELL IF NOT MANY * CHARACTERS ARE IN THE PATTERN.
// IF THEY ARE, WE GET AN EXPONENTIAL COMPLEXITY, BECAUSE THE FUNCTION IS CALLED
// MULTIPLE TIMES WITH THE SAME pIndex and sIndex.
// TO PREVENT THIS, WE CAN USE MEMOISATION OR DYNAMIC PROGRAMMING.

class Solution {
public:
    /**
     * Given an input string (s) and a pattern (p), implement regular expression
     * matching with support for '.' and '*'.
     * The matching should cover the entire input string (not partial).
     * Note:
     * s could be empty and contains only lowercase letters a-z.
     * p could be empty and contains only lowercase letters a-z, and characters 
     * like . or *.
     * '*' means zero or more of the preceding element.
     * '.' Matches any single character.
     */
    bool isMatch(string s, string p) {
        return isMatchInternal(s, p, 0, 0);
    }

private:
    /**
     * Internal recursive function for regular expression matching.
     */
    bool isMatchInternal(string s, string p, int sIndex, int pIndex) {
        cout << "s: " << sIndex << " p: " << pIndex << endl;
        // end of pattern reached -> is end of string reached?
        if (p.size() <= pIndex) { return s.size() <= sIndex;}
        // end of string reached
        if (s.size() <= sIndex) {
            if (p.size() > pIndex + 1 && p.at(pIndex + 1) == '*'){
                // skippable chars remain
                return isMatchInternal(s, p, sIndex, pIndex + 2);
            } else { // is end of pattern reached?
                return p.size() <= pIndex;
            }
        }
        // check if next character can be repeated
        if (p.size() > pIndex + 1 && p.at(pIndex + 1) == '*') {
            // current char is a match
            if (s.at(sIndex) == p.at(sIndex) || p.at(sIndex == '.')) {
                bool zeroRepetitions = isMatchInternal(s, p, sIndex, pIndex + 2);
                bool lastRepetition = isMatchInternal(s, p, sIndex + 1, pIndex + 2);
                bool continueRepetitions = isMatchInternal(s, p, sIndex + 1, pIndex);
                return zeroRepetitions || lastRepetition || continueRepetitions;
            } else { // no match, char has to be ignored
                return isMatchInternal(s, p, sIndex, pIndex + 2);
            }
        } else { // nonrepeatable character
            if (s.at(sIndex) == p.at(sIndex) || p.at(sIndex == '.')) {
                return isMatchInternal(s, p, sIndex + 1, pIndex + 1);
            } else { // no match
                return false;
            }
        }
    }
}; 
