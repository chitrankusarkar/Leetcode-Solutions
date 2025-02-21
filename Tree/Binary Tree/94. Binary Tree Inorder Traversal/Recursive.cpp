class Solution {
public:
    void print(TreeNode* root, vector<int>& nodes) {
        if (!root)
            return;
        print(root->left, nodes);
        nodes.push_back(root->val);
        print(root->right, nodes);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        print(root, res);
        return res;
    }
};
