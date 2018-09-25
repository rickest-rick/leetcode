class Solution {
public:
    /**
     * Given a sorted array and a target value, return the index if the target is 
     * found. If not, return the index where it would be if it were inserted in order.
     * You may assume no duplicates in the array.
     */
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        while (left < right) {
            int m = left + (right - left) / 2;
            // found
            if (nums[m] == target) return m;
            // target in right half
            else if (nums[m] < target) left = m + 1;
            // target in left half
            else right = m;
        }
        return left;
    }
};
