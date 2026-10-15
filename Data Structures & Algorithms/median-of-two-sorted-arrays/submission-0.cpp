class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        // Always perform binary search on the smaller array
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();

        // Total elements that should be present
        // on the left side of the partition
        int totalLeft = (m + n + 1) / 2;

        int low = 0;
        int high = m;

        while (low <= high) {

            // Number of elements taken from nums1
            int cut1 = low + (high - low) / 2;

            // Remaining elements needed from nums2
            int cut2 = totalLeft - cut1;

            // Left and right elements around the partition
            int left1;
            int right1;
            int left2;
            int right2;

            // If cut1 == 0, nothing is taken from nums1
            if (cut1 == 0) {
                left1 = INT_MIN;
            }
            else {
                left1 = nums1[cut1 - 1];
            }

            // If cut1 == m, all elements are taken from nums1
            if (cut1 == m) {
                right1 = INT_MAX;
            }
            else {
                right1 = nums1[cut1];
            }

            // If cut2 == 0, nothing is taken from nums2
            if (cut2 == 0) {
                left2 = INT_MIN;
            }
            else {
                left2 = nums2[cut2 - 1];
            }

            // If cut2 == n, all elements are taken from nums2
            if (cut2 == n) {
                right2 = INT_MAX;
            }
            else {
                right2 = nums2[cut2];
            }

            // Correct partition found
            if (left1 <= right2 && left2 <= right1) {

                // Total number of elements is odd
                if ((m + n) % 2 == 1) {

                    return max(left1, left2);
                }

                // Total number of elements is even
                else {

                    int leftMax = max(left1, left2);
                    int rightMin = min(right1, right2);

                    return (leftMax + rightMin) / 2.0;
                }
            }

            // nums1's left element is too large
            // Move partition in nums1 towards left
            else if (left1 > right2) {

                high = cut1 - 1;
            }

            // nums1's left element is too small
            // Move partition in nums1 towards right
            else {

                low = cut1 + 1;
            }
        }

        return 0.0;
    }
};