class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size()<3) return ans;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-2; i++){
            if(i>0 && nums[i]==nums[i-1])
                continue;
            int begin=i+1, end=nums.size()-1;
            while(begin<end){
                if(nums[i]+nums[begin]+nums[end]==0)
                    ans.push_back(vector<int> {nums[i], nums[begin], nums[end]});
                if(nums[i]+nums[begin]+nums[end]<0){
                    do{
                        begin++;
                    }while(begin<nums.size() && nums[begin]==nums[begin-1]);
                }
                else{
                    do{
                        end--;
                    }while(end>=0 && nums[end]==nums[end+1]);
                }
            }
        }
        return ans;
    }
};