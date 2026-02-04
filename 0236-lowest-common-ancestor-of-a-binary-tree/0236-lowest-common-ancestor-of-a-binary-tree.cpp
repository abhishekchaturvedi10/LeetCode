/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    map<TreeNode*,TreeNode*> parent;
    map<TreeNode*,int> depth;
    void findDepthAndParent(TreeNode* node, TreeNode* par, int d) {
        if(node==NULL) {
            return;
        }
        depth[node]=d;
        parent[node]=par;
        findDepthAndParent(node->left,node,d+1);
        findDepthAndParent(node->right,node,d+1);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        findDepthAndParent(root,NULL,1);
        int depthP = depth[p];
        int depthQ = depth[q];
        TreeNode* parP = p;
        TreeNode* parQ = q;
        if(depthP>depthQ) {
            while(depthP>depthQ) {
                depthP--;
                parP=parent[parP];
            }
        } else if (depthQ>depthP) {
            while(depthQ>depthP) {
                depthQ--;
                parQ=parent[parQ];
            }
        }
        while(parP!=parQ) {
            parP=parent[parP];
            parQ=parent[parQ];
        }
        return parP;
    }
};