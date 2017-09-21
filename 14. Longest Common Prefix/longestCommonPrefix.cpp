class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return string("");
        if(strs.size()==1) return strs[0];
        int minSize=INT_MAX, i;
        bool over = false;
        for(i=0; !over; i++){
            bool stop = false;
            char ch = strs[0][i];
            for(int j=1; j<strs.size(); j++){
                if(i>=strs[j].size()){
                    over = true;
                    break;
                }
                if(strs[j][i]!=ch){
                    stop = true;
                    break;
                }
            }
            if(stop||over) break;
        }
        return strs[0].substr(0,i);                                          
    }
};