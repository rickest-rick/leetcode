// NOT FINISHED YET AND SHORTER/CLEANER SOLUTION POSSIBLE; IDEA IS RIGHT THOUGH

#include <algorithm>
/**
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 *
 * Find the median of the two sorted arrays. The overall run time complexity 
 * should be O(log (m+n)).
 *
 * You may assume nums1 and nums2 cannot be both empty.
 */
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // check for empty vectors
        if (nums1.size() == 0) {
            return findMedianSortedArray(nums2);
        }
        if (nums2.size() == 0) {
            return findMedianSortedArray(nums1);
        }     
        
        int left1 = 0, left2 = 0;
        int right1 = nums1.size(), right2 = nums2.size();
        double median;
        int median1, median2;
        int numElements1 = right1;
        int numElements2 = right2;
        
        while (numElements1 > 1 && numElements2 > 1) {
            // compute the medians of the two subarrays
            median1 = nums1[left1 + (numElements1 / 2)];
            median2 = nums2[left2 + (numElements2 / 2)];
            // ignore the smaller subarrays above the larger and below the 
            // smaller median
            int numIgnoredElements = std::min(numElements1, numElements2) / 2;
            if (median1 >= median2) {
                right1 -= numIgnoredElements;
                left2 += numIgnoredElements;
            } else {
                left1 += numIgnoredElements;
                right2 -= numIgnoredElements;
            }
            numElements1 -= numIgnoredElements;
            numElements2 -= numIgnoredElements;
        }
        if (numElements1 == 1 && numElements2 == 1) {
            median = (nums1[left1] + nums2[left2]) / 2.0;
        } else if (numElements1 == 1) {
            median = findMedianExtraElement(nums2, left2, right2, nums1[left1]);
        } else if (numElements2 == 1) {
            median = findMedianExtraElement(nums1, left1, right1, nums2[left2]);
        }
        return median;
    }
private:
    /**
    * Returns the median of a subarray and an extra element.
    * 
    * @ensure: right - left > 1
    */
    double findMedianExtraElement(const vector<int>& nums, int left, int right, 
                                  int extra) {
        int leftMiddle, middle, rightMiddle;
        double median;
        // odd number -> check three middle and extra elements
        if ((right - left) % 2 == 1) {
            int middleIndex = left + (right - left) / 2;
            leftMiddle = nums[middleIndex - 1];
            middle = nums[middleIndex];
            rightMiddle = nums[middleIndex];
            std::vector<int> medianArray = {leftMiddle, middle, rightMiddle, extra};
            std::sort(medianArray.begin(), medianArray.begin());
            // median is mean between middle elements            
            median = (medianArray[1] + medianArray[2]) / 2.0;
        } // even number -> check two middle and extra elements
        else {
            leftMiddle = nums[left + (right - left) / 2 - 1];
            rightMiddle = nums[left + (right - left) / 2];
            std::vector<int> medianArray = {leftMiddle, rightMiddle, extra};
            std::sort(medianArray.begin(), medianArray.end());
            // median is middle element
            median = medianArray[1];
        }
        return median;
    }
    
    /**
     * return median of non-empty sorted array
     */
    double findMedianSortedArray(const vector<int>& nums) {
        if (nums.size() % 2 == 1) {
            return nums[nums.size() / 2.0];
        } else {
            int leftMiddle = nums[nums.size() / 2 - 1];
            int rightMiddle = nums[nums.size() / 2];
            return (leftMiddle + rightMiddle) / 2.0;
        }
    }
};
