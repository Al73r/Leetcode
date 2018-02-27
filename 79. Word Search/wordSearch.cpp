class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(word.empty()) return true;
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for( int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j]==word[0]){
                    visited[i][j] = true;
                    if(helper(board, word, i, j, 1, visited))
                        return true;
                    visited[i][j] = false;
                }
            }
        }
        return false;
    }

private:
    bool helper(vector<vector<char>>& board, string& word,
                int x, int y, int k, vector<vector<bool>>& visited) {
        if(k==word.size()) return true;

        if(x-1>=0 && !visited[x-1][y] && board[x-1][y]==word[k]) {
            visited[x-1][y] = true;
            if(helper(board, word, x-1, y, k+1, visited))
                return true;
            visited[x-1][y] = false;
        }

        if(x+1<board.size() && !visited[x+1][y] && board[x+1][y]==word[k]) {
            visited[x+1][y] = true;
            if(helper(board, word, x+1, y, k+1, visited))
                return true;
            visited[x+1][y] = false;
        }

        if(y-1>=0 && !visited[x][y-1] && board[x][y-1]==word[k]) {
            visited[x][y-1] = true;
            if(helper(board, word, x, y-1, k+1, visited))
                return true;
            visited[x][y-1] = false;
        }

        if(y+1<=board[0].size() && !visited[x][y+1] && board[x][y+1]==word[k]) {
            visited[x][y+1] = true;
            if(helper(board, word, x, y+1, k+1, visited))
                return true;
            visited[x][y+1] = false;
        }

        return false;
    }
};