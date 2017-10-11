class Solution {
public:
    int myAtoi(string str) {
        long long ans=0;
        int sign=1, i=0;
        while(str[i]==' ') i++;
        if(str[i]=='-'){
            sign *= -1;
            i++;
        }
        else if(str[i]=='+')
            i++;
        if(str[i]=='-' || str[i]=='+') return 0;
        while(str[i]=='0') i++;
        for(; i<str.size() && str[i]>='0' && str[i]<='9' ; i++){
            ans = ans*10 + (str[i]-'0');
            if(sign>0 && ans > INT_MAX) return INT_MAX;
            if(sign<0 && ans > (-(long long)INT_MIN)) return INT_MIN;
        }
        return ans*sign;
    }
};