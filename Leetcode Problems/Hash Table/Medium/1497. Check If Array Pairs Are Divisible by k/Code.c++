class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int c=0;
        int n=arr.size();
        int c1=0;
        unordered_map<int,int>mp;
        for(int i=0;i<arr.size();i++)
        {
            int rem=arr[i]%k;
            if(rem<0)
            {
                rem=rem+k;
            }
            if(rem==0)
            {
                c1++;
            }
            else if(rem>0 and mp.find(k-rem)!=mp.end())
            {
                c++;
                mp[k-rem]--;
                if(mp[k-rem]==0)
                {
                    mp.erase(k-rem);
                }
            }
            else
            {
                mp[rem]++;
            }
        }
        if(c1%2==0)
        c=c+(c1/2);
        if(c==n/2)
        return true;
        return false;
    }
};
