class Solution {
public:
    bool isScramble(string s1, string s2) {
        int length = s1.size();
        bool dp[length][length][length];
        for(int i=0; i<length; i++){
            for(int j=0; j<length; j++){
                dp[i][i][j] = s1[i] == s2[j];
            }
        }
        for(int l=1; l<length; l++){
            for(int i=0; i+l<length; i++){
                for(int j=0; j+l<length; j++){
                    bool ans = false;
                    for(int k=0; k<l; k++){
                        if((dp[i][i+k][j] && dp[i+k+1][i+l][j+k+1])
                            ||( dp[i][i+k][j+l-k] && dp[i+k+1][i+l][j])){
                            ans = true;
                            break;
                        }
                    }
                    dp[i][i+l][j] = ans;
                }
            }
        }
        return dp[0][length-1][0];
    }
};