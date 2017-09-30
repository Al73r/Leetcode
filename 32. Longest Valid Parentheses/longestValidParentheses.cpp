class Solution {
public:
    int longestValidParentheses(string s) {
        int sl=s.size(), ans=0;
        vector<int> dp(sl, 0);
        for(int i=1; i<sl; i++){
            int match = i - dp[i-1] -1; 
            if(s[i]==')' && match>=0 && s[match]=='('){
                dp[i] = dp[i-1] + 2;
                if(match>=1)
                    dp[i] += dp[match-1];
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};