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
        bool update = true;
        while(update){
            update = false;
            for(int i=0; i<9; i++){
                for(int j=0; j<9; j++){
                    if(n[i][j]!=1)
                        continue;
                    update = true;
                    for(int num=0; num<9; num++){
                        if(!p[i][j][num])
                            continue;
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
                        break;
                    }
                    break;
                }
                if(update) break;
            }
        }
        
    }
};