class Solution {
public:
const long long mod=1e9+7;
int dp[1001][1001][2];

int rec(int n,int k,int i,bool chk)
{

    if(k==0) return 1;
    if(i==n) return 0;

    if(dp[i][k][chk]!=-1) return dp[i][k][chk];
   
    int ways=0;
    if(chk)
    {
        ways=(ways+rec(n,k-1,i,false))%mod;
        ways=(ways+rec(n,k,i+1,true))%mod;
    }
    else
    {
        ways=(ways+rec(n,k,i+1,true))%mod;
        ways=(ways+rec(n,k,i+1,false))%mod;
    }

    return dp[i][k][chk]=ways;
    
}
    int numberOfSets(int n, int k) {
        memset(dp,-1,sizeof(dp));

        return rec(n,k,0,false);
    }
};