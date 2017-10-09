class Solution {
public:
    string multiply(string &num1, string &num2) {
        string ans="0";
        int i=num2.size()-1;
        while(i>=0){
            string tmp = oneMulti(num1, num2[i]);
            if(tmp!="0"){
                for(int j=i; j<num2.size()-1; j++){
                    tmp += '0';
                }
                ans = add(ans, tmp);
            }
            i--;
        }
        return ans;
    }

private:
    string add(string &num1, string &num2){
        string ans;
        int i=num1.size()-1, j=num2.size()-1, carry=0;
        while(i>=0 && j>=0){
            int n = num1[i] - '0' + num2[j] - '0' + carry;
            carry = n / 10;
            ans += (n % 10) + '0';
            i--; j--;
        }
        while(i>=0){
            int n = num1[i] - '0' + carry;
            carry = n / 10;
            ans += (n % 10) + '0';
            i--;
        }
        while(j>=0){
            int n = num2[j] - '0' + carry;
            carry = n / 10;
            ans += (n % 10) + '0';
            j--;
        }
        if(carry>0)
            ans += carry + '0';
        reverse(ans.begin(), ans.end());
        return ans;
    }

    string oneMulti(string &num1, char num2){
        if(num2=='0') return "0";
        string ans;
        int i=num1.size()-1, carry=0;
        while(i>=0){
            int n = (num1[i] - '0') * (num2 - '0') + carry;
            carry = n / 10;
            ans += (n % 10) + '0';
            i--;
        }
        if(carry>0)
            ans += carry + '0';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};