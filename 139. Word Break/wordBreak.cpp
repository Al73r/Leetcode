class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        if(n==0) return true;
        vector<bool> dp(n+1, false);
        dp[n] = true;
        for(int i=n-1; i>=0; i--) {
            for(int j=0; j<wordDict.size(); j++) {
                int nstart = i+wordDict[j].size();
                if(nstart<=n && dp[nstart] && s.substr(i, wordDict[j].size())==wordDict[j]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[0];
    }
};