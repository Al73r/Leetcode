class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path;
        sort(nums.begin(), nums.end());
        dfs(nums, nums.begin(), path, result);
        return result;
    }
private:
    void dfs(vector<int>& nums, vector<int>::iterator start,
             vector<int>& path, vector<vector<int>>& result){
        result.push_back(path);
        for(auto i=start; i!=nums.end(); i++){
            if(i!=start && *i==*(i-1)) continue;
            path.push_back(*i);
            dfs(nums, i+1, path, result);
            path.pop_back();
        }
    }
};