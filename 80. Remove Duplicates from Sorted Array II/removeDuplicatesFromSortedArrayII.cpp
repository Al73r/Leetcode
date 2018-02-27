class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        int p=1, num=nums[0], times=1;
        for(int i=1; i<nums.size(); i++){
            if(nums[i]==num){
                if(++times<=2)
                    nums[p++] = num;
            }
            else{
                num = nums[i];
                times = 1;
                nums[p++] = num;
            }
        }
        return p;
    }
};