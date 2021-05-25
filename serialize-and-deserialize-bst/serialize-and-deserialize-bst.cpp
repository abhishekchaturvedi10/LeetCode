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
        
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        if(!root)
            return "";
        
        string ser;
        
        string cur=to_string(root->val);
                
        ser+="|";
        
        for(char c:cur)
            ser+=c;
        
        ser+="|";
        
        ser+=(serialize(root->left)+serialize(root->right));
                
        return ser;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        if(data.size()==0)
            return NULL;
        
        vector<int> a;
        
        int i=1;
        
        while(i<data.size()){
            
            int j=i;
            
            while(j<data.size()-1&&data[j]!='|')
                j++;
            
            string temp=data.substr(i,j-i);
                    
            if(temp!="")
                a.push_back(stoi(temp));
            
            i=j+1;
        }
        
        TreeNode *root=new TreeNode(a[0]);
        
        vector<int> greater, smaller;
        
        for(int i=1;i<a.size();i++){
            if(a[i]<a[0])
                smaller.push_back(a[i]);
            else
                greater.push_back(a[i]);
        }
        
        string left="",right="";
        
        for(int i=0;i<smaller.size();i++)
            left+=('|'+to_string(smaller[i])+'|');
        
        for(int i=0;i<greater.size();i++)
            right+=('|'+to_string(greater[i])+'|');
        
        root->left=deserialize(left);
        root->right=deserialize(right);
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;