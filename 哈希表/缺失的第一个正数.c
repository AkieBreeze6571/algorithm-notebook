int firstMissingPositive(int* nums, int numsSize) {
    int a[100002]={0};
    for(int i =0;i<numsSize;i++){
        if(nums[i]>100002 || nums[i]<=0){

        }else{
            a[nums[i]]++;
        }
    }
    int j =1;
    while(a[j] != 0){
        j++;
    }
    printf("%d",j+1);
    return j;
}