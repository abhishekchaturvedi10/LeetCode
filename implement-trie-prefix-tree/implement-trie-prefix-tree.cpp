class TrieNode {
    
public:
    
    TrieNode *children[26];
    
    bool isWord;
    
    TrieNode(){
        
        for(int i=0;i<26;i++)
            children[i]=NULL;
        
        isWord=false;
    }
};


class Trie {
public:
    
    TrieNode *node;

    
    /** Initialize your data structure here. */    
    Trie() {
                
        node=new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        
        TrieNode *root=node;
                
        for(int i=0;i<word.length();i++){
            
            if(!root->children[word[i]-'a'])
                root->children[word[i]-'a']=new TrieNode();
            
            root=root->children[word[i]-'a'];
        } 
        
        root->isWord=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        
        TrieNode *root=node;
        
        for(int i=0;i<word.length();i++){
            
            if(!root->children[word[i]-'a'])
                return false;
            
            root=root->children[word[i]-'a'];
        }
        
        return root!=NULL && root->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        
        TrieNode *root=node;
        
        for(int i=0;i<prefix.length();i++){
            
            if(!root->children[prefix[i]-'a'])
                return false;
            
            root=root->children[prefix[i]-'a'];
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */