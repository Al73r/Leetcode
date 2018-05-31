class Solution {
public:
    int numDecodings(string s) {
        if(s.size()==0) return 0;
        vector<int> dp(s.size()+1,0);
        dp[s.size()] = 1;
        dp[s.size()-1] = s[s.size()-1]!='0';
        for(int i=s.size()-2; i>=0; i--){
            if(s[i]=='0') dp[i] = 0;
            else if(s[i]=='1' || (s[i]=='2' && s[i+1]<='6'))
                dp[i] = dp[i+1] + dp[i+2];
            else
                dp[i] = dp[i+1];
        }
        return dp[0];
    }
};