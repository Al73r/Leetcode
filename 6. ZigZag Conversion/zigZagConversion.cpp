class Solution {
public:
    string convert(string s, int numRows) {
        string ans;
        for(int j=0; j<numRows; j++){
            for(int i=j; i<s.size(); i+=2*numRows-2){
                ans.push_back(s[i]);
                int idx_next = i + 2 * (numRows - j - 1);
                if(j>0 && j<numRows-1 && idx_next<s.size()){
                    ans.push_back(s[i+2*(numRows)]);
                }
            }
        }
        return ans;
    }
};