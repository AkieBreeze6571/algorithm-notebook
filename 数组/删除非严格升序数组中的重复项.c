int removeDuplicates(int* nums, int numsSize) {
    int done = 1;
    for(int i =0;i<numsSize-1;i++){
        if(nums[i] < nums[i+1]){
            nums[done] = nums[i+1];
            done++;
        }
    }
    return done;
}