/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    string generate(TreeNode* root){
        
        if(!root)
            return "N,";
        
        string res;
        
        res+=to_string(root->val);
        
        res+=',';
        
        res+=generate(root->left);
        res+=generate(root->right);
        
        return res;
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        return generate(root);
    }
    
    int i;
    
    TreeNode* decode(vector<string>& v){
        
        if(v[i]=="N"){
            i++;
            return NULL;
        }
        
        TreeNode* me=new TreeNode(stoi(v[i++]));
        
        me->left=decode(v);
        me->right=decode(v);
        
        return me;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string res) {
        
        i=0;
        
        vector<string> v;
 
        int j=0;
        
        while(j<res.size()){
            
            int k=j;
            
            string temp;
            
            while(k<res.size()&&res[k]!=',')
                temp+=res[k], k++;
            
            j=k+1;
            
            v.push_back(temp);
        }
        
        return decode(v);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));