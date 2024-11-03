class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        //sum%k==0
        //subarray sum prefix[j]-prefix[i]=k*x (where x is some number)
        //(prefix[j]-prefix[i])%k==0
        //(prefix[j])%k - (prefix[i])%k==0
        //prefix[j]%k==prefix[i]%k
        unordered_map<int,int>mp;
        mp[0]=-1;
        int prev_sum=0;
        int curr_sum;
        for(int i=0;i<nums.size();i++)
        {
            curr_sum=(prev_sum+nums[i])%k;
            prev_sum=curr_sum;
            if(mp.find(curr_sum)==mp.end())
            {
                mp[curr_sum]=i;
            }
            else
            {
                if(i-mp[curr_sum]>=2)
                {
                    return true;
                }
            }
        }
        return false;
    }
};
