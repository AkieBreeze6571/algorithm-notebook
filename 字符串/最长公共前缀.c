//使用int记录最长长度把首个字符串直接传出

char* longestCommonPrefix(char** strs, int strsSize) {
    int i = 0;
    int j = 0;
    int go = 1;
    int lenth = 0;
    char temp;
    if(strsSize == 0){
        return "";
        }
    while(go){
        temp = strs[0][j];
        if(strs[i][j]!='\0' && strs[i][j]==temp){
            if(i<strsSize-1){
                i++;
            }else{
                i = 0;
                lenth++;
                j++;
            }
        }else{
            strs[0][lenth]='\0';
            return strs[0];
        }

    }
    return strs[0];
}