class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        unordered_set<string> current, next, visited;
        unordered_map<string, vector<string>> father;
        if(dict.find(endWord)==dict.end()) return ans;
        current.insert(beginWord);
        while(!current.empty()) {
            if(!ans.empty()) break;
            auto next_visited=visited;
            for(auto str: current) {
                if(str==endWord) {
                    vector<string> path(1,endWord);
                    dfs(beginWord, endWord, father, path, ans);
                    break;
                }
                for(int i=0; i<str.size(); i++) {
                    for(char ch='a'; ch<='z'; ch++) {
                        if(ch==str[i]) continue;
                        auto idx = str;
                        swap(str[i], ch);
                        if(visited.find(str)==visited.end()) {
                            if(dict.find(str)!=dict.end() || str==endWord) {
                                next_visited.insert(str);
                                next.insert(str);
                                father[str].push_back(idx);
                            }
                        }
                        swap(str[i], ch);
                    }
                }
            }
            visited = next_visited;
            current = next;
            next.clear();
        }
        return ans;
    }
private:
    void dfs(string& beginWord, string& endWord, unordered_map<string, vector<string>>& father,
             vector<string>& path, vector<vector<string>>& ans) {
        if(endWord==beginWord) {
            reverse(path.begin(), path.end());
            ans.push_back(path);
            reverse(path.begin(), path.end());
            return;
        }
        for(int i=0; i<father[endWord].size(); i++) {
            path.push_back(father[endWord][i]);
            dfs(beginWord, father[endWord][i], father, path, ans);
            path.pop_back();
        }
    }
};