class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one=0, two=0;
        for(auto i: nums) {
            auto three = ~(one | two);
            two = (two & (~i)) | (one & i);
            one = (one & (~i)) | (three & i);
        }
        return one;
    }
};