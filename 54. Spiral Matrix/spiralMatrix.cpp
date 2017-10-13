class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return {};
        vector<int> ans;
        int n = matrix.size();
        int m = matrix[0].size();
        int layers = (min(n,m)-1)/2;
        int x, y;
        for(int l=0; l<=layers; l++){
            int left = l;
            int right = m - l - 1;
            int top = l;
            int bottom = n - l - 1;
            x = top; y = left;
            while(y<=right){
                ans.push_back(matrix[x][y]);
                y++;
            }
            y = right; x++;
            while(x<=bottom){
                ans.push_back(matrix[x][y]);
                x++;
            }
            if(bottom>top){
                x = bottom; y--;
                while(y>=left){
                    ans.push_back(matrix[x][y]);
                    y--;
                }
            }
            if(left<right){
                y = left; x--;
                while(x>top){
                    ans.push_back(matrix[x][y]);
                    x--;
                }
            }
        }
        return ans;
    }
};