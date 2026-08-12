int search(int* nums, int numsSize, int target) {
    int mode;
    int pos;
    int l;
    int r;
    int mid;

    if (numsSize == 0) {
        return -1;
    }

    if (target == nums[0]) {
        return 0;
    }

    if (target > nums[0]) {
        mode = 0;
    } else {
        mode = 1;
    }

    /* 找旋转位置 */
    pos = 0;

    while (pos + 1 < numsSize && nums[pos] < nums[pos + 1]) {
        pos++;
    }

    /*
        mode = 0
        target > nums[0]
        应该在左边升序部分
    */
    if (mode == 0) {
        l = 0;
        r = pos;
    }
    /*
        mode = 1
        target < nums[0]
        应该在右边升序部分
    */
    else {
        l = pos + 1;
        r = numsSize - 1;
    }

    /* 普通二分查找 */
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

    return -1;
}