class Solution {
public:
    int longestValidParentheses(string s) {
        int ans=0, len=0, stk=0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='('){
                stk++;
                len++;
            }
            else if(stk>0){
                stk--;
                len++;
            }
            else{
                ans = max(ans, len);
                len = 0;
            }
        }
        if(stk>=0){
            ans = max(ans, len-stk);
        }
        return ans;
    }
};