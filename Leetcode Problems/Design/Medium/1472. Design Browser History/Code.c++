class Node{
    public:
    string str;
    Node* next;
    Node* prev;
    Node(string s)
    {
        str=s;
        next=NULL;
        prev=NULL;
    }
};
class BrowserHistory {
public:
    Node* head;
    Node* curr;
    Node* curr_prev;
    BrowserHistory(string homepage) {
        head=new Node(homepage);
        curr=head;
    }
    
    void visit(string url) {
        Node* temp=new Node(url);
        curr->next=temp;
        temp->prev=curr;
        curr_prev=temp;
        curr=curr->next;
    }
    
    string back(int steps) {
        if(curr==NULL)
        {
            curr=curr_prev;
        }
        while(steps>0 and curr->prev!=NULL)
        {
            curr=curr->prev;
            steps--;
        }
        curr_prev=curr;
        return curr->str;
    }
    
    string forward(int steps) {
        if(curr==NULL)
        {
            curr=curr_prev;
        }
        int i=1;
        while(i<=steps and curr->next!=NULL)
        {
            curr=curr->next;
            i++;
        }
        curr_prev=curr;
        return curr->str;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
