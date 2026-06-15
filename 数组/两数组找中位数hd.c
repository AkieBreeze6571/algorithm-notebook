#include <limits.h>

int maxInt(int a, int b) {
    return a > b ? a : b;
}

int minInt(int a, int b) {
    return a < b ? a : b;
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    // 题目的时间复杂度只能采用二分法
    // 只二分一个数组，另一个数组的切割位置自动获取

    int left;
    int right;
    int total;
    int half;

    // 保证 nums1 是较短的数组
    // 因为只在 nums1 上二分
    if (nums1Size > nums2Size) {
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }

    left = 0;
    right = nums1Size;

    total = nums1Size + nums2Size;
    half = (total + 1) / 2;

    while (left <= right) {
        int i = (left + right) / 2;
        int j = half - i;

        int nums1Left;
        int nums1Right;
        int nums2Left;
        int nums2Right;

        nums1Left = (i == 0) ? INT_MIN : nums1[i - 1];
        nums1Right = (i == nums1Size) ? INT_MAX : nums1[i];

        nums2Left = (j == 0) ? INT_MIN : nums2[j - 1];
        nums2Right = (j == nums2Size) ? INT_MAX : nums2[j];

        if (nums1Left <= nums2Right && nums2Left <= nums1Right) {
            if (total % 2 == 1) {
                return (double)maxInt(nums1Left, nums2Left);
            } else {
                return ((double)maxInt(nums1Left, nums2Left)
                      + (double)minInt(nums1Right, nums2Right)) / 2.0;
            }
        } else if (nums1Left > nums2Right) {
            right = i - 1;
        } else {
            left = i + 1;
        }
    }

    return 0.0;
}