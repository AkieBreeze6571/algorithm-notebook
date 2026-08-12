int searchInsert(int* nums, int numsSize, int target) {
    int l;
    int r;
    int mid;

    l = 0;
    r = numsSize - 1;

    while (l <= r) {
        mid = (l + r) / 2;

        if (nums[mid] == target) {
            return mid;
        }

        if (nums[mid] < target) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    return l;
}