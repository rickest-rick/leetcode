class Solution {
public:
    /**
     * Given n non-negative integers a1, a2, ..., an , where each represents 
     * a point at coordinate (i, ai). n vertical lines are drawn such that the 
     * two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which 
     * together with x-axis forms a container, such that the container contains 
     * the most water.
     */
    int maxArea(vector<int>& height) {
        // starting from the outer borders of the array
        int left = 0, right = height.size() - 1;
        int maxVolume = area(height, left, right);
        // iterate towards the middle, stopping at higher left and right borders
        // that might result in a higher maxVolume
        while (right > left) {
            if (height[right] > height[left]) {
                left++;
                if (height[left] > height[left - 1]) {
                    maxVolume = max(maxVolume, area(height, left, right));
                }
            } else {
                right--;
                if (height[right] > height[right + 1]) {
                    maxVolume = max(maxVolume, area(height, left, right));
                }
            }
        }        
        return maxVolume;
    }
private:
    /**
     * Given n non-negative integers a1, a2, ..., an, where each represent
     * a point at coordinate (i, ai) and two indices left and right. Return
     * the area of the rectangle, if a vertical line is dran between 
     * (left, a_left) and (right, a_right).
     */
     int area(const vector<int>& height, int left, int right) {
         return min(height[left], height[right]) * (right - left);
     }
};
