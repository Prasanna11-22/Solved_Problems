class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n=quiet.size();
        vector<vector<int>> adj(n);
        vector<int> indeg(n,0);
        vector<int> res(n);

        for(int i=0;i<n;i++) res[i]=i;

        for(auto i : richer)
        {
            int u=i[0]; //1
            int v=i[1]; //0

            adj[u].push_back(v); 
            indeg[v]++;
        }
        queue<int> q;

         for(int i=0;i<n;i++)
         {
            if(indeg[i]==0) q.push(i);
         }

         while(!q.empty())
         {
           int node=q.front();
            q.pop();

            for( auto nei : adj[node])
            {
            if(quiet[res[node]]<quiet[res[nei]])
            {
                res[nei]=res[node];
            }
                indeg[nei]--;
                if(indeg[nei]==0)
                {
                    q.push(nei);
                }
            }
         }



        return res;
        
    }
};