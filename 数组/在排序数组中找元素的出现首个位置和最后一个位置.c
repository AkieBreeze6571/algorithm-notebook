int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int l, r, mid;
    int start, end;
    int l1, r1;
    int* result;

    result = malloc(sizeof(int) * 2);
    *returnSize = 2;

    if (numsSize == 0) {
        result[0] = -1;
        result[1] = -1;
        return result;
    }

    l = 0;
    r = numsSize - 1;

    /* 第一次二分：先找到任意一个 target */
    while (l <= r) {
        mid = (l + r) / 2;

        if (nums[mid] == target) {
            break;
        }

        if (nums[mid] < target) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    /* 没找到 */
    if (l > r) {
        result[0] = -1;
        result[1] = -1;
        return result;
    }

    start = mid;
    end = mid;

    /*
        当前已经知道 nums[mid] == target

        左边界搜索范围：
        l ~ mid
    */
    r1 = mid;

    while (l < r1) {
        mid = (l + r1) / 2;

        if (nums[mid] < target) {
            l = mid + 1;
        } else {
            r1 = mid;
        }
    }

    start = l;

    /*
        右边界搜索范围：
        原来的 target 位置 ~ r
    */
    l1 = end;

    while (l1 < r) {
        mid = (l1 + r + 1) / 2;

        if (nums[mid] > target) {
            r = mid - 1;
        } else {
            l1 = mid;
        }
    }

    end = r;

    result[0] = start;
    result[1] = end;

    return result;
}