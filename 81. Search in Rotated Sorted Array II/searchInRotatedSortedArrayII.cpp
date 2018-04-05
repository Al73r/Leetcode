class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int first=0, last=nums.size()-1;
        if(first>last) return false;
        while(first<last) {
            int mid = (first + last) / 2;
            if(target==nums[mid]) return true;
            if(nums[mid]==nums[first]){
                first++;
                continue;
            }
            if(nums[mid]==nums[last]){
                last = mid - 1;
                continue;
            }
            if(nums[mid]>nums[first]){
                if(target>nums[mid])
                    first = mid + 1;
                else if(target>=nums[first])
                    last = mid - 1;
                else
                    first = mid + 1;
            }
            else{
                if(target<nums[mid])
                    last = mid - 1;
                else if(target<nums[first])
                    first = mid + 1;
                else
                    last = mid - 1;
            }

        }
        if(target==nums[first]) return true;
        else return false;
    }
};