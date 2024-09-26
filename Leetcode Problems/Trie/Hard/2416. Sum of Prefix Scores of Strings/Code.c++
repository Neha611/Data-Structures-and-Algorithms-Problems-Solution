class node{
    public:
    node* next[26];
    int count;
    node()
    {
        for(int i=0;i<26;i++)
        {
            next[i]=NULL;
        }
        count=0;
    }
};
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        // a ab abc --> 5
        // 1 1   1
        // 2 2   1
        // a ab     -->4
        vector<int>ans;
        node* root=new node();
        for(int i=0;i<words.size();i++)
        {
            insert(root,words[i]);
        }
        for(int i=0;i<words.size();i++)
        {
            ans.push_back(search(root,words[i]));
        }
        return ans;
    }
    int search(node* root,string &s)
    {
        node* temp=root;
        int ans=0;
        for(int i=0;i<s.length();i++)
        {
            if(temp->next[s[i]-'a']!=NULL)
            {
                temp=temp->next[s[i]-'a'];
                ans+=temp->count;
            }
        }
        return ans;
    }
    void insert(node* root,string &s)
    {
        int c=0;
        node* temp=root;
        for(int i=0;i<s.length();i++)
        {
            if(temp->next[s[i]-'a']!=NULL)
            {
                c++;
            }
            else
            {
                temp->next[s[i]-'a']=new node();
            }
            temp=temp->next[s[i]-'a'];
            temp->count++;
        }
    }
};
