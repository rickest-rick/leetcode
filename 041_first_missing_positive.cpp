// FIRST IDEA THAT'S NOT IN O(n): USE A MIN-HEAP AND REMOVE THE ROOT UNTIL YOU FIND
// TWO NON-CONSECUTIVE NUMBERS. THIS SOLUTION WOULD BE IN-PLACE WITH A BEST CASE OF 
// O(n) AND A WORST-CASE OF O(n log n).
// My solution uses the fact that, given the number of positive numbers k, the solution
// has to be between 1 and k + 1.
//      1. ignore non-positive numbers by setting them to INT_MAX (now all numbers are positive)
//      2. count to k
//      3. use the vector as hash map, where positive numbers are new and negative have been seen
//          before
//      4. return the first number that was not signed
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int k = 0;
        // set non-positive numbers to dummy values and count number of positive numbers
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= 0) nums[i] = INT_MAX;
            else k++;
        }
        // cache numbers between 1 and k
        for (int i = 0; i < nums.size(); i++) {
            int x = abs(nums[i]);
            if (x > 0 && x <= k) nums[x - 1] = - abs(nums[x - 1]);
        }
        // return first non-cached number
        int smallestMissingPositive = k + 1;
        for (int i = 0; i < k; i++) {
            if (nums[i] > 0) {
                smallestMissingPositive = i + 1;
                break;
            }
        }
        return smallestMissingPositive;
    }
};
