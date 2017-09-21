class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        if(n < 4) return res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 3; i++) {
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            if(nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;
            if(nums[i] + nums[n - 1] + nums[n - 2] + nums[n - 3] < target) continue;
            int sum3 = target - nums[i];
            for(int j = i + 1; j < n - 2; j++) {
                if(j > i + 1 && nums[j] == nums[j - 1]) continue;
                if(nums[j] + nums[j + 1] + nums[j + 2] > sum3) break;
                if(nums[j] + nums[n - 1] + nums[n - 2] < sum3) continue;
                int front = j + 1, back = n - 1;
                int sum2 = sum3 - nums[j];
                while(front < back) {
                    int tmp = nums[front] + nums[back];
                    if(tmp < sum2) front++;
                    else if(tmp > sum2) back--;
                    else {
                        vector<int> v = {nums[i], nums[j], nums[front], nums[back]};
                        res.push_back(v);
                        while(front < back && nums[front] == v[2]) front++;
                        while(front < back && nums[back] == v[3]) back--;
                    }
                }
            }
        }
        return res;
    }
};