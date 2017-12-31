class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int N=triangle.size();
        int dp[N];
        for(int j=0; j<=N-1; j++){
            dp[j] = triangle[N-1][j];
        }
        for(int i=N-2; i>=0; i--){
            for(int j=0; j<=i; j++){
                dp[j] = min(dp[j], dp[j+1]) + triangle[i][j];
            }
        }
        return dp[0];
    }
};