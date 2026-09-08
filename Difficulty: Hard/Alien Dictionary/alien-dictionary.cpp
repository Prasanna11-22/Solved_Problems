class Solution {
  public:
  unordered_set<char> s;
    string findOrder(vector<string> &words) {
        
        for(auto i :  words)
        {
            for(auto j : i)
            {
                if(s.find(j)==s.end()) 
                 {   s.insert(j); }
            }
        }
        
        int k=s.size();
        int cnt=0;
        string ans="";
        
        vector<vector<int>> adj(26);
        vector<int> indeg(26,0);
        
        for(int i=0;i<words.size()-1;i++)
        {
            
            string &s1=words[i];
            string &s2=words[i+1];
            
            bool chk=false;
            
            int mini=min(s1.size(),s2.size());
            for(int j=0;j<mini;j++)
            {
                if(s1[j]!=s2[j])
                {
                    int u=s1[j]-'a';
                    int v=s2[j]-'a';
                    adj[u].push_back(v);
                    indeg[v]++;
                    chk=true;
                    break;
                }
            }
            
            if(!chk&&s1.size()>s2.size()) return "";
        }
        
        
        queue<int> q;
        
        for(auto i : s)
        {
            if(indeg[i-'a']==0) q.push(i-'a');
        }
        
        while(!q.empty())
        {
            int n=q.front();
            q.pop();
            cnt++;
            ans+=(char)(n+'a');
            
            for(int nei : adj[n])
            {
                indeg[nei]--;
                if(indeg[nei]==0) q.push(nei);
            }
        }
          
          
        if(cnt!=k) return "";      
        
        

        return ans;
    }
};