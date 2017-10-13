class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> visit(nums.size(), false);
        visit[nums.size()-1] = true;
        for(int i=nums.size()-2; i>=0; i--){
            int j = i + 1;
            while(j<= i+nums[i] && j<nums.size()){
                if(visit[j]){
                    visit[i] = true;
                    break;
                }
                j += max(1, nums[j]);
            }
        }
        return visit[0];
    }
};