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
    int dfs(TreeNode* root, int k, long long sum, unordered_map<long long, int>& mp){
        if(!root)return 0;
            
        sum+=root->val;
        int count = mp[sum - k];
        mp[sum]++;
        
        int left=dfs(root->left, k, sum, mp);
        int right=dfs(root->right, k, sum, mp);
        
        mp[sum]--;
        sum-=root->val;
        return count+left+right;
    }
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> mp;
        mp[0]=1;
        return dfs(root, targetSum, 0, mp);
    }
};