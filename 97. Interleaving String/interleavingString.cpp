class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l1=s1.size(), l2=s2.size(), l3=s3.size();
        if(l1+l2!=l3) return false;
        vector<vector<bool>> dp(l1+1, vector<bool>(l2+1));
        dp[l1][l2] = true;
        for(int i=l1-1; i>=0; i--)
            dp[i][l2] = dp[i+1][l2] && s1[i]==s3[i+l2];
        for(int j=l2-1; j>=0; j--)
            dp[l1][j] = dp[l1][j+1] && s2[j]==s3[l1+j];
        for(int i=l1-1; i>=0; i--)
            for(int j=l2-1; j>=0; j--)
                dp[i][j] = (s1[i]==s3[i+j] && dp[i+1][j])
                            ||(s2[j]==s3[i+j] && dp[i][j+1]);
        return dp[0][0];
    }
};