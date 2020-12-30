class Solution {
public:
    vector<int> res;
    void travel(TreeNode* root, int depth) {
        if(root==NULL) {
            return;
        }
        if(res.size()==depth) {
            res.push_back(root->val);
        }
        travel(root->right, depth+1);
        travel(root->left, depth+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        travel(root, 0);
        return res;
    }
};