class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path;
        helper(nums, 0, path, result);
        return result;
    }

private:
    void helper(vector<int>& nums, int i, vector<int>& path, vector<vector<int>>& result){
        if(i==nums.size()){
            result.push_back(path);
            return;
        }
        helper(nums, i+1, path, result);
        path.push_back(nums[i]);
        helper(nums, i+1, path, result);
        path.pop_back();
    }
};