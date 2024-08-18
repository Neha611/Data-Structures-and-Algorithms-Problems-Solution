class Solution {
public:
    vector<vector<long long>>dp;
    long long maxEnergyBoost(vector<int>& arr1, vector<int>& arr2) {
        dp.resize(arr1.size(),vector<long long>(4,-1));
       return fun(arr1,arr2,0,-1); 
    }
    long long fun(vector<int>&arr1,vector<int>&arr2,int i,int curr_drink)
    {
        if(i>=arr1.size())
        {
            return 0;
        }
        if(dp[i][curr_drink+1]!=-1)
            return dp[i][curr_drink+1];
        long long c1=0;
        long long c2=0;
        if(i==0)
        {
            //can drink from A 
            c1=arr1[i]+max(fun(arr1,arr2,i+1,1),fun(arr1,arr2,i+2,2));
            //can drink from B
            c2=arr2[i]+max(fun(arr1,arr2,i+1,2),fun(arr1,arr2,i+2,1));
        }
        else
        {
            //can drink from same drinks
            if(curr_drink==1)
            {
                c1=arr1[i]+fun(arr1,arr2,i+1,1);
                c2=arr1[i]+fun(arr1,arr2,i+2,2);
            }
            else 
            {
                c1=arr2[i]+fun(arr1,arr2,i+1,2);
                c2=arr2[i]+fun(arr1,arr2,i+2,1);
            }
        }
        return dp[i][curr_drink+1]=max(c1,c2);
    }
};
