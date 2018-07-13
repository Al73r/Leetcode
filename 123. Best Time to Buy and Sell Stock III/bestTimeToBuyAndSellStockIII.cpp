class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        vector<int> f(prices.size(), 0);
        int cur_min=prices[0];
        for(int i=1; i<prices.size(); i++){
            f[i] = max(f[i-1], prices[i] - cur_min);
            cur_min = min(cur_min, prices[i]);
        }
        vector<int> g(prices.size()+1, 0);
        int cur_max = prices[prices.size()-1];
        for(int i=prices.size()-2; i>=0; i--){
            g[i] = max(g[i+1], cur_max - prices[i]);
            cur_max = max(cur_max, prices[i]);
        }
        int ans=0;
        for(int i=0; i<prices.size(); i++){
            ans = max(ans, f[i]+g[i+1]);
        }
        return ans;
    }
};