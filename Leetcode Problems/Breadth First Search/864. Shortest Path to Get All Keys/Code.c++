class Solution {
public:
    vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
    int m,n;
    int shortestPathAllKeys(vector<string>& grid) {
        m=grid.size();
        n=grid[0].size();
        int totalKeys=0;
        queue<vector<int>>q;
        vector<vector<vector<bool>>>vis;
        vis.resize(m,vector<vector<bool>>(n,vector<bool>(65,false)));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='@')
                {
                    q.push({i,j,0,0});
                    vis[i][j][0]=true;
                }
                else if(grid[i][j]>='a' and grid[i][j]<='z')
                {
                    totalKeys++;
                }
            }
        }
        while(!q.empty())
        {
            int row=q.front()[0];
            int col=q.front()[1];
            int keys=q.front()[2];
            int steps=q.front()[3];
            //cout<<row<<" "<<col<<" "<<keys<<endl;
            q.pop();
            if(keys==(1 << totalKeys)-1)
            {
                return steps;
            }
            for(int i=0;i<4;i++)
            {
                int r=row+dir[i][0];
                int c=col+dir[i][1];
                if(r>=0 and c>=0 and r<m and c<n)
                {
                    if(grid[r][c]=='.' || grid[r][c]=='@')
                    {
                        //free space
                        if(!vis[r][c][keys])
                        {
                            q.push({r,c,keys,steps+1});
                            vis[r][c][keys]=true;
                        }
                    }
                    else if(grid[r][c]=='#')
                    {
                        //wall
                        continue;
                    }
                    else if(grid[r][c]>='A' and grid[r][c]<='Z')
                    {
                        //lock
                        int temp=tolower(grid[r][c])-'a';
                        if(keys&(1<<temp) and !vis[r][c][keys])
                        {
                            q.push({r,c,keys,steps+1});
                            vis[r][c][keys]=true;
                        }
                    }
                    else if(grid[r][c]>='a' and grid[r][c]<='z')
                    {
                        //key
                        int temp=grid[r][c]-'a';
                        int new_keys=keys|(1<<temp);
                        if(!vis[r][c][new_keys])
                        {
                            q.push({r,c,new_keys,steps+1});
                            vis[r][c][new_keys]=true;
                        }
                    }
                }
            }
        }
        return -1;
    }
};
