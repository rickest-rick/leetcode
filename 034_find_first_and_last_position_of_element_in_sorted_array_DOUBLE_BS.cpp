class Solution {
public:
    /**
     * Given an array of integers nums sorted in ascending order, find the starting 
     * and ending position of a given target value.
     * Your algorithm's runtime complexity must be in the order of O(log n).
     * If the target is not found in the array, return [-1, -1].
     */
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        int first = -1, last = -1;
        // binary search for first
        while (left < right) {
            int m = left + (right - left) / 2;
            if (nums[m] == target) first = m;
            if (nums[m] >= target) right = m;
            else left = m + 1;
        } 
        if (first != -1) { // target is present in nums
            left = 0;
            right = nums.size();
            // binary search for last
            while (left < right) {
                int m = left + (right - left) / 2;
                if (nums[m] == target) last = m;
                if (nums[m] <= target) left = m + 1;
                else right = m;
            }
        }
        return vector<int>{first, last};
    }
}; 
