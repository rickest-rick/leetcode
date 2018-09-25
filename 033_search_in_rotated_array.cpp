class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        while (left < right) {
            int m = left + (right - left) / 2;
            if (target == nums[m]) return m; // middle is target index -> return m
            else if (nums[m] <= nums[right - 1]) { // middle is right of pivot
                if (nums[m] > target || nums[right - 1] < target) { 
                    // target is smaller than middle or larger than right -> left side
                    right = m;
                } else { 
                    // target is larger than middle or smaller than or equal to right -> right
                    left = m + 1;
                }
            } else { // middle is left of pivot
                if (nums[m] < target || nums[left] > target) {
                    // target is larger than middle or smaller than left -> right
                    left = m + 1;
                } else {
                    // target is larger than or equal to right and smaller than middle -> left
                    right = m;
                }
            }
        }
        return -1;
    }
};
