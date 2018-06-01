/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> result;
        if(n>0)
            result = dfs(1, n);
        return result;
    }
private:
    vector<TreeNode*> dfs(int start, int end){
        vector<TreeNode*> result;
        if(start>end) {
            result.push_back(NULL);
            return result;
        }
        for(int i=start; i<=end; i++){
            vector<TreeNode*> lrlt = dfs(start, i-1);
            vector<TreeNode*> rrlt = dfs(i+1, end);
            for(auto l:lrlt){
                for(auto r:rrlt){
                    TreeNode* t = new TreeNode(i);
                    t->left = l;
                    t->right = r;
                    result.push_back(t);
                }
            }   
        }
        return result;
    }
};