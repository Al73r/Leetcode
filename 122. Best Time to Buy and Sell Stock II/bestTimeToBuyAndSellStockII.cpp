class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0, Max, Min;
        for(int i=0; i<prices.size(); ){
            Min=INT_MAX;
            while(i<prices.size() && prices[i]<Min)
                Min = prices[i++];
            if(i>=prices.size()) break;
            Max=INT_MIN;
            while(i<prices.size() && prices[i]>Max)
                Max = prices[i++];
            ans += max(0, Max-Min);
        }
        return ans;
    }
};