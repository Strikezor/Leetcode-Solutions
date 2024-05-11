// First Approach : BFS 

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        
        if(root==NULL)
        {
            return {};
        }
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int count=q.size();
            for(int i=count;i>0;i--)
            {
                TreeNode* node= q.front();
                q.pop();

                if(i==count)
                {
                    res.push_back(node->val);
                }
                
                if(node->right != NULL)
                {
                    q.push(node->right);
                }
                if(node->left != NULL)
                {
                    q.push(node->left);
                }
            }
        }
        return res;
    }
};

//Second Approach Level by level traversal
class Solution {
public:
    vector<int> ans;
    void solve(TreeNode* root, int level, vector<int>& ans){
        if(!root) return;
        if(ans.size()== level) ans.push_back(root->val);
        solve(root->right,level+1,ans);
        solve(root->left,level+1,ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        int level = 0;
        solve(root,level,ans);
        return ans;
    }
};