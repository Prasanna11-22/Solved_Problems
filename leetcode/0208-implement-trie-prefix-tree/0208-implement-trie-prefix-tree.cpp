class Node
{
public:
    Node* link[26];
    bool flag;

    Node()
    {
    flag=false;
    for(int i=0;i<26;i++)
    {
        link[i]=NULL;
    }
    }
    bool containskey(char ch)
    {
        return link[ch-'a']!=NULL;
    }
    
    Node* get(char ch)
    {
        return link[ch-'a'];
    }

    void put(char ch,Node* node)
    {
        link[ch-'a']=node;
    }

    void setEnd() {
        flag=true;
    }
    bool isEnd()
    {
        return flag;
    }
};

class Trie {
private:
Node* root;
public:
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node* temp=root;

        for(char ch:word)
        {
            if(temp->containskey(ch)==false)
            {
                temp->put(ch,new Node());
            }
            temp=temp->get(ch);

        }
        temp->setEnd();  
    }
    
    bool search(string word) {
        Node* temp=root;

        for(char ch:word)
        {
            if(temp->containskey(ch))
            {
                temp=temp->get(ch);
            }
            else return false;
        }
        return temp->isEnd();  
    }
    
    bool startsWith(string prefix) {
        
        Node* temp=root;

        for(char ch:prefix)
        {
            if(temp->containskey(ch))
            {
                temp=temp->get(ch);
            }
            else return false;
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