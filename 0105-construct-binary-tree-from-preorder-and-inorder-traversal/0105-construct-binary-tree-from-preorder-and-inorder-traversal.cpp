class Solution {
public:
    unordered_map<int, int> inorderIndexMap;
    int preorderIndex = 0;

    TreeNode* buildTreeHelper(vector<int>& preorder, int inStart, int inEnd) {
        if (inStart > inEnd)
            return nullptr;

        int rootVal = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(rootVal);

        int inorderIndex = inorderIndexMap[rootVal];

        root->left = buildTreeHelper(preorder, inStart, inorderIndex - 1);
        root->right = buildTreeHelper(preorder, inorderIndex + 1, inEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        inorderIndexMap.clear();
        preorderIndex = 0;

        for (int i = 0; i < inorder.size(); i++) {
            inorderIndexMap[inorder[i]] = i;
        }

        return buildTreeHelper(preorder, 0, inorder.size() - 1);
    }
};