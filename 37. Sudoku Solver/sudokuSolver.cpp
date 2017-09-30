class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<int>> n(9,vector<int>(9,9));
        vector<vector<vector<bool>>> p(9, vector<vector<bool>>(9, vector<bool>(9, true)));
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j]=='.') continue;
                int num = board[i][j] - '0' - 1;
                for(int k=0; k<9; k++){
                    if(p[i][k][num]){
                        n[i][k]--;
                        p[i][k][num] = false;
                    }
                    if(p[k][j][num]){
                        n[k][j]--;
                        p[k][j][num] = false;
                    }
                    int x = i / 3 * 3 + k / 3;
                    int y = j / 3 * 3 + k % 3;
                    if(p[x][y][num]){
                        n[x][y]--;
                        p[x][y][num] = false;
                    }
                }
                n[i][j] = 0;
            }
        }
        infer(board, n, p);
        
    }
private:
    void infer(vector<vector<char>>& board, vector<vector<int>>& n, vector<vector<vector<bool>>>& p){
        bool update = true;
        while(update){
            update = false;
            int i, j, num;
            for(i=0; i<9; i++){
                for(j=0; j<9; j++){
                    if(n[i][j]==1){
                        update = true;
                        break;
                    }
                }
                if(update) break;
            }
            if(!update) break;
            for(num=0; num<9; num++){
                if(p[i][j][num])
                    break;
            }
            board[i][j] = num + '0' + 1;
            for(int k=0; k<9; k++){
                if(p[i][k][num]){
                    n[i][k]--;
                    p[i][k][num] = false;
                }
                if(p[k][j][num]){
                    n[k][j]--;
                    p[k][j][num] = false;
                }
                int x = i / 3 * 3 + k / 3;
                int y = j / 3 * 3 + k % 3;
                if(p[x][y][num]){
                    n[x][y]--;
                    p[x][y][num] = false;
                }
            }
        }
    }
    bool dfs(vector<vector<char>>& board, vector<vector<int>>& n, vector<vector<vector<bool>>>& p){
        int i, j, num;
        bool update = false;
        for(i=0; i<9; i++){
            for(j=0; j<9; j++){
                if(n[i][j]==2){
                    update = true;
                    break;
                }
            }
            if(update) break;
        }
        if(n[i][j]!=2)
            return false;
        for(num=0; num<9; num++){
            if(!p[i][j][num])
                continue;
            vector<vector<char>> board2(board);
            vector<vector<int>> n2(n);
            vector<vector<vector<bool>>> p;
            //dfs(b);
        }
    }
};