class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        stack<pair<TreeNode*, int>> nodeStack;
        int i = 0, n = traversal.size();
        TreeNode* root = nullptr;
        while (i < n) {
            int depth = 0;
            while (i < n && traversal[i] == '-') {
                depth++;
                i++;
            }
            int value = 0;
            while (i < n && isdigit(traversal[i])) {
                value = value * 10 + (traversal[i] - '0');
                i++;
            }
            TreeNode* newNode = new TreeNode(value);
            if (nodeStack.empty()) {
                root = newNode;
            } else {
                while (!nodeStack.empty() && nodeStack.top().second >= depth) {
                    nodeStack.pop();
                }
                TreeNode* parent = nodeStack.top().first;
                if (!parent->left) {
                    parent->left = newNode;
                } else {
                    parent->right = newNode;
                }
            }
            nodeStack.push({newNode, depth});
        }
        return root;
    }
};
