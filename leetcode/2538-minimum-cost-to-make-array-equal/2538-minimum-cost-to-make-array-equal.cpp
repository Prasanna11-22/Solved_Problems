class Solution {
public:
#define ll long long 
    long long minCost(vector<int>& nums, vector<int>& cost) {
      
     vector<pair<int,int>> k;
        
      ll tot=accumulate(cost.begin(),cost.end(),0LL); 
      ll ntot=0;
      int r;
      bool chk=true;
      for(int i=0;i<nums.size();i++)
      {
        k.push_back({nums[i],cost[i]});
       
      }

      sort(k.begin(),k.end());

      for(int i=0;i<nums.size();i++)
      {
        ntot+=k[i].second;
        if((2*ntot>=tot)&&(chk))
        {
            r=k[i].first;
            chk=false;
        }
      }

      ll ans=0;

      for(int i=0;i<nums.size();i++)
      {
        ans+=1LL*cost[i]*abs(1LL*nums[i] -r);
      }

    return ans;
    }
};