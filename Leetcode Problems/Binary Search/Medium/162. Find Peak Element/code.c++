class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1)
        {
            return 0;
        }
        int start=0;
        int end=nums.size()-1;
        int ans=-1;
        fun(nums,start,end,ans);
        return ans;
    }
    void fun(vector<int>&nums,int start,int end,int &ans)
    {
        if(start>end)
        {
            return;
        }
        int mid=(start+end)/2;
        if(mid==0)
        {
           if(nums[mid+1]<nums[mid])
           {
               ans=mid;
               return;
           }
           else
           {
               fun(nums,mid+1,end,ans);
           }
        }
        else if(mid==nums.size()-1)
        {
            if(nums[mid-1]<nums[mid])
            {
                ans=mid;
                return;
            }
            else
            {
                fun(nums,start,mid-1,ans);
                return;
            }
        }
        else if(mid>0 and mid<nums.size()-1)
        {
            if(nums[mid]>nums[mid-1] and nums[mid]>nums[mid+1])
            {
                ans=mid;
                return;
            }
            fun(nums,start,mid-1,ans);
            fun(nums,mid+1,end,ans);
        }
    }
};
