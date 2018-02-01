class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> path;
        vector<vector<int>> result;
        helper(n, k, 0, path, result);
        return result;
    }

private: 
    void helper(int n, int k, int last, vector<int> &path, vector<vector<int>> &result) {
        if(k==0) {
            result.push_back(path);
            return;
        }
        for(int i=last+1; i<=n-k+1; i++){
            path.push_back(i);
            helper(n, k-1, i, path, result);
            path.pop_back();
        }
    }
};


