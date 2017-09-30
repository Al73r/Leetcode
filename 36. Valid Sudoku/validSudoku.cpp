class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9; i++){
            int trow[9]={0}, tcol[9]={0}, tblk[9]={0};
            for(int j=0; j<9; j++){
                if(board[i][j]!='.'){
                    int nrow = board[i][j] - '0' - 1;
                    if(trow[nrow]) return false;
                    trow[nrow]++;
                }
                if(board[j][i]!='.'){
                    int ncol = board[j][i] - '0' - 1;
                    if(tcol[ncol]) return false;
                    tcol[ncol]++;
                }
                int x = i / 3 * 3 + j / 3;
                int y = i % 3 * 3 + j % 3;
                if(board[x][y]!='.'){
                    int nblk = board[x][y] - '0' - 1;
                    if(tblk[nblk]) return false;
                    tblk[nblk]++;
                }
            }
        }
        return true;
    }
};