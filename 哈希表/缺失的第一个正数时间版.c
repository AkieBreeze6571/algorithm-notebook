int firstMissingPositive(int* nums, int numsSize) {
    int i,harsh[100001];
    for(i=0;i<numsSize+1;i++){
        harsh[i]=0;
    }
    for(i=0;i<numsSize;i++){
        if(0<nums[i]&&numsSize+1>nums[i]){harsh[nums[i]-1]=1;}
    }
    for(i=0;i<numsSize+1;i++){
        if(!harsh[i]) return i+1;
    }
    return numsSize + 1;
}
//在检测过程中对size范围进行调整，减少最后的判断次数，减少了时间消耗。