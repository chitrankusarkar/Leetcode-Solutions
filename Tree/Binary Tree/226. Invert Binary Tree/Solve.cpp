class Solution {
public:
    void swapNodes(TreeNode* curr) {
        if(!curr)
            return;
        swapNodes(curr->left);
        swapNodes(curr->right);

        TreeNode *t = curr->left;
        curr->left = curr->right;
        curr->right = t;
    }
    TreeNode* invertTree(TreeNode* root) {
        swapNodes(root);
        return root;
    }
};
