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
        int maxLength = 0;

        for(int i = 0; i < s.length(); i++) {
            // check if the current character is already hashed
            if (charCache.count(s[i]) > 0) {
                // set new starting point right behind last occurence
                // of current character, update cache
                char duplicate = s[i];
                while (currentSubstring.front() != duplicate) {
                    charCache.erase(currentSubstring.front());
                    currentSubstring.pop_front();
                }
                // @TODO: this duplicate code is ugly, but a do-while-loop
                // wouldn't work, because we would skip the last duplicate 
                // element to delete
                charCache.erase(currentSubstring.front());
                currentSubstring.pop_front();
            }
            currentSubstring.emplace_back(s[i]);
            charCache.emplace(s[i]);
            if (charCache.size() > maxLength) maxLength = charCache.size();
        }
        return maxLength;
    }
};
