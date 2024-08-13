class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        int start=0;
        int end=sum;
        int mid;
        int ans=sum;
        while(start<=end)
        {
            mid=(start+end)/2;
            if(fun(nums,mid,k))
            {
                ans=mid;
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
        }
        return ans;
    }
    bool fun(vector<int>&arr,int &target,int &k)
    {
        int sum=0;
        int s=1;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]>target)
            {
                return false;
            }
            else if(sum+arr[i]>target)
            {
                s++;
                sum=arr[i];
                if(s>k)
                return false;
            }
            else
            {
                sum+=arr[i];
            }
        }
        return true;
    }
};
