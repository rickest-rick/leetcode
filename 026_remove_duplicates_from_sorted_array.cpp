class Solution {
public:
    /**
     * Given a sorted array nums, remove the duplicates in-place such that each 
     * element appear only once and return the new length.
     * Do not allocate extra space for another array, you must do this by modifying 
     * the input array in-place with O(1) extra memory.
     */
    int removeDuplicates(vector<int>& nums) {
        int current = 0, lastUnique = -1;
        while (current < nums.size()) {
            // save first instance of newly found element behind lastUnique
            nums[++lastUnique] = nums[current];
            // skip duplicates
            do current++;
            while (nums[current] == nums[current - 1]);
        }
        return lastUnique + 1;
    }
};
