class Solution {
public:
void dfs(int src,int node,vector<vector<int>>&adj,vector<int>&vis,vector<vector<int>>&ans)
{
    for(auto nei : adj[node])
    {
        if(vis[nei]) continue;

        vis[nei]=1;
        ans[nei].push_back(src);
        dfs(src,nei,adj,vis,ans);
    }
}
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);
        vector<vector<int>> ans(n);

        for(auto i : edges)
        {
            adj[i[0]].push_back(i[1]);
        }

        for(int i=0;i<n;i++)
        {
            vector<int> vis(n,0);
            dfs(i,i,adj,vis,ans);
        }

        return ans;

        
    }
};