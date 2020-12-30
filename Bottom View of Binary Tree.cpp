class Solution {
public:
    int d=0;
    int element;
    void call(TreeNode* root, int depth){
        if(root == NULL){
            return;
        }
        
        if(depth > d){
            d = depth;
            element = root->val;
        }
        
        call(root->left, depth+1);
        call(root->right, depth+1);
        
    }
    
    int findBottomLeftValue(TreeNode* root) {
        element = root->val;
        call(root, 0);
        return element;
    }
};