// BRUTE FORCE SOLUTION WITH SLIGHT IMPROVEMENT

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
        int maxVolume = 0;
        // check each pair of borders
        for (int i = 0; i < height.size(); i++) {
            // skip left borders that can't increase maxVolume
            if (height[i] * (height.size() - i - 1) <= maxVolume) continue;
            for (int j = i + 1; j < height.size(); j++) {
                // update maxVolume if a_i and a_j form new largest container 
                maxVolume = std::max(std::min(height[i], height[j]) * (j - i), 
                                     maxVolume);
            }
        }
        return maxVolume;
    }
};
