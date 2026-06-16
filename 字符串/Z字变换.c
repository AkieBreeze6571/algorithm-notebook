void swap(char*a ,char*b){
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

char* convert(char* s, int numRows) {
    char * a = malloc(sizeof(char)*1001);
    int length = strlen(s);
    int right = length -1;
    int i=0;
    int nowp = 0;
    int offset = 0;
    int conoffset = 0;
    if(length<=numRows || numRows ==1){
        return s;
    }
    conoffset = 2*(numRows-1);
    for(;i<=right;i+=conoffset){
        a[nowp] = s[i];
        nowp++;
    }
    for(int j =1;j<numRows-1;j++){
    for(i=j;i<=right;i+=conoffset){
        a[nowp] = s[i];
        nowp++;
        offset = conoffset - 2 * j;
        if(i+offset<=right) {
            a[nowp] = s[i+offset];
            nowp++;
        }
    }
    }
    for(i = numRows-1;i<=right;i+=conoffset){
        a[nowp] = s[i];
        nowp++;
    }
    a[length] ='\0';
    return a;
}