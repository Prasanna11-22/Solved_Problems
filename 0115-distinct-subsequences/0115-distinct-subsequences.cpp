class Solution {
public:
vector<vector<int>> dp;
//i-> s 
//j-> t

int rec(int i,int j,string &s,string &t)
{
    if(j==t.size()) return 1;
    if(i>=s.size()) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int ways=0;

    ways+=rec(i+1,j,s,t);
    
    if(s[i]==t[j])
    {
        ways+=rec(i+1,j+1,s,t);
    }

    return dp[i][j]=ways;
}
    int numDistinct(string s, string t) {
        if(s.size()<t.size()) return 0;
      dp.assign(s.size(),vector<int>(t.size(),-1));
      return rec(0,0,s,t);
    }
};