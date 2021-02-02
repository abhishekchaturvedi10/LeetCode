/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* helper(ListNode* head){
        if(!head)
            return NULL;
        //cout<<head->val<<" ";
        ListNode *list=head;
        int len=0;
        while(list)
            len++, list=list->next;
        //cout<<len<<endl;
        if(len==1){
            TreeNode *root=new TreeNode(head->val);
            return root;
        }
        if(len==2){
            TreeNode *root=new TreeNode(head->val);
            root->right=helper(head->next);
            return root;
        }
        int cnt=1;
        ListNode *l=head;
        while(cnt<len/2){
            cnt++;
            head=head->next;
        }
        TreeNode *root=new TreeNode(head->next->val);
        ListNode *x=head->next->next;
        head->next=NULL;
        root->left=helper(l);
        root->right=helper(x);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        return helper(head);
    }
};