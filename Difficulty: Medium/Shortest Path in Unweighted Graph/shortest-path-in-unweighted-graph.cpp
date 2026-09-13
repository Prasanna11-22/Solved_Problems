class Solution {
  public:
  
 int dijkstra (int V,vector<vector<pair<int,int>>>& adj,int src,int dest)
  {
      vector<int> dist(V,1e9);
      vector<int> par(V,-1);
      priority_queue<pair<int,int>,vector<pair<int,int>> ,greater<pair<int,int>>> pq;
      
      dist[src]=0;
      
      pq.push({0,src});
      
      while(!pq.empty())
      {
          auto [d,node] = pq.top();
          pq.pop();
          
          for(auto nei : adj[node])
          {
              int dest=nei.second;
              int w=nei.first;
              
              if(d+w<dist[dest])
              {
                  dist[dest]=d+w;
                  pq.push({dist[dest],dest});
                  par[dest]=node;
              }
          }
      }
      
     if(dist[dest]==1e9) return -1;
     
     int k=dest;
     vector<int> path;
     
     while(par[k]!=-1)
     {
         path.push_back(par[k]);
         k=par[k];
     }
     
     //reverse(path.begin(),path.end());
     
     return path.size();
      
      
  }
    int shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
        
        vector<vector<pair<int,int>>> adj(V);
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            
            adj[u].push_back({1,v});
            adj[v].push_back({1,u});
        }
        
        
        
        return dijkstra(V,adj,src,dest);
        
    }
};
