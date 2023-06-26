class Trie {
public:
    struct trieNode{
        bool isEndOfWord;
        trieNode* children[26];
    };
    trieNode* getNode(){
        trieNode* newNode = new trieNode();
        newNode-> isEndOfWord = false;
        for(int i=0;i<26;i++){
            newNode->children[i]=NULL;
        }
        return newNode;
    }
    trieNode* root;
    Trie() {
        root = getNode();
    }
    
    void insert(string word) {
        trieNode* curr = root;
        for(int i=0;i<word.size();i++){
            char ch = word[i];
            int idx = ch-'a';
            if(!curr->children[idx]){
                curr->children[idx]=getNode();
            }
            curr=curr->children[idx];
        }
        curr->isEndOfWord = true;
    }
    
    bool search(string word) {
        trieNode* curr = root;
        for(int i=0;i<word.size();i++){
            char ch = word[i];
            int idx = ch-'a';
            if(!curr->children[idx]){
                return false;
            }
            curr=curr->children[idx];
        }
        return(curr!=NULL && curr->isEndOfWord==true);
    }
    
    bool startsWith(string prefix) {
        trieNode* curr = root;
        int i=0;
        for(;i<prefix.size();i++){
            char ch = prefix[i];
            int idx = ch-'a';
            if(!curr->children[idx]){
                return false;
            }
            curr=curr->children[idx];
        }
        return(i==prefix.size());
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */