class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()) return {-1, -1};
        int start=0, end=nums.size()-1;
        while(start<end){
            int mid = (start + end) / 2;
            if(nums[mid]>=target)
                end = mid;
            else
                start = mid+1;
        }
        if(nums[start]!=target) return {-1, -1};
        int a=start;
        start=0, end=nums.size()-1;
        while(start<end){
            int mid = (start + end) / 2;
            if(nums[mid]>=target+1)
                end = mid;
            else
                start = mid+1;
        }
        if(nums[start]==target) return {a, start};
        return {a, start-1};
    }
};