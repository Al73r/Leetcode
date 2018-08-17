class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int m=costs.size();
        if(m==0) return 0;
        int dp[m][3];
        for(int j=0; j<3; j++)
            dp[0][j] = costs[0][j];
        for(int i=1; i<m; i++) {
            dp[i][0] = costs[i][0] + min(dp[i-1][1], dp[i-1][2]);
            dp[i][1] = costs[i][1] + min(dp[i-1][0], dp[i-1][2]);
            dp[i][2] = costs[i][2] + min(dp[i-1][0], dp[i-1][1]);
        }
        return min(dp[m-1][0], min(dp[m-1][1], dp[m-1][2]));
    }
};