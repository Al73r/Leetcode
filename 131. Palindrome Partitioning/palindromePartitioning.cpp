class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n=s.size();
        if(n==0) return vector<vector<string>>(1, vector<string>(0));
        vector<vector<string>> dp[n];
        bool palindrome[n][n];
        for(int j=1; j<=n; j++) {
            for(int i=0; i+j-1<n; i++) {
                if(j==1) palindrome[i][i+j-1] = true;
                else if(j==2) palindrome[i][i+j-1] = s[i]==s[i+j-1];
                else palindrome[i][i+j-1] = palindrome[i+1][i+j-2] && s[i]==s[i+j-1];
            }
        }
        dp[0].push_back(vector<string>(1, s.substr(0,1)));
        for(int i=1; i<s.size(); i++) {
            for(int j=i; j>0; j--) {
                if(palindrome[j][i]) {
                    auto tmp = dp[j-1];
                    for(int k=0; k<tmp.size(); k++) {
                        tmp[k].push_back(s.substr(j, i-j+1));
                        dp[i].push_back(tmp[k]);
                    }
                }
            }
            if(palindrome[0][i]) dp[i].push_back(vector<string>(1, s.substr(0, i+1)));
        }
        return dp[s.size()-1];
    }
};