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
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        
        int len=0;
        
        ListNode* cur=head;
        
        while(cur){
            len++;
            cur=cur->next;
        }
        
        vector<ListNode*> res;
        
        int rem=len%k, each=len/k, left=k-rem;
        
        cur=head;
        
        while(rem--){
            
            int cnt=each+1;
            
            ListNode* current=cur;
            
            ListNode* ans=current;
            
            while(cnt-->1){
                current=current->next;
            }
            
            cur=current->next;
            
            current->next=NULL;
            
            res.push_back(ans);
        }
        
        if(each==0){
            while(left--)
                res.push_back({});
        }   
        else{
            
            while(left--){
            
                int cnt=each;
            
                ListNode* current=cur;
            
                ListNode* ans=current;
            
                while(cnt-->1){
                    current=current->next;
                }
            
                cur=current->next;
            
                current->next=NULL;
            
                res.push_back(ans);
            }
        }
        
        return res;
    }
};