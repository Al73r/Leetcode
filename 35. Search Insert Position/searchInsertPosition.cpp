class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.empty()) return 0;
        int start=0, end=nums.size()-1;
        while(start<end){
            int mid = (start + end) / 2;
            if(nums[mid]>=target)
                end = mid;
            else
                start = mid+1;
        }
        if(nums[start]>=target) return start;
        return start+1;
    }
};