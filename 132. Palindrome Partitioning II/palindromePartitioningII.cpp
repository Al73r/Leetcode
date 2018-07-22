class Solution {
public:
    int minCut(string s) {
        int n=s.size();
        if(n==0) return -1;
        bool palindrome[n][n];
        for(int length=1; length<=n; length++) {
            for(int i=0; i+length-1<n; i++) {
                if(length==1) palindrome[i][i+length-1] = true;
                else if(length==2) palindrome[i][i+length-1] = s[i]==s[i+1];
                else palindrome[i][i+length-1] = palindrome[i+1][i+length-2] && s[i]==s[i+length-1];
            }
        }
        int dp[n];
        for(int i=0; i<n; i++) {
            if(palindrome[0][i]) dp[i] = 0;
            else {
                dp[i] = INT_MAX - 1;
                for(int j=i; j>=0; j--) {
                    if(palindrome[j][i]) {
                        dp[i] = min(dp[i], dp[j-1]+1);
                    }
                }
            }
        }
        return dp[n-1];
    }
};