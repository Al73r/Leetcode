class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.empty()) return 1;
        bool flag[nums.size()] = {false};
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>0 && nums[i]<nums.size()+1)
                flag[nums[i]-1] = true;
        }
        for(int i=0; i<nums.size(); i++){
            if(!flag[i])
                return i+1;
        }
        return nums.size()+1;
    }
};