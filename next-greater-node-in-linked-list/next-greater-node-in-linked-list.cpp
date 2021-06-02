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
    vector<int> nextLargerNodes(ListNode* head) {
        
        stack<pair<int, int>> s;

        int len=0;
        
        unordered_map<int,int> m;
        
        while(head){
            
            while(!s.empty()&&head->val>s.top().first){
                
                m[s.top().second]=head->val;
                s.pop();
            }
            
            s.push({head->val, len++});
            head=head->next;
        }
        
        vector<int> res(len);
        
        for(auto i:m)
            res[i.first]=i.second;
        
        return res;
    }
};