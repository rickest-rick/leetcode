#include <vector>
#include <algorithm>

class Solution {
public:
    /*
    * Given an array of integers, return indices of the two numbers
    * such that they add up to a specific target.
    * You may assume that each input would have exactly one solution, 
    * and you may not use the same element twice.
    */
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> cache;
        // iterate over all elements
        for(int i = 0; i < nums.size(); i++){
            // check if the value of the current element is cached
            int currentElement = nums[i];
            if (cache.count(currentElement) > 0) {
                // if it is: return the cached index and the current index
                vector<int> result;
                result.emplace_back(cache.at(currentElement));
                result.emplace_back(i);
                return result;
            }
            // else: cache target minus current element as key and current
            // index as value
            else {
                cache.emplace(target - currentElement, i);
            }
        }
    }
};
