class Solution {
public:
    /**
     * Implement next permutation, which rearranges numbers into the lexicographically 
     * next greater permutation of numbers. If such arrangement is not possible, it must 
     * rearrange it as the lowest possible order (ie, sorted in ascending order). The 
     * replacement must be in-place and use only constant extra memory.
     * Here are some examples. Inputs are in the left-hand column and its corresponding
     * outputs are in the right-hand column. 
     *  1,2,3 ? 1,3,2
     *  3,2,1 ? 1,2,3
     *  1,1,5 ? 1,5,1
     */
    void nextPermutation(vector<int>& nums) {
        int smallerIndex = -1;
        // find the index of the first number which is smaller than its successor
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                smallerIndex = i;
                break;
            }
        }
        // not all numbers are sorted ascending
        if (smallerIndex != -1) {
            int smallestLarger = smallerIndex + 1; 
            // locate the smallest number which is larger than the found smaller predecessor 
            // between smallerIndex and the end of nums
            for (int i = smallerIndex + 1; i < nums.size(); i++) {
                if (nums[i] > nums[smallerIndex] && nums[i] < nums[smallestLarger]) smallestLarger = i;
            }
            // swap this number with smallerIndex
            swap(nums[smallestLarger], nums[smallerIndex]);
            // sort all numbers behind smallerIndex
            sort(nums.begin() + smallerIndex + 1, nums.end());
        } // all numbers are ascending -> all numbers are descending once reversed
        else { 
            reverse(nums.begin(), nums.end());
        }
    }
}; 
