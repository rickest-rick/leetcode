class Solution {
public:
    /**
     * Given an array nums of n integers and an integer target, find three integers in nums 
     * such that the sum is closest to target. Return the sum of the three integers. You 
     * may assume that each input would have exactly one solution.
     */
    int threeSumClosest(vector<int>& nums, int target) {
        // sort the numbers
        sort(nums.begin(), nums.end());
        // initialize closest with first triplet
        int closest = nums.at(0) + nums.at(1) + nums.at(2);
        // for each starting point
        for (int start = 0; start + 2 < nums.size(); start++) {
            // start with smallest and largest point behind start
            int left = start + 1;
            int right = nums.size() - 1;
            while (left < right) {
                int sum = nums.at(start) + nums.at(left) + nums.at(right);
                // if sum is target, return target
                if (sum == target) return target;
                // if sum is closer to target than closest so far, update it
                else if (abs(target - sum) < abs(target - closest)) closest = sum;
                // if sum is too small, increase smaller number
                if (sum < target) left++;
                // if sum is too large, decrease larger number
                else right--;
            }
            // skip duplicate starting points
            while (start + 3 < nums.size() && nums.at(start) == nums.at(start + 1)) start++;
        }
        return closest;
    }
}; 

