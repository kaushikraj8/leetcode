class Solution {
public:
   void traversal(TreeNode* root,vector<vector<int>>& result,int level)
    {
        if(!root)
            return;
        if(level+1>result.size())
            result.push_back(vector<int> {});
        
        result[level].push_back(root->val);
        traversal(root->left,result,level+1);
        traversal(root->right,result,level+1);
            
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        traversal(root,result,0);
        return result;
    }
};