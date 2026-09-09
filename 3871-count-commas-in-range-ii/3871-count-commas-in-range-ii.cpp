class Solution {
public:
    long long countCommas(long long n) {
        long long ans=0;
        long long curr=1;

        while(n>=curr*1000)
        {
            curr=curr*1e3;
            ans+=n-curr+1;
        }

        return ans;
        
    }
};