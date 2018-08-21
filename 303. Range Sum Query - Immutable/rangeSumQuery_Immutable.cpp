class NumArray {
public:
    NumArray(vector<int> nums) {
        if(nums.empty()) return;
        sums.resize(nums.size(), 0);
        sums[0] = nums[0];
        for(int i=1; i<nums.size(); i++)
            sums[i] = (nums[i] + sums[i-1]);
    }
    
    int sumRange(int i, int j) {
        return sums[j] - (i<0 ? 0 : sums[i-1]);
    }
private:
    vector<int> sums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */