class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        vector<vector<int>> m(matrix.size(), vector<int>(matrix[0].size(), 0));
        for(int i=0; i<m.size(); i++){
            for(int j=m[0].size()-1; j>=0; j--){
                if(j!=m[0].size()-1 && matrix[i][j]-'0' && matrix[i][j+1]-'0')
                    m[i][j] = m[i][j+1] + 1;
                else
                    m[i][j] = matrix[i][j] - '0';
            }
        }
        int rlt=0;
        m.push_back(vector<int>(matrix[0].size(), 0));
        for(int j=0; j<m[0].size(); j++){
            stack<int> s;
            for(int i=0; i<m.size(); ){
                if(s.empty() || m[i][j]>m[s.top()][j])
                    s.push(i++);
                else{
                    int tmp = s.top();
                    s.pop();
                    rlt = max(rlt, m[tmp][j]*(s.empty() ? i : i-s.top()-1));
                }
            }
        }
        return rlt;
    }
};