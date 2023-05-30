//https://leetcode.com/problems/design-hashset/description/
struct Node{
    int data;
    struct Node* next;
    Node(int x)
    {
       data = x;
       next = NULL;
    }
};
class MyHashSet {
public:
    struct Node* mp[1000];
    MyHashSet() {
        for(int i=0;i<1000;i++)
        mp[i] = NULL;
    }
    
    void add(int key) {
        if(contains(key))
        return;
        int temp = key;
        key = (key%1000);
        struct Node* head = mp[key];
        struct Node* n = new Node(temp);
        if(head==NULL)
        {
            mp[key] = n;
            cout<<n->data<<' ';
            return;
        }
        while(head->next)
        {
            head = head->next;
        }
        head->next = n;
        cout<<n->data<<' ';

    }
    
    void remove(int key) 
    {
        if(!contains(key))
        return;
        int temp = key;
        key = (key%1000);
        struct Node* head = mp[key];
        if(head && head->data == temp)
        {
            mp[key] = head->next;
            return;
        }
        struct Node* prev = mp[key];
        while(head->data!=temp)
        {
            prev = head;
            head = head->next;
        }
        prev->next = head->next;
    }
    
    bool contains(int key) 
    {
        int temp = key;
        key = (key%1000);
        struct Node* head = mp[key];
        if(head==NULL)
        {
            return false;
        }
        while(head && (head->data)!=temp)
        {
            head = head->next;
        } 
        if(head==NULL)
        return false;
        return true;
    }
};
