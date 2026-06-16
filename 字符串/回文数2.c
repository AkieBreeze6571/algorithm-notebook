bool isPalindrome(int x) {
    if(x < 0){
        return false;
    }
    if(x ==0){
        return true;
    }
    
    int length = 0;
    int right = 0;
    int i=0;
    char a[100];
    sprintf(a,"%d",x);
    length = strlen(a);
    right = length - 1;
    while(i<right - i){
        if(a[i] != a[right - i]) return false;
        i++;
    }
    return true;

}