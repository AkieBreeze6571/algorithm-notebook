void swap(int *n, int *m) {
    int temp = *n;
    *n = *m;
    *m = temp;
}

void nextPermutation(int* nums, int numsSize) {
    int pos;
    int change;
    int i;
    int left;
    int right;

    pos = numsSize - 2;

    /* 找到第一个 nums[pos] < nums[pos + 1] */
    while (pos >= 0 && nums[pos] >= nums[pos + 1]) {
        pos--;
    }

    /* 如果整个数组都是降序，说明已经是最大排列 */
    if (pos < 0) {
        left = 0;
        right = numsSize - 1;

        while (left < right) {
            swap(&nums[left], &nums[right]);
            left++;
            right--;
        }

        return;
    }

    /* 按照你的逻辑寻找 change */
    change = pos + 1;
    i = 1;

    while (change + 1 <= numsSize - 1 && i) {
        if (nums[pos] >= nums[change + 1]) {
            i = 0;
        } else {
            change++;
        }
    }

    /* 交换 pos 和 change */
    swap(&nums[pos], &nums[change]);

    /* 将 pos 后面的部分重新变成升序 */
    left = pos + 1;
    right = numsSize - 1;

    while (left < right) {
        swap(&nums[left], &nums[right]);
        left++;
        right--;
    }
}