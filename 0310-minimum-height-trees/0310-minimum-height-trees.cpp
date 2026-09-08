class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
       vector<vector<int>> adj(n);
       vector<int> deg(n,0);

       if(n==1) return {0};

       for( int i=0;i<edges.size();i++)
       {
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
       }
       
       queue<int> q;
       for( int i=0;i<n;i++)
       {
        if(deg[i]==1) q.push(i);
       }

       int rem=n;

       while(rem>2)
       {
        int s=q.size();
        rem-=s;

        while(s--)
        {
            int node=q.front();
            q.pop();

            for(int nei : adj[node])
            {
                deg[nei]--;
                if(deg[nei]==1) q.push(nei);
            }
        }

       }

       vector<int> ans;
       while(!q.empty())
       {
        ans.push_back(q.front());
        q.pop();
       }

        return ans;
    }
};