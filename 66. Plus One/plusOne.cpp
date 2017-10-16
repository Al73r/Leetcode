class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int carry=1;
        for(int i=digits.size()-1; i>=0; i--){
            int tmp = digits[i] + carry;
            carry = tmp / 10;
            ans.push_back(tmp%10);
        }
        if(carry) ans.push_back(carry);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};