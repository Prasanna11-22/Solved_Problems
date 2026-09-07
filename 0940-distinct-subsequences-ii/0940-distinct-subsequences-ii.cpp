class Solution {
public:
    int distinctSubseqII(string s) {
        const long long mod=1e9+7;
        long long seq=1;
        vector<long long> last(26,0);

        for(char c : s)
        {
            int ind=c -'a';
            long long oldseq=seq;
            seq=(2*oldseq-last[ind]+mod)%mod;

            last[ind]=oldseq;
        }

        return (seq-1+mod)%mod;
        
    }
};