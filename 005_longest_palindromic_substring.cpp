// SIMPLE SOLUTION USING THE MIDDLE POINTS OF POSSIBLE PALINDROMES
// DYNAMIC PROGRAMMING IS POSSIBLE, BUT OFFERS NO REAL ADVANTAGE BEING
// STILL O(n^2), BUT NOT IN-PLACE.

class Solution {
public:
    /**
     * Given a string s, find the longest palindromic substring in s. 
     * You may assume that the maximum length of s is 1000.
     */
    string longestPalindrome(string s) {
        if (s.empty()) {
            return "";
        }
        int longestLength = 0;
        int leftSolution;
        for (int palStart = 0; palStart < s.size();) {
            // can we even find a new longest palindrome starting here?
            if (2 * (s.size() - palStart - 1) + 1 <= longestLength) break;
            int left = palStart;
            int right = palStart;
            // duplicate characters can be skipped; we also don't 
            // have to check for odd and even length palindromes
            while (right < s.size() - 1 && s[right] == s[right + 1]) {
                right ++;
            }
            // duplicate characters don't have to be considered for
            // start points again
            palStart = right + 1;
            // check for matching characters at the start and end
            while (left > 0 && right < s.size() - 1 && s[left-1] == s[right+1]) {
                left--;
                right++;
            }
            if (right - left + 1 > longestLength) {
                leftSolution = left;
                longestLength = right - left + 1;
            }
        }
        return s.substr(leftSolution, longestLength);
    }
};
