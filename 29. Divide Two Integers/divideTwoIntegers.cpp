class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor==0 || (dividend==INT_MIN && divisor==-1))
            return INT_MAX;
        long long a = labs(dividend);
        long long b = labs(divisor);
        long long c=b;
        long long i=1;
        while((c<<1)<=a){
            c <<= 1;
            i <<= 1;
        }
        int ans = 0;
        while(c>=b){
            if(a>=c){
                a -= c;
                ans += i;
            }
            c >>= 1;
            i >>= 1;
        }
        return (dividend ^ divisor)>>31 ? -ans : ans;
    }
};