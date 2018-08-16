class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int Max=nums[0], Min=nums[0], ans=nums[0];
        for(int i=1; i<nums.size(); i++) {
            if(Max==0 || Min==0) {
                Max = nums[i];
                Min = nums[i];
                ans = max(ans, Max);
                continue;
            }
            if(nums[i]==0) {
                Max = nums[i];
                Min = nums[i];
            }
            else if(nums[i]<0) {
                if(Max<0) {
                    Max = Min * nums[i];
                    Min = nums[i];
                }
                else if(Min>0) {
                    int tmp = Max;
                    Max = max(Min*nums[i], nums[i]);
                    Min = tmp * nums[i];
                }
                else {
                    swap(Max, Min);
                    Max = Max * nums[i];
                    Min = Min * nums[i];
                }
            }
            else {
                if(Max<0) {
                    Min = Min * nums[i];
                    Max = nums[i];
                }
                else if(Min>0) {
                    Max = Max * nums[i];
                    Min = nums[i];
                }
                else {
                    Max = Max * nums[i];
                    Min = Min * nums[i];
                }
            }
            ans = max(ans, Max);
        }
        return ans;
    }
};