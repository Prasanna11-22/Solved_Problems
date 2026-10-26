class Solution {
public:

int cnt(auto l)
{
    int count=0;

    for(int i=0;i<l.size();i++)
    {
        if(l[i]=='1') count++;
    }
    return count;
}
    int calculateScore(int a, int b) {
      bitset<32> n(a);
      bitset<32> m(b);
    
      

      int c1=cnt(n.to_string());
      int c2=cnt(m.to_string());

      if(c1>=c2) return (c1*c2);

      return c2/c1;  
    }
};