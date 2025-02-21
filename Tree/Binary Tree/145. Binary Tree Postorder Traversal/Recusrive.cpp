class Solution {
public:
    void print(TreeNode* root, vector<int>& nodes) {
        if (!root)
            return;
        print(root->left, nodes);
        print(root->right, nodes);
        nodes.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        print(root, res);
        return res;
    }
};
