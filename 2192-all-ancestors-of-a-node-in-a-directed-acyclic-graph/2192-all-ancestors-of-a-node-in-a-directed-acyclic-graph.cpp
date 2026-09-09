class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);
        vector<vector<int>> ans(n);
        vector<set<int>> res(n);
        vector<int> indeg(n,0);
        for(auto i : edges)
        {
            adj[i[0]].push_back(i[1]);
            indeg[i[1]]++;
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

            for(auto nei : adj[node])
            {
                res[nei].insert(node);

                for( auto par : res[node])
                {
                    res[nei].insert(par);
                }
                indeg[nei]--;
                if(indeg[nei]==0) q.push(nei);

            }

        }

        for(auto i=0;i<n;i++)
        {
            for(auto j : res[i])
            {
                ans[i].push_back(j);
            }
        }

return ans;

        
    }
};