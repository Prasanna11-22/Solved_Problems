class Solution {
public:
    int rows,cols;

    long long bfs(vector<vector<int>>& grid,vector<vector<bool>>& visited,int startI,int startJ)
    {
        queue<pair<int,int>>q;
        q.push({startI,startJ});
        visited[startI][startJ]=true;

       long long sum=0;

        int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

        while(!q.empty())
        {
            auto[i,j]=q.front();
            q.pop();

            sum+=grid[i][j];
            for(int d=0;d<4;d++)
                {
                    int ni=i+dir[d][0];
                    int nj=j+dir[d][1];
                
            if(ni>=0&&ni<rows&&nj>=0&&nj<cols&&grid[ni][nj]!=0&&!visited[ni][nj])
            {
                visited[ni][nj]=true;
                q.push({ni,nj});
            }
    }
                
    }
        return sum;
    }
int countIslands(vector<vector<int>>& grid, int k) 
{
    rows=grid.size();
    if(rows==0) return 0;
    cols=grid[0].size();

    vector<vector<bool>>
    visited(rows,vector<bool>(cols,false));
    int count=0;

    for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
                {
                    if(grid[i][j]!=0&&!visited[i][j])
                    {
                       long long island=bfs(grid,visited,i,j);
                        if(island%k==0)
                        {
                            count++;
                        }
                    }
                }
            
        }
return count;
       
}
};