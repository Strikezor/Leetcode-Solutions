/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int distributeCoins(TreeNode* root) {
        TreeNode dummy;
        return dfs(root, &dummy);
    }
    
private:
    int dfs(TreeNode* curr, TreeNode* parent) {
        if (curr == nullptr) {
            return 0;
        }
        int moves = dfs(curr->left, curr) + dfs(curr->right, curr);
        int from = curr->val - 1;
        parent->val += from;
        moves += abs(from);
        return moves;
    }
};