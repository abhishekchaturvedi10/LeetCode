class TrieNode{
public:
    
    TrieNode *children[26];
    
    bool isWord;
    
    TrieNode(){
        
        memset(children, 0, sizeof(children));
        
        isWord=false;
    }
    
};

class Trie{
public:
    
    TrieNode *root;
    
    Trie(){
        
        root=new TrieNode();
    }
    
    void insert(string s){
        
        TrieNode *node=root;
        
        for(char c:s){
            
            if(!node->children[c-'a'])
                node->children[c-'a']=new TrieNode();
            
            node=node->children[c-'a'];
        }
        
        node->isWord=true;
    }
    
    bool search(string s){
        
        TrieNode *node=root;
        
        for(char c:s){
            
            if(!node->children[c-'a'])
                return false;
            
            node=node->children[c-'a'];
        }
        
        return node!=NULL && node->isWord;
    }
};

class Solution {
public:
    
    string replaceWords(vector<string>& dic, string sentence) {
        
        Trie *t=new Trie();
        
        for(string s:dic)
            t->insert(s);
        
        string res;
        
        int i=0;
        
        while(i<sentence.length()){
            
            int j=i;
            
            while(j<sentence.length()&&(sentence[j]>='a'&&sentence[j]<='z')){
                j++;
            }
            
            string temp=sentence.substr(i,j-i);
            
            i=j+1;
            
            string x;
            
            bool found=0;
            
            for(int i=0;i<temp.length();i++){
                x+=temp[i];
                if(t->search(x)){
                    res+=x+' ';
                    found=1;
                    break;
                }
            }
              
            if(!found)
                res+=temp + ' ';
        }
        
        return res.substr(0,res.length()-1);
    }
};