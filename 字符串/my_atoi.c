#define MAX 2147483647
int myAtoi(char* s) {
    long long sum = 0;
    long long i = 0;
    char temp = '0';
    while(s[i] ==' '){
        i++;
    }
    if(s[i] =='-'){
        i++;
        while(s[i] != '\0' && s[i]>='0' && s[i]<='9'){
            if(sum * 10 - s[i] + temp<=-MAX-1){
                return -MAX-1;
            }else{
                sum = sum * 10 - s[i] + temp;
            }
            i++;
        }
        return sum;
    }else{
        if(s[i]=='+') i++;
        if(s[i]>'9' || s[i]<'0') return sum;
            while(s[i] != '\0' && s[i]>='0' && s[i]<='9'){
            if(sum*10 + s[i]-temp >=MAX){
                return MAX;
            }else{
                sum =  sum * 10 + s[i] - temp;
            }
            i++;
        }
        return sum;
    }
}