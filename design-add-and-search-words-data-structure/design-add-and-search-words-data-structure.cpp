class TrieNode{
public:
    
    struct TrieNode *children[26];
    
    bool isWord;
    
    TrieNode(){
        
        for(int i=0;i<26;i++)
            children[i]=NULL;
        
        isWord=false;
    }
};

class WordDictionary {
public:
    
    TrieNode *root;
    
    /** Initialize your data structure here. */
    WordDictionary() {
        
        root=new TrieNode();
    }
    
    void addWord(string word) {
        
        TrieNode *node=root;
        
        for(int i=0;i<word.length();i++){
            
            if(word[i]!='.'&&!node->children[word[i]-'a'])
                node->children[word[i]-'a']=new TrieNode();
            
            if(word[i]=='.')
                for(int i=0;i<26;i++)
                    node->children[i]=new TrieNode();
            
            node=node->children[word[i]-'a'];
        }
        
        node->isWord=true;
    }
    
    bool search(string word) {
        
        TrieNode *node=root;
        
        for(int i=0;i<word.length();i++){
            
            if(word[i]!='.'&&!node->children[word[i]-'a'])
                return false;
            
            if(word[i]!='.')
                node=node->children[word[i]-'a'];
            else{
                
                for(int j=0;j<26;j++){
                    string x=word.substr(0,i)+(char)(97+j)+word.substr(i+1,word.length()-1-i);
                    if(search(x))
                        return true;
                }
                
                return false;
            }
        }
        
        return node!=NULL && node->isWord;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */