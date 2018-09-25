class Solution {
public:
    /**
     * Given an array of integers nums sorted in ascending order, find the starting 
     * and ending position of a given target value.
     * Your algorithm's runtime complexity must be in the order of O(log n).
     * If the target is not found in the array, return [-1, -1].
     */
    vector<int> searchRange(vector<int>& nums, int target) {
        // binary search for any occurence of the target
        int left = 0, right = nums.size(), targetIndex = -1;
        while (left < right) {
            int m = left + (right - left) / 2;
            if (nums[m] == target) {
                targetIndex = m;
                break;
            } 
            else if (nums[m] > target) right = m;
            else left = m + 1;
        }
        if (targetIndex != -1) {
            int first = targetIndex, last = targetIndex;
            // binary search to the left for first position of the target
            left = 0;
            right = targetIndex + 1;
            while (left < right) {
                int m = left + (right - left) / 2;
                if (nums[m] == target) first = m;
                if (nums[m] >= target) right = m;
                else left = m + 1;
            }
            // binary search to the right for last position of the target
            left = targetIndex;
            right = nums.size();
            while (left < right) {
                int m = left + (right - left) / 2;
                if (nums[m] == target) last = m;
                if (nums[m] <= target) left = m + 1;
                else right = m;
            }
            return vector<int>{first, last};
        } else { // no target
            return vector<int>{-1,-1};
        }
    }
}; 
