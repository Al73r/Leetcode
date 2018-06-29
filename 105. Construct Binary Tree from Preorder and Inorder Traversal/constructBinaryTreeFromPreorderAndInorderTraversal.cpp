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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return solve(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
    TreeNode* solve(vector<int>& preorder, int start1, int finish1,
                    vector<int>& inorder, int start2, int finish2){
        if(start1>finish1) return nullptr;
        TreeNode* node = new TreeNode(preorder[start1]);
        int shift;
        for(shift=0; start2+shift<=finish2; shift++)
            if(inorder[start2+shift]==preorder[start1])
                break;
        node->left = solve(preorder, start1+1, start1+shift, inorder, start2, start2+shift-1);
        node->right = solve(preorder, start1+shift+1, finish1, inorder, start2+shift+1, finish2);
        return node;
    }
};