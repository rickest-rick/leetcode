enum MatchingType : short {
    FALSE = 0,
    TRUE,
    UNKNOWN,
};

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
        vector<vector<MatchingType>> cache = {s.size() + 1, vector<MatchingType>(p.size() + 1)};
        for (auto& i : cache) {
            fill(i.begin(), i.end(), UNKNOWN);
        }
        return isMatchInternal(cache, s, p, 0, 0);
    }

private:
    /**
     * Internal recursive function for regular expression matching.
     */
    bool isMatchInternal(vector<vector<MatchingType>>& cache, string const& s, 
                         string const& p, int sIndex, int pIndex) {
        // return cached value, if it has been computed before
        if (cache[sIndex][pIndex] != UNKNOWN) return cache[sIndex][pIndex];
        // end of pattern reached -> is end of string reached?
        if (p.size() <= pIndex) {
            cache[sIndex][pIndex] = s.size() <= sIndex ? TRUE : FALSE;
        } // end of string reached
        else if (s.size() <= sIndex) {
            if (p.size() > pIndex + 1 && p.at(pIndex + 1) == '*'){
                // skippable chars remain
                cache[sIndex][pIndex] = isMatchInternal(cache, s, p, sIndex, pIndex + 2) ?
                    TRUE : FALSE;
            } else { // is end of pattern reached?
                cache[sIndex][pIndex] = p.size() <= pIndex ? TRUE : FALSE;
            }
        } // check if next character can be repeated
        else if (p.size() > pIndex + 1 && p.at(pIndex + 1) == '*') {
            // current char is a match
            if (s.at(sIndex) == p.at(pIndex) || p.at(pIndex) == '.') {
                bool zeroRepetitions = isMatchInternal(cache, s, p, sIndex, pIndex + 2);
                bool lastRepetition = isMatchInternal(cache, s, p, sIndex + 1, pIndex + 2);
                bool continueRepetitions = isMatchInternal(cache, s, p, sIndex + 1, pIndex);
                cache[sIndex][pIndex] = zeroRepetitions || lastRepetition || 
                    continueRepetitions ? TRUE : FALSE;
            } else { // no match, char has to be ignored
                cache[sIndex][pIndex] = isMatchInternal(cache, s, p, sIndex, pIndex + 2) ? 
                    TRUE : FALSE;
            }
        } else { // nonrepeatable character
            if (s.at(sIndex) == p.at(pIndex) || p.at(pIndex) == '.') {
                cache[sIndex][pIndex] = isMatchInternal(cache, s, p, sIndex + 1, pIndex + 1) ? 
                    TRUE : FALSE;
            } else { // no match
                cache[sIndex][pIndex] = FALSE;
            }
        }
        return cache[sIndex][pIndex];
    }
}; 
