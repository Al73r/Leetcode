class Solution {
public:
    int nthUglyNumber(int n) {
        if(n==0) return 0;
        int nums[n];
        nums[0] = 1;
        int pA=0, pB=0, pC=0;
        for(int i=1; i<n; i++) {
            int last = nums[i-1];
            while(nums[pA]*2<=last) pA++;
            while(nums[pB]*3<=last) pB++;
            while(nums[pC]*5<=last) pC++;
            nums[i] = min(nums[pA]*2, min(nums[pB]*3, nums[pC]*5));
        }
        return nums[n-1];
    }
};