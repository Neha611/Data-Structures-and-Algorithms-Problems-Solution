class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans=0;
        int max_ele=-1;
        for(int i=0;i<arr.size();i++)
        {
            max_ele=max(max_ele,arr[i]);
            if(max_ele==i)
            {
                ans++;
            }
        }
        return ans;
    }
};
