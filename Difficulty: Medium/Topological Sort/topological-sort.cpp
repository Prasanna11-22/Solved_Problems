class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
     // vector<int> vis(V,0);
      vector<vector<int>> adj(V);
      vector<int> res;
      vector<int> indeg(V);
      for(int i=0;i<edges.size();i++)
      {
          int u=edges[i][0];
          int v=edges[i][1];
          adj[u].push_back(v);
          indeg[v]++;
      }
      
      queue<int> q;
      
      for(int i=0;i<V;i++)
      {
          if(indeg[i]==0) q.push(i);
      }
      
      while(!q.empty())
      {
          
          int node=q.front();
          q.pop();
          res.push_back(node);
          
          for(auto nei :  adj[node])
          {
              indeg[nei]--;
              
              if(indeg[nei]==0) q.push(nei);
          }
          
      }
        
      return res;
    }
};