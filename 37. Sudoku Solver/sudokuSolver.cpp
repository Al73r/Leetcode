class Solution {
public:
    int row[9], col[9], blo[9];
    void solveSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9; i++){
            row[i] = (1<<9) - 1;
            col[i] = (1<<9) - 1;
            blo[i] = (1<<9) - 1;
        }
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j]!='.'){
                    int num = board[i][j] - '1';
                    row[i] -= 1<<num;
                    col[j] -= 1<<num;
                    blo[i/3*3 + j/3] -= 1<<num;
                }
            }
        }
        dfs(0, 0, board);
    }

private:
    bool dfs(int x, int y, vector<vector<char>>& board){
        if(y>8){
            if(x<8){
                y = 0;
                x++;
            }
            else
                return true;
        }
        if(board[x][y]!='.')
            return dfs(x, y+1, board);

        int tmp = row[x] & col[y] & blo[x/3*3 + y/3];
        if(tmp==0)
            return false;
        for(int i=0; i<9; i++){
            if(!(tmp & (1<<i)))
                continue;
            board[x][y] = i + '1';
            row[x] -= 1<<i;
            col[y] -= 1<<i;
            blo[x/3*3 + y/3] -= 1<<i;
            if(dfs(x, y+1, board))
                return true;
            board[x][y] = '.';
            row[x] += 1<<i;
            col[y] += 1<<i;
            blo[x/3*3 + y/3] += 1<<i;
            tmp -= 1<<i;
        }
        return false;
    }
};