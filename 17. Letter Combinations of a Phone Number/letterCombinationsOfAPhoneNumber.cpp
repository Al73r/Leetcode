class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        dfs(digits, 0, ans);
        return ans;
    }
private:
    vector<string> character={"","","abc","def",
                              "ghi","jkl","mno",
                              "pqrs","tuv","wxyz"};
    void dfs(string& digits, size_t cur, vector<string>& ans, string tmp=""){
        if(cur>=digits.size()){
            if(tmp.size()>0) ans.push_back(tmp);
            return;
        }
        for(auto it: character[digits[cur]-'0']){
            dfs(digits, cur+1, ans, tmp+it);
        }
    }
};