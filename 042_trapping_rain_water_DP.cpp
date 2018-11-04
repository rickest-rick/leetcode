class Solution {
public:
    /**
     * Given n non-negative integers representing an elevation map where the width of 
     * each bar is 1, compute how much water it is able to trap after raining.
     */
    int trap(vector<int>& height) {
        /* The maximum point to the left of i is either the maximum point to the left of 
            i - 1 or i - 1 itself. */
        vector<int> max_left(height.size());
        for (int i = 1; i < max_left.size(); i++) {
            max_left[i] = max(max_left[i-1], height[i-1]);
        }
        /* The maximum point to the right of i is either the maximum point to the right of 
            i + 1 or i + 1 itself. */
        vector<int> max_right(height.size());
        for (int i = max_right.size() - 2; i >= 0; i--) {
            max_right[i] = max(max_right[i+1], height[i+1]);
        }
        /* The amount of water trapped above a point i is the minimum of the maximum points 
            to the left and right minus height[i] or 0. These maximum points were calculated 
            using dynamic programming. */
        int trapped_water = 0;
        for (int i = 0; i < height.size(); i++) {
            int water_above = max(min(max_left[i], max_right[i]) - height[i], 0);
            trapped_water += water_above;
        }
        return trapped_water;
    }
};
