class Solution {
public:
int r,c;

long long dfs(int i,int j,vector<vector<int>>& grid)
{
    if(i<0||j<0||i>=r||j>=c||grid[i][j]==0) return 0;

    int val=grid[i][j];
    grid[i][j]=0;

    return val+dfs(i+1,j,grid)+dfs(i,j+1,grid)+dfs(i-1,j,grid)+dfs(i,j-1,grid);

}
    int countIslands(vector<vector<int>>& grid, int k) {
        int cnt=0;
        r=grid.size(),c=grid[0].size();
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]!=0)
                {
                    long long res = dfs(i,j,grid);

                    if(res!=0&&res%k==0)
                    {
                        cnt++;
                    }
                }
            }
        }

        return cnt;
        
    }
};