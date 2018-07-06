class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        ans.push_back(1);
        for(int i=0; i<rowIndex; i++){
            vector<int> next;
            next.push_back(1);
            for(int j=0; j<ans.size()-1; j++)
                next.push_back(ans[j] + ans[j+1]);
            next.push_back(1);
            ans = next;
        }
        return ans;
    }
};