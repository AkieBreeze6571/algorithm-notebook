int lengthOfLastWord(char* s) {
    int p = 0;
    int count = 0;
    int rec = 0;
    while(s[p]!= '\0'){
        if(s[p] == ' '){
            if(count != 0) rec = count;
            count = 0; 
        }else{
            count ++;
        }
        p++;
    }
    if(s[p-1] == ' ') return rec;
    return count;
}