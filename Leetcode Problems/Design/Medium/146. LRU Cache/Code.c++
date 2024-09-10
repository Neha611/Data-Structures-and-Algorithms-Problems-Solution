class Node{
    public:
    int data;
    int key;
    Node* prev;
    Node* next;
    Node(int x,int y)
    {
        data=x;
        key=y;
        prev=NULL;
        next=NULL;
    }
};

class LRUCache {
public:
    unordered_map<int,pair<int,Node*>>mp;
    int cap;
    Node* head;
    Node* tail;
    LRUCache(int capacity) {
        cap=capacity;
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()) //not present in cache
        {
            return -1;
        }
        else
        {
            int ans=mp[key].first;
            Node* temp=mp[key].second;
            remove(temp);
            mp[key].second=insert(mp[key].first,key);
            return ans;
        }
    }
    
    void put(int key,int value) {
        if(mp.find(key)==mp.end())
        {
            if(mp.size()<cap)
            {
                mp[key]={value,insert(value,key)};
            }
            else
            {
                int k=tail->prev->key;
                remove(tail->prev);
                mp.erase(k);
                mp[key]={value,insert(value,key)};
            }
        }
        else
        {
            Node* temp=mp[key].second;
            remove(temp);
            mp[key]={value,insert(value,key)};
        }
        
    }
    void remove(Node* temp)
    {
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        temp->prev=NULL;
        temp->next=NULL;
        delete(temp);
    }
    Node* insert(int val,int key)
    {
        Node* newnode=new Node(val,key);
        Node* temp=head->next;
        head->next=newnode;
        newnode->next=temp;
        newnode->prev=head;
        temp->prev=newnode;
        return newnode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
