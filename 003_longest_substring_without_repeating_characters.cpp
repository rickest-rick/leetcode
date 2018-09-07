#include <unordered_set>
#include <list>

class Solution {
public:
    /**
    * Given a string, find the length of the longest substring 
    * without repeating characters.
    */
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0) return 0;
        
        list<char> currentSubstring;
        unordered_set<char> charCache;
        int maxLength = 0, length = 0;

        for(int i = 0; i < s.length(); i++) {
            // check if the current character is already hashed
            if (charCache.count(s[i]) > 0) {
                // set new starting point right behind last occurence
                // of current character, update cache
                char duplicate = s[i];
                while (currentSubstring.front() != duplicate) {
                    charCache.erase(currentSubstring.front());
                    currentSubstring.pop_front();
                    length--;
                }
                // @TODO: this duplicate code is ugly, but a do-while-loop
                // wouldn't work, because we would skip the last duplicate 
                // element to delete
                charCache.erase(currentSubstring.front());
                currentSubstring.pop_front();
                length--;
            }
            currentSubstring.emplace_back(s[i]);
            length++;
            if (length > maxLength) maxLength = length;
            charCache.emplace(s[i]);
        }
        return maxLength;
    }
};
