class Solution {
public:
    int helper(TreeNode* root, int& len) {
        if(root == NULL)
            return 0;
        int left = helper(root->left, len);
        int right = helper(root->right, len);
        len = max(left + right, len);
        return max(left, right) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int d = 0;
        helper(root, d);
        return d;
    }
};
