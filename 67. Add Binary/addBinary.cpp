class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int i=a.size()-1, j=b.size()-1, carry = 0;
        while(i>=0 && j>=0){
            int n = a[i]-'0' + b[j]-'0' + carry;
            carry = n/2;
            ans += n%2 + '0';
            i--; j--;
        }
        while(i>=0){
            int n = a[i]-'0' + carry;
            carry = n/2;
            ans += n%2 + '0';
            i--;
        }
        while(j>=0){
            int n = b[j]-'0' + carry;
            carry = n/2;
            ans += n%2 + '0';
            j--;
        }
        if(carry) ans += '1';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};