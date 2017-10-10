class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> ansmap;
        for(int i=0; i<strs.size(); i++){
            string tmp(strs[i]);
            sort(tmp.begin(), tmp.end());
            if(!ansmap.count(tmp))
                ansmap[tmp]={};
            ansmap[tmp].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for(auto v: ansmap)
            ans.push_back(v.second);
        return ans;
    }
};