class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        ans = solve(candidates, target, 0);
        return ans;
    }
private:
    vector<vector<int>> solve(vector<int>& candidates, int target, int start) {
        vector<vector<int>> ans;
        for(int i=start; i<candidates.size(); i++){
            if(target-candidates[i]<0){
                continue;
            }
            else if(target-candidates[i]==0){
                ans.push_back({candidates[i]});
            }
            else{
                vector<vector<int>> tmp;
                tmp = solve(candidates, target-candidates[i], i);
                if(tmp.empty())
                    continue;
                for(auto v: tmp){
                    v.push_back(candidates[i]);
                    ans.push_back(v);
                }
            }
        }
        return ans;
    }
};