// THIS SOLUTION DOESN#T WORK. TO MAKE IT WORK, WE HAVE TO CACHE SET THE VALUES OF b AND
// -(a+b) FOR EACH a INDIVIDUALLY TO TRUE. OTHERWISE, IT IS NOT GUARANTEED THAT EACH TRIPLET
// IS SAVED ONLY ONCE. HOWEVER, THIS INCREASES THE RUNNING TIME EVEN MORE COMPARED TO THE
// SOLUTION WITH SORTING, WHICH IS EVEN IN-PLACE.
class Solution {
public:
    /**
     * Given an array nums of n integers, are there elements a, b, c in nums
     * such that a + b + c = 0? Find all unique triplets in the array which 
     * gives the sum of zero.
     *
     * Note:
     * The solution set must not contain duplicate triplets.
     */
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int, bool> cache;
        vector<vector<int>> output;
        // cache each number
        for (int i = 0; i < nums.size(); i++) {
            cache.emplace(nums[i], false);
        }
        // for each pair (a,b): check if -(a+b) is cached.
        for(int i = 0; i < nums.size() - 1; i++) {
            int a = nums[i];
            // skip a, if it was seen before
            if (cache[a] == true) break;
            for (int j = i + 1; j < nums.size(); j++) {
                int b = nums[j];
                unordered_map<int, bool>::const_iterator thirdElementIt =
                    cache.find(-(a + b));
                // if element was found, append triplet to output
                if (thirdElementIt != cache.end()) {
                    vector<int> zeroTriplet = {a, b, thirdElementIt->first};
                    output.emplace_back(zeroTriplet);
                }
            }
            // save that a was seen
            cache[a] = true;
        }
        return output;
    }
};
