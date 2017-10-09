class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        ans = solve(candidates, target, 0);
        for(int i=0; i<ans.size(); i++){
            reverse(ans[i].begin(), ans[i].end());
        }
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
                tmp = solve(candidates, target-candidates[i], i+1);
                for(auto v: tmp){
                    v.push_back(candidates[i]);
                    ans.push_back(v);
                }
            }
            while(i+1<candidates.size() && candidates[i]==candidates[i+1])
                i++;
        }
        return ans;
    }
};