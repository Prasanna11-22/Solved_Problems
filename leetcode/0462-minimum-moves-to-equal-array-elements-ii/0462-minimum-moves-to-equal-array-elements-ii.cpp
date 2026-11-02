class Solution {
public:

int calc(int a,vector<int>& nums)
{
    int tot=0;
    for(int i=0;i<nums.size();i++)
    {
        tot+=abs(nums[i]-nums[a]);
    }
    return tot;
}
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int tot=0;
        int med;

        if(n%2!=0)
        {
            med=n/2;
            tot = calc(med,nums);
        }
        else
        {
            int med1=floor(n/2),med2=ceil(n/2);
            tot=min(calc(med1,nums),calc(med2,nums));
        }

        return tot;
    }
};