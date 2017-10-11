class Solution {
public:
    int reverse(int x) {
        long long ans=0, base1=1, base2=1;
        while(x/(base1*10)!=0){
            base1*=10;
        }
        while(x/base2!=0){
            ans += ((x/base1)%10) * base2;
            base1/=10;
            base2*=10;
        }
        if(ans>INT_MAX || ans<INT_MIN) return 0;
        return ans;
    }
};