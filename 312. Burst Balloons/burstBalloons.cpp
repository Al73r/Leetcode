class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int dp[n+2][n+2]={0};
        for(int l=0; l<n; l++) {
            for(int i=1; i+l<=n; i++) {
                int left = nums[i-1];
                int right = nums[i+l+1];
                int rlt = INT_MIN;
                for(int j=i; j<=i+l; j++) {
                    rlt = max(rlt, dp[i][j-1]+dp[j+1][i+l]+nums[j]*left*right);
                }
                dp[i][i+l] = rlt;
            }
        }
        return dp[1][n];
    }
};