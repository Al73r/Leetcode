class Solution {
public:
    int mySqrt(int x) {
        return solve(x, 0, x);
    }
    int solve(int x, int start, int end){
        if(start>=end-1) return end*end==x ? end : start;
        long long mid = (start + end) / 2;
        if(mid*mid>=x) return solve(x, start, mid);
        else return solve(x, mid, end);
    }
};