void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quicksort(int *nums, int left, int right) {
    if (left >= right) {
        return;
    }

    int pivot = nums[right];
    int i = left - 1;
    int j;

    for (j = left; j < right; j++) {
        if (nums[j] < pivot) {
            i++;
            swap(&nums[j], &nums[i]);
        }
    }

    i++;
    swap(&nums[i], &nums[right]);

    quicksort(nums, left, i - 1);
    quicksort(nums, i + 1, right);
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    int capacity = 100;
    int** result;
    int i, k;

    *returnSize = 0;

    result = (int**)malloc(sizeof(int*) * capacity);
    *returnColumnSizes = (int*)malloc(sizeof(int) * capacity);

    if (numsSize < 4) {
        return result;
    }

    quicksort(nums, 0, numsSize - 1);

    for (i = 0; i < numsSize - 3; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }

        for (k = i + 1; k < numsSize - 2; k++) {
            int left;
            int right;

            if (k > i + 1 && nums[k] == nums[k - 1]) {
                continue;
            }

            left = k + 1;
            right = numsSize - 1;

            while (left < right) {
                long long sum = (long long)nums[i] + nums[k] + nums[left] + nums[right];

                if (sum == target) {
                    if (*returnSize == capacity) {
                        capacity *= 2;
                        result = (int**)realloc(result, sizeof(int*) * capacity);
                        *returnColumnSizes = (int*)realloc(*returnColumnSizes, sizeof(int) * capacity);
                    }

                    result[*returnSize] = (int*)malloc(sizeof(int) * 4);

                    result[*returnSize][0] = nums[i];
                    result[*returnSize][1] = nums[k];
                    result[*returnSize][2] = nums[left];
                    result[*returnSize][3] = nums[right];

                    (*returnColumnSizes)[*returnSize] = 4;
                    (*returnSize)++;

                    left++;
                    right--;

                    while (left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }

                    while (left < right && nums[right] == nums[right + 1]) {
                        right--;
                    }

                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
    }

    return result;
}