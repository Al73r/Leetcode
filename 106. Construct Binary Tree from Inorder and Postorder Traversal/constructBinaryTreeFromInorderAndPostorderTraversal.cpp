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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return solve(begin(inorder), end(inorder), begin(postorder), end(postorder));
    }
private:
    template<typename InputIterator>
    TreeNode* solve(InputIterator in_first, InputIterator in_last,
            InputIterator post_first, InputIterator post_last){
                if(in_first==in_last || post_first==post_last) return nullptr;
                auto node = new TreeNode(*prev(post_last));
                auto pos = find(in_first, in_last, *prev(post_last));
                auto shift = distance(pos, in_last);
                node->left = solve(in_first, prev(in_last, shift), post_first, prev(post_last, shift));
                node->right = solve(prev(in_last, shift+1), in_last, prev(post_last, shift), prev(post_last));
                return node;
        }
};