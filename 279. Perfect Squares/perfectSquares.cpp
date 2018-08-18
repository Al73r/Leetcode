class Solution {
public:
    int numSquares(int n) {
        int dp[n+1]={0};
        for(int i=1; i<=n; i++) {
            int m=INT_MAX;
            for(int j=1; j*j<=i; j++)
                m = min(m, dp[i-j*j]);
            dp[i] = m + 1;
        }
        return dp[n];
    }
};