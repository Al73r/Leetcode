class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0; i<(n+1)/2; i++){
            for(int j=0; j<n-2*i-1; j++){
                int x1=i, y1=i+j;
                int x2=i+j, y2=n-1-i;
                int x3=n-1-i, y3=n-1-(i+j);
                int x4=n-1-(i+j), y4=i;
                int tmp = matrix[x4][y4];
                matrix[x4][y4] = matrix[x3][y3];
                matrix[x3][y3] = matrix[x2][y2];
                matrix[x2][y2] = matrix[x1][y1];
                matrix[x1][y1] = tmp;
            }
        }
    }
};