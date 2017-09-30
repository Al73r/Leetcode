class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==0) return -1;
        int idxmax = binary_max(nums, 0, nums.size()-1);
        if(target>=nums[0]){
            auto itu = lower_bound(nums.begin(), nums.begin()+idxmax+1, target);
            if(itu==nums.begin()+idxmax+1) return -1;
            return itu - nums.begin();
        }
        else{
            auto itv = lower_bound(nums.begin()+idxmax+1, nums.end(), target);
            if(itv==nums.end()) return -1;
            return itv - nums.begin();
        }
    }

private: 
    int binary_max(vector<int>& nums, int start, int end){
        if(nums[start]<=nums[end])
            return end;
        int mid = (start + end) / 2;
        if(nums[start]>=nums[mid])
            return binary_max(nums, start, mid);
        else
            return binary_max(nums, mid, end);
    }
};