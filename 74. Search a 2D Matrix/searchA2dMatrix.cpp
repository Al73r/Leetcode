class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        m=matrix.size();
        n=matrix[0].size();
        return helper(matrix, target, 0, m*n-1);
    }
private:
    int m,n;
    bool helper(vector<vector<int>>& matrix, int target, int start, int end){
        int mid = (start + end) / 2;
        int x = mid / n;
        int y = mid % n;
        if(start>=end) return matrix[x][y]==target;
        if(matrix[x][y]<target)
            return helper(matrix, target, mid+1, end);
        else
            return helper(matrix, target, start, mid);
    }
};