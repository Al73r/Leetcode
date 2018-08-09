class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        vector<vector<node*>> nodes(n+1, vector<node*>());
        for(int i=n-1; i>=0; i--) {
            for(auto w: wordDict) {
                int l=w.size();
                if(i+l<=n && w==s.substr(i, l)) {
                    if(i+l==n || !nodes[i+l].empty()) {
                        auto newnode = new node(w);
                        nodes[i].push_back(newnode);
                        for(auto nextnode: nodes[i+l])
                            newnode->next.push_back(nextnode);
                    }
                }
            }
        }
        vector<string> ans;
        for(auto start: nodes[0]) {
            vector<node*> path;
            dfs(start, path, ans);
        }
        return ans;
    }
private:
    struct node {
        string str;
        vector<node*> next;
        node(string s) : str(s) {}
    };
    void dfs(node* start, vector<node*>& path, vector<string>& ans) {
        path.push_back(start);
        if(start->next.empty()) {
            string rlt;
            for(int i=0; i<path.size(); i++) {
                rlt += path[i]->str;
                if(i!=path.size()-1)
                    rlt += " ";
            }
            ans.push_back(rlt);
        }
        for(auto nextnode: start->next)
            dfs(nextnode, path, ans);
        path.pop_back();
    }
};