//https://leetcode.com/problems/design-add-and-search-words-data-structure/
class TrieNode{
    public:
    TrieNode* ch[26];
    int isEnd;
    TrieNode()
    {
        for(int i=0;i<26;i++)
        ch[i] = NULL;
        isEnd=false;
    }
    bool containsKey(char c)
    {
        return ch[c-'a']!=NULL;
    }
    void setEnd()
    {
        isEnd = true;
    }
    void putNode(char c)
    {
        ch[c-'a'] = new TrieNode();
    }
    TrieNode* next(char c)
    {
        return ch[c-'a'];
    }
    TrieNode* getNode(char c)
    {
     
        return ch[c-'a'];
    }
    bool isend()
    {
        return isEnd;
    }
};

class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() 
    {
        root = new TrieNode();
    }

    void addWord(string word) 
    {
         TrieNode* n = root;
        for(int i=0;i<word.size();i++)
        {
            if(!n->containsKey(word[i]))
            n->putNode(word[i]);
            n = n->getNode(word[i]);
        }
        n->setEnd();
    }
    bool helper(TrieNode* n,string word,int i)
    {
        if(n==NULL)
        return false;
        if(i==word.size())
        return n->isend();
        if(word[i]=='.')
        {
            for(TrieNode* child:n->ch)
            {
                if(helper(child,word,i+1))
                return true;
            }
            return false;
        }
        else{
            TrieNode* child = n->getNode(word[i]);
            if(child==NULL)
            return false;
            return helper(child,word,i+1);
        }
        return false;
    }
    bool search(string word) 
    {
        TrieNode* n = root;
        return helper(n,word,0);

    }
};
