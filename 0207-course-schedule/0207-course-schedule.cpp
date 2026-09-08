class Solution {
public:
    bool canFinish(int numc, vector<vector<int>>& prereq) 
    {
        vector<vector<int>> adj(numc);
        vector<int> indeg(numc,0);
        //vector<int> res;
        int cnt=0;
        for(int i=0;i<prereq.size();i++)
        {
            int u=prereq[i][0];
            int v=prereq[i][1];
            adj[v].push_back(u);
            indeg[u]++;
        }

        queue<int> q;
        for(int i=0;i<numc;i++)
        {
            if(indeg[i]==0) q.push(i);
        }

        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            //res.push_back(node);
            cnt++;
            for(auto nei : adj[node])
            {
                indeg[nei]--;
                if(indeg[nei]==0) q.push(nei);
            }
        }

        if(cnt==numc) return true;

        return false;
        
    }
};