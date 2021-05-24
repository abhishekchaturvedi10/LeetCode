class TrieNode {
public:
    
    TrieNode *children[26];
    
    bool isWord;
    
    TrieNode(){
        
        memset(children,0,sizeof(children));
        
        isWord=false;
    }
};

class Trie{
public:
    
    TrieNode *root;
    
    Trie(vector<string>& words){
        
        root=new TrieNode();
        
        for(int i=0; i<words.size(); ++i)
            insert(words[i]);
    }
    
    TrieNode* getRoot(){
        
        return root;
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
    
    int vis[15][15];
    
    unordered_set<string> res;

    bool isValid(vector<vector<char>> &board, int x, int y){
        
        if(x<0||y<0||x==board.size()||y==board[0].size()||vis[x][y])
            return false;
            
        return true;
    }

    void rec(vector<vector<char>> &board, int i, int j, string s, TrieNode *root){
                
        if(!isValid(board, i, j))
            return;
        
        if(root->children[board[i][j]-'a']){
            
            root=root->children[board[i][j]-'a'];
            
            s+=board[i][j];
            
            if(root->isWord)
                res.insert(s);
        
            vis[i][j]=1;
        
            rec(board, i-1, j, s,root);
            rec(board, i+1, j, s,root);
            rec(board, i, j-1, s,root);
            rec(board, i, j+1, s,root);
                
            vis[i][j]=0;
        }
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        Trie *t;
    
        TrieNode *root;
        
        t=new Trie(words);
        
        root=t->getRoot();
        
        memset(vis, 0, sizeof(vis));
	    
	    for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                rec(board,i,j,"",root);
            }
        }
	    
        vector<string> result;
        
        for(string s:res)
            result.push_back(s);
            
	    return result;
    }
};