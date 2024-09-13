class Solution {
public:
    int jump(vector<int>& nums) {
       if(nums.size()==1)
       {
           return 0;
       }
        if(nums[0]==0)
        {
            return -1;
        }
        int steps=1;
        int maxsteps=nums[0];
        int step=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(i==nums.size()-1)
            {
                return steps;
            }
           if(maxsteps>=i)
           {
               maxsteps=max(maxsteps,i+nums[i]);
               step--;
               if(step==0)
               {
                   steps++;
                   step=maxsteps-i;
               }
           }
        }
        return -1;
    }
};
