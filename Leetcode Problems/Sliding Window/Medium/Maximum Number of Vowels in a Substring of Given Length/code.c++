class Solution {
public:
    int maxVowels(string s, int k) {
        int ans=0;
        int count=0;
        int start=0;
        int end=0;
        while(end<s.length())
        {
            if(end-start+1<=k)
            {
                if(isvalid(s[end]))
                {
                    count++;
                }
                end++;
            }
            if(end-start+1>k)
            {
                ans=max(ans,count);
                if(isvalid(s[start]))
                {
                    count--;
                }
                start++;
            }
        }
        return ans;
    }
    bool isvalid(char c)
    {
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
        {
            return true;
        }
        return false;
    }
};
