int jump(int* nums, int numsSize)
{
    int maxs[numsSize];
    int count = 0;
    int lmax;
    int nmax;
    int i;
    int j;

    if (numsSize <= 1)
    {
        return 0;
    }

    for (i = 0; i < numsSize; i++)
    {
        maxs[i] = i + nums[i];

        if (maxs[i] >= numsSize)
        {
            maxs[i] = numsSize - 1;
        }
    }

    lmax = 0;
    nmax = 0;

    for (j = 0; j < numsSize - 1; j++)
    {
        if (maxs[j] > nmax)
        {
            nmax = maxs[j];
        }

        if (j == lmax)
        {
            count++;
            lmax = nmax;

            if (lmax >= numsSize - 1)
            {
                return count;
            }
        }
    }

    return count;
}