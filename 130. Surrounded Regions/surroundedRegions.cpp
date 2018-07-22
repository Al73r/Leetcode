class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty() || board[0].empty())
            return;
        vector<vector<bool>> sign(board.size(), vector<bool>(board[0].size(), false));
        int i=0, j=0;
        dfs(i, j, board, sign);
        while(i<board.size()-1)
            dfs(i++, j, board, sign);
        while(j<board[0].size()-1)
            dfs(i, j++, board, sign);
        while(i>0)
            dfs(i--, j, board, sign);
        while(j>0)
            dfs(i, j--, board, sign);
        for(int i=0; i<sign.size(); i++)
            for(int j=0; j<sign[0].size(); j++)
                if(!sign[i][j] && board[i][j]=='O')
                    board[i][j] = 'X';
    }
private:
    void dfs(int i, int j, vector<vector<char>>& board, vector<vector<bool>>& sign) {
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]=='X' || sign[i][j])
            return;
        sign[i][j] = true;
        dfs(i+1, j, board, sign);
        dfs(i-1, j, board, sign);
        dfs(i, j+1, board, sign);
        dfs(i, j-1, board, sign);
    }
};