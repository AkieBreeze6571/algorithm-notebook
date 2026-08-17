/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

void backtrack(int *nums,
               int numsSize,
               int *path,
               int *used,
               int depth,
               int **result,
               int *resultSize)
{
    int i;
    int j;

    if (depth == numsSize)
    {
        result[*resultSize] =
            (int *)malloc(sizeof(int) * numsSize);

        for (j = 0; j < numsSize; j++)
        {
            result[*resultSize][j] = path[j];
        }

        (*resultSize)++;

        return;
    }

    for (i = 0; i < numsSize; i++)
    {
        if (used[i] == 1)
        {
            continue;
        }

        path[depth] = nums[i];
        used[i] = 1;

        backtrack(nums,
                  numsSize,
                  path,
                  used,
                  depth + 1,
                  result,
                  resultSize);

        used[i] = 0;
    }
}

int** permute(int* nums,
              int numsSize,
              int* returnSize,
              int** returnColumnSizes)
{
    int total;
    int i;

    int **result;
    int *path;
    int *used;

    total = 1;

    for (i = 1; i <= numsSize; i++)
    {
        total *= i;
    }

    result =
        (int **)malloc(sizeof(int *) * total);

    path =
        (int *)malloc(sizeof(int) * numsSize);

    used =
        (int *)calloc(numsSize, sizeof(int));

    *returnSize = 0;

    backtrack(nums,
              numsSize,
              path,
              used,
              0,
              result,
              returnSize);

    *returnColumnSizes =
        (int *)malloc(sizeof(int) * (*returnSize));

    for (i = 0; i < *returnSize; i++)
    {
        (*returnColumnSizes)[i] = numsSize;
    }

    free(path);
    free(used);

    return result;
}