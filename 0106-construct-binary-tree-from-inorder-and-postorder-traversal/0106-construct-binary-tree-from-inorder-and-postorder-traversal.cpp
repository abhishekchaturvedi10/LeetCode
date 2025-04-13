class Solution {
public:
    unordered_map<int, int> inorderIndexMap;
    int postorderIndex;

    TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd) {
        if (inStart > inEnd)
            return nullptr;

        int rootVal = postorder[postorderIndex--];
        TreeNode* root = new TreeNode(rootVal);

        int inorderIndex = inorderIndexMap[rootVal];

        // Build right subtree first (reverse of preorder)
        root->right = buildTreeHelper(inorder, postorder, inorderIndex + 1, inEnd);
        root->left = buildTreeHelper(inorder, postorder, inStart, inorderIndex - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        inorderIndexMap.clear();
        for (int i = 0; i < inorder.size(); ++i) {
            inorderIndexMap[inorder[i]] = i;
        }
        postorderIndex = postorder.size() - 1;
        return buildTreeHelper(inorder, postorder, 0, inorder.size() - 1);
    }
};