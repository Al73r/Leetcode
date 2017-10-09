class Solution {
public:
    int jump(vector<int>& nums) {
        int t[nums.size()];
        t[nums.size()-1]=0;
        for(int i=nums.size()-2; i>=0; i--){
            if(nums[i]==0){
                t[i] = INT_MAX;
                continue;
            }
            int m=INT_MAX, j=1;
            while(j<=nums[i] && i+j<nums.size()){
                if(nums[i]-j>=nums[i+j]){
                    m = min(m, t[i+j]-1);
                    m = max(0, m);//in case i+j represents the destination
                    j += max(1, nums[i+j]);
                }
                else{
                    m = min(m, t[i+j]);
                    j += 1;
                }
            }
            t[i] = m==INT_MAX ? m: m + 1;
        }
        return t[0];
    }
};