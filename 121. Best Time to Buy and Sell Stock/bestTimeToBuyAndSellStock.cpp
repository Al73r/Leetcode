class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        vector<int> pmax(prices.size(), 0);
        vector<int> pmin(prices.size(), 0);
        pmin[0] = prices[0];
        for(int i=1; i<prices.size(); i++)
            pmin[i] = min(pmin[i-1], prices[i]);
        pmax[prices.size()-1] = prices[prices.size()-1];
        for(int i=prices.size()-2; i>=0; i--)
            pmax[i] = max(pmax[i+1], prices[i]);
        int ans = 0;
        for(int i=0; i<prices.size(); i++)
            ans = max(ans, pmax[i]-pmin[i]);
        return ans;
    }
};