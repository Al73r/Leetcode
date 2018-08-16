class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        if(n==0 || k==0) return 0;
        if(k>=n/2)
            return solveMaxProfit(prices);
        int f[k]={0}, g[k]={0};
        for(int i=1; i<n; i++) {
            int diff = prices[i]-prices[i-1];
            for(int j=k-1; j>=1; j--) {
                f[j] = max(g[j-1]+max(diff, 0), f[j]+diff);
                g[j] = max(g[j], f[j]);
            }
            f[0] = max(f[0], 0) + diff;
            g[0] = max(g[0], f[0]);
        }
        return g[k-1];
    }
private:
    int solveMaxProfit(vector<int>& prices) {
        int ans = 0;
        for(int i=1; i<prices.size(); i++) {
            int diff = prices[i] - prices[i-1];
            if(diff>0)
                ans += diff;
        }
        return ans;
    }
};