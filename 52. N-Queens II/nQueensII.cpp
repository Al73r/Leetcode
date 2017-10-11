class Solution {
public:
    int totalNQueens(int n) {
        vector<bool>  col(n, false), md(2*n-1, false), cd(2*n-1, false);
        return solve(0, n, col, md, cd);
    }
private:
    int solve(int i, int n, vector<bool> &col, vector<bool> &md, vector<bool> &cd){
        if(i==n) return 1;
        int ans=0;
        for(int j=0; j<n; j++){
            if(col[j] || md[i-j+n-1] || cd[i+j]) continue;
            col[j] = true;
            md[i-j+n-1] = true;
            cd[i+j] = true;

            ans += solve(i+1, n, col, md, cd);
            col[j] = false;
            md[i-j+n-1] = false;
            cd[i+j] = false;
        }
        return ans;
    }
};