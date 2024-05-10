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
    int maxlen=0;
    void depthfirsts(TreeNode* curr,bool goLeft,int count){
        if(!curr) return;
        maxlen=max(maxlen,count);
        if(goLeft){
            depthfirsts(curr->left,false,count+1);
            depthfirsts(curr->right,true,1);
        }
        else{
            depthfirsts(curr->left,false,1);
            depthfirsts(curr->right,true,count+1);
        }
    }
    int longestZigZag(TreeNode* root){
        depthfirsts(root,false,0);
        depthfirsts(root,true,0);
        return maxlen;
    }
};