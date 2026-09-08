class Solution {
  public:
  
  stack<int> st;
  void dfs(int i,vector<vector<int>>&adj,vector<int>&vis)
  {
      vis[i]=1;
      
      for(auto nei : adj[i])
      {
          if(!vis[nei])
          {
              dfs(nei,adj,vis);
          }
      }
      st.push(i);
  }
  
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<int> vis(V,0);
        //cout<<true;
        vector<vector<int>> adj(V);
        vector<int> res;
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
        }
        
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                dfs(i,adj,vis);
            }
        }
        
        while(!st.empty())
        {
            res.push_back(st.top());
            st.pop();
            
        }
        return res;
        
    }
};