class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size()==1) return nums[0];
        int f1=nums[0], g1=0;
        for(int i=1; i<nums.size()-1; i++) {
            int tmp = f1;
            f1 = nums[i] + g1;
            g1 = max(tmp, g1);
        }
        int f2=nums[1], g2=0;
        for(int i=2; i<nums.size(); i++) {
            int tmp = f2;
            f2 = nums[i] + g2;
            g2 = max(tmp, g2);
        }
        return max(max(f1, g1), max(f2, g2));
    }
};