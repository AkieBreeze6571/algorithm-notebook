void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int* nums, int left, int right) {
    int pivot = nums[right]; 
    int i = left - 1;
    int j;

    for (j = left; j < right; j++) {
        if (nums[j] <= pivot) {
            i++;
            swap(&nums[i], &nums[j]);
        }
    }

    swap(&nums[i + 1], &nums[right]);

    return i + 1;
}

void quickSort(int* nums, int left, int right) {
    if (left >= right) {
        return;
    }

    int pivotIndex = partition(nums, left, right);

    quickSort(nums, left, pivotIndex - 1);
    quickSort(nums, pivotIndex + 1, right);
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int capacity = 100;
    int** result;
    int i;

    *returnSize = 0;

    result = (int**)malloc(sizeof(int*) * capacity);
    *returnColumnSizes = (int*)malloc(sizeof(int) * capacity);

    if (numsSize < 3) {
        return result;
    }

    quickSort(nums, 0, numsSize - 1);

    for (i = 0; i < numsSize - 2; i++) {
        int left;
        int right;

        // 如果当前数已经大于 0，后面都更大，不可能凑成 0
        if (nums[i] > 0) {
            break;
        }

        // 跳过重复的 nums[i]
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }

        left = i + 1;
        right = numsSize - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];

            if (sum == 0) {
                if (*returnSize == capacity) {
                    capacity *= 2;
                    result = (int**)realloc(result, sizeof(int*) * capacity);
                    *returnColumnSizes = (int*)realloc(*returnColumnSizes, sizeof(int) * capacity);
                }

                result[*returnSize] = (int*)malloc(sizeof(int) * 3);

                result[*returnSize][0] = nums[i];
                result[*returnSize][1] = nums[left];
                result[*returnSize][2] = nums[right];

                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;

                left++;
                right--;

                // 跳过重复的 left
                while (left < right && nums[left] == nums[left - 1]) {
                    left++;
                }

                // 跳过重复的 right
                while (left < right && nums[right] == nums[right + 1]) {
                    right--;
                }

            } else if (sum < 0) {
                left++;
            } else {
                right--;
            }
        }
    }

    return result;
}