class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        stack<pair<TreeNode*, int>> nodeStack; // (Node, Depth)
        int i = 0, n = traversal.size();
        TreeNode* root = nullptr; // To store the root node

        while (i < n) {
            int depth = 0;
            while (i < n && traversal[i] == '-') { // Count dashes for depth
                depth++;
                i++;
            }

            int value = 0;
            while (i < n && isdigit(traversal[i])) { // Parse number
                value = value * 10 + (traversal[i] - '0');
                i++;
            }

            TreeNode* newNode = new TreeNode(value);
            
            // If it's the first node, set it as root
            if (nodeStack.empty()) {
                root = newNode;
            } else {
                // Maintain correct parent-child relationship using depth
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

            nodeStack.push({newNode, depth}); // Add new node to stack
        }

        return root; // Return the stored root node
    }
};
