class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans=nums[0]+nums[1]+nums[2];
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-2; i++){
            int begin=i+1, end=nums.size()-1;
            while(begin<end){
                int sum = nums[i]+nums[begin]+nums[end];
                if(abs(sum-target)<abs(ans-target))
                    ans = sum;
                if(nums[i]+nums[begin]+nums[end]<target)
                    begin++;
                else
                    end--;
            }
        }
        return ans;
    }
};