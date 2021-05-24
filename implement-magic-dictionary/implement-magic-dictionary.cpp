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
    
//     bool startsWith(string const &prefix) {
        
//         TrieNode *root=node;
        
//         for(int i=0;i<prefix.length();i++){
            
//             if(!root->children[prefix[i]-'a'])
//                 return false;
            
//             root=root->children[prefix[i]-'a'];
//         }
        
//         return root!=NULL;
//     }
};

class MagicDictionary {
public:
    
    Trie *t;
    
    /** Initialize your data structure here. */
    MagicDictionary() {
        
        t=new Trie();
    }
    
    void buildDict(vector<string> dictionary) {
        
        for(auto s:dictionary)
            t->insert(s);
    }
    
    bool search(string searchWord) {
        
        for(int i=0;i<searchWord.length();i++){
            for(int j=0;j<26;j++){
                if(searchWord[i]==(char)(j+97))
                    continue;
                char temp=searchWord[i];
                searchWord[i]=(char)(97+j);
                if(t->search(searchWord))
                    return 1;
                searchWord[i]=temp;
            }
        }
        
        return 0;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */