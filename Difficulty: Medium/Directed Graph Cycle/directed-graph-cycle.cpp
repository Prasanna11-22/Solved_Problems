class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<int> indeg(V,0);
        vector<vector<int>> adj(V);
        int cnt=0;
        
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
            int node= q.front();
            q.pop();
            
            cnt++;
            for( int nei : adj[node])
            {
                indeg[nei]--;
                
                if(indeg[nei]==0) q.push(nei);
            }
        }
        //cout<<cnt;
        
        return (cnt!=V);
    }
};