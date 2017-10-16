class Solution {
public:
    string simplifyPath(string path) {
        string ans;
        int i=0;
        while(i<path.size()){
            while(i<path.size() && path[i]=='/') i++;
            string tmp;
            while(i<path.size() && path[i]!='/'){
                tmp += path[i];
                i++;
            }
            if(tmp=="." || tmp.empty()) continue;
            if(tmp==".."){
                if(!ans.empty()){
                    int j=ans.size()-1;
                    while(j>=0 && ans[j]!='/') j--;
                    ans.erase(ans.begin()+j, ans.end());
                }
            }
            else{
                ans += '/';
                ans += tmp;
            }
        }
        if(ans.empty()) ans += '/';
        return ans;
    }
};