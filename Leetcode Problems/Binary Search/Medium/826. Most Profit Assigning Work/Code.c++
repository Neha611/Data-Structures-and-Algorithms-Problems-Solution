class Solution {
public:
    int maxProfitAssignment(vector<int>& d,vector<int>& p,vector<int>& w){
        int ans=0;
        vector<pair<int,int>>v;
        for(int i=0;i<p.size();i++)
        {
            v.push_back({d[i],p[i]});
        }
        sort(v.begin(),v.end());
        for(int i=1;i<v.size();i++)
        {
            v[i].second=max(v[i].second,v[i-1].second);
        }
        for(int i=0;i<w.size();i++)
        {
            int start=0;
            int end=p.size()-1;
            int mid;
            int a=0;
            while(start<=end)
            {
                mid=(start+end)/2;
                if(v[mid].first<=w[i])
                {
                    a=max(a,v[mid].second);
                    start=mid+1;
                }
                else
                {
                    end=mid-1;
                }
            }
            ans+=a;
        }
        return ans;
    }
};
