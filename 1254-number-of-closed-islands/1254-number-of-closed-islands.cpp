class Solution {
public:

int r,c;
bool dfs(vector<vector<int>>& grid,int i,int j)
{
    if(i<0||j<0||i>=r||j>=c) return false;
    if(grid[i][j]==1) return true;

    grid[i][j]=1;

    bool up=dfs(grid,i-1,j);
    bool down=dfs(grid,i+1,j);
    bool right=dfs(grid,i,j+1);
    bool left=dfs(grid,i,j-1);

    return (up && left && right && down);
}


    int closedIsland(vector<vector<int>>& grid) {

        int cnt=0;
         r=grid.size(),c=grid[0].size();

        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]==0)
                {
                   if(dfs(grid,i,j)==true)
                   {
                    cnt++;
                   }
                }
            }
        }
    return cnt;

    }
};