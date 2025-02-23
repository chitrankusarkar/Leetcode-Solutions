class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        int count = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            vector<int> level;
            for(int i = 0; i < size; i++) {
                TreeNode *node = q.front();
                q.pop();
                if(node->left != NULL)
                    q.push(node->left);
                if(node->right != NULL)
                    q.push(node->right);
            }
            count++;
        }
        return count;    
    }
};
