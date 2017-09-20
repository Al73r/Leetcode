class Solution {
public:
    int maxArea(vector<int>& height) {
        int start,end,ans;
        start=0; end=height.size()-1; ans=0;
        while(start<end){
            ans = max(ans, min(height[start], height[end])*(end-start));
            if(height[start]<=height[end])
                start++;
            else
                end--;
        }
        return ans;
    }
};