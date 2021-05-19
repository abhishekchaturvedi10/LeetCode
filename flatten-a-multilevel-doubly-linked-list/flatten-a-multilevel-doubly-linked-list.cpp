/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    
    Node *helper(Node *&head){
        
        if(!head)
            return NULL;
        
        Node *res=head;
        
        while(res){
            
            if(res->child){
                
                Node *next=res->next;
                
                Node *child=helper(res->child);
                
                res->next=child;
                
                res->child=NULL;
                
                child->prev=res;
                
                Node* lastNode = child;
                
                while(lastNode->next) 
                    lastNode = lastNode->next;
                
                lastNode->next = next;
                
                if(next) 
                    next->prev = lastNode;
            }
            
            res=res->next;
        }
        
        return head;
    }
    
    Node* flatten(Node* head) {
        return helper(head);   
    }
};