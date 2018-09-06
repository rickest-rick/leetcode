// SORTING LIKE THIS DOESN'T WORK BECAUSE THIS WAY WE CAN'T RETURN THE INDICES

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
        // sort the array 
        std::sort(nums.begin(), nums.end());
        unsigned int i = 0, j = nums.size() - 1;
        while (i < j) {
            int smallElement = nums[i], largeElement = nums[j];
            int sum = smallElement + largeElement;
            if (sum == target){
                // target found, return both elements
                vector<int> result;
                result.emplace_back(i);
                result.emplace_back(j);
                return result;
            }
            else if (sum < target){
                // choose larger small element
                i++; 
            }
            else if (sum > target){
                // choose smaller large element
                j--;
            }
        }
    }
};
