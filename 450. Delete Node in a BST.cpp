/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root)
            if(key<root->val) root->left = deleteNode(root->left,key);
            else if(key> root->val) root->right = deleteNode(root->right,key);
            else{
                if(!root->left && !root->right) return NULL;
                if(!root->left || !root->right){
                    return root->left ? root->left : root->right;
                }

                TreeNode* curr= root->left;
                while(curr->right!=NULL)curr=curr->right;
                root->val = curr->val;
                root->left = deleteNode(root->left,curr->val);
            }
        return root;
    }
};