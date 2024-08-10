class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int ans=0;
        long long sum=0;
        int i=0;
        while(sum<n){
            if(i<nums.size() and (sum+1)>=nums[i])
            {
                sum+=nums[i];
                i++;
            }
            else{
                sum+=(sum+1);
                ans++;
            }
        }
        return ans;
    }
};
