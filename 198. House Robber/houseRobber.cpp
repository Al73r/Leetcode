class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        int f=nums[0], g=0;
        for(int i=1; i<nums.size(); i++) {
            int tmp=f;
            f = nums[i] + g;
            g = max(tmp, g);
        }
        return max(f, g);
    }
};