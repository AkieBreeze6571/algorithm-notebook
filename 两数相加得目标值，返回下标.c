/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include<stdlib.h>
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int * ans = (int*)malloc(sizeof(int)*2);
    int j ;
    for(int i = 0;i<numsSize;i++){

        for(j=i+1;j<numsSize;j++){
            if(nums[i]+nums[j] == target){
                *returnSize = 2;
                ans[0] = i;
                ans[1] = j;
                return ans;
            }
        }
        
    }
    *returnSize = 0;
        return NULL;
}