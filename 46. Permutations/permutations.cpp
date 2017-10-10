class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        vector<int> path;
        vector<vector<int>> ans;
        solve(nums, used, path, ans);
        return ans;
    }
private:
    void solve(vector<int> &nums, vector<bool> &used,
                              vector<int> &path, vector<vector<int>> &ans){
        if(path.size()==nums.size()){
            ans.push_back(path);
            return;
        }
        for(int i=0; i<nums.size(); i++){
            if(used[i]) continue;
            used[i] = true;
            path.push_back(nums[i]);
            solve(nums, used, path, ans);
            path.pop_back();
            used[i] = false;
        }
    }
};