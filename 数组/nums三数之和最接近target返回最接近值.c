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

int threeSumClosest(int* nums, int numsSize, int target) {
    int i;
    int result;

    quicksort(nums, 0, numsSize - 1);

    result = nums[0] + nums[1] + nums[2];

    for (i = 0; i < numsSize - 2; i++) {
        int left = i + 1;
        int right = numsSize - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];

            if (abs(sum - target) < abs(result - target)) {
                result = sum;
            }

            if (sum < target) {
                left++;
            } else if (sum > target) {
                right--;
            } else {
                return sum;
            }
        }
    }

    return result;
}