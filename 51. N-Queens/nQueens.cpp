class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        vector<bool> row(n, false), col(n, false);
        vector<bool> md(2*n-1, false), cd(2*n-1, false);
        solve(0, 0, n, ans, board, row, col, md, cd);
        return ans;
    }
private:
    void solve(int x, int y, int nleft, vector<vector<string>> &ans,
               vector<string> &board, vector<bool> &row,
               vector<bool> &col, vector<bool> &md, vector<bool> &cd){
        if(nleft==0){
            ans.push_back(board);
            return;
        }
        if(y>board[0].size()-1){
            if(x<board.size()-1){
                x++;
                y = 0;
            }
            else{
                return;
            }
        }
        for(int i=x; i<board.size(); i++){
            if(row[i]) continue;
            for(int j=((i==x)?y:0); j<board[0].size(); j++){
                if(col[j] || md[i-j+board.size()-1] || cd[i+j]) continue;
                board[i][j] = 'Q';
                row[i] = true;
                col[j] = true;
                md[i-j+board.size()-1] = true;
                cd[i+j] = true;
                
                solve(i, j+1, nleft-1, ans, board, row, col, md, cd);
                board[i][j] = '.';
                row[i] = false;
                col[j] = false;
                md[i-j+board.size()-1] = false;
                cd[i+j] = false;
                
            }
        }
    }
};