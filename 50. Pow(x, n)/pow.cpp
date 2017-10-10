class Solution {
public:
    double myPow(double x, int m) {
        double ans=1;
        int sign = 1;
        long long n = m;
        if(n<0){ x=1.0/x; n=-n;}
        while(n>0){
            if(n%2) ans*=x;
            x *= x;
            n /= 2;
        }
        return ans;
    }
};