class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if(n==0) return {};
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int layers=(n-1)/2, x=0, y=0, i=1;
        for(int l=0; l<=layers; l++){
            while(y<=n-l-1){
                ans[x][y] = i;
                y++; i++;
            }
            y--; x++;
            while(x<=n-l-1){
                ans[x][y] = i;
                x++; i++;
            }
            x--; y--;
            while(y>=l){
                ans[x][y] = i;
                y--; i++;
            }
            y++; x--;
            while(x>=l+1){
                ans[x][y] = i;
                x--; i++;
            }
            x++; y++;
        }
        return ans;
    }
};