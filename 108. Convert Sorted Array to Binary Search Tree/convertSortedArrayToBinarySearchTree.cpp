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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return solve(begin(nums), end(nums));
    }
private:
    template<typename InputIterator>
    TreeNode* solve(InputIterator first, InputIterator last){
        if(first>=last) return nullptr;
        auto length = distance(first, last);
        auto node = new TreeNode(*next(first, length/2));
        node->left = solve(first, next(first, length/2));
        node->right = solve(next(first, length/2+1), last);
        return node;
    }
};