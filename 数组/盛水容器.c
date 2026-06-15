int minnum(int a,int b){
    if (a > b) return b;
    else return a;
}
int maxArea(int* height, int heightSize) {
    int lft,rit;
    int max = 0;
    lft = 0;
    rit = heightSize - 1;
    while(lft != rit){
        if((minnum(height[rit],height[lft])*(rit-lft))>max) { 
            max =(minnum(height[rit],height[lft])*(rit-lft));
        }if(height[lft]>height[rit]){
            rit --;
        }else{
            lft++;
        }
    }
    return max;
}