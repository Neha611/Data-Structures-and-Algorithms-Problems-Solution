class Solution {
public:
    int m,n;
    vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
    int swimInWater(vector<vector<int>>& arr) {
        m=arr.size();
        n=arr[0].size();
        int start=0;
        int end=m*n;
        int mid;
        int ans=INT_MAX;
        while(start<=end)
        {
            mid=(start+end)/2;
            if(fun(arr,mid))
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
    bool fun(vector<vector<int>>&arr,int &path)
    {
        queue<vector<int>>q;
        q.push({0,0});
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        vis[0][0]=true;
        if(arr[0][0]>path)
            return false;
        while(!q.empty())
        {
            int row=q.front()[0];
            int col=q.front()[1];
            q.pop();
            if(row==m-1 and col==n-1)
            {
                if(arr[row][col]>path)
                    return false;
                return true;
            }
            for(int i=0;i<dir.size();i++)
            {
                int r=row+dir[i][0];
                int c=col+dir[i][1];
                if((r>=0 and r<m) and (c>=0 and c<n))
                {
                    if(arr[r][c]<=path and vis[r][c]==false)
                    {
                        vis[r][c]=true;
                        q.push({r,c});
                    }
                }
            }
        }
        return false;
    }
};
