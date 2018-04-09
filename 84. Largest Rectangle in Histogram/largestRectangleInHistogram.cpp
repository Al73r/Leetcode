class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        heights.push_back(0);
        int rlt=0;
        for(int i=0; i<heights.size(); ){
            if(s.empty() || heights[s.top()]<heights[i])
                s.push(i++);
            else{
                int tmp = s.top();
                s.pop();
                rlt = max(rlt, heights[tmp]*(s.empty() ? i : i-s.top()-1));
            }
        }
        return rlt;
    }
};