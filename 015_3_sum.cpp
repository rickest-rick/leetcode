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
        vector<vector<int>> output;
        // sort the numbers
        sort(nums.begin(), nums.end());
        // set the inverse of the current element as target
        int target, left, right, sum;
        for (int i = 0; i + 2 < nums.size(); ) {
            target = -nums[i];
            // start with the outer elements at the start and end behind the target
            left = i + 1;
            right = nums.size() - 1;
            while (left < right) {
                sum = nums[left] + nums[right];
                // check if the sum of a and b is the negative of the target
                if (sum == target) {
                    // if it is, save them to the output
                    vector<int> threeSum = {-target, nums[left], nums[right]};
                    output.emplace_back(threeSum);
                    // continue, skipping elements which were seen before to prevent duplicates
                    while (nums[left] == threeSum[1] && left < right) left++;
                    while (nums[right] == threeSum[2] && left < right) right--;
                } // if the sum is too small, increase smaller value
                else if (sum <  target) left++;
                // if the sum is too large, decrease larger value
                else if (sum > target) right--;
            }
            // increase index i for target and skip duplicates
            do {
                i++;
            } while (nums[i] == nums[i - 1]);
        }
        return output;
    }
}; 
