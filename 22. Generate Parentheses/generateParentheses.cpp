class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if(n==0) return {};
        return solve(2*n, 0, n);
    }
private:
    vector<string> solve(int layer, int ul, int ll){
        if(layer==1) return {")"};
        vector<string> ans;
        vector<string> tmp;
        if(ul<=0){
            tmp = solve(layer-1, ul+1, ll-1);
            for(auto s: tmp){
                ans.push_back("("+s);
            }
        }
        else if(ll<=0){
            tmp = solve(layer-1, ul-1, ll);
            for(auto s: tmp){
                ans.push_back(")"+s);
            }
        }
        else{
            tmp = solve(layer-1, ul+1, ll-1);
            for(auto s: tmp){
                ans.push_back("("+s);
            }
            tmp = solve(layer-1, ul-1, ll);
            for(auto s: tmp){
                ans.push_back(")"+s);
            }
        }
        return ans;
    }
};